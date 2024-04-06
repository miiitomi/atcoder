#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        D[i] %= (A+B);
    }
    sort(D.begin(), D.end());
    ll tmp = D.back() - D.front();
    for (int i = 1; i < N; i++) {
        tmp = min(tmp, A+B-(D[i] - D[i-1]));
    }
    if (tmp <= A-1) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
