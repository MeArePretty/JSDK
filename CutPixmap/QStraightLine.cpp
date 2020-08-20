#include "QStraightLine.h"

QStraightLine::QStraightLine(QPen pen, QColor Foreground, QColor Background, Qt::PenStyle PenStyle ):
	QLayer(pen, Foreground, Background, PenStyle)
{
	m_CLASSNAME = LINE;
}

QStraightLine::~QStraightLine()
{
}

void QStraightLine::Draw(QPainter * m_Painter)
{
	m_Painter->setPen(m_Pen);
	m_Painter->drawLine(Start,End);
	if (m_PictureStatus == SELECTED)
	{
		m_Painter->setPen(Qt::SolidLine);
		m_Painter->setPen(QColor(0, 0, 0));
		m_Painter->setBrush(QColor(0, 0, 0));
		m_Painter->drawRects(m_ptrStraight, 2);
		QPen temp;
		temp.setStyle(Qt::DashLine);
		temp.setColor(QColor(0, 0, 251));
		m_Painter->setPen(temp);
		m_Painter->drawLine(Start, End);
	}
}

bool QStraightLine::MouseInside(QPoint point)
{
	float fenzi = abs((End.y() - Start.y())*point.x() - (End.x() - Start.x())*point.y() + Start.y()*End.x() - Start.x()*End.y());
	float fenmu = sqrtf(powf(End.y() - Start.y(), 2) + powf(End.x() - Start.x(), 2));
	QRect rect2= QRect(Start, End).normalized();
	if ((fenzi / fenmu <= 5) && ((point.x()>rect2.left()&&point.x()<rect2.right())||(point.y()>rect2.top()&&point.y()<rect2.bottom())))
		return true;
	else
		return false;
}

void QStraightLine::EghiteAngle(int Width)
{
	m_ptrStraight[0] = QRect(Start.x() - Width/2, Start.y() - Width / 2, Width, Width);
	m_ptrStraight[1]= QRect(End.x() - Width / 2, End.y() - Width / 2, Width, Width);
}

void QStraightLine::CursorPos(QPoint * point)
{
	if (m_ptrStraight[1].contains(*point))
	{
		m_CurPos = CENTERBOTTOM;
		return;
	}
	if (m_ptrStraight[0].contains(*point))
	{
		m_CurPos = CENTERTOP;
		return;
	}
	if (MouseInside(*point))
	{
		m_CurPos = INSIDE;
		return;
	}
	m_CurPos = DEFAULT;
}

void QStraightLine::MoveCurrentRect(QPoint point)
{
	switch (m_CurPos)
	{
	case CENTERTOP:Start=point; break;
	case CENTERBOTTOM:End= point; break;
	case INSIDE:
	{
		Start += (point - m_First);
		End+= (point - m_First);
		m_First = point;
	}; break;
	}
}

void QStraightLine::CenterPoint(QPoint point)
{
	QPoint Center((Start.x() + End.x()) / 2, (Start.y() + End.y()) / 2);
	Start += point - Center;
	End += point - Center;
}

void QStraightLine::Copy(void*layer)
{
	memcpy(this, (QStraightLine*)layer, sizeof(QStraightLine));
}


