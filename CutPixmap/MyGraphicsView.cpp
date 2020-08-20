#include "MyGraphicsView.h"
#include"CutPixmap.h"

#include <QWheelEvent>
#include <QApplication>

MyGraphicsView::MyGraphicsView(QGraphicsScene *scene, QWidget *parent) :
	QGraphicsView(scene, parent)
{
	Q_ASSERT(scene != NULL);
	Q_ASSERT(parent != NULL);
	m_Cutpixmap = (CutPixmap*)parent;

	//1. 设置视图和屏幕一样大小 居中
	this->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	this->centerOn(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	//2. 设置不拖拽 以鼠标所在点缩放试图
	this->setDragMode(QGraphicsView::NoDrag);
	this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	//3. 关闭水平 垂直滚动条
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//4. 设置视图背景为透明
	QPalette  palette;
	QColor  color(255, 255, 255);
	color.setAlphaF(0.01);
	palette.setBrush(backgroundRole(), color);
	this->setPalette(palette);
	this->setStyleSheet("border:0px");//无边框，背景透明
}

MyGraphicsView::~MyGraphicsView()
{
}

void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
	m_Cutpixmap->viewWheelEvent(event);

	if (event->isAccepted() == false)
		QGraphicsView::wheelEvent(event);
}


void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
	m_Cutpixmap->viewMousePressEvent(event);

	if (event->isAccepted() == false)
		QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
	m_Cutpixmap->viewMouseMoveEvent(event);

	if (event->isAccepted() == false)
		QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
	m_Cutpixmap->viewMouseReleaseEvent(event);

	if (event->isAccepted() == false)
		QGraphicsView::mouseReleaseEvent(event);
}

void MyGraphicsView::focusInEvent(QFocusEvent * event)
{
	m_Cutpixmap->viewfocusInEvent(event);
	if (event->isAccepted() == false)
		QGraphicsView::focusInEvent(event);
}

