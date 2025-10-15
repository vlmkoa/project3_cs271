#include <iostream>
#include "element.h"
#include <string>

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

using namespace std;
template <class T>
class HashTable{
    private:
        int size;
        int h(int k);
        Element<T>** slots;
        void search(int k);
    public:
        HashTable (int n);
        void insert (T d, int k);
        void remove (int k);
        void member (T d, int k);
        string to_string () const;
    
};

 #endif 