#ifndef __LISTQUEUE__
#define __LISTQUEUE__
#include <iostream>
#include "Node.h"

template <typename T>
class Listqueue
{
private:
    SingleNode<T>* _head;
    SingleNode<T>* _end;
    int _count;
public:
    Listqueue();
    ~Listqueue();

    typedef SingleNode<T>* pointer;

    Listqueue<T>& push(const T value);

    Listqueue<T>& pop();

    T get_head() const { return _head->_next->_value; }

    bool IsEmpty() const { return _count == 0; }
    int size() const { return _count; }
    SingleNode<T>* get_list() { return _head->_next; }
    Listqueue<T>& print();
};

template <typename T>
inline
Listqueue<T>::Listqueue()
    : _count(0)
{
    _head = new SingleNode<T>(0,0,NULL);
    _end = _head;
}

template <typename T>
inline
Listqueue<T>::~Listqueue()
{
    SingleNode<T>* p = _head->_next;
    SingleNode<T>* pre = _head;
    for(p; p != NULL; pre = p, p = p->_next){
        delete pre;
    }
    delete pre;
}

template <typename T>
inline
Listqueue<T>& Listqueue<T>::push(const T value){
    SingleNode<T>* p = new SingleNode<T>(value,++_count,NULL);
    _end->_next = p;
    _end = p;
    return *this;
}

template <typename T>
inline
Listqueue<T>& Listqueue<T>::pop(){
    if(this->IsEmpty()){
        std::cout << "Liststack is empty!NO MORE POP!" << std::endl;
        return *this;
    }
    SingleNode<T>* p = _head->_next;
    for(p; p != NULL; p = p->_next){
        p->_index--;
    }
    p = _head->_next;
    _head->_next = _head->_next->_next;
    delete p;
    _count--;
    return *this;
}

template <typename T>
inline
Listqueue<T>& Listqueue<T>::print(){
    if(this->IsEmpty()){
        std::cout << "Liststack is empty!" << std::endl;
        return *this;
    }
    SingleNode<T>* p = _head->_next;
    for(p; p != NULL; p = p->_next){
        std::cout << "num: " << p->_index << " data: " << p->_value << std::endl;
    }
    return *this;
}

#endif