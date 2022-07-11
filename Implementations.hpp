
#include "Declarations.h"

template<typename T>
Vector<T>::Vector():size(0),capacity(5),array(new T[capacity]){
    cout<<endl;
    ++vectors_counter;
    cout<<"Constructor called for type "<<typeid(*this).name()<<vectors_counter<<endl;
}
template<typename T>
Vector<T>::Vector(const Vector &other):size(other.size),capacity(other.capacity + 5),array(new T[other.capacity]) {

    for (int i = 0; i < other.size; ++i) {
        array[i] = other.array[i];
    }
    cout<<endl;
    ++vectors_counter;
    cout<<"Copy constructor called for type "<<typeid(*this).name()<<vectors_counter<<endl;

}
template<typename T>
Vector<T>::Vector(int number_of_elements, T value):size(number_of_elements),capacity(number_of_elements + 5),array(new T[capacity]) {
    for (int i = 0; i < size; ++i) {
        array[i] = value;
    }
    cout<<endl;
    ++vectors_counter;
    cout<<"Constructor with parameters called for type "<<typeid(*this).name()<<vectors_counter<<endl;
}
template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& arguments_list):size(0),capacity(arguments_list.size() + 5),array(new T[capacity]) {
    for (int el: arguments_list) {
        push_back(el);
    }
    cout<<endl;
    ++vectors_counter;
    cout<<"Initializer_list Constructor called for type "<<typeid(*this).name()<<vectors_counter<<endl;
}
//==========================================================================
template<typename T>
void Vector<T>::push_back(T value){
      if(size < capacity){
          array[size] = value;
          ++size;
      }else{
          capacity *= 2;
          cout<<endl;
          cout<<"Memory reallocation for type "<<typeid(*this).name()<<vectors_counter<<" on "<<capacity<<endl;
          T* new_array = new T[capacity];
          for (int i = 0; i < size; ++i) {
              new_array[i] = array[i];
          }
          new_array[size] = value;
          ++size;
          delete [] array;
          array = new_array;
      }
}
template<typename T>
bool Vector<T>::empty() const {
    return size == 0;
}
template<typename T>
int Vector<T>::get_size() const{
    return size;
}
template<typename T>
int Vector<T>::get_capacity() const{
    return capacity;
}
template<typename T>
int& Vector<T>::get_array() const {
    return array;
}
template<typename T>
void Vector<T>::pop_back() {
    std::string  message = typeid(*this).name() + std::to_string(vectors_counter) + " is empty";
    if(empty()){
        throw (message);
    }
    T* new_array = new T[size-1];
    for (int i = 0; i < size-1; ++i) {
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
    --size;
}
template<typename T>
T& Vector<T>::front() {
    return array[0];
}
template<typename T>
T& Vector<T>::back() {
    return array[size-1];
}
template<typename T>
void Vector<T>::insert(int index, T value) {
    if(index < 0 || index >= size){

        throw("out of range");

    }else if(size != capacity){

        if(size != capacity){
            for (int i = size-1; i >= index; --i) {
                array[i+1] = array[i];
            }
        }
        array[index] = value;
        ++size;

    }else{
        capacity*=2;
        T* new_array = new T[capacity];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        insert(index,value);
    }

}
template<typename T>
void Vector<T>::erase(int index) {

    if((index < 0) || (index >= size)){
        throw("out of range");
    }
    for (int i = index; i < size - 1 ; ++i) {
        array[i] = array[i+1];
    }
    --size;
}
template<typename T>
void Vector<T>::clear() {
    size = 0;
}

//==========================================================================
template<typename T>
bool Vector<T>::operator == (const Vector& other) const{

    if(size != other.size)return false;

    for (int i = 0; i < size; ++i) {
        if(array[i] != other.array[i]){
            return false;
        }
    }
    return true;
}
template<typename T>
bool Vector<T>::operator != (const Vector& other) const{

    return !(*this == other);
}
template<typename T>
Vector<T>& Vector<T>::operator = (const Vector& other){
    if(other.size > size){
        delete [] array;
        capacity = other.size + 5;
        array = new T[capacity];
    }
    for (int i = 0; i < other.get_size(); ++i) {
        array[i]= other.array[i];
    }
    size = other.size;

    return *this;
}
template<typename T>
T& Vector<T>::operator[](int index) const {
    return array[index];
}
template<typename T>
T& Vector<T>::at(int index) {
    std::string  message = typeid(*this).name() + std::to_string(vectors_counter) + "(invalid index)" + std::to_string(index);
    if(index >= size || index < 0)throw(message);
    return array[index];
}
template<typename T>
std::ostream& operator << (std::ostream& stream,const Vector<T>& obj){
    stream<<endl;
    stream<<"Vector"<<Vector<T>::vectors_counter<<" : ";
    for (int i = 0; i < obj.get_size(); ++i) {
        stream<<std::setw(5)<<obj[i];
    }
    stream<<" | capacity | ";
    for (int i = obj.get_size(); i < obj.get_capacity(); ++i) {
        stream<<std::setw(5)<<obj[i];
    }

    return stream;
}
//==========================================================================
template<typename T>
Vector<T>::~Vector(){
    delete[] array;
    cout<<endl;
    cout<<"Destructor called for type "<<typeid(*this).name()<<vectors_counter<<endl;
    --vectors_counter;

}


