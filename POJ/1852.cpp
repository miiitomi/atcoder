#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int L, N;
    cin >> L >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans_min = -1;
    int ans_max = -1;

    for (int i = 0; i < N; i++) {
        ans_min = max(ans_min, min(a[i], L - a[i]));
        ans_max = max(ans_max, max(a[i], L - a[i]));
    }

    cout << ans_min << " " << ans_max << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
