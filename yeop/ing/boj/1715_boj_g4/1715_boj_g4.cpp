#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, num;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push(-num);
    }
    int duration = 0;
    while(pq.size() != 1){
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        duration += one + two;
        pq.push(one+two);
    }
    cout << -duration;
}