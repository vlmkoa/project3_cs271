#include <iostream>
#include <element.h>


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
        insert (T d, int k);
        remove (int k);
        member (T d, int k);

    
};

 #endif 