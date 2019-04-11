package Chess_pieces;

import enums.color_piece;

public class Queen extends Piece {
    public Queen(int x, int y, color_piece color){
        super(x, y, 9, color);
    }

    public boolean isMoveValid(int x, int y){
        int array_size = 8;

        for (int i = 1; i <= array_size; i++){

            if ((x == this.x-i)&&(y == this.y-i)){
                return true;
            }else if((x == this.x-i)&&(y == this.y+i)){
                return true;
            }else if ((x == this.x+i)&&(y == this.y+i)){
                return true;
            }else if (((x == this.x+i)&&(y == this.y-i))){
                return true;
            }
        }
        return ((x == this.x && y != this.y) || (x != this.x && y == this.y));
    }
}
