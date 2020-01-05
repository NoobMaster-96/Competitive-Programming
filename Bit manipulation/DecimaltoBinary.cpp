#include<bits/stdc++.h>
using namespace std;

int decimal2binary(int n){
	int ans = 0;
	int p = 1;
	while(n != 0){
		ans += p*(n&1);
		n = n>>1;
		p *= 10;
	}
	return ans;
}
int main(){
	int n = 15;
	cin>>n;
	cout<<decimal2binary(n);
}