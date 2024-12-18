#include"Concert system.h"
int Login()
{
	while (1)
	{
		printf("----------------------------------------------------------\n");
		printf("*                                                        *\n");
		printf("*                       1���û���¼                      *\n");
		printf("*                       2���û�ע��                      *\n");
		printf("*                                                        *\n");
		printf("----------------------------------------------------------\n");
		int choose;
		char fusername[100], fpassword[100];
		char username[100], password[100];
		scanf("%d", &choose);



		if (choose == 1)
		{
			FILE* f1 = fopen("user.txt", "r");
			printf("�������û�����");
			scanf("%s", username);
			getchar();
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

			fscanf(f1, "%s %s", fusername, fpassword);
			if ((strcmp(fusername, username) == 0) && (strcmp(fpassword, password)) == 0)
			{
				printf("��½�ɹ�\n");
				getch();
				system("cls");
				return 1;
			}
			else
			{
				printf("�û������������");
				getch();
				return 0;
			}
		}

		else if (choose == 2)
		{
			FILE* f2 = fopen("user.txt", "w");
			printf("�������û�����");
			scanf("%s", username);
			printf("���������룺");
			scanf("%s", password);
			fprintf(f2, "%s %s", username, password);
			fclose(f2);
			system("cls");
			printf("ע��ɹ���\n");
		}
	}
}

void Menu()
{
	printf("\n\n");
	printf("-----------------------------�ݳ������ϵͳ--------------------------------\n");

	printf("\t1.����ݳ�����Ϣ    2.ɾ��ĳ���ݳ�����Ϣ    3.����ĳ���ݳ�����Ϣ\n");

	printf("\t4.�޸��ݳ�����Ϣ    5.ɾ�������ݳ�����Ϣ    6.��ʾ�����ݳ�����Ϣ\n");

	printf("\t7.����            8.����                0.�˳�\n");

	printf("\n-------------------------------------------------------------------------\n");

}

int Choose() {
	int n;
	printf("���������:");
	while (scanf("%d", &n) != 1 || n < 0 || n>8)
	{
		printf("����������:");
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
	printf("�ɹ�����%d����Ϣ\n\n", count);
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

	printf("�������ݳ������ƣ�  ");
	scanf("%s", a->name);
	printf("�������ݳ���ص㣺 ");
	scanf("%s", a->location);
	printf("������Ʊ�ۣ�  ");
	scanf("%lf", &a->price);

	printf("�������ݳ��Ὺʼʱ�䣺xx��/xx��/xx��(xx:xx)  ");
	scanf("%s", a->time);
	

	a->next = NULL;
	ticket* b = List_head;
	while (b->next != NULL)
		b = b->next;
	b->next = a;
	system("cls");
	printf("��ӳɹ�\n\n");
}

void Search()
{
	int flag = 1;
	ticket* a, * b;
	a = b = List_head->next;
	char name[100];
	printf("����Ҫ���ҵ��ݳ�����:");
	scanf("%s", name);
	printf("\n");
	while (strcmp(a->name, name))
	{
		b = a;
		a = b->next;
		if (a == NULL)
		{
			printf("����ʧ��\n\n");
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("�ݳ�����\t\t�ص�\t\tƱ��\t\t��ʼʱ��\n");
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
	printf("����Ҫɾ�����ݳ������� ");
	scanf("%s", name);
	while (strcmp(a->name, name))
	{
		b = a;
		a = b->next;
	}
	printf("ȷ��ɾ�����ݳ��� %s (y/n)", a->name);
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
	printf("����Ҫ�޸ĵ��ݳ������� ");
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
		printf("�ݳ�����Ϊ %s �Ƿ��޸�(y/n)", a->name);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", a->name);
		}


		printf("�ݳ���ص�Ϊ %s �Ƿ��޸� (y/n)", a->location);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", &a->location);
		}

		printf("Ʊ��Ϊ %.2f �Ƿ��޸�(y/n)", a->price);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%f", &a->price);
		}

		printf("�ݳ��Ὺʼʱ��Ϊ %s �Ƿ��޸�(y/n)", a->time);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &a->time);
		}
		printf("�޸����");
	}
	else
		printf("δ�ҵ�\n\n");
	getch();
	system("cls");
}

