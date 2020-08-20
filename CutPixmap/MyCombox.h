#pragma once

#include <QComboBox>
#include<qpainter.h>
class MyCombox : public QComboBox
{
	Q_OBJECT

public:
	MyCombox(QWidget *parent);
	~MyCombox();

signals:
	void LineStatusChanged(Qt::PenStyle);
private:
	void paintEvent(QPaintEvent*event);

private slots:
	void IndexChanged(int index);

private:
	Qt::PenStyle m_Style;
};
