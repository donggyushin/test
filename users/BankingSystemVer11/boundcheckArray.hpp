//
//  boundcheckArray.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef boundcheckArray_hpp
#define boundcheckArray_hpp

#include <iostream>
using namespace std;


template <class T>
class boundcheckArray {
    T * arr;
    int arrlen;
    
public:
    boundcheckArray(int len = 100);
    T operator[](int idx) const;
    T& operator[](int idx);
    ~boundcheckArray();
    int getarrlen() const;
};



template<class T>
boundcheckArray<T>:: boundcheckArray(int len) : arrlen(len) {
    arr = new T[len];
}

template<class T>
T boundcheckArray<T>:: operator[](int idx) const{
    if (idx < 0 || idx >=arrlen) {
        cout<<"out of boundary"<<endl;
        exit(1);
    }
    return arr[idx];
}

template<class T>
T& boundcheckArray<T>:: operator[](int idx){
    if (idx < 0 || idx >=arrlen) {
        cout<<"out of boundary"<<endl;
        exit(1);
    }
    return arr[idx];
}




template<class T>
boundcheckArray<T>:: ~boundcheckArray(){
    delete []arr;
}

template<class T>
int boundcheckArray<T>:: getarrlen() const{
    return arrlen;
}

























#endif /* boundcheckArray_hpp */
