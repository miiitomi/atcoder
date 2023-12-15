#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e+9 + 7;
const ll base = 100;
vector<ll> p(1e+6, 1);

struct Data {
    ll x, siz;
    Data() {x=0; siz=0;}
    Data(ll x_, ll siz_): x(x_), siz(siz_) {}
    bool operator==(const Data &other) {return x == other.x && siz == other.siz;}
    bool operator!=(const Data &other) {return x != other.x || siz != other.siz;}
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
        return Data((a.x*p[b.siz] + b.x)%MOD, a.siz + b.siz);
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

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int x = 1; x < 1e+6; x++) p[x] = p[x-1]*base%MOD;
    ll N, Q;
    string S, T;
    cin >> N >> Q >> S;
    T = S;
    reverse(T.begin(), T.end());
    SegmentTree<Data> st1(N), st2(N);
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'a' + 1;
        st1.update(i, Data(c, 1));
        c = T[i] - 'a' + 1;
        st2.update(i, Data(c, 1));
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, a;
            char c;
            cin >> x >> c;
            x--;
            a = c - 'a' + 1;
            st1.update(x, Data(a, 1));
            st2.update(N-1-x, Data(a, 1));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int u = N-1-r, v = N-1-l;
            if (st1.query(l, r+1) == st2.query(u, v+1)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
