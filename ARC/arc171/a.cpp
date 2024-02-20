#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (A < 1) {
        N -= A;
        ll tmp = N * ((N+1)/2);
        if (tmp >= B) cout << "Yes\n";
        else cout << "No\n";
    } else if (2*A <= N) {
        ll tmp = A * A;
        tmp += A * (N - 2*A);
        tmp += A * ((N - 2*A + 1)/2);
        tmp += (N - 2*A) * ((N - 2*A + 1)/2);
        if (tmp >= B) cout << "Yes\n";
        else cout << "No\n";
    } else if (A <= N) {
        ll x = 2*A - N;
        A -= x;
        N -= x;
        ll tmp = A * A;
        if (tmp >= B) cout << "Yes\n";
        else cout << "No\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
