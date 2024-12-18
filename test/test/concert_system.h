#ifndef CONCERT_SYSTEM_H
#define CONCERT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
// 定义各类最大长度限制
#define User_length 20  
#define Password_length 20  
#define Concert_length 50  

// 用户结构体
typedef struct User {
    char username[User_length];
    char password[Password_length];
    struct User* next;
} User;

// 管理员结构体
typedef struct Admin {
    char username[User_length];
    char password[Password_length];
    struct Admin* next;
} Admin;

// 演唱会结构体
typedef struct Concert {
    char name[Concert_length];
    char performer[Concert_length];
    char venue[Concert_length];
    char date[Concert_length];
    struct Concert* next;
} Concert;

// 购票信息结构体
typedef struct Ticket {
    char username[User_length];
    char concertName[Concert_length];
    struct Ticket* next;
} Ticket;

// 声明全局链表头指针
extern User* userList;
extern Admin* adminList;
extern Concert* concertList;
extern Ticket* ticketList;

// 函数声明
void saveData();
void loadData();
void registerUser();
int userLogin();
void registerAdmin();
int adminLogin();
void addConcert();
void deleteConcert();
void searchConcert();
void modifyConcert();
void buyTicket();
void userMenu();
void adminMenu();
void filterConcertsByDate(const char* startDate, const char* endDate);
void filterConcertsByPerformer(const char* performerName);
void viewPurchasedTickets(const char* username);

#endif