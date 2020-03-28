#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int swaps = 0;
	for(int i=0;i<n;i++){
		int idx = -1;
		int ele = A[i];
		for(int j=i+1;j<n;j++){
			if(ele<A[j]){
				idx = j;
			}
		}
		if(idx != -1){
			int temp = A[i];
			A[i] = A[idx];
			A[idx] = temp;
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