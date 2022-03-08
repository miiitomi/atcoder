#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int end = 0;
    set<int> S;
    int ans = 0;

    for (int start = 0; start < N; start++) {
        while (!S.count(A[end])) {
            if (end == N) break;
            S.insert(A[end]);
            end++;
        }
        ans = max(ans, end - start);
        S.erase(A[start]);
    }

    cout << ans << endl;
}
