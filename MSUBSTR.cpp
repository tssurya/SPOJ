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
	int t;
	scanf("%d",&t);
	string s;
	while(t--)
	{
		cin>>s;
		string t=pre_process(s);
		int n=t.size();
		int p[6005];
		memset(p,6005,0);
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
		int max_length=0;
		for(int i=1;i<n-1;i++)
		{
			max_length=max(max_length,p[i]);
		}
		int cnt=0;
		for(int i=1;i<n-1;i++)
		{
			if(p[i]==max_length)
				cnt++;
		}
		printf("%d %d\n",max_length,cnt );
	}
	return 0;
}