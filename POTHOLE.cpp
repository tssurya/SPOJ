#include<bits/stdc++.h>
#define infinity 1e9

using namespace std;
int graph[205][205];
int rgraph[205][205];
int vis[205];
int parent[205];
int s,t,n;

bool bfs()
{
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();

		if(vis[t]==1)
			return true;

		for(int v=1;v<=n;v++)
		{
			if(!vis[v] and rgraph[u][v]>0)
			{
				q.push(v);
				parent[v]=u;
				vis[v]=1;
			}
		}
	}
	return false;
}

void flow()
{
	int max_flow=0;
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
			rgraph[u][v]=graph[u][v];

	while(bfs())
	{
		int path_flow=infinity;
		for(int v=t;v!=s;v=parent[v])
		{
			int u=parent[v];
			path_flow=min(path_flow,rgraph[u][v]);
		}

		for(int v=t;v!=s;v=parent[v])
		{
			int u=parent[v];
			rgraph[u][v]-=path_flow;
			rgraph[v][u]+=path_flow;
		}

		max_flow+=path_flow;
	}

	printf("%d\n",max_flow );
}
int main()
{
	int test,m,k;
	scanf("%d",&test);
	s=1;
	while(test--)
	{
		memset(graph,0,sizeof(graph));
		memset(parent,0,sizeof(parent));
		memset(rgraph,0,sizeof(rgraph));
		scanf("%d",&n);
		t=n;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&k);
				if(i==1 or k==n)
				{
					graph[i][k]=1;
				}
				else
				{
					graph[i][k]=infinity;
				}
			}
		}
		flow();
	}
	return 0;
}
