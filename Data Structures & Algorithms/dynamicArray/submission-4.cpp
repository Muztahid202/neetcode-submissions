class DynamicArray {

private:
    int *array;
    int size;
    int capacity;
public:

    DynamicArray(int capacity) : capacity(capacity), size(0) {
        array = new int[capacity];
    }

    int get(int i) {
        return array[i];
    }

    void set(int i, int n) {
        array[i] = n;
    }

    void pushback(int n) {
        if(size == capacity)
            resize();
        array[size++] = n;
    }

    //remove the last element of the array
    int popback() {
        //size = 1 and pop
        if(size>0)
            size--;
        return array[size];
        
    }

    void resize() {
        capacity *= 2;
        int *newArray = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
