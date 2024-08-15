// https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), cnt_a(N, 0), B(N), cnt_b(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        cnt_a[A[i]]++;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
        cnt_b[B[i]]++;
    }
    for (ll b = 0; b < N; b++) {
        if (cnt_b[b] > N-cnt_a[b]) {
            cout << "No\n";
            return;
        }
    }

    vector<ll> p(N+1);
    for (int i = 0; i <= N; i++) p[i] = distance(A.begin(), lower_bound(A.begin(), A.end(), i));
    vector<ll> ng(N+1, 0);
    for (int i = 0; i < N; i++) {
        ll b = B[i];
        if (i < p[b]) {
            ll l = p[b] - i, r = p[b+1] - i;
            ng[l]++;
            ng[r]--;
        } else if (i < p[b+1]) {
            ll l = 0, r = p[b+1] - i;
            ng[l]++;
            ng[r]--;
            l = p[b]+N-i, r = N;
            ng[l]++;
            ng[r]--;
        } else {
            ll l = p[b]+N-i, r = p[b+1]+N-i;
            ng[l]++;
            ng[r]--;
        }
    }
    for (ll k = 0; k < N; k++) {
        if (ng[k] == 0) {
            vector<ll> C(N);
            for (int i = 0; i < N; i++) {
                C[(i+k)%N] = B[i];
            }
            cout << "Yes\n";
            for (ll c : C) cout << c+1 << " ";
            cout << endl;
            return;
        }
        ng[k+1] += ng[k];
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
