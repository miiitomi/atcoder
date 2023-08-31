#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        X -= A[i];
    }
    int m = *min_element(A.begin(), A.end());
    int ans = N;
    ans += (X / m);
    cout << ans << endl;
}
