#include<bits/stdc++.h>

using namespace std;
const int MX=100000;
vector<bool> visited(MX+10,false);
vector<bool> visited1(MX+10, false);
vector<vector<long long int>> g(MX+10);
vector<int> cicle(MX+10);
vector<int> team;

typedef long long int ll;


void DFS(int node){
    visited1[node]=true;
    for(auto x: g[node]){
        if(!visited1[x]){
            DFS(x);
        }
    }
}


int main(){
    int n,m; cin>>n>>m;
   
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        g[u-1].push_back(v-1);
    }

    vector<ll> components;

    
        
    for(int i=0; i<n; i++){
        if(!visited1[i]){
            //cout<<i<<endl;
            components.push_back(i);
            DFS(i);
        }
    }

    for(int i=0 ; i<n; i++){
        cout<<visited[i]<<" ";
    }
    
    
    
    
    
    for(int i=0; i<components.size(); i++){
        
        
        
        queue<int> q; q.push(components[i]);
        cicle[components[i]]=1;
        team[components[i]]=1;
        while(!q.empty()){
            int u= q.front(); q.pop();
            visited[u]=true;
            for(auto x: g[u]){
                /*
                if(visited[x]){
                    if(cicle[u]%2==0){
                        cout<<"IMPOSIBLE";
                        return 0;
                    }
                }
                */
                
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                    cicle[x]= cicle[u]+1;
                    if(team[u]==1){
                        team[x]=2;
                    }else{
                        team[x]=1;
                    }    
                }

                
            }
        }
        /*
        for(int j=0; j<team.size(); j++){
            cout<<team[j]<<" ";
        }
        */
    }
    

    

    cout<<endl;
    /*
    for(int i=0; i<n; i++){
        cout<<cicle[i]<<" ";
    }
    */

}