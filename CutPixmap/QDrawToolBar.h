#pragma once
#pragma once

#include <QToolBar>
#include<qpropertyanimation.h>
#include<qpainter.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
#include<qvector.h>
#include<qaction.h>
#include <QFocusEvent> 
#include"MyColorDialog.h"
class QDrawToolBar : public QToolBar
{
	Q_OBJECT

public:
	QDrawToolBar(QWidget *parent);
	~QDrawToolBar();

signals:
	void SelectCurrentText_Pen(QColor);
	void SendCurrentText_Pen(QColor);

private:
	void paintEvent(QPaintEvent*event);

private slots:
	void ColorSelected();

public:

	void Setproperty();
	void SetWindowFlag();
	void CreateAction();
	void Connect(QWidget *parent);
private:
	QVector<QIcon*> m_IconGroup;
	QAction*DefaultMouse;
	QAction*LineCurve;
	QAction*StraightLine;
	QAction*Rect;
	QAction*RoundRect;
	QAction*Ellipse;
	QAction*Text;
	QAction*Font;
	QAction*TextColorBox;
	MyColorDialog*ColorDialog;
private:
	int Width;
	int Height;
	bool Drawcheck;
	QColor m_Pen_TextColor;
};
