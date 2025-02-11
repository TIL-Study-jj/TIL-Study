#include <iostream>
#include <algorithm>
using namespace std;
 
int answer;
int totsum;
int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
 
// bool compare(int a, int b){
//     return a > b;
// }
 
void howmany(int level, int limit, int leftweight, int rightweight, int used, int arr[]) { 
    if (level == limit) { 
        answer++;
        return;
    }
    if (leftweight >= totsum - leftweight + rightweight) {
        answer += (1 << (limit - level)) * factorial[limit - level];
        return;
    }
 
    for (int i = 0; i < limit; i++) {
        if (!(used & (1 << i))) { 
            int newUsed = used | (1 << i);
 
            howmany(level + 1, limit, leftweight + arr[i], rightweight, newUsed, arr);
             
            if (leftweight >= rightweight + arr[i]) { 
                howmany(level + 1, limit, leftweight, rightweight + arr[i], newUsed, arr);
            }
        }
    }
}
 
int main() {
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) { 
        int arr[10] = {0};
        answer = 0;
        totsum = 0;
         
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            totsum += arr[j];
        }
        sort(arr, arr + n, greater<int>());
        howmany(0, n, 0, 0, 0, arr);
        cout << "#" << i << " " << answer << "\n";
    }
}