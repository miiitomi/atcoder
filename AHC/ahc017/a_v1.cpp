// 各回で最小個の工事回数をランダムに行っていく.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  // グラフ頂点数. 500 <= N <= 1000.
    cin >> N;
    int M;  // グラフ辺数. 500 <= M <= 3000.
    cin >> M;
    int D;  // 日数. 5 <= D <= 30.
    cin >> D;
    int K;  // 一日に工事可能な辺数の上限. ceil(M/D) <= K <= 2*ceil(M/D).
    cin >> K;

    int L;
    if (M % D == 0) L = M / D;
    else L = (M / D) + 1;

    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int day = 1;
    int now = 0;
    vector<int> v(M);
    for (int m = 0; m < M; m++) {
        v[m] = day;

        now++;
        if (now == L) {
            now = 0;
            day++;
        }
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < M; i++) {
        cout << v[i];
        if (i == M-1) cout << endl;
        else cout << " ";
    }
}
