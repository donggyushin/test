//
//  Account.cpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#include "Account.hpp"


Account::Account(int id, int money, string name) : accID(id), balance(money) {
    this->name = name;
}

int Account:: getaccID() const{
    return accID;
}

void Account:: deposit(int money){
    if (money < 0) {
        throw minusException(money);
    }
    
    balance+=money;
}
int Account:: withdraw(int money) {
    if (balance < money) {
        throw suffException(balance, money);
    }
    
    balance -= money;
    return money;
}


void Account:: showAcc() const{
    cout<<"accID:"<<accID<<endl;
    cout<<"balance:"<<balance<<endl;
    cout<<"name:"<<name<<endl;
    
    
}
