#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

template<typename T>
class Element {
private:
    T data;
    long key;

public:
    Element<T>* prev;
    Element<T>* next;

    // constructors
    Element()
        : data(), key(-1), prev(nullptr), next(nullptr) {}
    Element(const T& data_, long key_)
        : data(data_), key(key_), prev(nullptr), next(nullptr) {}

    long get_key() const { return key; }
    T get_data() const { return data; }
};

#endif



