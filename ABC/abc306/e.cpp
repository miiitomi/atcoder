#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    ll ans = 0;
    multiset<int> U, L;
    for (int i = 0; i < K; i++) U.insert(0);
    for (int i = 0; i < N-K; i++) L.insert(0);
    vector<int> A(N, 0);
    int min_u = 0;
    int max_l = 0;

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        int a = A[x];

        if (a >= min_u) {
            if (y >= max_l) {
                U.erase(U.find(a));
                U.insert(y);
                ans += (y - a);
                min_u = *U.begin();
            } else {
                min_u = max_l;
                ans += (max_l - a);
                U.erase(U.find(a));
                U.insert(min_u);
                L.erase(L.find(max_l));
                L.insert(y);
                auto iter = L.end();
                iter--;
                max_l = *iter;
            }
        } else {
            if (y > min_u) {
                ans += (y - min_u);
                U.erase(U.find(min_u));
                U.insert(y);
                L.erase(L.find(a));
                L.insert(min_u);
                min_u = *U.begin();
                auto iter = L.end();
                iter--;
                max_l = *iter;
            } else {
                L.erase(L.find(a));
                L.insert(y);
                auto iter = L.end();
                iter--;
                max_l = *iter;
            }
        }

        cout << ans << endl;
        A[x] = y;
    }
}
