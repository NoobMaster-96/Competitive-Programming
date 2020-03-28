#include<bits/stdc++.h>
using namespace std;

int main(){
	int q,k;
	cin>>q>>k;
	priority_queue <long long int> pq;
	for(int i=0;i<k;i++){
		long long int a,x,y;
		cin>>a>>x>>y;
		long long int dist = pow(x,2) + pow(y,2);
		pq.push(dist);
	}
	for(int i=0;i<q-k;i++){
		int a;
		cin>>a;
		if(a==2){
			cout<<pq.top()<<endl;
		}
		else{
			long long int x,y;
			cin>>x>>y;
			long long int dist = pow(x,2) + pow(y,2);
			pq.push(dist);
			pq.pop();
		}
	}
}