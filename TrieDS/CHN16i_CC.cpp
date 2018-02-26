#include <bits/stdc++.h>
#define SIZE 100001
#define boost ios_base::sync_with_stdio(0)
using namespace std;
struct Node{
    int cnt;
    Node* next[26];
    Node(){
        cnt = 0;
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
}*root = new Node();
int N,M;
string s[SIZE];
string STR;
int LEN;
void insert(Node *temp,int currIdx)
{
    temp->cnt++;
    if(currIdx >= LEN){
        return ;
    }
    if(temp->next[STR[currIdx]-'a'] == NULL){
        temp->next[STR[currIdx]-'a'] = new Node();
    }
    insert(temp->next[STR[currIdx]-'a'],currIdx+1);
}
int currAns;
void query(Node *temp,int currIdx, int cnt)
{
    if(currIdx >= LEN){
        return ;
    }
    int x = STR[currIdx]-'a';
    if(temp->next[x] == NULL)
        return ;
    int val = temp->cnt - (temp->next[x])->cnt;
    cnt++;
    cnt = max(0,cnt-val);
    if(cnt >= temp->cnt)
        return ;
    currAns++;
    query(temp->next[x],currIdx+1,cnt);
}
int main()
{
    boost;
    string str;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>s[i];
    }
    for(int i=1;i<=M;i++){
        cin>>str;
        STR = str;
        LEN = STR.length();
        insert(root,0);
    }
    long long fans = 0;
    for(int i=1;i<=N;i++){
        currAns = 0;
        if(root->next[s[i][0]-'a'] != NULL){
            currAns++;
            STR = s[i];
            LEN = STR.length();
            query(root->next[s[i][0]-'a'],1,0);
        }
        fans += currAns;
    }
    cout<<fans<<endl;
    return 0;
} 