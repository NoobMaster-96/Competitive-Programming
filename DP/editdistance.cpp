#include<bits/stdc++.h>
using namespace std;

int editdistance(string a, string b){
	int lena = a.length(), lenb = b.length();
	vector<vector<int>> dp(lena+1,vector<int>(lenb+1));
	dp[0][0] = 0;
	for(int i=1; i<=lena; i++){
		dp[i][0] = dp[i-1][0] + 1;
	}
	for(int i=1; i<=lenb; i++){
		dp[0][i] = dp[0][i-1] + 1;
	}

	for(int i=1; i<=lena; i++){
		for(int j=1; j<=lenb; j++){
			int q1 = dp[i-1][j-1];
			int q2 = dp[i-1][j];
			int q3 = dp[i][j-1];
			dp[i][j] = min(q1,min(q2,q3)) + (a[i-1] != b[j-1]);
		}
	}
	for(int i=0;i<=lena;i++){
		for(int j=0;j<=lenb;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[lena][lenb];
}

int main(){

	string a,b;
	cin>>a>>b;
	int ans = editdistance(a,b);
	cout<<ans<<endl;

	return 0;
}