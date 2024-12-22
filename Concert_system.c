#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#include<conio.h>
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
void saveData(); //���ݱ���
void loadData();//���ݼ���
void registerUser();//�û�ע��
int userLogin();//�û���¼
void registerAdmin();//����Աע��
int adminLogin();//����Ա��¼
void addConcert();//����ݳ�����Ŀ
void deleteConcert();//ɾ���ݳ�����Ŀ
void searchConcert();//�����ݳ�����Ŀ
void modifyConcert();//�޸��ݳ�����Ŀ
void buyTicket();//������Ʊ
void userMenu();//�û��˵�
void adminMenu();//����Ա�˵�
void filterConcertsByDate(const char* startDate, const char* endDate);//������ɸѡ�ݳ���
void filterConcertsByPerformer(const char* performerName);//��������ɸѡ�ݳ���
void viewPurchasedTickets(const char* username);//�û���ѯ�ѹ�����ݳ�����Ʊ����






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



// ȫ������ͷָ�붨��
User* userList = NULL;
Admin* adminList = NULL;
Concert* concertList = NULL;
Ticket* ticketList = NULL;

// �������ݵ��ļ�
void saveData() {
    FILE* userFile = fopen("users.txt", "w");
    User* user = userList;
    while (user != NULL) {
        fprintf(userFile, "%s %s\n", user->username, user->password);
        user = user->next;
    }
    fclose(userFile);

    FILE* adminFile = fopen("admins.txt", "w");
    Admin* admin = adminList;
    while (admin != NULL) {
        fprintf(adminFile, "%s %s\n", admin->username, admin->password);
        admin = admin->next;
    }
    fclose(adminFile);

    FILE* concertFile = fopen("concerts.txt", "w");
    Concert* concert = concertList;
    while (concert != NULL) {
        fprintf(concertFile, "%s %s %s %s\n", concert->name, concert->performer,
            concert->venue, concert->date);
        concert = concert->next;
    }
    fclose(concertFile);

    FILE* ticketFile = fopen("tickets.txt", "w");
    Ticket* ticket = ticketList;
    while (ticket != NULL) {
        fprintf(ticketFile, "%s %s\n", ticket->username, ticket->concertName);
        ticket = ticket->next;
    }
    fclose(ticketFile);
}

// ���ļ���������
void loadData() {
    FILE* userFile = fopen("users.txt", "r");
    if (userFile != NULL) {
        char username[User_length];
        char password[Password_length];
        while (fscanf(userFile, "%s %s", username, password) == 2) {
            User* newUser = (User*)malloc(sizeof(User));
            strcpy(newUser->username, username);
            strcpy(newUser->password, password);
            newUser->next = userList;
            userList = newUser;
        }
        fclose(userFile);
    }

    FILE* adminFile = fopen("admins.txt", "r");
    if (adminFile != NULL) {
        char username[User_length];
        char password[Password_length];
        while (fscanf(adminFile, "%s %s", username, password) == 2) {
            Admin* newAdmin = (Admin*)malloc(sizeof(Admin));
            strcpy(newAdmin->username, username);
            strcpy(newAdmin->password, password);
            newAdmin->next = adminList;
            adminList = newAdmin;
        }
        fclose(adminFile);
    }

    FILE* concertFile = fopen("concerts.txt", "r");
    if (concertFile != NULL) {
        char name[Concert_length];
        char performer[Concert_length];
        char venue[Concert_length];
        char date[Concert_length];
        while (fscanf(concertFile, "%s %s %s %s", name, performer, venue,
            date) == 4) {
            Concert* newConcert = (Concert*)malloc(sizeof(Concert));
            strcpy(newConcert->name, name);
            strcpy(newConcert->performer, performer);
            strcpy(newConcert->venue, venue);
            strcpy(newConcert->date, date);
            newConcert->next = concertList;
            concertList = newConcert;
        }
        fclose(concertFile);
    }

    FILE* ticketFile = fopen("tickets.txt", "r");
    if (ticketFile != NULL) {
        char username[User_length];
        char concertName[Concert_length];
        while (fscanf(ticketFile, "%s %s", username, concertName) == 2) {
            Ticket* newTicket = (Ticket*)malloc(sizeof(Ticket));
            strcpy(newTicket->username, username);
            strcpy(newTicket->concertName, concertName);
            newTicket->next = ticketList;
            ticketList = newTicket;
        }
        fclose(ticketFile);
    }
}

// ע���û�
void registerUser() {
    User* newUser = (User*)malloc(sizeof(User));
    printf("�������û�����");
    scanf("%s", newUser->username);
    printf("���������룺");
    scanf("%s", newUser->password);
    newUser->next = userList;
    userList = newUser;
    printf("ע��ɹ���\n");
    Sleep(3000);
    saveData();
}

// �û���¼
int userLogin() {

    char username[User_length];
    char password[Password_length];
    printf("�������û�����");
    scanf("%s", username);
    printf("���������룺");
    char c;
    int i = 0;
    while ((c = getch()) != '\r')
    {
        if (c == '\b')
        {
            i--;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
        else
        {
            password[i] = c;
            i++;
            putchar('*');
        }
    }
    printf("\n");
    password[i] = '\0';
    User* current = userList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 &&
            strcmp(current->password, password) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// ע�����Ա
void registerAdmin() {
    Admin* newAdmin = (Admin*)malloc(sizeof(Admin));
    printf("�������û�����");
    scanf("%s", newAdmin->username);
    printf("���������룺");
    scanf("%s", newAdmin->password);
    newAdmin->next = adminList;
    adminList = newAdmin;
    printf("����Աע��ɹ���\n");
    Sleep(3000);
    saveData();
}

// ����Ա��¼
int adminLogin() {
    char username[User_length];
    char password[Password_length];
    printf("�������û�����");
    scanf("%s", username);
    printf("���������룺");
    char c;
    int i = 0;
    while ((c = getch()) != '\r')
    {
        if (c == '\b')
        {
            i--;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
        else
        {
            password[i] = c;
            i++;
            putchar('*');
        }
    }
    printf("\n");
    password[i] = '\0';
    Admin* current = adminList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 &&
            strcmp(current->password, password) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// ����ݳ�����Ŀ
void addConcert() {
    Concert* newConcert = (Concert*)malloc(sizeof(Concert));
    printf("�������ݳ������ƣ�");
    scanf("%s", newConcert->name);
    printf("����������ߣ�");
    scanf("%s", newConcert->performer); 
    printf("�����볡�أ�");
    scanf("%s", newConcert->venue);
    printf("���������ڣ�");
    scanf("%s", newConcert->date);
    newConcert->next = concertList;
    concertList = newConcert;
    printf("�ݳ�����Ŀ��ӳɹ���\n");
    Sleep(3000);
}

// ɾ���ݳ�����Ŀ
void deleteConcert() {
    char concertName[Concert_length];
    printf("������Ҫɾ���ݳ������ƣ�");
    scanf("%s", concertName);
    Concert* prev = NULL;
    Concert* current = concertList;
    while (current != NULL) {
        if (strcmp(current->name, concertName) == 0) {
            if (prev == NULL) {
                concertList = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("�ݳ�����Ŀɾ���ɹ���\n");
            Sleep(3000);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("δ�ҵ���Ӧ���ݳ�����Ŀ��ɾ��ʧ�ܣ�\n");
    Sleep(3000);
}

// ��ѯ�ݳ�����Ŀ
void searchConcert() {
    char keyword[Concert_length];
    printf("��������ҵ��ݳ������ƣ�");
    scanf("%s", keyword);
    Concert* current = concertList;
    while (current != NULL) {
        if (strstr(current->name, keyword) != NULL ||
            strstr(current->performer, keyword) != NULL ||
            strstr(current->venue, keyword) != NULL ||
            strstr(current->date, keyword) != NULL) {
            printf("����: %s��������: %s������: %s������: %s\n",
                current->name, current->performer,
                current->venue, current->date);
            Sleep(3000);
        }
        current = current->next;
    }
    printf("δ�ҵ���Ӧ���ݳ�����Ŀ��\n");
    Sleep(3000);
}

// �޸��ݳ�����Ŀ
void modifyConcert() {
    char concertName[Concert_length];
    printf("������Ҫ�޸ĵ��ݳ������ƣ�");
    scanf("%s", concertName);
    Concert* current = concertList;
    while (current != NULL) {
        if (strcmp(current->name, concertName) == 0) {
            printf("����: %s��������: %s������: %s������: %s\n",
                current->name, current->performer,
                current->venue, current->date);
            printf("����������ߣ�");
            scanf("%s", current->performer);
            printf("�����볡�أ�");
            scanf("%s", current->venue);
            printf("���������ڣ�");
            scanf("%s", current->date);
            printf("�ݳ�����Ŀ�޸ĳɹ���\n");
            Sleep(3000);
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ���Ӧ���ݳ�����Ŀ���޸�ʧ�ܣ�\n");
    Sleep(3000);
}

// ������Ʊ
void buyTicket() {
    char username[User_length];
    char concertName[Concert_length];
    printf("�������û�����");
    scanf("%s", username);
    printf("�������ݳ������ƣ�");
    scanf("%s", concertName);
    User* user = userList;
    while (user != NULL) {
        if (strcmp(user->username, username) == 0) {
            break;
        }
        user = user->next;
    }
    if (user == NULL) {
        printf("�û������ڣ���Ʊʧ�ܣ�\n");
        Sleep(3000);
        return;
    }
    Concert* concert = concertList;
    while (concert != NULL) {
        if (strcmp(concert->name, concertName) == 0) {
            break;
        }
        concert = concert->next;
    }
    if (concert == NULL) {
        printf("�ݳ��᲻���ڣ���Ʊʧ�ܣ�\n");
        Sleep(3000);
        return;
    }
    Ticket* newTicket = (Ticket*)malloc(sizeof(Ticket));
    strcpy(newTicket->username, username);
    strcpy(newTicket->concertName, concertName);
    newTicket->next = ticketList;
    ticketList = newTicket;
    printf("��Ʊ�ɹ���\n");
    Sleep(3000);
}

// ������ɸѡ�ݳ���
void filterConcertsByDate(const char* startDate, const char* endDate) {
    Concert* current = concertList;
    while (current != NULL) {
        if ((strcmp(current->date, startDate) >= 0) && (strcmp(current->date, endDate) <= 0)) {
            printf("����: %s��������: %s������: %s������: %s\n",
                current->name, current->performer,
                current->venue, current->date);
        }
        current = current->next;
    }  
    Sleep(3000);
}

// ��������ɸѡ�ݳ���
void filterConcertsByPerformer(const char* performerName) {
    Concert* current = concertList;
    while (current != NULL) {
        if (strstr(current->performer, performerName) != NULL) {
            printf("����: %s��������: %s������: %s������: %s\n",
                current->name, current->performer,
                current->venue, current->date);
            Sleep(3000);
        }
        current = current->next;
    }
}

// �û���ѯ�ѹ�����ݳ�����Ʊ����
void viewPurchasedTickets(const char* username) {
    Ticket* current = ticketList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            Concert* concert = concertList;
            while (concert != NULL) {
                if (strcmp(concert->name, current->concertName) == 0) {
                    printf("�ݳ�������: %s��������: %s������: %s������: %s\n",
                        concert->name, concert->performer,
                        concert->venue, concert->date);
                    Sleep(3000);
                    break;
                }
                concert = concert->next;
            }
        }
        current = current->next;
    }
}

// ��ʾ�û��˵�
void userMenu() {
   
    int choice;
    char startDate[Concert_length];
    char endDate[Concert_length];
    char performerName[Concert_length];
    char username[User_length];
    while (1) { 
        system("cls");
        printf("=====�û��˵�=====\n");
        printf("1.\t��ѯ�ݳ�����Ŀ\n");
        printf("2.\t������Ʊ\n");
        printf("3.\t������ɸѡ�ݳ���\n");
        printf("4.\t��������ɸѡ�ݳ���\n");
        printf("5.\t��ѯ�ѹ������Ʊ\n");
        printf("6.\t�˳�ϵͳ\n");
        printf("���������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            searchConcert();
            Sleep(1000);
            break;
        case 2:
            buyTicket();
            Sleep(1000);
            break;
        case 3:
            printf("�밴 ��/��/�� ��ʽ�����뿪ʼ���ڣ�");
            scanf("%s", startDate);
            printf("�밴 ��/��/�� ��ʽ������������ڣ�");
            scanf("%s", endDate);
            filterConcertsByDate(startDate, endDate);
            Sleep(1000);
            break;
        case 4:
            printf("����������ߣ�");
            scanf("%s", performerName);
            filterConcertsByPerformer(performerName);
            Sleep(1000);
            break;
        case 5:
            printf("�������û�����");
            scanf("%s", username);
            viewPurchasedTickets(username);
            Sleep(1000);
            break;
        case 6:
            saveData();
            printf("��лʹ�ã����˳�ϵͳ��\n");
            Sleep(1000);
            exit(0);
        default:
            printf("��Ч��ѡ�����������룡\n");
            Sleep(1000);
        }
    }
}

// ��ʾ����Ա�˵�
void adminMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("=====����Ա�˵�=====\n");
        printf("1. ����ݳ�����Ŀ\n");
        printf("2. ɾ���ݳ�����Ŀ\n");
        printf("3. ��ѯ�ݳ�����Ŀ\n");
        printf("4. �޸��ݳ�����Ŀ\n");
        printf("5. �˳�ϵͳ\n");
        printf("���������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addConcert();
            break;
        case 2:
            deleteConcert();
            break;
        case 3:
            searchConcert();
            break;
        case 4:
            modifyConcert();
            break;
        case 5:
            saveData();
            printf("��лʹ�ã����˳�ϵͳ��\n");
            Sleep(1000);
            exit(0);
        default:
            printf("��Ч��ѡ�����������룡\n");
            Sleep(1000);
        }
    }
}


