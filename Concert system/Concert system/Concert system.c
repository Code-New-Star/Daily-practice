#define _CRT_SECURE_NO_WARNINGS
#include"Concert system.h"
void user_register() {
	system("cls");
	user new_user;
	user_file = fopen("user_information.txt", "a+");
	printf("�����������û�����");
	scanf("%s",new_user.id);
	printf("�������������룺");
	scanf("%s",new_user.password);
	fprintf(user_file, "�û�����%s ���룺%s", new_user.id, new_user.password);
	user_long_on();
}

void read_information() {

}
void user_long_on() {
	system("cls");
	char temp_id[N];
	char temp_password[N];
	printf("�����������û�����");
	scanf("%s", temp_id);
	printf("�������������룺");
	scanf("%s", temp_password);
	
}
