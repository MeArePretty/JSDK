/********************************************************************************
** Form generated from reading UI file 'CutPixmap.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTPIXMAP_H
#define UI_CUTPIXMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CutPixmapClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *CutPixmapClass)
    {
        if (CutPixmapClass->objectName().isEmpty())
            CutPixmapClass->setObjectName(QStringLiteral("CutPixmapClass"));
        CutPixmapClass->resize(600, 400);
        centralWidget = new QWidget(CutPixmapClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CutPixmapClass->setCentralWidget(centralWidget);

        retranslateUi(CutPixmapClass);

        QMetaObject::connectSlotsByName(CutPixmapClass);
    } // setupUi

    void retranslateUi(QMainWindow *CutPixmapClass)
    {
        CutPixmapClass->setWindowTitle(QApplication::translate("CutPixmapClass", "CutPixmap", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CutPixmapClass: public Ui_CutPixmapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTPIXMAP_H
