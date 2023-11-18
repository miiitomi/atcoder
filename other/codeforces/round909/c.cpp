#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(vector<ll> &v) {
    ll sum = v[0];
    ll ans = sum;
    for (int i = 1; i < (int)v.size(); i++) {
        ll num = v[i];
        sum = max(sum+num, num);
        ans = max(ans, sum);
    }
    return ans;
}

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int idx = 0;
    vector<ll> v;
    ll ans = -1e+18;
    while (idx < N) {
        if (v.empty() || ( ((v.back()+(ll)1e+9)%2) != ((A[idx]+(ll)1e+9)%2))) {
            v.emplace_back(A[idx]);
        } else {
            ans = max(ans, f(v));
            v.resize(0);
            idx--;
        }
        idx++;
    }
    if (!v.empty()) ans = max(ans, f(v));
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
