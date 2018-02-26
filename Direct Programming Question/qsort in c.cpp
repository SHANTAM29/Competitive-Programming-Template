#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<assert.h>
#define forp(i,a,b) for( i=a;i<=b;i++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)

#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 100000

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int a[SIZE],n,q,i,x;
	scanf("%d",&n);
	forp(i,0,n-1){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmpfunc);
	//sort(a,a+n);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		int lo=0,hi=n-1;
		while(lo<=hi){
			int mid = lo+hi>>1;
			if(a[mid]==x){
				printf("%d\n",mid+1);
				break;
			}
			else if(a[mid]<x)
			lo=mid+1;
			else
			hi=mid-1;
		}
	}
	return 0;
}
