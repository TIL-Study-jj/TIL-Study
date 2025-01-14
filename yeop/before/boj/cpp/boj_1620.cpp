#include <iostream>
#include <map>
#include <cstdio> // using scanf, prints
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    map<string, int> pd1;
    map<int, string> pd2;

    for (int i = 0; i < n; i++) {
        char p[100]; // pokemon name : no std::string allowed at scanf
        scanf("%s", p);
        pd1[p] = i + 1;
        pd2[i + 1] = p;
    }

    for (int i = 0; i < m; i++) {
        char input[100];
        scanf("%s", input); 
        string p = input;

        if (('a' <= p[0] && p[0] <= 'z') || ('A' <= p[0] && p[0] <= 'Z')) { // if input is pokemon name
            printf("%d\n", pd1[p]); 
        } 
        else { // if input is number
            printf("%s\n", pd2[stoi(p)].c_str()); // c_str() <- Essential (if not using c_str with printf, string will changing weird)
        }
    }

    return 0;
}
