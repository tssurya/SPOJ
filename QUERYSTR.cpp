#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int Z[100005];
void z_algorithm(string s)
{
	int l=0,r=0;
	for(int i=1;i<s.size();i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<s.size() and s[r-l]==s[r])r++;
			Z[i]=r-l;r--;
		}
		else
		{
			int k=i-l;
			if(Z[k]<r-i+1)Z[i]=Z[k];
			else
			{
				l=i;
				while(r<s.size() and s[r-l]==s[r])r++;
				Z[i]=r-l;r--;
			}
		}
	}
	Z[0]=s.size();
	int query,num;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		scanf("%d",&num);
		printf("%d\n",Z[s.size()-num] );
	}
}
int main()
{
	string s;int test;
	cin>>test;
	while(test--)
	{
		cin>>s;
		reverse(s.begin(),s.end());
		z_algorithm(s);
	}
	return 0;
}
