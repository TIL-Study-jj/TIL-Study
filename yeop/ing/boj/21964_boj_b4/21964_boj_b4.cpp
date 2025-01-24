#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i = s.size() - 5; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}
