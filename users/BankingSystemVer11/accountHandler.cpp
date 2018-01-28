//
//  accountHandler.cpp
//  BankingSystemVer11
//
//  Created by 좌 준협 on 14/11/2017.
//  Copyright © 2017 좌 준협. All rights reserved.
//

#include "accountHandler.hpp"
#include "normalAccount.hpp"
#include "highcredit.hpp"
#include "Exception.hpp"





accountHandler:: accountHandler() : accNum(0) {}

void accountHandler:: addAcc(ACC_PTR emp){
    acc[accNum++] = emp;
}

void accountHandler:: normal(){
    int id, money;
    string name;
    
    cout<<"input id:"; cin>>id;
    cout<<"input money:"; cin>>money;
    cout<<"input name:"; cin>>name;
    
    
    addAcc(new normalAccount(id, money, name));
    
    
}


void accountHandler:: highcredit() {
    int id, money, level;
    string name;
    
    cout<<"input id:"; cin>>id;
    cout<<"input money:"; cin>>money;
    cout<<"input name:"; cin>>name;
    cout<<"level(1 to A, 2 to B, 3 to C):"; cin>>level;
    
    switch (level) {
        case 1:
            addAcc(new highcreditAccount(id, money, name, LEVEL_A));
            break;
        case 2:
            addAcc(new highcreditAccount(id, money, name, LEVEL_B));
            break;
        case 3:
            addAcc(new highcreditAccount(id, money, name, LEVEL_C));
            break;
            
            
        default:
            cout<<"wrong input"<<endl;
            break;
    }
    
    
    
}



void accountHandler:: showmenu() const{
    cout<<"----menu----"<<endl;
    cout<<"1. make account"<<endl;
    cout<<"2. deposit money"<<endl;
    cout<<"3. withdraw money"<<endl;
    cout<<"4. show all info"<<endl;
    cout<<"5. Exit"<<endl;
}


void accountHandler:: makeacc(){
    int select;
    
    cout<<"which type of account do you want to build up?"<<endl;
    cout<<"1 to normal, 2 to highcredit"<<endl;
    cin>>select;
    
    switch (select) {
        case NORMAL:
            normal();
            break;
        case HIGH:
            highcredit();
            break;
            
        default:
            cout<<"wrong input"<<endl;
            break;
    }
    
}



void accountHandler:: depositmoney(){
    int id, money;
    
    
    cout<<"input id:"; cin>>id;
    
    
    while (1) {
        
        cout<<"input money:"; cin>>money;
        try {
            for (int i = 0 ; i < accNum ; i++) {
                if (acc[i]->getaccID() == id) {
                    acc[i]->deposit(money);
                    cout<<"complete"<<endl;
                    return;
                }
            }
            cout<<"fail to find id you input"<<endl;
            return;
        } catch (minusException & expn) {
            expn.showExceptionReason();
            cout<<"reinput only money please"<<endl;
        }
        
        
        
        
    }
    
    
    
    
    
    
}



void accountHandler:: withdrawmoney() {
    int id, money;
    
    cout<<"input id:"; cin>>id;
    
    
    while (1) {
        
        cout<<"input money:"; cin>>money;
        
        try {
            for (int i = 0 ; i < accNum ; i++) {
                if (acc[i]->getaccID() == id) {
                    acc[i]->withdraw(money);
                    cout<<"complete"<<endl;
                    return;
                }
            }
            cout<<"fail to find id"<<endl;
            return;
        } catch (suffException & expn) {
            expn.showExceptionReason();
            cout<<"please reinput only money"<<endl;
        }
        
   
    }
    
    
    
}


void accountHandler:: showallinfo() const{
    for (int i = 0 ; i < accNum ; i++) {
        acc[i]->showAcc();
    }
    cout<<endl;
}

accountHandler:: ~accountHandler(){
    for (int i = 0 ; i < accNum ; i++) {
        delete acc[i];
    }
}



















