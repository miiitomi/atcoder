// https://atcoder.jp/contests/abc173/tasks/abc173_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;


void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (a != 0) A.push_back(a);
    }
    if (K == 1) {
        sort(A.begin(), A.end());
        if (A.back() > 0 || (int)A.size() == N) {
            cout << ((mint)A.back()).val() << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    }
    if ((int)A.size() < K) {
        cout << 0 << endl;
        return;
    }
    ll p = 0, m = 0;
    for (ll a : A) {
        if (a > 0) p++;
        else m++;
    }
    bool can_be_larger_than_zero = false;
    for (ll a = 0; a <= p; a++) {
        if (a + m < K) continue;
        ll b = K - a;
        if (b % 2 == 0) {
            can_be_larger_than_zero = true;
            break;
        }
    }
    if (!can_be_larger_than_zero) {
        if ((int)A.size() < N) {
            cout << 0 << endl;
            return;
        } else {
            mint ans = 1;
            sort(A.begin(), A.end(), [](const ll &l, const ll &r) {return abs(l) < abs(r);});
            for (int k = 0; k < K; k++) ans *= A[k];
            cout << ans.val() << endl;
            return;
        }
    }
    sort(A.begin(), A.end(), [](const ll &l, const ll &r) {return abs(l) > abs(r);});
    p = 0;
    m = 0;
    for (int i = 0; i < K; i++) {
        if (A[i] > 0) p++;
        else m++; 
    }
    if (m % 2 == 0) {
        mint ans = 1;
        for (int i = 0; i < K; i++) ans *= A[i];
        cout << ans.val() << endl;
        return;
    }
    pair<ll,ll> q1{K-1LL, -1LL}, q2{-1LL, -1LL};
    for (int i = K; i < (int)A.size(); i++) {
        if ((A[K-1] > 0) == (A[i] > 0)) {
            if (q2.second == -1) q2.second = i;
        } else {
            if (q1.second == -1) q1.second = i;
        }
    }
    for (int i = K-2; i >= 0; i--) {
        if ((A[K-1]>0) != (A[i] > 0)) {
            q2.first = i;
            break;
        }
    }
    if ((q1.first == -1) || (q1.second == -1)) {
        swap(q1, q2);
    } else if (!(q2.first == -1 || q2.second == -1)) {
        if (abs(A[q1.first]*A[q2.second]) > abs(A[q2.first]*A[q1.second])) {
            swap(q1, q2);
        }
    }

    mint ans = 1;
    for (int k = 0; k < (int)A.size(); k++) {
        if ((k < K && k != q1.first) || k == q1.second) ans *= (mint)A[k];
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
