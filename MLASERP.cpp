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
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define DEBUG if(0)

using namespace std;
template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6>
void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

char grid[128][128];
int d[128][128];
int sx,sy,ex,ey,h,w;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool valid(int r2,int c2)
{
	if(r2>=0 and r2<=h-1 and c2>=0 and c2<=w-1)return true;
	else
		return false;
}
int bfs()
{
	int r1,r2,c1,c2;
	queue<int> q;
	q.push(sx);
	q.push(sy);
	memset(d,0x3f,sizeof d);
	d[sx][sy]=-1;
	while(!q.empty())
	{
		 r1=q.front();
		 q.pop();
		 c1=q.front();
	    q.pop();
	    //cout<<r1<<c1;
		for(int i=0;i<4;i++)
		{

			r2=r1+dx[i];
			 c2=c1+dy[i];
			while(valid(r2,c2) and grid[r2][c2]!='*')
			{
				//cout<<valid(r2,c2);
				if(d[r2][c2]>d[r1][c1]+1)
				{
					d[r2][c2]=d[r1][c1]+1;
					if(r2==ex and c2==ey)return d[r2][c2];
					q.push(r2);
					q.push(c2);
				}
				r2+=dx[i];
				c2+=dy[i];
			}
		}
	}
	return d[ex][ey];
}

int main()
{
		//DEBUG READ("in.txt");
		//DEBUG WRITE("out.txt");
	int cnt=0;
	scanf("%d %d",&w,&h);
	for(int i=0;i<h;i++)
		{
			scanf("%s",grid[i]);
			for (int j = 0; j < w and cnt<2;j++)
			{	//cout<<"-1\n";
				if(grid[i][j]=='C')
				{
					//cout<<"-1\n";
					if(cnt==0)
						{
							//cout<<"-1\n";
							sx=i,sy=j,cnt++;
						}
					else
						ex=i,ey=j,cnt++;
				}
			}
		}

//cout<<sx<<sy<<ex<<ey<<"\n";
printf("%d\n",bfs());

return 0;
}
