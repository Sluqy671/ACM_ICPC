#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3000 + 10
#define M 30000 + 10
using namespace std;

typedef long long LL;
struct edge
{
    int to, next;
}e[M];
int n, m, num, p[N], d[N], flag[N];
LL ans;
void add(int x, int y)
{
    e[++num].to = y;
    e[num].next = p[x];
    p[x] = num;
}
void init()
{
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &x, &y);
        add(x, y);
    }
}
void dfs(int x, int last, int h)
{
    if (h == 2)
    {
        ++d[x];
        return;
    }
    for (int i = p[x]; i; i = e[i].next)
    {
        int k = e[i].to;
        if (k != last) dfs(k, x, h+1);
    }
}
LL cal(int x)
{
    LL tmp = 0;
    for (int i = p[x]; i; i = e[i].next)
    {
        int k = e[i].to;
        for (int j = p[k]; j; j = e[j].next)
        {
            int t = e[j].to;
            if (t != x && !flag[t])
            {
                tmp += d[t] * (d[t]-1) / 2;
                flag[t] = 1;
            }
        }
    }
    return tmp;
}
void deal()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        flag[j] = d[j] = 0;
        dfs(i, 0, 0);
        ans += cal(i);
    }
    printf("%I64d\n", ans);
}
int main()
{
    init();
    deal();
    return 0;
}
