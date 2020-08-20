#include "QDrawWindow.h"

QDrawWindow* QDrawWindow::m_pInstance = NULL;

QDrawWindow::QDrawWindow(QWidget *parent)
	: QWidget(parent)
{
	SetWindowFlag();
	m_toolbar = new TransToolBar(this);
	m_toolbar->show();
	m_pScene = new QGraphicsScene(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	m_pView = new MyGraphicsView(m_pScene, this);
}

QDrawWindow::~QDrawWindow()
{

}

void QDrawWindow::SetWindowFlag()
{
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	setMouseTracking(true);
}

void QDrawWindow::focusInEvent(QFocusEvent * event)
{

}

void QDrawWindow::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(QColor(255, 255, 255, 100));
	painter.drawEllipse(500, 500, 500, 500);
}

void QDrawWindow::viewWheelEvent(QWheelEvent * event)
{
	Q_UNUSED(event);
}

void QDrawWindow::viewMousePressEvent(QMouseEvent * event)
{
	/*qDebug() << event->pos().x();*/
}

void QDrawWindow::viewMouseMoveEvent(QMouseEvent * event)
{
	Q_UNUSED(event);
}

void QDrawWindow::viewMouseReleaseEvent(QMouseEvent * event)
{
	Q_UNUSED(event);
}

void QDrawWindow::GetShow_Hide(bool show_hide)
{
	if (show_hide)
	{
		showFullScreen();
	}
	else
	{
		hide();
	}
}
