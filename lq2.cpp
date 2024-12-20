#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool check(string num, int n) {
	int i = 0;
	int temp = 0;
	for (i=0; i < n; i++) {
		temp = (int)num[i] - '0';
		if (i % 2 == 0 && temp % 2 != 1) {
			return false;
		}
		else if (i % 2 == 1 && temp % 2 != 0) {
			return false;
		}
	}
	return true;
}
int main() {
	long int N = 0, count = 0;
	string str_num = "";
	long int i = 0;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		str_num = to_string(i);
		reverse(str_num.begin(), str_num.end());
		if (check(str_num, str_num.size()))
			count++;
	}
	cout << count;
	return 0;
}
