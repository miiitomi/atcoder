// https://atcoder.jp/contests/abc315/tasks/abc315_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].second >> V[i].first;
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());

    if (V[0].second == V[1].second) {
        int ans = V[0].first + V[1].first / 2;
        int tmp = V[0].first;
        for (int j = 0; j < N; j++) {
            if (V[j].second != V[0].second) {
                tmp += V[j].first;
                break;
            }
        }
        cout << max(ans, tmp) << endl;
    } else {
        cout << V[0].first + V[1].first << endl;
    }
}
