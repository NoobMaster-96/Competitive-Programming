#include<bits/stdc++.h>
using namespace std;

int fastexpo(int a, int n){
	int ans = 1;
	while(n>0){
		int bit = (n&1);
		if(bit == 1){
			ans = ans*a;
		}
		a = a*a;
		n = n>>1;
	}
	return ans;
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<fastexpo(a,n);
	return 0;
}