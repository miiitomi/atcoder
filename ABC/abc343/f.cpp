#include <bits/stdc++.h>
using namespace std;

struct Data {
    int first=0, first_size=0, second=0, second_size=0;

    Data() {};
    Data(int f, int fs, int s, int ss): first(f), first_size(fs), second(s), second_size(ss) {};
};

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = Data();  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        if (a.first == b.first) {
            if (a.second == b.second) return Data(a.first, a.first_size + b.first_size, a.second, a.second_size + b.second_size);
            if (a.second < b.second) return Data(a.first, a.first_size + b.first_size, b.second, b.second_size);
            if (a.second > b.second) return Data(a.first, a.first_size + b.first_size, a.second, a.second_size);
        }
        if (a.first > b.first) {
            if (a.second == b.first) return Data(a.first, a.first_size, a.second, a.second_size + b.first_size);
            if (a.second < b.first) return Data(a.first, a.first_size, b.first, b.first_size);
            if (a.second > b.first) return Data(a.first, a.first_size, a.second, a.second_size);
        }
        if (a.first < b.first) {
            if (a.first == b.second) return Data(b.first, b.first_size, a.first, a.first_size + b.second_size);
            if (a.first < b.second) return Data(b.first, b.first_size, b.second, b.second_size);
            if (a.first > b.second) return Data(b.first, b.first_size, a.first, a.first_size);
        }
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
    int N, Q;
    cin >> N >> Q;
    SegmentTree<Data> st(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        st.update(i, Data(a, 1, 0, 0));
    }
    while (Q--) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 1) {
            st.update(l-1, Data(r, 1, 0, 0));
        } else {
            Data res = st.query(l-1, r);
            cout << res.second_size << endl;
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
