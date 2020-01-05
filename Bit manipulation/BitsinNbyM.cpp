#include<bits/stdc++.h>
using namespace std;

int clearrangeofbits(int n, int i, int j){
	int mask = (-1<<j+1);
	int temp = ~(-1<<i);
	mask = mask|temp;

	return (n & mask);
}

int replaceBits(int n, int m, int i, int j){
	int n_  = clearrangeofbits(n,i,j);
	m = m<<i;
	return (n_|m);
}
int main(){
	int n = 15, i = 1, j = 3, m = 2;
	cout<<replaceBits(n,m,i,j);
}