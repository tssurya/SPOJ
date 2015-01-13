#include<bits/stdc++.h>

using namespace std;

int graph[125][125];
int vis[125];
int matchL[125];
int matchR[125];

bool bpm(int node_u)
{
	for(int node_v=0;node_v<120;node_v++)
	{
		if(!vis[node_v] and graph[node_u][node_v])
		{
			vis[node_v]=1;
			if(matchR[node_v]<0 or bpm(matchR[node_v]))
			{
				matchR[node_v]=node_u;
				matchL[node_u]=node_v;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int test_cases,x,y,n;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d",&n);
		int answer=0;
		memset(matchL,-1,sizeof(matchL));
		memset(matchR,-1,sizeof(matchR));
		memset(graph,0,sizeof(graph));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			graph[x][y]=1;
		}

		for(int i=0;i<120;i++)
		{
			memset(vis,0,sizeof(vis));
			if(bpm(i))
				answer++;
		}
		printf("%d\n",answer );
	}
	return 0;
}
