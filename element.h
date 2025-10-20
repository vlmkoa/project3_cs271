//=================================================
// Nate Hydukovich, Ava De La Cruz, Ryan Vo
// October 2025
// element.h
// This file defines the Element class template,
// which stores a single key–data pair used in the
// HashTable class. Each Element acts as a node in
// a doubly linked list for separate chaining.
//=================================================

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

//=================================================
// Class: Element
// The Element class represents a single node in a
// hash table bucket chain. Each node stores a data
// item (of any type T), a key, and pointers to the
// previous and next nodes in the chain.
//=================================================
template<typename T>
class Element {
private:
    T data;       // the stored data value
    long key;     // unique key for hashing and lookup

public:
    Element<T>* prev;   // pointer to previous node in the chain
    Element<T>* next;   // pointer to next node in the chain

    //=================================================
    // Element
    // Default constructor.
    // Initializes data to its default value, sets key
    // to -1, and pointers to nullptr.
    // Parameters:
    // None.
    // Return Value:
    // None.
    //=================================================
    Element()
        : data(), key(-1), prev(nullptr), next(nullptr) {}

    //=================================================
    // Element
    // Parameterized constructor.
    // Creates a new Element with specified data and key.
    // Parameters:
    // data_ : const T& — the value to store.
    // key_  : long — the unique key associated with the data.
    // Return Value:
    // None.
    //=================================================
    Element(const T& data_, long key_)
        : data(data_), key(key_), prev(nullptr), next(nullptr) {}

    //=================================================
    // get_key
    // Returns the key value associated with this element.
    // Parameters:
    // None.
    // Return Value:
    // long — the key used for hashing and lookup.
    //=================================================
    long get_key() const { return key; }

    //=================================================
    // get_data
    // Returns the data value stored in this element.
    // Parameters:
    // None.
    // Return Value:
    // T — the data stored in this node.
    //=================================================
    T get_data() const { return data; }
};

#endif
