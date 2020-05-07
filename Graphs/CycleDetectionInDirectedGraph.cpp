#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

template<typename T>
class graph{
	map<T,list<T>> adjlist;

public:
	graph(){}

	void addedge(T u, T v, bool bidir=false){
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

	bool containsCycle(){
		
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