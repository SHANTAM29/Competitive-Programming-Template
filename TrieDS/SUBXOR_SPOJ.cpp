#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
#define all(v) v.begin(),v.end()
using namespace std;
struct Node{
    int cnt;
    Node *next[2];
    Node(){
        cnt = 0;
        for(int i=0;i<2;i++){
            next[i] = NULL;
        }
    }
}*root;
int N,K;
string STR;
int LEN;
string which;
void insert(Node *temp,int currIdx)
{
    temp->cnt++;
    if(currIdx >= LEN){
        return;
    }
    if(temp->next[STR[currIdx]-'0'] == NULL){
        temp->next[STR[currIdx]-'0'] = new Node();
    }
    insert(temp->next[STR[currIdx]-'0'],currIdx+1);
}
long long query(Node *temp,int currIdx,int currIdx2)
{
    if(currIdx >= LEN){
        return 0;
    }
    if(which[currIdx2] == '0'){
        if(temp->next[STR[currIdx]-'0'] == NULL){
            return 0;
        }
        else{
            return query(temp->next[STR[currIdx]-'0'],currIdx+1,currIdx2+1);
        }
    }
    else{
        long long fans = 0;
        if(temp->next[STR[currIdx]-'0'] != NULL){
            fans += (temp->next[STR[currIdx]-'0'])->cnt;
        }
        for(int i=0;i<2;i++){
            if(i != STR[currIdx]-'0'){
                if(temp->next[i] != NULL){
                    fans += query(temp->next[i],currIdx+1,currIdx2+1);
                }
            }
        }
        return fans;
    }
}
string func(int x)
{
    string ans = "";
    while(x){
        if(x%2){
            ans += "1";
        }
        else{
            ans += "0";
        }
        x/=2;
    }
    while((ans.length()+1)%25)
        ans+="0";
    reverse(all(ans));
    return ans;
}
int main()
{
    boost;
    int T;
    cin>>T;
    while(T--){
        root = new Node();
        cin>>N>>K;
        int val = 0,x;
        long long fans = 0;
        which = func(K);
        STR = func(0);
        LEN = STR.length();
        insert(root,0);
        for(int i=1;i<=N;i++){
            cin>>x;
            val ^= x;
            STR = func(val);
            LEN = STR.length();
            fans += query(root,0,0);
            insert(root,0);
        }
        cout<<fans<<endl;
    }
    return 0;
}