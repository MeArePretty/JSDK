#pragma once

#include <QWidget>
#include<qapplication.h>
#include<qpixmap.h>
#include<qdesktopwidget.h>
#include<qpainter.h>
#include<QMouseEvent>
#include<QKeyEvent>
#include<QScreen>
#include<qrect.h>
#include<qpoint.h>
#include<qaction.h>
#include<qfiledialog.h>
#include<QDateTime>
#include<qclipboard.h>
#include"MyToolBar.h"
class QShowDesk : public QWidget
{
	Q_OBJECT

public:
	QShowDesk(QWidget *parent);
	~QShowDesk();
	enum RectCurPos {LEFTTOP,CENTERTOP,RIGHTTOP,CENTERRIGHT, RIGHTBOTTOM,CENTERBOTTOM, LEFTBOTTOM, CENTERLEFT,INSIDE,DEFAULT};
	enum CutStatue { IDLE,FINISH, CUTTING};
signals:
	void WindowClose();

private slots:
	void OnBtnSave();
	void OnBtnFinish();

private:
	void Initi_Toolbar();
	void Initi_Window();
	void Initi_Object();
	void DrawRectAngle(QPainter&painter) ;
	void DrawRectCut(QPoint&, QPoint&);
	void EghiteAngle();
	void Connect(QWidget *parent);
	void CloseBack();
	void CursorPos(QPoint* point);
	void SetCursor();
	void MoveCurrentRect(QPoint point);
	void ToolBarPos();
	void SidePos(QPoint Start, QPoint End);
	void SetSidePos(QPoint Dleat);
private:
	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent*event);
	void mouseReleaseEvent(QMouseEvent*event);
	void mouseMoveEvent(QMouseEvent*event);
	void keyPressEvent(QKeyEvent*event);
private:
	MyToolBar* m_Toolbar;
	QRect m_ptrRect[8];
	RectCurPos m_CurPos;//´ý¶¨
	RectCurPos m_SidePos;//´ý¶¨
	int m_ToolbarPos;
	CutStatue m_CutStatue;
	QPixmap m_Desktop_Pixmap;
	QPixmap m_Current_Pixmap;
	QRect m_Desktop_Rect;
	QRect m_CurrentCut;
	QPoint m_Start, m_End,m_First;
	bool m_Press_Release;
	
};
