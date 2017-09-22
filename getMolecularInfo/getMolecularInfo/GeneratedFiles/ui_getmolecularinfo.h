/********************************************************************************
** Form generated from reading UI file 'getmolecularinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETMOLECULARINFO_H
#define UI_GETMOLECULARINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_getMolecularInfoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *getMolecularInfoClass)
    {
        if (getMolecularInfoClass->objectName().isEmpty())
            getMolecularInfoClass->setObjectName(QString::fromUtf8("getMolecularInfoClass"));
        getMolecularInfoClass->resize(600, 400);
        menuBar = new QMenuBar(getMolecularInfoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        getMolecularInfoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(getMolecularInfoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        getMolecularInfoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(getMolecularInfoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        getMolecularInfoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(getMolecularInfoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        getMolecularInfoClass->setStatusBar(statusBar);

        retranslateUi(getMolecularInfoClass);

        QMetaObject::connectSlotsByName(getMolecularInfoClass);
    } // setupUi

    void retranslateUi(QMainWindow *getMolecularInfoClass)
    {
        getMolecularInfoClass->setWindowTitle(QApplication::translate("getMolecularInfoClass", "getMolecularInfo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getMolecularInfoClass: public Ui_getMolecularInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETMOLECULARINFO_H
