#include <iostream>
#include <vector>
int main(){
    int iter_num = 0;
    std::cin >> iter_num;
    for(int i = 0; i < iter_num; i++){
        int k, n;
        std::cin >> k >> n;
        std::vector<int> arr1;
        for(int j = 1; j < n+1; j++){
            arr1.push_back(j);
        }
        for(int j = 0; j < k; j++){
            for(int p = 1; p < n; p++){
                arr1[p] += arr1[p-1];
            }
        }
        std::cout << arr1[n-1] << std::endl;
    }
}