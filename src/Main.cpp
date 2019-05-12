//
// Created by janum on 11.04.2019.
//
#include "Chess_common/Tab.h"

using namespace std;

int main(){

//    ########################################## GAME 1 ##############################################
    cout << "#### GAME 1 START ####" <<  endl;
    Tab *tab1 = new Tab();

    tab1->Load("../examples/game1.txt");
//    tab1->Load("examples/game1.txt");

    tab1->newGame();
    tab1->start_auto();
    tab1->PrintGame();

    tab1->next();
    tab1->next();

    tab1->next();
    tab1->next();

    tab1->prew();
//
//    tab1->next();
//    tab1->next();
//
//    tab1->next();
//    tab1->next();
//
//    tab1->next();
//    tab1->next();
//
//    tab1->next();
//    tab1->next();

    cout << "#### GAME 1 END ####" <<  endl;
//    ########################################## GAME 2 ##############################################
    cout << "#### GAME 2 START ####" <<  endl;
    Tab *tab2 = new Tab();

    tab2->Load("../examples/game2.txt");
//    tab2->Load("examples/game2.txt");

    tab2->newGame();
    tab2->start_auto();
    tab2->PrintGame();

    tab2->Move("a2","a3");
    tab2->Move("a7","a6");

    tab2->undo();

    cout << "#### GAME 2 END ####" <<  endl;
//    ########################################## GAME 3 ##############################################
    cout << "#### GAME 3 START ####" <<  endl;
    Tab *tab3 = new Tab();

    tab3->Load("../examples/game3.txt");
//    tab3->Load("examples/game3.txt");

    tab3->newGame();
    tab3->start_auto();
    tab3->PrintGame();

    tab3->next();
    tab3->next();



    tab3->Move("a2","a3");
    tab3->Move("a7","a6");

    cout << "#### GAME 3 END ####" <<  endl;

}

