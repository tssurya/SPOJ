#include<bits/stdc++.h>
using namespace std;

string pre_process(string s)
{
	int n=s.size();
	if(n==0)
		return "^$";
	string ret="^";
	for(int i=0;i<n;i++)
	{
		ret+="#"+s.substr(i,1);
	}
	ret+="#$";
	return ret;
}
int main()
{
	int k;
	scanf("%d",&k);
	string s;
	cin>>s;
	string t=pre_process(s);
	int n=t.size();
	int p[60005];
	memset(p,60005,0);
	int center=0,right=0;
	for(int i=1;i<n-1;i++)
	{
		int i_dash=2*center-i;
		p[i]=((right>i)?min(right-i,p[i_dash]):0);
		while(t[i+1+p[i]]==t[i-1-p[i]])
			p[i]++;
		if(i+p[i]>right)
		{
			center=i;
			right=i+p[i];
		}
	}
	int result=0;
	for(int i=1;i<n-1;i++)
	{
		if(p[i]>=k)
		{
			if(k%2==0)
			{
				if(t[i]=='#')
					result++;
			}
			else
			{
				if(t[i]!='#')
					result++;
			}
		} 
	}
	printf("%d\n",result );
	
	return 0;
}