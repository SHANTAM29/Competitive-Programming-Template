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
int a[30];
int n,k;
bool check(int i)
{
	int ans=0,j;
	forp(j,i,29){
		ans*=2;
		ans+=a[j];
		if(ans>=n)
		return false;
	}
	if(ans<n)
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
	int t,i;
	cin>>t;
	while(t--){
		mem(a,0);
		cin>>n>>k;
		if(k==0){
			cout<<"-1\n";
		}
		else if(k==1){
			cout<<"1\n";
		}
		else{
			a[29]=1;
			k--;
			int j=0;
			for(i=1;i<=k;i++){
				while(j<29){
					a[j]=1;
					if(check(0))
					{
						j++;
						break;
					}
					a[j]=0;
					j++;
				}
				if(j==30)
				break;
			}
			int ans=0;
			forp(i,0,29){
				ans*=2;
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
