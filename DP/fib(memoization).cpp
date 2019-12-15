#include<bits/stdc++.h>
using namespace std;

vector<int> memo(1000,-1);

int fib(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}

	if(memo[n] != -1){
		return memo[n];
	}

	int ans = fib(n-1) + fib(n-2);
	memo[n] = ans;
	return ans;
}

int main(){
	int n;
	cin>>n;
	int ans = fib(n);
	cout<<n<<"th fibonacci number is : "<<ans<<endl;
}