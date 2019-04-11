package Chess_pieces;

import enums.color_piece;

public class Pawn extends Piece {
    private boolean is_on_starting_position = true;

    public Pawn(int x, int y, color_piece color){
        super(x, y, 1, color);
    }

    public boolean isMoveValid(int x, int y, Piece target){
        if (this.color == color_piece.BLACK){
            if (target == null){
                if(is_on_starting_position){
                    setNotOnStart();
                    return (y <= (this.y + 2) && y > this.y && this.x == x);
                }
                return (y <= (this.y + 1) && y > this.y && x == this.x);
            }else{
                return (y <= (this.y + 1) && (x == this.x+1 || x == this.x-1));
            }
        }else{
            if (target == null){
                if(is_on_starting_position){
                    setNotOnStart();
                    return (this.y <= (y + 2)  && this.y > y && this.x == x); // CHECKED
                }
                return (this.y == (y + 1) && this.y > y  && x == this.x); // CHECKED
            }else{
                return (this.y == (y + 1) && (x+1 == this.x || x-1 == this.x)); // CHECKED
            }
        }
    }
    public boolean getIsOnStart(){
        return this.is_on_starting_position;
    }
    private void setNotOnStart() {
        this.is_on_starting_position = false;
    }
}
