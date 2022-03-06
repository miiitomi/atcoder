#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll x, int N, vector<ll> &H, vector<ll> &S) {
    vector<ll> V(N);
    for (int i = 0; i < N; i++) {
        if (H[i] > x) return false;
        V[i] = (x - H[i]) / S[i];
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++) {
        if (V[i] < i) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

    ll left = -1;
    ll right = 1e18;
    while (right - left > 1) {
        ll mid = (left + right) / 2LL;
        if (f(mid, N, H, S)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}
