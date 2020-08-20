#pragma once


#include <QToolBar>
#include<qaction.h>
#include<qpainter.h>
#include<qpixmap.h>
#include<qthread.h>
#include<qrect.h>
#include"QShowDesk.h"
#include"QShapeToolBar.h"
#include"QDockToolbar.h"
class TransToolBar : public QToolBar
{
	Q_OBJECT

public:
	TransToolBar(QWidget *parent= Q_NULLPTR);
	~TransToolBar();

signals:
	void SendDrawcheck(bool);
	void SendShow_Hide(bool);
	void ShowFlash();
	void CloseFlash();
	void ModifyCloseFlashValue();
private slots:
	void OnBtnCut();
	void CutWindowclose();
	void OnBtnLock();
	void OnBtnDraw();
	void ModifyCloseFlash();
private:
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent*event);

private:
	void SetWindowFlag();
	void Setproperty();
	void CreateAction();
	void Connect(QWidget *parent);
private:
	QVector<QIcon*>m_IconGroup;
	QAction* ActionStart;
	QAction*ActionLock;
	QAction*ActionCut;
	QAction*ActionDraw;
	QAction*ActionClose;
	QAction*ActionSave;
	QAction*ActionHistory;
	QAction*ActionNew;
	QShowDesk*m_QShowDesk;

private:
	bool m_Press_Release;
	QPoint m_First;
	bool drawcheck;
	bool CLOSEOPEN;
};
