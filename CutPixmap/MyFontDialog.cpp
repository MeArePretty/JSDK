#include "MyFontDialog.h"

MyFontDialog::MyFontDialog(QWidget *parent)
	: QFontDialog(parent)
{
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	resize(500, 360);
	move((QApplication::desktop()->width() - 640) / 2, (QApplication::desktop()->height() - 480) / 2);
}

MyFontDialog::~MyFontDialog()
{
}

void MyFontDialog::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(QColor(232, 245, 251, 100));
	painter.setPen(Qt::NoPen);
	painter.drawRoundRect(0, 0, width(), height());
}
