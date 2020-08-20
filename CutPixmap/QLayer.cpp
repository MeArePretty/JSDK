#include "QLayer.h"

QLayer::QLayer(QPen pen,QColor Foreground, QColor Background, Qt::PenStyle PenStyle,bool frame , bool hollow)
{
	m_Foreground = Foreground;
	m_Background = Background;
	m_BackgroudBrush.setColor(m_Background);
	m_BackgroudBrush.setStyle(Qt::SolidPattern);
	m_Pen = pen;
	m_Pen.setColor(m_Foreground);
	Hollow = hollow;
	Frame = frame;
	m_PenStyle = PenStyle;
	m_Pen.setStyle(m_PenStyle);

	m_PictureStatus = NOSELECTED;
	m_CurPos = DEFAULT;

	m_Rect = QRect(0, 0, 0, 0);
}

QLayer::QLayer(QFont font, QPen pen, QColor Foreground, QColor Background, Qt::PenStyle PenStyle, bool frame, bool hollow)
{
	m_Font = font;
	m_FontMetrics = new QFontMetrics(font);
	m_Foreground = Foreground;
	m_Background = Background;
	m_BackgroudBrush.setColor(m_Background);
	m_BackgroudBrush.setStyle(Qt::SolidPattern);
	m_Pen = pen;
	m_Pen.setColor(m_Foreground);
	Hollow = hollow;
	Frame = frame;
	m_PenStyle = PenStyle;
	m_Pen.setStyle(m_PenStyle);

	m_PictureStatus = NOSELECTED;
	m_CurPos = DEFAULT;

	m_Rect = QRect(0, 0, 0, 0);
}


QLayer::~QLayer()
{
	if(!m_FontMetrics)
	delete m_FontMetrics;
}




