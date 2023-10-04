// https://atcoder.jp/contests/abc171/tasks/abc171_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    vector<ll> X(1e+5 + 1, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        sum += a;
        X[a]++;
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ll b, c;
        cin >> b >> c;
        sum -= b*X[b];
        sum += c*X[b];
        X[c] += X[b];
        X[b] = 0;
        cout << sum << endl;
    }
}
