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
int r,cnt;
using namespace std;

void build_failure_function(string pattern,int m,int F[])
{
	F[0]=F[1]=0;
	for(int i=2;i<=m;i++)
	{
		int j=F[i-1];
		for(;;)
		{
			if(pattern[j]==pattern[i-1])
			{
				cnt++;
				r=1;
				F[i]=j+1;
				break;
			}
			if(j==0)
			{
				cnt=0;
				r=0;
				F[i]=0;
				break;
			}
			j=F[j];
			r=cnt=0;
		}
	}
}
int main()
{
	string pattern;
	while(1)
	{
		cin>>pattern;
		int F[100005];
		r=0,cnt=0;
		if(pattern=="*")
			break;
		build_failure_function(pattern,pattern.size(),F);
		int res=0;
		if(r==0)
			printf("1\n");
		else
		{
			if(pattern.size()%(pattern.size()-cnt
				)!=0)
				res=1;
			else
				res=pattern.size()/(pattern.size()-cnt);

			printf("%d\n",res );
		}
	}
	return 0;
}