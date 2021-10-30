#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> F(N+1, -1), B(N+1, -1);

    for (int q = 0; q < Q; q++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x, y;
            cin >> x >> y;
            B[x] = y;
            F[y] = x;
        } else if (a == 2) {
            int x, y;
            cin >> x >> y;
            B[x] = -1;
            F[y] = -1;
        } else {
            int x;
            cin >> x;
            while (F[x] != -1) x = F[x];
            vector<int> ans;
            while (x != -1) {
                ans.push_back(x);
                x = B[x];
            }
            cout << ans.size() << " ";
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << ans[i];
                if (i == (int)ans.size() - 1) cout << endl;
                else cout << " ";
            }
        }
    }
}
