//
//  accountHandler.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef accountHandler_hpp
#define accountHandler_hpp

#include "Account.hpp"
#include "boundcheckArray.hpp"
#include "CONST.h"

typedef Account* ACC_PTR;

class accountHandler {
private:
    boundcheckArray<ACC_PTR> acc;
    int accNum;
    
public:
    accountHandler();
    void addAcc(ACC_PTR emp);
    void showmenu() const;
    void makeacc();
    void depositmoney();
    void withdrawmoney();
    void showallinfo() const;
    ~accountHandler();
    
    
protected:
    void normal();
    void highcredit();
    
    
};








#endif /* accountHandler_hpp */
