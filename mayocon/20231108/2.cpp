// https://atcoder.jp/contests/abc321/tasks/abc321_b
#include <bits/stdc++.h>
using namespace std;

bool is_ok(int N, int X, vector<int> A, int y) {
    A.push_back(y);
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 1; i < N-1; i++) ans += A[i];
    return ans >= X;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N-1);
    for (int i = 0; i < N-1; i++) cin >> A[i];

    for (int y = 0; y <= 100; y++) {
        if (is_ok(N, X, A, y)) {
            cout << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
