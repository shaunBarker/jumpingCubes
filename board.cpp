#include "board.h"
#include <vector>
#include <QMessageBox>


//Constructor for board
board::board(QWidget *parent, unsigned int newBoardSize, unsigned int numPlayers) :
    QWidget(parent)
{
    //intialise everything
    aiTurn=false;
    m_currentTurn=Qt::red;//set first move to red
    m_numberOfPlayers=numPlayers;//set how many humans are playing
    m_boardSize=newBoardSize;//set the width and height of the board (its square)
    m_changedNewBoardSize=newBoardSize;//set the value to resize to by default
    std::vector<Die*> dieVectorToPush;//create a temporary vector that ends up into the m_boardDie 2D vector
    m_layout=new QGridLayout(this);//set the layout of this widget

    //create a 2D vector of dice connect them to the dieHit command
    for(unsigned int i = 0; i<m_boardSize;i++){
        dieVectorToPush.clear();
        for(unsigned int j = 0; j<m_boardSize;j++){
            Die* newDie = new Die(this,QPoint(i,j),Qt::white,1);
            dieVectorToPush.push_back(newDie);
            connect(newDie,SIGNAL(pressed(QPoint)),this,SLOT(dieHit(QPoint)));
            m_layout->addWidget(newDie,i,j);
        }
        m_boardDie.push_back(dieVectorToPush);
    }
}

//Destructor, loop through and destroy all dies in 2D vector
board::~board(){
    for(unsigned int i = 0; i<m_boardSize;i++){
        for(unsigned int j = 0; j<m_boardSize;j++){
            delete m_boardDie[i][j];
        }
    }
}

//resizeBoard is called by the slot resetBoard below
void board::resizeBoard(int newSize){
    //loop through and delete all dies
    for(unsigned int i = 0; i<m_boardSize;i++){
        for(unsigned int j = 0; j<m_boardSize;j++){
            delete m_boardDie[i][j];
        }
    }

    m_boardSize=newSize;
    m_boardDie.clear();//clear out the 2D vector of the pointers to nothing

    std::vector<Die*> dieVectorToPush;//temporary vector used to add Dies
    for(unsigned int i = 0; i<m_boardSize;i++){
        dieVectorToPush.clear();
        for(unsigned int j = 0; j<m_boardSize;j++){
            Die* newDie = new Die(this,QPoint(i,j),Qt::white,1);//make a new Die*, parent is this, exists at (i,j) is white and has a facevalue of 1
            dieVectorToPush.push_back(newDie);
            connect(newDie,SIGNAL(pressed(QPoint)),this,SLOT(dieHit(QPoint)));
            m_layout->addWidget(newDie,i,j);
        }
        m_boardDie.push_back(dieVectorToPush);
    }
}

//runResize is just a slot that changes the potential new board size
void board::runResize(int newSize){
    m_changedNewBoardSize=newSize;
}

//runs the resize function above
void board::resetBoard(){
    aiTurn=false;
    m_currentTurn=Qt::red;
    resizeBoard(m_changedNewBoardSize);
}

//loop through return true if any Die can be rolledOver, false otherwise
bool board::anyValidFlips(){
    for(unsigned int x = 0; x<m_boardSize;x++){
        for(unsigned int y = 0; y<m_boardSize;y++){
            if(m_boardDie[x][y]->rollOver(m_boardSize)){
                return(true);
            }
        }
    }
    return(false);
}

//establish a 2D vector where each element corresponds to the die at the same point, 0 if it shouldn't change, 1 if it should change to the current turn and increase by 1, 2 if it should reset back to 1
std::vector<std::vector<int> >board::listValidFlips(){
    std::vector<std::vector<int> > validFlipPoints(m_boardSize, std::vector<int> (m_boardSize,0));
    for(unsigned int i = 0; i<m_boardSize;i++){
        for(unsigned int j = 0; j<m_boardSize;j++){
            if(m_boardDie[i][j]->rollOver(m_boardSize)){

                validFlipPoints[i][j]=2;//set the current Die to 2

                //set any existing surrounding Dies to 1
                if(i>0){
                    if(validFlipPoints[i-1][j]==0){
                         validFlipPoints[i-1][j]=1;
                    }
                }
                if(i<(m_boardSize-1)){
                    if(validFlipPoints[i+1][j]==0){
                         validFlipPoints[i+1][j]=1;
                    }
                }
                if(j>0){
                    if(validFlipPoints[i][j-1]==0){
                         validFlipPoints[i][j-1]=1;
                    }
                }
                if(j<(m_boardSize-1)){
                    if(validFlipPoints[i][j+1]==0){
                         validFlipPoints[i][j+1]=1;
                    }
                }
            }
        }
    }
    return(validFlipPoints);//return the 2D vector
}

//while anything can be flipped make the above functions vector and act on it
void board::checkAndCallFlips(){
    while(anyValidFlips()){
        std::vector<std::vector<int> > flipsToDo=listValidFlips();//make vector from above function

        for(unsigned int i=0;i<m_boardSize;i++){
            for(unsigned int j=0;j<m_boardSize;j++){

                if(flipsToDo[i][j]==1){
                    m_boardDie[i][j]->increaseFaceValue();
                    m_boardDie[i][j]->changeColour(m_currentTurn);
                }

                if(flipsToDo[i][j]==2){
                    m_boardDie[i][j]->reset();
                    m_boardDie[i][j]->changeColour(m_currentTurn);
                }

            }
        }
        flipsToDo.clear();//clear out the values
    }
}


//loop through and see if all values are the same, return false if any are different otherwise true
bool board::isWinner(){
    QColor firstColour=m_boardDie[0][0]->getTeamColour();
    for(unsigned int i = 0; i<m_boardSize;i++){
        for(unsigned int j = 0; j<m_boardSize;j++){
            if(firstColour!=m_boardDie[i][j]->getTeamColour()){
                return(false);
            }
        }
    }
    return(true);
}

//return the current player, not used at the moment, potentially useful for AI programming
QColor board::currentPlayer(){
    return(m_currentTurn);
}

//return the boardSize, not used currently
unsigned int board::getSize(){
    return(m_boardSize);
}

//return the Die* to a Die in teh grid
Die* board::getBoardDie(unsigned int x, unsigned int y){
    return(m_boardDie[x][y]);
}

//act if something is clicked on
int board::dieHit(QPoint diePosition){
    //if the clicked on die is the same as the current turn or white
    if((m_boardDie[diePosition.x()][diePosition.y()]->getTeamColour())==Qt::white or m_currentTurn==(m_boardDie[diePosition.x()][diePosition.y()]->getTeamColour())){

        //up die that was clicked on by 1, change its colour (for whites) and update it
        m_boardDie[diePosition.x()][diePosition.y()]->increaseFaceValue();
        m_boardDie[diePosition.x()][diePosition.y()]->changeColour(m_currentTurn);
        m_boardDie[diePosition.x()][diePosition.y()]->update();

        checkAndCallFlips();//call the flipping mechanism

        //if someone has won, announce it
        if(isWinner() and m_currentTurn==Qt::red){
            QMessageBox msgBox;
            msgBox.setText("The winner is the RED team");
            msgBox.exec();
            resetBoard();
            return(0);
        }
        if(isWinner() and m_currentTurn==Qt::blue){
            QMessageBox msgBox;
            msgBox.setText("The winner is the BLUE team");
            msgBox.exec();
            resetBoard();
            return(0);
        }

        //switch turns
        if(m_currentTurn==Qt::red){
           m_currentTurn=Qt::blue;
        } else {
            m_currentTurn=Qt::red;
        }

        if(aiTurn){
            aiTurn=false;
        } else {
            aiTurn=true;
            emit tellAiToTakeATurn();
        }
    }
    return(0);
}
