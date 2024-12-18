#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<string.h>
#define N 100


//用户
 typedef struct user {
	char id[N];                                    //用户名
	char password[N];                              //密码                     
}user;

 typedef struct ticket {
	 char name[N];   
	 char location[N];
	 double price;
	 char time[N];

	  ticket* next;
 }ticket;

 ticket* List_head = NULL;

 int Login(); //登录
 void Menu(); //主菜单
 int Choose(); //选择功能
 void Creathead(); // 创建头结点
 void Reload();     //  载入本地文件

 void Search();      //  查找演唱会
 void Creat();       //  新建演唱会
 void Delete();     //  删除演唱会
 void DeleteAll();   // 删除所有
 void Modify();     //  修改演唱会数据
 void Sort();      // 排序
 void Changedata(ticket* p);   // 排序中的数据交换
 void DisplayAll();  //  显示所有演唱会
 void Save();       //  保存
