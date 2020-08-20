#pragma once
#include "QLayer.h"
class QRoundRect :
	public QLayer
{
public:
	QRoundRect(QPen pen = QPen(Qt::SolidLine), QColor Foreground = QColor(0, 0, 0), QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine, bool frame = true, bool hollow = true);
	~QRoundRect();

private:
	 void Draw(QPainter* m_Painter);
	 bool MouseInside(QPoint point);
	 void EghiteAngle(int Width);
	 void DrawRectCut();
	 void CursorPos(QPoint* point);
	 void Copy(void* layer);
	 void MoveCurrentRect(QPoint point);
	 void RectNormlized() { m_Rect = m_Rect.normalized(); }
	 void CenterPoint(QPoint point);
	 QRect XY_Rnd();

};

