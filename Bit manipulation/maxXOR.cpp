#include<bits/stdc++.h>
using namespace std;

long long int maxXORInRange(long long int L, long long int R){ 
    long long int LXR = L ^ R; 
    long long int msbPos = 0; 
    while(LXR){ 
        msbPos++; 
        LXR >>= 1; 
    }
    long long int maxXOR = 0; 
    long long int two = 1; 
    while(msbPos--){ 
        maxXOR += two; 
        two <<= 1; 
    }
    return maxXOR; 
} 
int main(){
	long long int l,r;
	cin>>l>>r;
	cout<<maxXORInRange(l,r);
}