#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<pair<int64_t, int64_t>> V(N, pair<int64_t, int64_t>(0LL, 0LL));
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        V.at(i) = make_pair(a, b);
    }

    sort(V.begin(), V.end());

    int64_t now = 0LL;
    for (int i = 0; i < N; i++) {
        if (now + K < V.at(i).first) {
            cout << now + K << endl;
            return 0;
        }
        K = K - (V.at(i).first - now) + V.at(i).second;
        now = V.at(i).first;
    }
    cout << now + K << endl;
}