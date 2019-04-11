package Chess_pieces;

import enums.color_piece;

public class Knight extends Piece {
    public Knight(int x, int y, color_piece color){
        super(x, y, 3, color);
    }

    public boolean isMoveValid(int x, int y){
        if(x > this.x){
            if(y > this.y){ // LEFT DOWN
                return ((x == (this.x+1) && y == (this.y+2)) || (x == (this.x+2) && y == (this.y+1)));
            }else if (y < this.y){ //LEFT UP
                return ((x == (this.x+1) && y == (this.y-2)) || (x == (this.x+2) && y == (this.y-1)));
            }
            return false;
        }else if (x < this.x){
            if(y > this.y){ // RIGHT DOWN
                return ((x == (this.x-1) && y == (this.y+2)) || (x == (this.x-2) && y == (this.y+1)));
            }else if (y < this.y){ //RIGHT UP
                return ((x == (this.x-1) && y == (this.y-2)) || (x == (this.x-2) && y == (this.y-1)));
            }
            return false;
        }
        return false;
    }
}
