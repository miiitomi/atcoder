#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    ll m = 0;
    vector<ll> V(N), A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    vector<int> ans;
    ans.reserve(N);
    for (int i = 0; i < N; i++) {
        ll a = A[i], b = B[i];
        V[i] = a - b;
        if (i == 0) m = a-b;
        else m = max(m, a-b);
    }

    for (int i = 0; i < N; i++) {
        if (V[i] == m) ans.push_back(i+1);
    }
    
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i != (int)ans.size()-1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
