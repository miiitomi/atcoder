#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> V;
    V.push_back(0);

    int now = 0;
    for (int i = 0; i < N; i++) {
        now -= A[i];
        if (now < 0) now += 360;
        V.push_back(now);
    }

    sort(V.begin(), V.end());
    int ans = 0;
    for (int i = 1; i < (int)V.size(); i++) {
        ans = max(ans, V[i] - V[i-1]);
    }
    ans = max(ans, 360 - V[V.size()-1]);
    cout << ans << endl;
}
