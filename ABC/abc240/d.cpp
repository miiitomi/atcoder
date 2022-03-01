#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> V;

    int a;
    cin >> a;
    V.push_back(make_pair(a, 1));

    int ans = 1;
    cout << ans << endl;

    for (int i = 1; i < N; i++) {
        int b;
        cin >> b;
        ans++;
        pair<int, int> p = V[(int)V.size()-1];
        if (b != p.first) {
            V.push_back(make_pair(b, 1));
            cout << ans << endl;
        } else {
            p.second++;
            V[(int)V.size()-1] = p;
            if (p.second == b) {
                V.pop_back();
                ans -= p.second;
            }
            cout << ans << endl;
        }
    }
}
