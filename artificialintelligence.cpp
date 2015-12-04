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
//This seems to be junk, no idea why it's here? Maybe left over from an original prototype?
//QPoint artificialIntelligence::whereShouldIMove()
//{
//    QPoint iShouldMoveHere(0,0);
//    return(iShouldMoveHere);
//}

//could this be an array instead of a vector? Need to check what's going on.
std::vector<std::vector<int> > artificialIntelligence::findFlippablePoints(){
    std::vector<std::vector<int> > flippablePoints(whereIAmPlaying->getSize(), std::vector<int> (whereIAmPlaying->getSize(),0));

    for(unsigned int i=0; i<whereIAmPlaying->getSize();i++){
        for(unsigned int j=0; j<whereIAmPlaying->getSize();j++){

            //don't let the ai play on the opponent's spaces
            if(whereIAmPlaying->getBoardDie(i,j)->getTeamColour()!=m_aiColour and whereIAmPlaying->getBoardDie(i,j)->getTeamColour()!=Qt::white){
                flippablePoints[i][j]=flippablePoints[i][j]-5000;
            } else {
                flippablePoints[i][j]=flippablePoints[i][j]+6;
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
