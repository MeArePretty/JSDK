#pragma once

#include <QToolBar>
#include<qpalette.h>
#include<qicon.h>
#include<qaction.h>
#include<qvector.h>
#include<qpainter.h>
#include <QKeySequence> 
class MyToolBar : public QToolBar
{
	Q_OBJECT

public:
	MyToolBar(QWidget *parent,int Width=200,QColor color=QColor(232, 245, 251,100));
	~MyToolBar();

private:
	QAction* Actionsave;
	QAction*ActionFinish;
	QVector<QIcon*>m_IconGroup;
	QColor m_color;
private:
	void paintEvent(QPaintEvent* event);

private:
	void Connect(QWidget *parent);
	void Setproperty(int Width, QColor color);
	void CreateAction();
};
