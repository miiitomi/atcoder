// https://atcoder.jp/contests/abc216/tasks/abc216_g
#include <bits/stdc++.h>
using namespace std;

struct Constraint {
    int L;
    int R;
    int X;
    Constraint(int l, int r, int x): L(l), R(r), X(x) {};
};

bool cmp(const Constraint &l, const Constraint &r) {return l.R < r.R;};

template<typename T>
struct Fenwick {
    int n;
    vector<T> data;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    T sum(int i) {
        // compute sum of a[i] with i in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<Constraint> V;
    V.reserve(M);
    for (int i = 0; i < M; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        V.push_back(Constraint(l, r, x));
    }
    sort(V.begin(), V.end(), cmp);

    Fenwick<int> f(N);
    vector<int> Q;
    vector<int> A(N, 0);
    int tmp = 0;
    for (Constraint &c : V) {
        while (tmp <= c.R) {
            Q.push_back(tmp);
            tmp++;
        }
        int Y = c.X - f.sum(c.L, c.R+1);
        while (Y > 0) {
            Y--;
            int a = Q.back();
            Q.pop_back();
            A[a] = 1;
            f.add(a, 1);
        }
    }

    for (int a : A) cout << a << " ";
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
