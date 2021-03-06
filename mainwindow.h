#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void showBoard(board* newBoard);
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

signals:
    void resetBoard();
    void resizeRequest(int newSize);

private slots:
    void on_actionRestart_triggered();
    void on_actionGrid_Size_triggered();
};

#endif // MAINWINDOW_H
