#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adjlist[], int s, int d){
	adjlist[s].push_back(d);
	adjlist[d].push_back(s);
}

void bfs(vector<int> adjlist[], int V){
	vector<bool> visited(V,false);
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout<<temp<<" ";
		for(int num:adjlist[temp]){
			if(visited[num] == false){
				q.push(num);
				visited[num] = true;
			}
		}
	}
}

void dfshelper(vector<int> adjlist[], vector<int> &visited, int source){
	visited[source] = true;
	cout<<source<<" ";
	for(int next:adjlist[source]){
		if(!visited[next]){
			dfshelper(adjlist,visited,next);
		}
	}
}

void dfs(vector<int> adjlist[], int V, int source){
	vector<int> visited(V,false);
	dfshelper(adjlist,visited,source);
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
	dfs(adjlist,6,0);
	/*for(int i=0;i<6;i++){
		cout<<i<<"- ";
		for(int num: adjlist[i]){
			cout<<num<<" ";
		}
		cout<<endl;
	}*/
	string a="apple",b="batman";
	if(b>a){
		cout<<b;
	}
	return 0;
}