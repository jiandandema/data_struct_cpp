#include <iostream>
#include <vector>
#include "Singlelist.h"
#include "Doublelist.h"
#include "Arraystack.h"
#include "Liststack.h"
#include "Arrayqueue.h"
#include "Listqueue.h"

void test_Singlelist(){
    Singlelist<double> a;
    std::cout << "--------------Empty Singlelist test!------------" << std::endl;
    a.print().del(10);
    std::cout << a.size() << std::endl;
    std::cout << "--------------insert test!------------" << std::endl;
    std::cout << "initialize insert!" << std::endl;
    a.insert_last(10.0).insert_last(20.0).insert_last(30.0).print();
    std::cout << "out_range insert!" << std::endl;
    a.insert(10,100.0).print();
    std::cout << "midway insert!" << std::endl;
    a.insert(2,10000.0).print();
    std::cout << "head insert!" << std::endl;
    a.insert_head(232324.0).print();
    std::cout << "compute size!" << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << "--------------delete test!------------" << std::endl;
    std::cout << "out-range delete!" << std::endl;
    a.del(100).print();
    std::cout << "head delete!" << std::endl;
    a.del_head().print();
    std::cout << "midway delete!" << std::endl;
    a.del(3).print();
    std::cout << "last delete!" << std::endl;
    a.del_last().print();
    std::cout << "--------------get value test!------------" << std::endl;
    std::cout << "out-range get value!" << std::endl;
    std::cout << a.get_value(20) << std::endl;
    std::cout << "get value test!" << std::endl;
    std::cout << a.get_value(2) << std::endl;
    std::cout << "--------------pointer test!------------" << std::endl;
    Singlelist<double>::pointer p = a.get_head();
    for(p; p != NULL; p = p->_next){
        std::cout << "index: " << p->_index << " data: " << p->_value << std::endl;
    }
}
/*
void test_DoubleList(){
    DoubleList<double> a;
    std::cout << "--------------Empty Singlelist test!------------" << std::endl;
    a.print();
    std::cout << "-------------------insert test!-----------------" << std::endl;
    std::cout << "initialize insert!" << std::endl;
    a.insert_last(10.0).insert_last(20.0).insert_last(30.0).print().size();
    std::cout << "out_range insert!" << std::endl;
    a.insert(10,100.0).print().size();
    std::cout << "midway insert!" << std::endl;
    a.insert(2,10000.0).print();
    std::cout << "head insert!" << std::endl;
    a.insert_head(232324.0).print();
    std::cout << "compute size!" << std::endl;
    a.size();
    std::cout << "--------------get value test!------------" << std::endl;
    std::cout << "out-range get value!" << std::endl;
    std::cout << a.get_value(20) << std::endl;
    std::cout << "get value test!" << std::endl;
    std::cout << a.get_value(2) << std::endl;
    std::cout << "--------------pointer test!------------" << std::endl;
    DoubleList<double>::pointer head = a.get_head(), p = head;
    DoubleList<double>::pointer last = a.get_last();
    int tag = 0;
    std::cout << "increase print" << std::endl;
    for(p; (p != head || tag != 1); p = p->_next, tag = 1){
        std::cout << "index: " << p->_index << " data: " << p->_value << std::endl;
    }
    std::cout << "decrease print" << std::endl;
    for(p=last; (p != last || tag != 0); p = p->_pre, tag = 0){
        std::cout << "index: " << p->_index << " data: " << p->_value << std::endl;
    }
    std::cout << "--------------delete test!------------" << std::endl;
    std::cout << "out-range delete!" << std::endl;
    a.del(100).print();
    std::cout << "head delete!" << std::endl;
    a.del_head().print();
    std::cout << "midway delete!" << std::endl;
    a.del(3).print();
    std::cout << "last delete!" << std::endl;
    a.del_last().print();
}

void test_Arraystack(){
    Arraystack<int> a;
    a.push(10).push(20).push(30);
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
}

void test_Liststack(){
    Liststack<int> a;
    a.push(10).push(20).push(30);
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
    std::cout << a.size() <<std::endl;
    std::cout << a.get_top() <<std::endl; a.pop();
}

void test_Arrayqueue(){
    Arrayqueue<int> a(4);
    std::cout << "push test and out-range push test!" << std::endl;
    a.push(10).push(20).push(30).push(40).push(50);
    std::cout << a.get_head() << std::endl;
    std::cout << "pop test and loop push test!" << std::endl;
    a.pop();
    std::cout << a.get_head() << std::endl;
    a.push(50).push(60);
    std::cout << "check every element in Arrayqueue is right!" << std::endl;
    std::cout << a.get_head() << std::endl;
    for(int i = 0; i < 4; ++i)
        std::cout << a.get_array()[i] << std::endl;
}

void test_Listqueue(){
    Listqueue<int> a;
    std::cout << "push test and out-range push test!" << std::endl;
    a.push(10).push(20).push(30).push(40).push(50);
    std::cout << a.get_head() << std::endl;
    std::cout << "pop test and loop push test!" << std::endl;
    a.pop();
    std::cout << a.get_head() << std::endl;
    a.push(500).push(600);
    std::cout << "check every element in Arrayqueue is right!" << std::endl;
    Listqueue<int>::pointer p = a.get_list();
    for(p; p != NULL; p = p->_next){
        std::cout << p->_value << std::endl;
    }
}
*/


int main(){

    test_Singlelist();

    return 0;
}