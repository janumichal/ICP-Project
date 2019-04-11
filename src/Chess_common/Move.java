package Chess_common;

import enums.color_piece;

public class Move {
    private Field from;
    private Field to;
    private boolean is_take;
    private boolean is_check;
    private boolean is_mat;
    private color_piece color;

    private boolean is_king;
    private boolean is_queen;
    private boolean is_bishop;

    private boolean is_knight;
    private boolean is_pawn;
    private boolean is_rook;

    private int column;
    private int row;

    private char exchange;

    public Move() {
        this.column = -1;
        this.row = -1;
        this.is_take = false;
        this.is_check = false;
        this.is_mat = false;

        this.is_knight = false;
        this.is_king = false;
        this.is_queen = false;
        this.is_bishop = false;
        this.is_pawn = false;
        this.is_rook = false;
    }

    public void setColor(color_piece color) {
        this.color = color;
    }

    public color_piece getColor() {
        return color;
    }

    public String pritnMove(){
        StringBuffer output = new StringBuffer();
        if (isKing()){
            output.append('K');
        }else if (isQueen()){
            output.append('D');
        }else if (isKnight()){
            output.append('J');
        }else if (isBishop()){
            output.append('S');
        }else if (isRook()){
            output.append('V');
        }

        if (this.from != null){
            char x = (char)(this.from.getCol() + 97);
            char y = (char)(8 - this.from.getRow() + 48);
            output.append(x);
            output.append(y);

        }else {
            if (this.column != -1){
                char znak = (char)(this.column + 97); // COLUMN WRONG
                output.append(znak);
            }else if (this.row != -1){
                char znak = (char)(8 - this.row + 48); // COLUMN WRONG
                output.append(znak);
            }
        }

        if (isTake()){
            output.append('x');
        }

        char x = (char)(this.to.getCol() + 97);
        char y = (char)(8 - this.to.getRow() + 48);
        output.append(x);
        output.append(y);
        if (this.getExchange() != '\0'){
            output.append(this.getExchange());
        }
        if (isMat()){
            output.append('#');
        }else if (isCheck()){
            output.append('+');
        }
        return output.toString();
    }


    public char getExchange() {
        return exchange;
    }

    public void setExchange(char exchange) {
        this.exchange = exchange;
    }

    public void setFrom(Field from) {
        this.from = from;
    }

    public void setTo(Field to) {
        this.to = to;
    }

    public void setTake() {
        this.is_take = true;
    }

    public void setCheck() {
        this.is_check = true;
    }

    public void setMat() {
        this.is_mat = true;
    }

    public void setKing() {
        this.is_king = true;
    }

    public void setQueen() {
        this.is_queen = true;
    }

    public void setBishop() {
        this.is_bishop = true;
    }

    public void setKnight() {
        this.is_knight = true;
    }

    public void setPawn() {
        this.is_pawn = true;
    }

    public void setRook() {
        this.is_rook = true;
    }

    public Field getFrom() {
        return from;
    }

    public Field getTo() {
        return to;
    }

    public boolean isTake() {
        return is_take;
    }

    public boolean isCheck() {
        return is_check;
    }

    public boolean isMat() {
        return is_mat;
    }

    public boolean isKing() {
        return is_king;
    }

    public boolean isQueen() {
        return is_queen;
    }

    public boolean isBishop() {
        return is_bishop;
    }

    public boolean isKnight() {
        return is_knight;
    }

    public boolean isPawn() {
        return is_pawn;
    }

    public boolean isRook() {
        return is_rook;
    }

    public void setColumn(char column) {
        this.column = ((int)column - 97);
    }

    public void setColumn(int column) {
        this.column = column;
    }

    public void setRow(char row) {
        this.row = 8 - ((int)row - 48);
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getColumn() {
        return column;
    }

    public int getRow() {
        return row;
    }
}
