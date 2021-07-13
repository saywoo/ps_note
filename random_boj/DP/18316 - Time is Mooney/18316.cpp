/*
    시간은 무니

    <문제>
    베시는 보비니아에 출장중인데, 이곳은 1~N으로 되어있는 N(2 <= N <= 1000)개의 도시가
    M(1 <= M <= 2000)개의 단방향 도로로 연결되어있다. 베시가 매번 도시 i로 갈때마다, 
    베시는 Mi(0 <= Mi <= 1000)의 무니를 벌게 된다. 도시 1에서 시작하는 베시는
    여러 도시들을 여행하고 마지막에 도시 1에 돌아왔을때 최대한 많은 무니를 벌기를 원한다.
    혼란을 막기 위해 M1 = 0이다.

    두 도시를 도로로 건너가는 것은 하루가 걸린다. 여행하기 위한 준비비용은 매우 비싼데
    T일 동안 여행하는데 C * T^2만큼의 무니가 들게 된다. (1 <= C <= 1000)

    베시가 한 번의 여행에 벌수 있는 무니의 최댓값은 얼마입니까? 베시가 도시 1 이외의
    다른 도시를 방문하지 않는 것이 가장 최대일 수 있는데, 이 경우 답은 0이 됩니다. 

    <입력>
    첫번째 줄에는 N, M, C가 입력됩니다.
    두번째 줄에는 N개의 정수 M1, M2,... MN이 입력됩니다.
    그리고 다음 M개의 줄에는 도시 a에서 도시 b로 가는 단방향 도로를 의미하는
    a, b (a /= b)가 입력됩니다.

    <출력> 
    첫번째 줄에 답을 출력합니다.

    <풀이>
    dp[a][b] = a번째 날에 b 도시에 있는 경우에서의 벌수 있는 무니의 최댓값 -> dp[a][b] = max(dp[a-1][m1], dp[a-1][m2], ~ dp[a-1][mp])
    (a의 크기는 Mi 중 최댓값의 크기와 같음) (b의 크기는 n의 크기와 같음)

    Mi > T^2 (t < Mi) 이므로 성립
*/

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