// https://atcoder.jp/contests/abc233/tasks/abc233_h
#include <bits/stdc++.h>
using namespace std;
const int B = 1000;

void solve() {
    int N;
    cin >> N;
    int M = (N + B - 1)/ B;

    vector<pair<int,int>> P(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i].first = x+y;
        P[i].second = x - y + (int)(1e+5);
    }
    sort(P.begin(), P.end());

    vector<pair<int,int>> V(M, {0, 0});
    vector<vector<int>> S(M, vector<int>((int)(2e+5)+ 3, 0));

    for (int i = 0; i < N; i += B) {
        V[i / B].first = P[i].first;
        V[i / B].second = P[min(i+B-1, N-1)].first;
        for (int j = i; j < min(N, i + B); j++) S[i / B][P[j].second + 1]++;
        for (int x = 0; x <= (int)2e+5 + 1; x++) S[i/B][x+1] += S[i/B][x];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b, K;
        cin >> a >> b >> K;
        int u = a+b, v = a-b+(int)(1e+5);
        int left = -1, right = (int)(2e+5) + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int min_u = max(0, u-mid), max_u = min((int)2e+5, u+mid), min_v = max(0, v-mid), max_v = min((int)2e+5, v+mid);
            int cnt = 0;
            for (int i = 0; i < N; i += B) {
                int k = i / B;
                if (min_u <= V[k].first && V[k].second <= max_u) {
                    cnt += S[k][max_v + 1] - S[k][min_v];
                } else if (V[k].second < min_u || V[k].first > max_u) {
                    continue;
                } else {
                    for (int j = i; j < min(N, i+B); j++) {
                        if (min_u <= P[j].first && P[j].first <= max_u && min_v <= P[j].second && P[j].second <= max_v) {
                            cnt++;
                        }
                    }
                }
            }
            if (cnt >= K) right = mid;
            else left = mid;
        }
        cout << right << "\n";
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
