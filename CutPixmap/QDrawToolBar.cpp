#include "QDrawToolBar.h"

QDrawToolBar::QDrawToolBar(QWidget *parent)
	: QToolBar(parent)
{
	SetWindowFlag();
	Setproperty();
	CreateAction();
	Connect(parent);

}

QDrawToolBar::~QDrawToolBar()
{
	for (int i = 0; i < m_IconGroup.size(); i++)
	{
		delete m_IconGroup[i];
	}
}

void QDrawToolBar::paintEvent(QPaintEvent * event)
{

}


void QDrawToolBar::SetWindowFlag()
{
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
}



void QDrawToolBar::Setproperty()
{
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/click_cursor_mouse_pointer_select.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/line_curve.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/line.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/rectangle.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/roundedrectangle.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Ellipse.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/edit_text.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/Setfont.png"));
	m_IconGroup.push_back(new QIcon(":/CutPixmap/Resources/text.png"));
	this->setIconSize(QSize(36, 36));
	Width = (m_IconGroup.size()+1) * 44;
	Height = 50;
	Drawcheck = true;
	this->resize(Width, Height);
}

void QDrawToolBar::CreateAction()
{
	ColorDialog = new MyColorDialog(this);
	DefaultMouse = new QAction(*m_IconGroup[0], QString::fromLocal8Bit("默认鼠标"),this);
	addAction(DefaultMouse);
	LineCurve = new QAction(*m_IconGroup[1], QString::fromLocal8Bit("曲线"), this);
	addAction(LineCurve);
	StraightLine= new QAction(*m_IconGroup[2], QString::fromLocal8Bit("直线"), this);
	addAction(StraightLine);
	Rect= new QAction(*m_IconGroup[3], QString::fromLocal8Bit("矩形"), this);
	addAction(Rect);
	RoundRect= new QAction(*m_IconGroup[4], QString::fromLocal8Bit("圆角矩形"), this);
	addAction(RoundRect);
	Ellipse= new QAction(*m_IconGroup[5], QString::fromLocal8Bit("圆形"), this);
	addAction(Ellipse);
	Text= new QAction(*m_IconGroup[6], QString::fromLocal8Bit("文字"), this);
	addAction(Text);
	Font=new QAction(*m_IconGroup[7], QString::fromLocal8Bit("字体设置"), this);
	addAction(Font);
	TextColorBox = new QAction(*m_IconGroup[8], QString::fromLocal8Bit("线条色彩"), this);
	addAction(TextColorBox);
}

void QDrawToolBar::Connect(QWidget *parent)
{
	connect(TextColorBox, SIGNAL(triggered()), this, SLOT(ColorSelected()));
	connect(this, SIGNAL(SelectCurrentText_Pen(QColor)), parent->parent(), SLOT(GetCurrentText_PenColor(QColor)));
	connect(DefaultMouse, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_MOUSE()));
	connect(LineCurve, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_CURVE()));
	connect(this, SIGNAL(SendCurrentText_Pen(QColor)), parent, SLOT(GetCurrentPen_TextColor(QColor)));
	connect(StraightLine, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_LINE()));
	connect(Rect, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_RECT()));
	connect(RoundRect, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_ROUNDRECT()));
	connect(Ellipse, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_ELLIPSE()));
	connect(Text, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawPenModel_TEXT()));
	connect(Font, SIGNAL(triggered()), parent->parent(), SLOT(GetDrawFont()));
	
}

void QDrawToolBar::ColorSelected()
{
	int result = ColorDialog->exec();
	if (!result)
	{
		return;
	}
	else
	{
	m_Pen_TextColor = ColorDialog->selectedColor();
	 emit	SelectCurrentText_Pen(m_Pen_TextColor);
	 emit SendCurrentText_Pen(m_Pen_TextColor);
	}
}