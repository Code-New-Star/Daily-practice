#define _CRT_SECURE_NO_WARNINGS
#include "concert_system.h"

// 全局链表头指针定义
User* userList = NULL;
Admin* adminList = NULL;
Concert* concertList = NULL;
Ticket* ticketList = NULL;

// 保存数据到文件
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

// 从文件加载数据
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

// 注册用户
void registerUser() {
    User* newUser = (User*)malloc(sizeof(User));
    printf("请输入用户名：");
    scanf("%s", newUser->username);
    printf("请输入密码：");
    scanf("%s", newUser->password);
    newUser->next = userList;
    userList = newUser;
    printf("注册成功！\n");
    saveData();
}

// 用户登录
int userLogin() {

    char username[User_length];
    char password[Password_length];
    printf("请输入用户名：");
    scanf("%s", username);
    printf("请输入密码：");
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

// 注册管理员
void registerAdmin() {
    system("cls");
    Admin* newAdmin = (Admin*)malloc(sizeof(Admin));
    printf("请输入用户名：");
    scanf("%s", newAdmin->username);
    printf("请输入密码：");
    scanf("%s", newAdmin->password);
    newAdmin->next = adminList;
    adminList = newAdmin;
    printf("管理员注册成功！\n");
    saveData();
}

// 管理员登录
int adminLogin() {
    char username[User_length];
    char password[Password_length];
    printf("请输入用户名：");
    scanf("%s", username);
    printf("请输入密码：");
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

// 添加演唱会项目
void addConcert() {
    Concert* newConcert = (Concert*)malloc(sizeof(Concert));
    printf("请输入演唱会名称：");
    scanf("%s", newConcert->name);
    printf("\n");
    printf("请输入表演者：");
    scanf("%s", newConcert->performer); 
    printf("\n");
    printf("请输入场地：");
    scanf("%s", newConcert->venue);
    printf("\n");
    printf("请输入日期：");
    printf("\n");
    scanf("%s", newConcert->date);
    newConcert->next = concertList;
    concertList = newConcert;
    printf("演唱会项目添加成功！\n");
}

// 删除演唱会项目
void deleteConcert() {
    char concertName[Concert_length];
    printf("请输入要删除演唱会名称：");
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
            printf("演唱会项目删除成功！\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("未找到对应的演唱会项目，删除失败！\n");
}

// 查询演唱会项目
void searchConcert() {
    char keyword[Concert_length];
    printf("请输入查找的演唱会名称：");
    scanf("%s", keyword);
    Concert* current = concertList;
    while (current != NULL) {
        if (strstr(current->name, keyword) != NULL ||
            strstr(current->performer, keyword) != NULL ||
            strstr(current->venue, keyword) != NULL ||
            strstr(current->date, keyword) != NULL) {
            printf("名称: %s，表演者: %s，场地: %s，日期: %s\n",
                current->name, current->performer,
                current->venue, current->date);
        }
        current = current->next;
    }
    printf("未找到对应的演唱会项目！\n");
}

// 修改演唱会项目
void modifyConcert() {
    char concertName[Concert_length];
    scanf("%s", concertName);
    Concert* current = concertList;
    while (current != NULL) {
        if (strcmp(current->name, concertName) == 0) {
            scanf("%s", current->performer);
            scanf("%s", current->venue);
            scanf("%s", current->date);
            printf("演唱会项目修改成功！\n");
            return;
        }
        current = current->next;
    }
    printf("未找到对应的演唱会项目，修改失败！\n");
}

// 购买门票
void buyTicket() {
    char username[User_length];
    char concertName[Concert_length];
    printf("请输入用户名：");
    scanf("%s", username);
    printf("请输入演唱会名称：");
    scanf("%s", concertName);
    User* user = userList;
    while (user != NULL) {
        if (strcmp(user->username, username) == 0) {
            break;
        }
        user = user->next;
    }
    if (user == NULL) {
        printf("用户不存在，购票失败！\n");
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
        printf("演唱会不存在，购票失败！\n");
        return;
    }
    Ticket* newTicket = (Ticket*)malloc(sizeof(Ticket));
    strcpy(newTicket->username, username);
    strcpy(newTicket->concertName, concertName);
    newTicket->next = ticketList;
    ticketList = newTicket;
    printf("购票成功！\n");
}

// 按日期筛选演唱会
void filterConcertsByDate(const char* startDate, const char* endDate) {
    Concert* current = concertList;
    while (current != NULL) {
        if ((strcmp(current->date, startDate) >= 0) && (strcmp(current->date, endDate) <= 0)) {
            printf("名称: %s，表演者: %s，场地: %s，日期: %s\n",
                current->name, current->performer,
                current->venue, current->date);
        }
        current = current->next;
    }
}

// 按表演者筛选演唱会
void filterConcertsByPerformer(const char* performerName) {
    Concert* current = concertList;
    while (current != NULL) {
        if (strstr(current->performer, performerName) != NULL) {
            printf("名称: %s，表演者: %s，场地: %s，日期: %s\n",
                current->name, current->performer,
                current->venue, current->date);
        }
        current = current->next;
    }
}

// 用户查询已购买的演唱会门票功能
void viewPurchasedTickets(const char* username) {
    Ticket* current = ticketList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            Concert* concert = concertList;
            while (concert != NULL) {
                if (strcmp(concert->name, current->concertName) == 0) {
                    printf("演唱会名称: %s，表演者: %s，场地: %s，日期: %s\n",
                        concert->name, concert->performer,
                        concert->venue, concert->date);
                    break;
                }
                concert = concert->next;
            }
        }
        current = current->next;
    }
}

// 显示用户菜单
void userMenu() {
   
    int choice;
    char startDate[Concert_length];
    char endDate[Concert_length];
    char performerName[Concert_length];
    char username[User_length];
    while (1) { 
        system("cls");
        printf("=====用户菜单=====\n");
        printf("1.\t查询演唱会项目\n");
        printf("2.\t购买门票\n");
        printf("3.\t按日期筛选演唱会\n");
        printf("4.\t按表演者筛选演唱会\n");
        printf("5.\t查询已购买的门票\n");
        printf("6.\t退出系统\n");
        printf("请输入你的选择: ");
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
            scanf("%s", startDate);
            scanf("%s", endDate);
            filterConcertsByDate(startDate, endDate);
            Sleep(1000);
            break;
        case 4:
            scanf("%s", performerName);
            filterConcertsByPerformer(performerName);
            Sleep(1000);
            break;
        case 5:
            scanf("%s", username);
            viewPurchasedTickets(username);
            Sleep(1000);
            break;
        case 6:
            saveData();
            printf("感谢使用，已退出系统！\n");
            Sleep(1000);
            exit(0);
        default:
            printf("无效的选择，请重新输入！\n");
            Sleep(1000);
        }
    }
}

// 显示管理员菜单
void adminMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("=====管理员菜单=====\n");
        printf("1. 添加演唱会项目\n");
        printf("2. 删除演唱会项目\n");
        printf("3. 查询演唱会项目\n");
        printf("4. 修改演唱会项目\n");
        printf("5. 退出系统\n");
        printf("请输入你的选择: ");
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
            printf("感谢使用，已退出系统！\n");
            Sleep(1000);
            exit(0);
        default:
            printf("无效的选择，请重新输入！\n");
            Sleep(1000);
        }
    }
}