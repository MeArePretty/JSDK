#include "TransToolBar.h"

TransToolBar::TransToolBar(QWidget *parent)
	: QToolBar(parent)
{
	Setproperty();
	SetWindowFlag();
	CreateAction();
	Connect(parent);
}

void TransToolBar::SetWindowFlag()
{
	this->setWindowFlag(Qt::Window);
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->resize(65* m_IconGroup .size()-1+10, 63);
	this->move(QApplication::desktop()->width()/2-width()/2, QApplication::desktop()->height()-130);
}

void TransToolBar::Setproperty()
{
	m_Press_Release = false;
	drawcheck = true;
	CLOSEOPEN = false;
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/good.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Opened_Lock.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Closed_Lock.png"));

	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/pen.png"));

	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/new_128px.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/save_128px.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/history.png"));

	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/photo.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/close.png"));
	this->setIconSize(QSize(65, 63));
}

void TransToolBar::CreateAction()
{

	ActionStart = new QAction(*m_IconGroup[0], "Good", this);
	addAction(ActionStart);
	ActionLock = new QAction(*m_IconGroup[2],"Lock", this);
	addAction(ActionLock);
	
	ActionDraw=new QAction(*m_IconGroup[3], "Draw", this);
	//ActionDraw->setCheckable(true);
	addAction(ActionDraw);

	ActionNew= new QAction(*m_IconGroup[4], "NewFile", this);
	addAction(ActionNew);


	ActionSave = new QAction(*m_IconGroup[5], "Save", this);
	addAction(ActionSave);

	ActionHistory = new QAction(*m_IconGroup[6], "History", this);
	addAction(ActionHistory);

	ActionCut = new  QAction(*m_IconGroup[7], "Cut", this);
	addAction(ActionCut);
	
	ActionClose = new QAction(*m_IconGroup[8], "close", this);
	addAction(ActionClose);
}

void TransToolBar::Connect(QWidget *parent)
{
	connect(ActionCut, SIGNAL(triggered()), this, SLOT(OnBtnCut()));
	connect(ActionLock, SIGNAL(triggered()), this, SLOT(OnBtnLock()));
	connect(ActionDraw, SIGNAL(triggered()), this, SLOT(OnBtnDraw()));
	connect(ActionClose, SIGNAL(triggered()), parent, SLOT(OnCloseWindow()));
	connect(ActionSave, SIGNAL(triggered()), parent, SLOT(OnSaveCurrentPicture()));
	connect(ActionHistory, SIGNAL(triggered()), parent, SLOT(OnHistoryCurrentPicture()));
	connect(ActionNew, SIGNAL(triggered()), parent, SLOT(OnNewPicture()));
	connect(this, SIGNAL(SendShow_Hide(bool)), parent, SLOT(GetShow_Hide(bool)));
}


TransToolBar::~TransToolBar()
{
	for (int i = 0; i < m_IconGroup.size(); i++)
	{
		delete m_IconGroup[i];
	}
}

void TransToolBar::paintEvent(QPaintEvent * event)
{
	QWidget::paintEvent(event);
}

void TransToolBar::mouseMoveEvent(QMouseEvent * event)
{
	this->move(event->globalPos());
}



void TransToolBar::OnBtnCut()
{
	this->hide();
	QThread::msleep(300);
	m_QShowDesk = new QShowDesk(this);
}

void TransToolBar::CutWindowclose()
{
	this->showNormal();
}

void TransToolBar::OnBtnLock()//1 open 2 close false
{
	if (CLOSEOPEN)
	{
		ActionLock->setIcon(*m_IconGroup[2]);
		ActionSave->setEnabled(true);
		ActionNew->setEnabled(true); 
		ActionHistory->setEnabled(true);
	}
	else
	{
		ActionLock->setIcon(*m_IconGroup[1]);
		ActionSave->setEnabled(false);
		ActionNew->setEnabled(false);
		ActionHistory->setEnabled(false);
	}
	emit SendShow_Hide(CLOSEOPEN);
	CLOSEOPEN = !CLOSEOPEN;
}

void TransToolBar::OnBtnDraw()
{

	if (drawcheck)
	{
		emit ShowFlash();
		emit ModifyCloseFlashValue();
	}
		
	else
	{
		emit CloseFlash();
	}
	drawcheck = !drawcheck;
}

void TransToolBar::ModifyCloseFlash()
{
	emit CloseFlash();
	drawcheck = true;
}




