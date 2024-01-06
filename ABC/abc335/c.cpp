#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    deque<pair<ll, ll>> D;
    for (int i = 1; i <= N; i++) D.push_back(make_pair(i, 0));

    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            char c;
            cin >> c;
            auto p = D.front();
            D.pop_back();
            if (c == 'R') p.first++;
            else if (c == 'L') p.first--;
            else if (c == 'U') p.second++;
            else p.second--;
            D.push_front(p);
        } else {
            int i;
            cin >> i;
            i--;
            cout << D[i].first << " " << D[i].second << "\n";
        }
    }
}
