/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#include "Tab.h"
#include <iostream>
#include <fstream>

#include "others.h"

using namespace std;

Tab::Tab() {
    this->game = new Game();
    newGame();
}

void Tab::Load(const string &url){
    ifstream input(url);
    string str;
    for( std::string line; getline( input, line ); )
    {
        str.append(line);
        str.append("\n");
    }
    this->loadAllMoves(str);
}

void Tab::PrintGame(){
    this->game->board->printPoints();
    cout << endl;
    cout << this->game->printAllMoves() << endl;
    this->game->board->showPiecesText();
}

void Tab::next(){
    if(this->game->isAuto_mode()){
        this->game->next();
    }
    PrintGame();
}

void Tab::prew(){
    if(this->game->isAuto_mode()){
        this->game->prew();
    }
    PrintGame();
}

void Tab::undo(){
    if(!this->game->isAuto_mode()){
        this->game->undo();
        PrintGame();
    }
}

void Tab::redo(){
    if(!this->game->isAuto_mode()){
        this->game->redo();
    }
    PrintGame();
}

void Tab::Move(string from, string to){
    if(from.length() != 2 || to.length() != 2){
        cout << "WROND POSITION" << endl;
    }
    int col_from = ((int)from[0] - 97);
    int row_from = 8 - ((int)from[1] - 48);

    int col_to = ((int)to[0] - 97);
    int row_to = 8 - ((int)to[1] - 48);

    Field *f1 = this->game->board->getField(col_from, row_from);
    Field *f2 = this->game->board->getField(col_to, row_to);
    this->move(f1,f2);
}

void Tab::move(Field *from, Field *to){
    if(from->getPiece() == nullptr){
        printf("NO PIECE TO MOVE!!!"); // TODO POPUP
    }else{
        this->game->setAuto_modeOFF();
        this->game->move(from, to);
    }
    PrintGame();
}

void Tab::start_auto(){
    this->game->setAuto_modeON();
    this->game->setIndex(0);
}

void Tab::loadAllMoves(string moves_input) {
    this->game->loadAllMoves(moves_input);
}

void Tab::newGame() {
    this->game->setIndex(0);
    this->game->board->white_on_move = true;
    this->game->board->cleanBoard();
    this->game->board->fillBoard();
}
