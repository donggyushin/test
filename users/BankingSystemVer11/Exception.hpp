//
//  Exception.hpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>



class minusException {
private:
    int problem;
    
public:
    minusException(int money);
    void showExceptionReason() const;
};

class suffException {
private:
    int balance;
    int money;
    
public:
    suffException(int bal, int mon);
    void showExceptionReason() const;
};





#endif /* Exception_hpp */
