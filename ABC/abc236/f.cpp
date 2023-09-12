#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> C;
    C.reserve((1 << N));
    for (int i = 1; i < (1 << N); i++) {
        int c;
        cin >> c;
        C.push_back(make_pair(c, i));
    }
    sort(C.begin(), C.end());

    vector<bool> B((1 << N), false);
    B[0] = true;

    ll ans = 0;

    for (auto p : C) {
        int c = p.first;
        int i = p.second;
        if (B[i]) continue;
        ans += c;
        for (int j = 0; j < (1 << N); j++) {
            if (B[j]) B[j^i] = true;
        }
    }

    cout << ans << endl;
}
