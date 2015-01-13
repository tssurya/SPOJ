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
int n;
int vis[55][55];
int graph[55][55];
void reset()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			vis[i][j]=0;
			graph[i][j]=0;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	string s;
	while(t--)
	{
		cin>>s;
		n=s.size();
		reset();
		for(int i=0;i<n;i++)
		{
			if(s[i]=='Y')
				graph[0][i]=1;
		}
		for(int i=1;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<n;j++)
			{
				if(s[j]=='Y')
					graph[i][j]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
					graph[i][j]=-1;
			}
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(graph[i][j]==0 and graph[i][k]!=0 and graph[k][j]!=0)
					{
						//graph[i][j]=1;
						vis[i][j]=1;
					}
				}
		int pos=0,max=0;
		for(int i=0;i<n;i++)
		{
			int res=0;
			for(int j=0;j<n;j++)
			{
				if(vis[i][j])
					res++;
			}
			if(res>max)
			{
				max=res;
				pos=i;
			}
		}
	/*	cout<<"second time\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"visited array\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<vis[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		printf("%d %d\n",pos,max );
	}
	return 0;
}