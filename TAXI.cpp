#include<bits/stdc++.h>

using namespace std;

int vis[205];
int graph[405][205];
int matchL[405];
int matchR[205];
int persons,taxi_cabs,speed,time_needed;

int distance(int x1,int x2,int y1,int y2)
{
	return (abs(x2-x1))+(abs(y2-y1));
}

bool bpm(int node_u)
{
	for(int node_v=0;node_v<taxi_cabs;node_v++)
	{
		if(!vis[node_v] and graph[node_u][node_v]==1)
		{
			vis[node_v]=1;
			if(matchR[node_v]<0 || bpm(matchR[node_v]))
			{
				matchL[node_u]=node_v;
				matchR[node_v]=node_u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int test_cases,x,y;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int answer=0;
		scanf("%d%d%d%d",&persons,&taxi_cabs,&speed,&time_needed);
		memset(graph,0,sizeof(graph));
		memset(matchL,-1,sizeof(matchL));
		memset(matchR,-1,sizeof(matchR));
		vector<pair<int,int> > p;
		vector<pair<int,int> > t;

		for(int i=0;i<persons;i++)
		{
			scanf("%d%d",&x,&y);
			p.push_back(make_pair(x,y));
		}

		for(int i=0;i<taxi_cabs;i++)
		{
			scanf("%d%d",&x,&y);
			t.push_back(make_pair(x,y));
		}
		
		for(int i=0;i<persons;i++)
		{
			for(int j=0;j<taxi_cabs;j++)
			{
				int dis=distance(p[i].first,t[j].first,p[i].second,t[j].second);
				if((dis*200)<=(time_needed*speed))
				{
					graph[i][j]=1;
				}
			}
		}

		for(int i=0;i<persons;i++)
		{
			memset(vis,0,sizeof(vis));
			if(bpm(i))
				answer++;
		}
		printf("%d\n",answer );

	}
	return 0;
}
