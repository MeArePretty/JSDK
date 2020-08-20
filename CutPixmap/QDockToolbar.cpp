#include "QDockToolbar.h"
#include"CutPixmap.h"
QDockToolbar::QDockToolbar(QWidget *parent)
	: QDockWidget(parent)
{
	SetWindowFlag();
	CreateWindow();
	Connect(parent);
}

QDockToolbar::~QDockToolbar()
{

}

void QDockToolbar::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(QColor(232, 245, 251, 100));
	painter.setPen(Qt::NoPen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawRoundRect(0, 0, this->width() , this->height() , 25, 25);
	painter.setPen(Qt::SolidLine);
	painter.setPen(QColor(255, 0, 0));
	painter.drawText(QPoint((width() - m_QShapeToolBar_Color->width()) / 2 + 450, 137),QString::fromLocal8Bit("线条宽度%1").arg(m_HSlider->value()));
	painter.drawText(QPoint((width() - m_QShapeToolBar_Color->width()) / 2 + 450, 167), QString::fromLocal8Bit("画刷透明度%1%").arg(m_HTransparency->value()));
	painter.setBrush(m_BrushColor);
	painter.drawText(QPoint((width() - m_QShapeToolBar_Color->width()) / 2 +10, 210), QString::fromLocal8Bit("当前画刷色彩:"));
	painter.setPen(QColor(0, 0, 0));
	painter.drawRect((width() - m_QShapeToolBar_Color->width()) / 2 + 90, 200, 36, 36);
	painter.setPen(QColor(255, 0, 0));
	painter.drawText(QPoint((width() - m_QShapeToolBar_Color->width()) / 2 + 180, 210), QString::fromLocal8Bit("当前线条色彩:"));
	painter.setBrush(m_Pen_TextColor);
	painter.setPen(QColor(0, 0, 0));
	painter.drawRect((width() - m_QShapeToolBar_Color->width()) / 2 +260, 200, 36, 36);
}

void QDockToolbar::SetWindowFlag()
{
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlag(Qt::Window);
}

void QDockToolbar::CreateWindow()
{

	m_BrushColor = QColor(232, 245, 251, 100);
	m_Pen_TextColor = QColor(0, 0, 0);

	m_ComboBox = new MyCombox(this);
	m_ComboBox->resize(100, 17);
	m_ComboBox->setIconSize(QSize(100, 17));
	m_ComboBox->addItem(QIcon(":/CutPixmap/Resources/solidline.png"),QString::fromLocal8Bit("实线"));
	m_ComboBox->addItem(QIcon(":/CutPixmap/Resources/dashline.png"), QString::fromLocal8Bit("虚线"));
	m_ComboBox->addItem(QIcon(":/CutPixmap/Resources/dotline.png"), QString::fromLocal8Bit("点线"));
	m_ComboBox->addItem(QIcon(":/CutPixmap/Resources/dashdotline.png"), QString::fromLocal8Bit("虚点线"));
	m_ComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	m_ComboBox->show();
	

	m_HSlider = new QSlider(Qt::Horizontal,this);
	m_HSlider->show();
	m_HSlider->setMaximum(40);
	m_HSlider->setMinimum(1);
	m_HSlider->setFixedWidth(400);
	m_HSlider->setValue(5);

	m_HTransparency= new QSlider(Qt::Horizontal, this);
	m_HTransparency->show();
	m_HTransparency->setMaximum(100);
	m_HTransparency->setMinimum(0);
	m_HTransparency->setFixedWidth(400);
	m_HTransparency->setValue(0);


	m_framebox = new QCheckBox(QString::fromLocal8Bit("边框"),this);
	m_framebox->setChecked(true);
	
	m_framebox->show();
	m_Hollowbox=new QCheckBox(QString::fromLocal8Bit("空心"),this);
	m_Hollowbox->setChecked(true);
	m_Hollowbox->show();

	m_QShapeToolBar_Color = new QShapeToolBar(this);
	m_QShapeToolBar_Color->show();
	m_QShapeToolBar_DrawModel = new QDrawToolBar(this);
	m_QShapeToolBar_DrawModel->show();
	Width = 640;
	Height = 270;
	resize(Width, Height+50);
	m_ComboBox->move((width() - m_QShapeToolBar_Color->width()) / 2 + 350+40, 85);
	m_QShapeToolBar_Color->move((width() - m_QShapeToolBar_Color->width()) / 2, 20);
	m_QShapeToolBar_DrawModel->move((width() - m_QShapeToolBar_Color->width()) / 2, 70);
	m_HSlider->move((width() - m_QShapeToolBar_Color->width()) / 2+10, 120);
	m_HTransparency->move((width() - m_QShapeToolBar_Color->width()) / 2 + 10, 150);
	m_framebox->move((width() - m_QShapeToolBar_Color->width()) / 2 + 450, 180);
	m_Hollowbox->move((width() - m_QShapeToolBar_Color->width()) / 2 + 450, 210);
}

void QDockToolbar::Connect(QWidget * parent)
{
	connect(m_HSlider, SIGNAL(sliderReleased()), parent, SLOT(GetPenWidth()));
	connect(m_HSlider, SIGNAL(valueChanged(int)), this, SLOT(WidthvalueChanged(int)));

	connect(m_HTransparency, SIGNAL(sliderReleased()), parent, SLOT(GetBrushTrans()));
	connect(m_HTransparency, SIGNAL(valueChanged(int)), this, SLOT(TransvalueChanged(int)));

	connect(m_framebox, SIGNAL(stateChanged(int )), parent, SLOT(frameStatus(int)));
	connect(m_Hollowbox, SIGNAL(stateChanged(int)), parent, SLOT(HollowStatus(int)));

	connect(m_ComboBox, SIGNAL(LineStatusChanged(Qt::PenStyle)), parent, SLOT(GetLineStatusChanged(Qt::PenStyle)));

	connect(this, SIGNAL(ChangedofTrans()), parent, SLOT(ChangedofTransDynamicdisplay()));
	//connect(parent,SIGNAL( SendMessageDraw(QLayer*)), this, SLOT(GetMessageDraw(QLayer*)));
}



void QDockToolbar::ShowFlash()
{
	animationStart = new QPropertyAnimation(this, "geometry");
	animationStart->setDuration(1000);
	animationStart->setStartValue(QRect((QApplication::desktop()->width() - Width) / 2, -Height, Width, Height));
	animationStart->setEndValue(QRect((QApplication::desktop()->width() - Width) / 2, 50, Width, Height));
	animationStart->setEasingCurve(QEasingCurve::InOutQuad);
	animationStart->start(QAbstractAnimation::DeleteWhenStopped);
	QRect rect=this->geometry();
	show();
}

void QDockToolbar::CloseFlash()
{
	animationEnd = new QPropertyAnimation(this, "geometry");
	animationEnd->setDuration(1000);
	animationEnd->setStartValue(QRect((QApplication::desktop()->width() - Width) / 2, 50, Width, Height));
	animationEnd->setEndValue(QRect((QApplication::desktop()->width() - Width) / 2, -Height, Width, Height));
	animationEnd->setEasingCurve(QEasingCurve::InOutQuad);
	animationEnd->start(QAbstractAnimation::DeleteWhenStopped);
	connect(animationEnd, SIGNAL(finished()), this, SLOT(OnAnimationEnd()));
	QRect rect = this->geometry();
}

void QDockToolbar::WidthvalueChanged(int value)
{
	update();
}

void QDockToolbar::TransvalueChanged(int value)
{
	if(((CutPixmap*)parent())->GetCurrentIndexSelected()>=0)
	emit ChangedofTrans();
	update();
}

void QDockToolbar::OnAnimationEnd()
{
	hide();
}


int QDockToolbar::GetPenWidth()
{
	return m_HSlider->value();
}

int QDockToolbar::GetBrushTrans()
{	
	return 255*(1-((float)m_HTransparency->value())/100);
}

void QDockToolbar::GetCurrentBrushColor(QColor color)
{
	m_BrushColor = color;
	update();
}

void QDockToolbar::GetCurrentPen_TextColor(QColor color)
{
	m_Pen_TextColor = color;
	update();
}

void QDockToolbar::GetMessageDraw(QLayer * layer)
{
	m_HSlider->setValue(layer->GetFontWidth());
	m_framebox->setChecked(layer->isframe());
	m_Hollowbox->setChecked(layer->isHollow());
	m_BrushColor = layer->GetBackground();
	m_PenStyle = layer->GetPenStyle();
	m_Pen_TextColor = layer->GetForeground();
	m_HTransparency->setValue(100-((float)layer->GetColorAlpha())*20/51);
	update();
}
