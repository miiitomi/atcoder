#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        if (A.at(i) > 10) {
            ans += A.at(i) - 10;
        }
    }
    cout << ans << endl;
}