// https://atcoder.jp/contests/abc344/tasks/abc344_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M, L;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    vector<ll> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    cin >> L;
    vector<ll> C(L);
    for (int i = 0; i < L; i++) cin >> C[i];

    set<ll> S;
    for (ll a: A) {
        for (ll b : B) {
            for (ll c : C) {
                S.insert(a+b+c);
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        if (S.count(x)) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
