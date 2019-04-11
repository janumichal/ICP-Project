package Chess_common;

import java.util.ArrayList;
import java.util.List;

public class History {
    private List<HistoryItem> array;
    private int pointer;

    public History() {
        this.array = new ArrayList<>();
        this.pointer = 0;
    }

    public void add(HistoryItem item){
        int array_size = this.array.size();
        if (this.pointer <= array_size){
            clear();
        }
        this.array.add(item);
        this.pointer++;
    }

    private void clear(){
        this.array.subList(this.pointer, this.array.size()).clear();
    }

    public HistoryItem undo(){
        int array_size = this.array.size();
        if (!(array_size < 1)){
            return this.array.get(--this.pointer);
        }
        return null;
    }

    public HistoryItem redo(){
        int array_size = this.array.size();
        if (this.pointer < array_size){
            return this.array.get(this.pointer++);
        }
        return null;
    }
}
