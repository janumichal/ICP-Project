//
// Created by janum on 23.04.2019.
//

#ifndef CPP_CHESS_HISTORY_H
#define CPP_CHESS_HISTORY_H

#include <vector>
#include "HistoryItem.h"

using namespace std;

class History{
private:
    vector<HistoryItem*> array;
    int pointer;

public:
    History(){
        this->pointer = 0;
    }

    void add(HistoryItem* item){
        int array_size = (int)this->array.size();
        if (this->pointer <= array_size){
            clear();
        }
        this->array.push_back(item);
        this->pointer++;
    }

private:
    void clear(){
        this->array.erase(array.begin() + this->pointer, array.end());
    }

public:
    HistoryItem* undo(){
        int array_size = (int)this->array.size();
        if (array_size >= 1){
            return this->array[--this->pointer];
        }
        return nullptr;
    }

    HistoryItem* redo(){
        int array_size = (int)this->array.size();
        if (this->pointer < array_size){
            return this->array[this->pointer++];
        }
        return nullptr;
    }

};



#endif //CPP_CHESS_HISTORY_H
