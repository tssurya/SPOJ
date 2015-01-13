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
int n,a[50005];
int max1(int a,int b,int c)
{
	return max(max(a,b),c);
}
struct node
{
	int sum,prefix,suffix,ans;
};
node t[4*50005];
void combine(node &v,node &left,node &right)
{
	v.sum=left.sum+right.sum;
	v.prefix=max(left.sum+right.prefix,left.prefix);
	v.suffix=max(right.sum+left.suffix,right.suffix);
	v.ans=max1(left.suffix+right.prefix,left.ans,right.ans);
}
void build(int low,int high,int v)
{
	if(low==high)
	{
		t[v].sum=t[v].prefix=t[v].suffix=t[v].ans=a[low];
		return;
	}
	else
	{
		int left=v<<1;
		int right=left|1;
		int mid=(low+high)>>1;
		build(low,mid,left);
		build(mid+1,high,right);
		combine(t[v],t[left],t[right]);
	}
}
void query(node &res,int low,int high,int v,int l,int r)
{
	if(low==l and high==r)
		res=t[v];
	else
	{
		int left=v<<1;
		int right=left|1;
		int mid=(low+high)>>1;
		if(l>mid)
			query(res,mid+1,high,right,l,r);
		else if(r<=mid)
			query(res,low,mid,left,l,r);
		else
		{
			node leftnode,rightnode;
			query(leftnode,low,mid,left,l,mid);
			query(rightnode,mid+1,high,right,mid+1,r);
			combine(res,leftnode,rightnode);
		}
	}
}
void update(int low,int high,int v,int pos,int val)
{
	if(low==high and pos==low)
	{
		t[v].sum=t[v].prefix=t[v].suffix=t[v].ans=val;
		return;
	}
	
		int left=v<<1;
		int right=left|1;
		int mid=(low+high)>>1;
		if(pos<=mid)
			update(low,mid,left,pos,val);
		else
			update(mid+1,high,right,pos,val);
		combine(t[v],t[left],t[right]);
	
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <=n; ++i)
	{
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	int m,x,y,chk;
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d",&chk,&x,&y);
		if(chk)
		{
			node res;
			query(res,1,n,1,x,y);
			printf("%d\n",res.ans );
		}
		else
		{
			update(1,n,1,x,y);
		}
	}
return 0;
}
