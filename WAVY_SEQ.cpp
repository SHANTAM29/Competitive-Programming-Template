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
int BIT[SIZE][2];
vector<int> A[26];
int BIT2[SIZE];
void upd(int i,int j,int val)
{
	while(i<SIZE){
		BIT[i][j] = (BIT[i][j]+val)%MOD;
		i+=i&(-i);
	}	
}
int query(int i,int j)
{
	int sum = 0;
	while(i){
		sum = (sum + BIT[i][j])%MOD;
		i-=i&(-i);
	}
	return sum;
}
void upd2(int i,int val)
{
	while(i<SIZE){
		BIT2[i]+=val;
		i+=i&(-i);
	}
}
int query2(int i)
{
	int sum=0;
	while(i){
		sum+=BIT2[i];
		i-=i&(-i);
	}
	return sum;
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
	int i,N;
	string s;
	cin>>N;
	forp(i,1,N){
		cin>>s;
		A[s[0]-'a'].pb(len(s));
	}
	int ans=0;
	for(int j=0;j<26;j++){
		if(A[j].size() < 2)
		continue;
		mem(BIT,0);
		mem(BIT2,0);
		upd2(A[j][0],1);
		forp(i,1,A[j].size()-1){
			int less_than = query2(A[j][i]-1);
			int great_than =  query2(SIZE-1)-query2(A[j][i]);
			if(great_than < 0)
			great_than+=MOD;
			int val1 = query(A[j][i]-1,1);
			int val2 = query(SIZE-1,0)-query(A[j][i],0);
			if(val2 < 0){
			    val2+=MOD;
			}
			ans = (ans + ((val1+less_than)%MOD + (val2+great_than)%MOD)%MOD)%MOD;
			upd(A[j][i],0,(val1+less_than)%MOD);
			upd(A[j][i],1,(val2+great_than)%MOD);
			upd2(A[j][i],1);
		}	
	}
	cout<<ans<<endl;
	return 0;
}
