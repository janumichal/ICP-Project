package Chess_common;

import enums.color_piece;

public class Tab {
    Game game;

    public Tab() {
        this.game = new Game();
        String all_moves = "1. d4 a5\n" +
                "2. Dec3 J8f6\n" +
                "3. cxd5 c7c6\n" +
                "4. d5xc6 f7f5\n";

        this.game.loadAllMoves(all_moves);

        next();
        next();

        next();
//        next();

//        next();
//        next();
//
//        next();
//        next();
//
//        next();
//        next();
//
//        next();


//        Field f1 = this.game.board.getField(2,4);
//        Field f2 = this.game.board.getField(3,3);
//        move(f1,f2);


        this.game.board.printPoints();

        System.out.println();
        this.game.printAllMoves();


        this.game.board.showPiecesText();
    }

    public void next(){
        if(this.game.isAuto_mode()){
            this.game.next();
        }
    }

    public void prew(){
        if(this.game.isAuto_mode()){
            this.game.prew();
        }
    }

    public void undo(){
        this.game.undo();
    }

    public void redo(){
        this.game.redo();
    }

    public void move(Field from, Field to){
        this.game.setAuto_mode();
        this.game.move(from, to);
    }
}
