#include <bits/stdc++.h>
using namespace std;
const int INF = 2e+9;


void solve() {
    int N;
    cin >> N;
    map<int, pair<int,int>> mp;
    mp[0] = make_pair(INF, INF);
    mp[INF] = make_pair(0, 0);
    int pre = 0, nxt = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[pre].second = a;
        mp[INF].first = a;
        mp[a] = make_pair(pre, INF);
        pre = a;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y;
            cin >> x >> y;
            nxt = mp[x].second;
            mp[y] = make_pair(x, nxt);
            mp[x].second = y;
            mp[nxt].first = y;
        } else {
            int x;
            cin >> x;
            mp[mp[x].first].second = mp[x].second;
            mp[mp[x].second].first = mp[x].first;
            mp.erase(x);
        }
    }

    int a = 0;
    while (true) {
        a = mp[a].second;
        if (a == INF) {
            cout << "\n";
            return;
        }
        cout << a << " ";
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
