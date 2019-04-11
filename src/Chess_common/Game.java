package Chess_common;

import Chess_pieces.*;
import enums.color_piece;
import sun.security.jca.GetInstance;
import sun.text.resources.en.FormatData_en_IE;

import java.util.ArrayList;
import java.util.List;

public class Game {
    Board board;
    History history;
    HistoryItem item;
    private List<Move> loaded_moves; // SHOWS LOADED MOVES
    private boolean is_pawn;
    private int index; // INDEX IN MOVES
    private boolean auto_mode;

    public Game() {
        this.index = 0;
        this.loaded_moves = new ArrayList<>();
        this.board = new Board();
        this.history = new History();
        HistoryItem item;
        board.fillBoard();
        this.is_pawn = false;
        this.auto_mode = true;
    }

    public boolean isAuto_mode() {
        return auto_mode;
    }

    public void setAuto_mode() {
        this.auto_mode = false;
    }

    public void prew(){
        undo();
        this.index--;
    }

    public void next(){
        if (this.loaded_moves.size() > 0 && this.index < this.loaded_moves.size()){
            applyMove();
        }
    }

    public void applyMove(){
        Move move = this.loaded_moves.get(this.index);
        if (move.getTo() != null && move.getFrom() != null){
            fullFormat(move);
        }else if (move.getTo() != null && move.getFrom() == null){
            simpleFormat(move);
        }
    }

    public void fullFormat(Move one_move){
        if ((one_move.isTake() && one_move.getTo().getPiece() != null) || (!one_move.isTake() && one_move.getTo().getPiece() == null)){
            if (one_move.isPawn() && one_move.getFrom().getPiece() instanceof Pawn) {
                if (one_move.getExchange() == '\0'){
                    move(one_move.getFrom(), one_move.getTo());
                    this.index++;
                }else{
                    if ((one_move.getFrom().getPiece() != null && one_move.getFrom().getPiece().getColor() == color_piece.WHITE && one_move.getTo().getRow() == 0)||(one_move.getFrom().getPiece() != null && one_move.getFrom().getPiece().getColor() == color_piece.BLACK && one_move.getTo().getRow() == 7)){
                        if (this.board.is_white_on_move()){
                            if (one_move.getFrom().getPiece().getColor() == color_piece.WHITE){
                                exchange(one_move);
                            }else {
                                // TODO POPUP
                                System.out.println("MOVE WITH WRONG COLOR");
                            }
                        }else {
                            if (one_move.getFrom().getPiece().getColor() == color_piece.BLACK){
                                exchange(one_move);
                            }else {
                                // TODO POPUP
                                System.out.println("MOVE WITH WRONG COLOR");
                            }
                        }
                    }else {
                        System.out.println("WRONGLY FORMATED MOVE WRONG PLACE");
                    }
                }
            }else if (one_move.isKnight() && one_move.getFrom().getPiece() instanceof Knight) {
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
            }else if (one_move.isKing() && one_move.getFrom().getPiece() instanceof King){
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
            }else if (one_move.isQueen() && one_move.getFrom().getPiece() instanceof Queen){
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
            }else if (one_move.isBishop() && one_move.getFrom().getPiece() instanceof Bishop){
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
            }else if (one_move.isRook() && one_move.getFrom().getPiece() instanceof Rook){
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
            }else {
                System.out.println("WRONGLY FORMATED MOVE");
            }
        }else {
            System.out.println("WRONGLY FORMATED MOVE");
        }
    }

    public void exchange(Move one_move){
        if (one_move.getExchange() == 'D'){
            Queen piece = new Queen(one_move.getTo().getRow(),one_move.getTo().getCol(), one_move.getFrom().getPiece().getColor());

            saveHistory(one_move, piece);

            one_move.getFrom().removePiece();
            one_move.getTo().putPiece(piece);
            this.index++;

        }else if (one_move.getExchange() == 'V'){
            Rook piece = new Rook(one_move.getRow(),one_move.getColumn(), one_move.getFrom().getPiece().getColor());

            saveHistory(one_move, piece);

            one_move.getFrom().removePiece();
            one_move.getTo().putPiece(piece);
            this.index++;
        }else if (one_move.getExchange() == 'J'){
            Knight piece = new Knight(one_move.getRow(),one_move.getColumn(), one_move.getFrom().getPiece().getColor());

            saveHistory(one_move, piece);

            one_move.getFrom().removePiece();
            one_move.getTo().putPiece(piece);
            this.index++;
        }else if (one_move.getExchange() == 'S'){
            Bishop piece = new Bishop(one_move.getRow(),one_move.getColumn(), one_move.getFrom().getPiece().getColor());

            saveHistory(one_move, piece);

            one_move.getFrom().removePiece();
            one_move.getTo().putPiece(piece);
            this.index++;
        }else {
            System.out.println("WRONGLY FORMATED MOVE WRONG PIECE");
        }
    }

    public void saveHistory(Move one_move, Piece piece){
        HistoryItem new_item = new HistoryItem(one_move.getFrom(), one_move.getTo(), one_move.getTo().getPiece());
        new_item.setExchange(piece);
        this.history.add(new_item);
    }

    public void simpleFormat(Move one_move){
        getFromCoords(one_move);
    }

    public void getFromCoords(Move one_move){
        if (one_move.isPawn()){
            if (one_move.isTake()){
                if (one_move.getColor() == color_piece.WHITE){
                    pawnCheckTake(Field_interface.Direction.LEFT_DOWN, Field_interface.Direction.RIGHT_DOWN, one_move);
                }else if (one_move.getColor() == color_piece.BLACK){
                    pawnCheckTake(Field_interface.Direction.LEFT_UP, Field_interface.Direction.RIGHT_UP, one_move);
                }
            }else {
                if (one_move.getColor() == color_piece.WHITE){
                    pawnCheck(Field_interface.Direction.DOWN, one_move);
                }else if (one_move.getColor() == color_piece.BLACK){
                    pawnCheck(Field_interface.Direction.UP, one_move);
                }
            }
        }else if (one_move.isKing()){
            kingCheck(one_move);
        }else if (one_move.isQueen()){
            queenCheck(one_move);
        }else if (one_move.isKnight()){
            knightCheck(one_move);
        }else if (one_move.isBishop()){
            bishopCheck(one_move);
        }else if (one_move.isRook()){
            rookCheck(one_move);
        }
    }

    public void queenCheck(Move move){
        Field to = move.getTo();

        if (move.isTake() && to.getPiece() != null || !move.isTake() && to.getPiece() == null){
            if (move.getColumn() == -1 && move.getRow() == -1){
                if (bishopAll(move,to , "Queen")){
                    return;
                }
                if (rookCheckAll(move, to, "Queen")){
                    return;
                }
            }else if (move.getColumn() != -1){
                if(bishopCheckCol(move, "Queen")){
                    return;
                }
                if (rookCheckCol(move, "Queen")){
                    return;
                }
            }else if (move.getRow() != -1){
                if(bishopCheckRow(move, "Queen")){
                    return;
                }
                if (rookCheckRow(move, "Queen")){
                    return;
                }
            }
        }
        System.out.println("WRONG MOVE !!!"); // TODO POPUP
    }

    public boolean bishopCheck(Move move){
        Field to = move.getTo();

        if (move.isTake() && to.getPiece() != null || !move.isTake() && to.getPiece() == null){
            if (move.getColumn() == -1 && move.getRow() == -1){
                if (bishopAll(move,to , "Bishop")){
                    return true;
                }
            }else if (move.getColumn() != -1){
                if(bishopCheckCol(move, "Bishop")){
                    return true;
                }
            }else if (move.getRow() != -1){
                if(bishopCheckRow(move, "Bishop")){
                    return true;
                }
            }
        }
        System.out.println("WRONG MOVE !!!"); // TODO POPUP
        return false;
    }

    public boolean bishopAll(Move move, Field to, String piece){
        Field left_up = to.nextField(Field_interface.Direction.LEFT_UP);
        Field right_up = to.nextField(Field_interface.Direction.RIGHT_UP);
        Field left_down = to.nextField(Field_interface.Direction.LEFT_DOWN);
        Field right_down = to.nextField(Field_interface.Direction.RIGHT_DOWN);

        if (twoSides(left_up, Field_interface.Direction.LEFT_UP, right_up, Field_interface.Direction.RIGHT_UP, move, piece)){
            return true;
        }

        if (twoSides(left_down, Field_interface.Direction.LEFT_DOWN, right_down, Field_interface.Direction.RIGHT_DOWN, move, piece)){
            return true;
        }
        return false;
    }

    public boolean bishopCheckCol(Move move, String piece){
        Field to = move.getTo();

        if (move.getColumn() < to.getCol()){ // left
            Field left_up = to.nextField(Field_interface.Direction.LEFT_UP);
            Field left_down = to.nextField(Field_interface.Direction.LEFT_DOWN);

            return twoSides(left_up, Field_interface.Direction.LEFT_UP, left_down, Field_interface.Direction.LEFT_DOWN, move, piece);

        }else if (move.getColumn() > to.getCol()){ // right
            Field right_up = to.nextField(Field_interface.Direction.RIGHT_UP);
            Field right_down = to.nextField(Field_interface.Direction.RIGHT_DOWN);

            return twoSides(right_up, Field_interface.Direction.RIGHT_UP, right_down, Field_interface.Direction.RIGHT_DOWN, move, piece);
        }
        return false;
    }

    public boolean bishopCheckRow(Move move, String piece){
        Field to = move.getTo();

        if (move.getRow() < to.getRow()){ // up
            Field left_up = to.nextField(Field_interface.Direction.LEFT_UP);
            Field right_up = to.nextField(Field_interface.Direction.RIGHT_UP);

            return twoSides(left_up, Field_interface.Direction.LEFT_UP, right_up, Field_interface.Direction.RIGHT_UP, move, piece);

        }else if (move.getRow() > to.getRow()){ // down
            Field left_down = to.nextField(Field_interface.Direction.LEFT_DOWN);
            Field right_down = to.nextField(Field_interface.Direction.RIGHT_DOWN);

            return twoSides(left_down, Field_interface.Direction.LEFT_DOWN, right_down, Field_interface.Direction.RIGHT_DOWN, move, piece);
        }
        return false;
    }

    public boolean rookCheck(Move move){
        Field to  = move.getTo();
            if (rookCheckAll(move,to , "Rook")){
                return true;
            }
        if (move.isTake() && to.getPiece() != null || !move.isTake() && to.getPiece() == null){
            if (move.getColumn() == -1 && move.getRow() == -1){


            }else if (move.getColumn() != -1){
                if(rookCheckCol(move, "Rook")){
                    return true;
                }

            }else if (move.getRow() != -1){
                if(rookCheckRow(move, "Rook")){
                    return true;
                }

            }
        }
        System.out.println("WRONG MOVE !!!"); // TODO POPUP
        return false;
    }

    public boolean rookCheckAll(Move move,Field to, String piece){
        Field up = to.nextField(Field_interface.Direction.UP);
        Field down = to.nextField(Field_interface.Direction.DOWN);
        Field left = to.nextField(Field_interface.Direction.LEFT);
        Field right = to.nextField(Field_interface.Direction.RIGHT);

        if (twoSides(up, Field_interface.Direction.UP, down, Field_interface.Direction.DOWN, move, piece)){
            return true;
        }

        if (twoSides(left, Field_interface.Direction.LEFT, right, Field_interface.Direction.RIGHT, move, piece)){
            return true;
        }
        return false;
    }

    public boolean rookCheckRow(Move move ,String piece){
        Field to = move.getTo();
        if (move.getRow() == to.getRow()){
            Field left = to.nextField(Field_interface.Direction.LEFT);
            Field right = to.nextField(Field_interface.Direction.RIGHT);

            return twoSides(left, Field_interface.Direction.LEFT, right, Field_interface.Direction.RIGHT, move, piece);

        }else if (move.getRow() < to.getRow()){
            Field up = to.nextField(Field_interface.Direction.UP);

            return oneSide(up, Field_interface.Direction.UP, move, piece);

        }else if (move.getRow() > to.getRow()){
            Field down = to.nextField(Field_interface.Direction.DOWN);

            return oneSide(down, Field_interface.Direction.DOWN, move, piece);
        }
        return false;
    }

    public boolean oneSide(Field f1, Field_interface.Direction dir1, Move move, String piece){
        while (f1 != null){
            switch (piece){
                case "Queen":
                    if (f1.getPiece() != null && f1.getPiece() instanceof Queen){
                        pieceCheckMove(f1,move);
                        return true;
                    }
                    break;
                case "Rook":
                    if (f1.getPiece() != null && f1.getPiece() instanceof Rook){
                        pieceCheckMove(f1,move);
                        return true;
                    }
                    break;
                case "Bishop":
                    if (f1.getPiece() != null && f1.getPiece() instanceof Bishop){
                        pieceCheckMove(f1,move);
                        return true;
                    }
                    break;
            }
            f1 = f1.nextField(dir1);
        }
        return false;
    }

    public boolean twoSides(Field f1, Field_interface.Direction dir1, Field f2, Field_interface.Direction dir2, Move move, String piece){
        while (f1 != null || f2 != null){
            if (f1 != null){
                switch (piece){
                    case "Queen":
                        if (f1.getPiece() != null && f1.getPiece() instanceof Queen){
                            pieceCheckMove(f1,move);
                            return true;
                        }
                        break;
                    case "Rook":
                        if (f1.getPiece() != null && f1.getPiece() instanceof Rook){
                            pieceCheckMove(f1,move);
                            return true;
                        }
                        break;
                    case "Bishop":
                        if (f1.getPiece() != null && f1.getPiece() instanceof Bishop){
                            pieceCheckMove(f1,move);
                            return true;
                        }
                        break;
                }
                f1 = f1.nextField(dir1);
            }
            if (f2 != null){
                switch (piece){
                    case "Queen":
                        if (f2.getPiece() != null && f2.getPiece() instanceof Queen){
                            pieceCheckMove(f2,move);
                            return true;
                        }
                        break;
                    case "Rook":
                        if (f2.getPiece() != null && f2.getPiece() instanceof Rook){
                            pieceCheckMove(f2,move);
                            return true;
                        }
                        break;
                    case "Bishop":
                        if (f2.getPiece() != null && f2.getPiece() instanceof Bishop){
                            pieceCheckMove(f2,move);
                            return true;
                        }
                        break;
                }
                f2 = f2.nextField(dir2);
            }
        }
        return false;
    }

    public boolean rookCheckCol(Move move, String piece){
        Field to = move.getTo();
        if (move.getColumn() == to.getCol()){
            Field up = to.nextField(Field_interface.Direction.UP);
            Field down = to.nextField(Field_interface.Direction.DOWN);

            return twoSides(up, Field_interface.Direction.UP, down, Field_interface.Direction.DOWN, move, piece);
        }else if (move.getColumn() < to.getCol()){
            Field left = to.nextField(Field_interface.Direction.LEFT);

            return oneSide(left, Field_interface.Direction.LEFT, move, piece);
        }else if (move.getColumn() > to.getCol()){
            Field right = to.nextField(Field_interface.Direction.RIGHT);

            return oneSide(right, Field_interface.Direction.RIGHT, move, piece);
        }
        return false;
    }


    public void knightCheck(Move one_move){
        Field to = one_move.getTo();
        if (one_move.isTake() && to.getPiece() != null || !one_move.isTake() && to.getPiece() == null){
            if (one_move.getColumn() == -1 && one_move.getRow() == -1){
                knightCheckAllmoves(one_move, to);
            }else if (one_move.getColumn() != -1){
                knightCheckColumn(one_move, to);
            }else if (one_move.getRow() != -1){
                knightCheckRow(one_move, to);
            }
        }else {
            System.out.println("WRONG MOVE !!!"); // TODO POPUP
        }
    }

    public void knightCheckRow(Move move, Field to){
        if (move.getRow() != to.getRow()){
            if (move.getRow() < to.getRow()){ //from (UP) to (DOWN)
                knightCheckRowN(to, move, Field_interface.Direction.UP);
            }else if (move.getRow() > to.getRow()){ // from (DOWN) to (UP)
                knightCheckRowN(to, move, Field_interface.Direction.DOWN);
            }
        }else {
            System.out.println("WRONG MOVE !!!"); // TODO POPUP
        }
    }

    public void knightCheckRowN(Field to, Move move, Field_interface.Direction dir){
        Field from;
        int adder = dir == Field_interface.Direction.UP ? -1 : +1;
        int adder2 = dir == Field_interface.Direction.UP ? -2 : +2;

        if ((to.getRow() + adder) == move.getRow()){
            from = to.nextField(dir);
            if (from.nextField(Field_interface.Direction.LEFT) != null) {
                from = from.nextField(Field_interface.Direction.LEFT);
                if ((from = from.nextField(Field_interface.Direction.LEFT)) != null && from.getPiece() != null && from.getPiece() instanceof Knight) {
                    pieceCheckMove(from, move);
                    return;
                }
            }
            from = to.nextField(dir);
            if (from.nextField(Field_interface.Direction.RIGHT) != null ){
                from = from.nextField(Field_interface.Direction.RIGHT);
                if ((from = from.nextField(Field_interface.Direction.RIGHT)) != null && from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
        }else if ((to.getRow() + adder2) == move.getRow()){
            from = to.nextField(dir).nextField(dir);
            if (from.nextField(Field_interface.Direction.LEFT) != null) {
                from = from.nextField(Field_interface.Direction.LEFT);
                if (from.getPiece() != null && from.getPiece() instanceof Knight) {
                    pieceCheckMove(from, move);
                    return;
                }
            }
            from = to.nextField(dir).nextField(dir);
            if (from.nextField(Field_interface.Direction.RIGHT) != null){
                from = from.nextField(Field_interface.Direction.RIGHT);
                if (from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
        }
        System.out.println("WRONG MOVE !!!"); // TODO POPUP
    }

    public void knightCheckColumn(Move move, Field to){
        if (move.getColumn() != to.getCol()){
            if (move.getColumn() < to.getCol()){ //from (levo) to (pravo)
                knightCheckColumnN(to, move, Field_interface.Direction.LEFT);
            }else if (move.getColumn() > to.getCol()){ // from (pravo) to (levo)
                knightCheckColumnN(to, move, Field_interface.Direction.RIGHT);
            }
        }else {
            System.out.println("WRONG MOVE !!!"); // TODO POPUP
        }
    }

    public void knightCheckColumnN(Field to, Move move, Field_interface.Direction dir){
        Field from;
        int adder = dir == Field_interface.Direction.LEFT ? -1 : +1;
        int adder2 = dir == Field_interface.Direction.LEFT ? -2 : +2;

        if ((to.getCol() + adder) == move.getColumn()){
            from = to.nextField(dir);
            if (from.nextField(Field_interface.Direction.UP) != null){
                from = from.nextField(Field_interface.Direction.UP);
                if ((from = from.nextField(Field_interface.Direction.UP)) != null && from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
            from = to.nextField(dir);
            if (from.nextField(Field_interface.Direction.DOWN) != null){
                from = from.nextField(Field_interface.Direction.DOWN);
                if ((from = from.nextField(Field_interface.Direction.DOWN)) != null && from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
        }else if ((to.getCol() + adder2) == move.getColumn()){
            from = to.nextField(dir).nextField(dir);
            if (from.nextField(Field_interface.Direction.UP) != null){
                from = from.nextField(Field_interface.Direction.UP);
                if (from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
            from = to.nextField(dir).nextField(dir);
            if (from.nextField(Field_interface.Direction.DOWN) != null){
                from = from.nextField(Field_interface.Direction.DOWN);
                if (from.getPiece() != null && from.getPiece() instanceof Knight){
                    pieceCheckMove(from, move);
                    return;
                }
            }
        }
        System.out.println("WRONG MOVE !!!"); // TODO POPUP
    }

    public void knightCheckAllmoves(Move one_move, Field to){
        Field from;
        Field tmp;

        if((tmp = to.nextField(Field_interface.Direction.UP))!= null){
            if((from = tmp.nextField(Field_interface.Direction.LEFT_UP))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
            }else if ((from = tmp.nextField(Field_interface.Direction.RIGHT_UP))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }
        }

        if((tmp = to.nextField(Field_interface.Direction.LEFT))!= null){
            if((from = tmp.nextField(Field_interface.Direction.LEFT_UP))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }else if ((from = tmp.nextField(Field_interface.Direction.LEFT_DOWN))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }
        }

        if((tmp = to.nextField(Field_interface.Direction.DOWN))!= null){
            if((from = tmp.nextField(Field_interface.Direction.RIGHT_DOWN))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }else if ((from = tmp.nextField(Field_interface.Direction.LEFT_DOWN))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }
        }

        if((tmp = to.nextField(Field_interface.Direction.RIGHT))!= null){
            if((from = tmp.nextField(Field_interface.Direction.RIGHT_DOWN))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }else if ((from = tmp.nextField(Field_interface.Direction.RIGHT_UP))!= null && from.getPiece() != null && from.getPiece() instanceof Knight){
                pieceCheckMove(from,one_move);
                return;
            }
        }

        System.out.println("WRONG MOVE !!!");
    }

    public void pieceCheckMove(Field from, Move one_move){
        one_move.setFrom(from);
        move(one_move.getFrom(), one_move.getTo());
        this.index++;
    }

    public void kingCheck(Move one_move){
        Field to = one_move.getTo();
        for (Field_interface.Direction dir : Field_interface.Direction.values()) {
            Field tmp = to.nextField(dir);
            if (tmp != null && tmp.getPiece() != null && tmp.getPiece() instanceof King && tmp.getPiece().getColor() == one_move.getColor()){
                one_move.setFrom(tmp);
                move(one_move.getFrom(), one_move.getTo());
                this.index++;
                break;
            }
        }
        if (one_move.getFrom() == null){
            System.out.println("WRONG MOVE !!!"); // TODO POPUP
        }
    }

    public void pawnCheck(Field_interface.Direction dir, Move one_move){
        Field to = one_move.getTo();
        Field tmp = to.nextField(dir);

        if (tmp != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn){
            pieceCheckMove(tmp, one_move);
        }else if ((tmp = tmp.nextField(dir)) != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn && ((Pawn) tmp.getPiece()).getIsOnStart()){
            pieceCheckMove(tmp, one_move);
        }else {
            System.out.println("WRONG MOVE !!!");
        }
    }

    public void pawnCheckTake(Field_interface.Direction dir1, Field_interface.Direction dir2, Move one_move){ // LEFT RIGHT
        Field to = one_move.getTo();
        Field tmp;
        if (one_move.getColumn() == -1){
            if ((tmp = to.nextField(dir1)) != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn){
                pieceCheckMove(tmp, one_move);
            }else if ((tmp = to.nextField(dir2)) != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn){
                pieceCheckMove(tmp, one_move);
            }else {
                System.out.println("WRONG MOVE !!!"); // TODO POPUP
            }
        }else {
            if (one_move.getColumn() < one_move.getTo().getCol()){
                if ((tmp = to.nextField(dir1)) != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn){
                    pieceCheckMove(tmp, one_move);
                }else{
                    System.out.println("WRONG MOVE !!!"); // TODO POPUP
                }
            }else if (one_move.getColumn() > one_move.getTo().getCol()){
                if ((tmp = to.nextField(dir2)) != null && tmp.getPiece() != null && tmp.getPiece() instanceof Pawn){
                    pieceCheckMove(tmp, one_move);
                }else{
                    System.out.println("WRONG MOVE !!!"); // TODO POPUP
                }
            }
        }
    }

    public void move(Field from, Field to){
        if (!isAuto_mode()){
            delFromIndex();

            Move move = createMove(from, to);

            if (this.loaded_moves.size() % 2 == 0){
                move.setColor(color_piece.WHITE);
            }else {
                move.setColor(color_piece.BLACK);
            }

            this.loaded_moves.add(move);

        }
        item = this.board.movePiece(from, to);
        if (item != null){
            this.history.add(item);
        }
    }

    public void delFromIndex(){
        this.loaded_moves.subList(index, this.loaded_moves.size()).clear();
    }

    public Move createMove(Field from, Field to){
        Move new_move = new Move();
        int from_x = from.getCol();
        int from_y =  from.getRow();
        new_move.setFrom(new Field(from_x, from_y));

        int to_x = to.getCol();
        int to_y = to.getRow();
        new_move.setTo(new Field(to_x, to_y));

        if (to.getPiece() != null){
            new_move.setTake();
        }

        if ((from.getPiece() instanceof Pawn && from.getPiece().getColor() == color_piece.WHITE && to.getRow() == 0)||(from.getPiece() instanceof Pawn && from.getPiece().getColor() == color_piece.BLACK && to.getRow() == 7)){
            // TODO WHAT TO CHANGE TO POPUP
            new_move.setExchange('K');
        }
        if (from.getPiece() instanceof King){
            new_move.setKing();
        }else if (from.getPiece() instanceof Queen){
            new_move.setQueen();
        }else if (from.getPiece() instanceof Bishop){
            new_move.setBishop();
        }else if (from.getPiece() instanceof Knight){
            new_move.setKnight();
        }else if (from.getPiece() instanceof Rook){
            new_move.setRook();
        }

        //TODO CHACK AND MAT

        return new_move;
    }

    public int points(color_piece color){
        if (color == color_piece.BLACK){
            return this.board.getBlack_points();
        }else{
            return this.board.getWhite_points();
        }
    }

    public void undo(){
        HistoryItem item = history.undo();
        if (item != null){
            Field from = item.getFrom();
            Field to = item.getTo();
            Piece target = item.getTarget_to();
            Piece exchange = item.getExchange();

            board.moveHistory(from, to, target, exchange);
        }
    }

    public void redo(){
        HistoryItem item = history.redo();
        if (item != null){
            Field from = item.getFrom();
            Field to = item.getTo();
            Piece exchange = item.getExchange();

            board.moveHistory(to, from, null, exchange);
        }
    }

    public void loadAllMoves(String all_moves){
        if (!all_moves.equals("")){
            String[] rotation_format = all_moves.split("\n");
            for (int i = 0; i < rotation_format.length ; i++){
                String[] splited = rotation_format[i].split("\\.");
                if (i+1 != Integer.valueOf(splited[0].trim())){
                    System.out.println("Order is INVALID"+ splited[0]);
                    // TODO WINDOW POPUP
                    break;
                }else {
                    String[] arr_cord = splited[1].trim().split(" ");
                    int move_length = arr_cord.length;
                    if (move_length > 2 || move_length < 1){
                        System.out.println("INVALID NUMBER OF MOVES");
                        break;
                    }else {
                        String white = arr_cord[0];

                        if (validFormat(white)) {
                            Move w_move = formatMove(white);
                            w_move.setColor(color_piece.WHITE);
                            this.loaded_moves.add(w_move);
                            if (move_length > 1 ){
                                String black = arr_cord[1];

                                if (validFormat(black)){
                                    Move b_move = formatMove(black);
                                    b_move.setColor(this.loaded_moves.size() % 2 == 0 ? color_piece.WHITE : color_piece.BLACK);
                                    this.loaded_moves.add(b_move);
                                }else {
                                    System.out.println("FORMAT NOT VALID");
                                    break;
                                }
                            }
                        }else{
                            System.out.println("err");
                            System.out.println("FORMAT NOT VALID");
                            break;
                        }
                    }
                }
            }
        }else {
            this.auto_mode = false;
        }
        printAllMoves();
    }

    public void printAllMoves(){
        int counter = 1;
        int arr_size = this.loaded_moves.size();
        for (int idx = 0; idx < arr_size ; idx++){

            boolean even = idx % 2 == 0;
            String move = this.loaded_moves.get(idx).pritnMove();
            if (even){
                System.out.print(counter + ". " + move + " ("+ idx + ") ");
                if (idx+1 == arr_size){
                    System.out.println();
                }
            }else {
                System.out.print(move + " ("+ idx + ") \n");
                counter++;
            }
        }
    }

    public Move formatMove(String coordinates){
        Move move = new Move();
            int counter = 0;
            char sign = coordinates.charAt(counter++);
            switch (sign){
                case 'K':
                    move.setKing();
                    sign = coordinates.charAt(counter++);
                    return isBodyMove(coordinates, sign, counter, move);
                case 'D':
                    move.setQueen();
                    sign = coordinates.charAt(counter++);
                    return isBodyMove(coordinates, sign, counter, move);
                case 'V':
                    move.setRook();
                    sign = coordinates.charAt(counter++);
                    return isBodyMove(coordinates, sign, counter, move);
                case 'S':
                    move.setBishop();
                    sign = coordinates.charAt(counter++);
                    return isBodyMove(coordinates, sign, counter, move);
                case 'J':
                    move.setKnight();
                    sign = coordinates.charAt(counter++);
                    return isBodyMove(coordinates, sign, counter, move);
                default:
                    move.setPawn();
                    return isBodyMove(coordinates, sign, counter, move);
            }
    }

    public Move isBodyMove(String coordinates, char sign, int counter, Move move){
        if (isValidSign(sign)){ // is a,b,c,d,e,f,g,h (FIRST CHAR)
            move.setColumn(sign);
            sign = coordinates.charAt(counter++);
            if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8
                move.setRow(sign);

                if (coordinates.length() <= counter){
                    move.setTo(this.board.getField(move.getColumn(), move.getRow()));
                    move.setColumn(-1);
                    move.setRow(-1);

                    return move;
                }

                sign = coordinates.charAt(counter++);
                if (sign == 'x'){
                    move.setFrom(this.board.getField(move.getColumn(), move.getRow()));
                    move.setColumn(-1);
                    move.setRow(-1);

                    move.setTake();
                    sign = coordinates.charAt(counter++);
                    return isValidFromTakeToEndMove(coordinates, sign, counter, move);
                }else if (isValidSign(sign)){
                    move.setFrom(this.board.getField(move.getColumn(), move.getRow()));
                    return isValidFromTakeToEndMove(coordinates, sign, counter, move);
                }else {
                    move.setTo(this.board.getField(move.getColumn(), move.getRow()));
                    move.setColumn(-1);
                    move.setRow(-1);
                    return endSwitchFormatMove(coordinates, counter, sign, move);
                }
            }else if (sign == 'x'){
                move.setTake();
                sign = coordinates.charAt(counter++);
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }else if (isValidSign(sign)){
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }
        }else if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8 (FIRST CHAR) simplified version DONE
            move.setRow(sign);
            sign = coordinates.charAt(counter++);
            if(isValidSign(sign)){ // is a,b,c,d,e,f,g,h (SECOND CHAR)
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }else if (sign == 'x'){ // is x (SECOND CHAR)
                move.setTake();
                sign = coordinates.charAt(counter++);
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }
        }else if (sign == 'x'){
            move.setTake();
            sign = coordinates.charAt(counter++);
            return isValidFromTakeToEndMove(coordinates, sign, counter, move);
        }
        return move;
    }

    public Move isValidFromTakeToEndMove(String coordinates, char sign, int counter, Move move){
        int col = setColumnI(sign);
        sign = coordinates.charAt(counter++);
        int row = setRowI(sign);
        move.setTo(this.board.getField(col,row));
        if (coordinates.length() > counter){
            sign = coordinates.charAt(counter++);
            return endSwitchFormatMove(coordinates, counter, sign, move);
        }else {
            return move;
        }
    }

    public Move endSwitchFormatMove(String coordinates, int counter, char sign, Move move){
        switch (sign){
            case 'D':
            case 'V':
            case 'S':
            case 'J':
                move.setExchange(sign);
                if (coordinates.length() > counter){
                    sign = coordinates.charAt(counter++);
                    if (sign == '#' || sign == '+'){
                        move.setMat();
                    }else if (sign == '+'){
                        move.setCheck();
                    }
                    return move;
                }else {
                    return move;
                }
            case '#':
                move.setMat();
                return move;
            case '+':
                move.setCheck();
                return move;
        }
        return move;
    }

    // VALIDATION OF MOVE FORMAT

    public boolean validFormat(String coordinates){
        if (coordinates.length() < 2){
            System.out.println("INVALID LENGTH OF COORDINATES");
        }else {
            int counter = 0;
            char sign = coordinates.charAt(counter++);
            switch (sign){
                case 'K':
                case 'D':
                case 'V':
                case 'S':
                case 'J':
                    sign = coordinates.charAt(counter++);
                    return isBody(coordinates, sign, counter);
                default:
                    this.is_pawn = true;
                    return isBody(coordinates, sign, counter);
            }
        }
        return false;
    }

    public boolean isValidSign(char Character){
        // is a,b,c,d,e,f,g,h
        return ((int) Character) > 96 && ((int) Character) < 105;
    }

    public boolean isValidNumber(char Character){
        // is 1,2,3,4,5,6,7,8
        return ((int) Character) > 48 && ((int) Character) < 57;
    }

    public boolean isValidFromTakeToEnd(String coordinates, char sign, int counter){
        if (!isValidSign(sign)){ // is a,b,c,d,e,f,g,h
            System.out.println(sign + " IS NOT OK");
            return false;
        }else {
            if (coordinates.length() < counter){
                return false;
            }
            sign = coordinates.charAt(counter++);
            if (!isValidNumber(sign)){
                System.out.println(sign + " IS NOT OK");
                return false;
            }else {
                if (coordinates.length() > counter){
                    sign = coordinates.charAt(counter++);
                    return endSwitchFormat(coordinates, sign, counter);
                }else {
                    return true;
                }
            }
        }
    }

    public boolean endSwitchFormat(String coordinates, char sign, int counter){
        switch (sign){
            case 'D':
            case 'V':
            case 'S':
            case 'J':
                if (!this.is_pawn){
                    System.out.println("ONLY PAWN CAN EXCHANGE");
                    return false;
                }
                if (coordinates.length() > counter){
                    sign = coordinates.charAt(counter++);
                    if (sign == '#' || sign == '+'){
                        if (coordinates.length() > counter){
                            sign = coordinates.charAt(counter++);
                            System.out.println(sign + " IS NOT OK");
                            return false;
                        }else {
                            return true;
                        }
                    }
                    System.out.println(sign + " IS NOT OK");
                    return false;
                }else {
                    return true;
                }
            case '#':
            case '+':
                if (coordinates.length() > counter){
                    sign = coordinates.charAt(counter++);
                    System.out.println(sign + " IS NOT OK");
                    return false;
                }
                return true;
            default:
                System.out.println(sign + " IS NOT OK");
                return false;
        }
    }

    public boolean isBody(String coordinates, char sign, int counter){
        if (isValidSign(sign)){ // is a,b,c,d,e,f,g,h (FIRST CHAR)
            if (coordinates.length() <= counter){
                return false;
            }
            sign = coordinates.charAt(counter++);
            if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8
                if (coordinates.length() <= counter){
                    return true;
                }
                sign = coordinates.charAt(counter++);
                if (sign == 'x'){
                    if (coordinates.length() <= counter){
                        return false;
                    }
                    sign = coordinates.charAt(counter++);
                    return isValidFromTakeToEnd(coordinates, sign, counter);
                }else if (isValidSign(sign)){
                    return isValidFromTakeToEnd(coordinates, sign, counter);
                }else {
                    return endSwitchFormat(coordinates, sign, counter);

                }
            }else if (sign == 'x'){
                if (coordinates.length() <= counter){
                    return false;
                }
                sign = coordinates.charAt(counter++);
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else if (isValidSign(sign)){
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else {
                return false;
            }
        }else if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8 (FIRST CHAR) simplified version DONE
            sign = coordinates.charAt(counter++);
            if(isValidSign(sign)){ // is a,b,c,d,e,f,g,h (SECOND CHAR)
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else if (sign == 'x'){ // is x (SECOND CHAR)
                if (coordinates.length() <= counter){
                    return false;
                }
                sign = coordinates.charAt(counter++);
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else {
                return false;
            }
        }else if (sign == 'x'){
            if (coordinates.length() <= counter){
                return false;
            }
            sign = coordinates.charAt(counter++);
            return isValidFromTakeToEnd(coordinates, sign, counter);
        }else {
            return false;
        }
    }

    public int setColumnI(char sign){
        return ((int)sign - 97);
    }

    public int setRowI(char sign){
        return 8 - ((int)sign - 48);
    }
}
