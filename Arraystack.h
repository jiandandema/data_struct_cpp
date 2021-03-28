#ifndef __ARRAYSTACK__
#define __ARRAYSTACK__
#include <iostream>
#include <cmath>

template <typename T>
class Arraystack
{
private:
    T* _array;
    int _top;
    int _capacity;
public:
    Arraystack(const int& capacity = 10);
    ~Arraystack();


    Arraystack<T>& push(const T& value);

    Arraystack<T>& pop();

    T get_top() const { return IsEmpty() ? sqrt(-1):_array[_top]; }

    bool IsEmpty() const { return _top == -1; }
    bool IsFull() const { return _top == _capacity-1; }
    int size() const { return _top+1; }
    T* get_array() { return _array; }                           //this method is used to test code!It should NOT appear in release version!
};

template <typename T>
inline
Arraystack<T>::Arraystack(const int& capacity)
    : _top(-1), _capacity(capacity)
{
    _array = new T[_capacity];
}

template <typename T>
inline
Arraystack<T>::~Arraystack()
{
    delete[] _array;
}

template <typename T>
inline
Arraystack<T>& Arraystack<T>::push(const T& value){
    if(this->IsFull()){
        std::cout << "Arraystack is full!NO MORE PUSH!" << std::endl;
        return *this;
    }
    _array[++_top] = value;
    return *this;
}

template <typename T>
inline
Arraystack<T>& Arraystack<T>::pop(){
    if(this->IsEmpty()){
        std::cout << "Arraystack is empty!NO MORE POP!" << std::endl;
        return *this;
    }
    _top--;
    return *this;
}



#endif