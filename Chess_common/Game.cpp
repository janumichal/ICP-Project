//
// Created by janum on 24.04.2019.
//

#include "Game.h"
#include "others.h"

using namespace std;

Game::Game(){
    this->index = 0;
    this->board = new Board();
    board->fillBoard();
    this->history = new History();
    this->is_pawn = false;
    this->auto_mode = true;
}

bool Game::isAuto_mode() {
    return this->auto_mode;
}

void Game::setAuto_mode() {
    this->auto_mode = false;
}

void Game::prew(){
    undo();
    this->index--;
}

void Game::next(){
    if (!this->loaded_moves.empty() && this->index < this->loaded_moves.size()){
        applyMove();
    }
}

void Game::applyMove(){
    Move *move = this->loaded_moves[this->index];
    if (move->getTo() != nullptr && move->getFrom() != nullptr){
        fullFormat(move);
    }else if (move->getTo() != nullptr && move->getFrom() == nullptr){
        simpleFormat(move);
    }
}


void Game::fullFormat(Move *one_move){
    if ((one_move->isTake() && one_move->getTo()->getPiece() != nullptr) || (!one_move->isTake() && one_move->getTo()->getPiece() == nullptr)){
        if (one_move->isPawn() && isPawn(one_move->getFrom()->getPiece())) {
            if (one_move->getExchange() == '\0'){
                move(one_move->getFrom(), one_move->getTo());
                this->index++;
            }else{
                if ((one_move->getFrom()->getPiece() != nullptr && one_move->getFrom()->getPiece()->getColor() == WHITE && one_move->getTo()->getRow() == 0)||(one_move->getFrom()->getPiece() != nullptr && one_move->getFrom()->getPiece()->getColor() == BLACK && one_move->getTo()->getRow() == 7)){
                    if (this->board->is_white_on_move()){
                        if (one_move->getFrom()->getPiece()->getColor() == WHITE){
                            exchange(one_move);
                        }else {
                            // TODO POPUP
                            printf("MOVE WITH WRONG COLOR\n");
                        }
                    }else {
                        if (one_move->getFrom()->getPiece()->getColor() == BLACK){
                            exchange(one_move);
                        }else {
                            // TODO POPUP
                            printf("MOVE WITH WRONG COLOR\n");
                        }
                    }
                }else {
                    printf("WRONGLY FORMATED MOVE WRONG PLACE\n");
                }
            }
        }else if (one_move->isKnight() && isKnight(one_move->getFrom()->getPiece())) {
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
        }else if (one_move->isKing() && isKing(one_move->getFrom()->getPiece())){
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
        }else if (one_move->isQueen() && isQueen(one_move->getFrom()->getPiece())){
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
        }else if (one_move->isBishop() && isBishop(one_move->getFrom()->getPiece())){
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
        }else if (one_move->isRook() && isRook(one_move->getFrom()->getPiece())){
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
        }else {
            printf("WRONGLY FORMATED MOVE\n");
        }
    }else {
        printf("WRONGLY FORMATED MOVE\n");
    }
}


void Game::exchange(Move* one_move){
    if (one_move->getExchange() == 'D'){
        auto *piece = new Queen(one_move->getTo()->getRow(),one_move->getTo()->getCol(), one_move->getFrom()->getPiece()->getColor());

        saveHistory(one_move, piece);

        one_move->getFrom()->removePiece();
        one_move->getTo()->putPiece(piece);
        this->index++;

    }else if (one_move->getExchange() == 'V'){
        auto *piece = new Rook(one_move->getRow(),one_move->getColumn(), one_move->getFrom()->getPiece()->getColor());

        saveHistory(one_move, piece);

        one_move->getFrom()->removePiece();
        one_move->getTo()->putPiece(piece);
        this->index++;
    }else if (one_move->getExchange() == 'J'){
        auto *piece = new Knight(one_move->getRow(),one_move->getColumn(), one_move->getFrom()->getPiece()->getColor());

        saveHistory(one_move, piece);

        one_move->getFrom()->removePiece();
        one_move->getTo()->putPiece(piece);
        this->index++;
    }else if (one_move->getExchange() == 'S'){
        auto *piece = new Bishop(one_move->getRow(),one_move->getColumn(), one_move->getFrom()->getPiece()->getColor());

        saveHistory(one_move, piece);

        one_move->getFrom()->removePiece();
        one_move->getTo()->putPiece(piece);
        this->index++;
    }else {
        printf("WRONGLY FORMATED MOVE WRONG PIECE\n");
    }
}


void Game::saveHistory(Move *one_move, Piece *piece){
    auto *new_item = new HistoryItem();
    new_item->addValues(one_move->getFrom(), one_move->getTo(), one_move->getTo()->getPiece());
    new_item->setExchange(piece);
    this->history->add(new_item);
}

void Game::simpleFormat(Move* one_move){
    getFromCoords(one_move);
}

void Game::getFromCoords(Move* one_move){
    if (one_move->isPawn()){
        if (one_move->isTake()){
            if (one_move->getColor() == WHITE){
                pawnCheckTake(LEFT_DOWN, RIGHT_DOWN, one_move);
            }else if (one_move->getColor() == BLACK){
                pawnCheckTake(LEFT_UP, RIGHT_UP, one_move);
            }
        }else {
            if (one_move->getColor() == WHITE){
                pawnCheck(DOWN, one_move);
            }else if (one_move->getColor() == BLACK){
                pawnCheck(UP, one_move);
            }
        }
    }else if (one_move->isKing()){
        kingCheck(one_move);
    }else if (one_move->isQueen()){
        queenCheck(one_move);
    }else if (one_move->isKnight()){
        knightCheck(one_move);
    }else if (one_move->isBishop()){
        bishopCheck(one_move);
    }else if (one_move->isRook()){
        rookCheck(one_move);
    }
}

void Game::queenCheck(Move *move){
    Field *to = move->getTo();

    if ((move->isTake() && to->getPiece() != nullptr) || (!move->isTake() && to->getPiece() == nullptr)){
        if (move->getColumn() == -1 && move->getRow() == -1){
            if (bishopAll(move, to, "Queen")){
                return;
            }
            if (rookCheckAll(move, to, "Queen")){
                return;
            }
        }else if (move->getColumn() != -1){
            if(bishopCheckCol(move, "Queen")){
                return;
            }
            if (rookCheckCol(move, "Queen")){
                return;
            }
        }else if (move->getRow() != -1){
            if(bishopCheckRow(move, "Queen")){
                return;
            }
            if (rookCheckRow(move, "Queen")){
                return;
            }
        }
    }
    printf("WRONG MOVE !!!\n"); // TODO POPUP
}


bool Game::bishopCheck(Move *move){
    Field *to = move->getTo();

    if ((move->isTake() && to->getPiece() != nullptr) || (!move->isTake() && to->getPiece() == nullptr)){
        if (move->getColumn() == -1 && move->getRow() == -1){
            if (bishopAll(move,to , "Bishop")){
                return true;
            }
        }else if (move->getColumn() != -1){
            if(bishopCheckCol(move, "Bishop")){
                return true;
            }
        }else if (move->getRow() != -1){
            if(bishopCheckRow(move, "Bishop")){
                return true;
            }
        }
    }
    printf("WRONG MOVE !!!\n"); // TODO POPUP
    return false;
}


bool Game::bishopAll(Move *move, Field *to, const string &piece){
    Field *left_up = to->nextField(LEFT_UP);
    Field *right_up = to->nextField(RIGHT_UP);
    Field *left_down = to->nextField(LEFT_DOWN);
    Field *right_down = to->nextField(RIGHT_DOWN);

    if (twoSides(left_up, LEFT_UP, right_up, RIGHT_UP, move, piece)){
        return true;
    }

    if (twoSides(left_down, LEFT_DOWN, right_down, RIGHT_DOWN, move, piece)){
        return true;
    }
    return false;
}


bool Game::bishopCheckCol(Move *move, const string &piece){
    Field *to = move->getTo();

    if (move->getColumn() < to->getCol()){ // left
        Field *left_up = to->nextField(LEFT_UP);
        Field *left_down = to->nextField(LEFT_DOWN);

        return twoSides(left_up, LEFT_UP, left_down, LEFT_DOWN, move, piece);

    }else if (move->getColumn() > to->getCol()){ // right
        Field *right_up = to->nextField(RIGHT_UP);
        Field *right_down = to->nextField(RIGHT_DOWN);

        return twoSides(right_up, RIGHT_UP, right_down, RIGHT_DOWN, move, piece);
    }
    return false;
}

bool Game::bishopCheckRow(Move *move, const string &piece){
    Field *to = move->getTo();

    if (move->getRow() < to->getRow()){ // up
        Field *left_up = to->nextField(LEFT_UP);
        Field *right_up = to->nextField(RIGHT_UP);

        return twoSides(left_up, LEFT_UP, right_up, RIGHT_UP, move, piece);

    }else if (move->getRow() > to->getRow()){ // down
        Field *left_down = to->nextField(LEFT_DOWN);
        Field *right_down = to->nextField(RIGHT_DOWN);

        return twoSides(left_down, LEFT_DOWN, right_down, RIGHT_DOWN, move, piece);
    }
    return false;
}


bool Game::rookCheck(Move *move){
    Field *to  = move->getTo();
    if (rookCheckAll(move,to , "Rook")){
        return true;
    }
    if ((move->isTake() && to->getPiece() != nullptr) || (!move->isTake() && to->getPiece() == nullptr)){
        if (move->getColumn() == -1 && move->getRow() == -1){


        }else if (move->getColumn() != -1){
            if(rookCheckCol(move, "Rook")){
                return true;
            }

        }else if (move->getRow() != -1){
            if(rookCheckRow(move, "Rook")){
                return true;
            }

        }
    }
    printf("WRONG MOVE !!!\n"); // TODO POPUP
    return false;
}


bool Game::rookCheckAll(Move *move, Field *to, const string &piece){
    Field *up = to->nextField(UP);
    Field *down = to->nextField(DOWN);
    Field *left = to->nextField(LEFT);
    Field *right = to->nextField(RIGHT);

    if (twoSides(up, UP, down, DOWN, move, piece)){
        return true;
    }

    if (twoSides(left, LEFT, right, RIGHT, move, piece)){
        return true;
    }
    return false;
}

bool Game::rookCheckRow(Move *move , const string &piece){
    Field *to = move->getTo();
    if (move->getRow() == to->getRow()){
        Field *left = to->nextField(LEFT);
        Field *right = to->nextField(RIGHT);

        return twoSides(left, LEFT, right, RIGHT, move, piece);

    }else if (move->getRow() < to->getRow()){
        Field *up = to->nextField(UP);

        return oneSide(up, UP, move, piece);

    }else if (move->getRow() > to->getRow()){
        Field *down = to->nextField(DOWN);

        return oneSide(down, DOWN, move, piece);
    }
    return false;
}


bool Game::oneSide(Field *f1, direction dir1, Move *move, const string &piece){
    while (f1 != nullptr){
        if(piece == "Queen") {
            if (f1->getPiece() != nullptr && isQueen(f1->getPiece())){
                pieceCheckMove(f1, move);
                return true;
            }
        }else if (piece == "Rook") {
            if (f1->getPiece() != nullptr && isRook(f1->getPiece())){
                pieceCheckMove(f1, move);
                return true;
            }
        }else if (piece == "Bishop") {
            if (f1->getPiece() != nullptr && isBishop(f1->getPiece())){
                pieceCheckMove(f1, move);
                return true;
            }
        }
        f1 = f1->nextField(dir1);
    }
    return false;
}


bool Game::twoSides(Field *f1, direction dir1, Field *f2, direction dir2, Move *move, const string &piece){
    while (f1 != nullptr || f2 != nullptr){
        if (f1 != nullptr){
            if(piece == "Queen") {
                if (f1->getPiece() != nullptr && isQueen(f1->getPiece())){
                    pieceCheckMove(f1, move);
                    return true;
                }
            }else if (piece == "Rook") {
                if (f1->getPiece() != nullptr && isRook(f1->getPiece())){
                    pieceCheckMove(f1, move);
                    return true;
                }
            }else if (piece == "Bishop") {
                if (f1->getPiece() != nullptr && isBishop(f1->getPiece())){
                    pieceCheckMove(f1, move);
                    return true;
                }
            }
            f1 = f1->nextField(dir1);
        }
        if (f2 != nullptr){
            if(piece == "Queen") {
                if (f2->getPiece() != nullptr && isQueen(f2->getPiece())){
                    pieceCheckMove(f2, move);
                    return true;
                }
            }else if (piece == "Rook") {
                if (f2->getPiece() != nullptr && isRook(f2->getPiece())){
                    pieceCheckMove(f2, move);
                    return true;
                }
            }else if (piece == "Bishop") {
                if (f2->getPiece() != nullptr && isBishop(f2->getPiece())){
                    pieceCheckMove(f2, move);
                    return true;
                }
            }
            f2 = f2->nextField(dir2);
        }
    }
    return false;
}


bool Game::rookCheckCol(Move *move, const string &piece){
    Field *to = move->getTo();
    if (move->getColumn() == to->getCol()){
        Field *up = to->nextField(UP);
        Field *down = to->nextField(DOWN);

        return twoSides(up, UP, down, DOWN, move, piece);
    }else if (move->getColumn() < to->getCol()){
        Field *left = to->nextField(LEFT);

        return oneSide(left, LEFT, move, piece);
    }else if (move->getColumn() > to->getCol()){
        Field *right = to->nextField(RIGHT);

        return oneSide(right, RIGHT, move, piece);
    }
    return false;
}

void Game::knightCheck(Move *one_move){
    Field *to = one_move->getTo();
    if ((one_move->isTake() && to->getPiece() != nullptr) || (!one_move->isTake() && to->getPiece() == nullptr)){
        if (one_move->getColumn() == -1 && one_move->getRow() == -1){
            knightCheckAllmoves(one_move, to);
        }else if (one_move->getColumn() != -1){
            knightCheckColumn(one_move, to);
        }else if (one_move->getRow() != -1){
            knightCheckRow(one_move, to);
        }
    }else {
        printf("WRONG MOVE !!!\n"); // TODO POPUP
    }
}

void Game::knightCheckRow(Move *move, Field *to){
    if (move->getRow() != to->getRow()){
        if (move->getRow() < to->getRow()){ //from (UP) to (DOWN)
            knightCheckRowN(to, move, UP);
        }else if (move->getRow() > to->getRow()){ // from (DOWN) to (UP)
            knightCheckRowN(to, move, DOWN);
        }
    }else {
        printf("WRONG MOVE !!!\n"); // TODO POPUP
    }
}

void Game::knightCheckRowN(Field *to, Move *move, direction dir){
    Field *from;
    int adder = dir == UP ? -1 : +1;
    int adder2 = dir == UP ? -2 : +2;

    if ((to->getRow() + adder) == move->getRow()){
        from = to->nextField(dir);
        if (from->nextField(LEFT) != nullptr) {
            from = from->nextField(LEFT);
            if ((from = from->nextField(LEFT)) != nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())) {
                pieceCheckMove(from, move);
                return;
            }
        }
        from = to->nextField(dir);
        if (from->nextField(RIGHT) != nullptr ){
            from = from->nextField(RIGHT);
            if ((from = from->nextField(RIGHT)) != nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
    }else if ((to->getRow() + adder2) == move->getRow()){
        from = to->nextField(dir)->nextField(dir);
        if (from->nextField(LEFT) != nullptr) {
            from = from->nextField(LEFT);
            if (from->getPiece() != nullptr && isKnight(from->getPiece())) {
                pieceCheckMove(from, move);
                return;
            }
        }
        from = to->nextField(dir)->nextField(dir);
        if (from->nextField(RIGHT) != nullptr){
            from = from->nextField(RIGHT);
            if (from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
    }
    printf("WRONG MOVE !!!\n"); // TODO POPUP
}


void Game::knightCheckColumn(Move *move, Field *to){
    if (move->getColumn() != to->getCol()){
        if (move->getColumn() < to->getCol()){ //from (levo) to (pravo)
            knightCheckColumnN(to, move, LEFT);
        }else if (move->getColumn() > to->getCol()){ // from (pravo) to (levo)
            knightCheckColumnN(to, move, RIGHT);
        }
    }else {
        printf("WRONG MOVE !!!\n"); // TODO POPUP
    }
}

void Game::knightCheckColumnN(Field *to, Move *move, direction dir){
    Field *from;
    int adder = dir == LEFT ? -1 : +1;
    int adder2 = dir == LEFT ? -2 : +2;

    if ((to->getCol() + adder) == move->getColumn()){
        from = to->nextField(dir);
        if (from->nextField(UP) != nullptr){
            from = from->nextField(UP);
            if ((from = from->nextField(UP)) != nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
        from = to->nextField(dir);
        if (from->nextField(DOWN) != nullptr){
            from = from->nextField(DOWN);
            if ((from = from->nextField(DOWN)) != nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
    }else if ((to->getCol() + adder2) == move->getColumn()){
        from = to->nextField(dir)->nextField(dir);
        if (from->nextField(UP) != nullptr){
            from = from->nextField(UP);
            if (from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
        from = to->nextField(dir)->nextField(dir);
        if (from->nextField(DOWN) != nullptr){
            from = from->nextField(DOWN);
            if (from->getPiece() != nullptr && isKnight(from->getPiece())){
                pieceCheckMove(from, move);
                return;
            }
        }
    }
    printf("WRONG MOVE !!!\n"); // TODO POPUP
}


void Game::knightCheckAllmoves(Move *one_move, Field *to){
    Field *from;
    Field *tmp;

    if((tmp = to->nextField(UP))!= nullptr){
        if((from = tmp->nextField(LEFT_UP))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
        }else if ((from = tmp->nextField(RIGHT_UP))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }
    }

    if((tmp = to->nextField(LEFT))!= nullptr){
        if((from = tmp->nextField(LEFT_UP))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }else if ((from = tmp->nextField(LEFT_DOWN))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }
    }

    if((tmp = to->nextField(DOWN))!= nullptr){
        if((from = tmp->nextField(RIGHT_DOWN))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }else if ((from = tmp->nextField(LEFT_DOWN))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }
    }

    if((tmp = to->nextField(RIGHT))!= nullptr){
        if((from = tmp->nextField(RIGHT_DOWN))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }else if ((from = tmp->nextField(RIGHT_UP))!= nullptr && from->getPiece() != nullptr && isKnight(from->getPiece())){
            pieceCheckMove(from,one_move);
            return;
        }
    }

    printf("WRONG MOVE !!!\n");
}


void Game::pieceCheckMove(Field *from, Move *one_move){
    one_move->setFrom(from);
    move(one_move->getFrom(), one_move->getTo());
    this->index++;
}

void Game::kingCheck(Move *one_move){
    Field *to = one_move->getTo();
    for (int pointer = 0 ; pointer < 8; pointer++) { // FOR EACH ENUM
        auto dir = direction(pointer); // TODO HOPE IT WORKS
        Field *tmp = to->nextField(dir);
        if (tmp != nullptr && tmp->getPiece() != nullptr && isKing(tmp->getPiece()) && tmp->getPiece()->getColor() == one_move->getColor()){
            one_move->setFrom(tmp);
            move(one_move->getFrom(), one_move->getTo());
            this->index++;
            break;
        }
    }
    if (one_move->getFrom() == nullptr){
        printf("WRONG MOVE !!!\n"); // TODO POPUP
    }
}

void Game::pawnCheck(direction dir, Move *one_move){
    Field *to = one_move->getTo();
    Field *tmp = to->nextField(dir);

    if (tmp != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece())){
        pieceCheckMove(tmp, one_move);
    }else if ((tmp = tmp->nextField(dir)) != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece()) && ((Pawn*)tmp->getPiece())->getIsOnStart()){
        pieceCheckMove(tmp, one_move);
    }else {
        printf("WRONG MOVE !!!\n");
    }
}

void Game::pawnCheckTake(direction dir1, direction dir2, Move *one_move){ // LEFT RIGHT
    Field *to = one_move->getTo();
    Field *tmp;
    if (one_move->getColumn() == -1){
        if ((tmp = to->nextField(dir1)) != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece())){
            pieceCheckMove(tmp, one_move);
        }else if ((tmp = to->nextField(dir2)) != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece())){
            pieceCheckMove(tmp, one_move);
        }else {
            printf("WRONG MOVE !!!\n"); // TODO POPUP
        }
    }else {
        if (one_move->getColumn() < one_move->getTo()->getCol()){
            if ((tmp = to->nextField(dir1)) != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece())){
                pieceCheckMove(tmp, one_move);
            }else{
                printf("WRONG MOVE !!!\n"); // TODO POPUP
            }
        }else if (one_move->getColumn() > one_move->getTo()->getCol()){
            if ((tmp = to->nextField(dir2)) != nullptr && tmp->getPiece() != nullptr && isPawn(tmp->getPiece())){
                pieceCheckMove(tmp, one_move);
            }else{
                printf("WRONG MOVE !!!\n"); // TODO POPUP
            }
        }
    }
}

void Game::move(Field *from, Field *to){
    if (!isAuto_mode()){
        delFromIndex();

        Move *move = createMove(from, to);

        if (this->loaded_moves.size() % 2 == 0){
            move->setColor(WHITE);
        }else {
            move->setColor(BLACK);
        }

        this->loaded_moves.push_back(move);

    }
    item = this->board->movePiece(from, to);
    if (item != nullptr){
        this->history->add(item);
    }
}

void Game::delFromIndex(){
    this->loaded_moves.erase(loaded_moves.begin() + this->index, loaded_moves.end());
}

Move* Game::createMove(Field *from, Field *to){
    Move *new_move = new Move();
    int from_x = from->getCol();
    int from_y =  from->getRow();
    new_move->setFrom(new Field(from_x, from_y));

    int to_x = to->getCol();
    int to_y = to->getRow();
    new_move->setTo(new Field(to_x, to_y));

    if (to->getPiece() != nullptr){
        new_move->setTake();
    }

    if ((isPawn(from->getPiece()) && from->getPiece()->getColor() == WHITE && to->getRow() == 0)||(isPawn(from->getPiece()) && from->getPiece()->getColor() == BLACK && to->getRow() == 7)){
        // TODO WHAT TO CHANGE TO POPUP
        new_move->setExchange('K'); // choose what to change to
    }
    if (isKing(from->getPiece())){
        new_move->setKing();
    }else if (isQueen(from->getPiece())){
        new_move->setQueen();
    }else if (isBishop(from->getPiece())){
        new_move->setBishop();
    }else if (isKnight(from->getPiece())){
        new_move->setKnight();
    }else if (isRook(from->getPiece())){
        new_move->setRook();
    }

    //TODO CHACK AND MAT

    return new_move;
}


int Game::points(color_piece color){
    if (color == BLACK){
        return this->board->getBlack_points();
    }else{
        return this->board->getWhite_points();
    }
}

void Game::undo(){
    HistoryItem *item = history->undo();
    if (item != nullptr){
        Field *from = item->getFrom();
        Field *to = item->getTo();
        Piece *target = item->getTarget_to();
        Piece *exchange = item->getExchange();

        board->moveHistory(from, to, target, exchange);
    }
}

void Game::redo(){
    HistoryItem *item = history->redo();
    if (item != nullptr){
        Field *from = item->getFrom();
        Field *to = item->getTo();
        Piece *exchange = item->getExchange();

        board->moveHistory(to, from, nullptr, exchange);
    }
}


void Game::loadAllMoves(const string &all_moves){
    if (!all_moves.empty()){
        vector<string> rotation_format = split(all_moves,'\n');
        for (int i = 0; i < rotation_format.size() ; i++){
            vector<string> splited = split(rotation_format[i], '.');

            if (i+1 != stoi(trim(splited[0]))){
                cout << splited[0] << endl;
                // TODO WINDOW POPUP
                break;
            }else {
                vector<string> arr_cord = split(trim(splited[1]),' ');
                int move_length = (int)arr_cord.size();
                if (move_length > 2 || move_length < 1){
                    printf("INVALID NUMBER OF MOVES\n");
                    break;
                }else {
                    string white = arr_cord[0];

                    if (validFormat(white)) {
                        Move *w_move = formatMove(white);
                        w_move->setColor(WHITE);
                        this->loaded_moves.push_back(w_move);
                        if (move_length > 1 ){
                            string black = arr_cord[1];

                            if (validFormat(black)){
                                Move *b_move = formatMove(black);
                                b_move->setColor(this->loaded_moves.size() % 2 == 0 ? WHITE : BLACK);
                                this->loaded_moves.push_back(b_move);
                            }else {
                                printf("FORMAT NOT VALID\n");
                                break;
                            }
                        }
                    }else{
                        printf("FORMAT NOT VALID\n");
                        break;
                    }
                }
            }
        }
    }else {
        this->auto_mode = false;
    }
}

void Game::printAllMoves(){
    int counter = 1;
    int arr_size = (int)this->loaded_moves.size();
    for (int idx = 0; idx < arr_size ; idx++){

        bool even = idx % 2 == 0;
        string move = this->loaded_moves[idx]->pritnMove();
        if (even){
            cout << to_string(counter) + ". " + move + " ("+ to_string(idx) + ") ";
            if (idx+1 == arr_size){
                cout << endl;
            }
        }else {
            cout << move + " (" + to_string(idx) + ") \n";
            counter++;
        }
    }
}

Move* Game::formatMove(string coordinates){
    Move *move = new Move();
    int counter = 0;
    char sign = coordinates[counter++];
    switch (sign){
        case 'K':
            move->setKing();
            sign = coordinates[counter++];
            return isBodyMove(coordinates, sign, counter, move);
        case 'D':
            move->setQueen();
            sign = coordinates[counter++];
            return isBodyMove(coordinates, sign, counter, move);
        case 'V':
            move->setRook();
            sign = coordinates[counter++];
            return isBodyMove(coordinates, sign, counter, move);
        case 'S':
            move->setBishop();
            sign = coordinates[counter++];
            return isBodyMove(coordinates, sign, counter, move);
        case 'J':
            move->setKnight();
            sign = coordinates[counter++];
            return isBodyMove(coordinates, sign, counter, move);
        default:
            move->setPawn();
            return isBodyMove(coordinates, sign, counter, move);
    }
}

Move* Game::isBodyMove(string coordinates, char sign, int counter, Move *move){
    if (isValidSign(sign)){ // is a,b,c,d,e,f,g,h (FIRST CHAR)
        move->setColumn(sign);
        sign = coordinates[counter++];
        if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8
            move->setRow(sign);

            if (coordinates.size() <= counter){
                move->setTo(this->board->getField(move->getColumn(), move->getRow()));
                move->setColumn(-1);
                move->setRow(-1);

                return move;
            }

            sign = coordinates[counter++];
            if (sign == 'x'){
                move->setFrom(this->board->getField(move->getColumn(), move->getRow()));
                move->setColumn(-1);
                move->setRow(-1);

                move->setTake();
                sign = coordinates[counter++];
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }else if (isValidSign(sign)){
                move->setFrom(this->board->getField(move->getColumn(), move->getRow()));
                return isValidFromTakeToEndMove(coordinates, sign, counter, move);
            }else {
                move->setTo(this->board->getField(move->getColumn(), move->getRow()));
                move->setColumn(-1);
                move->setRow(-1);
                return endSwitchFormatMove(coordinates, counter, sign, move);
            }
        }else if (sign == 'x'){
            move->setTake();
            sign = coordinates[counter++];
            return isValidFromTakeToEndMove(coordinates, sign, counter, move);
        }else if (isValidSign(sign)){
            return isValidFromTakeToEndMove(coordinates, sign, counter, move);
        }
    }else if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8 (FIRST CHAR) simplified version DONE
        move->setRow(sign);
        sign = coordinates[counter++];
        if(isValidSign(sign)){ // is a,b,c,d,e,f,g,h (SECOND CHAR)
            return isValidFromTakeToEndMove(coordinates, sign, counter, move);
        }else if (sign == 'x'){ // is x (SECOND CHAR)
            move->setTake();
            sign = coordinates[counter++];
            return isValidFromTakeToEndMove(coordinates, sign, counter, move);
        }
    }else if (sign == 'x'){
        move->setTake();
        sign = coordinates[counter++];
        return isValidFromTakeToEndMove(coordinates, sign, counter, move);
    }
    return move;
}


Move* Game::isValidFromTakeToEndMove(string coordinates, char sign, int counter, Move *move){
    int col = setColumnI(sign);
    sign = coordinates[counter++];
    int row = setRowI(sign);
    move->setTo(this->board->getField(col,row));
    if (coordinates.size() > counter){
        sign = coordinates[counter++];
        return endSwitchFormatMove(coordinates, counter, sign, move);
    }else {
        return move;
    }
}

Move* Game::endSwitchFormatMove(string coordinates, int counter, char sign, Move *move){
    switch (sign){
        case 'D':
        case 'V':
        case 'S':
        case 'J':
            move->setExchange(sign);
            if (coordinates.size() > counter){
                sign = coordinates[counter++];
                if (sign == '#' || sign == '+'){
                    move->setMat();
                }else if (sign == '+'){
                    move->setCheck();
                }
                return move;
            }else {
                return move;
            }
        case '#':
            move->setMat();
            return move;
        case '+':
            move->setCheck();
            return move;
    }
    return move;
}

bool Game::validFormat(string coordinates){
    if (coordinates.size() < 2){
        printf("INVALID LENGTH OF COORDINATES\n");
    }else {
        int counter = 0;
        char sign = coordinates[counter++];
        switch (sign){
            case 'K':
            case 'D':
            case 'V':
            case 'S':
            case 'J':
                sign = coordinates[counter++];
                return isBody(coordinates, sign, counter);
            default:
                this->is_pawn = true;
                return isBody(coordinates, sign, counter);
        }
    }
    return false;
}

bool Game::isValidSign(char Character){
    // is a,b,c,d,e,f,g,h
    return ((int) Character) > 96 && ((int) Character) < 105;
}

bool Game::isValidNumber(char Character){
    // is 1,2,3,4,5,6,7,8
    return ((int) Character) > 48 && ((int) Character) < 57;
}

bool Game::isValidFromTakeToEnd(string coordinates, char sign, int counter){
    if (!isValidSign(sign)){ // is a,b,c,d,e,f,g,h
        string s;
        s += sign;
        cout << s + " IS NOT OK" << endl;
        return false;
    }else {
        if (coordinates.size() < counter){
            return false;
        }
        sign = coordinates[counter++];
        if (!isValidNumber(sign)){

            string s;
            s += sign;
            cout << s + " IS NOT OK" << endl;
            return false;
        }else {
            if (coordinates.size() > counter){
                sign = coordinates[counter++];
                return endSwitchFormat(coordinates, sign, counter);
            }else {
                return true;
            }
        }
    }
}


bool Game::endSwitchFormat(string coordinates, char sign, int counter){
    switch (sign){
        case 'D':
        case 'V':
        case 'S':
        case 'J':
            if (!this->is_pawn){
                printf("ONLY PAWN CAN EXCHANGE\n");
                return false;
            }
            if (coordinates.size() > counter){
                sign = coordinates[counter++];
                if (sign == '#' || sign == '+'){
                    if (coordinates.size() > counter){
                        sign = coordinates[counter++];
                        string s;
                        s += sign;
                        cout << s + " IS NOT OK";
                        return false;
                    }else {
                        return true;
                    }
                }
                string s;
                s += sign;
                cout << s + " IS NOT OK";
                return false;
            }else {
                return true;
            }
        case '#':
        case '+':
            if (coordinates.size() > counter){
                sign = coordinates[counter++];
                string s;
                s += sign;
                cout << s + " IS NOT OK";
                return false;
            }
            return true;
        default:
            string s;
            s += sign;
            cout << s + " IS NOT OK";
            return false;
    }
}


bool Game::isBody(string coordinates, char sign, int counter){
    if (isValidSign(sign)){ // is a,b,c,d,e,f,g,h (FIRST CHAR)
        if (coordinates.size() <= counter){
            return false;
        }
        sign = coordinates[counter++];
        if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8
            if (coordinates.size() <= counter){
                return true;
            }
            sign = coordinates[counter++];
            if (sign == 'x'){
                if (coordinates.size() <= counter){
                    return false;
                }
                sign = coordinates[counter++];
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else if (isValidSign(sign)){
                return isValidFromTakeToEnd(coordinates, sign, counter);
            }else {
                return endSwitchFormat(coordinates, sign, counter);

            }
        }else if (sign == 'x'){
            if (coordinates.size() <= counter){
                return false;
            }
            sign = coordinates[counter++];
            return isValidFromTakeToEnd(coordinates, sign, counter);
        }else if (isValidSign(sign)){
            return isValidFromTakeToEnd(coordinates, sign, counter);
        }else {
            return false;
        }
    }else if (isValidNumber(sign)){ // is 1,2,3,4,5,6,7,8 (FIRST CHAR) simplified version DONE
        sign = coordinates[counter++];
        if(isValidSign(sign)){ // is a,b,c,d,e,f,g,h (SECOND CHAR)
            return isValidFromTakeToEnd(coordinates, sign, counter);
        }else if (sign == 'x'){ // is x (SECOND CHAR)
            if (coordinates.size() <= counter){
                return false;
            }
            sign = coordinates[counter++];
            return isValidFromTakeToEnd(coordinates, sign, counter);
        }else {
            return false;
        }
    }else if (sign == 'x'){
        if (coordinates.size() <= counter){
            return false;
        }
        sign = coordinates[counter++];
        return isValidFromTakeToEnd(coordinates, sign, counter);
    }else {
        return false;
    }
}

int Game::setColumnI(char sign){
    return ((int)sign - 97);
}

int Game::setRowI(char sign){
    return 8 - ((int)sign - 48);
}