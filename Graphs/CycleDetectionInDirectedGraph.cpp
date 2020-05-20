#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class graph{
	vector<int> *adjlist;
	int N;

public:
	graph(int n){
		N = n;
		adjlist = new vector<int>[N];
	}

	void addedge(int u, int v, bool bidir=false){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}

	bool cycle_helper(int node, bool *visited, bool *s){
		visited[node] = true;
		s[node] = true;
		for(auto nbr:adjlist[node]){
			if(s[nbr]==true){
				return true;
			}
			else if(!visited[nbr]){
				bool cycle = cycle_helper(nbr,visited,s);
				if(cycle){
					return true;
				}
			}
		}
		s[node] = false;
		return false;
	}

	bool containsCycle(){
		bool *visited = new bool[N];
		bool *s = new bool[N];
		for(int i=0;i<N;i++){
			visited[i] = false;
			s[i] = false;
		}
		return cycle_helper(0,visited,s);
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		graph g(n);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			g.addedge(u,v);
		}
		cout<<g.containsCycle()<<endl;
	}
}