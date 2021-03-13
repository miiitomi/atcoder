#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    string N_string = to_string(N);
    int k = N_string.size();

    int64_t ans = 0;

    for (int i = 3; i < k; i += 3) {
        ans += ((i-1)/3) * (pow(10LL, i) - pow(10LL, i-3));
    }

    ans += ((k-1)/3) * (1 + N - pow(10LL, ((k-1)/3)*3));
    cout << ans << endl;
}