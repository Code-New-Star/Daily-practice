#define _CRT_SECURE_NO_WARNINGS
#include "concert_system.h"

int main() {
   
    int choice=0;
    loadData();  // 加载之前保存的数据
    while (choice!=5) { 
        system("cls");
        printf("**************************************************************\n");
        printf("*                     演唱会售票系统                         *\n");
        printf("**************************************************************\n");
        printf("\n");
        printf("* [1] 用户注册.............................................. *\n");
        printf("* [2] 用户登录.............................................. *\n");
        printf("* [3] 管理员注册............................................ *\n");
        printf("* [4] 管理员登录............................................ *\n");
        printf("* [5] 退出系统.............................................. *\n");

        // 提示输入选择
        printf("\n请输入你的选择->___ ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (userLogin()) {
                userMenu();
            }
            else {
                printf("登录失败，请检查用户名和密码！\n");
                Sleep(1000);
            }
            break;
        case 3:
            registerAdmin();
            break;
        case 4:
            if (adminLogin()) {
                adminMenu();
            }
            else {
                printf("登录失败，请检查用户名和密码！\n");
                Sleep(1000);
            }
            break;
        case 5:
            saveData();
            printf("感谢使用，系统已退出！\n");
        }
    }
    return 0;
}