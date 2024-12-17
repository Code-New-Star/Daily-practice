#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<string.h>
#define N 100
#define size 100
//管理员
typedef struct administrator {
	char id[N];                                     //用户名
	char password[N];                               //密码
}Admin;

//用户
 typedef struct user {
	char id[N];                                    //用户名
	char password[N];                              //密码
	struct voto* ticket[N];                        //用户购买的票的地址
	int sum;                                       //用户购买的票数
}user;

 //门票
  typedef struct voto {
	 char name[N];                                //名称
	 char year[N];
	 char month[N];
	 char days[N];
	 char start[N];                               //场次
	 char Ticket[N];                              //票档
	 double price[N];                             //价格
	 int num[N];                                  //数量
	 int id[N];                                   //编号
	 char seat[N];                                //座位
	 bool flag ;                           //记录票是否被售出
 }voto;

  FILE* Admin_file;
  FILE* user_file;                                
  FILE* voto_file;

  Admin AdminList[size];                          //管理员列表
  user UserList[size];                            //用户列表
  voto VotoList[size];                            //门票列表

  void read_information();                        //读取信息
  void user_register();                           //用户注册
  void user_long_on();                            //用户登录
 