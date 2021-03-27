#ifndef __ARRAYQUEUE__
#define __ARRAYQUEUE__
#include <iostream>

template <typename T>
class Arrayqueue
{
private:
    T* _array;
    int _head;
    int _end;
    int _count;
    int _capacity;
public:
    Arrayqueue(const int& capacity = 10);
    ~Arrayqueue();

    Arrayqueue<T>& push(const T& value);
    Arrayqueue<T>& pop();

    int size() const { return _count; }
    T get_head() const{ return _array[_head]; }
    bool IsEmpty() const { return _count == 0; }
    bool IsFull() const { return _count == _capacity; }
    T* get_array() const { return _array; }                     //this method is used to test code!It should NOT appear in release version!
};

template <typename T>
inline
Arrayqueue<T>::Arrayqueue(const int& capacity)
    : _count(0), _head(0), _end(-1), _capacity(capacity)
{
    _array = new T[_capacity];
}

template <typename T>
inline
Arrayqueue<T>::~Arrayqueue()
{
    delete[] _array;
}

template <typename T>
inline
Arrayqueue<T>& Arrayqueue<T>::push(const T& value){
    if(this->IsFull()){
        std::cout << "Arrayqueue is full!NO MORE PUSH!" << std::endl;
        return *this;
    }
    _end = (_end + 1) % _capacity;
    _array[_end] = value;
    _count++;

    return *this;
}

template <typename T>
inline
Arrayqueue<T>& Arrayqueue<T>::pop(){
    if(this->IsEmpty()){
        std::cout << "Arrayqueue is empty!NO MORE POP!" << std::endl;
        return *this;
    }
    _array[_head] = 0;
    _head = (_head + 1) % _capacity;
    _count--;

    return *this;
}

#endif