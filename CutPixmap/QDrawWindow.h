#pragma once

#include <QWidget>
#include<qpainter.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
#include<qvector.h>
#include"QLayer.h"
#include <QGraphicsScene> 
#include <QGraphicsView> 
#include<QGraphicsTextItem>
#include"MyGraphicsView.h"
#include<QMouseEvent>
#include"TransToolBar.h"
#define SCREEN_WIDTH    QApplication::desktop()->width()
#define SCREEN_HEIGHT   QApplication::desktop()->height()

class QDrawWindow : public QWidget
{
	Q_OBJECT

public:
	QDrawWindow(QWidget *parent=0);
	~QDrawWindow();

private slots:
	void GetShow_Hide(bool);

private:
	void SetWindowFlag();
private:
	void focusInEvent(QFocusEvent*event);
	void paintEvent(QPaintEvent*event);
public:
	void viewWheelEvent(QWheelEvent *event);
	void viewMousePressEvent(QMouseEvent *event);
	void viewMouseMoveEvent(QMouseEvent *event);
	void viewMouseReleaseEvent(QMouseEvent *event);
private:
	QVector<QLayer*> m_Layer;
	QGraphicsScene  *m_pScene;          //场景
	MyGraphicsView  *m_pView;           //视图
	TransToolBar * m_toolbar;
	static QDrawWindow  *m_pInstance;
public:

	//本类实例
	static QDrawWindow  *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = new QDrawWindow;
		}
		return m_pInstance;
	}
};
