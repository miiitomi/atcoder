// https://atcoder.jp/contests/abc299/tasks/abc299_g
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = INF;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return min(a, b);
    }

    // Update data[i] to a.
    void update(int i, T a) {
        i = n - 1 + i;
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        T vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        T vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(M);
    SegmentTree<int> st(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        st.update(i, a);
        V[a].push_back(i);
    }
    set<pair<int,int>> S;
    for (int a = 0; a < M; a++) S.insert({V[a].back(), a});
    vector<int> B(M);
    int l = 0;
    for (int t = 0; t < M; t++) {
        int r = S.begin()->first;
        int a = st.query(l, r+1);
        while (st.query(l, l+1) != a) {
            st.update(l, INF);
            l++;
        }
        S.erase({V[a].back(), a});
        for (int v : V[a]) st.update(v, INF);
        B[t] = a;
        l++;
    }

    for (int b : B) cout << b+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
