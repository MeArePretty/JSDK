#include "CutPixmap.h"


//CutPixmap*  CutPixmap::m_pInstance = NULL;

CutPixmap::CutPixmap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	CloseFlashValue = false;
	m_DrawPenModel = MOUSE;
	DrawStatus = IDEL;
	m_CurrentBrushColor = QColor(232, 245, 251, 100);
	m_CurrentText_PenColor = QColor(0, 0, 0);
	m_PenWidth = 5;
	m_Pen.setStyle(Qt::SolidLine);
	m_Pen.setWidth(m_PenWidth);
	m_font.setWeight(QFont::Normal);
	m_font.setPointSize(12);
	m_font.setFamily(QString::fromLocal8Bit("宋体"));
	LastIndexSelected = -1;
	
	CurrentIndexSelected = -1;
	IndexCount = -1;
	
	m_PixmapSizeSclaed = QSize(QApplication::desktop()->width() / 6, QApplication::desktop()->height() / 6);
	LeftbuttonPress = false;
	frame = true;
	hollow = true;
	m_PenStyle = Qt::SolidLine;
	PictureCopy = new QAction(this);
	PictureCopy->setShortcut(QKeySequence(Qt::CTRL + Qt::Key::Key_C)); /*setShortcut(QApplication::translate("CutPixmapClass", "Ctrl+C", Q_NULLPTR));*/
	addAction(PictureCopy);
	PicturePaste = new QAction(this);
	addAction(PicturePaste);
	PicturePaste->setShortcut(QKeySequence(Qt::CTRL + Qt::Key::Key_V));/* setShortcut(QApplication::translate("CutPixmapClass", "Ctrl+V", Q_NULLPTR));*/
	PictureDelete = new QAction(this);
	addAction(PictureDelete);
	PictureDelete->setShortcut(QKeySequence(Qt::Key::Key_Delete));
	m_textEdit = new MyPlaintText(this);

	m_HistoryPixmap = new QComboBox(this);
	m_HistoryPixmap->hide();
	m_HistoryPixmap->setIconSize(m_PixmapSizeSclaed);
	m_HistoryPixmap->setFixedSize(m_PixmapSizeSclaed);
	m_HistoryPixmap->setWindowFlag(Qt::Window);
	m_HistoryPixmap->setWindowTitle(QString::fromLocal8Bit("历史记录"));
	m_HistoryPixmap->setWindowIcon(QIcon(":/CutPixmap/Resources/color_palette.png"));

	/*QVector<QLayer*>*temp = new QVector<QLayer*>;*/
	m_CurrentPicture.push_back(QVector<QLayer*>());
	m_CurrentPictureCount = 1;
	m_CurrentPictureIndex = 0;

	/*addPictureToCombbox();*/

	m_CursorVector.push_back(QPixmap(":/CutPixmap/Resources/Feather.png"));
	m_CursorVector.push_back(QPixmap(":/CutPixmap/Resources/rect-pro.cur"));
	m_CursorVector.push_back(QPixmap(":/CutPixmap/Resources/line-pro.cur"));
	m_CursorVector.push_back(QPixmap(":/CutPixmap/Resources/ellipse-pro.cur"));
	SetWindowFlag();
	CreateWindow();
	Connect();

}


CutPixmap::~CutPixmap()
{
	for (int i = 0; i < m_CurrentPicture.size(); i++)
	{
		for (int j = 0; j < m_CurrentPicture[i].size(); j++)
		{
			delete m_Layer[i];
		}
	}
	for (int i = 0; i < m_Layerdelete.size(); i++)
	{
		delete m_Layerdelete[i];
	}
	if (m_Layer.size() != 0)
	{
		for (int i = 0; i < m_Layer.size(); i++)
		{
			delete m_Layer[i];
		}
	}
}

void CutPixmap::CreateWindow()
{
	m_TransToolBar = new TransToolBar(this);
	m_TransToolBar->show();
	m_QDockToolbar = new QDockToolbar(this);
	m_MyShowDrawWidget = new MyShowDrawWidget(this);
	m_pScene = new QGraphicsScene(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,this);
	m_pView = new MyGraphicsView(m_pScene, this);
}

void CutPixmap::ModifyCloseFlashValue()
{
	CloseFlashValue = true;
}


void CutPixmap::SetWindowFlag()
{
	this->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/CutPixmap/Resources/color_palette.png"));
	//this->setWindowFlag(Qt::SubWindow);
	setMouseTracking(true);
}

void CutPixmap::Connect()
{
	connect(m_TransToolBar, SIGNAL(ShowFlash()), m_QDockToolbar, SLOT(ShowFlash()));
	connect(m_TransToolBar, SIGNAL(CloseFlash()), m_QDockToolbar, SLOT(CloseFlash()));
	connect(this, SIGNAL(CloseFlash()), m_TransToolBar, SLOT(ModifyCloseFlash()));
	connect(m_TransToolBar, SIGNAL(ModifyCloseFlashValue()), this, SLOT(ModifyCloseFlashValue()));
	connect(PictureCopy, SIGNAL(triggered()), this, SLOT(OnPictureCopy()));
	connect(PicturePaste, SIGNAL(triggered()), this, SLOT(OnPicturePaste()));
	connect(PictureDelete, SIGNAL(triggered()), this, SLOT(OnPictureDelete()));
	connect(this, SIGNAL(TextShow(QRect*)), m_textEdit, SLOT(GetTextShow(QRect*)));
	connect(this, SIGNAL(TextHidde()), m_textEdit, SLOT(GetTextHidde()));
	connect(m_HistoryPixmap, SIGNAL(activated(int)), this, SLOT(GetCurrentPictureIndex(int)));

}

int CutPixmap::GetSelectedIndex(QPoint point)
{
	for (int i = IndexCount; i >= 0; i--)
	{
		if (m_Layer[i]->IsMouseInside(point))
		{
			m_Layer[i]->SetPictureStatus(true);
			return i;
		}
	}
	return -1;
}

void CutPixmap::SetOtherPictureStatusFalse()
{
	for (int i = 0; i < IndexCount + 1; i++)
	{
		if (i != CurrentIndexSelected)
		{
			m_Layer[i]->SetPictureStatus(false);
		}
	}
}

void CutPixmap::SetLastIndexPictureStatusFalse()
{
	if (LastIndexSelected >= 0)
	{
		m_Layer[LastIndexSelected]->SetPictureStatus(false);
	}
	//else
	//{
	//	SetOtherPictureStatusFalse();
	//}
}

void CutPixmap::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	//if (m_CurrentPictureIndex >= 0)
	//{
	//	for (int i = 0; i < m_CurrentPicture[m_CurrentPictureIndex].size(); i++)
	//	{
	//		m_CurrentPicture[m_CurrentPictureIndex][i]->DrawMap(&painter);
	//	}
	//}
	//else
	//{
	for (int i = 0; i < m_Layer.size(); i++)
	{
		m_Layer[i]->DrawMap(&painter);
	}
	//}
}

void CutPixmap::viewWheelEvent(QWheelEvent * event)
{
	Q_UNUSED(event);
}

void CutPixmap::viewMousePressEvent(QMouseEvent * event)
{
	if (CloseFlashValue)
	{
		emit CloseFlash();
		CloseFlashValue = !CloseFlashValue;
	}
	if (CurrentIndexSelected >= 0)
	{
		if (m_Layer[CurrentIndexSelected]->GetCurPos() == QLayer::INSIDE)
		{
			m_Layer[CurrentIndexSelected]->SetFirstPoint(&event->pos());
		}
		if (m_Layer[CurrentIndexSelected]->GetCurPos() != QLayer::DEFAULT)
		{
			DrawStatus = MOVING;
			return;
		}
	}
	if (event->button() == Qt::LeftButton&&DrawStatus == IDEL)
	{
		LeftbuttonPress = true;
		QLayer* layer;
		switch (m_DrawPenModel)
		{
		case CutPixmap::CURVE:
		{
			layer = new QCurve(m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle);
			layer->Push_backPonit(event->pos());
			layer->SetPointStatr(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::LINE:
		{
			layer = new QStraightLine(m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle);
			layer->SetPointStatr(event->pos());
			layer->SetPointEnd(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::RECT:
		{
			layer = new QRectDraw(m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle, frame, hollow);
			layer->SetPointStatr(event->pos());
			layer->SetPointEnd(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::ROUNDRECT:
		{
			layer = new QRoundRect(m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle, frame, hollow);
			layer->SetPointStatr(event->pos());
			layer->SetPointEnd(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::ELLIPSE:
		{
			layer = new QEllipse(m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle, frame, hollow);
			layer->SetPointStatr(event->pos());
			layer->SetPointEnd(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::TEXT:
		{
			SetTextEidtshowModel();
			layer = new QText(m_font, m_Pen, m_CurrentText_PenColor, m_CurrentBrushColor, m_PenStyle, frame, hollow);
			layer->SetPointStatr(event->pos());
			layer->SetPointEnd(event->pos());
			DrawStatus = DRAWING;
			IndexCount++;
			m_Layer.push_back(layer);
			if (!IndexCount)
				return;
			m_Layer[IndexCount - 1]->SetPictureStatus(false);
			update();
		}
		break;
		case CutPixmap::MOUSE:
		{

			SelectedChange(GetSelectedIndex(event->pos()));
			SetLastIndexPictureStatusFalse();
			if (CurrentIndexSelected >= 0)
				SendMessageDraw(m_Layer[CurrentIndexSelected]);
		};
		return;
		}
	}

}

void CutPixmap::viewMouseMoveEvent(QMouseEvent * event)
{
	m_PastePoint = event->pos();
	Q_UNUSED(event);
	if (CurrentIndexSelected >= 0 && DrawStatus == MOVING)
	{
		m_Layer[CurrentIndexSelected]->MoveCurrentDraw(m_PastePoint);
		m_Layer[CurrentIndexSelected]->SetPictureStatus(false);
		m_Layer[CurrentIndexSelected]->SetEghiteAngle(m_PenWidth * 2);

		update();
		return;
	}
	if (CurrentIndexSelected >= 0 && DrawStatus == IDEL)
	{
		m_Layer[CurrentIndexSelected]->GetCursorPos(&m_PastePoint);
		SetCursor();
	}
	if (LeftbuttonPress&&DrawStatus == DRAWING)
	{
		switch (m_DrawPenModel)
		{
		case CutPixmap::CURVE:
		{
			m_Layer[IndexCount]->Push_backPonit(m_PastePoint);
		}
		break;
		case CutPixmap::LINE:
		{
			m_Layer[IndexCount]->SetPointEnd(m_PastePoint);
		}
		break;
		case CutPixmap::RECT:
		{
			m_Layer[IndexCount]->SetPointEnd(m_PastePoint);
			m_Layer[IndexCount]->SetDrawRectCut();
		}
		break;
		case CutPixmap::ROUNDRECT:
		{
			m_Layer[IndexCount]->SetPointEnd(m_PastePoint);
			m_Layer[IndexCount]->SetDrawRectCut();
		}
		break;
		case CutPixmap::ELLIPSE:
		{
			m_Layer[IndexCount]->SetPointEnd(m_PastePoint);
			m_Layer[IndexCount]->SetDrawRectCut();
		}
		break;
		case CutPixmap::TEXT:
		{
			m_Layer[IndexCount]->SetPointEnd(m_PastePoint);
			m_Layer[IndexCount]->SetDrawRectCut();
			emit TextShow(&m_Layer[IndexCount]->GetRect());
			m_textEdit->setText(m_Layer[IndexCount]->GetTextString());
		}
		break;
		case CutPixmap::MOUSE:
			return;
		}
		update();
	}

}

void CutPixmap::viewMouseReleaseEvent(QMouseEvent * event)
{
	Q_UNUSED(event);

	if (event->button() == Qt::LeftButton)
	{
		LeftbuttonPress = false;
		DrawStatus = IDEL;
		switch (m_DrawPenModel)
		{
		case CutPixmap::CURVE:
		{
			m_Layer[IndexCount]->SetPointEnd(event->pos());
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::LINE:
		{
			m_Layer[IndexCount]->SetPictureStatus(true);
			m_Layer[IndexCount]->SetEghiteAngle(m_PenWidth * 2);
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::RECT:
		{
			m_Layer[IndexCount]->SetPictureStatus(true);
			m_Layer[IndexCount]->SetEghiteAngle(m_PenWidth * 2);
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::ROUNDRECT:
		{
			m_Layer[IndexCount]->SetPictureStatus(true);
			m_Layer[IndexCount]->SetEghiteAngle(m_PenWidth * 2);
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::ELLIPSE:
		{
			m_Layer[IndexCount]->SetPictureStatus(true);
			m_Layer[IndexCount]->SetEghiteAngle(m_PenWidth * 2);
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::TEXT:
		{
			m_Layer[IndexCount]->SetPictureStatus(false);
			//m_Layer[IndexCount]->SetEghiteAngle(m_PenWidth * 2);
			SelectedChange(IndexCount);
		}
		break;
		case CutPixmap::MOUSE:
		{

		}
		break;
		}
		if (CurrentIndexSelected >= 0)
		{
			m_Layer[CurrentIndexSelected]->SetPictureStatus(true);
			m_Layer[CurrentIndexSelected]->SetRectNormlized();
		}
		update();
	}
	if (event->button() == Qt::RightButton)
	{
		if (m_DrawPenModel == TEXT)
		{
			SetTextEidtshowModel();
			update();
			return;
		}
		if (CurrentIndexSelected >= 0)
		{
			m_Layer[CurrentIndexSelected]->SetPictureStatus(false);
			SelectedChange(-1);
		}
		update();
		return;
	}

}

void CutPixmap::viewfocusInEvent(QFocusEvent * event)
{
	Q_UNUSED(event);
}


void CutPixmap::GetShow_Hide(bool show_hide)
{
	if (show_hide)
	{
		show();
		m_MyShowDrawWidget->hide();
	}
	else
	{
		hide();
		m_HistoryPixmap->hide();
		SendLayer(m_Layer);
		update();
	}
}


void CutPixmap::GetCurrentBrushColor(QColor BrushColor)
{
	m_CurrentBrushColor = BrushColor;
	m_CurrentBrushColor.setAlpha(m_QDockToolbar->GetBrushTrans());
}


void CutPixmap::GetCurrentText_PenColor(QColor Text_Pen)
{
	m_CurrentText_PenColor = Text_Pen;
	m_textEdit->setTextColor(m_CurrentText_PenColor);
}

void CutPixmap::GetPenWidth()
{
	m_PenWidth = m_QDockToolbar->GetPenWidth();
	m_Pen.setWidth(m_PenWidth);
}

void CutPixmap::GetBrushTrans()
{
	m_CurrentBrushColor.setAlpha(m_QDockToolbar->GetBrushTrans());
}

void CutPixmap::GetEditText(QString str)
{
	if (str.isEmpty())
	{
		m_Layer.erase(m_Layer.begin() + CurrentIndexSelected);
		CurrentIndexSelected = -1;
		LastIndexSelected = -1;
		IndexCount--;
		return;
	}
	m_Layer[CurrentIndexSelected]->SetEidtText(str);
	update();
}

void CutPixmap::GetDrawFont()
{
	MyFontDialog fontdialog(this);
	fontdialog.setCurrentFont(m_font);
	int ok = fontdialog.exec();
	if (ok)
	{
		m_font = fontdialog.selectedFont();
		m_textEdit->setFont(m_font);
	}
}



void CutPixmap::GetDrawPenModel_MOUSE()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = MOUSE;
	setCursor(Qt::ArrowCursor);
	update();
}

void CutPixmap::GetDrawPenModel_CURVE()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = CURVE;
	setCursor(m_CursorVector[0]);
	update();
}

void CutPixmap::GetDrawPenModel_RECT()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = RECT;
	setCursor(m_CursorVector[1]);
	update();
}

void CutPixmap::GetDrawPenModel_ROUNDRECT()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = ROUNDRECT;
	setCursor(m_CursorVector[1]);
	update();
}

void CutPixmap::GetDrawPenModel_LINE()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = LINE;
	setCursor(m_CursorVector[2]);
	update();
}

void CutPixmap::GetDrawPenModel_ELLIPSE()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = ELLIPSE;
	setCursor(m_CursorVector[3]);
	update();
}

void CutPixmap::GetDrawPenModel_TEXT()
{
	SetTextEidtshowModel();
	SelectedChange(-1);
	SetLastIndexPictureStatusFalse();
	m_DrawPenModel = TEXT;
	setCursor(Qt::IBeamCursor);
	update();
}

void CutPixmap::GetLineStatusChanged(Qt::PenStyle penstyle)
{
	m_PenStyle = penstyle;
}

void CutPixmap::GetCurrentPictureIndex(int index)
{
	m_CurrentPictureIndex = index;
	m_Layer = m_CurrentPicture[m_CurrentPictureIndex];
	IndexCount = m_Layer.size() - 1;
	CurrentIndexSelected = -1;
	LastIndexSelected = -1;
	update();
}

void CutPixmap::frameStatus(int status)
{
	frame = status;
}

void CutPixmap::HollowStatus(int status)
{
	if (CurrentIndexSelected >= 0)
	{
		m_Layer[CurrentIndexSelected]->SetHollow(status);
	}
	hollow = status;
	update();
}

void CutPixmap::ChangedofTransDynamicdisplay()
{

	m_Layer[CurrentIndexSelected]->SetAlpha(m_QDockToolbar->GetBrushTrans());
	update();
}

void CutPixmap::OnCloseWindow()
{
	exit(0);
}

void CutPixmap::OnPictureCopy()
{
	if (CurrentIndexSelected >= 0)
	{
		layercopy = m_Layer[CurrentIndexSelected];
	}
}

void CutPixmap::OnPicturePaste()
{
	if (layercopy == NULL)
		return;
	QLayer*temp;
	switch (layercopy->GetCLASSNAME())
	{
	case QLayer::CURVE:
	{
		temp = new QCurve;
	}break;
	case QLayer::LINE:
	{
		temp = new  QStraightLine;
		temp->CopyLayer(layercopy);
		temp->SetCenterPoint(m_PastePoint);
		temp->SetEghiteAngle(temp->GetFontWidth());
		temp->SetPictureStatus(true);
		m_Layer.push_back(temp);
	}break;
	case QLayer::RECT:
	{
		temp = new QRectDraw;
		temp->CopyLayer(layercopy);
		temp->SetCenterPoint(m_PastePoint);
		temp->SetEghiteAngle(temp->GetFontWidth());
		temp->SetPictureStatus(true);
		m_Layer.push_back(temp);
	}break;
	case QLayer::ROUNDRECT:
	{
		temp = new QRoundRect;
		temp->CopyLayer(layercopy);
		temp->SetCenterPoint(m_PastePoint);
		temp->SetEghiteAngle(temp->GetFontWidth());
		temp->SetPictureStatus(true);
		m_Layer.push_back(temp);
	}break;
	case QLayer::ELLIPSE:
	{
		temp = new QEllipse;
		temp->CopyLayer(layercopy);
		temp->SetCenterPoint(m_PastePoint);
		temp->SetEghiteAngle(temp->GetFontWidth());
		temp->SetPictureStatus(true);
		m_Layer.push_back(temp);
	}break;
	case QLayer::TEXT:
	{
		temp = new QText(QFont());
		temp->CopyLayer(layercopy);
		temp->SetCenterPoint(m_PastePoint);
		temp->SetEghiteAngle(temp->GetFontWidth());
		temp->SetPictureStatus(true);
		m_Layer.push_back(temp);
	}break;
	}
	SelectedChange(m_Layer.size() - 1);
	SetLastIndexPictureStatusFalse();
	IndexCount++;
	update();
}

void CutPixmap::OnPictureDelete()
{
	if (CurrentIndexSelected >= 0)
	{
		m_Layerdelete.push_back(m_Layer[CurrentIndexSelected]);
		m_Layer.erase(m_Layer.begin() + CurrentIndexSelected);
		CurrentIndexSelected = -1;
		LastIndexSelected = -1;
		IndexCount--;
		switch (m_DrawPenModel)
		{
		case CutPixmap::CURVE:setCursor(m_CursorVector[0]);
			break;
		case CutPixmap::LINE:setCursor(m_CursorVector[2]);
			break;
		case CutPixmap::RECT:setCursor(m_CursorVector[1]);
			break;
		case CutPixmap::ROUNDRECT:setCursor(m_CursorVector[1]);
			break;
		case CutPixmap::ELLIPSE:setCursor(m_CursorVector[3]);
			break;
		case CutPixmap::TEXT:setCursor(Qt::IBeamCursor);
			break;
		case CutPixmap::MOUSE:setCursor(Qt::ArrowCursor);
			break;
		}
		update();
	}
}

void CutPixmap::OnNewPicture()
{
		if (OnSaveCurrentPicture())
		{
			m_CurrentPictureSelected();
		}
		else
		{
			if (m_Layer.size() == 0)
			{
				return;
			}
			m_CurrentPictureSelected();
		}
		m_Layer = QVector<QLayer*>();
 		LastIndexSelected = -1;
		CurrentIndexSelected = -1;
		IndexCount = -1;

	update();
}

bool CutPixmap::OnSaveCurrentPicture()
{
	if (CurrentIndexSelected >= 0)
	{
		m_Layer[CurrentIndexSelected]->SetPictureStatus(false);
		update();
	}
	if (m_Layer.size() <= 0)
	{
		return false;
	}
	QMessageBox msg(QMessageBox::Question, QString::fromLocal8Bit("保存"),
		QString::fromLocal8Bit("是否保存当前画板到历史"), QMessageBox::Save | QMessageBox::No, this);
	msg.setWindowIcon(QIcon(":/CutPixmap/Resources/color_palette.png"));
	if (msg.exec() == QMessageBox::No)
		return false;
	m_CurrentPicture[m_CurrentPictureIndex].swap(m_Layer);
	m_Layer = m_CurrentPicture[m_CurrentPictureIndex];
	::_sleep(300);
	m_CurrentPicturePixmap = QApplication::primaryScreen()->grabWindow(QApplication::desktop()->winId());
	m_CurrentPicturePixmap = m_CurrentPicturePixmap.scaled(m_PixmapSizeSclaed, Qt::KeepAspectRatio);
	
	m_HistoryPixmap->insertItem(m_CurrentPictureIndex, m_CurrentPicturePixmap,NULL);
	m_HistoryPixmap->removeItem(m_CurrentPictureIndex+1);
	

	return true;
}

void CutPixmap::OnHistoryCurrentPicture()
{
	int n = m_HistoryPixmap->count();
	if (m_HistoryPixmap->isHidden())
		m_HistoryPixmap->show();
	else
	{
		m_HistoryPixmap->hide();
	}
}


void CutPixmap::SetCursor()
{
	if (CurrentIndexSelected < 0)
		return;
	if (QLayer::LEFTTOP == m_Layer[CurrentIndexSelected]->GetCurPos() || QLayer::RIGHTBOTTOM == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		setCursor(Qt::SizeFDiagCursor);
		return;
	}
	if (QLayer::RIGHTTOP == m_Layer[CurrentIndexSelected]->GetCurPos() || QLayer::LEFTBOTTOM == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		setCursor(Qt::SizeBDiagCursor);
		return;
	}
	if (QLayer::CENTERTOP == m_Layer[CurrentIndexSelected]->GetCurPos() || QLayer::CENTERBOTTOM == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		setCursor(Qt::SizeVerCursor);
		return;
	}
	if (QLayer::CENTERRIGHT == m_Layer[CurrentIndexSelected]->GetCurPos() || QLayer::CENTERLEFT == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		setCursor(Qt::SizeHorCursor);
		return;
	}
	if (QLayer::INSIDE == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		setCursor(Qt::SizeAllCursor);
		return;
	}
	if (QLayer::DEFAULT == m_Layer[CurrentIndexSelected]->GetCurPos())
	{
		switch (m_DrawPenModel)
		{
		case CutPixmap::CURVE:setCursor(m_CursorVector[0]);
			break;
		case CutPixmap::LINE:setCursor(m_CursorVector[2]);
			break;
		case CutPixmap::RECT:setCursor(m_CursorVector[1]);
			break;
		case CutPixmap::ROUNDRECT:setCursor(m_CursorVector[1]);
			break;
		case CutPixmap::ELLIPSE:setCursor(m_CursorVector[3]);
			break;
		case CutPixmap::TEXT:setCursor(Qt::IBeamCursor);
			break;
		case CutPixmap::MOUSE:setCursor(Qt::ArrowCursor);
			break;
		}
	}



}

void CutPixmap::SelectedChange(int index)
{
	if (index == CurrentIndexSelected)
	{
		return;
	}
	else
	{
		if (CurrentIndexSelected >= 0)
		{
			LastIndexSelected = CurrentIndexSelected;
		}
		CurrentIndexSelected = index;
	}
}

void CutPixmap::SetTextEidtshowModel()
{
	if (!m_textEdit->isHidden() && CurrentIndexSelected >= 0)
	{
		emit TextHidde();
		if (CurrentIndexSelected < 0)
			return;
		m_Layer[CurrentIndexSelected]->SetPictureStatus(true);
		SetLastIndexPictureStatusFalse();
		update();
		return;
	}
}

void CutPixmap::addPictureToCombbox()
{
	::_sleep(300);
	m_CurrentPicturePixmap = QApplication::primaryScreen()->grabWindow(QApplication::desktop()->winId());
	m_CurrentPicturePixmap = m_CurrentPicturePixmap.scaled(m_PixmapSizeSclaed, Qt::KeepAspectRatio);
	m_HistoryPixmap->addItem(m_CurrentPicturePixmap, NULL);
}

//独立封装
void CutPixmap::m_CurrentPictureSelected()
{
	if (m_CurrentPicture.size() - 1 == m_HistoryPixmap->count())
	{
		if (m_CurrentPicture[m_CurrentPictureCount - 1].size() != 0)
		{
			m_CurrentPicture.push_back(QVector<QLayer*>());
			m_CurrentPictureCount++;
		}
	}
	else if (m_CurrentPicture.size() == m_HistoryPixmap->count())
	{
		m_CurrentPicture.push_back(QVector<QLayer*>());
		m_CurrentPictureCount++;
	}
	m_CurrentPictureIndex = m_CurrentPictureCount - 1;
}
