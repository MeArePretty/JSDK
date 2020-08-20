#include "QCurve.h"

QCurve::QCurve(QPen pen , QColor Foreground , QColor Background, Qt::PenStyle PenStyle ) :
	QLayer(pen, Foreground, Background, PenStyle)
{
	m_CLASSNAME = CURVE;
}

QCurve::~QCurve()
{
}

void QCurve::Draw(QPainter* Painter)
{
	Painter->setPen(m_Pen);
	Painter->drawPolyline(m_Point.begin(), m_Point.size());
}
