#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define FOR(tt,a,b) for(int tt=a;tt<=b;tt++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define gl(cin,s)  getline(cin,s);
#define bitc(n) __builtin_popcountll(n)
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 1000001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;

struct query{
	int l;
	int r;
	int pos;
}Q[SIZE];

int a[SIZE];
int fans[SIZE];
int ans;
int cnt[SIZE];
int block;

bool cmp(query A,query B)
{
	int sqn = block;
	if( A.l / sqn != B.l / sqn )
		return A.l / sqn < B.l / sqn;
	return A.r < B.r ;
}

void add(int id)
{
	cnt[a[id]]++;
	if(cnt[a[id]]==1)
	ans++;
}

void remove(int id)
{
	cnt[a[id]]--;
	if(cnt[a[id]] == 0)
	ans--;
}
int main()
{  	
	boost;
	int i,n,q;
	//cin>>n;
	scanf("%d",&n);
	block = sqrt(n);
	forp(i,1,n){
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	//cin>>q;
	scanf("%d",&q);
	forp(i,1,q){
		//cin>>Q[i].l>>Q[i].r;
		scanf("%d %d",&Q[i].l,&Q[i].r);
		Q[i].pos=i;
	}
	sort(Q+1,Q+1+q,cmp);
	int idl=1;
	int idr=0;
	forp(i,1,q){
		int x=Q[i].l;
		int y=Q[i].r;
		while(idr < y){
			add(++idr);
		}
		while(idr > y){
			remove(idr);
			idr--;
		}
		while(idl < x){
			remove(idl);
			idl++;
		}
		while(idl > x){
			idl--;
			add(idl);
		}
		fans[Q[i].pos]=ans;
	}
	forp(i,1,q){
		printf("%d\n",fans[i]);
	}
	return 0;
}
