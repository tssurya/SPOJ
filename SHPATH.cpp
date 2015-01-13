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
struct edge
{
	int v;
	int w;
};
std::vector<edge> graph[10005];
int dist[10005];int parent[10005];
int globe=0;

bool operator <(edge a,edge b)
{
	return a.w>b.w;
}
void dijkstra(int s,int d)
{
	for (int i = 0; i <=globe; ++i)
	{
		dist[i]=int(1e9);
		parent[i]=-1;
	}
	dist[s]=0;
	priority_queue<edge> q;
	q.push((edge){s,0});
	
	//cout<<"s="<<s<<" "<<"d="<<d<<"\n";
	while(!q.empty())
	{
		edge p=q.top();
		q.pop();
		int node=p.v;int weight=p.w;
		if(node==d)break;
		for(int i=0;i<graph[node].size();i++)
		{
			int to=graph[node][i].v;
			int weight_extra=graph[node][i].w;
			if(weight+weight_extra<dist[to])
			{
				dist[to]=weight_extra+weight;
				parent[to]=node;
				q.push((edge){to,dist[to]});
			}
		}
	}
	
	printf("%d\n",dist[d] );


}

int main()
{
	int t,n,neighbours,index,cost,r;
	string s,s1,d1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		globe=n;
		std::map<string, int> m;
		for (int i = 0; i<=n;++i) graph[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			m[s]=i;
			scanf("%d",&neighbours);
			for(int j=0;j<neighbours;j++)
			{
				scanf("%d %d",&index,&cost);
				graph[i].push_back((edge){index,cost});
			}
		}
		scanf("%d",&r);
		
		for (int i = 0; i < r; ++i)
		{
			cin>>s1;cin>>d1;
			
			dijkstra(m[s1],m[d1]);
					
		}

		
	}
	return 0;
}