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

int f,s,g,u,d;
bool vis[1000010];

struct p{
int x,y;
p(){}
p(int i,int j):x(i),y(j){}
};

queue<p> Q;
p* bfs()
{

while(!Q.empty())Q.pop();
Q.push(p(s,0));
vis[s]=1;
p cur;
while(!Q.empty()){

cur=Q.front();
Q.pop();

if(cur.x==g)return &cur;


if(cur.x+u<=f and !vis[cur.x+u])
{
vis[cur.x+u]=1;
Q.push(p(cur.x+u,cur.y+1));
}
if(cur.x-d>0 and !vis[cur.x-d])
{
vis[cur.x-d]=1;
Q.push(p(cur.x-d,cur.y+1));
}

}

return NULL;
}

int main()
{
	while(scanf("%d%d%d%d%d",&f,&s,&g,&u,&d)!=EOF){

	if(s==g)
	printf("0\n");

	else{
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	p * ans=bfs();
	if(ans==NULL)
	printf("use the stairs\n");
	else printf("%d",ans->y);
}
}
return 0;
}


