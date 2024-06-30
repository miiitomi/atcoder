#include <bits/stdc++.h>
using namespace std;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = {0, 0}; // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a+b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return {x.first+m, x.second};
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        if (a.first > b.first) return a;
        else if (a.first < b.first) return b;
        else if (a.second < b.second) return a;
        else return b;
    }

    void initialize(int i) {
        data[n-1+i] = {0, i};
        i = n-1+i;
        while (i > 0) {
            i = (i-1)/2;
            data[i] = X_operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }


    void eval(int k) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = X_M_operation(data[k], lazy[k]);
        lazy[k] = M_init;
    }

    void _update(int a, int b, M m, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {
            lazy[k] = M_operation(lazy[k], m);
            eval(k);
        } else if (a < r && l < b) {
            _update(a, b, m, k * 2 + 1, l, (l + r) / 2);
            _update(a, b, m, k * 2 + 2, (l + r) / 2, r);
            data[k] = X_operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // Update data[i] with i in [a, b) by multiplying m in M.
    void update(int a, int b, M m) {
        _update(a, b, m, 0, 0, n);
    }

    X _sub_query(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {
            return X_init;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            X vl = _sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = _sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return X_operation(vl, vr);
        }
    }

    // Return the answer in [a, b)
    X query(int a, int b) {
        return _sub_query(a, b, 0, 0, n);
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> L(N), R(N), v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back((int)1e+9);
    v.push_back(((int)1e+9)-1);
    v.push_back(((int)1e+9)-2);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        v.push_back(max(L[i]-1, 0));
        v.push_back(L[i]);
        v.push_back(L[i]+1);
        v.push_back(R[i]-1);
        v.push_back(R[i]);
        v.push_back(min(R[i]+1, (int)1e+9));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        L[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), L[i]));
        R[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), R[i]));
    }

    int M = v.size();
    LazySegmentTree<pair<int,int>, int> lst(M);
    for (int i = 0; i < M; i++) lst.initialize(i);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    for (int i = 0; i < N; i++) {
        int l = L[i], r = R[i];
        lst.update(l+1, r, 1);
        Q.push({l, r});
    }

    int valu = 0;
    pair<int,int> ans = {0, 1};
    priority_queue<int, vector<int>, greater<int>> Q2;

    vector<pair<int,int>> V;
    for (int i = 0; i < M; i++) {
        while (!Q2.empty() && Q2.top() <= i) {
            int r = Q2.top();
            lst.update(r+1, M, -1);
            Q2.pop();
        }
        while (!Q.empty() && Q.top().first <= i) {
            auto [l, r] = Q.top();
            Q.pop();
            lst.update(l+1, r, -1);
            V.push_back({l, r});
        }
        auto [nv, j] = lst.query(i+1, M);
        if (valu < nv) {
            valu = nv;
            ans = {i, j};
        }

        while (!V.empty()) {
            int r = V.back().second;
            V.pop_back();
            lst.update(r+1, M, 1);
            Q2.push(r);
        }
    }

    ans.first = v[ans.first];
    ans.second = v[ans.second];

    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
