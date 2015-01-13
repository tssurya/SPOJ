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
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
const double EPS=1e-9;

struct point{
	double x,y,z;
};

point p[6],r1,r2;
vector<pair<point,double> > vp;
int idx[6],n;

bool inside_rectangle(const point &p1)
{

	if(p1.x< _min(r1.x,r2.x))return false;
	if(p1.x> _max(r1.x,r2.x))return false;
	if(p1.y> _max(r1.y,r2.y))return false;
	if(p1.y< _min(r1.y,r2.y))return false;
	if(p1.z< _min(r1.z,r2.z))return false;
	if(p1.z> _max(r1.z,r2.z))return false;
	return true;
}


double distance_square(const point &p1,const point &p2)
{
	return ((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y))+((p1.z-p2.z)*(p1.z-p2.z));
}

bool outside_circle(const point &p)
{
	int i;
	for(int i=0;i<vp.size();i++)
	{
		if(distance_square(vp[i].first,p)>(sq(vp[i].second)))continue;
		else
		return false;
	}
	return true;
}

double getmin(const point &p)
{
	int i;
	double res=1e19;
	for(int i=0;i<vp.size();i++)
	{
		double dd=sqrt(distance_square(vp[i].first,p))-vp[i].second;
		res= _min(res,dd);
	}
	return res;
}




int main()
{
double PI=acos(-1.0),area,rarea,ans;
int cnt=1;

while(scanf("%d",&n)==1 && n);
{
	cin>>r1.x>>r1.y>>r1.z;
	cin>>r2.x>>r2.y>>r2.z;

	for(int i=0;i<n;i++)
	{
		idx[i]=i;
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
	}
	ans=0.0;
do{
	area=0.0;
	vp.clear();
	for(int i=0;i<n;i++)
	{
		point p1=p[idx[i]];
		if(inside_rectangle(p1) && outside_circle(p1))
		{
			double temp=fabs(r1.x-p1.x);
			temp=_min(temp,fabs(r1.y-p1.y));
			temp=_min(temp,fabs(r1.z-p1.z));
			temp=_min(temp,fabs(r2.x-p1.x));
			temp=_min(temp,fabs(r2.y-p1.y));
			temp=_min(temp,fabs(r2.z-p1.z));
			temp=_min(temp,getmin(p1));
			vp.push_back(make_pair(p1,temp));			
			area+=4.0/3.0*PI*temp*temp*temp;
		}
	}
         ans=_max(ans,area);
   }while(next_permutation(idx,idx+n));

	rarea=fabs(r1.x-r2.x)*fabs(r1.y-r2.y)*fabs(r1.z-r2.z);

	printf("Box %d: %.0lf\n\n",cnt++,rarea-ans+EPS);
}
	return 0;
}
