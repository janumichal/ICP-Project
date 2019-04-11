package Chess_common;

import Chess_pieces.Piece;

public interface Field_interface {
    Piece getPiece();
    void setPiece(Piece piece);

    boolean isEmpty();

    void putPiece(Piece piece);
    Piece removePiece();

    void setCol(int col);
    void setRow(int row);

    void getCords();

    void addNextField(Field_interface.Direction direction, Field field);
    Field nextField(Field_interface.Direction direction);

    enum Direction{
        LEFT_UP,
        UP,
        RIGHT_UP,
        RIGHT,
        RIGHT_DOWN,
        DOWN,
        LEFT_DOWN,
        LEFT;
    }
}
