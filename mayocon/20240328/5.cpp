// https://atcoder.jp/contests/abc134/tasks/abc134_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    multiset<int> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i == 0) S.insert(a);
        else {
            auto iter = S.lower_bound(a);
            if (iter == S.begin()) S.insert(a);
            else {
                iter--;
                S.erase(iter);
                S.insert(a);
            }
        }
    }

    cout << S.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
