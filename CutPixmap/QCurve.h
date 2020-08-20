#pragma once
#include "QLayer.h"
#include<qvector.h>
class QCurve :
	public QLayer
{
public:
	QCurve(QPen pen = QPen(Qt::SolidLine), QColor Foreground = QColor(0, 0, 0), QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine);
	~QCurve();

public:

private:
void Draw(QPainter* Painter);

inline void push_backPonit(QPoint point) { m_Point.push_back(point); };
private:
	QVector<QPoint>m_Point;
};

