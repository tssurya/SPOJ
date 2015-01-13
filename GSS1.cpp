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

int n;
int a[50005];
struct node
{
	  int sum,prefix,suffix,ans;
};
node t[4*50005];
/*node make_node(int val)
{
	node res;
	res.sum=res.prefix=res.suffix=res.ans=val;
	return res;
}*/
node combine(node left,node right)
{
	node res;
	res.sum=left.sum+right.sum;
	res.prefix=max(left.prefix,left.sum+right.prefix);
	res.suffix=max(right.suffix,right.sum+left.suffix);
	res.ans=max(max(left.ans,right.ans),left.suffix+right.prefix);
	return res;
}
void build(int low,int high,int v)
{
	if(low==high)
		t[v].sum=t[v].prefix=t[v].suffix=t[v].ans=a[low];
	else
	{
		int cl=v>>1,cr=cl|1;
		int mid=(low+high)>>1;
		build(low,mid,cl);
		build(mid+1,high,cr);
		t[v]=combine(t[cl],t[cr]);
	}
}
node query(int low,int high,int v,int l,int r)
{
	if(low==high)
		return t[v];
	int cl=v>>1;
	int cr=cl|1;
	int mid=(low+high)>>1;
	if(l>mid)
		return query(mid+1,high,cr,l,r);
	if(r<=mid)
		return query(low,mid,cl,l,r);
	return combine(query(low,mid,cl,l,mid),query(mid+1,high,cr,mid+1,r));
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	int m,x,y;
	scanf("%d",&m);
	node answer;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d",&x,&y);
		answer=query(1,n,1,x,y);
		printf("%d\n",answer.ans);
	}
return 0;
}
