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
#define SIZE 205

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
char a[SIZE][SIZE];
int val[SIZE][SIZE];
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
	int n,m,t,i,j;
	cin>>t;
	while(t--){
		cin>>n>>m;
		forp(i,0,204){
			forp(j,0,204){
				val[i][j]=-999999;
			}
		}
		forp(i,1,n){
			forp(j,1,m){
				cin>>a[i][j];
			}
		}
		if(a[1][1]=='L'){
			cout<<"0\n";
			continue;
		}
		if(a[1][1]=='D'){
			cout<<"-1\n";
			continue;
		}
		val[1][1]=150;
		forp(i,1,n){
			forp(j,1,m){
				if(i!=1 or j!=1){
					if(val[i-1][j]<0 and val[i][j-1]<0){
						val[i][j]=-999999;
					}
					else{
						val[i][j]=max(val[i-1][j],val[i][j-1]);
						if(a[i][j]=='T'){
							val[i][j]+=150;
						}
						else if(a[i][j]=='D'){
							val[i][j]-=100;
						}
					}
				}
			}
		}
		if(val[n][m]>=0){
			cout<<val[n][m]<<endl;
		}
		else{
			cout<<"-1\n";
		}
	}
	return 0;
}
