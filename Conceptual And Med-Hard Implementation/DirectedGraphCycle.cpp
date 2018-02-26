#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
#define SIZE 510
using namespace std;
set<int> g[SIZE];
int N,M;
int par[SIZE];
bool visit[SIZE];
bool isCyclic;
int from,to;
void dfs(int curr)
{
    visit[curr] = true;
    for(int x:g[curr]){
        if(!visit[x]){
            par[x] = curr;
            dfs(x);
            if(isCyclic){
                return ;
            }
        }
        else{
            if(par[x] != -1){
                isCyclic = true;
                from = curr;
                to = x;
                return ;
            }
        }
    }
    par[curr] = -1;
}
bool isCycle()
{
    for(int i=1;i<=N;i++){
        visit[i] = false;
        par[i] = -1;
    }
    isCyclic = false;
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            par[i] = i;
            dfs(i);
            if(isCyclic)
                return true;
        }
    }
    return false;
}
int main()
{
    boost;
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
    }
    if(!isCycle()){
        cout<<"YES"<<endl;
    }
    else{
        //cout<<"Hello"<<endl;
        vector<int> edges;
        while(from != to){
            edges.push_back(from);
            from = par[from];
        }
        edges.push_back(from);
        reverse(edges.begin(),edges.end());
       /* for(int i=0;i<edges.size();i++){
            cout<<edges[i]<<" ";
        }
        cout<<endl;*/
        for(int i=0;i<edges.size();i++){
            if(i==edges.size() - 1){
                g[edges[i]].erase(edges[0]);
                if(!isCycle()){
                    cout<<"YES"<<endl;
                    return 0;
                }
                g[edges[i]].insert(edges[0]);
            }
            else{
                //cout<<edges[i]<<" "<<edges[i+1]<<endl;
                g[edges[i]].erase(edges[i+1]);
                if(!isCycle()){
                    cout<<"YES"<<endl;
                    return 0;
                }
                g[edges[i]].insert(edges[i+1]);
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}