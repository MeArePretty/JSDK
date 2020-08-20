#include "MyCombox.h"

MyCombox::MyCombox(QWidget *parent)
	: QComboBox(parent)
{
	m_Style = Qt::SolidLine;
	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(IndexChanged(int)));
}

MyCombox::~MyCombox()
{
}

void MyCombox::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(QColor(232, 245, 251, 100));
	painter.drawRect(0, 0, width() - 5, height() - 5);
	
	switch (m_Style)
	{
	case Qt::SolidLine: {
		painter.setPen(Qt::SolidLine); 
		painter.drawText(width()-50, (height() ) / 2+3,QString::fromLocal8Bit("实线"));
	}
		break;
	case Qt::DashLine: {
		painter.setPen(Qt::DashLine); 
		painter.drawText(width() - 50, (height()) / 2+3, QString::fromLocal8Bit("虚线"));
	}
		break;
	case Qt::DotLine: {
		painter.setPen(Qt::DotLine); 
		painter.drawText(width() - 50, (height() ) / 2+3, QString::fromLocal8Bit("点线"));
	}
		break;
	case Qt::DashDotLine: {
		painter.setPen(Qt::DashDotLine);
		painter.drawText(width() - 50, (height() ) / 2+3, QString::fromLocal8Bit("虚点线"));

	}
		break;
	}
	painter.drawLine(10, (height()-5) / 2, width()-55, (height() -5)/ 2);
}

void MyCombox::IndexChanged(int index)
{
	switch (index)
	{
	case 0:
	{
		m_Style = Qt::SolidLine;
	}break;
	case 1:
	{
		m_Style = Qt::DashLine;
	}break;
	case 2:
	{
		m_Style = Qt::DotLine;
	}break;
	case 3:
	{
		m_Style = Qt::DashDotLine;
	}break;
	}
	emit LineStatusChanged(m_Style);
	update();
}