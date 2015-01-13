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
int a[26][26];
int d[26][26];
using namespace std;
class cmp
{
	public:
	int operator()(const pair<int,pair<int,int> > &a1,pair<int,pair<int,int> >b)
	{
		return a1.se.se>b.se.se;
	}
};
int main()
{
	int w,h;
	scanf("%d %d",&w,&h);
	
	while(w!=0 and h!=0)
	{
		int x1=0,y1=0,x2=0,y2=0;
		for(int i=0;i<h;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<w;j++)
			{
				if(s[j]=='X')a[i][j]=int(1e9);
				else if(s[j]=='S')x1=i,y1=j,a[i][j]=int(1e9);
				else if(s[j]=='D')x2=i,y2=j,a[i][j]=0;
				else
				a[i][j]=s[j]-'0';
				
				d[i][j]=int(1e9);
			}
		}
		/*for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		priority_queue< pair<int,pii> ,vector<pair<int,pii > >,cmp >q;
		d[x1][y1]=0;
		q.push(mp(x1,mp(y1,0)));
		while(!q.empty())
		{
			
			int x=q.top().fi;
			int y=q.top().se.fi;
			int dis=q.top().se.se;
			if(x==x2 and y==y2)
			break;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int interx=x+dx[i];
				int intery=y+dy[i];
				if(interx>=0 and intery>=0 and interx<h and intery<w and d[interx][intery]>d[x][y]+a[interx][intery])
				{
					d[interx][intery]=d[x][y]+a[interx][intery];
					q.push(mp(interx,mp(intery,d[interx][intery])));
				}
			}
		}
		printf("%d\n",d[x2][y2]);
		scanf("%d %d",&w,&h);			
	}
scanf("\n");
return 0;
}
