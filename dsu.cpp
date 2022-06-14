/*
Approach:

Complexity:
    Time:
    Space:
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int parent[10000];
int rankk[10000];
int vis[10000];
vector<int>ans;
int cnt;
int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]);
}
void unionn(int u, int v){
    u=findpar(u);
    v=findpar(v);
    if(rankk[u]>rankk[v]){
        parent[v]=u;
    }
    else if(rankk[u]<rankk[v]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rankk[u]++;
    }
}
void dfs(int x,int vis[], vector<int>g[]){
    vis[x]=1;
    for(auto v:g[x]){
        if(vis[v]==0){
            dfs(v,vis,g);
        }
    }
}
int main(){
    int n;
    for(int i=0;i<10000;i++){
        parent[i]=i;
    }
    cin>>n;

    set<int>st;
    vector<int>g[10000];
    vector<int>temp;
    for(int ii=0;ii<n-1;ii++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(findpar(u)==findpar(v)){
            ans.push_back(u);
            ans.push_back(v);
        }
        else{
            unionn(u,v);
        }
    }
    cnt=0;
    for(int x=1;x<=n;x++){
        if(vis[x]==0){
            temp.push_back(x);

            dfs(x,vis,g);
        }
    }
    int val=temp.size();
    cout<<val-1<<endl;
    val--;
    for(int i=0,j=0;i<val;i++,j+=2){
        cout<<ans[j]<<" "<<ans[j+1]<<" "<<temp[i]<<" "<<temp[i+1]<<endl;
    }


    return 0;
}

