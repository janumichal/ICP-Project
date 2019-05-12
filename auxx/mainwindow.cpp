#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gametab.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    ui->TabWidget->addTab(new GameTab, QString("Game %0").arg(ui->TabWidget->count()));
    ui->TabWidget->setCurrentIndex(ui->TabWidget->count() - 1);

    //int tab_index = ui->TabWidget->count();

    //Todo indexovani tabu a jejich vytvareni.

}

void MainWindow::on_TabWidget_tabCloseRequested(int index)
{
    ui->TabWidget->removeTab(index);
}




//void MainWindow::on_LoadButton_clicked()
//{
//    ui->PlayButton->setEnabled(true);
//    ui->NextButton->setEnabled(true);
//    ui->PlayButton->setEnabled(true);
//}
