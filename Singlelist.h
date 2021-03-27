#ifndef __SINGLELIST__
#define __SINGLELIST__
#include <iostream>
#include <cmath>
#include "Node.h"

template <typename T>
class Singlelist
{
private:
    SingleNode<T>* _head;
    int _count;
    SingleNode<T>* getNode(const int& index);
public:
    Singlelist();
    ~Singlelist();

    typedef SingleNode<T>* pointer;

    Singlelist<T>& insert(const int& index, const T& value);
    Singlelist<T>& insert_head(const T& value);
    Singlelist<T>& insert_last(const T& value);

    Singlelist<T>& del(const int& index);
    Singlelist<T>& del_head();
    Singlelist<T>& del_last();

    T get_value(const int& index) { return getNode(index) ? getNode(index)->_value:sqrt(-1); }          //this is not the bast way, because sqrt(-1) may be not compatible with T

    int size() const { return _count; }
    bool IsEmpty() const { return _count == 0; }
    SingleNode<T>* get_head() const { return _head->_next; }                    //maybe it should not provide to user!
    Singlelist<T>& print();
};

template <typename T>
inline
Singlelist<T>::Singlelist()
    : _count(0)
{
    _head = new SingleNode<T>(0,0,NULL);
}

template <typename T>
inline
Singlelist<T>::~Singlelist()
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
SingleNode<T>* Singlelist<T>::getNode(const int& index){
    if(index > _count){
        std::cout << "User input index: " << index << " is out-of-range!" << std::endl;
        return NULL;
    }
    SingleNode<T>* p = _head;
    for(int i = 0; i < index; ++i){
        p = p->_next;
    }

    return p;
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::print(){
    if(this->IsEmpty()){
        std::cout << "Singlelist is empty!" << std::endl;
        return *this;
    }
    SingleNode<T>* p = _head->_next;
    for(p; p != NULL; p = p->_next){
        std::cout <<"num: " << p->_index << " data: " << p->_value << std::endl;
    }
    return *this;
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::insert(const int& index, const T& value){
    SingleNode<T>* temp = getNode(index);
    if(temp){                                                               //because of out-range-insert
        SingleNode<T>* p = new SingleNode<T>(value,index,temp->_next);
        temp->_next = p;
        for(p; p != NULL; p = p->_next){
            p->_index++;
        }
        _count++;
    }

    return *this;
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::del(const int& index){
    if(this->IsEmpty()){
        std::cout << "Singlelist is empty!NO MORE DELETE!" << std::endl;
        return *this;
    }
    if(getNode(index)){                                             //because of out-range-del
        SingleNode<T>* temp = getNode(index-1);
        temp->_next = temp->_next->_next;
        SingleNode<T>* p = temp->_next;
        for(p; p != NULL; p = p->_next){
            p->_index--;
        }
        _count--;
    }

    return *this;
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::insert_head(const T& value){
    return insert(0,value);
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::insert_last(const T& value){
    return insert(_count,value);
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::del_head(){
    return del(0);
}

template <typename T>
inline
Singlelist<T>& Singlelist<T>::del_last(){
    return del(_count);
}

#endif