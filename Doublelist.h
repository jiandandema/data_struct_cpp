#ifndef __DOUBLELIST__
#define __DOUBLELIST__
#include <iostream>
#include "Node.h"

template <typename T>
class Doublelist
{
private:
    DoubleNode<T>* _head;
    int _count;
    DoubleNode<T>* getNode(const int& index);
public:
    Doublelist();
    ~Doublelist();

    typedef DoubleNode<T>* pointer;

    Doublelist<T>& insert(const int& index, const T& value);
    Doublelist<T>& insert_head(const T& value);
    Doublelist<T>& insert_last(const T& value);

    Doublelist<T>& del(const int& index);
    Doublelist<T>& del_head();
    Doublelist<T>& del_last();

    T get_value(const int& index) { return getNode(index) ? getNode(index)->_value:sqrt(-1); }          //this is not the bast way, because sqrt(-1) may be not compatible with T

    int size() const { std::cout << "size: " << _count << std::endl;; return _count; }
    DoubleNode<T>* get_head() { return _head->_next; }
    DoubleNode<T>* get_last() { return _head->_pre; };
    bool IsEmpty() const { return _count == 0; }
    Doublelist<T>& print();
};

template <typename T>
inline
Doublelist<T>::Doublelist()
    : _count(0)
{
    _head = new DoubleNode<T>(0,0,NULL,NULL);
    _head->_next = _head;
    _head->_pre = _head;
}

template <typename T>
inline
Doublelist<T>::~Doublelist()
{
    DoubleNode<T>* p = _head->_next;
    DoubleNode<T>* pre = _head;
    for(int i = 0; i < _count; ++i){
        delete pre;
        pre = p;
        p = p->_next;
    }
    delete pre;
}

template <typename T>
inline
DoubleNode<T>* Doublelist<T>::getNode(const int& index){
    if(index > _count){
        std::cout << "User input index: " << index << " is out-of-range!" << std::endl;
        return NULL;
    }
    DoubleNode<T>* p = _head;
    for(int i = 0; i < index; ++i){
        p = p->_next;
    }

    return p;
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::insert(const int& index, const T& value){
    DoubleNode<T>* p = getNode(index);
    if(p){
        DoubleNode<T>* temp = new DoubleNode<T>(value,index+1,p->_next,p);
        p->_next = temp;
        temp->_next->_pre = temp;
        for(int i = index; i < _count; ++i){
            temp = temp->_next;
            temp->_index++;
        }
        _count++;
    }
    return *this;
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::del(const int& index){
    if(this->IsEmpty()){
        std::cout << "Doublelist is empty!NO MORE DELETE!" << std::endl;
        return *this;
    }
    if(getNode(index)){
        DoubleNode<T>* p = getNode(index-1);
        DoubleNode<T>* temp = p->_next;
        p->_next = temp->_next;
        temp->_next->_pre = p;
        p = temp->_next;
        delete temp;
        for(int i = index; i < _count; ++i){
            p = p->_next;
            p->_index--;
        }
        _count--;
    }
    return *this;
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::print(){
    if(this->IsEmpty()){
        std::cout << "Doublelist is empty!" << std::endl;
    }
    DoubleNode<T>* p = _head->_next;
    for(int i = 0; i < _count; ++i){
        std::cout <<"num: " << p->_index << " data: " << p->_value << std::endl;
        p = p->_next;
    }

    return *this;
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::insert_head(const T& value){
    return insert(0,value);
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::insert_last(const T& value){
    return insert(_count,value);
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::del_head(){
    return del(1);
}

template <typename T>
inline
Doublelist<T>& Doublelist<T>::del_last(){
    return del(_count);
}

#endif