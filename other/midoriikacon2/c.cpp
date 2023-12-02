#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    for (int j = 1; j <= X; j++) {
        int ans = -1;
        for (int i = 0; i < N; i++) {
            int tmp = max(0, B[i] - abs(j - A[i]));
            ans = max(ans, tmp);
        }
        cout << ans;
        if (j != X) cout << " ";
        else cout << endl;
    }
}
