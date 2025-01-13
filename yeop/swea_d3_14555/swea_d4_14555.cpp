#include <iostream>
#include <string>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    for (int i = 1; i < tc + 1; i++) {
        int ans = 0;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') {
                ans += 1;
            }
            if (s[j] == ')' && s[j-1] == '|') {
                ans += 1;
            }
        }
        cout << "#" << i << " " << ans << endl;
    }
}