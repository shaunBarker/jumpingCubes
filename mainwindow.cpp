#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "die.h"
#include "artificialintelligence.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    board* newBoard = new board(this,4,2);//I want a board, with 1 of every player and 4 by 4 of every Die!
    artificialIntelligence* newAI = new artificialIntelligence(this,QColor(Qt::blue),newBoard);
    ui->boardLayout->addWidget(newBoard);
    QObject::connect(ui->spinBoardSize,SIGNAL(valueChanged(int)),newBoard,SLOT(runResize(int)));
    QObject::connect(ui->resetButton,SIGNAL(clicked()),newBoard,SLOT(resetBoard()));
    QObject::connect(newBoard,SIGNAL(tellAiToTakeATurn()),newAI,SLOT(takeATurn()));
}

MainWindow::~MainWindow()
{
    delete ui;//when things need to die, we want to make sure no one sees anything

}
