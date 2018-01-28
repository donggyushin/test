//
//  normalAccount.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef normalAccount_hpp
#define normalAccount_hpp

#include "Account.hpp"


class normalAccount : public Account {
private:
    int interRate;
    
public:
    normalAccount(int id, int money, string name);
    virtual void deposit(int money);
};


normalAccount:: normalAccount(int id, int money, string name)
: Account(id, money, name), interRate(3){}

void normalAccount:: deposit(int money){
    if (money < 0) {
        throw minusException(money);
    }
    Account::deposit(money);
    Account::deposit((int)money*interRate/100.0);
}





#endif /* normalAccount_hpp */
