#pragma once

#include <QColorDialog>
#include<qpainter.h>
#include<qcolor.h>
#include<qpixmap.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
class MyColorDialog : public QColorDialog
{
	Q_OBJECT

public:
	MyColorDialog(QWidget *parent);
	~MyColorDialog();

private:
	void paintEvent(QPaintEvent*event);

};
