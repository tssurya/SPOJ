//merge sort

#include<bits/stdc++.h>

using namespace std;
long long int ans=0;


void merge(long long int arr[],int low,int mid,int high)
{
	long long int a[high-low+1];
	int i=low;
	int j=mid+1;
	int k=0;
	while(i<=mid and j<=high)
	{
		if(arr[i]>arr[j])
		{
			a[k++]=arr[j++];
			ans+=mid-i+1;
		}
		else
		{
			a[k++]=arr[i++];
		}
	}
	while(i<=mid)
	{
		a[k++]=arr[i++];
	}
	while(j<=high)
	{
		a[k++]=arr[j++];
	}
	int l=0;
	for(int m=low;m<=high;m++,l++)
	{
		arr[m]=a[l];
	}
}

void merge_sort(long long int arr[],int low,int high)
{
	if(low>=high)
		return;
	int mid=(low+high)/2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	merge(arr,low,mid,high);
}


int main()
{
	int t;
	scanf("%d",&t);
	long long int n;
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		long long int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		merge_sort(arr,0,n-1);
		printf("%lld\n",ans );
	}
	return 0;
}