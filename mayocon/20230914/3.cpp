// https://atcoder.jp/contests/abc187/tasks/abc187_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    vector<ll> X(N);
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        sum -= a;
        X[i] = 2*a + b;
    }
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());

    int ans = 0;
    int i = 0;
    while (sum <= 0) {
        ans++;
        sum += X[i];
        i++;
    }

    cout << ans << endl;
}
