#include <bits/stdc++.h>
using namespace std;

template<typename T> struct erasable_priority_queue {
    priority_queue<T> Q, R;

    void push(T x) {
        Q.push(x);
    }

    void erase(T x) {
        R.push(x);
    }

    T top() {
        T x = Q.top();
        while (!R.empty() && R.top() == x) {
            Q.pop();
            R.pop();
            x = Q.top();
        }
        return x;
    }

    int size() {
        return Q.size() - R.size();
    }

    bool empty() {
        return Q.size() == R.size();
    }
};

struct DataStructure {
    int n;
    vector<erasable_priority_queue<int>> data;

    DataStructure(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.resize(2*n-1);
        for (int i = 0; i < 2*n-1; i++) data[i].push(0);
    }

    void _update(int a, int b, int x, bool add, int k, int l, int r) {
        if (a <= l && r <= b) {
            if (add) data[k].push(x);
            else data[k].erase(x);
        } else if (a < r && l < b) {
            _update(a, b, x, add, k*2+1, l, (l+r)/2);
            _update(a, b, x, add, k*2+2, (l+r)/2, r);
        }
    }

    void update(int a, int b, int x, bool add) {
        _update(a, b, x, add, 0, 0, n);
    }

    int query(int i) {
        i = n - 1 + i;
        int ans = data[i].top();
        while (i > 0) {
            i = (i - 1) / 2;
            ans = max(ans, data[i].top());
        }
        return ans;
    }
};

void solve() {
    int N;
    cin >> N;
    DataStructure ds(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ds.update(i, i+1, a, true);
    }

    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q), x(Q);
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> l[q] >> r[q] >> x[q];
            l[q]--;
            r[q]--;
            ds.update(l[q], r[q]+1, x[q], true);
        } else if (t == 2) {
            int i;
            cin >> i;
            i--;
            ds.update(l[i], r[i]+1, x[i], false);
        } else {
            int i;
            cin >> i;
            i--;
            cout << ds.query(i) << "\n";
        }
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
