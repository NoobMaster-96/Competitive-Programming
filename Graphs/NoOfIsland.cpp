#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& mat, int r, int c){
	int nr = mat.size();
	int nc = mat[0].size();
	mat[r][c] = 0;
	if(r-1 >= 0 && mat[r-1][c] == 1){
		dfs(mat,r-1,c);
	}
	if(r+1 < nr && mat[r+1][c] == 1){
		dfs(mat,r+1,c);
	}
	if(c-1 >= 0 && mat[r][c-1] == 1){
		dfs(mat,r,c-1);
	}
	if(c+1 < nc && mat[r][c+1] == 1){
		dfs(mat,r,c+1);
	}
}

int numIslands(vector<vector<int>>& mat){
	int nr = mat.size();
	if(!nr){
		return 0;
	}
	int nc = mat[0].size();
	int count = 0;
	for(int i=0; i<nr; i++){
		for(int j=0; j<nc; j++){
			if(mat[i][j] == 1){
				dfs(mat,i,j);
				count++;
			}
		}
	}
	return count;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mat(n,vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>mat[i][j];
		}
	}
	cout<<numIslands(mat);
}