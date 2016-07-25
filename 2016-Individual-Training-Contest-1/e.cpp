#include <cstdio>
#define N 200 + 5
#define M 10000 + 10

using namespace std;

struct edge
{
    int to, next;
}e[M];
int n, m, num, a[N], b[N], p[N];
int mat[2*N], flag[2*N];
inline int abs(const int &x) { return x > 0 ? x : -x; }
void add(int x, int y)
{
    e[++num].to = y;
    e[num].next = p[x];
    p[x] = num;
}
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
        for (int j = 1; j <= n; ++j)
        if (abs(a[j]-b[i]) <= 1) add(j, i+n);
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
void deal()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        flag[j+n] = 0;
        ans += find(i);
    }
    printf("%d\n", ans);
}
int main()
{
    init();
    deal();
    return 0;
}
