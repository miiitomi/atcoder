#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i).first;
        a.at(i).second = i;
    };
    sort(a.begin(), a.end());

    int64_t x = (K / N);
    vector<int64_t> ans(N, x);
    K = (K % N);
    for (int i = 0; i < K; i++) {
        ans.at(a.at(i).second)++;
    }

    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
}
