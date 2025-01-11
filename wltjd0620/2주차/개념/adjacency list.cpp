#include <bits/stdc++.h>
using namespace std;

const int V = 10;
vector <int> adj[10];
int visited[10];

void go(int idx){
    cout << idx << "\n";
    visited[idx] = 1;
    
    for(int k = 0;k < adj[idx].size(); k++){
        if(visited[idx]==1)continue;
        go(k);
    }

}

int main(){
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[3].push_back(1);
    adj[1].push_back(3);

    adj[3].push_back(4);
    adj[4].push_back(3);

    for(int i = 0; i<V ; i++){
        if(adj[i].size()&&visited[i]==0){
            go(i);
        }
    }

}