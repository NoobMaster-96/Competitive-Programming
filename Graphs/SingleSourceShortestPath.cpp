#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adjlist[], int s, int d){
	adjlist[s].push_back(d);
	adjlist[d].push_back(s);
}

void bfs(vector<int> adjlist[], int V){
	vector<int> dist(V,INT_MAX);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int val:adjlist[temp]){
			if(dist[val] == INT_MAX){
				dist[val] = dist[temp]+1;
				q.push(val);
			}
		}
	}
	for(int d:dist){
		cout<<d<<" ";
	}
}

int main(){
	int V=6;
	//cin>>V;
	vector<int> adjlist[V];
	addedge(adjlist,1,0);
	addedge(adjlist,1,2);
	addedge(adjlist,2,4);
	addedge(adjlist,2,3);
	addedge(adjlist,3,5);
	addedge(adjlist,3,4);
	addedge(adjlist,4,0);
	bfs(adjlist,6);

	return 0;
}