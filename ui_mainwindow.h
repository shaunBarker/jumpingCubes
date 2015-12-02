/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRestart;
    QAction *actionExit;
    QAction *actionGrid_Size;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *boardLayout;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuMain_Menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 400);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionGrid_Size = new QAction(MainWindow);
        actionGrid_Size->setObjectName(QStringLiteral("actionGrid_Size"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        boardLayout = new QGridLayout();
        boardLayout->setSpacing(6);
        boardLayout->setObjectName(QStringLiteral("boardLayout"));

        gridLayout_2->addLayout(boardLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuMain_Menu = new QMenu(menuBar);
        menuMain_Menu->setObjectName(QStringLiteral("menuMain_Menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMain_Menu->menuAction());
        menuMain_Menu->addAction(actionRestart);
        menuMain_Menu->addAction(actionGrid_Size);
        menuMain_Menu->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Jumping Cubes", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Jumping Cubes</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionGrid_Size->setText(QApplication::translate("MainWindow", "Grid Size", 0));
        menuMain_Menu->setTitle(QApplication::translate("MainWindow", "Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
