//
//  Account.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#include "Exception.hpp"



class Account {
private:
    int accID;
    int balance;
    string name;
    
public:
    Account(int id, int money, string name);
    int getaccID() const;
    virtual void deposit(int money);
    int withdraw(int money);
    void showAcc() const;
    
    };






#endif /* Account_hpp */
