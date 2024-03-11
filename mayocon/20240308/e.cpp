// https://atcoder.jp/contests/abc258/tasks/abc258_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll N, Q, X;
    cin >> N >> Q >> X;
    vector<ll> W(N), S(2*N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        S[i+1] = S[i] + W[i];
    }
    for (int i = 0; i < N; i++) {
        S[N+1+i] = S[N+i] + W[i];
    }

    vector<ll> nxt(N, -1), cnt(N, 0);
    for (int i = 0; i < N; i++) {
        ll x = X;
        cnt[i] += (x / S[N]) * N;
        x %= S[N];
        if (x == 0) {
            nxt[i] = i;
            continue;
        }
        int left = 0, right = N;
        while (right - left > 1) {
            int m = (right+left) / 2;
            if (S[i+m] - S[i] >= x) right = m;
            else left = m;
        }
        cnt[i] += right;
        nxt[i] = (i + right) % N;
    }
    vector<int> p, q;
    set<int> st;
    int i = 0;
    while (!st.count(i)) {
        p.push_back(i);
        st.insert(i);
        i = nxt[i];
    }
    while (p.back() != i) {
        q.push_back(p.back());
        p.pop_back();
    }
    q.push_back(i);
    p.pop_back();
    reverse(q.begin(), q.end());

    while (Q--) {
        ll K;
        cin >> K;
        if (K <= (ll)p.size()) {
            cout << cnt[p[K-1]] << "\n";
            continue;
        }
        K -= p.size();
        K--;
        K %= q.size();
        cout << cnt[q[K]] << "\n";
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
