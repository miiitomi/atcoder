// https://atcoder.jp/contests/abc133/tasks/abc133_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), X(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i % 2 == 0) X[0] += A[i];
        else X[0] -= A[i];
    }

    for (int i = 0; i < N-1; i++) {
        X[i+1] = 2*A[i] - X[i];
    }
    for (ll x : X) cout << x << " ";
    cout << endl;
}
