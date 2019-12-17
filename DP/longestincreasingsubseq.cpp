#include<bits/stdc++.h>
using namespace std;

int longestsubseq(vector<int> seq, int n){
	vector<int> dp(n,1);
	int ans = 0;
	for(int i=1; i<n; i++){
		int best = 0;
		for(int j=0; j<i; j++){
			int local = 1;
			if(seq[j]<seq[i]){
				local = 1 + dp[j];
			}
			best = max(local,best);
		}
		dp[i] = best;
		ans = max(ans,best);
	}
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> seq(n);
	for(int i=0; i<n; i++){
		cin>>seq[i];
	}
	int ans = longestsubseq(seq,n);
	cout<<ans<<endl;
}