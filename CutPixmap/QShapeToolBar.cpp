#include "QShapeToolBar.h"
#include"CutPixmap.h"
#include"QDockToolbar.h"
QShapeToolBar::QShapeToolBar(QWidget *parent)
	: QToolBar(parent)
{
	SetWindowFlag();
	Setproperty();
	CreateAction();
	Connect(parent);
	parentparent = (CutPixmap*)(parent->parent());
	
}

QShapeToolBar::~QShapeToolBar()
{
	for (int i = 0; i < m_IconGroup.size(); i++)
	{
		delete m_IconGroup[i];
	}
}

void QShapeToolBar::paintEvent(QPaintEvent * event)
{

}



void QShapeToolBar::SetWindowFlag()
{
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
}





void QShapeToolBar ::Setproperty()
{
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/black.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/white.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/red.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/orange.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/yellow.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Qgreen.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/green.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Qblue.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/blue.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Sblue.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/purple.ico"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/color_palette.png"));
	this->setIconSize(QSize(36, 36));
	Width = (m_IconGroup.size()) * 44;
	Height = 50;
	Drawcheck = true;
	this->resize(Width, Height);
}

void QShapeToolBar::CreateAction()
{
	ColorDialog = new MyColorDialog(this);
	ColorBlack = new QAction(*m_IconGroup[0], QString::fromLocal8Bit("黑色"), this);
	addAction(ColorBlack);
	ColorWhite = new QAction(*m_IconGroup[1], QString::fromLocal8Bit("白色"), this);
	addAction(ColorWhite);
	ColorRed = new QAction(*m_IconGroup[2], QString::fromLocal8Bit("红色"), this);
	addAction(ColorRed);
	ColorOrange = new QAction(*m_IconGroup[3], QString::fromLocal8Bit("橘色"), this);
	addAction(ColorOrange);
	ColorYellow = new QAction(*m_IconGroup[4], QString::fromLocal8Bit("黄色"), this);
	addAction(ColorYellow);
	ColorQGreen = new QAction(*m_IconGroup[5], QString::fromLocal8Bit("浅绿色"), this);
	addAction(ColorQGreen);
	ColorGreen = new QAction(*m_IconGroup[6], QString::fromLocal8Bit("绿色"), this);
	addAction(ColorGreen);
	ColorQBlue = new QAction(*m_IconGroup[7], QString::fromLocal8Bit("浅蓝色"), this);
	addAction(ColorQBlue);
	ColorBlue = new QAction(*m_IconGroup[8], QString::fromLocal8Bit("蓝色"), this);
	addAction(ColorBlue);
	ColorSBlue = new QAction(*m_IconGroup[9], QString::fromLocal8Bit("深蓝色"), this);
	addAction(ColorSBlue);
	ColorPurple = new QAction(*m_IconGroup[10], QString::fromLocal8Bit("紫色"), this);
	addAction(ColorPurple);
	ColorBox = new QAction(*m_IconGroup[11], QString::fromLocal8Bit("画刷颜色"), this);
	addAction(ColorBox);
}

void QShapeToolBar::Connect(QWidget *parent)
{

	connect(ColorBlack, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorWhite, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorRed, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorOrange, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorYellow, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorQGreen, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorGreen, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorQBlue, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorBlue, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorSBlue, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorPurple, SIGNAL(triggered()), this, SLOT(UsuallyColor()));
	connect(ColorBox, SIGNAL(triggered()), this, SLOT(ColorSelected()));

	connect(this, SIGNAL(SelectCurrentBrushColor(QColor)), parent->parent(), SLOT(GetCurrentBrushColor(QColor)));
	connect(this,SIGNAL(SendCurrentBrushColor(QColor)),parent,SLOT(GetCurrentBrushColor(QColor)));
}

void QShapeToolBar::ColorSelected()
{
	int result= ColorDialog->exec();
	if (!result)
	{
		return;
	}
	else
	{
		m_BrushColor = ColorDialog->selectedColor();
		int n = parentparent->GetCurrentIndexSelected();
		if (n >= 0)
		{
			m_BrushColor.setAlpha(((QDockToolbar*)parent())->GetBrushTrans());
			parentparent->GetLayer()[n]->SetBrushColor(m_BrushColor);
			parentparent->update();
		}
		else
		{
			emit SendCurrentBrushColor(m_BrushColor);
			emit SelectCurrentBrushColor(m_BrushColor);
		}
	}
}


void QShapeToolBar::UsuallyColor()
{

	QAction *select=(QAction*)sender();
	if (select == ColorBlack)
	{
		m_BrushColor.setRgb(0, 0, 0);
	}
	else if (select == ColorWhite)
	{
		m_BrushColor.setRgb(255, 255, 255);
	}
	else if (select == ColorRed)
	{
		m_BrushColor.setRgb(255, 0, 0);
	}
	else if (select == ColorOrange)
	{
		m_BrushColor.setRgb(255, 192, 0);
	}
	else if (select == ColorYellow)
	{
		m_BrushColor.setRgb(255, 255, 1);
	}
	else if (select == ColorQGreen)
	{
		m_BrushColor.setRgb(146, 209, 79);
	}
	else if (select == ColorGreen)
	{
		m_BrushColor.setRgb(0, 175, 80);
	}
	else if (select == ColorQBlue)
	{
		m_BrushColor.setRgb(1, 176, 241);
	}
	else if (select == ColorBlue)
	{
		m_BrushColor.setRgb(0, 113, 193);
	}
	else if (select == ColorSBlue)
	{
		m_BrushColor.setRgb(1, 32, 96);
	}
	else if (select == ColorPurple)
	{
		m_BrushColor.setRgb(121, 48, 160);
	}
	else
		return;
	
	int n = parentparent->GetCurrentIndexSelected();
	if (n >= 0)
	{
		m_BrushColor.setAlpha(((QDockToolbar*)parent())->GetBrushTrans());
		parentparent->GetLayer()[n]->SetBrushColor(m_BrushColor);
		parentparent->update();
	}
	else
	{
		emit SendCurrentBrushColor(m_BrushColor);
		emit SelectCurrentBrushColor(m_BrushColor);
	}
}