#pragma once

#include <QTextEdit>
#include<qpainter.h>
class MyPlaintText : public QTextEdit
{
	Q_OBJECT

public:
	MyPlaintText(QWidget *parent);
	~MyPlaintText();
signals:
	void SendEditText(QString);
private slots:
	void GetTextShow(QRect* rect);
	void GetTextHidde();

};
