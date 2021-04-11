#include <bits/stdc++.h>
using namespace std;

int n, m, c, s, e, tmp;
vector<int> v;
vector<vector<int> > dp, road;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> c;

    v.resize(n + 1); road.resize(n + 1);
    for (int i = 1; i <= n; i++) { cin >> v[i]; tmp = max(v[i], tmp); }
    dp.resize(tmp + 2);

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        road[s].push_back(e);
    }
    dp[0].resize(n + 1, -1); dp[0][1] = 0;
    tmp = 0;
    for (int i = 0; i <= dp.size() - 2; i++) {
        dp[i+1].resize(n + 1, -1);

        tmp = max(tmp, dp[i][1] - c * i * i);

        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == -1) continue;
            else { for (int k: road[j]) dp[i+1][k] = max(dp[i+1][k], dp[i][j] + v[k]); }
        }
    }

    cout << tmp << '\n';

    return 0;
}