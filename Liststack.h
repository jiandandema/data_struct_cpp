#ifndef __LISTSTACK__
#define __LISTSTACK__
#include <iostream>
#include "Node.h"


template <typename T>
class Liststack
{
private:
    SingleNode<T>* _top;
    int _count;
public:
    Liststack();
    ~Liststack();

    Liststack<T>& push(const T& value);

    Liststack<T>& pop();

    T get_top() const { return IsEmpty() ? sqrt(-1) : _top->_next->_value; }            //this is not the bast way, because sqrt(-1) may be not compatible with T

    bool IsEmpty() const { return _count == 0; }
    int size() const { return _count; }
    Liststack<T>& print();
};

template <typename T>
inline
Liststack<T>::Liststack()
    : _count(0)
{
    _top = new SingleNode<T>(0,0,NULL);
}

template <typename T>
inline
Liststack<T>::~Liststack()
{
    SingleNode<T>* p = _top->_next;
    SingleNode<T>* pre = _top;
    for(p; p != NULL; pre = p, p = p->_next){
        delete pre;
    }
    delete pre;
}

template <typename T>
inline
Liststack<T>& Liststack<T>::push(const T& value){
    SingleNode<T>* p = new SingleNode<T>(value,++_count,_top->_next);
    _top->_next = p;
    return *this;
}

template <typename T>
inline
Liststack<T>& Liststack<T>::pop(){
    if(this->IsEmpty()){
        std::cout << "Liststack is empty!NO MORE POP!" << std::endl;
        return *this;
    }
    SingleNode<T>* p = _top->_next;
    _top->_next = _top->_next->_next;
    delete p;
    _count--;
    return *this;
}

template <typename T>
inline
Liststack<T>& Liststack<T>::print(){
    if(this->IsEmpty()){
        std::cout << "Liststack is empty!" << std::endl;
        return *this;
    }
    SingleNode<T>* p = _top->_next;
    for(p; p != NULL; p = p->_next){
        std::cout << "num: " << p->_index << " data: " << p->_value << std::endl;
    }
    return *this;
}

#endif