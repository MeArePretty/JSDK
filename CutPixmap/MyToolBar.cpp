#include "MyToolBar.h"

MyToolBar::MyToolBar(QWidget *parent, int Width, QColor color)
	: QToolBar(parent)
{
	Setproperty(Width, color);
	CreateAction();
	Connect(parent);
}

MyToolBar::~MyToolBar()
{
	for (int i = 0; i < m_IconGroup.size(); i++)
	{
		delete m_IconGroup[i];
	}
}

void MyToolBar::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(m_color);
	painter.drawRect(0,0,width(),height());
}

void MyToolBar::Connect(QWidget *parent)
{
	connect(Actionsave, SIGNAL(triggered()), parent, SLOT(OnBtnSave()));
	connect(ActionFinish, SIGNAL(triggered()), parent, SLOT(OnBtnFinish()));
}

void MyToolBar::Setproperty(int Width, QColor color)
{
	setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	setFixedWidth(Width);
	m_color = color;
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/save.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/done.png"));
}

void MyToolBar::CreateAction()
{
	Actionsave = new QAction(*(m_IconGroup[0]), QString::fromLocal8Bit("±£´æ"), this);
	Actionsave->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	ActionFinish = new QAction(*(m_IconGroup[1]), QString::fromLocal8Bit("Íê³É"), this);
	ActionFinish->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
	addAction(Actionsave);
	addAction(ActionFinish);
}
