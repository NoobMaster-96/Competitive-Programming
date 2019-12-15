#include<bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
vector<int> memo(10000,-1);

int reduceto1(int n){
	if(n == 1){
		return 0;
	}
	int q1 = inf, q2 = inf, q3 = inf;
	if(memo[n] != -1){
		return memo[n];
	}
	if(n % 3 == 0){
		q1 = 1 + reduceto1(n/3); 
	}
	if(n % 2 == 0){
		q2 = 1 + reduceto1(n/2);
	}
	q3 = 1 + reduceto1(n-1);
	memo[n] = min(q1,min(q2,q3)); //memoization
	return memo[n];
}

int reduceto1DP(int n){
	vector<int> dp(10000,-1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for(int currnum = 4;currnum <= n; currnum++){ // bottom up approach
		int q1 = inf, q2 = inf, q3 = inf;
		if(currnum % 3 == 0){
			q1 = 1 + dp[currnum/3];
		}
		if(currnum % 2 == 0){
			q2 = 1 + dp[currnum/2];
		}
		q3 = 1 + dp[currnum - 1];

		dp[currnum] = min(q1,min(q2,q3));
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	int ans = reduceto1DP(n);
	cout<<"Minimun steps from "<<n<<" to 1 is "<<ans;
	return 0;
}