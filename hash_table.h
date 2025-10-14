#include <iostream>
#include <element.h>


#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class T>
class HashTable{
    private:
        void h(int k);
        Element* slots;
    public:
        HashTable (int n);        

};
#endif