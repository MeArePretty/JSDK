#pragma once

#include <QFontDialog>
#include<qpainter.h>
#include<qcolor.h>
#include<qdesktopwidget.h>
#include<qapplication.h>

class MyFontDialog : public QFontDialog
{
	Q_OBJECT

public:
	MyFontDialog(QWidget *parent);
	~MyFontDialog();

private:
	void paintEvent(QPaintEvent*event);
};
