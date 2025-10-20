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
        Element<T>** slots;
        Element<T>* search(long k);
        int h(long k);
    public:
        HashTable (int n);
        ~HashTable();
        void insert (T d, long k);
        void securedInsert (T d, long k);
        void remove (long k);
        bool member (T d, long k);
        string to_string () const;
        void clear() noexcept;
        bool isMemberInSlot(T data, long k);
};

 #endif 