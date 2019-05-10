//
// Created by janum on 24.04.2019.
//

#include "History.h"

using namespace std;

History::History(){
    this->pointer = 0;
}

void History::add(HistoryItem* item){
    int array_size = (int)this->array.size();
    if (this->pointer <= array_size){
        clear();
    }
    this->array.push_back(item);
    this->pointer++;
}

void History::clear(){
    this->array.erase(array.begin() + this->pointer, array.end());
}

HistoryItem* History::undo(){
    int array_size = (int)this->array.size();
    if (array_size >= 1){
        return this->array[--this->pointer];
    }
    return nullptr;
}

HistoryItem* History::redo(){
    int array_size = (int)this->array.size();
    if (this->pointer < array_size){
        return this->array[this->pointer++];
    }
    return nullptr;
}

