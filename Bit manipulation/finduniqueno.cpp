#include<bits/stdc++.h>
using namespace std;
// given 2n+1 numbers find the unique val
int main(){
	int n;
	cin>>n;
	int ans = 0;
	int temp;
	for(int i=0;i<n*2+1;i++){
		cin>>temp;
		ans ^= temp;
	}
	cout<<ans<<endl;
}