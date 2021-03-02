#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    int64_t ans = 0;

    for (int64_t i = 1; i*i <= 2*N; i++) {
        if (((2*N) % i == 0) && (i%2 != ((2*N)/i)%2)) {
            ans+=2;
        }
    }
    cout << ans << endl;
}