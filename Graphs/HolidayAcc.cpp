#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lli long long int

class graph{
	list<pair<int,int>> *adjlist;

public:
	graph(int n){
		adjlist = new list<pair<int,int>>[n];
	}

	void addedge(int u, int v, int w, bool bidir=true){
		adjlist[u].push_back(make_pair(v,w));
		if(bidir){
			adjlist[v].push_back(make_pair(u,w));
		}
	}

	int dfshelper(int node, bool *visited, int *count, lli &ans, int n){
		visited[node] = true;
		count[node] = 1;
		for(auto nbr_pair:adjlist[node]){
			int nbr = nbr_pair.first;
			int w = nbr_pair.second;
			if(!visited[nbr]){
				count[node] += dfshelper(nbr,visited,count,ans,n);
				int nx = count[nbr];
				int ny = n-nx;
				ans += 2*min(nx,ny)*w;
			}
		}
		return count[node];
	}

	lli dfs(int n){
		bool *visited = new bool[n];
		int *count = new int[n];
		for(int i=0;i<n;i++){
			visited[i] = false;
			count[i] = 0;
		}
		lli ans = 0;
		dfshelper(0,visited,count,ans,n);
		return ans;
	}
	
};

int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		cin>>n;
		graph g(n);
		for(int i=1;i<n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			u--;
			v--;
			g.addedge(u,v,w);
		}
		lli ans = g.dfs(n);
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
}