#include "hash_table.h"

template <class T>
HashTable<T>::HashTable(int n){
        slots = new Element*[n];
}

template <class T>
void HashTable<T>::insert (T d, int k){
    Element<T> e(d, k);
    int hashk = h(k);
    if (slots[hashk] == nullptr) {
        slots[hashk] = e;
    } else {
        slots[hashk]->prev = e;
        e->next = slots[hashk];
        slots[hashk] = e;
    }

}

template <class T>
void HashTable<T>::remove (int k){

}

template <class T>
void HashTable<T>::member (T d, int k){

}