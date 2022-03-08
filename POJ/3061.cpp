#include <iostream>
#include <vector>
using namespace std;

int solve() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int j = 0; j < N; j++) cin >> A[j];

    int sum = 0;
    int end = 0;
    int ans = 1e+9;
    for (int start = 0; start < N; start++) {
        while (sum < S) {
            if (end >= N) break;
            sum += A[end];
            end++;
        }
        if (sum < S) break;
        ans = min(ans, end - start);
        sum -= A[start];
    }

    if (ans != 1e+9) return ans;
    else return 0;
}

int main() {
    int T;
    cin >> T;
    vector<int> ans(T);
    for (int i = 0; i < T; i++) {
        ans[i] = solve();
    }
    for (int i = 0; i < T; i++) {
        cout << ans[i] << endl;
    }
}
