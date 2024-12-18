#include"Concert system.h"
int Login()
{
	while (1)
	{
		printf("----------------------------------------------------------\n");
		printf("*                                                        *\n");
		printf("*                       1：用户登录                      *\n");
		printf("*                       2：用户注册                      *\n");
		printf("*                                                        *\n");
		printf("----------------------------------------------------------\n");
		int choose;
		char fusername[100], fpassword[100];
		char username[100], password[100];
		scanf("%d", &choose);



		if (choose == 1)
		{
			FILE* f1 = fopen("user.txt", "r");
			printf("请输入用户名：");
			scanf("%s", username);
			getchar();
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

			fscanf(f1, "%s %s", fusername, fpassword);
			if ((strcmp(fusername, username) == 0) && (strcmp(fpassword, password)) == 0)
			{
				printf("登陆成功\n");
				getch();
				system("cls");
				return 1;
			}
			else
			{
				printf("用户名或密码错误");
				getch();
				return 0;
			}
		}

		else if (choose == 2)
		{
			FILE* f2 = fopen("user.txt", "w");
			printf("请输入用户名：");
			scanf("%s", username);
			printf("请输入密码：");
			scanf("%s", password);
			fprintf(f2, "%s %s", username, password);
			fclose(f2);
			system("cls");
			printf("注册成功！\n");
		}
	}
}

void Menu()
{
	printf("\n\n");
	printf("-----------------------------演唱会管理系统--------------------------------\n");

	printf("\t1.添加演唱会信息    2.删除某个演唱会信息    3.查找某个演唱会信息\n");

	printf("\t4.修改演唱会信息    5.删除所有演唱会信息    6.显示所有演唱会信息\n");

	printf("\t7.排序            8.保存                0.退出\n");

	printf("\n-------------------------------------------------------------------------\n");

}

int Choose() {
	int n;
	printf("请输入序号:");
	while (scanf("%d", &n) != 1 || n < 0 || n>8)
	{
		printf("请重新输入:");
		scanf("%d", &n);
	}
	return n;
}

void Reload()
{
	int  time,count = 0, grade;
	double price;
	char name[100];
	char location[100];
	char time[100];
	ticket* b = List_head;
	FILE* p = fopen("data.txt", "a+");

	while (fscanf(p, "%s%s%lf%s", name, location,&price,time) == 4)
	{

		ticket* a = (ticket*)malloc(sizeof(ticket));
		b->next = a;

		strcpy(a->name, name);
		strcpy(a->location, location);
		a->price = price;
		strcpy(a->time, time);

		

		b = b->next;
		count++;
	}
	if (count != 0)
		b->next = NULL;
	printf("成功载入%d条信息\n\n", count);
	fclose(p);
}

void Creathead()
{
	ticket* a = (ticket*)malloc(sizeof(ticket));

	a->price = 0;
	strcpy(a->name, " ");
	strcpy(a->location, " ");
	strcpy(a->time, " ");

	a->next = NULL;
	List_head = a;
}

void Creat()
{
	ticket*a = (ticket*)malloc(sizeof(ticket));

	printf("请输入演唱会名称：  ");
	scanf("%s", a->name);
	printf("请输入演唱会地点： ");
	scanf("%s", a->location);
	printf("请输入票价：  ");
	scanf("%lf", &a->price);

	printf("请输入演唱会开始时间：xx年/xx月/xx日(xx:xx)  ");
	scanf("%s", a->time);
	

	a->next = NULL;
	ticket* b = List_head;
	while (b->next != NULL)
		b = b->next;
	b->next = a;
	system("cls");
	printf("添加成功\n\n");
}

void Search()
{
	int flag = 1;
	ticket* a, * b;
	a = b = List_head->next;
	char name[100];
	printf("输入要查找的演唱会名:");
	scanf("%s", name);
	printf("\n");
	while (strcmp(a->name, name))
	{
		b = a;
		a = b->next;
		if (a == NULL)
		{
			printf("查找失败\n\n");
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("演唱会名\t\t地点\t\t票价\t\t开始时间\n");
		printf("------------------------------------");
		printf("------------------------------------\n");

		printf("%*s\t%s\t\t%.2lf\t\t%s\n", -10, a->name, a->location, a->price, a->time);
	}
	printf("\n\n");
	getchar();
	getchar();
	system("cls");
}

void Delete()
{
	char choose;
	char name[100];
	ticket* a = List_head, *b = List_head;
	printf("输入要删除的演唱会名： ");
	scanf("%s", name);
	while (strcmp(a->name, name))
	{
		b = a;
		a = b->next;
	}
	printf("确认删除该演唱会 %s (y/n)", a->name);
	getchar();
	scanf("%c", &choose);
	if (choose == 'y')
	{
		b->next = a->next;
		free(a);
	}
}

void DeleteAll()
{
	ticket* a, *b;
	a = b = List_head->next;
	while (a != NULL)
	{
		b = a->next;
		free(a);
		a = b;
	}
	List_head->next = NULL;
	remove("data");
}

void Modify()
{
	int flag = 0;
	char name[100], choose;
	ticket* a = List_head->next, *b = List_head;
	getchar();
	printf("输入要修改的演唱会名： ");
	scanf("%s", name);
	getchar();
	while (a != NULL)
	{
		if (strcmp(a->name, name) == 0)
		{
			flag = 1;
			break;
		}
		b = a;
		a = b->next;
	}
	if (flag)
	{
		printf("演唱会名为 %s 是否修改(y/n)", a->name);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", a->name);
		}


		printf("演唱会地点为 %s 是否修改 (y/n)", a->location);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", &a->location);
		}

		printf("票价为 %.2f 是否修改(y/n)", a->price);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%f", &a->price);
		}

		printf("演唱会开始时间为 %s 是否修改(y/n)", a->time);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%d", &a->time);
		}
		printf("修改完成");
	}
	else
		printf("未找到\n\n");
	getch();
	system("cls");
}

