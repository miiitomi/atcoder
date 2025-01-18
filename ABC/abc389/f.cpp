#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int l, r;
int e() {return 0;}
int op(int a, int b) {return max(a, b);};
int mapping(int f, int x) {return x+f;}
int composition(int f, int g) {return f+g;}
int id() {return 0;}

bool f(int x) {return x < l;}
bool g(int x) {return x <= r;}

void solve() {
    int N;
    cin >> N;
    int M = (int)5e+5;
    lazy_segtree<int, op, e, int, mapping, composition, id> lst(M+1);
    for (int i = 1; i <= M; i++) lst.set(i, i);
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        int L = lst.max_right<f>(0);
        int R = lst.max_right<g>(0);
        lst.apply(L, R, 1);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        cout << lst.get(x) << "\n";
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
