#ifndef CONCERT_SYSTEM_H
#define CONCERT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
// ���������󳤶�����
#define User_length 20  
#define Password_length 20  
#define Concert_length 50  

// �û��ṹ��
typedef struct User {
    char username[User_length];
    char password[Password_length];
    struct User* next;
} User;

// ����Ա�ṹ��
typedef struct Admin {
    char username[User_length];
    char password[Password_length];
    struct Admin* next;
} Admin;

// �ݳ���ṹ��
typedef struct Concert {
    char name[Concert_length];
    char performer[Concert_length];
    char venue[Concert_length];
    char date[Concert_length];
    struct Concert* next;
} Concert;

// ��Ʊ��Ϣ�ṹ��
typedef struct Ticket {
    char username[User_length];
    char concertName[Concert_length];
    struct Ticket* next;
} Ticket;

// ����ȫ������ͷָ��
extern User* userList;
extern Admin* adminList;
extern Concert* concertList;
extern Ticket* ticketList;

// ��������
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