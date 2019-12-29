#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
	return(n&1);
}

int getBit(int n, int i){            //returns ith bit of a number
	int a = (1<<i);
	int bit = (n&a)>0 ? 1:0;

	return bit;
}

int setBit(int n, int i){          //set the ith bit of a num to 1
	int a = (1<<i);
	n = (n|a);

	return n;
}

int main(){
	int n;
	cin>>n;
	cout<<isOdd(n);
}