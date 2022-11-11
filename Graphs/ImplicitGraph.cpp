#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int m,n;

char board[1000][1000];

bool vis[1000][1000];

int h(int i,int j){return i*m+j;}

int Dfs(vector<vector<int>>arr){

}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    ll count=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]) continue;
            if(board[i][j]!='.') continue;
            queue<ii> q;
            q.push(ii(i,j));
            vector<vector<int>> dist(n,vector<int>(m));
            dist[i][j]=0;
            while(!q.empty()){
                ii u= q.front(); q.pop();
                int i= u.first, j=u.second;
                //cout<<i<<" "<<j<<endl;
                vis[i][j]=true;
                if(board[i][j]=='.' && board[i+1][j]=='.' && !vis[i+1][j]) {q.push(ii(i+1,j)); dist[i+1][j]=dist[i][j]+1;}
                if(board[i][j]=='.' && board[i][j+1]=='.'  && !vis[i][j+1]) {q.push(ii(i,j+1));dist[i][j+1]=dist[i][j]+1;}
                if(board[i][j]=='.' && board[i-1][j]=='.'&& !vis[i-1][j]) {q.push(ii(i-1,j));dist[i-1][j]=dist[i][j]+1;}
                if(board[i][j]=='.' && board[i][j-1]=='.'&& !vis[i][j-1]) {q.push(ii(i,j-1));dist[i][j+1]=dist[i][j]+1;}
            }
            count++;
 
        }
    }

    cout<<count;

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<<dist[i][j]<<" ";

        cout<<endl;
    }
    */

}