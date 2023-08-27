#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> ans;
    ans.reserve(1000);
    ans.push_back(N);

    int K = 1;
    while (N != K) {
        if (N & K) {
            N -= K;
            ans.push_back(N);;
        }
        K = (K << 1);
    }

    while (N != 1) {
        N = (N >> 1);
        ans.push_back(N);;
    }

    cout << (int)ans.size() << endl;
    for (int a : ans) cout << a << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
