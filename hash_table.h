//=================================================
// Nate Hydukovich, Ava De La Cruz, Ryan Vo
// October 2025
// hash_table.h
// This file defines a generic hash table class template
// that stores key–value pairs using separate chaining.
// It supports inserting, removing, searching, and 
// checking membership of elements.
//=================================================

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include "element.h"
using namespace std;

//=================================================
// Class: HashTable
// The HashTable class implements a simple hash table
// using open chaining. Each bucket contains a linked
// list of Element<T> objects.
//=================================================
template <class T>
class HashTable {
private:
    int size;                 // number of buckets in the hash table
    Element<T>** slots;       // array of pointers to linked lists (buckets)

    //=================================================
    // search
    // This function looks up an element in the hash table 
    // using its key and returns a pointer to it if found.
    // Parameters:
    // k : long — the key to search for (must be >= 0)
    // Return Value:
    // Pointer to the Element<T> object if found, or nullptr otherwise.
    //=================================================
    Element<T>* search(long k);

public:
    //=================================================
    // HashTable
    // Constructor that creates a new hash table with n buckets.
    // Parameters:
    // n : int — number of buckets, should be > 0.
    //=================================================
    HashTable(int n);

    //=================================================
    // ~HashTable
    // Destructor that deallocates memory and clears all entries
    // in the hash table.
    //=================================================
    ~HashTable();

    //=================================================
    // insert
    // Inserts a new element into the hash table.
    // Parameters:
    // d : T — the data value to store.
    // k : long — the key associated with the data.
    // Return Value:
    // None. Adds the element into the correct chain based on hash.
    //=================================================
    void insert(T d, long k);

    //=================================================
    // securedInsert
    // Inserts a new element into the table only if it does not
    // already exist (prevents duplicates).
    // Parameters:
    // d : T — the data value to insert.
    // k : long — the key for hashing and lookup.
    // Return Value:
    // None. Prints an error or skips insertion if the key exists.
    //=================================================
    void securedInsert(T d, long k);

    //=================================================
    // remove
    // Removes the element with the specified key from the table.
    // Parameters:
    // k : long — key of the element to remove.
    // Return Value:
    // None. If the key does not exist, nothing is removed.
    //=================================================
    void remove(long k);

    //=================================================
    // member
    // Checks if an element with the given data and key exists.
    // Parameters:
    // d : T — data value to check.
    // k : long — key of the element.
    // Return Value:
    // true if the element is found, false otherwise.
    //=================================================
    bool member(T d, long k);

    //=================================================
    // to_string
    // Converts the entire hash table into a printable string form.
    // Parameters:
    // None.
    // Return Value:
    // string — showing all buckets and their contents.
    //=================================================
    string to_string() const;

    //=================================================
    // clear
    // Removes all elements from the table and frees memory.
    // Parameters:
    // None.
    // Return Value:
    // None. The table becomes empty.
    //=================================================
    void clear() noexcept;

    //=================================================
    // isMemberInSlot
    // Checks if the given element exists in the slot determined
    // by its hash index.
    // Parameters:
    // data : T — data value to look for.
    // k : long — key used to locate the correct slot.
    // Return Value:
    // true if found in that slot, false otherwise.
    //=================================================
    bool isMemberInSlot(T data, long k);

    //=================================================
    // h
    // Computes the hash index from a given key.
    // Parameters:
    // k : size_t — the key to hash.
    // Return Value:
    // int — the index between 0 and (size - 1).
    //=================================================
    int h(size_t k);
};

#endif
