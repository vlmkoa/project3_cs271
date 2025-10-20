#include "hash_table.h"
#include <sstream>
#include <string>

using namespace std;

template <class T>
HashTable<T>::HashTable(int n){
    size = n;
    slots = new Element<T>*[n]();
}

template <class T>
HashTable<T>::~HashTable(){
    clear();
    delete[] slots;
}

template <class T>
int HashTable<T>::h(long k){
    return k%size;
}

template <class T>
void HashTable<T>::insert (T d, long k){
    if (search(k) != nullptr){
        cout<<"Key occupied, cannot insert";
        return;
    } 
    Element<T>* e = new Element<T>(d,k);
    if (size != 0) {
        int hashk = h(k);
        if (slots[hashk] == nullptr) {
            slots[hashk] = e;
        } else {
            slots[hashk]->prev = e;
            e->next = slots[hashk];
            slots[hashk] = e;
        }
        
    } 
}

template <class T>
void HashTable<T>::remove (long k){
    Element<T>* elt = search(k);
    if (elt != nullptr) {
        int hashk = h(k);
        if (elt->prev == nullptr && elt->next == nullptr) { // if only elt in list
            delete elt;
            slots[hashk] = nullptr;
        } else if (elt->prev == nullptr) { // if first elt in list
            elt->next->prev = nullptr;
            slots[hashk] = elt->next;
            delete elt;
        } else if (elt->next == nullptr) { // if last elt in list
            elt->prev->next = nullptr;
            delete elt;
        } else {
            elt->next->prev = elt->prev;
            elt->prev->next = elt->next;
            delete elt;
        }
    }
}

template <class T>
bool HashTable<T>::member (T d, long k){
    Element<T>* elt = search(k);
    if ((elt != nullptr) && (elt->get_data() == d) && (elt->get_key() == k)) {
        return true;
    }

    return false;
}

template <class T>
string HashTable<T>::to_string() const{
    stringstream ss;
    for (int i = 0; i < size; i++){
        
        ss << i ;
        ss<< ": ";
        if(slots[i] != nullptr){
            Element<T>* current = slots[i];
            while (current != nullptr)
            {
                T data = current->get_data();
                long key = current->get_key();
                ss << "(";
                ss << data;
                ss << ",";
                ss << key;
                ss << ")";
                ss << " ";
                current = current->next;
            }  
        } 
        ss << "\n";
        
        
    }   
    return ss.str();
}

template <class T>
Element<T>* HashTable<T>::search(long k) {
    if (size != 0) {
        int hashk = h(k);
        Element<T>* curr = slots[hashk];
        while ((curr != nullptr) && (curr->get_key() != k)) {
            curr = curr->next;
        }
        
        if (curr != nullptr && curr->get_key() == k) {
            return curr;
        }
    }
    return nullptr;
}

template <class T>
bool HashTable<T>::isMemberInSlot(T data, long k) {
    if (size != 0) {
        int hashk = h(k);
        Element<T>* curr = slots[hashk];
        while ((curr != nullptr) && (curr->get_data() != data)) {
            curr = curr->next;
        }
        
        if (curr != nullptr && curr->get_data() == data) {
            return true;
        }
    }
    return false;
}

template <class T>
void HashTable<T>::securedInsert (T d, long k){
    Element<T>* e = new Element<T>(d,-1);
    if (size != 0) {
        int hashk = h(k);
        if (slots[hashk] == nullptr) {
            slots[hashk] = e;
        } else {
            slots[hashk]->prev = e;
            e->next = slots[hashk];
            slots[hashk] = e;
        }
        
    } 
}

template <class T>
void HashTable<T>::clear() noexcept {
    for (int i = 0; i < size; i++) {
        Element<T>* cur = slots[i];
        while (cur) {
            Element<T>* t = cur;
            cur = cur->next;
            delete t;                
        }
        slots[i] = nullptr;
    }
}

template class HashTable<string>;