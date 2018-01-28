//
//  main.c
//  20171021_shaun
//
//  Created by 신 동규 on 2017. 10. 21..
//  Copyright © 2017년 신 동규. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAX 60

typedef struct nodelist
{
    int data;
    struct nodelist* Next;
    struct nodelist* Prev;
}NODE;

NODE* CreateNode(int data)
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->Next = NULL;
    newnode->Prev = NULL;
    
    return newnode;
}

void DeleteNode(NODE* node)
{
    free(node);
}


NODE* GetNodeAt(NODE* head, int index)
{
    NODE* horse = head;
    int count = 0;
    
    while(horse != NULL)
    {
        if(count++ == index)
            return horse;
        horse = horse->Next;
    }
    return NULL;
}




void AddNode(NODE** head, NODE* newnode)
{
    if( (*head) == NULL)
    {
        (*head) = newnode;
    }
    else{
        NODE* horse = (*head);
        
        while(horse->Next != NULL){
            horse = horse->Next;
        }
        
        horse->Next = newnode;
        newnode->Prev = horse;
        
        
    }
    
}



int CountNode(NODE* head){
    
    int count = 0;
    NODE* horse = head;
    
    while(horse != NULL){
        
        count++;
        horse = horse->Next;
        
    }
    
    return count;
    
}


void InsertNode(NODE* Current, NODE* newnode){
    
    if( Current->Next == NULL && Current->Prev == NULL){
        
        Current->Next = newnode;
        newnode->Prev = Current;
        
        
    }
    
    if( Current->Next == NULL){
        
        Current->Next = newnode;
        newnode->Prev = Current;
        
    }
    
    
    else{
        
        newnode->Next = Current->Next;
        Current->Next->Prev = newnode;
        newnode->Prev = Current;
        Current->Next = newnode;
        
        
    }
    
    
}

void RemoveNode(NODE** head, NODE* removeNode){
    
    
    if( (*head) == removeNode){
        
        (*head) = (*head)->Next;
    }
    
    
    if(removeNode->Next != NULL){
        
        removeNode->Next->Prev = removeNode->Prev;
    }
    
    if(removeNode->Prev != NULL){
        
        removeNode->Prev->Next = removeNode->Next;
    }
    
    
    
    DeleteNode(removeNode);
    
    
}

int main(void){
    
    
    int i = 0;
    int count = 0;
    
    NODE* List = NULL;
    NODE* newNode = NULL;
    NODE* Curr = NULL;
    
    
    
    for( i = 0 ; i < 5 ; i++){
        
        
        newNode = CreateNode(i);
        AddNode(&List, newNode);
        
        
    }
    
    count = CountNode(List);
    
    for( i = 0 ; i < count ; i++){
        
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d \n", i , Curr->data);
    }
    
    printf("\n\ncreate 5 new nodes\n\n");
    
    newNode = CreateNode(18);
    Curr = GetNodeAt(List, 3);
    InsertNode(Curr, newNode);
    
    newNode = CreateNode(69);
    Curr = GetNodeAt(List, 4);
    InsertNode(Curr, newNode);
    
    count = CountNode(List);
    for(i = 0 ; i< count ; i++){
        
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d \n", i , Curr->data);
    }
    
    printf("\n\ninser 2 new nodes\n\n");
    
    Curr = GetNodeAt(List, 0);
    
    RemoveNode(&List, Curr);
    
    count = CountNode(List);
    for(i=0 ; i<count ; i++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d \n", i , Curr->data);
    }
    
    printf("\n\nafther removing first node\n\n");
    
    return 0;
    
    
    
}








/*
typedef struct NodeList{
    int data;
    struct NodeList* NEXT;
    struct NodeList* PREV;
}NODE;


NODE* CreateNode(int data){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->NEXT = NULL;
    newnode->PREV = NULL;
    
    return newnode;
}

void DeleteNode(NODE* node){
    free(node);
}

NODE* GetNodeAt(NODE* head, int index){
    int count = 0;
    NODE* horse = head;
    
    while(horse != NULL){
        if(count++ == index)
            return horse;
        horse = horse->NEXT;
    }
    return NULL;
}

int CountNode(NODE* head){
    NODE* horse = head;
    int count = 0;
    while(horse != NULL){
        count++;
        horse = horse->NEXT;
    }
    return count;
}


void AddNode(NODE** head, NODE* newnode){
    if( (*head) == NULL){
        (*head) = newnode;
    }
    else{
        NODE* horse = (*head);
        while(horse->NEXT != NULL){
            horse = horse->NEXT;
        }
        horse->NEXT = newnode;
        newnode->PREV = horse;
    }
}

void InsertNode(NODE* Curr, NODE* newnode){
    if(Curr->NEXT == NULL && Curr->PREV == NULL){
        Curr->NEXT = newnode;
        newnode->PREV = Curr;
    }
    if(Curr->NEXT == NULL){
        Curr->NEXT = newnode;
        newnode->PREV = Curr;
    }
    else{
        newnode->NEXT = Curr->NEXT;
        Curr->NEXT->PREV = newnode;
        newnode->PREV = Curr;
        Curr->NEXT = newnode;
    }
}

void RemoveNode(NODE** head, NODE* removenode){
    if( (*head) == removenode){
        (*head) = (*head)->NEXT;
    }
    
    if(removenode->NEXT != NULL){
        removenode->NEXT->PREV = removenode->PREV;
    }
    if(removenode->PREV != NULL){
        removenode->PREV->NEXT = removenode->NEXT;
    }
    
    DeleteNode(removenode);
}

int main(){
    
    int i = 0;
    int count = 0;
    
    NODE* List = NULL;
    NODE* NewNode = NULL;
    NODE* Curr = NULL;
    
    for(i = 0 ; i <5 ; i++){
        NewNode = CreateNode(i);
        AddNode(&List, NewNode);
    }
    
    for(i = 0 ; i< 5; i ++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d\n", i, Curr->data);
    }
    
    printf("\n\n get 5 nodes \n\n");
    
    NewNode = CreateNode(99);
    Curr = GetNodeAt(List, 1);
    InsertNode(Curr, NewNode);

    NewNode = CreateNode(444);
    Curr = GetNodeAt(List, 3);
    InsertNode(Curr, NewNode);
    
    count = CountNode(List);
    
    for(i = 0 ; i < count ; i++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d\n", i , Curr->data);
    }
    
    printf("\n\n add 2 more nodes\n\n");
    
    Curr = GetNodeAt(List, 0);
    RemoveNode(&List, Curr);
    
    count = CountNode(List);
    
    for( i = 0 ; i < count ; i ++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d\n", i , Curr->data);
    }
    
    printf("\n\n after remove first node\n\n");
    
    return 0 ;
    
}


*/



/*
typedef struct phonebook{
    char name[20];
    char num[20];
}phone;

phone Book[MAX];
int size = 0;

void Regist();
void Print_Book();
int Find_index(char* name);
void Delete();

int main(){
    
    int menu;
    
    while(1)
    {
        system("cls");
        puts("      manage to phone book\n");
        puts("1.show 2.regist 3.delete 4.quit\n");
        printf("      []\b\b");
        scanf(" %d", &menu);
        
        
        switch (menu) {
            case 1: Print_Book();
                break;
            case 2: Regist();
                break;
            case 3: Delete();
                break;
            case 4: exit(1);
            default: printf("input only 1 to 4 \n");
                break;
        }
        
        printf("press any key to continue\n");
        getchar();

    }
    return 0;
    
}

void Delete(){
    char name[20];
    int index;
    int i;
    printf("input name you want to delete\n");
    scanf(" %s", name);
    
    index = Find_index(name);
    
    for( i = index ; i < size-1 ; i++){
        Book[i] = Book[i+1];
    }
    size--;
}



int Find_index(char* name){
    int i;
    for( i = 0 ; i < size ; i++){
        
        if(strcmp(name, Book[i].name) == 0){
            return i;
        }
    }
    return -1;
}

void Print_Book(){
    int i;
    for(i = 0 ; i < size ; i++){
        printf("%-8s %-20s\n", Book[i].name, Book[i].num);
    }
}

void Regist(){
    printf("input name\n");
    scanf(" %s", Book[size].name);
    printf("input phone number\n");
    scanf(" %s", Book[size].num);
    size++;
}

*/


/*
typedef struct {
    char word[20];
    int cnt;
}list;
int limit = 0;

list stress[MAX];

void detector (char* stk);
void Assist(char* stk, char* str, char* seps);

int main(){
    
    char* str;
    int memory;
    char* stoken;
    char seps[] = " ";
    puts("how many memories do you want to have?");
    scanf(" %d", &memory);
    str = (char*)malloc(memory);
    puts("input some sentence");
    getchar();
    gets(str);
    Assist(stoken, str, seps);
    
    int i;
    for(i = 0 ; i < limit ; i++){
        
        printf("%-8s %-5d\n", stress[i].word, stress[i].cnt+1);
    }
    
    return 0;
    
}

void Assist(char* stk, char* str, char* seps)
{
    stk = strtok(str, seps);
    
    while(stk != NULL){
        
        
        detector(stk);
        
        
        
        stk = strtok(NULL, seps);
    }
}


void detector (char* stk){
    int i, found = 0;
    for(i = 0 ; i < limit ; i++){
        if(strcmp(stk, stress[i].word)==0){
            found = 1;
            stress[i].cnt++;
        }
    }
    
    if(found == 0){
        strcpy(stress[limit].word, stk);
        limit++;
    }
}
*/




/*
int main(){
    
    char temp[80];
    char* memory[3];
    int i;
    
    for( i = 0 ; i < 3 ; i++){
        puts("input some sentence");
        gets(temp);
        memory[i] = (char*)malloc(sizeof(char) * (strlen(temp)+1));
        strcpy(memory[i], temp);
    }
    
    for( i = 0 ; i < 3 ; i++){
        puts(memory[i]);
    }
    
    return 0;
    
}

*/





/*

int main(){
    
    char* str;
    int memory;
    int len = 0;
    int i = 0;
    puts("how many memories do you want to input?");
    scanf(" %d", &memory);
    
    str = (char*)malloc(memory);
    
    puts("input some sentence");
    getchar();
    gets(str);
    len = strlen(str);
    
    for(i = len ; i > 0 ; i--){
        if(str[i] == ' '){
            printf("%s ", &str[i+1]);
            str[i] = NULL;
        }
    }
    
    puts(str);
    
    return 0;
    
    
}


*/





/*
int main(){
    
    int arrlen = 5;
    int* arr = (int*)malloc(sizeof(int)*arrlen);
    int idx = 0;
    int i = 0;
    
    
    printf("input number (-1 to quit)\n");
    
    
    while(1){
        
        scanf(" %d", &arr[idx]);
        if( arr[idx] == -1) break;
        
        if(arrlen == idx + 1){
            arrlen += 5;
            arr = (int*)realloc(arr, sizeof(int)*arrlen);
        }
        
        idx++;
        
    }
    
    for(;i<idx;i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
    
    
    
    
    
}
*/


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define N 6

typedef struct nodelist{
    int data;
    struct nodelist * NEXT;
    struct nodelist * PREV;
}NODE;


NODE* CreateNode(int a){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = a;
    newnode->NEXT = NULL;
    newnode->PREV=NULL;
    
    return newnode;
}


void DeleteNode(NODE* node){
    free(node);
}


NODE* GetNodeAt(NODE* head, int index){
    NODE* horse = head;
    int count = 0;
    while(horse != NULL){
        if(count++ == index){
            return horse;
        }
        horse = horse->NEXT;
    }
    return NULL;
}


int CountNode(NODE* head){
    NODE* horse = head;
    int count = 0;
    while(horse != NULL){
        count++;
        horse = horse->NEXT;
    }
    return count;
}



void AddNode(NODE** head, NODE* newnode){
    if( (*head) == NULL){
        (*head) = newnode;
    }
    else{
        NODE* horse = (*head);
        
        while(horse->NEXT != NULL){
            horse = horse->NEXT;
        }
        
        horse->NEXT = newnode;
        newnode->PREV = horse;
    }
}


void InsertNode(NODE* current, NODE* newnode){
    if(current->NEXT == NULL && current->PREV == NULL){
        current->NEXT = newnode;
        newnode->PREV = current;
    }
    if(current->NEXT == NULL){
        current->NEXT = newnode;
        newnode->PREV = current;
    }
    else{
        newnode->NEXT = current->NEXT;
        current->NEXT->PREV = newnode;
        newnode->PREV = current;
        current->NEXT = newnode;
    }
}


void RemoveNode(NODE** head, NODE* removenode){
    if( (*head) == removenode){
        (*head) = (*head)->NEXT;
    }
    
    if(removenode->NEXT != NULL){
        removenode->NEXT->PREV = removenode->PREV;
    }
    if(removenode->PREV != NULL){
        removenode->PREV->NEXT = removenode->NEXT;
    }
    
    DeleteNode(removenode);
}

int main(){
    int i = 0;
    int count = 0;
    
    NODE* List = NULL;
    NODE* NewNode = NULL;
    NODE* Curr = NULL;
    
    for(i = 0 ; i < 5 ; i++){
        NewNode = CreateNode(i);
        AddNode(&List, NewNode);
    }
    
    count = CountNode(List);
    
    for( i = 0 ; i < count ; i++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d \n", i , Curr->data);
    }
    
    printf("------------------get 5 nodes------------------\n");
    
    NewNode = CreateNode(99);
    Curr = GetNodeAt(List, 1);
    InsertNode(Curr, NewNode);
    
    NewNode = CreateNode(444);
    Curr = GetNodeAt(List, 4);
    InsertNode(Curr, NewNode);
    
    count = CountNode(List);
    
    for( i = 0 ; i < count ; i++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d \n", i , Curr->data);
    }
    
    printf("--------------------add 2 nodes--------------------\n");
    
    
    Curr = GetNodeAt(List, 3);
    RemoveNode(&List, Curr);
    Curr = GetNodeAt(List, 0);
    RemoveNode(&List, Curr);
    
    count = CountNode(List);
    
    for( i = 0 ; i < count ; i++){
        Curr = GetNodeAt(List, i);
        printf("List[%d] = %d\n", i , Curr->data);
    }
    
    printf("----------------------remove 2nodes----------------------\n");
    
    return 0;
}

*/





/*
int arr[N];
void Randomnum(void);
int Checkoverlap(void);
void Sort(void);
void Printlotto(void);

int main(){
    srand(time(NULL));
    int c;
    
    do
    {
        system("cls");
        Randomnum();
        c = Checkoverlap();
        if(c) continue;
        Sort();
        Printlotto();
        puts("press any key to continue");
        
    }while(getch()!=0X1B);

        return 0 ;
}

void Printlotto(){
    int i;
    for(i=0 ; i<N ; i++){
        printf("%d ", arr[i]);
    }
}

void Sort(){
    int i,j;
    for(i=0 ; i<N ; i++){
        for(j = i+1 ; j<N ; j++){
            if(arr[i] > arr[j]){
                int t;
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int Checkoverlap(){
    int i,j;
    for(i=0 ; i<N ; i++){
        for(j=i+1 ; j<N ; j++){
            if(arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}



void Randomnum(){
    int i;
    for(i=0 ; i<N ; i++){
        arr[i] = rand()%45+1;
    }
}

*/

/*
typedef struct nodelist{
    int data;
    struct nodelist * NEXT;
    struct nodelist * PREV;
}NODE;

NODE* CREATENODE(int a){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = a;
    newnode->NEXT = NULL;
    newnode->PREV=NULL;
    
    return newnode;
}

void DELETENODE(NODE* node){
    free(node);
}

NODE* GETNODEAT(NODE* head, int index){
    NODE* horse = head;
    int count = 0;
    while(horse != NULL){
        if(count++ == index)
            return horse;
        horse = horse->NEXT;
    }
    return NULL;
}

int COUNTNODE(NODE* head){
    NODE* horse = head;
    int count = 0;
    while(horse != NULL){
        count++;
        horse = horse->NEXT;
    }
    return count;
}

void ADDNODE(NODE** head, NODE* newnode){
    if( (*head) == NULL){
        *head = newnode;
    }
    else{
        NODE* horse = (*head);
        
        while(horse->NEXT != NULL){
            horse = horse->NEXT;
        }
        
        horse->NEXT = newnode;
        newnode->PREV = horse;
    }
    
}

void INSERTNODE(NODE* current, NODE* newnode){
    if(current->NEXT == NULL && current->PREV == NULL){
        current->NEXT = newnode;
        newnode->PREV = current;
    }
    if(current->NEXT == NULL){
        current->NEXT = newnode;
        newnode->PREV = current;
    }
    else{
        current->NEXT->PREV = newnode;
        newnode->NEXT = current->NEXT;
        newnode->PREV = current;
        current->NEXT = newnode;
    }
}


void REMOVENODE(NODE** head, NODE* removenode){
    if( (*head)==removenode){
        (*head) = (*head)->NEXT;
    }
    if(removenode->NEXT != NULL){
        removenode->NEXT->PREV = removenode->PREV;
    }
    if(removenode->PREV != NULL){
        removenode->PREV->NEXT = removenode->NEXT;
    }
    
    DELETENODE(removenode);
}

int main(){
    
    int i=0;
    int count = 0;
    
    NODE* List = NULL;
    NODE* newNode = NULL;
    NODE* current = NULL;
    
    for(i = 0; i<5; i++){
        newNode = CREATENODE(i);
        ADDNODE(&List, newNode);
    }
    
    count = COUNTNODE(List);
    
    for(i=0 ; i<count ; i++){
        current = GETNODEAT(List, i);
        printf("List[%d] = %d\n", i, current->data);
    }
    
    printf("------------- get 5 nodes-------------\n");
    
    newNode = CREATENODE(99);
    current = GETNODEAT(List, 0);
    INSERTNODE(current, newNode);
    
    newNode = CREATENODE(444);
    current = GETNODEAT(List, 4);
    INSERTNODE(current, newNode);
    
    count = COUNTNODE(List);
    
    for(i=0 ; i<count ; i++){
        current = GETNODEAT(List, i);
        printf("List[%d] = %d\n", i, current->data);
    }
    
    printf("--------------- add 2 nodes---------------");
    
    
    newNode = GETNODEAT(List, 1);
    REMOVENODE(&List, newNode);
    
    newNode = GETNODEAT(List, 0);
    REMOVENODE(&List, newNode);
    
    count = COUNTNODE(List);
    
    for(i=0 ; i<count ; i++){
        current = GETNODEAT(List, i);
        printf("List[%d] = %d\n", i, current->data);
    }
    
    printf("------------after node with index 0,1 removed------------\n");
    
    return 0;
    
}

*/




/*
int searching(char* who, char(*name)[7]);
void SWAPCAHR(char * A, char * B);
void sort(char (*A)[7], char (*B)[7], double * C);
void SWAPDOUBLE(double * A, double * B);
void PRINTSTUDENT(char (*name)[7], char (*stdnum)[7], double * grade);

int main(int argc, const char * argv[]) {
    // insert code here...
    char who[7], name[N][7] = {"song", "goo", "hugo", "sdf", "asdd", "sdasd", "qwe", "dfg", "ert", "ajgd"};
    char stdnum[N][7] = {"5228", "5211", "1235", "8282", "5165", "5232", "3452", "5210", "5210", "8255"};
    double grade[N] = {4.3, 4.0, 3.2, 2.7, 3.2, 4.0, 4.4, 3.7, 4.2, 3.8};
    int menu;
    puts("input the name you want to find");
    scanf(" %s", who);
    
    int c;
    c = searching(who, name);
    
    printf("%-8s %-8s %-5.1lf\n", name[c], stdnum[c], grade[c]);
    
    puts("How to sort?(1.name   2.student number)");
    scanf(" %d", &menu);
    
    switch(menu){
        case 1: sort(name, stdnum, grade); break;
        case 2: sort(stdnum, name, grade); break;
        default: puts("input number only 1 or 2");
    };
    PRINTSTUDENT(name, stdnum, grade);
    


    return 0;
}

void PRINTSTUDENT(char (*name)[7], char (*stdnum)[7], double * grade){
    int i;
    for(i=0; i<N;i++){
        printf("%-8s %-8s %-5.1lf\n", name[i], stdnum[i], grade[i]);
    }
}


void SWAPCAHR(char * A, char * B){
    char temp[7];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
}
void SWAPDOUBLE(double * A, double * B){
    double T;
    T = *A;
    *A = *B;
    *B = T;
}


void sort(char (*A)[7], char (*B)[7], double * C){
    int i,j;
    for(i=0;i<N; i++){
        for(j=i+1; j<N;j++){
            if(strcmp(A[i], A[j])>0){
                
                SWAPCAHR(A[i], A[j]);
                SWAPCAHR(B[i], B[j]);
                SWAPDOUBLE(&C[i], &C[j]);
                
            }
        }
    }
}






int searching(char* who, char(*name)[7]){
    int i;
    for(i=0;i<N;i++){
        if(strcmp(who, name[i])==0){
            return i;
        }
    }
    return -1;
}
*/

