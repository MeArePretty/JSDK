#pragma once
#include "QLayer.h"

class QStraightLine :
	public QLayer
{
public:
	QStraightLine(QPen pen = QPen(Qt::SolidLine), QColor Foreground = QColor(0, 0, 0), QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine);
	~QStraightLine();

private:
	void Draw(QPainter* m_Painter);
	bool MouseInside(QPoint point);
	void EghiteAngle(int Width);
	void CursorPos(QPoint* point);
	void MoveCurrentRect(QPoint point);
	void CenterPoint(QPoint point);
	void Copy(void*layer);
	
};

