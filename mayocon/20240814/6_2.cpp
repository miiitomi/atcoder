#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const ll B = 1000;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    ll Q;
    cin >> Q;
    vector<vector<ll>> Queries(Q, vector<ll>(3, 0));
    for (int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;
        Queries[q] = {q, l-1, r};
    }
    sort(Queries.begin(), Queries.end(), [](const vector<ll> &l, const vector<ll> &r) {
        if (l[1]/B != r[1]/B) return l[1]/B < r[1]/B;
        return l[2] < r[2];
    });
    vector<ll> cnt(N, 0);
    ll tmp = 0, left = 0, right = 0;
    vector<ll> ans(Q);
    for (vector<ll> &v : Queries) {
        ll q = v[0], l = v[1], r = v[2];
        while (right < r) {
            cnt[A[right]]++;
            if (cnt[A[right]] % 2 == 0) tmp++;
            right++;
        }
        while (r < right) {
            right--;
            cnt[A[right]]--;
            if (cnt[A[right]] % 2 == 1) tmp--;
        }
        while (left < l) {
            cnt[A[left]]--;
            if (cnt[A[left]] % 2 == 1) tmp--;
            left++;
        }
        while (l < left) {
            left--;
            cnt[A[left]]++;
            if (cnt[A[left]] % 2 == 0) tmp++;
        }
        ans[q] = tmp;
    }
    for (ll a : ans) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
