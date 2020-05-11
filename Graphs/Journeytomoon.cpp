#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

template<typename T>
class graph{
	map<T,list<T>> adjlist;

public:
	graph(){}

	void addedge(T u, T v, bool bidir=true){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}

	void print(){
		for(auto i:adjlist){
			cout<<i.first<<"->";
			for(T entry:i.second){
				cout<<entry<<" ";
			}
			cout<<endl;
		}
	}

	int journeyToMoon(int n){
		vector<T> visited(n,false);
		vector<int> ele;
		for(int i=0;i<n;i++){
			queue<T> q;
			if(!visited[i]){
				int ans = 0;
				q.push(i);
				visited[i] = true;
				ans++;
				while(!q.empty()){
					T node = q.front();
					q.pop();
					for(auto j:adjlist[node]){
						if(!visited[j]){
							q.push(j);
							visited[j] = true;
							ans++;
						}
					}
				}
				ele.push_back(ans);
			}
		}
		int ans = n*(n-1)/2;
		for(auto i:ele){
			if(i>1){
				ans -= i*(i-1)/2;
			}
		}
		return ans;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	graph<int> g;
	for(int i=0;i<q;i++){
		int v,u;
		cin>>v>>u;
		g.addedge(v,u);
	}
	cout<<g.journeyToMoon(n)<<endl;
}