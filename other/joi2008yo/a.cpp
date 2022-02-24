#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    N = 1000 - N;

    vector<int> coin = {500, 100, 50, 10, 5, 1};
    int ans = 0;
    for (int i = 0; i < (int)coin.size(); i++) {
        ans += N / coin[i];
        N = N % coin[i];
    }

    cout << ans << endl;
}
