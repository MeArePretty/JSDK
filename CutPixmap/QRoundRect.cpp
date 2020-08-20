#include "QRoundRect.h"

QRoundRect::QRoundRect(QPen pen, QColor Foreground, QColor Background, Qt::PenStyle PenStyle,bool frame, bool hollow) :
	QLayer(pen, Foreground, Background, PenStyle,frame, hollow)
{
	m_CLASSNAME = ROUNDRECT;
}

QRoundRect::~QRoundRect()
{
}

void QRoundRect::Draw(QPainter * m_Painter)
{
	if (Frame)
	{
		m_Painter->setPen(m_Pen);
	}
	else
	{
		m_Painter->setPen(Qt::NoPen);
	}
	if (Hollow)
	{
		m_Painter->setBrush(Qt::NoBrush);
	}
	else
	{
		m_Painter->setBrush(m_Background);
	}
	
	m_Painter->drawRoundRect(XY_Rnd());
	if (m_PictureStatus == SELECTED)
	{
		m_Painter->setPen(Qt::SolidLine);
		m_Painter->setPen(QColor(0, 0, 0));
		m_Painter->setBrush(QColor(0, 0, 0));
		m_Painter->drawRects(m_ptrRect, 8);
		m_Painter->setBrush(Qt::NoBrush);
		QPen temp;
		temp.setStyle(Qt::DashLine);
		temp.setColor(QColor(0, 0, 251));
		m_Painter->setPen(temp);
		m_Painter->drawRect(m_Rect);
	}
}

bool QRoundRect::MouseInside(QPoint point)
{
	return m_Rect.contains(point);
}

void QRoundRect::EghiteAngle(int Width)
{
	
	//m_ptrRect[0] = QRect(m_Rect.left() - Width/2, m_Rect.top() - Width/2, Width, Width);
	//m_ptrRect[1] = m_ptrRect[0].translated(m_Rect.width() / 2, 0);
	//m_ptrRect[2] = m_ptrRect[0].translated(m_Rect.width(), 0);
	//m_ptrRect[3] = m_ptrRect[2].translated(0, m_Rect.height() / 2);
	//m_ptrRect[4] = m_ptrRect[2].translated(0, m_Rect.height());
	//m_ptrRect[5] = m_ptrRect[4].translated(-m_Rect.width() / 2, 0);
	//m_ptrRect[6] = m_ptrRect[4].translated(-m_Rect.width(), 0);
	//m_ptrRect[7] = m_ptrRect[0].translated(0, m_Rect.height() / 2);
	QRect temp = m_Rect.normalized();
	m_ptrRect[0] = QRect(temp.left() - Width / 2, temp.top() - Width / 2, Width, Width);
	m_ptrRect[1] = m_ptrRect[0].translated(temp.width() / 2, 0);
	m_ptrRect[2] = m_ptrRect[0].translated(temp.width(), 0);
	m_ptrRect[3] = m_ptrRect[2].translated(0, temp.height() / 2);
	m_ptrRect[4] = m_ptrRect[2].translated(0, temp.height());
	m_ptrRect[5] = m_ptrRect[4].translated(-temp.width() / 2, 0);
	m_ptrRect[6] = m_ptrRect[4].translated(-temp.width(), 0);
	m_ptrRect[7] = m_ptrRect[0].translated(0, temp.height() / 2);
}

void QRoundRect::DrawRectCut()
{
	if (Start.x() < End.x() && Start.y() < End.y())//Start左上End右下
	{
		m_Rect = QRect(Start, End);
	}
	else if (Start.x() < End.x() && Start.y() > End.y())//Start左下End右上
	{
		m_Rect.setTopRight(End);
		m_Rect.setBottomLeft(Start);
	}
	else if (Start.x() > End.x() && Start.y() < End.y())//Start右下End左上
	{
		m_Rect.setTopRight(Start);
		m_Rect.setBottomLeft(End);
	}
	else//Start右上End左下
	{
		m_Rect = QRect(End, Start);
	}
}

void QRoundRect::CursorPos(QPoint * point)
{
	if (m_ptrRect[0].contains(*point))
	{
		m_CurPos = LEFTTOP;
		return;
	}
	if (m_ptrRect[1].contains(*point))
	{
		m_CurPos = CENTERTOP;
		return;
	}
	if (m_ptrRect[2].contains(*point))
	{
		m_CurPos = RIGHTTOP;
		return;
	}
	if (m_ptrRect[3].contains(*point))
	{
		m_CurPos = CENTERRIGHT;
		return;
	}
	if (m_ptrRect[4].contains(*point))
	{
		m_CurPos = RIGHTBOTTOM;
		return;
	}
	if (m_ptrRect[5].contains(*point))
	{
		m_CurPos = CENTERBOTTOM;
		return;
	}
	if (m_ptrRect[6].contains(*point))
	{
		m_CurPos = LEFTBOTTOM;
		return;
	}
	if (m_ptrRect[7].contains(*point))
	{
		m_CurPos = CENTERLEFT;
		return;
	}
	if (m_Rect.contains(*point))
	{
		m_CurPos = INSIDE;
		return;
	}
	m_CurPos = DEFAULT;
}

void QRoundRect::Copy(void* layer)
{
	memcpy(this, (QRoundRect*)layer, sizeof(QRoundRect));
}

void QRoundRect::MoveCurrentRect(QPoint point)
{
	//switch (m_CurPos)
	//{
	//case LEFTTOP:Start = point; break;
	//case RIGHTTOP: {Start.setY(point.y()); End.setX(point.x()); }break;
	//case RIGHTBOTTOM:End = point; break;
	//case LEFTBOTTOM: {Start.setX(point.x()); End.setY(point.y()); }break;
	//case CENTERTOP:Start.setY(point.y()); break;
	//case CENTERRIGHT:End.setX(point.x()); break;
	//case CENTERBOTTOM:End.setY(point.y()); break;
	//case CENTERLEFT:Start.setX(point.x()); break;
	//case INSIDE:
	//{
	//	Start += (point - m_First);
	//	End += (point - m_First);
	//	m_First = point;
	//}; break;
	//}
	switch (m_CurPos)
	{
	case LEFTTOP:m_Rect.setTopLeft(point); break;
	case RIGHTTOP: m_Rect.setTopRight(point); break;
	case RIGHTBOTTOM:m_Rect.setBottomRight(point); break;
	case LEFTBOTTOM:m_Rect.setBottomLeft(point); break;
	case CENTERTOP:m_Rect.setTop(point.y()); break;
	case CENTERRIGHT:m_Rect.setRight(point.x()); break;
	case CENTERBOTTOM:m_Rect.setBottom(point.y()); break;
	case CENTERLEFT:m_Rect.setLeft(point.x()); break;
	case INSIDE:
	{
		m_Rect.translate(point - m_First);
		m_First = point;
	}; break;
	}
}

void QRoundRect::CenterPoint(QPoint point)
{
	m_Rect.moveCenter(point);
}

QRect QRoundRect::XY_Rnd()
{
	if (!m_Rect.isValid())
	{
		return m_Rect.normalized();
	}
	return m_Rect;
}
