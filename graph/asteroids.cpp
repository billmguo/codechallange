#include <iostream>
#include <vector>
using namespace std;
const int N=1001;
int n,k;
int map[N][N],vis[N],link[N];
vector<vector<int>> map(N,vector<int>(N,0));
vector<int> visited(N,0);
vector<int> link(N,0);
int find(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(map[x][i]&&!visited[i])
        {
            vis[i]=1;
            if(link[i]==0||find(link[i]))
            {
                link[i]=x;
                return 1;
            }
        }        
    }
    return 0;
}
int main()
{
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            s++;
    }
    return 0;
}
