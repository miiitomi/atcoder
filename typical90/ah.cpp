#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    map<int, int> m;
    int first = 0;
    int last = -1;
    for (int i = 0; i < N; i++) {
        m[a[i]]++;
        last = i;
        if ((int)m.size() == K) break;
    }
    int ans = last - first + 1;
    while (true) {
        last++;
        if (last == N) break;
        m[a[last]]++;
        if ((int)m.size() <= K) {
            ans = max(ans, last - first + 1);
        } else {
            while ((int)m.size() > K) {
                m[a[first]]--;
                if (m[a[first]] == 0) m.erase(a[first]);
                first++;
            }
            ans = max(ans, last - first + 1);
        }
    }
    cout << ans << endl;
}
