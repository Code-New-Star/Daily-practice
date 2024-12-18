#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct a {

	char name[100]; //��Ӱ��
	int grade; //����
	int number;  //һ�쳡��
	int time;  //��Ӱʱ��
	int	hall; //չ����
	double price;  //Ʊ��
	char timeline[100][100]; //ʱ���

	struct a* next;
}Cinema, * List;

List head = NULL;

int  Login();    // ��½
void Menu();      //   ���˵�
int Choose();    //  ѡ����
void Creathead(); // ����ͷ���
void Reload();     //  ���뱾���ļ�

void Search();      //  ���ҵ�Ӱ
void Creat();       //  �½���Ӱ����
void Delete();     //  ɾ����Ӱ
void DeleteAll();   // ɾ������
void Modify();     //  �޸ĵ�Ӱ����
void Sort();      // ����
void Changedata(List p);   // �����е����ݽ���
void DisplayAll();  //  ��ʾ���е�Ӱ
void Save();       //  ����

int main()
{
	if (Login() == 0) return 0;
	Creathead();
	Reload();
	while (1)
	{
		Menu();
		switch (Choose())
		{
		case 1:
			Creat(); break;
		case 2:
			Delete(); break;
		case 3:
			Search(); break;
		case 4:
			Modify(); break;
		case 6:
			DisplayAll(); break;
		case 5:
			DeleteAll(); break;
		case 7:
			Sort(); break;
		case 8:
			Save(); break;
		case 0:
			return 0;
		}
	}
}

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
	printf("-----------------------------ӰԺ����ϵͳ--------------------------------\n");

	printf("\t1.��ӵ�Ӱ��Ϣ    2.ɾ��ĳ����Ӱ��Ϣ    3.����ĳ����Ӱ��Ϣ\n");

	printf("\t4.�޸ĵ�Ӱ��Ϣ    5.ɾ�����е�Ӱ��Ϣ    6.��ʾ���е�Ӱ��Ϣ\n");

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
	int number, time, hall, count = 0, grade;
	double price;
	char name[100];
	char timeline[100][100];
	List b = head;
	FILE* p = fopen("data.txt", "a+");

	while (fscanf(p, "%s%d%d%d%d%lf", name, &grade, &number, &time, &hall, &price) == 6)
	{

		List a = (List)malloc(sizeof(Cinema));
		b->next = a;

		a->grade = grade;
		a->price = price;
		a->time = time;
		a->hall = hall;
		a->number = number;
		strcpy(a->name, name);

		int i;
		for (i = 0; i < number; i++)
		{
			fscanf(p, "%s", timeline[i]);
			strcpy(a->timeline[i], timeline[i]);
		}

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
	List a = (List)malloc(sizeof(Cinema));

	a->price = 0;
	a->time = 0;
	a->hall = 0;
	a->number = 0;
	a->grade = 0;
	strcpy(a->name, "0");
	//	strcpy(a->timeline, "0");
	a->next = NULL;
	head = a;
}



void Creat()
{
	List a = (List)malloc(sizeof(Cinema));

	printf("�������Ӱ����  ");
	scanf("%s", a->name);
	printf("�������Ӱ���֣� ");
	scanf("%d", &a->grade);
	printf("�������Ӱʱ����(��λmin)  ");
	scanf("%d", &a->time);
	printf("����չ���ţ�  ");
	scanf("%d", &a->hall);
	printf("������Ʊ�ۣ�  ");
	scanf("%lf", &a->price);

	printf("������һ�칲������  ");
	scanf("%d", &a->number);
	printf("�������Ӱʱ��Σ�(xx:xx)  ");
	int i;
	for (i = 0; i < a->number; i++)
		scanf("%s", a->timeline[i]);

	a->next = NULL;
	List b = head;
	while (b->next != NULL)
		b = b->next;
	b->next = a;
	system("cls");
	printf("��ӳɹ�\n\n");
}

void Search()
{
	int flag = 1;
	List a, b;
	a = b = head->next;
	char name[100];
	printf("����Ҫ���ҵĵ�Ӱ��:");
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
		printf("��Ӱ��\t\t����\t\t����\t\tʱ��\t\tչ����\t\tƱ��\t\t��ӳʱ���\n");
		printf("---------------------------------------------------------");
		printf("---------------------------------------------------\n");

		printf("%*s\t%d\t\t%d\t\t%d\t\t%d\t\t%.2lf\t\t[1]%s\n", -10, a->name, a->grade, a->number, a->time, a->hall, a->price, a->timeline[0]);
		int i;
		for (i = 1; i < a->number; i++)
			printf("\t\t\t\t\t\t\t\t\t\t\t\t[%d]%s\n", i + 1, a->timeline[i]);
		printf("\n");
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
	List a = head, b = head;
	printf("����Ҫɾ���ĵ�Ӱ���� ");
	scanf("%s", name);
	while (strcmp(a->name, name))
	{
		b = a;
		a = b->next;
	}
	printf("ȷ��ɾ����Ӱ %s (y/n)", a->name);
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
	List a, b;
	a = b = head->next;
	while (a != NULL)
	{
		b = a->next;
		free(a);
		a = b;
	}
	head->next = NULL;
	remove("data");
}


void Modify()
{
	int flag = 0;
	char name[100], choose;
	List a = head->next, b = head;
	getchar();
	printf("����Ҫ�޸ĵĵ�Ӱ���� ");
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
		printf("��Ӱ��Ϊ %s �Ƿ��޸�(y/n)", a->name);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", a->name);
		}


		printf("��Ӱ����Ϊ %d �Ƿ��޸� (y/n)", a->grade);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &a->grade);
		}

		printf("��Ӱһ�쳡��Ϊ %d �Ƿ��޸�(y/n)", a->number);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &a->number);
		}

		printf("��Ӱʱ��Ϊ %dmin �Ƿ��޸�(y/n)", a->time);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &a->time);
		}

		printf("չ����Ϊ %d �Ƿ��޸�(y/n)", a->hall);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &a->hall);
		}

		printf("Ʊ��Ϊ %.2f �Ƿ��޸�(y/n)", a->price);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%f", &a->price);
		}

		printf("�޸����");
	}
	else
		printf("δ�ҵ�\n\n");
	getch();
	system("cls");
}



void DisplayAll()
{
	system("cls");
	List a, b;
	a = b = head->next;

	if (head->next == NULL)
	{
		printf("������");
		getchar();
		getchar();
		system("cls");
		return;
	}

	printf("��Ӱ��\t\t����\t\t����\t\tʱ��\t\tչ����\t\tƱ��\t\t��ӳʱ���\n");
	printf("---------------------------------------------------------");
	printf("---------------------------------------------------\n");

	while (a != NULL)
	{
		printf("%*s\t%d\t\t%d\t\t%d\t\t%d\t\t%.2lf\t\t[1]%s\n", -10, a->name, a->grade, a->number, a->time, a->hall, a->price, a->timeline[0]);
		int i;
		for (i = 1; i < a->number; i++)
			printf("\t\t\t\t\t\t\t\t\t\t\t\t[%d]%s\n", i + 1, a->timeline[i]);
		printf("\n");
		b = a;
		a = b->next;
	}
	getchar();
	getchar();
	system("cls");
}

void Sort()
{
	int a, b;
	printf("��ѡ�� 1.���� 2.���� ���� :");
	scanf("%d", &a);
	printf("��ѡ�� 1.���� 2.���� :");
	scanf("%d", &b);

	List p = head->next;
	List p1 = NULL;
	while (p != p1)
	{
		while (p->next != p1)
		{
			if (a == 1)
			{
				if (b == 1)
				{
					if (p->grade < p->next->grade)
					{
						Changedata(p);
					}
				}
				else if (b == 2)
				{
					if (p->grade > p->next->grade)
					{
						Changedata(p);
					}
				}
			}
			if (a == 2)
			{
				if (b == 1)
				{
					if (p->number < p->next->number)
					{
						Changedata(p);
					}
				}
				else if (b == 2)
				{
					if (p->number > p->next->number)
					{
						Changedata(p);
					}
				}
			}
			p = p->next;
		}
		p1 = p;
		p = head->next;
	}

	printf("����ɹ�\n\n");
	getch();
	system("cls");

}

void Changedata(List p)
{
	double ex1 = p->price;
	p->price = p->next->price;
	p->next->price = ex1;

	int ex2 = p->grade;
	p->grade = p->next->grade;
	p->next->grade = ex2;

	int ex4 = p->time;
	p->time = p->next->time;
	p->next->time = ex4;

	int ex5 = p->hall;
	p->hall = p->next->hall;
	p->next->hall = ex5;

	char temp[100];
	strcpy(temp, p->name);
	strcpy(p->name, p->next->name);
	strcpy(p->next->name, temp);

	char temp2[100][100];
	int i;
	for (i = 0; i < p->number; i++)
		strcpy(temp2[i], p->timeline[i]);
	for (i = 0; i < p->next->number; i++)
		strcpy(p->timeline[i], p->next->timeline[i]);
	for (i = 0; i < p->number; i++)
		strcpy(p->next->timeline[i], temp2[i]);

	int ex3 = p->number;
	p->number = p->next->number;
	p->next->number = ex3;
}

void Save()
{
	if (head->next == NULL)
	{
		printf("δ¼����Ϣ\n\n");
		return;
	}
	List a = head->next, b = head;

	FILE* p = fopen("data.txt", "w");
	while (a != NULL)
	{
		fprintf(p, "%s %d %d %d %d %.2lf ", a->name, a->grade, a->number, a->time, a->hall, a->price);
		int i;
		for (i = 0; i < a->number; i++)
			fprintf(p, "%s ", a->timeline[i]);
		fprintf(p, "\n");
		b = a;
		a = a->next;
	}
	fclose(p);

	printf("����ɹ�");
	getch();
	system("cls");
}
