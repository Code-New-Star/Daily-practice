#define _CRT_SECURE_NO_WARNINGS
#include "concert_system.h"

int main() {
   
    int choice=0;
    loadData();  // ����֮ǰ���������
    while (choice!=5) { 
        system("cls");
        printf("**************************************************************\n");
        printf("*                     �ݳ�����Ʊϵͳ                         *\n");
        printf("**************************************************************\n");
        printf("\n");
        printf("* [1] �û�ע��.............................................. *\n");
        printf("* [2] �û���¼.............................................. *\n");
        printf("* [3] ����Աע��............................................ *\n");
        printf("* [4] ����Ա��¼............................................ *\n");
        printf("* [5] �˳�ϵͳ.............................................. *\n");

        // ��ʾ����ѡ��
        printf("\n���������ѡ��->___ ");
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
                printf("��¼ʧ�ܣ������û��������룡\n");
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
                printf("��¼ʧ�ܣ������û��������룡\n");
                Sleep(1000);
            }
            break;
        case 5:
            saveData();
            printf("��лʹ�ã�ϵͳ���˳���\n");
        }
    }
    return 0;
}