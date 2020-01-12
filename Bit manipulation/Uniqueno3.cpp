#include<bits/stdc++.h>
using namespace std;

// find the one unique no present in the array rest nos are present 3 times for ex [1,1,1,3,3,3,2]

int main(){
	int n,no;
	cin>>n;
	int cnt[64] = {0};
	for(int i=0; i<n; i++){
		cin>>no;
		// update cnt array
		int j = 0;
		while(no>0){
			int bit = (no&1);
			cnt[j] += bit;
			no = no>>1;
			j++;
		}
	}
	int ans = 0;
	for(int i=0; i<64; i++){
		if(cnt[i]%3 == 1){
			ans = ans|(1<<i);
		}
	}
	cout<<ans;
}