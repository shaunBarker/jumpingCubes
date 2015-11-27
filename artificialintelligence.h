#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H
#include <QColor>
#include <QPoint>
#include <QWidget>
#include "board.h"
#include <vector>

class artificialIntelligence: public QWidget

{
    Q_OBJECT

public:
    artificialIntelligence(QWidget *parent = 0, QColor colourIAm=QColor(Qt::blue), board* boardIWillPlayOn= new board());
    QPoint whereShouldIMove();
    std::vector<std::vector<int> > findFlippablePoints();
    QPoint findMaxPosition(std::vector<std::vector<int> > vectorToSearch);

public slots:
    void takeATurn();

signals:

private:
    QColor m_aiColour;
    board* whereIAmPlaying;
};

#endif // ARTIFICIALINTELLIGENCE_H
