package Chess_pieces;

import enums.color_piece;

public class Piece {
    protected int x, y; // Position on board
    protected color_piece color = null; // Color of piece
    protected int value_of_piece; // value of certain piece

    public Piece(int x, int y, int value_of_piece, color_piece color){
        this.x = x;
        this.y = y;
        this.value_of_piece = value_of_piece;
        this.color = color;
    }

    public int getValue(){
        return this.value_of_piece;
    }

    public color_piece getColor(){
        return color;
    }

    public void setCol(int x) {
        this.x = x;
    }

    public void setRow(int y) {
        this.y = y;
    }
}
