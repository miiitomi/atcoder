#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];

    map<int, int> M;

    for (int i = 0; i < K; i++) {
        if (M.count(c[i])) M[c[i]] += 1;
        else M[c[i]] = 1;
    }

    int ans = (int)M.size();

    for (int i = K; i < N; i++) {
        M[c[i-K]] -= 1;
        if (M[c[i-K]] == 0) {
            M.erase(c[i-K]);
        }

        if (M.count(c[i])) M[c[i]] += 1;
        else M[c[i]] = 1;

        ans = max(ans, (int)M.size());
    }

    cout << ans << endl;
}
