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
#define SIZE 300010

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
string str;
int N,M;
set<int> edges[SIZE];
set<int> rev[SIZE];
bool visit[SIZE];
int dp[SIZE];
vector<int> order,component;
void dfs1 (int v) {
    visit[v] = true;
    for(int x:edges[v])
        if (!visit[x])
            dfs1 (x);
    order.push_back (v);
}

void dfs2 (int v) {
    visit[v] = true;
    component.push_back (v);
    for(int x:rev[v])
        if (!visit[x])
            dfs2 (x);
}
int func(int curr)
{
    int ret = 0;
    for(int i=1;i<=N;i++){
        dp[i] = 0;
    }
    for(int i=0;i<order.size();i++){
        int mx = 0;
        for(int j:rev[order[i]]){
            mx = max(mx,dp[j]);
        }
        dp[order[i]] = mx;
        if(str[order[i]-1]-'a' == curr){
            dp[order[i]]++;
        }
    }
    for(int i=1;i<=N;i++){
        ret = max(ret,dp[i]);
    }
    return ret;
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
    cin>>N>>M;
    cin>>str;
    for(int i=1;i<=M;i++){
        int x,y;
        cin>>x>>y;
        if(x == y){
            cout<<"-1"<<endl;
            return 0;
        }
        else{
            edges[x].insert(y);
            rev[y].insert(x);
        }
    }
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            dfs1(i);
        }
    }
    for(int i=1;i<=N;i++){
        visit[i] = false;
    }
    for(int i=1;i<=N;i++) {
        int v = order[N-i];
        if (!visit[v]) {
            dfs2 (v);
            if(component.size() >= 2){
                //cout<<"Cycle"<<endl;
                cout<<"-1"<<endl;
                return 0;
            }
            component.clear();
        }
    }
    reverse(order.begin(),order.end());
    int fans = 0;
    for(int i=0;i<26;i++){
        fans = max(fans,func(i));
    }
    cout<<fans<<endl;
    return 0;
}