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
#define SIZE 500001
#define SZ 1000001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int phi[SIZE];
int A[SZ];
int F[SIZE];
bool isPrime[SIZE];
int BIT[SZ];
void solve()
{
	mem(isPrime,true);
	isPrime[0] = isPrime[1] = false;
	for(int i=0;i<SIZE;i++){
		phi[i] = i;
	}
	for(int i=2;i<SIZE;i++){
		if(isPrime[i]){
			phi[i] -= phi[i]/i; 
		}
		else{
			continue;
		}
		for(int j=2*i;j<SIZE;j+=i){
			phi[j] -= phi[j]/i;
			isPrime[j] = false;
		}
	}
	for(int i=0;i<SIZE;i++){
		F[i] = phi[i];
	}
	for(int i=2;i<SIZE;i++){
		for(int j=i;j<SIZE;j+=i){
			int temp = j/i;
			F[j] = (F[j] + (i*phi[temp])%MOD)%MOD; 
		}
	}
}
void upd(int i,int val)
{
	while(i<SZ){
		BIT[i] = (BIT[i] + val)%MOD;
		if(BIT[i] < 0)
		BIT[i]+=MOD;
		i+=i&(-i);
	}
}
int query(int i)
{
	int fans = 0;
	while(i){
		fans = (fans+BIT[i])%MOD;
		i-=i&(-i);
	}
	return fans;
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
	//cout<<"Case "<<tt<<": ";
	solve();
	int i,N,Q;
	cin>>N;
	forp(i,1,N){
		cin>>A[i];
		upd(i,F[A[i]]);
	}
	cin>>Q;
	while(Q--){
		char type;
		int X,Y;
		cin>>type>>X>>Y;
		if(type=='C'){
		    int fans = query(Y)-query(X-1);
		    if(fans < 0)
		    fans+=MOD;
			cout<<fans<<endl;
		}
		else{
			upd(X,-F[A[X]]);
			A[X] = Y;
			upd(X,F[A[X]]);
		}
	}
	return 0;
}
