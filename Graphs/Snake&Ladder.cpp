#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adjlist[], int s, int d){
	adjlist[s].push_back(d);
	//adjlist[d].push_back(s);
}

int bfs(vector<int> adjlist[]){
	vector<int> dist(101,-1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int val:adjlist[temp]){
			if(dist[val] == -1){
				dist[val] = dist[temp]+1;
				q.push(val);
			}
		}
	}
	return dist[100];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> adjlist[101];
		vector<int> board(101,0);
		int ladders,snakes;
		cin>>ladders;
		for(int i=0;i<ladders;i++){
			int s,e;
			cin>>s>>e;
			board[s] = e-s;
		}
		cin>>snakes;
		for(int i=0; i<snakes; i++){
			int s,e;
			cin>>s>>e;
			board[s] = e-s;
		}
		for(int i=1; i<100; i++){
			for(int j=1; j<=6; j++){
				if(i+j<=100){
					addedge(adjlist,i,i+j+board[i+j]);
				}
			}
		}
		cout<<bfs(adjlist)<<endl;
	}
	return 0;
}