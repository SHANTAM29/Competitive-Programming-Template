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
map<int,int> m;
map<int,int>* ans[SIZE];
set<int> diff_color;
int color[SIZE];
vector<int> v[SIZE];
ll fans=0;
int dist_node[SIZE];
void dfs(int i,int par)
{
	if(i!=1 and v[i].size()==1){
		ans[i] = new map<int,int>;
		(*ans[i])[color[i]]=1;
		ll ans_of_leaf=0;
		ans_of_leaf+=diff_color.size();
		if(m[color[i]]==1)
        {
            ans_of_leaf--;
            dist_node[i]=1;
        }
		//cout<<ans_of_leaf<<endl;
		fans += ans_of_leaf;
		return ;
	}
	int sz=0;
	int in=0;
	for(int j=0;j<v[i].size();j++){
		int ch=v[i][j];
		if(ch==par)
		continue;
		dfs(ch,i);
		if((*ans[ch]).size() > sz){
			sz = (*ans[ch]).size();
			in = ch;
		}
	}
	ans[i]=ans[in];
	map<int,int> :: iterator itr;
    int dist=0;
	for(int j=0;j<v[i].size();j++){
		int ch=v[i][j];
		if(ch==par or ch==in)
		continue;
		for(itr = (*ans[ch]).begin() ; itr!=(*ans[ch]).end();itr++){
			if((*ans[i]).find(itr->first)==(*ans[i]).end())
                (*ans[i])[itr->first] = 0;
            (*ans[i])[itr->first] += itr->second;
            if(m[itr->first]==(*ans[i])[itr->first])
                    dist++;
		}
	}
	if((*ans[i]).find(color[i])==(*ans[i]).end())
        (*ans[i])[color[i]] = 0;
    (*ans[i])[color[i]]++;
    if(m[color[i]] == (*ans[i])[color[i]])
            	dist++;
    dist+=dist_node[in];
    dist_node[i]=dist;
	ll ans_of_node = diff_color.size() - dist;
	ans_of_node = ans_of_node*((*ans[i]).size());
	fans += ans_of_node;
	//cout<<dist<<" "<<ans_of_node<<endl;
}
int main()
{
	boost;
	//cin.tie(0);
	//cout<<"Case #"<<tt<<": ";
	int i,n,x,y;
	cin>>n;
	forp(i,1,n){
		cin>>color[i];
		m[color[i]]++;
		diff_color.insert(color[i]);
	}
	//cout<<diff_color.size()<<endl;
	forp(i,1,n-1){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	cout<<fans<<endl;
	return 0;
}
