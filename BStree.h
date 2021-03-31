#ifndef __BSTREE__
#define __BSTREE__
#include <iostream>
#include "Node.h"

template <typename T>
class BStree
{
private:
    BSNode<T>* _root;

    void preOder(const BSNode<T>* node);
    void inOder(const BSNode<T>* node);
    void postOder(const BSNode<T>* node);

    BSNode<T>* predecessor(BSNode<T>* node);
    BSNode<T>* successor(BSNode<T>* node);

    BStree<T>& remove(BSNode<T>* node, const T& value);
public:
    BStree();
    ~BStree();

    BStree<T>& insert(const T& value);

    void preOder();
    void inOder();
    void postOder();

    BStree<T>& remove(const T& value);
};

template <typename T>
inline
BStree<T>::BStree()
{
    _root = NULL;
}


template <typename T>
inline
BStree<T>::~BStree()
{
}

template <typename T>
inline
BStree<T>& BStree<T>::insert(const T& value){
    BSNode<T>* temp = new BSNode<T>(value,NULL,NULL,NULL);
    //empty tree?
    if(_root == NULL){
        _root = temp;
        return *this;
    }
    //find insert location
    BSNode<T>* p = _root;
    BSNode<T>* pre = NULL;
    while (p)
    {
        pre = p;
        if(value > p->_value){
            p = p->_right;
        }
        else if(value < p->_value){
            p = p->_left;
        }
        else{
            break;
        }
    }
    //insert value and set parent node
    if(value > pre->_value){
        pre->_right = temp;
    }
    else{
        pre->_left = temp;
    }
    temp->_parent = pre;

    return *this;
}

template <typename T>
inline
void BStree<T>::preOder(const BSNode<T>* node){
    if (node!=NULL)
    {
        std::cout << node->_value << " ";
        preOder(node->_left);
        preOder(node->_right);
    }

}

template <typename T>
inline
void BStree<T>::inOder(const BSNode<T>* node){
    if (node!=NULL)
    {
        inOder(node->_left);
        std::cout << node->_value << " ";
        inOder(node->_right);
    }
}

template <typename T>
inline
void BStree<T>::postOder(const BSNode<T>* node){
    if (node!=NULL)
    {
        postOder(node->_left);
        postOder(node->_right);
        std::cout << node->_value << " ";
    }
}

template <typename T>
inline
void BStree<T>::preOder(){
    std::cout << "preOder print!" << std::endl;
    preOder(_root);
    std::cout << "\npreOder print!" << std::endl;
}

template <typename T>
inline
void BStree<T>::inOder(){
    std::cout << "inOder print!" << std::endl;
    inOder(_root);
    std::cout << "\ninOder print!" << std::endl;
}

template <typename T>
inline
void BStree<T>::postOder(){
    std::cout << "postOder print!" << std::endl;
    postOder(_root);
    std::cout << "\npostOder print!" << std::endl;
}

template <typename T>
inline
BSNode<T>* BStree<T>::predecessor(BSNode<T>* node){
    if(node == NULL)
        return NULL;
    if(node->_left){
        BSNode<T>* p = node->_left;
        while (p->_right){
            p = p->_right;
        }
        return p;
    }

    while(node->_parent != NULL && node->_parent->_left == node){
        node = node->_parent;
    }
    return node->_parent;
}

template <typename T>
inline
BSNode<T>* BStree<T>::successor(BSNode<T>* node){
    if(node == NULL)
        return NULL;
    if(node->_right){
        BSNode<T>* p = node->_right;
        while (p->_left){
            p = p->_left;
        }
        return p;
    }

    while(node->_parent != NULL && node->_parent->_right == node){
        node = node->_parent;
    }
    return node->_parent;
}

template <typename T>
inline
BStree<T>& BStree<T>::remove(BSNode<T>* node, const T& value){
    if(node){
        if(value == node->_value){
            BSNode<T>* pdel = NULL;
            if(node->_left == NULL || node->_right == NULL)
                pdel = node;
            else
                pdel = predecessor(node);

            BSNode<T>* pchild = NULL;
            if(pdel->_left)
                pchild = pdel->_left;
            else
                pchild = pdel->_right;

            if(pchild)
                pchild->_parent = pdel->_parent;

            if(pdel->_parent == NULL)
                _root = pchild;
            else if(pdel->_parent->_left == pdel){
                pdel->_parent->_left = pchild;
            }
            else{
                pdel->_parent->_right = pchild;
            }

            if(node->_value != pdel->_value)
                node->_value = pdel->_value;

            delete pdel;
            return *this;
        }
        else if(value > node->_value){
            return remove(node->_right,value);
        }
        else{
            return remove(node->_left,value);
        }
    }
    return *this;
}

template <typename T>
inline
BStree<T>& BStree<T>::remove(const T& value){
    return remove(_root, value);
}

#endif