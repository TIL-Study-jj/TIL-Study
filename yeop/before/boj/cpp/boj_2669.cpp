#include <iostream>
#include <utility>
#include <set>
using namespace std;

int main()
{
    set<pair<int, int>> coords; // except duplication
    int x1, y1, x2, y2;
    
    for(int i = 0; i < 4; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                coords.insert(make_pair(x, y)); // using make_pair to add 2nd coord at set
            }
        }    
    }
    
    cout<<coords.size();

    return 0;
}