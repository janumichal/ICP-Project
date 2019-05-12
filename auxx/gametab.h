#ifndef GAMETAB_H
#define GAMETAB_H

#include <QWidget>

namespace Ui {
class GameTab;
}

class GameTab : public QWidget
{
    Q_OBJECT

public:
    explicit GameTab(QWidget *parent = nullptr);
    ~GameTab();

private slots:

    void on_LoadButton_clicked();

    //void on_h6button_clicked();

    void on_SaveButton_clicked();

    void on_UndoButton_clicked();

    void on_RedoButton_clicked();

    void on_PlayButton_clicked();

    void on_NextButton_clicked();

    void on_PrevButton_clicked();

    void drawFigure(int i, int x, bool isPawn, bool isKnight, bool isBishop, bool isRook, bool isQueen, bool isKing);
    //void on_a1button_clicked();


private:
    Ui::GameTab *ui;
};

#endif // GAMETAB_H
