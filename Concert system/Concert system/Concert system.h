#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<string.h>
#define N 100


//�û�
 typedef struct user {
	char id[N];                                    //�û���
	char password[N];                              //����                     
}user;

 typedef struct ticket {
	 char name[N];   
	 char location[N];
	 double price;
	 char time[N];

	  ticket* next;
 }ticket;

 ticket* List_head = NULL;

 int Login(); //��¼
 void Menu(); //���˵�
 int Choose(); //ѡ����
 void Creathead(); // ����ͷ���
 void Reload();     //  ���뱾���ļ�

 void Search();      //  �����ݳ���
 void Creat();       //  �½��ݳ���
 void Delete();     //  ɾ���ݳ���
 void DeleteAll();   // ɾ������
 void Modify();     //  �޸��ݳ�������
 void Sort();      // ����
 void Changedata(ticket* p);   // �����е����ݽ���
 void DisplayAll();  //  ��ʾ�����ݳ���
 void Save();       //  ����
