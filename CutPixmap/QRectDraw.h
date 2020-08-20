#pragma once
#include "QLayer.h"
class QRectDraw :
	public QLayer
{
public:
	QRectDraw(QPen pen = QPen(Qt::SolidLine), QColor Foreground = QColor(0, 0, 0), 
		QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine, bool frame = true, bool hollow = true);
	~QRectDraw();

private:
	void Draw(QPainter* m_Painter);
	bool MouseInside(QPoint point);
	void DrawRectCut();
	void EghiteAngle(int Width);
	void CursorPos(QPoint* point);
	void MoveCurrentRect(QPoint point);
	void Copy(void* layer);
	void RectNormlized() { m_Rect = m_Rect.normalized(); }
	void CenterPoint(QPoint point);
	
};

