#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<vector<int>> memo(100,vector<int>(100,-1));

int maxProfit(vector<int> price, int be, int en, int year){ //memoization
	cnt++;
	if(be > en){
		return 0;
	}
	if(memo[be][en] != -1){
		return memo[be][en];
	}
	int q1 = price[be]*year + maxProfit(price,be+1,en,year+1);
	int q2 = price[en]*year + maxProfit(price,be,en-1,year+1);
	memo[be][en] = max(q1,q2);
	return memo[be][en];
}

int maxProfitDP(vector<int> price, int n){
	vector<vector<int>> DP(n,vector<int>(n));
	int year = n;

	for(int i=0; i<n; i++){
		DP[i][i] = price[i]*year;
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; j<n-i; j++){
			int q1 = DP[j][j+i-1] + price[j+i]*(n-i);
			int q2 = DP[j+1][j+i] + price[j]*(n-i);
			DP[j][j+i] = max(q1,q2);
		}
	}
	return DP[0][n-1];
}
int main(){
	int n;
	cin>>n;
	vector<int> price(n,0);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	int ans = maxProfitDP(price,n);
	cout<< ans<<endl;
}