#include <vector>
#include <tuple>
#include <cmath>
#include <iostream>

int bin_search(std::vector<int> arr, int y){
    int l = 0;
    int r = arr.size();
    int s;
    while(l <= r) {
        s = std::floor((l+r)/2);
        if (y == arr[s]){
            return s;
        }
        if (y > arr[s]){
            l = s+1;
        } else {
            r = s-1;
        }
    }
    return 0;
}

// searching for fair of elements that give the sum s together,
// should take the first appearance of any repeating element
std::tuple<int, int> binary_pair_search(std::vector<int> arr, int s) {
    int i = 0;
    int j = arr.size()-1;
    while (i <= j) {
        if (arr[i] + arr[j] == s) {
            while (arr[j-1] == arr[j]) {
                j--;
            }
            return std::make_tuple(i, j);
        } else if (arr[i] + arr[j] < s) {
            i++;
        } else {
            j--;
        }
    }
    return std::make_tuple(-1, -1);
}

int main() {
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,9};
    int idx = bin_search(arr,6);
    std::cout << "idx: " << idx << '\n';

    auto res = binary_pair_search(arr, 10);
    std::cout << "start: " << std::get<0>(res) << '\n';
    std::cout << "end: " << std::get<1>(res) << '\n';
}
