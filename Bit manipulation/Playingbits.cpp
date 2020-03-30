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

int main(){
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans = 0;
		for(int i=l;i<=r;i++){
			ans += NoOfSetBits(i);
		}
		cout<<ans<<endl;
	}
}