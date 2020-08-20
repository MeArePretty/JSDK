#pragma once

#include <QWidget>
#include<qpainter.h>
#include"QLayer.h"
#include<qvector.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
class MyShowDrawWidget : public QWidget
{
	Q_OBJECT

public:
	MyShowDrawWidget(QWidget *parent);
	~MyShowDrawWidget();
private:
	void paintEvent(QPaintEvent*event);

private slots:
	void GetLayer(QVector<QLayer*>layer);

private:
	QVector<QLayer*> m_Layer;

};
