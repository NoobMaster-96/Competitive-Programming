#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	vector<int> B(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		cin>>B[i];
	}
	int i=0,j=0;
	int med = 0;
	int ans;
	while(i<n && j<n){
		if(A[i]<B[j]){
			med++;
			if(med == n){
				ans = A[i];
				break;
			}
			i++;
		}
		else{
			med++;
			if(med == n){
				ans = B[j];
				break;
			}
			j++;
		}
	}
	cout<<ans<<endl;
}