#define _CRT_SECURE_NO_WARNINGS


////��һ����ҵ
//#include<iostream>
//using namespace std;
//double fac(double n) {
//	if (n < 0) {
//		cout << "input error!";
//		return -1;
//	}
//	else if (n <= 1&&n>=0) {
//		return 1;
//	}
//	else {
//		return fac(n - 1) * n;
//	}
//}
//int main() {
//	double a, b, c;
//	cout << "��ֱ�����a��b��c��ֵ�����ÿո����"<<endl;
//	cin >> a >> b >> c;
//	cout << "a!+b!+c!=" << fac(a) + fac(b) + fac(c);
//	return 0;
// }

////�ڶ�����ҵ
//#include<iostream>
//using namespace std;
// 
//double funcation(double x) {
//	if (x < 1) {
//		return x;
//	}
//	else if (x >= 1 && x < 10) {
//		return 2*x - 1;
//	}
//	else
//	{
//		return 3 * x - 1;
//	}
//}
//int main() {
//	double a;
//	cout << "������һ������"<<endl;
//	cin >> a;
//	cout << "f("<<a<<")=" << funcation(a);;
//	return 0;
//}

////��������ҵ
//#include<iostream>
//using namespace std;
//int main() {
//	double sum = 0;
//	double fac = 1;
//	for (int i = 1; i <=20; i++)
//	{
//		fac = fac * i;
//		sum = sum + fac;
//	}
//	cout << "1!+2!+3!+...+20!=" << sum;
//	return 0;
//}
//

////���Ĵ���ҵ
//#include<iostream>
//using namespace std;
//int main() {
//	int arr[3][3] = { 0 };
//	int i = 0, j = 0,sum=0;
//	cout << "���������Ԫ�أ�" << endl;
//	for (i=0; i < 3; i++) {
//		for (j=0; j < 3;j ++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	for (i=0; i < 3; i++) {
//		for (j=0; j < 3; j++)
//		{
//			if (i == j||i+j==2) {
//				sum = sum + arr[i][j];
//			}
//		}
//	}
//	cout << "�Խ���Ԫ��֮��Ϊ��" << sum;
//	return 0;
// }

////��6��
//#include<iostream>
//using namespace std;
//int main() {
//	int arr[10][10] = { 0 };
//	int i, j;
//	for (i = 0; i < 10; i++) {
//		for ( j = 0; j < i+1; j++)
//		{
//			if (i == 0 || i == j||j==0) {
//				arr[i][j] = 1;
//			}
//			else if (i > 1) {
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < 10; i++) {
//		for (j = 0; j < i + 1; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//class Teacher
//{
//public:
//	Teacher(string name1, int age1, string manl1, string adress1, string phone_num1, string title1);
//	void display();
//protected:
//	string name;
//	int age;
//	string manl;
//	string adress;
//	string phone_num;
//	string title;
//};
//
//Teacher::Teacher(string name1, int age1, string manl1, string adress1, string phone_num1, string title1) {
//	name = name1;
//	age = age1;
//	manl = manl1;
//	adress = adress1;
//	phone_num = phone_num1;
//	title = title1;
//}
//
//void Teacher::display() {
//	cout << name << endl;
//	cout << age << endl;
//	cout << manl << endl;
//	cout << adress << endl;
//	cout << phone_num << endl;
//	cout << title<< endl;
//}
//
//
//class Cadre
//{
//public:
//	Cadre(string name1, int age1, string manl1, string adress1, string phone_num1, string post);
//	void display();
//protected:
//	string name;
//	int age;
//	string manl;
//	string adress;
//	string phone_num;
//	string post;
//};
//
//Cadre::Cadre(string name1, int age1, string manl1, string adress1, string phone_num1, string post1)
//{
//	name = name1;
//	age = age1;
//	manl = manl1;
//	adress = adress1;
//	phone_num = phone_num1;
//	post = post1;
//}
//
//void Cadre::display() {
//	cout << name<<endl;
//	cout << age << endl;
//	cout << manl << endl;
//	cout << adress << endl;
//	cout << phone_num << endl;
//	cout<< post << endl;
//}
//
//
//class Teacher_Cadre :public Teacher, public Cadre
//{
//public:
//	Teacher_Cadre (string name1, int age1, string manl1, string adress1, string phone_num1, string title1,string post1,double wages1) : 
//		Teacher(name1,age1,manl1,adress1,phone_num1,title1), Cadre(name1, age1, manl1, adress1, phone_num1,post1) {wages=wages1;};
//	void show();
//protected:
//	double wages;
//};
//
//void Teacher_Cadre::show(){
//	Teacher::display();
//	cout << post << endl;
//	cout << wages << endl;
//}
//
//int main() {
//	Teacher_Cadre hunman("����", 30, "��", "������ĳ�ֵ�", "123456789", "��ʦ", "����������", 8000.0);
//	hunman.show();
//	return 0;
//}