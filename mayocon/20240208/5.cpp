// https://atcoder.jp/contests/abc281/tasks/abc281_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll tmp = 0;
    multiset<ll> S, L;
    for (int i = 0; i < M; i++) {
        ll a = A[i];
        if ((int)S.size() < K) {
            S.insert(a);
            tmp += a;
        } else if (a < *S.rbegin()) {
            ll b = *S.rbegin();
            S.erase(S.find(b));
            tmp += a - b;
            S.insert(a);
            L.insert(b);
        } else {
            L.insert(a);
        }
    }

    cout << tmp << " ";
    int l = 0, i = M;
    while (i < N) {
        ll a = A[l];
        if (L.find(a) != L.end()) {
            L.erase(L.find(a));
        } else {
            tmp -= a;
            S.erase(S.find(a));
        }

        ll b = A[i];
        L.insert(b);

        while ((int)S.size() < K) {
            ll s = *L.begin();
            L.erase(L.begin());
            tmp += s;
            S.insert(s);
        }

        while (!L.empty() && *S.rbegin() > *L.begin()) {
            ll x = *L.begin();
            L.erase(L.begin());
            ll y = *S.rbegin();
            S.erase(S.find(y));
            tmp += x - y;
            S.insert(x);
            L.insert(y);
        }

        cout << tmp << " ";

        l++;
        i++;
    }
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
