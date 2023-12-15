// https://atcoder.jp/contests/abc135/tasks/abc135_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, sum = 0;
    cin >> N;
    vector<ll> A(N+1), B(N);
    for (int i = 0; i < N+1; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < N; i++) {
        int m = min(A[i], B[i]);
        A[i] -= m;
        B[i] -= m;

        m = min(A[i+1], B[i]);
        A[i+1] -= m;
        B[i] -= m;
    }

    ll tmp = 0;
    for (ll a : A) tmp += a;

    cout << sum - tmp << endl;
}
