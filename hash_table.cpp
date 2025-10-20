#include "hash_table.h"
#include <sstream>
#include <string>
#include <cmath> 

using namespace std;

//=================================================
// Pre-condition: n must be >= 0.
// Post-condition: Creates a new hash table of size n and 
// initializes all slot pointers to nullptr. If n < 0, prints an error.
//=================================================
template <class T>
HashTable<T>::HashTable(int n){
    if (n < 0)  {
        cerr << "Size cannot be less than 0";
    }
    size = n;
    slots = new Element<T>*[n]();  // allocate and zero-initialize slots
}

//=================================================
// Pre-condition: Hash table may contain allocated elements.
// Post-condition: All elements and slot memory are properly 
// deallocated, leaving no memory leaks.
//=================================================
template <class T>
HashTable<T>::~HashTable(){
    clear();
    delete[] slots;
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Returns a valid index (0 <= index < size) for key k.
//=================================================
template <class T>
int HashTable<T>::h(size_t k){
    // Modular Method
    return k%size;

    // Most Significant Bits implementation
    // int p = log2(size);
    
    // // extract the p most significant bits
    // int width = floor(log2(k)) + 1; //the number of bits that the key value would occupy 
    // // a better method for width should specify desired width of all the input keys
    // size_t result = width > p ? (k >> (width - p)) : k; //if width is less than p, then result is just the number itself
    
    // return (int)result;

    // Cormen's Multiplication Method implementation
    // const double A = (sqrt(5) - 1) / 2;
    // double frac = fmod(k * A, 1.0);   // fractional part
    // return (int)(size * frac);
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Inserts a new element (d, k) into the table. 
// If a collision occurs, the new element is added to the front 
// of the linked list in that slot.
//=================================================
template <class T>
void HashTable<T>::insert (T d, long k){
    /*if (search(k) != nullptr) {
        cout<<"Key occupied, cannot insert";
        return;
    }  */
    Element<T>* e = new Element<T>(d,k);
    if (size != 0) {
        int hashk = h(k);
        if (slots[hashk] == nullptr) { // no collision
            slots[hashk] = e;
        } else { // collision -> insert at front of chain
            slots[hashk]->prev = e;
            e->next = slots[hashk];
            slots[hashk] = e;
        }
    } 
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Removes the element with key k if it exists.
// The linked list connections in that slot are updated correctly.
//=================================================
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
        } else { // middle of list
            elt->next->prev = elt->prev;
            elt->prev->next = elt->next;
            delete elt;
        }
    }
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Returns true if element (d, k) is found, 
// otherwise returns false.
//=================================================
template <class T>
bool HashTable<T>::member (T d, long k){
    Element<T>* elt = search(k);
    if ((elt != nullptr) && (elt->get_data() == d) && (elt->get_key() == k)) {
        return true;
    }
    return false;
}

//=================================================
// Pre-condition: None.
// Post-condition: Returns a string showing each slot index and 
// the key-value pairs stored in its chain.
//=================================================
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
                current = current->next; // move through list
            }  
        } 
        ss << "\n";
    }   
    return ss.str();
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Returns a pointer to the element with key k 
// if found, otherwise returns nullptr.
//=================================================
template <class T>
Element<T>* HashTable<T>::search(long k) {
    if (size != 0) {
        int hashk = h(k);
        Element<T>* curr = slots[hashk];
        while ((curr != nullptr) && (curr->get_key() != k)) {
            curr = curr->next;
        }
        
        if (curr != nullptr && curr->get_key() == k) {
            return curr; // found element
        }
    }
    return nullptr; // not found
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: Returns true if data exists in the slot 
// corresponding to key k, false otherwise.
//=================================================
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

//=================================================
// Pre-condition: size > 0.
// Post-condition: Inserts a new element (d, k) safely. 
// If the slot already contains data, element is added 
// to the front of the chain.
//=================================================
template <class T>
void HashTable<T>::securedInsert (T d, long k){
    Element<T>* e = new Element<T>(d,-1);
    if (size != 0) {
        int hashk = h(k);
        if (slots[hashk] == nullptr) { // empty slot
            slots[hashk] = e;
        } else { // insert at front
            slots[hashk]->prev = e;
            e->next = slots[hashk];
            slots[hashk] = e;
        }
    } 
}

//=================================================
// Pre-condition: size > 0.
// Post-condition: All elements in every slot are deleted,
// and all slot pointers are set to nullptr. Table becomes empty.
//=================================================
template <class T>
void HashTable<T>::clear() noexcept {
    for (int i = 0; i < size; i++) {
        Element<T>* cur = slots[i];
        while (cur) { // delete linked list for each slot
            Element<T>* t = cur;
            cur = cur->next;
            delete t;                
        }
        slots[i] = nullptr;
    }
}

template class HashTable<string>;
