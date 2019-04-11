package Chess_common;

import Chess_pieces.Pawn;
import Chess_pieces.Piece;

public class HistoryItem {
    private Field from;
    private Field to;
    private Piece target_to;
    private Piece exchange;

    public HistoryItem(Field from, Field to, Piece target_to) {
        this.from = from;
        this.to = to;
        this.target_to = target_to;
        this.exchange = null;
    }

    public Field getFrom() {
        return from;
    }

    public Field getTo() {
        return to;
    }

    public Piece getTarget_to() {
        return target_to;
    }

    public void setExchange(Piece piece){
        this.exchange = piece;
    }

    public Piece getExchange() {
        return exchange;
    }
}
