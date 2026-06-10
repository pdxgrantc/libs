#ifndef OBJ_H
#define OBJ_H

class Obj {
    public:
        int data1;
        int data2;

        Obj();
        Obj(int dataIn1, int dataIn2);
        ~Obj();
        void print_obj();
};

#include "obj.tpp"

#endif