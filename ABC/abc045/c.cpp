#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    int64_t ans = 0LL;

    for (int bit = 0; bit < (1<<(N-1)); bit++) {
        string x = "";
        for (int i = 0; i < N; i++) {
            x += S.at(i);
            if (bit & (1<<i)) {
                ans += stoll(x);
                x = "";
            }
        }
        ans += stoll(x);
    }
    cout << ans << endl;
}