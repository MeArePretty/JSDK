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
class CutPixmap ;
class QShapeToolBar : public QToolBar
{
	Q_OBJECT

public:
	QShapeToolBar(QWidget *parent);
	~QShapeToolBar();

signals:
	void SelectCurrentBrushColor(QColor);
	void SendCurrentBrushColor(QColor);
private:
	void paintEvent(QPaintEvent*event);

private slots:
	void ColorSelected();
	void UsuallyColor();
public:
	
	void Setproperty();
	void SetWindowFlag();
	void CreateAction();
	void Connect(QWidget *parent);
	inline QColor CurrentBrushColor() { return m_BrushColor; };
private:
	QVector<QIcon*> m_IconGroup;
	QAction*ColorBlack;
	QAction*ColorWhite;
	QAction*ColorRed;
	QAction*ColorOrange;
	QAction*ColorYellow;
	QAction*ColorQGreen;
	QAction*ColorGreen;
	QAction*ColorQBlue;
	QAction*ColorBlue;
	QAction*ColorSBlue;
	QAction*ColorPurple;
	QAction*ColorBox;
	MyColorDialog*ColorDialog;
	CutPixmap * parentparent;
private:
	int Width;
	int Height;
	bool Drawcheck;
	QColor m_BrushColor;
};
