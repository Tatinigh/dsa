#include<bits/stdc++.h>
using namespace std;
vector<int>dfsg(int V,vector<int>adj[],int vis[])
{
    vis[V]=1;
    vis[0]=1;
    vis[V]=1;
    for(auto it:adj[V]){
        if(!vis[it])
        {
            dfsg(it,adj,vis);
        }
    }
}
//creating an adjaceny list from adj matrix
int numprovince(vector<vector<int>>adj,int V){
    vector<int>ls[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==1&&i!=j)
            {
                ls[i].push_back(j);
                ls[j].push_back(i);
            }
        }
    } int vis[V]={0};
    int c=0;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            c++;
            dfsg(i,ls,vis);
        }
    }
    return c;
}
//count component
int numprovince(vector<vector<int>>adj,int V){
    vector<int>ls[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==1&&i!=j)
            {
                ls[i].push_back(j);
                ls[j].push_back(i);
            }
        }
    } int vis[V]={0};
    int c=0;
    for(int i=1;i<V;i++)
    {
        if(!vis[i])
        {
            c++; //new node visited
            dfsg(i,ls,vis);
        }
    }