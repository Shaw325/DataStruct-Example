//
// Created by lindsey on 2021/8/26.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include <iostream>
using namespace std;


template <typename T>
class List{
public:
    virtual int length(){ cout << "Not support the method call." << endl;return 0;};
    virtual bool add(T data){ cout << "Not support the method call." << endl;return 0;};
    virtual bool remove(int index){ cout << "Not support the method call." << endl;return 0;};
};
#endif //DATASTRUCTURE_LIST_H
