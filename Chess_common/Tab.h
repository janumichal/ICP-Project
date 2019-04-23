//
// Created by janum on 23.04.2019.
//

#ifndef CPP_CHESS_TAB_H
#define CPP_CHESS_TAB_H

#include "Game.h"

class Tab {
    Game *game;
public:
    Tab() {
        this->game = new Game();
        string all_moves = "1. d4 a5\n "
                           "2. Dec3 J8f6\n"
                           "3. cxd5 c7c6\n"
                           "4. d5xc6 f7f5\n";

        this->game->loadAllMoves(all_moves);

        next();
        next();

        next();
//        next();

//        next();
//        next();
//
//        next();
//        next();
//
//        next();
//        next();
//
//        next();


//        Field f1 = this.game.board.getField(2,4);
//        Field f2 = this.game.board.getField(3,3);
//        move(f1,f2);


        this->game->board->printPoints();

        cout << endl;
        this->game->printAllMoves();


        this->game->board->showPiecesText();
    }

    void next(){
        if(this->game->isAuto_mode()){
            this->game->next();
        }
    }

    void prew(){
        if(this->game->isAuto_mode()){
            this->game->prew();
        }
    }

    void undo(){
        this->game->undo();
    }

    void redo(){
        this->game->redo();
    }

    void move(Field *from, Field *to){
        this->game->setAuto_mode();
        this->game->move(from, to);
    }

};

#endif //CPP_CHESS_TAB_H
