#pragma once
#include<qcolor.h>
#include<qrect.h>
#include<qpoint.h>
#include<qpen.h>
#include<qpainter.h>
#include<qfont.h>
#include <QFontMetrics> 
class QLayer
{
public:
	QLayer(QPen pen=QPen(Qt::SolidLine) ,QColor Foreground = QColor(0, 0, 0), 
		QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine,bool frame=true,bool hollow=true);

	QLayer(QFont font,QPen pen = QPen(Qt::SolidLine), QColor Foreground = QColor(0, 0, 0), 
		QColor Background = QColor(0, 0, 0), Qt::PenStyle PenStyle = Qt::SolidLine, bool frame = true, bool hollow = true);
	
	virtual ~QLayer();
	enum PictureStatus {SELECTED,NOSELECTED};
	enum RectCurPos {
		LEFTTOP, CENTERTOP, RIGHTTOP, CENTERRIGHT, RIGHTBOTTOM,
		CENTERBOTTOM, LEFTBOTTOM, CENTERLEFT, INSIDE, DEFAULT
	};
	enum CLASS {CURVE, LINE, RECT, ROUNDRECT, ELLIPSE, TEXT };
protected:
	QColor m_Foreground;//文字颜色
	QColor m_Background;//填充色
	QPen	   m_Pen;
	QBrush m_BackgroudBrush;
	QPoint Start;
	QPoint End;
	QPoint m_First;
	bool Hollow;
	bool Frame;
	Qt::PenStyle m_PenStyle;
	QRect m_ptrRect[8];
	QRect m_ptrStraight[2];
	PictureStatus m_PictureStatus;
	RectCurPos m_CurPos;
	CLASS m_CLASSNAME;
	int FontWidth;
	int ColorAlpha;

protected:
	QPoint m_point[2];//直线

protected:
	QRect m_Rect;//矩形


protected:
	QString m_Text;

protected:
	QFont m_Font;
	QFontMetrics* m_FontMetrics;
protected:
	virtual void Draw(QPainter* m_Painter) = 0;
	virtual  void push_backPonit(QPoint point) {}
	virtual  void EghiteAngle(int Width) {}
	virtual bool MouseInside(QPoint) { return false; }
	virtual void CursorPos(QPoint* point) {}
	virtual void MoveCurrentRect(QPoint point) {}
	virtual void DrawRectCut() {}
	virtual void RectNormlized() {}
	virtual void CenterPoint(QPoint point) {}
	virtual void Copy(void* layer) {};
public:
	inline void DrawMap(QPainter* m_Painter) { Draw(m_Painter);}
	inline void Push_backPonit(QPoint point) { push_backPonit(point); }
	inline void SetPointStatr(QPoint start) { Start = start; }
	inline void SetPointEnd(QPoint end) { End = end; }
	inline bool isHollow() { return Hollow; }
	//inline void SetHollow(int hollow) { Hollow = hollow; };
	//inline void Setframe(int frame) { Frame = Frame; };
	inline bool isframe() { return Frame; }
	inline void SetPictureStatus(bool Status) { m_PictureStatus = Status ? SELECTED : NOSELECTED; }
	inline void SetEghiteAngle(int Width) { FontWidth = Width; EghiteAngle(FontWidth); }
	inline bool IsMouseInside(QPoint point) { return MouseInside(point); }
	inline RectCurPos GetCurPos() {return m_CurPos;}
	inline void GetCursorPos(QPoint* point) { CursorPos(point); }
	inline void SetFirstPoint(QPoint*point) {m_First = *point;}
	inline void MoveCurrentDraw(QPoint point) { MoveCurrentRect(point); }
	inline void SetPenColor(QColor color) { m_Foreground = color; m_Pen.setColor(m_Foreground);}
	inline void SetBrushColor(QColor color) { m_Background = color; m_BackgroudBrush.setColor(m_Background); }
	inline void SetAlpha(int Alpha) { ColorAlpha = Alpha; m_Background.setAlpha(ColorAlpha); m_BackgroudBrush.setColor(m_Background); }
	inline void SetPenStyle(Qt::PenStyle penstyle) { m_PenStyle = penstyle; m_Pen.setStyle(m_PenStyle); }
	inline void SetHollow(bool hollow) { Hollow = hollow; }
	inline void SetDrawRectCut() { DrawRectCut(); }
	inline void SetRectNormlized() { RectNormlized(); }
	inline void SetCenterPoint(QPoint point) { CenterPoint(point); }
	inline CLASS GetCLASSNAME() { return m_CLASSNAME; }
	inline void CopyLayer(void*layer) { Copy(layer);}
	inline int GetFontWidth() { return FontWidth; }
	inline QColor GetForeground() { return m_Foreground; }
	inline QColor GetBackground() { return m_Background; }
	inline Qt::PenStyle GetPenStyle() { return m_PenStyle; }
	inline int GetColorAlpha() { return ColorAlpha; }
	inline QRect GetRect() { return m_Rect; };
	inline QString GetTextString() { return m_Text; }
	inline void SetEidtText(QString str) { m_Text = str; }
};
