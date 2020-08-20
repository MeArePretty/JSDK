#include "MyPlaintText.h"

MyPlaintText::MyPlaintText(QWidget *parent)
	: QTextEdit(parent)
{
	setWindowFlag(Qt::FramelessWindowHint);
	setWindowFlag(Qt::Window);
	connect(this, SIGNAL(SendEditText(QString)), parent, SLOT(GetEditText(QString)));
}

MyPlaintText::~MyPlaintText()
{
}

void MyPlaintText::GetTextHidde()
{
	hide();
	emit SendEditText(toPlainText());
}

void MyPlaintText::GetTextShow(QRect* rect)
{
	setGeometry(*rect);
	show();
	setFocus();
}