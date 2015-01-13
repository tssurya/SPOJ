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
#define mod 1000000007ll
#define fill(x) memset(x,0,sizeof x)
#define inf (ll)1e18
#define iinf (int)1e9

using namespace std;
template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6>
void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}


int main()
{
	int r,c,t;
	int mr,mc,c1r,c1c,c2r,c2c;
	scanf("%d",&r);
	scanf("%d",&c);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&mr,&mc,&c1r,&c1c,&c2r,&c2c);
		if(mr>=c1r and mr>=c2r)printf("YES\n" );
		else if(mr<=c1r and mr<=c2r)printf("YES\n");
		else if(mc<=c1c and mc<=c2c)printf("YES\n");
		else if(mc>=c1c and mc>=c2c)printf("YES\n");
		else
		{
			int mtop,mbot,mleft,mright,ctop,cbot,cleft,cright;
			mtop=mr-1;
			ctop=min((abs(c1r-1)+abs(mc-c1c)),(abs(c2c-1)+abs(mc-c2c)));
				mright=mc-1;
				cright=min((abs(c2r-mr)+abs(c2c-1)),(abs(c1r-mr)+abs(c1c-1)));
				mleft=c-mc;
				cleft=min((abs(c2r-mr)+abs(c2c-c)),(abs(c1r-mr)+abs(c1c-c)));
				mbot=r-mr;
				cbot=min((abs(c2c-mc)+abs(c2r-r)),(abs(c1c-mc)+abs(c1r-r)));
				if(mtop<ctop or mbot<cbot or mleft<cleft or mright <cright)printf("YES\n" );
				else
					printf("NO\n");
		}
	}


return 0;
}
