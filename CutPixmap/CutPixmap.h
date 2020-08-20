#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CutPixmap.h"
#include<qpainter.h>
#include"TransToolBar.h"
#include<qvector.h>
#include <QGraphicsScene> 
#include <QGraphicsView> 
#include<QGraphicsTextItem>
#include<qmessagebox.h>
#include"MyGraphicsView.h"
#include<QMouseEvent>
#include"QDockToolbar.h"
#include"MyShowDrawWidget.h"
#include"MyPlaintText.h"
#include"MyFontDialog.h"


#include"QCurve.h"
#include"QStraightLine.h"
#include"QRectDraw.h"
#include"QRoundRect.h"
#include"QEllipse.h"
#include"QText.h"
#define SCREEN_WIDTH    QApplication::desktop()->width()
#define SCREEN_HEIGHT   QApplication::desktop()->height()

class CutPixmap : public QMainWindow
{
    Q_OBJECT

public:
    CutPixmap(QWidget *parent = Q_NULLPTR);
	~CutPixmap();
private:
    Ui::CutPixmapClass ui;
public:
	enum DrawPenModel {CURVE,LINE,RECT,ROUNDRECT,ELLIPSE,TEXT,MOUSE};
	enum DrawStatus {DRAWING,MOVING,IDEL};
signals:
	void CloseFlash();
	void SendLayer(QVector<QLayer*>);
	void SendMessageDraw(QLayer*);
	void TextShow(QRect*);
	void TextHidde();
private slots:
	void GetShow_Hide(bool);
	void ModifyCloseFlashValue();
	void GetCurrentBrushColor(QColor BrushColor);
	void GetCurrentText_PenColor(QColor Text_Pen);
	void GetPenWidth();
	void GetBrushTrans();
	void GetEditText(QString);
	void GetDrawFont();
	void GetDrawPenModel_MOUSE();
	void GetDrawPenModel_CURVE();
	void GetDrawPenModel_RECT();
	void GetDrawPenModel_ROUNDRECT();
	void GetDrawPenModel_LINE();
	void GetDrawPenModel_ELLIPSE();
	void GetDrawPenModel_TEXT();
	void GetLineStatusChanged(Qt::PenStyle);
	void GetCurrentPictureIndex(int);
	void frameStatus(int status);
	void HollowStatus(int status);
	void ChangedofTransDynamicdisplay();
	void OnCloseWindow();
	void OnPictureCopy();
	void OnPicturePaste();
	void OnPictureDelete();
	void OnNewPicture();
	bool OnSaveCurrentPicture();
	void OnHistoryCurrentPicture();



private:
	void SetWindowFlag();
	void CreateWindow();
	void Connect();
	int GetSelectedIndex(QPoint);
	void SetOtherPictureStatusFalse();
	void SetLastIndexPictureStatusFalse();
	void SetCursor();
	void SelectedChange(int);
	void SetTextEidtshowModel();
	void addPictureToCombbox();
private:
	void paintEvent(QPaintEvent*event);
public:
	void viewWheelEvent(QWheelEvent *event);
	void viewMousePressEvent(QMouseEvent *event);
	void viewMouseMoveEvent(QMouseEvent *event);
	void viewMouseReleaseEvent(QMouseEvent *event);
	void viewfocusInEvent(QFocusEvent*event);
private:

	QGraphicsScene  *m_pScene;          //场景
	MyGraphicsView  *m_pView;           //视图
	TransToolBar * m_TransToolBar;
	QDockToolbar* m_QDockToolbar;
	MyShowDrawWidget* m_MyShowDrawWidget;
private:
	bool CloseFlashValue;
	DrawPenModel m_DrawPenModel;
	DrawStatus DrawStatus;
	
	QVector<QLayer*> m_Layer;
	QVector<QPixmap> m_CursorVector;
	QAction* PictureCopy;
	QAction* PicturePaste;
	QAction*PictureDelete;
	int LastIndexSelected;
	int CurrentIndexSelected;
	int IndexCount;
	int m_PenWidth;
	bool LeftbuttonPress;
	bool frame;
	bool hollow;
	QLayer *layercopy;
	QPoint m_PastePoint;
	MyPlaintText *m_textEdit;

private:
	QColor m_CurrentBrushColor;
	QColor m_CurrentText_PenColor;
	QPen m_Pen;
	QBrush m_Brush;
	Qt::PenStyle m_PenStyle;
	QFont m_font;

private:
	QVector<QVector<QLayer*>>m_CurrentPicture;
	int m_CurrentPictureIndex;
	int m_CurrentPictureCount;
	QPixmap m_CurrentPicturePixmap;
	QComboBox * m_HistoryPixmap;
	QSize m_PixmapSizeSclaed;

private:
	QVector<QLayer*> m_Layerdelete;

private:
	void m_CurrentPictureSelected();//独立的封装

public:
	int GetCurrentIndexSelected() { return CurrentIndexSelected; }
	QVector<QLayer*> GetLayer() { return m_Layer; }
	//int m_PenWidth;
};
