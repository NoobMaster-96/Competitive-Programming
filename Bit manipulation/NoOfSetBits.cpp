#include<bits/stdc++.h>
using namespace std;

int NoOfSetBits(int n){
	int ans = 0;
	while(n != 0){
		ans += (n&1);
		n = n>>1;
	}
	return ans;
}

int countbits(int n){
	int ans = 0;
	while(n != 0){
		n = n & (n-1);
		ans++;
	}
	return ans;
}
int main(){
	int n = 13; 
	cout<<NoOfSetBits(n)<<endl;
	cout<<countbits(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;
}