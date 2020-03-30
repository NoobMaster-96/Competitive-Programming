#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int len = s1.length();
		string ans = "";
		for(int i=0;i<len;i++){
			int xr = (s1[i]-'0')^(s2[i]-'0');
			ans += xr+'0';
		}
		cout<<ans<<endl;
	}
}