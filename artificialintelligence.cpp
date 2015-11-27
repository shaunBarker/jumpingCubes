#include "artificialintelligence.h"

artificialIntelligence::artificialIntelligence(QWidget *parent, QColor colourIAm, board *boardIWillPlayOn) :
    QWidget(parent)
{
    m_aiColour=colourIAm;
    whereIAmPlaying=boardIWillPlayOn;
}

void artificialIntelligence::takeATurn(){
    QPoint moveOnThis=findMaxPosition(findFlippablePoints());
    whereIAmPlaying->getBoardDie(moveOnThis.x(),moveOnThis.y())->aiClickedOnMe();
}

QPoint artificialIntelligence::whereShouldIMove()
{
    QPoint iShouldMoveHere(0,0);
    return(iShouldMoveHere);
}

std::vector<std::vector<int> > artificialIntelligence::findFlippablePoints(){
    std::vector<std::vector<int> > flippablePoints(whereIAmPlaying->getSize(), std::vector<int> (whereIAmPlaying->getSize(),0));

    for(unsigned int i=0; i<whereIAmPlaying->getSize();i++){
        for(unsigned int j=0; j<whereIAmPlaying->getSize();j++){

            if(whereIAmPlaying->getBoardDie(i,j)->getTeamColour()!=m_aiColour){
                flippablePoints[i][j]=flippablePoints[i][j]-5000;
            }
            if(whereIAmPlaying->getBoardDie(i,j)->getTeamColour()==QColor(Qt::white)){
                flippablePoints[i][j]=flippablePoints[i][j]+5001;

            }
            if(whereIAmPlaying->getBoardDie(i,j)->getTeamColour()==m_aiColour){
                flippablePoints[i][j]=flippablePoints[i][j]+3;

            }
            if(whereIAmPlaying->getBoardDie(i,j)->rollOver(whereIAmPlaying->getSize())){
                flippablePoints[i][j]=flippablePoints[i][j]+6;

                if(i>0){
                         flippablePoints[i-1][j]=flippablePoints[i-1][j]+3;
                }
                if(i<(whereIAmPlaying->getSize()-1)){
                         flippablePoints[i+1][j]=flippablePoints[i+1][j]+3;
                }
                if(j>0){
                         flippablePoints[i][j-1]=flippablePoints[i][j-1]+3;
                }
                if(j<(whereIAmPlaying->getSize()-1)){
                         flippablePoints[i][j+1]=flippablePoints[i][j+1]+3;
                }
            }
        }
    }
    return(flippablePoints);
}

QPoint artificialIntelligence::findMaxPosition(std::vector<std::vector<int> > vectorToSearch){
    QPoint maxPosition(0,0);
    for(unsigned int i=0; i<vectorToSearch.size();i++){
        for(unsigned int j=0; j<vectorToSearch.size();j++){
            if(vectorToSearch[i][j]>vectorToSearch[maxPosition.x()][maxPosition.y()]){
                maxPosition=QPoint(i,j);
            }
        }
    }
    return(maxPosition);
}
