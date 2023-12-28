// https://atcoder.jp/contests/abc166/tasks/abc166_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> have(N, false);
    while (K--) {
        int d;
        cin >> d;
        while (d--) {
            int a;
            cin >> a;
            a--;
            have[a] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) if(!have[i]) cnt++;
    cout << cnt << endl;
}
