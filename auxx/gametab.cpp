#include "gametab.h"
#include "ui_gametab.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"


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

void GameTab::drawFigure (int x, int y, bool isPawn, bool isKnight, bool isBishop, bool isRook, bool isQueen, bool isKing)
{

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
    int buttCount = ui->boardMembers->buttons().count();
    printf("number of Butts: %d", buttCount);


}

// BOARD CONTROLS //




