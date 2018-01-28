//
//  main.cpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#include "accountHandler.hpp"


int main(int argc, const char * argv[]) {
    
    int choice;
    accountHandler manager;
    
    while (1) {
        manager.showmenu();
        cout<<"choice:"; cin>>choice;
        
        switch (choice) {
            case MAKE:
                manager.makeacc();
                break;
                
            case DEPOSIT:
                manager.depositmoney();
                break;
                
            case WITHDRAW:
                manager.withdrawmoney();
                break;
                
            case INQUIRE:
                manager.showallinfo();
                break;
                
            case EXIT:
                return 0;
                
            default:
                cout<<"illegal input"<<endl;
        }
    }
    
    
    
    
    return 0;
}
