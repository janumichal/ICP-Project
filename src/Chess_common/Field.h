/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_FIELD_H
#define CPP_CHESS_FIELD_H

#include <map>
#include "../Chess_pieces/Piece.h"
#include "../enum/direction.h"

using namespace std;

class Field{
private:
    int row{};
    int col{};
    Piece *piece_on_board = nullptr;
    std::map<direction , Field*> fields_around;

public:
    /**
     * @brief Creates instance of Field.
     * @param x Vertical position of Field.
     * @param y Horizontal position of Field.
     */
    Field(int x, int y);

    /**
     * @brief Gets Field in specific direction on board.
     * @param direction Diretion to go in.
     * @return Field in direction.
     */
    Field* nextField(direction direction);

    /**
     * @brief Adds Field to enum map in direction.
     * @param direction direction to set.
     * @param field Field to set in direction.
     */
    void addNextField(direction direction, Field *field);

    /**
     * @brief Setter for column.
     * @param col Column that is being set.
     */
    void setCol(int col);

    /**
     * @brief Setter for row.
     * @param col Row that is being set.
     */
    void setRow(int row);

    /**
     * @brief Getter for row.
     * @return row.
     */
    int getRow() ;

    /**
     * @brief Getter for column.
     * @return column.
     */
    int getCol();

    /**
     * @brief Getter for piece in field.
     * @return Pointer on piece.
     */
    Piece* getPiece();

    /**
     * @brief Setter for piece in field.
     * @param piece Piece that is being set.
     */
    void setPiece(Piece* piece);

    /**
     * @brief Checks if field is empty
     * @return is Empty.
     */
    bool isEmpty();

    /**
     * @brief Puts piece in field.
     * @param piece Piece that is being put.
     */
    void putPiece(Piece* piece);

    /**
     * @brief Removes Piece from field.
     * @return Pointer on piece that has been removed from field.
     */
    Piece* removePiece();

};

#endif //CPP_CHESS_FIELD_H
