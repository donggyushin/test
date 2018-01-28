//
//  Exception.cpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#include "Exception.hpp"

using namespace std;


minusException:: minusException(int money) : problem(money) {}

void minusException:: showExceptionReason() const{
    cout<<"[Exception :"<<problem<<"is unvailable]"<<endl;
}


suffException:: suffException(int bal, int mon) : balance(bal), money(mon) {}
void suffException:: showExceptionReason() const{
    cout<<"[Exception : you need more than"<<money-balance<<"]"<<endl;
}


