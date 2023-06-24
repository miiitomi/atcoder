#include <bits/stdc++.h>
using namespace std;

bool local = true;

int P;
typedef long long ll;
ll ans;
vector<int> all_costs{1, 2, 4, 8, 16, 32, 64, 128};

int N, W, K, C, remain_houses;
vector<int> a, b, c, d;
vector<vector<int>> S, T;
vector<vector<bool>> flowed;
vector<vector<int>> block_type;  // 0=None, 1=source, 2=house

vector<int> dx{-1, 1, 0, 0};
vector<int> dy{0, 0, -1, 1};

bool check_flowed(int x, int y) {
    if (S[x][y] > 0) {
        return false;
    }

    if (block_type[x][y] == 1) {
        flowed[x][y] = true;
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int s = x + dx[i];
        int t = y + dy[i];
        if (0 <= s && s < N && 0 <= t && t < N) {
            if (flowed[s][t]) {
                flowed[x][y] = true;
                return true;
            }
        }
    }
    return false;
}

void rec_flowing(int x, int y) {
    bool tmp_flowed = check_flowed(x, y);

    if (tmp_flowed) {

        if (block_type[x][y] == 2) remain_houses--;

        for (int i = 0; i < 4; i++) {
            int s = x + dx[i];
            int t = y + dy[i];
            if (0 <= s && s < N && 0 <= t && t < N && !flowed[s][t]) {
                rec_flowing(s, t);
            }
        }
    }
}

int local_destruct(int x, int y) {
    // cout << x << " " << y << " " << P << endl;
    ans += P + C;
    S[x][y] -= P;
    if (S[x][y] > 0) {
        return 0;
    } else {
        rec_flowing(x, y);
        if (remain_houses > 0) return 1;
        else return 2;
    }
}

int prd_destruct(int x, int y, int P) {
    cout << x << " " << y << " " << P << endl;
    int r;
    cin >> r;

    if (r == 1) {
        S[x][y] = 0;
        rec_flowing(x, y);
    }

    return r;
}

int for_each_house(int i) {
    int x = c[i];
    int y = d[i];

    int min_distance = 1e+9;
    int to_x = -1;
    int to_y = -1;

    for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
            if (S[s][t] > 0 && block_type[s][t] != 1) continue;
            int tmp_distance = abs(s - x) + abs(t - y);
            if (tmp_distance < min_distance) {
                min_distance = tmp_distance;
                to_x = s;
                to_y = t;
            }
        }
    }

    while (S[x][y] > 0 || x != to_x || y != to_y) {
        if (S[x][y] > 0) {
            int r = 0;
            while (r == 0) {
                if (local) r = local_destruct(x, y);
                else r = prd_destruct(x, y, 100);
            }
            if (r == 2) return 2;
        }

        if (x != to_x) {
            if (x > to_x) x--;
            else x++;
        } else if (y != to_y) {
            if (y > to_y) y--;
            else y++;
        }
    }

    return 1;
}

void solve() {
    vector<pair<int, int>> distance_house_pairs;
    for (int i = 0; i < K; i++) {
        int min_dist = 1e+9;
        for (int j = 0; j < W; j++) {
            int tmp_distance = abs(c[i] - a[j]) + abs(d[i] - b[j]);
            min_dist = min(min_dist, tmp_distance);
        }
        distance_house_pairs.push_back(make_pair(min_dist, i));
    }

    sort(distance_house_pairs.begin(), distance_house_pairs.end());

    for (int s = 0; s < K; s++) {
        int i = distance_house_pairs[s].second;
        int r = for_each_house(i);
        if (r == 2) {
            return;
        }
    }
}

int main() {
    cin >> N >> W >> K >> C;

    remain_houses = K;

    a.resize(W);
    b.resize(W);
    c.resize(K);
    d.resize(K);

    S.resize(N);
    T.resize(N);
    for (int i = 0; i < N; i++) S[i].assign(N, 1);
    for (int i = 0; i < N; i++) T[i].assign(N, 1);

    flowed.resize(N);
    for (int i = 0; i < N; i++) flowed[i].assign(N, false);

    block_type.resize(N);
    for (int i = 0; i < N; i++) block_type[i].assign(N, 0);

    if (local) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> S[i][j];
                T[i][j] = S[i][j];
            }
        }
    }

    for (int i = 0; i < W; i++) {
        cin >> a[i] >> b[i];
        block_type[a[i]][b[i]] = 1;
    }

    for (int i = 0; i < K; i++) {
        cin >> c[i] >> d[i];
        block_type[c[i]][d[i]] = 2;
    }

    for (int c : all_costs) {
        C = c;
        vector<int> p_list;
        for (int p = 10; p <= 1000; p += 10)
        p_list.push_back(p);
    
        for (int p : p_list) {
            P = p;
            ans = 0;
            S = T;
            remain_houses = K;
            for (int i = 0; i < N; i++) flowed[i].assign(N, false);

            solve();

            cout << ans;
            if (p == 1000 && c != 128) cout << endl;
            else if (p == 1000 && c == 128) {}
            else cout << " ";
        }
    }
}