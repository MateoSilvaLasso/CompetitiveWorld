#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<ll>>g(n);

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<bool> visited(n,false);
    vector<ll> dist(n,0);
    vector<ll> sucesor(n);
    queue<ll> q; q.push(0);
    dist[0]=0;
    sucesor[0]=0;
    while(!q.empty()){
        int u= q.front(); q.pop();
        visited[u]=true;
        for(auto x: g[u]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
                dist[x]= dist[u]+1;
                sucesor[x]=u;
            }
        }
    }
    for(int i=0; i<dist.size(); i++){
        if(i!=0){
            if(dist[i]==0){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
   
   vector<ll> alls;
   int i=n-1;
   while(i!=0){
      alls.push_back(sucesor[i]);
      i=sucesor[i]; 
   }
   
    cout<<alls.size()+1<<endl;
   for(int i=alls.size()-1; i>=0; i--){
        cout<<alls[i]+1<<" ";
   }
   cout<<n<<endl;
   

}