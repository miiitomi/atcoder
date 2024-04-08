#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<int,int> mp;
    for (int i = 0; i < N; i++) {
        int a, c;
        cin >> a >> c;
        if (mp.count(c)) {
            mp[c] = min(mp[c], a);
        } else {
            mp[c] = a;
        }
    }
    int ans = -1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ans = max(ans, iter->second);
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
