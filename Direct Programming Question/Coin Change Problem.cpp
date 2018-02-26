#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ren(i,a,b) for(i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
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
int dp[2001][2001];
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	int i,j,x,n,k,t;
	set<int> s;
	set<int> ::iterator it;
	cin>>t;
	while(t--){
		s.clear();
		cin>>n>>k;
		rep(i,1,n){
			cin>>x;
			s.insert(x);
		}
		rep(i,1,s.size()){
			dp[i][0]=1;
		}
		it=b(s);
		rep(i,1,k){
			if(i%*it==0)
			dp[1][i]=1;
			else
			dp[1][i]=0;
		}
		it++;
		i=2;
		while(it!=e(s)){
			for(j=1;j<=k;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=*it)
					dp[i][j]+=dp[i][j-*it];
			}
			i++;
			it++;
		}
		for(i=k;i>=0;i--){
			if(dp[s.size()][i])
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
