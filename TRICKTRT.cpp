#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
const double esp= 1e-12;
using namespace std;
struct point
{
	double x,y;
};

point p[500005];
int n;
double dist(point &a,point &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double f(double arg)
{
	point p1={arg,0};
	double result=0.0;
	for(int i=0;i<n;i++)
	{
		result=max(result,dist(p1,p[i]));
	}
	return result;
}
double ternary(double l,double r)
{
	int cnt=64;
	while(cnt--)//for precision issues to get the almost possible aprroximation	
	{
		double left_third=((2*l)+r)/3.0;
		double right_third=(l+(2*r))/3.0;
		if(f(left_third)<f(right_third))
			r=right_third;
		else
			l=left_third;
	}
	return (r+l)/2.0;
}
int main()
{
	double result=0.0;
	double xmin=0.0,xmax=0.0;
	while(scanf("%d",&n)==1 and n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&p[i].x,&p[i].y);
			if(i==0)
			{
				xmax=xmin=p[i].x;
			}
			else
			{
				xmin=min(xmin,p[i].x);
				xmax=max(xmax,p[i].x);
			}
		}
		result=ternary(xmin,xmax);
		printf("%.7lf %.7lf\n",result+esp,sqrt(f(result))+esp );
	}
	return 0;
}
