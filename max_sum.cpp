#include <vector>
#include <tuple>
#include <iostream>

// source: Průvodce světem algoritmů --> http://pruvodce.ucw.cz/static/pruvodce.pdf

// brute force
// O(n^3)
int max_sum1(std::vector<int> arr) {
    int steps = 0;
    int max = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum = sum + arr[k];
                steps++;
            max = max > sum ? max : sum;
            }
        }
    }
    std::cout << "steps: " << steps << "\n";
    return max;
}

// O(n^2)
int max_sum2(std::vector<int> arr) {
    int steps = 0;
    int max = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum = sum + arr[j];
            steps++;
            max = max > sum ? max : sum;
        }
    }
    std::cout << "steps: " << steps << "\n";
    return max;
}

// only once traverses the array
// O(n)
int max_sum3(std::vector<int> arr) {
    int steps = 0;
    int m = 0;
    int k = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        steps++;
        k = std::max(0, k) + arr[i];
        m = std::max(k, m);
    }
    std::cout << "steps: " << steps << "\n";
    return m;
}

// O(n)
// shows the indices of the elements from the maximal sum
std::tuple<int, int, int> max_sum4(std::vector<int> arr) {
    int steps = 0;
    int m = 0;
    int k = 0;
    int n = arr.size();
    int start_idx = 0;
    int end_idx = 0;
    int old_m;
    for (int i = 0; i < n; ++i) {
        steps++;
        k = std::max(0, k) + arr[i];
        old_m = m;
        m = std::max(k, m);
        if (k == arr[i]) {
            start_idx = i;
        }
        if (old_m < m) {
            end_idx = i;
        }
    }
    std::cout << "steps: " << steps << "\n";
    return std::make_tuple(m, start_idx, end_idx);
}

int main() {
    std::vector<int> arr = {1, -2, 4, 5, -1, -5, 2, 7};
    auto res = max_sum4(arr);

    std::cout << "max sum: " << std::get<0>(res) << "\n";
    std::cout << "start: " << std::get<1>(res) << "\n";
    std::cout << "end: " << std::get<2>(res) << "\n";

    return 0;
}