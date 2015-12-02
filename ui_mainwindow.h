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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRestart;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *controlBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBoardSize;
    QLabel *label_3;
    QPushButton *resetButton;
    QGridLayout *boardLayout;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuMain_Menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(570, 391);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        controlBox = new QGroupBox(centralWidget);
        controlBox->setObjectName(QStringLiteral("controlBox"));
        controlBox->setMinimumSize(QSize(150, 250));
        controlBox->setMaximumSize(QSize(120, 16777215));
        verticalLayout = new QVBoxLayout(controlBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        spinBoardSize = new QSpinBox(controlBox);
        spinBoardSize->setObjectName(QStringLiteral("spinBoardSize"));
        spinBoardSize->setMinimum(3);
        spinBoardSize->setMaximum(999);
        spinBoardSize->setValue(4);

        gridLayout_4->addWidget(spinBoardSize, 1, 0, 2, 1);

        label_3 = new QLabel(controlBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        resetButton = new QPushButton(controlBox);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        gridLayout_4->addWidget(resetButton, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        gridLayout_2->addWidget(controlBox, 0, 1, 1, 1);

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
        menuBar->setGeometry(QRect(0, 0, 570, 25));
        menuMain_Menu = new QMenu(menuBar);
        menuMain_Menu->setObjectName(QStringLiteral("menuMain_Menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMain_Menu->menuAction());
        menuMain_Menu->addAction(actionRestart);
        menuMain_Menu->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        controlBox->setTitle(QApplication::translate("MainWindow", "Controls", 0));
        label_3->setText(QApplication::translate("MainWindow", "Grid Width:", 0));
        resetButton->setText(QApplication::translate("MainWindow", "Restart", 0));
        menuMain_Menu->setTitle(QApplication::translate("MainWindow", "Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
