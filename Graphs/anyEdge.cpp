#include <bits/stdc++.h>

/*

using namespace std;

typedef long long int ll;

typedef pair<int, int> ii;

void BFS(){
    
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<ll>>g(n);

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<bool>visited(n,false);
    vector<int> dist(n,0);
    queue<int> q; q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int u= q.front(); q.pop();
        visited[u]=true;
        for(auto x: g[u]){
            if(!visited[x]){
                q.push(x);
                dist[x]= dist[u]+1;
            }
        }
    }

   vector<ii> p;
   ll count=0;
   for(int i=0; i<n; i++){
        if(visited[i]==false){
            count++;
            p.push_back(ii(0,i));
            g[0].push_back(i);
            
            visited.resize(n,false);
            dist.resize(n,0);
            q.push(0);
            dist[0]=0;
            while(!q.empty()){
                int u= q.front(); q.pop();
                visited[u]=true;
                for(auto x: g[u]){
                    if(!visited[x]){
                        q.push(x);
                        dist[x]= dist[u]+1;
                    }
                }
            }
            
            //i=0;

           
        }
   }
    cout<<count<<endl;
   for(int i=0; i<p.size(); i++){
        cout<<p[i].first+1<<" "<<p[i].second+1<<endl;
   }

}
*/
using namespace std;

#define MAXN 202020

int n, m;
vector<vector<int>>adj(MAXN);
vector<bool>visited(MAXN, false);
vector<int>bridges;

void DFS (int node) {
  visited[node] = true;
  for (auto child : adj[node]) {
    if (visited[child] == false) {
      DFS(child);
    }
  }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        cout<<i<<endl;
        bridges.push_back(i);
        DFS(i);
      }
    }
    
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
    return 0;
}