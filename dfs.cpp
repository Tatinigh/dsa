#include<bits/stdc++.h>
using namespace std;
vector<int>dfsg(int V,vector<int>adj[],vector<int>outputls)
{
    int vis[V]={0};
    vis[0]=1;
    vis[V]=1;
    outputls.push_back(V);
    for(auto it:adj[V]){
        if(!vis[it])
        {
            dfsg(it,adj,outputls);
        }
    }