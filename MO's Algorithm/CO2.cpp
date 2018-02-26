/* A New Start MO's Algorithm*/
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
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int a[SIZE];
int fans[SIZE];
int cnt[SIZE];
pair<pair<int,int>,int> query[SIZE];
int ans;
int block;
bool cmp(pair<pair<int,int>,int> A,pair<pair<int,int>,int> B)
{
	if(A.ff.ff/block != B.ff.ff/block) return A.ff.ff/block < B.ff.ff/block;
	return A.ff.ss <= B.ff.ss;
}
void add(int id)
{
	if (cnt[a[id]-1] == 0 and cnt[a[id]+1] == 0) ++ans;
  	if (cnt[a[id]-1] and cnt[a[id]+1]) --ans;
  	++cnt[a[id]];
}
void remove(int id)
{
	if (cnt[a[id]-1] == 0 and cnt[a[id]+1] == 0) --ans;
  	if (cnt[a[id]-1] and cnt[a[id]+1]) ++ans;
  	--cnt[a[id]];
}
int main()
{  	
	boost;
	//cin.tie(0);
	//cout<<"Case #"<<tt<<": ";
	int i,l,r,q,n;
	cin>>n>>q;
	block = sqrt(n);
	forp(i,1,n){
		cin>>a[i];
	}
	forp(i,1,q){
		cin>>l>>r;
		query[i]=mp(mp(l,r),i);
	}
	sort(query+1,query+1+q,cmp);
	int idxl=1;
	int idxr=0;
	forp(i,1,q){
		l = query[i].ff.ff;
		r = query[i].ff.ss;
		while (idxr < r){
    		add (++idxr);
   		}	
   		while (idxr > r) {
    		remove (idxr);
     		--idxr;
   		}
    	while (idxl < l) {
      		remove (idxl);
      		idxl++;
    	}
   		while (idxl > l) {
    		add (--idxl);
   		}
		fans[query[i].ss]=ans;
	}
	forp(i,1,q){
		cout<<fans[i]<<endl;
	}
	return 0;
}
