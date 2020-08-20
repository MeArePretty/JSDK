#include "QShowDesk.h"

QShowDesk::QShowDesk(QWidget *parent)
	: QWidget(parent)
{
	Initi_Object();
	Initi_Window();
	Initi_Toolbar();
	Connect(parent);
}

QShowDesk::~QShowDesk()
{

}

void QShowDesk::Initi_Object()
{
	m_CutStatue = IDLE;
	m_End = m_Start = QPoint(0, 0);
	m_Press_Release = false;
}

void QShowDesk::Initi_Window()
{
	this->setMouseTracking(true);
	this->setWindowFlag(Qt::Window);
	this->setWindowFlag(Qt::FramelessWindowHint);
	m_Desktop_Pixmap = QApplication::primaryScreen()->grabWindow(QApplication::desktop()->winId());
	m_Desktop_Rect = QRect(0, 0, m_Desktop_Pixmap.width(), m_Desktop_Pixmap.height());
	this->resize(m_Desktop_Pixmap.size());
	this->showFullScreen();
}



void QShowDesk::Initi_Toolbar()
{
	m_Toolbar = new MyToolBar(this);
	m_Toolbar->hide();
}

void QShowDesk::DrawRectAngle(QPainter&painter)
{
	EghiteAngle();
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(232, 245, 251));
	painter.drawRects(m_ptrRect,_countof(m_ptrRect));
}

void QShowDesk::DrawRectCut(QPoint &p1, QPoint &p2)
{
	if (p1.x() < p2.x()&& p1.y() < p2.y())//p1左上p2右下
	{
		m_CurrentCut = QRect(p1, p2);
	}
	else if (p1.x() < p2.x() && p1.y() > p2.y())//p1左下p2右上
	{
		m_CurrentCut.setTopRight(p2);
		m_CurrentCut.setBottomLeft(p1);
	}
	else if (p1.x() > p2.x() && p1.y()< p2.y())//p1右下p2左上
	{
		m_CurrentCut.setTopRight(p1);
		m_CurrentCut.setBottomLeft(p2);
	}
	else//p1右上p2左下
	{
		m_CurrentCut = QRect(p2, p1);
	}
	//m_Start = m_CurrentCut.topLeft();
	//m_End = m_CurrentCut.bottomRight();
}

void QShowDesk::EghiteAngle()
{
	m_ptrRect[0] = QRect(m_CurrentCut.left() - 5, m_CurrentCut.top() - 5, 10, 10);
	m_ptrRect[1] = m_ptrRect[0].translated(m_CurrentCut.width()/2, 0);
	m_ptrRect[2] = m_ptrRect[0].translated(m_CurrentCut.width() , 0);
	m_ptrRect[3] = m_ptrRect[2].translated(0, m_CurrentCut.height()/2);
	m_ptrRect[4] = m_ptrRect[2].translated(0, m_CurrentCut.height());
	m_ptrRect[5] = m_ptrRect[4].translated(-m_CurrentCut.width() / 2, 0);
	m_ptrRect[6] = m_ptrRect[4].translated(-m_CurrentCut.width() , 0);
	m_ptrRect[7] = m_ptrRect[0].translated(0, m_CurrentCut.height() / 2);
}

void QShowDesk::Connect(QWidget *parent)
{
	connect(this, SIGNAL(WindowClose()), parent, SLOT(CutWindowclose()));
}

void QShowDesk::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	/*桌面绘制*/
	painter.setBrush(QBrush(m_Desktop_Pixmap));
	painter.drawRect(0,0, m_Desktop_Pixmap.width(), m_Desktop_Pixmap.height());
	/*灰暗绘制+外部绘制*/
	painter.setBrush(QBrush(QColor(0, 0, 0, 100)));
	painter.setPen(Qt::NoPen);
	
	QPainterPath path;
	QRegion temp = QRegion(m_Desktop_Rect).subtracted(QRegion(m_CurrentCut));
	path.addRegion(temp);
	painter.drawPath(path);
	if (m_CurrentCut.isEmpty())
	{
		return;
	}
	/*线条绘制*/
	QPen pen(QColor(232, 245, 251));
	pen.setWidth(5);
	painter.setPen(pen);
	painter.setBrush(Qt::NoBrush);
	painter.drawRect(m_CurrentCut);
	/*8个点绘制*/
	DrawRectAngle(painter);
}

void QShowDesk::mousePressEvent(QMouseEvent * event)
{
	m_Press_Release = true;
	if (Qt::LeftButton == event->button())
	{
		if (m_CurPos != DEFAULT)
		{
			m_First = event->pos();
			m_Toolbar->hide();
		}
		if (m_CutStatue == FINISH)
		{
			return;
		}
	}
	if (Qt::RightButton == event->button())
	{
		m_Toolbar->hide();
		return;
	}
	if (Qt::LeftButton == event->button() && m_CutStatue == IDLE)
	{
		m_Start = event->pos();
		m_CurrentCut.setTopLeft(m_Start);
		m_CutStatue = CUTTING;
	}
}

void QShowDesk::mouseReleaseEvent(QMouseEvent * event)
{
	m_Press_Release = false;
	if (Qt::LeftButton == event->button())
	{
		if (m_CutStatue == CUTTING)
		{
			m_CutStatue = FINISH;
			ToolBarPos();
			m_Toolbar->show();
		}
		if (m_CurPos != DEFAULT)
		{
			m_Start = m_CurrentCut.topLeft();
			m_End = m_CurrentCut.bottomRight();
			ToolBarPos();
			m_Toolbar->show();
		}
	}
	if (Qt::RightButton == event->button())
	{
		m_CutStatue = IDLE;
		m_CurrentCut = QRect(0, 0, 0, 0);
		update();
		return;
	}
}

void QShowDesk::mouseMoveEvent(QMouseEvent * event)
{
	if ( m_CutStatue== CUTTING)
	{
		m_End = event->pos();
		DrawRectCut(m_Start, m_End);
		update();
	}
	if (m_CutStatue == FINISH)
	{
		if (!m_Press_Release)
		{
			CursorPos(&(event->pos()));
			SetCursor(); 
		}
		else
		{
			MoveCurrentRect(event->pos());
			DrawRectCut(m_Start, m_End);
			update();
		}
	}
}

void QShowDesk::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Escape)
	{
		CloseBack();
	}
}


void QShowDesk::OnBtnSave()
{
	m_Current_Pixmap = m_Desktop_Pixmap.copy(m_CurrentCut);
	QDateTime time = QDateTime::currentDateTime();
	QString timestr = time.toString(QString::fromLocal8Bit("蒋家伟截图yyyyMMdd_hh mmss"));
	QString filename = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存"), "./"+ timestr, QString::fromLocal8Bit("PNG(*.png);;BMP(*.bmp);;jpg(*.jpg *.jpeg);;所有文件(*.*)"));
	if (filename.isEmpty())
		return;
	m_Current_Pixmap.save(filename);
	CloseBack();
}


void QShowDesk::OnBtnFinish()
{
	QClipboard *clipboard = QGuiApplication::clipboard();
	clipboard->setPixmap(m_Desktop_Pixmap.copy(m_CurrentCut));
	CloseBack();
}

void QShowDesk::CloseBack()
{
	this->close();
	emit WindowClose();
}

void QShowDesk::CursorPos(QPoint * point)
{
	if (m_ptrRect[0].contains(*point))
	{
		m_CurPos = LEFTTOP;
		return;
	}
	if (m_ptrRect[1].contains(*point))
	{
		m_CurPos = CENTERTOP;
		return;
	}
	if (m_ptrRect[2].contains(*point))
	{
		m_CurPos = RIGHTTOP;
		return;
	}
	if (m_ptrRect[3].contains(*point))
	{
		m_CurPos = CENTERRIGHT;
		return;
	}
	if (m_ptrRect[4].contains(*point))
	{
		m_CurPos = RIGHTBOTTOM;
		return;
	}
	if (m_ptrRect[5].contains(*point))
	{
		m_CurPos = CENTERBOTTOM;
		return;
	}
	if (m_ptrRect[6].contains(*point))
	{
		m_CurPos = LEFTBOTTOM; 
		return;
	}
	if (m_ptrRect[7].contains(*point))
	{
		m_CurPos = CENTERLEFT;
		return;
	}
	if (m_CurrentCut.contains(*point))
	{
		m_CurPos = INSIDE;
		return;
	}
	m_CurPos = DEFAULT;
}

void QShowDesk::SetCursor()
{
	if (LEFTTOP == m_CurPos || RIGHTBOTTOM == m_CurPos)
	{
		setCursor(Qt::SizeFDiagCursor);
		return;
	}
	if (RIGHTTOP == m_CurPos || LEFTBOTTOM == m_CurPos)
	{
		setCursor(Qt::SizeBDiagCursor);
		return;
	}
	if (CENTERTOP == m_CurPos || CENTERBOTTOM == m_CurPos)
	{
		setCursor(Qt::SizeVerCursor);
		return;
	}
	if (CENTERRIGHT == m_CurPos || CENTERLEFT == m_CurPos)
	{
		setCursor(Qt::SizeHorCursor);
		return;
	}
	if (INSIDE == m_CurPos)
	{
		setCursor(Qt::SizeAllCursor);
		return;
	}
	setCursor(Qt::ArrowCursor);
}

void QShowDesk::MoveCurrentRect(QPoint point)
{
	switch (m_CurPos)
	{
	case LEFTTOP:m_Start=point; break;
	case RIGHTTOP: {m_Start.setY(point.y()); m_End.setX(point.x()); }break;
	case RIGHTBOTTOM:m_End= point; break;
	case LEFTBOTTOM: {m_Start.setX(point.x()); m_End.setY(point.y()); }break;
	case CENTERTOP:m_Start.setY(point.y()); break;
	case CENTERRIGHT:m_End.setX(point.x()); break;
	case CENTERBOTTOM:m_End.setY(point.y()); break;
	case CENTERLEFT:m_Start.setX(point.x()); break;
	case INSIDE:
	{
		QPoint pt = (point - m_First);
		QPoint tempStart = m_Start + pt;
		QPoint tempEnd = m_End + pt;
		SidePos(tempStart, tempEnd);
		SetSidePos(pt);
		m_First = point;
	}; break;
	}
}


void QShowDesk::ToolBarPos()
{
	if (m_CurrentCut.bottom() + m_Toolbar->height() > height())
		m_Toolbar->move(m_CurrentCut.topRight() -= QPoint(200, -8));
	else
		m_Toolbar->move(m_CurrentCut.bottomRight() -= QPoint(200, -8));
}

void QShowDesk::SidePos(QPoint Start, QPoint End)
{
	if (Start.x() <= 0 && Start.y() <= 0)
	{
		m_SidePos = LEFTTOP;
		return;
	}
	if (Start.y() <= 0 && End.x() >= width())
	{
		m_SidePos = RIGHTTOP;
		return;
	}
	if (End.x() >= width() && End.y() >= height())
	{
		m_SidePos = RIGHTBOTTOM;
		return;
	}
	if (m_Start.x() <= 0 && End.y() >= height())
	{
		m_SidePos = LEFTBOTTOM;
		return;
	}
	if (Start.x() < 0)
	{
		m_SidePos = CENTERLEFT;
		return;
	}
	if (Start.y() < 0)
	{
		m_SidePos = CENTERTOP;
		return;
	}
	if (End.x() > width())
	{
		m_SidePos = CENTERRIGHT;
		return;
	}
	if (End.y() > height())
	{
		m_SidePos = CENTERBOTTOM;
		return;
	}
	m_SidePos = INSIDE;
}

void QShowDesk::SetSidePos(QPoint Dleat)
{
	switch (m_SidePos)
	{
	case LEFTTOP:
		break;
	case RIGHTTOP:
		break;
	case RIGHTBOTTOM:
		break;
	case LEFTBOTTOM: 
	{
		if (m_End.y() > height())
			{
			m_CurrentCut.moveTop(m_End.y()-height());
			}
	}
		break;
	case CENTERTOP: 
	case CENTERBOTTOM: {m_Start.setX(m_Start.x() + Dleat.x()); m_End.setX(m_End.x() + Dleat.x()); }
		break;
	case CENTERLEFT:
	case CENTERRIGHT: {m_Start.setY(m_Start.y() + Dleat.y()); m_End.setY(m_End.y() + Dleat.y()); }
		break;
	case INSIDE: {m_Start += Dleat; m_End += Dleat; };
		break;
	}
}
