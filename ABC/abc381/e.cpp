#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct DisjointSparseTable {
    T identity_element = (T)0;    // TODO: Change identity_element if needed. e.g.) 0, 1, INF, etc.
    T f(T l, T r) {return max(l, r);}    // TODO: Change the function f if needed. e.g) min, max, etc.
    vector<vector<T>> st;
    vector<int> lookup;

    DisjointSparseTable(const vector<T> &v) {
        int b = 0;
        while ((1 << b) <= (int)v.size()) ++b;
        st.resize(b, vector<T>(v.size(), identity_element));
        for (int i = 0; i < (int)v.size(); i++) st[0][i] = v[i];
        for (int i = 1; i < b; i++) {
        int shift = 1 << i;
        for (int j = 0; j < (int)v.size(); j += (shift << 1)) {
                int t = min(j + shift, (int)v.size());
                st[i][t - 1] = v[t - 1];
                for (int k = t - 2; k >= j; k--) st[i][k] = f(v[k], st[i][k + 1]);
                if ((int)v.size() <= t) break;
                st[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for (int k = t + 1; k < r; k++) st[i][k] = f(st[i][k - 1], v[k]);
            }
        }
        lookup.resize(1 << b);
        for (int i = 2; i < (int)lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    T query(int l, int r) {
        // Return the answer in the interval [l, r).
        if (l >= --r) return st[0][l];
        int p = lookup[l ^ r];
        return f(st[p][l], st[p][r]);
    }
};

void solve() {
    ll N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> one, two, slash(N, 0);
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') one.push_back(i);
        else if (S[i] == '2') two.push_back(i);
        else slash[i] = 1;
    }
    DisjointSparseTable<int> dst(slash);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (dst.query(l, r)==0) {
            cout << 0 << "\n";
            continue;
        }

        int i = distance(one.begin(), lower_bound(one.begin(), one.end(), l));
        int j = distance(two.begin(), lower_bound(two.begin(), two.end(), r));
        int left = 0, right = N;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (i + mid-1 < (int)one.size() && j-mid >= 0 && one[i+mid-1] < two[j-mid] && dst.query(one[i+mid-1],two[j-mid])) {
                left = mid;
            } else {
                right = mid;
            }
        }
        cout << 1 + 2*left << "\n";
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
