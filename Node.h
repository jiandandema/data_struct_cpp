#ifndef __NODE__
#define __NODE__
#include <iostream>

template <typename T>
class SingleNode
{
private:
    T _value;
    int _index;
    SingleNode<T>* _next;
public:
    SingleNode(T& value, int& index = 0, SingleNode<T>* next = NULL)
        : _value(value), _index(index), _next(next) {}
};

template <typename T>
class DoubleNode
{
private:
    T _value;
    int _index;
    SingleNode<T>* _next;
    SingleNode<T>* _pre;
public:
    DoubleNode(T& value, int& index = 0, SingleNode<T>* next = NULL, SingleNode<T>* pre = NULL)
        : _value(value), _index(index), _next(next), _pre(pre) {}
};


#endif