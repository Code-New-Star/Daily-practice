#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int count=0;
	int num=0;
	string str="";
	for(int i=1;i<=5;i++){
		cin>>num;
		str=to_string(num);
		if(str[0]==str[2]&&str[3]-str[1]==1){
			count++;
		}
	}
	cout<<count;
	return 0;
}
