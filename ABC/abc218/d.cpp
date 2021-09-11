#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    set<pair<int, int>> S, T;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        S.insert(make_pair(x, y));
        T.insert(make_pair(y, x));
    }

    ll ans = 0;
    while (!S.empty()) {
        pair<int, int> a;
        a.first = S.begin()->first;
        a.second = S.begin()->second;
        S.erase(a);
        T.erase(make_pair(a.second, a.first));
        for (auto s : S) {
            if (s.first != a.first) break;
            
            auto iter = T.lower_bound(make_pair(a.second, 0));
            while (true) {
                if (iter->first != a.second) break;
                auto iter2 = S.lower_bound(make_pair(iter->second, s.second));
                if (iter2->first == iter->second && iter2->second == s.second) ans++;
                iter++;
            }
        }
    }
    cout << ans << endl;
}
