#include <cstdio>
#include <algorithm>
#define N 50 + 3

using namespace std;

typedef long long LL;
int t, n, a[N];
LL ans, C[N][N];
void pre_work()
{
    for (int i = 0; i <= 30; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = C[i][j-1] * (i-j+1);
            C[i][j] /= j;
        }
    }
}
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
    sort(a+1, a+n+1);
}
void deal()
{
    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            int num = n - j;
            if (num < i - 1) break;
            tmp += C[num][i-1] * a[j];
        }
        if (i&1) ans += tmp;
        else ans -= tmp;
    }
    printf("%I64d\n", ans > 0 ? ans : -ans);
}
int main()
{
    pre_work();
    scanf("%d", &t);
    while(t--)
    {
        init();
        deal();
    }
    return 0;
}
