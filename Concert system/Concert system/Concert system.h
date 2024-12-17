#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<string.h>
#define N 100
#define size 100
//����Ա
typedef struct administrator {
	char id[N];                                     //�û���
	char password[N];                               //����
}Admin;

//�û�
 typedef struct user {
	char id[N];                                    //�û���
	char password[N];                              //����
	struct voto* ticket[N];                        //�û������Ʊ�ĵ�ַ
	int sum;                                       //�û������Ʊ��
}user;

 //��Ʊ
  typedef struct voto {
	 char name[N];                                //����
	 char year[N];
	 char month[N];
	 char days[N];
	 char start[N];                               //����
	 char Ticket[N];                              //Ʊ��
	 double price[N];                             //�۸�
	 int num[N];                                  //����
	 int id[N];                                   //���
	 char seat[N];                                //��λ
	 bool flag ;                           //��¼Ʊ�Ƿ��۳�
 }voto;

  FILE* Admin_file;
  FILE* user_file;                                
  FILE* voto_file;

  Admin AdminList[size];                          //����Ա�б�
  user UserList[size];                            //�û��б�
  voto VotoList[size];                            //��Ʊ�б�

  void read_information();                        //��ȡ��Ϣ
  void user_register();                           //�û�ע��
  void user_long_on();                            //�û���¼
 