#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll f(ll a, ll b, ll c) {
    return a*b + b*c + c*a;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), C(N);
    for (ll &a : A) cin >> a;
    for (ll &b : B) cin >> b;
    for (ll &c : C) cin >> c;
    sort(A.begin(), A.end(), [](const auto &l, const auto &r) {return l > r;});
    sort(B.begin(), B.end(), [](const auto &l, const auto &r) {return l > r;});
    sort(C.begin(), C.end(), [](const auto &l, const auto &r) {return l > r;});
    set<tuple<int,int,int>> st;
    priority_queue<pair<ll,tuple<int,int,int>>> Q;
    Q.push({f(A[0],B[0],C[0]), make_tuple(0,0,0)});
    st.insert(make_tuple(0,0,0));
    for (int k = 1; k <= K; k++) {
        auto [x, t] = Q.top();
        Q.pop();
        if (k == K) {
            cout << x << endl;
            return;
        }
        auto [a,b,c] = t;
        if (a+1 < N && !st.contains(make_tuple(a+1,b,c))) {
            st.insert(make_tuple(a+1,b,c));
            Q.push({f(A[a+1],B[b],C[c]), make_tuple(a+1,b,c)});
        }
        if (b+1 < N && !st.contains(make_tuple(a,b+1,c))) {
            st.insert(make_tuple(a,b+1,c));
            Q.push({f(A[a],B[b+1],C[c]), make_tuple(a,b+1,c)});
        }
        if (c+1 < N && !st.contains(make_tuple(a,b,c+1))) {
            st.insert(make_tuple(a,b,c+1));
            Q.push({f(A[a],B[b],C[c+1]), make_tuple(a,b,c+1)});
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
