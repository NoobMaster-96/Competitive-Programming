#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> A(n);
	vector<int> pos(n+1,-1);
	for(int i=0;i<n;i++){
		cin>>A[i];
		pos[A[i]] = i;
	}
	int swaps=0;
	for(int i=n;i>0;i--){
		if(pos[i] != n-i){
			int idx = pos[i];
			pos[i] = n-i;
			pos[A[n-i]] = idx;
			A[idx] = A[n-i];
			A[n-i] = i;
			swaps++;
		}
		if(swaps == k){
			break;
		}
	}
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}