#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int> pq;
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == 0){
            if(pq.size() == 0){
                cout << "0\n";
            }
            else{
                cout << -pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(-num);
        }
    }
}