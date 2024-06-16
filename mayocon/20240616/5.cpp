// https://atcoder.jp/contests/abc241/tasks/abc241_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<bool> reached(N, false);
    ll x = 0;
    vector<ll> path;
    while (!reached[x % N]) {
        reached[x%N] = true;
        path.push_back(x%N);

        x += A[x%N];
        K--;
        if (K == 0) {
            cout << x << endl;
            return;
        }
    }

    ll cnt = 0, tmp=0;
    for (int i = path.size()-1; i >= 0; i--) {
        tmp += A[path[i]%N];
        cnt++;
        if (path[i]%N == x%N) break;
    }

    x += (K/cnt)*tmp;
    K %= cnt;

    while (K--) {
        x += A[x%N];
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
