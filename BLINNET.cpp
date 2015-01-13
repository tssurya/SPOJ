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
int n,cost,v,p;
vector<pair<int,pair<int,int> > >graph;
string name;
long long int total=0;
int parent[10005];
void reset()
{
	graph.clear();
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
	total=0;
}
int find(int x,int *parent)
{
	if(x!=parent[x])
		parent[x]=find(parent[x],parent);
	return parent[x];
}
void kruskal()
{
	sort(graph.begin(),graph.end());
	for(int i=0;i<graph.size();i++)
	{
		int pu=find(graph[i].second.first,parent);
		int pv=find(graph[i].second.second,parent);
		if(pu!=pv)
		{
			parent[pu]=parent[pv];
			total+=graph[i].first;
		}
	}
	printf("%lld\n",total );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		reset();
		for(int i=1;i<=n;i++)
		{
			cin>>name;
			scanf("%d",&p);
			for(int j=1;j<=p;j++)
			{
				scanf("%d %d",&v,&cost);
				graph.push_back(make_pair(cost,make_pair(i,v)));
			}
		}
		kruskal();
	}
	return 0;
}