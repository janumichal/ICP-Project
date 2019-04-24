//
// Created by janum on 24.04.2019.
//

#include "Tab.h"
#include <iostream>

#include "others.h"

using namespace std;

Tab::Tab(){
    this->game = new Game();
    string all_moves = "1. d4 a5\n"
                       "2. Dec3 J8f6\n"
                       "3. d5 c7c6\n"
                       "4. d5xc6 Jf6h5\n";

    cout << all_moves << endl;


    this->game->loadAllMoves(all_moves);

    next();
    next();

    next();
    next();

    next();
    next();

    next();
    next();

//    next();
//    next();
//
//    next();


//        Field f1 = this.game.board.getField(2,4);
//        Field f2 = this.game.board.getField(3,3);
//        move(f1,f2);


    this->game->board->printPoints();

    cout << endl;
    this->game->printAllMoves();


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
    this->game->undo();
}

void Tab::redo(){
    this->game->redo();
}

void Tab::move(Field *from, Field *to){
    this->game->setAuto_mode();
    this->game->move(from, to);
}
