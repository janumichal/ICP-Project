/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#include "Tab.h"
#include <iostream>

#include "others.h"

using namespace std;

Tab::Tab() {
    this->game = new Game();
    newGame();
//}

    string all_moves = "1. Jc3 a5\n"
                       "2. Jd5 J8f6\n"
                       "3. Jxf6+ c7c6\n"
                       "4. Dxa5 f7f5\n";

//    cout << all_moves << endl;


    loadAllMoves(all_moves);
    newGame();
    start_auto();

    next();
    next();

    next();
    next();


    Field *f1 = this->game->board->getField(3,3);
    Field *f2 = this->game->board->getField(5,2);
    move(f1, f2);
//
    f1 = this->game->board->getField(1,1);
    f2 = this->game->board->getField(1,3);
    move(f1, f2);


    newGame();
    start_auto();

    next();
    next();

    next();
    next();

    next();
    next();


//
//    f1 = this->game->board->getField(5,2);
//    f2 = this->game->board->getField(4,0);
//    move(f1, f2);
//
//    next();
//    next();
//
//    next();
//    next();

//    next();
//    next();
//
//    next();


//        Field f1 = this.game.board.getField(2,4);
//        Field f2 = this.game.board.getField(3,3);
//        move(f1,f2);


    this->game->board->printPoints();

    cout << endl;
    cout << this->game->printAllMoves() << endl;


    this->game->board->showPiecesText();
}

void Tab::next(){
    if(this->game->isAuto_mode()){
        this->game->next();
    }
}

void Tab::prew(){
    if(this->game->isAuto_mode()){
        this->game->prew();
    }
}

void Tab::undo(){
    if(this->game->isAuto_mode()){
        this->game->undo();
    }
}

void Tab::redo(){
    if(this->game->isAuto_mode()){
        this->game->redo();
    }
}

void Tab::move(Field *from, Field *to){
    if(from->getPiece() == nullptr){
        printf("NO PIECE TO MOVE!!!"); // TODO POPUP
    }else{
        this->game->setAuto_modeON();
        this->game->move(from, to);
    }
}

void Tab::start_auto(){
    this->game->setAuto_modeON();
    this->game->setIndex(0);
}

void Tab::loadAllMoves(string moves_input) {
    this->game->loadAllMoves(moves_input);
}

void Tab::newGame() {
    this->game->board->cleanBoard();
    this->game->board->fillBoard();
}
