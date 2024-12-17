#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

void result(int num,int p) {
	string str = "";
	int temp = 0;
	while (num)
	{
		temp = num % p;
		num = num / p;
		if(temp<=9){
		str = str + to_string(temp);}
		else {
			str = str + char('A' + abs(10 - temp));
		}
	}
	reverse(str.begin(), str.end());
	cout <<"=" <<str<<" ";
}
int main() {
	int p = 0;
	cin >> p;
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 1; i <p ; i++)
	{
		for ( j = 1; j <=i; j++)
		{
			if (i <=9) {
				cout << i<<'*';
			}
			else {
				cout << char('A' +abs( 10 - i))<<'*';
			}
			if (j <= 9) {
				cout << j;
			}
			else {
				cout << char('A' +abs( 10 - j));
			}
			temp = i * j;
			result(temp,p);
		}
		cout << "\n";
	}
	return 0;
}