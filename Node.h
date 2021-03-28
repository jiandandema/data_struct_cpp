#ifndef __NODE__
#define __NODE__
#include <iostream>

template <typename T>
class SingleNode
{
public:
    T _value;
    int _index;
    SingleNode<T>* _next;
public:
    SingleNode(const T& value, int index = 0, SingleNode<T>* next = NULL)
        : _value(value), _index(index), _next(next) {}
};

template <typename T>
class DoubleNode
{
public:
    T _value;
    int _index;
    DoubleNode<T>* _next;
    DoubleNode<T>* _pre;
public:
    DoubleNode(const T& value,const int& index = 0, DoubleNode<T>* next = NULL, DoubleNode<T>* pre = NULL)
        : _value(value), _index(index), _next(next), _pre(pre) {}
};


#endif