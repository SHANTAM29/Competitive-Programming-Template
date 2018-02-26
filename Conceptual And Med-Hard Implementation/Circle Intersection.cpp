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
ldo area(ldo r){
	return r*r*PI;
}
ldo func(ldo r0,ldo r1,ldo d)
{
	long double phi = acos((r0*r0 + d*d - r1*r1)/(2 * r0 * d)) * 2;
    long double theta = acos((r1*r1 + d*d - r0*r0)/(2 * r1 * d)) * 2;
    long double ans1 = 0.5L * theta * r1 * r1 - 0.5L * r1 * r1 * sin(theta);
    long double ans2 = 0.5L * phi * r0 * r0 - 0.5L * r0 * r0 * sin(phi);
    return ans1 + ans2;
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
	int i,n;
	ldo d,r,x1,y1;
	cin>>n>>d>>r;
	ldo ans=0.00000;
	forp(i,1,n){
		cin>>x1>>y1;
		long double dist = sqrt((x1 - 0) * (x1 - 0) + (y1 - 0) * (y1 - 0));
		if(dist==0.000000){
			ans+=area(min(r,d));
		}
		else if(dist<=abs(r-d)){
			ans+=area(min(r,d));
		}
		else if(dist > r+d){
			ans+=0.00;
		}
		else{
			ldo val=func(r,d,dist);
			ans+=val;
		}
	}
	ans/=area(r);
	cout<<fixed<<setprecision(4)<<ans<<endl;
	return 0;
}
