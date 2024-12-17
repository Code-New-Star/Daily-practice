#define _CRT_SECURE_NO_WARNINGS
#include"Concert system.h"
void user_register() {
	system("cls");
	user new_user;
	user_file = fopen("user_information.txt", "a+");
	printf("请输入您的用户名：");
	scanf("%s",new_user.id);
	printf("请输入您的密码：");
	scanf("%s",new_user.password);
	fprintf(user_file, "用户名：%s 密码：%s", new_user.id, new_user.password);
	user_long_on();
}

void read_information() {

}
void user_long_on() {
	system("cls");
	char temp_id[N];
	char temp_password[N];
	printf("请输入您的用户名：");
	scanf("%s", temp_id);
	printf("请输入您的密码：");
	scanf("%s", temp_password);
	
}
