#include<bits/stdc++.h>
using namespace std;

// given an array [5,1,2,1,2,3,5,7] find the 2 unique no which occur only ones and print in accending order.
void finduniqueno(vector<int> no, int n){
	int x = 0;
	for(int i=0; i<n; i++){
		x = x^no[i];
	}
	int i = 0;
	while(true){
		if((x>>i)&1 == 1){
			break;
		}
		i++;
	}
	int x_ = 0;
	for(int j=0; j<n; j++){
		if(((no[j]>>i)&1) == 1){
			x_ = x_^no[j];
		}
	}
	int y_ = x^x_;
	cout<<min(x_,y_)<<" "<<max(x_,y_)<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int> no(n);
	for(int i=0; i<n; i++){
		cin>>no[i];
	}
	finduniqueno(no,n);
}