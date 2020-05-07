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

	void dfshelper(T node, map<T,bool> &visited, list<T> &ordering){
		visited[node] = true;
		for(T neighbour:adjlist[node]){
			if(!visited[neighbour]){
				dfshelper(neighbour,visited,ordering);
			}					
		}
		ordering.push_front(node);
	}

	void dfsTS(){
		map<T,bool> visited;
		list<T> ordering;
		for(auto i:adjlist){
			T node = i.first;
			if(!visited[node]){
				dfshelper(node,visited,ordering);
			}
		}

		for(T elements:ordering){
			cout<<elements<<"-->";
		}
		cout<<endl;
	}

	void topologicalsort(){
		map<T,int> indegree;
		for(auto i:adjlist){
			indegree[i.first] = 0;
		}
		for(auto i:adjlist){
			int x = i.first;
			for(auto y:i.second){
				indegree[y]++;
			}
		}
		//bfs
		queue<T> q;
		for(auto i:indegree){
			if(i.second==0){
				q.push(i.first);
			}
		}
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto i:adjlist[node]){
				indegree[i]--;
				if(indegree[i]==0){
					q.push(i);
				}
			}
		}
	}
};

int main(){
	graph<int> g;
	g.addedge(1,2,0);
	g.addedge(1,4,0);
	g.addedge(3,2,0);
	g.addedge(2,4,0);
	g.addedge(2,7,0);
	g.addedge(2,8,0);
	g.addedge(2,6,0);
	g.addedge(5,6,0);
	g.addedge(6,9,0);
	g.addedge(7,9,0);
	g.addedge(8,9,0);
	g.addedge(4,5,0);
	g.dfsTS();

	graph<int> G;
	G.addedge(0,2,0);
	G.addedge(1,2,0);
	G.addedge(4,5,0);
	G.addedge(2,3,0);
	G.addedge(1,4,0);
	G.addedge(2,5,0);
	G.addedge(3,5,0);
	G.topologicalsort();
	
}