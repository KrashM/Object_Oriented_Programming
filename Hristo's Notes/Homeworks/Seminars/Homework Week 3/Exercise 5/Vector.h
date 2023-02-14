#ifndef VECTOR
#define VECTOR

class Vector{

    private:
        int SIZE, CAPACITY, *V;

        void reset();
        void resize();
        void sizeDown();
        void sizeUp();

    
    public:
        Vector();
        ~Vector();

        bool isEmpty();
        int getCapacity();
        int getSize();
        int getAt(int index);
        int getFirst();
        int getLast();
        void assign(int n, int x);
        void pushBack(int x);
        void popBack();
        void removeAt(int i);
        void insert(int i, int x);
        void erase(int x);
        char* toString();

};

#endif