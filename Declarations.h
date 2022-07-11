#ifndef V_DECLARATIONS_H
#define V_DECLARATIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;

template<typename T>
class Vector{

public:
    static int vectors_counter;
public:

    int size;
    int capacity;
    T *array;

public:
    //=================================
    explicit Vector();
    Vector(const Vector& other);
    explicit Vector(int number_of_elements,T value = 0);
    Vector(const std::initializer_list<T>& Args);

    //=================================
    void push_back  (T value);
    void pop_back   ();
    bool empty      () const;
    int get_size    () const;
    int get_capacity() const;
    int& get_array() const;
    T& front();
    T& back();
    void insert(int index,T value);
    void erase(int index);
    void clear();

    //=================================
    T& at(int index);
    bool operator ==(const Vector<T>& other) const;
    bool operator !=(const Vector<T>& other) const;
    Vector<T>& operator = (const Vector<T>& other);
    T& operator [](int index)const;

    //=================================

    ~Vector();
};
template<typename T>
std::ostream& operator <<(std::ostream& stream,const Vector<T>& obj);
template<typename T>
int Vector<T>::vectors_counter = 0;

#include "Implementations.hpp"
#endif //V_DECLARATIONS_H
