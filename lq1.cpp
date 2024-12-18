#include<iostream>
using namespace std;
int main(){
long long a,b,n;
cin>>a>>b>>n;
long long c=5*a+2*b;
long long x=n/c;
long long ans=7*x;
n%=c;
for(int i=1;n>0;i++,ans++){
	if(i<=5){
		n-=a;
	}
	else n-=b;
}
cout<<ans;
return 0;
}
