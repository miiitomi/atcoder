// https://atcoder.jp/contests/abc123/tasks/abc123_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A=2e+18;
    cin >> N;
    for (int i = 0; i < 5; i++) {
        ll b;
        cin >> b;
        A = min(A, b);
    }

    cout << (N+A-1) / A + 4 << endl;
}
