#include "MyColorDialog.h"

MyColorDialog::MyColorDialog(QWidget *parent)
	: QColorDialog(parent)
{
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	resize(960, 720);
	move((QApplication::desktop()->width()-640)/2 , (QApplication::desktop()->height()-480)/2);

}

MyColorDialog::~MyColorDialog()
{
}

void MyColorDialog::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(QColor(232, 245, 251, 100));
	painter.setPen(Qt::NoPen);
	painter.drawRoundRect(0,0,width(),height());
}


