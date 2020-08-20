#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
class CutPixmap;
class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	MyGraphicsView(QGraphicsScene *scene, QWidget *parent = 0);
	~MyGraphicsView();

protected:
	virtual void wheelEvent(QWheelEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void focusInEvent(QFocusEvent*event);
private:
	CutPixmap* m_Cutpixmap;
};

#endif // MYGRAPHICSVIEW_H