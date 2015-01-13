#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define inf (ll)1e18
#define iinf (int)1e9
#define triple(a,b,c) make_pair(a,make_pair(b,c))
#define two(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long,long long>
#define psi pair<string,int>
#define pis pair<int,string>
#define pss pair<string,string>
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define vc vector<char> 
#define vpii vector<pii>
#define GI ({int t;scanf("%d",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define GF ({float t;scanf("%f",&t);t;})
#define GL ({long long t;scanf("%lld",&t);t;})
#define GLD ({long double t;scanf("%Lf",&t);t;})


int dx[] = {-1,0,0,1,-1,-1,1,1};
int dy[] = {0,-1,1,0,-1,1,-1,1};
const double eps = 1e-9;

using namespace std;
vector<pair<int,int> >graph[100005];
int dist[100005];

int n,m,source,destination,u,v,cost;
void reset()
{
	//q.clear();
	for(int i=0;i<=n;i++)
	{
		graph[i].clear();
		dist[i]=int(1e9);
	}
}
void dijkstra()
{
	dist[source]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,source));
	while(!q.empty())
	{
		pair<int,int> p=q.top();
		int previous_weight= -p.first;
		int previous_node=p.second;
		q.pop();
		//cout<<"now\n";
		//cout<<"previous_node="<<previous_node<<" "<<"previous_weight="<<previous_weight<<"\n";
		if(previous_node==destination)
			break;
		for(int i=0;i<graph[previous_node].size();i++)
		{
			int new_weight=graph[previous_node][i].first;
			int new_node=graph[previous_node][i].second;
			//cout<<"new_node="<<new_node<<" "<<"new_weight="<<new_weight<<"\n";
			if(dist[new_node]>previous_weight+new_weight)
			{
				dist[new_node]=dist[previous_node]+new_weight;
				q.push(make_pair(-dist[new_node],new_node));
			}
		}
	}
	if(dist[destination]==int(1e9))
		printf("NONE\n");
	else
		printf("%d\n",dist[destination] );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d ",&n,&m,&source,&destination);
		reset();
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&cost);
			graph[u].push_back(make_pair(cost,v));
			graph[v].push_back(make_pair(cost,u));
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<graph[i].size();j++)
			{
				cout<<i<<"->"<<graph[i][j].second<<" "<<graph[i][j].first<<"\n";
			}
		}*/
		dijkstra();
	}
	return 0;
}