package Chess_pieces;

import enums.color_piece;

public class King extends Piece {
    public King(int x, int y, color_piece color){
        super(x, y, 0, color);
    }

    public boolean isMoveValid(int x, int y){
        return (!(x == this.x && y == this.y)) && ((( this.x == x+1 ) || ( this.x == x-1 ) || (this.x == x && this.y != y)) && (( this.y == y-1 ) || ( this.y == y+1 ) || (this.y == y && this.x != x)) );
    }
}
