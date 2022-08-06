#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    int i = N-1;
    int ans = 0;
    while (i != 0) {
        ans++;
        i = P[i];
    }

    cout << ans << endl;
}
