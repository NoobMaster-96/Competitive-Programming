#include<bits/stdc++.h>
using namespace std;
vector<int> memo(10000,-1);
int cnt = 0;

int maxprofit(vector<int> price, int n){ // memoization
	cnt++;
	if(memo[n] != -1){
		return memo[n];
	}
	if(n==0){
		return 0;
	}
	int best = 0;
	for(int i=1; i<=n; i++){
		int profit = price[i] + maxprofit(price,n-i);
		best = max(best,profit);
	}
	memo[n] = best;
	return memo[n];
}

int maxprofitDP(vector<int> price, int n){ // DP bottom up

	vector<int> dp(n,0);
	for(int i=1; i<=n; i++){
		int best = 0;
		for(int j=1; j<=i; j++){
			best = max(price[j] + price[i-j],best);
		}
		dp[i] = best;
	}

	return dp[n];
}
int main(){
	// maximize the profit by selling a rod of length n
	// selling price of length 1-n of rod are given
	int n;
	cin>>n;
	vector<int> price(n+1,0);
	for(int i=1; i<=n; i++){
		cin>>price[i];
	}

	int ans = maxprofitDP(price, n);
	cout<<ans<<endl; 
}