#include <bits/stdc++.h>
using namespace std;

map<int, vector<string>> mp;

vector<string> f(int k) {
    if (mp.count(k)) return mp[k];
    if (k == 0) {
        vector<string> s(1, "#");
        mp[k] = s;
        return mp[k];
    }
    vector<string> s = f(k-1);
    int M = s.size();
    vector<string> T(3*M, string(3*M, '.'));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    T[M*i+x][M*j+y] = s[x][y];
                }
            }
        }
    }
    mp[k] = T;
    return T;
}

void solve() {
    int N;
    cin >> N;
    vector<string> S = f(N);

    for (string s : S) {
        cout << s << "\n";
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
