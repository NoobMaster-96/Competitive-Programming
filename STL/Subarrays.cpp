#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	set<int> s;
	long long int ans = 0;
	int j=0;
	for(int i=0;i<n;i++){
		while(j<n && s.find(A[j]) == s.end()){
			s.insert(A[j]);
			j++;
		}
		long long int sum = (j-i)*(j-i+1)/2;
		ans += sum;
		s.erase(A[i]);
	}
	cout<<ans%1000000007<<endl;
}