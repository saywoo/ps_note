/*
    사용한 알고리즘:
    이분탐색, 누적합
    2차원 배열에서 나올 수 있는 값은 1~n*m이므로 
    이만큼을 이분탐색하게 되면 최적화 문제를 결정문제로 바꿀수 있게 된다.
    이렇게 이분탐색의 mid값을 정해놓은 상태에서 
    mid보다 큰 값은 1로,
    mid랑 같은 값은 0으로,
    mid보다 작은 값은 -1로 해서 
    2차원 배열에서의 누적합 배열을 저장해둔다.
    그리고 모든 경우의 직사각형을 다 만들어보면, 
    그 직사각형의 값이 0이면 mid의 값이 그 직사각형의 중앙값이 된다.
    그렇게 다 구해보았을때 직사각형의 값이 음수인 직사각형이 있다면 더 작은 중앙값이 있으므로 high = mid - 1를 해주고
    0이 있고 전부 양수이면 ans 값에 mid값을 저장해두고 low = mid + 1을 하는 식으로 이분탐색을 하면된다.
*/

#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second

int h, r, w, c, x, y, ans;
vector<vector<int> > v, ps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> h >> w;

    v.resize(r + 1); ps.resize(r + 1);
    for (int i = 1; i <= r; i++) {
        v[i].resize(c + 1); ps[i].resize(c + 1);
        for (int j = 1; j <= c; j++) cin >> v[i][j];
    }

    ps[0].resize(c + 1);

    int low = 0; int high = r * c;

    while (low <= high) {

        int mid = (low + high) / 2;

        //cout << mid << endl;

        for (int i = 1; i <= r; i++) {
            int s = 0;
            for (int j = 1; j <= c; j++) {   
                if (v[i][j] == mid) {  x = i; y = j; ps[i][j] = 0; }
                else if (v[i][j] < mid) ps[i][j] = -1;
                else ps[i][j] = 1;

                s += ps[i][j];
                ps[i][j] = s + ps[i-1][j];
            }
        }


        bool fa = false; // >
        bool fb = false; // =
        bool fc = false; // <

        //cout << x << " " << y << endl << endl;

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (i + h - 1 > r || j + w - 1 > c) continue;

                //cout << i << " " << j << " " << i + h - 1 << " " << j + w - 1 << '\n';

                int tmp = ps[i+h-1][j+w-1] - ps[i+h-1][j-1] - ps[i-1][j+w-1] + ps[i-1][j-1];

                if (tmp > 0) fa = true;
                else if (tmp == 0) fb = true;
                else fc = true;
            }
        }

        //cout << fa << " " << fb << " " << fc << endl;

        if (fc) high = mid - 1;
        else if (fb) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}
