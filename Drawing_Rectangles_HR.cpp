#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
using namespace std;
set<pair<int,int> > points;
map<int,int> hshX;
set<int> S1,S2;
int K1,K2;
map<int,int> hshY;
map<int,int> revX,revY;
vector<int> col;
vector<int> row;
set<pair<int,int> > edges;
set<int> whose;
void print()
{
    cout<<row.size()<<endl;
    for(int i=0;i<row.size();i++){
        cout<<row[i]<<" ";
    }
    cout<<endl;
    cout<<col.size()<<endl;
    for(int i=0;i<col.size();i++){
        cout<<col[i]<<" ";
    }
    cout<<endl;
}
/* Implementation Taken From http://zobayer.blogspot.in/2010/05/maximum-matching.html */
#define MAX 1000010
#define NIL 0
#define INF (1<<28)
vector<pair<int,int> > POINTS_X[MAX];
vector<pair<int,int> > POINTS_Y[MAX];
vector< int > G[MAX];
vector< int > GG[MAX];
bool visit[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m


bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs()){
        for(i=1; i<=n; i++){
            if(match[i]==NIL && dfs(i)){
                matching++;
            }
        }
    }
    return matching;
}
void hoJaBhai(int curr)
{
    visit[curr] = true;
    for(int x:GG[curr]){
        if(!visit[x]){
            hoJaBhai(x);
        }
    }
}
void kaamKarApna()
{
    for(pair<int,int> x:points){
        int from = hshX[x.first];
        int to = hshY[x.second] + n;
        if(edges.find(make_pair(from,to)) != edges.end()){
            GG[to].push_back(from);
        }
        else{
            GG[from].push_back(to);
        }
    }
    for(int x:whose){
        if(!visit[x]){
            hoJaBhai(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            row.push_back(revX[i]);
        }
    }
    for(int i=n+1;i<=n+m;i++){
        if(visit[i]){
            col.push_back(revY[i-n]);
        }
    }
}
int main()
{
    boost;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x2-x1 <= y2-y1){
            for(int j=x1;j<=x2;j++){
                POINTS_X[j].push_back(make_pair(y1,y2));
            }
        }
        else{
            for(int j=y1;j<=y2;j++){
                POINTS_Y[j].push_back(make_pair(x1,x2));
            }
        }
        /*for(int j=x1;j<=x2;j++){
            for(int k=y1;k<=y2;k++){
                points.insert(make_pair(j,k));
                S1.insert(j);
                S2.insert(k);
            }
        }*/
    }
    //assert(false);
    for(int i=0;i<=300000;i++){
        if(POINTS_X[i].size()){
            S1.insert(i);
            sort(POINTS_X[i].begin(),POINTS_X[i].end());
            int which = 0;
            for(int j=0;j<POINTS_X[i].size();j++){
                which = max(which,POINTS_X[i][j].first);
                while(which <= POINTS_X[i][j].second){
                    points.insert(make_pair(i,which));
                    S2.insert(which);
                    which++;
                }
            }
        }
    }
    for(int i=0;i<=300000;i++){
        if(POINTS_Y[i].size()){
            S2.insert(i);
            sort(POINTS_Y[i].begin(),POINTS_Y[i].end());
            int which = 0;
            for(int j=0;j<POINTS_Y[i].size();j++){
                which = max(which,POINTS_Y[i][j].first);
                while(which <= POINTS_Y[i][j].second){
                    points.insert(make_pair(which,i));
                    S1.insert(which);
                    which++;
                }
            }
        }
    }
    for(int x:S1){
        hshX[x] = ++K1;
        revX[K1] = x;
    }
    for(int x:S2){
        hshY[x] = ++K2;
        revY[K2] = x;
    }
    n = K1;
    m = K2;
    for(pair<int,int> x:points){
        int from = hshX[x.first];
        int to = hshY[x.second] + n;
        G[from].push_back(to);
        //G[to].push_back(from);
    }
    int ff = hopcroft_karp();
    cout<<ff<<endl;
    for(int i=1;i<=n;i++){
        if(match[i]){
            edges.insert(make_pair(i,match[i]));
        }
        else{
            whose.insert(i);
        }
    }
    kaamKarApna();
    print();
    return 0;
}