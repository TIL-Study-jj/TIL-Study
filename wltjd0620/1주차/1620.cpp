// https://www.acmicpc.net/problem/1620
// 나는야 포켓몬 마스터 이다솜

#include <bits/stdc++.h>
using namespace std;
// 첫째줄 : 포켓몬 개수 n, 맞춰야 하는 문제 개수 m / 1보다 크거나 같고, 100000보다 작거나 같은 자연수

// n개의 줄 동안 포켓몬의 번호가 1번인 포켓몬부터 n번인 포켓몬까지 들어옴
// 첫글자만 대문자, 나머지는 소문자
// 일부 포켓몬은 마지막 문제만 대문자일 수도 있음
// 포켓몬이름 최대 길이는 20, 최소는 2

// m개의 줄에 내가 맞춰야 하는 문제 입력으로 들어옴.
// 알파벳으로 들어오면 포켓몬 번호, 숫자로 들어오면 해당 포켓몬 출력
// 들어오는 숫자는 1보다 크거나 같고 n보다 작거나 같음.
// 무조건 도감에 있는 포켓몬 이름만 주어짐.

// 첫째줄부터 m개줄까지 각각의 문제에 대한 답 출력

int n, m;
// vector <string> name;
unordered_map<string, int> nameToIndex;
unordered_map<int,string> indexToName;
string k, na;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m ; // 26, 5
    // cout << n << m;

    for ( int i = 0; i < n; i++){
        cin >> na;
        indexToName[i+1] = na; // 포켓몬 번호를 키로, 이름을 값으로
        nameToIndex[na] = i+1; // 포켓몬 이름을 키로, 인덱스를 값으로
    }

    for ( int i = 0; i < m; i++){
        // 맞춰야 하는 값 k
        cin >> k;
        if(isdigit(k[0])){ // 숫자인 경우
            cout << indexToName[stoi(k)] << "\n";
        } 
        else{ // 문자인 경우
            cout << nameToIndex[k] << "\n";
        }
    }
    return 0;
}

// find(from, to , value) -> O(n)의 시간복잡도 -> 시간초과
// 찾는 경우에 map를 쓰면 O(1)로 훨씬 빨리 풀 수 있게 된다.
// 그래도 시간초과 날 경우에는
// ios::sync_with_stdio(false);
// cin.tie(NULL); 기억하기