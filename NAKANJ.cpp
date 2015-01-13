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




int dx[]={2,-1,1,2,-2,1,-1,-2};
int dy[]={-1,2,2,1,1,-2,-2,-1};
int visited[8][8];
char compare[9]={'a','b','c','d','e','f','g','h'};
int mark[9][9];

struct point{
	int x;
	int y;
};

	void compute(point source,point desti)
	{
		memset(visited,0,sizeof visited);
		queue<point> q;
		q.push(source);
		visited[source.x][source.y]=1;

		while(!q.empty())
		{
			point p=q.front();
			
			
			q.pop();
			for(int i=0;i<8;i++)
			{
				
				if(p.x+dx[i]>=0 and p.y+dy[i]>=0 and p.x+dx[i]<8 and p.y+dy[i]<8 and !visited[p.x+dx[i]][p.y+dy[i]])
				{  point New;
					New.x=p.x+dx[i]	; New.y=p.y+dy[i];				
					q.push(New);
					visited[New.x][New.y]=1;
					mark[New.x][New.y]=mark[p.x][p.y]+1;
				}
			}
		}
	}

	int main()
	{
		int t;
		scanf("%d",&t);
		char a[3],b[3];

		while(t--)
		{
			memset(mark,0,sizeof mark);
			scanf(" %s %s",a,b);
			point source,desti;

				for(int i=0;i<8;i++)
				{
					if(a[0]==compare[i])
						source.x=i;

					if(b[0]==compare[i])
						desti.x=i;
				}

				source.y=a[1]-'0'-1;
				desti.y=b[1]-'0'-1;
				//cout<<source.x<<source.y<<desti.x<<desti.y;

				compute(source,desti);

				printf("%d\n",mark[desti.x][desti.y] );
		}
	return 0;

	}
