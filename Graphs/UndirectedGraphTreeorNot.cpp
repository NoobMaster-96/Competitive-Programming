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

	bool is_tree(T src){
		map<T,bool> visited;
		map<T,T> parent;
		queue<T> q;
		for(auto i:adjlist){
			visited[i.first] = false;
			parent[i.first] = i.first;
		}
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(T nbr:adjlist[node]){
				if(visited[nbr] && parent[node]!=nbr){
					return false;
				}
				else if(!visited[nbr]){
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}
		return true;
	}
};

int main(){
	graph<int> g;
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,0);

	cout<<g.is_tree(0);
}