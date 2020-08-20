#include "MyShowDrawWidget.h"

MyShowDrawWidget::MyShowDrawWidget(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlag(Qt::Window);
	setWindowFlag(Qt::SubWindow);
	connect(parent, SIGNAL(SendLayer(QVector<QLayer*>)),this, SLOT(GetLayer(QVector<QLayer*>)));
}

MyShowDrawWidget::~MyShowDrawWidget()
{
}

void MyShowDrawWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	for (int i = 0; i < m_Layer.size(); i++)
	{
		m_Layer[i]->DrawMap(&painter);
	}
}

void MyShowDrawWidget::GetLayer(QVector<QLayer*>layer)
{
	m_Layer = layer;
	update();
	/*m_MyShowDrawWidget->*/showFullScreen();
}
