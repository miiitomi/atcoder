// https://atcoder.jp/contests/abc113/tasks/abc113_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, T, A;
    cin >> N >> T >> A;
    T *= 1000;
    A *= 1000;
    vector<ll> H(N), d(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        d[i] = abs(A - (T - H[i]*6));
    }

    cout << distance(d.begin(), min_element(d.begin(), d.end())) + 1 << endl;
}
