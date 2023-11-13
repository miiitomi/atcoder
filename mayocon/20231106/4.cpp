// https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(N), C(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) B[i] = A[i];
        else B[i] = gcd(B[i-1], A[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) C[i] = A[i];
        else C[i] = gcd(C[i+1], A[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        if (i == 0) tmp = C[i+1];
        else if (i == N-1) tmp = B[i-1];
        else tmp = gcd(B[i-1], C[i+1]);
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}
