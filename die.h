#ifndef DIE_H
#define DIE_H

#include <QWidget>
#include <QColor>
#include <QPoint>

class Die : public QWidget
{
    Q_OBJECT

    public:
        //explicit Die(QWidget *parent = 0, QPoint startPosition = QPoint(0,0));
        explicit Die(QWidget *parent = 0, QPoint startPosition = QPoint(0,0), QColor colour = QColor(Qt::white), unsigned int faceVal=1);

        unsigned int getFaceValue() const;
        QColor getTeamColour() const;
        QPoint getPoint() const;
        bool rollOver(int boardSize) const;
        void paintEvent(QPaintEvent *event);
        void reset();
        void changeColour(QColor newColour);
        void mousePressEvent(QMouseEvent *event);
        void aiClickedOnMe();

    private:
        unsigned int m_faceValue;
        QColor m_currentTeam;
        QPoint m_position;

    signals:
        void pressed(QPoint position);
    public slots:
        void increaseFaceValue();
        void clickIncrease();
};

#endif // DIE_H
