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
#define SIZE 501

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
char a[SIZE][SIZE];
int dp1[SIZE][SIZE];
int dp2[SIZE][SIZE];
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
	int i,j,n,m;
	cin>>n>>m;
	forp(i,1,n){
		forp(j,1,m){
			cin>>a[i][j];
		}
	}
	forp(i,1,n){
		forp(j,1,m-1){
			if(a[i][j]==a[i][j+1] and a[i][j]=='.')
			{
				dp1[i][j]=1+dp1[i][j-1];
			}
			else
			{
				dp1[i][j]=dp1[i][j-1];
			}
		}
	}
	forp(i,1,n-1){
		forp(j,1,m){
			dp2[i][j]=dp2[i-1][j];
			if(a[i][j]==a[i+1][j] and a[i][j]=='.')
			{
				dp2[i][j]++;
			}
		}
	}
	int q,x1,x2,y1,y2;
	cin>>q;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		int ans=0;
		forp(i,x1,x2){
			ans+=(dp1[i][y2-1]-dp1[i][y1-1]);
		}
		forp(j,y1,y2){
			ans+=(dp2[x2-1][j]-dp2[x1-1][j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
