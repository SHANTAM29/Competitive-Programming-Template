#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
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
}*root = new Node();
string STR;
const int LEN = 30;
void insert(Node *temp,int currIdx)
{
    temp->cnt++;
    if(currIdx >= LEN)
        return ;
    if(temp->next[STR[currIdx]-'0'] == NULL){
        temp->next[STR[currIdx]-'0'] = new Node();
    }
    insert(temp->next[STR[currIdx]-'0'],currIdx+1);
}
void del(Node *temp,int currIdx)
{
    temp->cnt--;
    if(currIdx >= LEN)
        return ;
    del(temp->next[STR[currIdx]-'0'],currIdx+1);
    if(temp->next[STR[currIdx]-'0']->cnt == 0){
        free(temp->next[STR[currIdx]-'0']);
        temp->next[STR[currIdx]-'0'] = NULL;
    }
    return ;
}
string func(int x)
{
    string s = "";
    while(x){
        if(x%2){
            s = s + "1";
        }
        else{
            s = s + "0";
        }
        x/=2;
    }
    while((s.length()+1) % 31){
        s = s + "0";
    }
    reverse(s.begin(),s.end());
    return s;
}
int fans;
void query(Node *temp,int currIdx)
{
    if(currIdx >= LEN)
        return ;
    fans *= 2;
    if(STR[currIdx] == '0'){
        if(temp->next[1] == NULL){
            query(temp->next[0],currIdx+1);
        }
        else{
            fans++;
            query(temp->next[1],currIdx+1);
        }
    }
    else{
        if(temp->next[0] == NULL){
            query(temp->next[1],currIdx+1);
        }
        else{
            fans++;
            query(temp->next[0],currIdx+1);
        }
    }
}
int main()
{
    boost;
    int N;
    cin>>N;
    STR = func(0);
    insert(root,0);
    while(N--){
        char type;
        int x;
        cin>>type;
        if(type == '+'){
            cin>>x;
            STR = func(x);
            insert(root,0);
        }
        else if(type == '-'){
            cin>>x;
            STR = func(x);
            del(root,0);
        }
        else{
            cin>>x;
            fans = 0;
            STR = func(x);
            query(root,0);
            cout<<fans<<endl;
        }
    }
    return 0;
}
