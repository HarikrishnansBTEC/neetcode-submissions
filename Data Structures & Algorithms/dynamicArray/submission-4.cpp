class DynamicArray {
public:

    int * arr;
    int size = 0;
    int capacity;
    DynamicArray(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        for(int i=0;i<capacity;i++)
        {
            arr[i] = 0;
        }
    }

    int get(int i) {
        return arr[i];

    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity)
        {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int result = arr[size-1];
        arr[size-1] = 0;
        size--;
        return result;
    }

   void resize() {
    int* newArr = new int[capacity * 2];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];   
    }

    for (int i = size; i < capacity * 2; i++) {
        newArr[i] = 0;
    }

    delete[] arr;             
    arr = newArr;
    capacity *= 2;
}

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
