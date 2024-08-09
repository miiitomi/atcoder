// https://atcoder.jp/contests/abc253/tasks/abc253_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    L--;
    vector<ll> start(N, 0);
    for (int x = 1; x < N; x++) start[x] = start[x-1] + N-1-(x-1);
    vector<ll> A(N);
    for (int i = 0; i < N; i++) A[i] = i;
    vector<bool> used(N, false);
    ll x = 0, y = N;
    while (y-x > 1) {
        ll m = (x+y)/2;
        if (start[m] <= L) x = m;
        else y = m;
    }
    for (int i = 0; i < x; i++) used[i] = true;
    y = x+1+(L-start[x]);
    while (L < R && y < N) {
        swap(A[x], A[y]);
        y++;
        L++;
    }

    if (L == R) {
        for (ll a: A) cout << a+1 << " ";
        cout << endl;
        return;
    }

    x++;
    deque<ll> B;
    for (ll i = x; i < N; i++) B.push_back(A[i]);
    while (x < N && start[x+1] <= R) {
        A[x] = B.back();
        B.pop_back();
        x++;
    }

    if (x == N) {
        for (ll a : A) cout << a+1 << " ";
        cout << endl;
        return;
    }

    for (int i = x; i < N; i++) {
        A[i] = B.front();
        B.pop_front();
    }
    y = x+1;
    while (start[x] < R) {
        swap(A[x], A[y]);
        y++;
        start[x]++;
    }

    for (ll a : A) cout << a+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
