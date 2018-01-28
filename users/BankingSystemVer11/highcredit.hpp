//
//  highcredit.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef highcredit_hpp
#define highcredit_hpp

#include "normalAccount.hpp"

class highcreditAccount : public normalAccount {
private:
    int specialRate;
    
public:
    highcreditAccount(int id, int money, string name, int rate);
    virtual void deposit(int money);
};



highcreditAccount:: highcreditAccount(int id, int money, string name, int rate)
: normalAccount(id, money, name), specialRate(rate) {}

void highcreditAccount:: deposit(int money){
    if (money < 0) {
        throw minusException(money);
    }
    normalAccount::deposit(money);
    Account::deposit((int)money*specialRate/100.0);
}



#endif /* highcredit_hpp */
