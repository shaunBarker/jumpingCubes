#include "die.h"
#include <QPen>
#include <QPainter>
#include <string>

    //initalise Die
    Die::Die(QWidget *parent, QPoint startPosition, QColor colour, unsigned int faceVal):
        QWidget(parent)
    {
        m_position=startPosition;
        m_currentTeam=colour;
        m_faceValue=faceVal;
    }

    //reset to white and facevalue of 1
    void Die::reset(){
        m_currentTeam=Qt::white;
        m_faceValue=1;
        this->update();
    }

    //return where this is
    QPoint Die::getPoint() const
    {
        return(m_position);
    }

    //SLOT, don't think this is actually ever used
    void Die::clickIncrease(){
        this->increaseFaceValue();
    }


    void Die::increaseFaceValue()
    {
        m_faceValue++;
        this->update();
    }

    void Die::changeColour(QColor newColour)
    {
        m_currentTeam=newColour;
        this->update();
    }

    unsigned int Die::getFaceValue() const
    {
        return(m_faceValue);
    }

    QColor Die::getTeamColour() const
    {
        return(m_currentTeam);
    }

    //determine where this Die lies on the board and decide if it is time to roll it over
    bool Die::rollOver(int boardSize) const{
        unsigned int theoreticalMax=1;
        if(m_position.x()>0){
            theoreticalMax++;
        }
        if(m_position.x()<(boardSize-1)){
            theoreticalMax++;
        }
        if(m_position.y()>0){
            theoreticalMax++;
        }
        if(m_position.y()<(boardSize-1)){
            theoreticalMax++;
        }
        if(m_faceValue>=theoreticalMax){
            return(true);
        }
        return(false);
    }

    //make this visible! GUI for the win
    void Die::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setPen(m_currentTeam);
        painter.fillRect(0,0,this->width()-1,this->height()-1,m_currentTeam);//rectangle of the current colour
        painter.setBrush(QColor(Qt::black));//draw the circles in Black. I used Black now, black is cool.

        //draw the right number of circles, averaged centres mostly at 1/4 points
        switch(m_faceValue)
        {
        case 1:
            painter.drawEllipse(QPoint(this->width()/2,this->height()/2),(this->width()+this->height())/16,(this->width()+this->height())/16);
            break;
        case 2:
            painter.drawEllipse(QPoint(this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(3*this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            break;
        case 3:
            painter.drawEllipse(QPoint(this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(3*this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(this->width()/2,this->height()/2),(this->width()+this->height())/16,(this->width()+this->height())/16);
            break;
        case 4:
            painter.drawEllipse(QPoint(3*this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(3*this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            break;
        case 5:
            painter.drawEllipse(QPoint(this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(3*this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(this->width()/2,this->height()/2),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(this->width()/4,3*this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            painter.drawEllipse(QPoint(3*this->width()/4,this->height()/4),(this->width()+this->height())/16,(this->width()+this->height())/16);
            break;
        default:
            painter.setPen(Qt::black);//this should never happen, who the fuck is entering invalid dies I ask?
            painter.setFont(QFont("Arial", this->height()/2));
            painter.drawText(QPoint(this->width()/2-this->height()/8,3*this->height()/4),QString::number(m_faceValue));
        }

    }
    void Die::mousePressEvent(QMouseEvent *event){
        emit pressed(m_position);//I've been clicked on, alert everyone
    }
    void Die::aiClickedOnMe(){
        emit pressed(m_position);//I've been clicked on, alert everyone
    }
