#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1;
	getline(cin,s1);
	string s2;
	getline(cin,s2);
	int len1=s1.length(),len2=s2.length();
	if(len2>len1){
		cout<<"No string";
		return 0;
	}
	int pat[256] = {0};
	int str[256] = {0};
	for(int i=0;i<len2;i++){
		pat[s2[i]]++;
	}
	int start = 0, idx = -1, min_len = INT_MAX;
	int count =0;
	for(int i=0;i<len1;i++){
		str[s1[i]]++;
		if(pat[s1[i]] != 0 && str[s1[i]]<=pat[s1[i]]){
			count++;
		}
		if(count == len2){
			while(str[s1[start]]>pat[s1[start]] || pat[s1[start]] == 0){
				if(str[s1[start]]>pat[s1[start]]){
					str[s1[start]]--;
				}
				start++;
			}

			int len_window = i-start+1;
			if(min_len>len_window){
				min_len = len_window;
				idx = start;
			}
		}
	}
	if(idx == -1){
		cout<<"No string";
		return 0;
	}
	cout<<s1.substr(idx,min_len);
}