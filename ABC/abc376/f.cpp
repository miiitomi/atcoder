#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> void chmin(T &l, T r) {if (l > r) l = r;}

ll N;
ll g(ll left, ll right, ll x) {
    if (left == x) return 0;
    else if (right == x) return INF;
    else if (left < x) {
        if (!(left < right && right < x)) return x - left;
        else return left - x + N;
    } else {
        if (!(x < right && right < left)) return left - x;
        else return x - left + N;
    }
}

void solve() {
    ll Q;
    cin >> N >> Q;
    vector<ll> dp(N, INF);
    char h = 'L';
    int t = 0;
    dp[1] = 0;
    while (Q--) {
        char nh;
        int nt;
        cin >> nh >> nt;
        nt--;
        vector<ll> ndp(N, INF);
        if (h == nh) {
            for (int i = 0; i < N; i++) {
                chmin(ndp[i], dp[i]+g(t, i, nt));
                chmin(ndp[(nt-1+N)%N], dp[i]+min(g(i,t,(nt-1+N)%N)+g(t,(nt-1+N)%N,nt), g(t,i,nt)+g(i,nt,(nt-1+N)%N)));
                chmin(ndp[(nt+1)%N], dp[i]+min(g(i,t,(nt+1)%N)+g(t,(nt+1)%N,nt), g(t,i,nt)+g(i,nt,(nt+1)%N)));
            }
        } else {
            for (int i = 0; i < N; i++) {
                chmin(ndp[t], dp[i]+g(i,t,nt));
                chmin(ndp[(nt-1+N)%N], dp[i]+min(g(t,i,(nt-1+N)%N)+g(i,(nt-1+N)%N,nt), g(i,t,nt)+g(t,nt,(nt-1+N)%N)));
                chmin(ndp[(nt+1)%N], dp[i]+min(g(t,i,(nt+1)%N)+g(i,(nt+1)%N,nt), g(i,t,nt)+g(t,nt,(nt+1)%N)));
            }
        }
        swap(dp, ndp);
        h = nh;
        t = nt;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
