// https://atcoder.jp/contests/abc151/tasks/abc151_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> AC(N, false);
    vector<int> WA(N, 0);
    int num_ac=0, num_wa=0;
    for (int t = 0; t < M; t++) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") {
            if (!AC[p]) num_ac++;
            AC[p] = true;
        } else {
            if (!AC[p]) WA[p]++;
        }
    }
    for (int p = 0; p < N; p++) if (AC[p]) num_wa += WA[p];

    cout << num_ac << " " << num_wa << endl;
}
