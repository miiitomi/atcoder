#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = _pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

map<ll, pair<int,int>> MP;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll mean = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mean += A[i];
    }

    if (mean % N != 0) {
        cout << "No" << endl;
        return;
    }

    mean /= N;

    vector<int> P(32, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] == mean) {
            continue;
        }
        ll x = A[i] - mean;
        if (MP.count(x)) {
            auto p = MP[x];
            P[p.first]++;
            P[p.second]--;
        } else {
            cout << "No" << endl;
            return;
        }
    }

    for (int p : P) {
        if (p != 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

    return;
}


int main() {
    for (int p = 0; p <= 31; p++) {
        for (int q = 0; q <= 31; q++) {
            MP[_pow(2, p) - _pow(2, q)] = make_pair(p, q);
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
