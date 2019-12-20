#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a; i<=b; i++)
#define rloop(i,a,b)     for(int i=a; i>=b; i--)
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define lli              long long int
#define vlli             vector<lli>
#define vvlli            vector<vector<lli>>
#define pb               push_back
#define endl             "\n"

const int inf = (int)1e9;

int lcsubseq(string A, string B){
	int lena = A.length(), lenb = B.length();
	vvi dp(lena+1, vi(lenb+1,0));
	loop(i,1,lena){
		loop(j,1,lenb){
			if(A[i-1]==B[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	/*loop(i,0,lena){
		loop(j,0,lenb){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return dp[lena][lenb];
}

int main(){
	string A,B;
	cin>>A>>B;
	int ans = lcsubseq(A,B);
	cout<<ans<<endl;
}