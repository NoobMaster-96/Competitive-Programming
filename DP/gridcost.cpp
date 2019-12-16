#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> grid, int n){

	vector<vector<int>> dp(n,vector<int>(n,0));
	dp[0][0] = grid[0][0];
	for(int i=1; i<n; i++){
		dp[0][i] = dp[0][i-1] + grid[0][i];
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}

	for(int i=1; i<n; i++){
		dp[i][i] = min(dp[i][i-1],dp[i-1][i]) + grid[i][i];
		for(int j=i+1; j<n; j++){
			dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
			dp[j][i] = min(dp[j-1][i],dp[j][i-1]) + grid[j][i];
		}
	}
	return dp[n-1][n-1];
}

int main(){
	// given a grid of n*n size find the min cost to reach bottom right cell from the first cell
	// we can only allowed to move right and down
	int n;
	cin>>n;
	vector<vector<int>> grid(n,vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	int ans = minCost(grid, n);
	cout<<ans<<endl;
}