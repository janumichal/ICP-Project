package Chess_common;

import Chess_pieces.Piece;

import java.util.EnumMap;

public class Field implements Field_interface{
    private int row;
    private int col;

    private Piece piece_on_board = null;
    private EnumMap<Field_interface.Direction, Field> fields_around;

    public Field(int x, int y){
        fields_around = new EnumMap<>(Field_interface.Direction.class);
        setCol(x);
        setRow(y);
    }

    public Field nextField(Field_interface.Direction direction){
        return this.fields_around.get(direction);
    }

    public void addNextField(Field_interface.Direction direction, Field field){
        this.fields_around.put(direction, field);
    }


    public void setCol(int col){
        this.col = col;
    }

    public void setRow(int row){
        this.row = row;
    }

    public int getRow() {
        return this.row;
    }

    public int getCol() {
        return this.col;
    }

    // get piece placed in this field
    public Piece getPiece() {
        return this.piece_on_board;
    }

    // set piece on this field
    public void setPiece(Piece piece){
        this.piece_on_board = piece;
    }

    // check if field is empty
    public boolean isEmpty(){
        return this.piece_on_board == null;
    }

    // put piece on field if empty and return true if piece was successfuly placed
    public void putPiece(Piece piece){
        removePiece();
        if (piece != null){
            piece.setCol(this.getCol());
            piece.setRow(this.getRow());
        }
        setPiece(piece);
    }

    public Piece removePiece() {
        Piece piece = this.piece_on_board;
        this.piece_on_board = null;
        return piece;
    }

    public void getCords(){
        System.out.println("["+getCol()+","+getRow()+"]");
    }

}
