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
#define SIZE 101

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int dp[SIZE][SIZE];
int dp2[SIZE][SIZE];
int dp3[SIZE][SIZE];
int a[SIZE][SIZE],n;
void f1()
{
	int i,j;
	forp(i,1,n){
		forp(j,1,n){
			dp[i][j]=dp[i][j-1]+a[i][j];
		}
	}
}
void f2()
{
	int i,j;
	forp(i,1,n){
		forp(j,1,n){
			dp2[i][j]=dp2[i-1][j]+a[i][j];
		}
	}
}
void f3()
{
	int i,j;
	forp(i,1,n){
		forp(j,1,n){
			dp3[i][j]=dp3[i-1][j]+dp[i][j];
		}
	}
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
	int i,j,k,p;
	cin>>n;
	forp(i,1,n){
		forp(j,1,n){
			cin>>a[i][j];
		}
	}
	f1();
	f2();
	f3();
	int ans=INT_MIN;
	forp(i,1,n){
		forp(j,1,n){
			forp(k,i,n){
				forp(p,j,n){
					int temp=dp3[k][p];
					temp+=dp3[i-1][j-1];
					temp-=dp3[i-1][p];
					temp-=dp3[k][j-1];
					ans=max(ans,temp);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
