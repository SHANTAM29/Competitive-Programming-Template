#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
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
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
set<int> s;
int a[SIZE];
int c,n;
bool check(int mid)
{
	int k=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=k){
			cnt++;
			k=a[i]+mid;
		}
		else{
			while(i<=n and a[i]<k)
			i++;
			if(i<=n){
				cnt++;
				k=a[i]+mid;
			}
		}
	}
	if(cnt>=c)
	return true;
	return false;
}
int main()
{  	
	/* #ifndef ONLINE_JUDGE
	freopen(fi, "r", stdin);
	#endif */
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//cin.ignore();
	//cin.clear();
	boost;
	//cin.tie(0);
	int i,t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		forp(i,1,n){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		s.clear();
		int lo=0,hi=1e9;
		while(lo<=hi){
			int mid=lo+hi>>1;
			if(check(mid)){
				s.insert(mid);
				lo=mid+1;
			}
			else{
				hi=mid-1;
			}
		}
		cout<<*(s.rbegin())<<endl;
	}
	return 0;
}
