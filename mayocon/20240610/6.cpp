// https://atcoder.jp/contests/abc165/tasks/abc165_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> odd, even;
    for (int x = 1; x < (N + 1)/2; x++) {
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    vector<pair<int,int>> V;
    int x = 0, y = 2*odd.size();
    while (!odd.empty()) {
        V.push_back({x, x+odd.back()});
        odd.pop_back();
        x++;
    }
    while (!even.empty()) {
        V.push_back({y, y+even.back()});
        even.pop_back();
        y++;
    }
    while ((int)V.size() > M) V.pop_back();
    for (pair<int,int> &p : V) cout << p.first+1 << " " << p.second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
