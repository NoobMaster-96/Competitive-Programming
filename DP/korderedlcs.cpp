#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> seq1(2001);
vector<int> seq2(2001);
int dp[2001][2001][6];

int korderedlcs(int i, int j, int k){
	if(i==n || j==m){
		return 0;
	}
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	int ans = 0;
	if(seq1[i]==seq2[j]){
		ans = 1 + korderedlcs(i+1,j+1,k);
	}
	else{
		if(k>0){
			ans = 1 + korderedlcs(i+1,j+1,k-1);
		}
		ans = max(ans,korderedlcs(i,j+1,k));
		ans = max(ans,korderedlcs(i+1,j,k));
	}
	dp[i][j][k] = ans;

	return dp[i][j][k];
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>seq1[i];
	}
	for(int i=0;i<m;i++){
		cin>>seq2[i];
	}

	int ans = korderedlcs(0, 0, k);
	cout<<ans<<endl;

	return 0;
}