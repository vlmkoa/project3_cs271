#include <iostream>
#include "element.h"


#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class T>
class HashTable{
    private:
        void h(int k);
        Element** slots;
        void search(int k);
    public:
        HashTable (int n);
        void insert (T d, int k);
        void remove (int k);
        void member (T d, int k);

    
};

 #endif 