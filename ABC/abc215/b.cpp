#include <bits/stdc++.h>
using namespace std;

int64_t power(int64_t m) {
    int64_t res = 1LL;
    for (int i = 0; i < m; i++) {
        res *= 2LL;
    }
    return res;
}

int main() {
    int64_t N;
    cin >> N;
    int64_t left = 0;
    int64_t right = 63;
    while (right - left > 1) {
        int64_t mid = (left + right) / 2;
        if (power(mid) <= N) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
}
