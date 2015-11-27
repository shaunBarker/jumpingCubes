#ifndef BOARD_H
#define BOARD_H
#include <QColor>
#include <vector>
#include <QWidget>
#include "die.h"
#include <QGridLayout>

class board : public QWidget
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = 0, unsigned int newBoardSize = 4, unsigned int numPlayers=2);
    ~board();
    bool anyValidFlips();
    //void runFlips();
    bool isWinner();
    QColor currentPlayer();
    unsigned int getSize();
    Die* getBoardDie(unsigned int x, unsigned int y);
    void resizeBoard(int newSize=4);
    std::vector<std::vector<int> > listValidFlips();
    void checkAndCallFlips();
    //void runFlips();
    //void flip(QPoint dieToFlip);

private:
    QColor m_currentTurn;
    unsigned int m_numberOfPlayers;
    unsigned int m_boardSize;
    std::vector<std::vector<Die*> > m_boardDie;
    QGridLayout* m_layout;
    int m_changedNewBoardSize;
    bool aiTurn;

signals:
    void tellAiToTakeATurn();
    
public slots:
    void runResize(int newSize=4);
    void resetBoard();
    int dieHit(QPoint diePosition);

};

#endif // BOARD_H
