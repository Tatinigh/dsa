#include<bits/stdc++.h>
using namespace std;
int orange(vector<vector<int>>&grid)
{
    //vector<vector> creates a 2d vector
    int n=grid.size();//no of rows
    int m=grid[0].size();//no of columns at row 0
    queue<pair<pair<int,int>,int>>q;//first element int er duto pair dhore rakhe second element is a single integer
    int vis[n][m];//visited matrix
    int cntfresh=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=2;//updating the visited matrix
            }
            if(grid[i][j]==1) cntfresh++;
    }
    int time=0;
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};

    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        time=max(time,t);
        q.pop();
        for(int i=0;i<4;i++)//visiting all the neighbours 4
        {
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
            {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]!=2&&grid[i][j]==1)
            {
                return -1;
            }
        }
    }
    return time;
}
