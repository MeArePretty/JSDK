#pragma once

#include <QDockWidget>
#include<qpainter.h>
#include<qpropertyanimation.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
#include<qtoolbar.h>
#include<qslider.h>
#include<qcheckbox.h>
#include<qicon.h>

#include"QShapeToolBar.h"
#include"QDrawToolBar.h"
#include"MyCombox.h"
#include"QLayer.h"
class QDockToolbar : public QDockWidget
{
	Q_OBJECT

public:
	QDockToolbar(QWidget *parent);
	~QDockToolbar();

signals:
	void SendDrawcheck(bool);
	void ChangedofTrans();
private:
	QPropertyAnimation * animationStart;
	QPropertyAnimation * animationEnd;

private slots:
	void OnAnimationEnd();
	void ShowFlash();
	void CloseFlash();
	void WidthvalueChanged(int value);
	void TransvalueChanged(int value);
	void GetCurrentBrushColor(QColor);
	void GetCurrentPen_TextColor(QColor);
	void GetMessageDraw(QLayer*layer);
private:
	void paintEvent(QPaintEvent*event);

private:
	void SetWindowFlag();
	void CreateWindow();
	void Connect(QWidget *parent);
public:
	int GetPenWidth();
	int GetBrushTrans();

private:
	QShapeToolBar * m_QShapeToolBar_Color;
	QDrawToolBar* m_QShapeToolBar_DrawModel;
	QSlider* m_HSlider;
	QSlider* m_HTransparency;
	QColor m_BrushColor;
	QColor m_Pen_TextColor;
	QCheckBox*m_framebox;
	QCheckBox*m_Hollowbox;
	MyCombox*m_ComboBox;
	Qt::PenStyle m_PenStyle;
	bool Drawcheck;
	int Width;
	int Height;
};
