#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct edge
{
    int to, next;
}e[100];
int n, m, num, ans;
int s[10], p[21], flag[21], mat[21];
int w[10][10];
void add(int x, int y)
{
    e[++num].to = y;
    e[num].next = p[x];
    p[x] = num;
}
void init()
{
    int x, y;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    w[i][j] = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &x, &y);
        w[x][y] = 1;
    }
}
int find(int x)
{
    for (int i = p[x]; i; i = e[i].next)
    {
        int k = e[i].to;
        if (!flag[k])
        {
            flag[k] = 1;
            if (!mat[k] || find(mat[k]))
            {
                mat[k] = x;
                return 1;
            }
        }
    }
    return 0;
}
int cnt()
{
    num = 0;
    memset(p, 0, sizeof p);
    memset(mat, 0, sizeof mat);
    for (int i = 1; i < n; ++i)
    for (int j = 1; j <= n; ++j)
    if (!w[j][s[i]] && !w[j][s[i+1]]) add(j, i+n);
    for (int i = 1; i <= n; ++i)
    if (!w[i][s[n]] && !w[i][s[1]]) add(i, 2*n);
    int tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        tmp += find(i);
        memset(flag, 0, sizeof flag);
    }
    return tmp;
}
void deal()
{
    if (!n || !m)
    {
        printf("0\n");
        return;
    }
    ans = 0; s[n] = n;
    for (int i = 1; i < n; ++i)
    s[i] = i;
    do
    {
        ans = max(ans, cnt());
    }while(next_permutation(s+1, s+n));
    printf("%d\n", n-ans);
}
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        init();
        deal();
    }
    return 0;
}
