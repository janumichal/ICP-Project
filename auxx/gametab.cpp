#include "gametab.h"
#include "ui_gametab.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "Chess_common/Tab.h"
#include "Chess_common/Board.h"
#include "Chess_common/Game.h"
#include "Chess_common/Field.h"
#include "Chess_common/Move.h"




GameTab::GameTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTab)
{
    ui->setupUi(this);
}



GameTab::~GameTab()
{
    delete ui;
}

// CONTROL PANEL SECTION //

void GameTab::on_LoadButton_clicked()
{
    ui->PlayButton->setEnabled(true);
    ui->NextButton->setEnabled(true);
    ui->PrevButton->setEnabled(true);

}


void GameTab::on_SaveButton_clicked() //Save
{
    //Todo
}

void GameTab::on_UndoButton_clicked() //Undo
{
    //Todo
}

void GameTab::on_RedoButton_clicked() //Redo
{
    //Todo
}

void GameTab::on_PlayButton_clicked() //Play
{
    //Todo
}

void GameTab::on_NextButton_clicked() //Next
{
    //Todo
}

void GameTab::on_PrevButton_clicked() //Prev
{
    //Todo
}

// BOARD CONTROLS //

void GameTab::drawFigure(int x,int y, Tab *tab){

         QLabel* aux = Get_Coord(x,y);

         Piece *piece = tab->game->board->getField(x, y)->getPiece();
         if(isRook(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/Rook_w.png");
                    aux->setPixmap(figure);
             }else{
                    QPixmap figure(":/Rook_b.png");
                    aux->setPixmap(figure);
             }
         }else if(isKnight(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/Knight_w.png");
                    aux->setPixmap(figure);
             }else{
                    QPixmap figure(":/Knight_b.png");
                    aux->setPixmap(figure);
             }
         }else if(isBishop(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/Bishop_w.png");
                    aux->setPixmap(figure);
             }else{
                    QPixmap figure(":/Bishop_b.png");
                    aux->setPixmap(figure);

             }
         }else if(isKing(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/King_w.png");
                    aux->setPixmap(figure);

             }else{
                    QPixmap figure(":/King_b.png");
                    aux->setPixmap(figure);

             }
         }else if(isQueen(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/Queen_w.png");
                    aux->setPixmap(figure);

             }else{
                    QPixmap figure(":/Queen_b.png");
                    aux->setPixmap(figure);
             }
         }else if(isPawn(piece)){
             if (piece->getColor() == WHITE){
                    QPixmap figure(":/Pawn_w.png");
                    aux->setPixmap(figure);
             }else{
                    QPixmap figure(":/Pawn_b.png");
                    aux->setPixmap(figure);
             }
         }else{
                    aux->clear();

         }


     }

QLabel* GameTab::Get_Coord(int x, int y)
{
    switch(y)
    {

        case 1: //a
        {
            switch(x)
            {
                case 1: return ui->a1;
                case 2: return ui->a2;
                case 3: return ui->a3;
                case 4: return ui->a4;
                case 5: return ui->a5;
                case 6: return ui->a6;
                case 7: return ui->a7;
                case 8: return ui->a8;
            }
        }
        case 2:
        {
            switch(x)
            {
                case 1: return ui->b1;
                case 2: return ui->b2;
                case 3: return ui->b3;
                case 4: return ui->b4;
                case 5: return ui->b5;
                case 6: return ui->b6;
                case 7: return ui->b7;
                case 8: return ui->b8;
            }
        }
        case 3:
        {
            switch(x)
            {
                case 1: return ui->c1;
                case 2: return ui->c2;
                case 3: return ui->c3;
                case 4: return ui->c4;
                case 5: return ui->c5;
                case 6: return ui->c6;
                case 7: return ui->c7;
                case 8: return ui->c8;
            }
        }
        case 4:
        {
            switch(x)
            {
                case 1: return ui->d1;
                case 2: return ui->d2;
                case 3: return ui->d3;
                case 4: return ui->d4;
                case 5: return ui->d5;
                case 6: return ui->d6;
                case 7: return ui->d7;
                case 8: return ui->d8;
            }
        }
        case 5:
        {
            switch(x)
            {
                case 1: return ui->e1;
                case 2: return ui->e2;
                case 3: return ui->e3;
                case 4: return ui->e4;
                case 5: return ui->e5;
                case 6: return ui->e6;
                case 7: return ui->e7;
                case 8: return ui->e8;
            }
        }
        case 6:
        {
            switch(x)
            {
                case 1: return ui->f1;
                case 2: return ui->f2;
                case 3: return ui->f3;
                case 4: return ui->f4;
                case 5: return ui->f5;
                case 6: return ui->f6;
                case 7: return ui->f7;
                case 8: return ui->f8;
            }
        }
        case 7:
        {
            switch(x)
            {
                case 1: return ui->g1;
                case 2: return ui->g2;
                case 3: return ui->g3;
                case 4: return ui->g4;
                case 5: return ui->g5;
                case 6: return ui->g6;
                case 7: return ui->g7;
                case 8: return ui->g8;
            }
        }
        case 8:
        {
            switch(x)
            {
                case 1: return ui->h1;
                case 2: return ui->h2;
                case 3: return ui->h3;
                case 4: return ui->h4;
                case 5: return ui->h5;
                case 6: return ui->h6;
                case 7: return ui->h7;
                case 8: return ui->h8;
            }
        }
    }
    return nullptr;
}

void GameTab::drawBoard(int size, Tab *tab)
{
    for (int x = 1; x <= size; x++)
    {
        for (int y = 1; y <= size; y++)
        {
            drawFigure(x,y, tab);
        }
    }
}





//New Game


//Tab *tab = new Tab;
















