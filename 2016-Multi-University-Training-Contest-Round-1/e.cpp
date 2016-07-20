#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define N 200 + 5
#define M 100000 + 10
#define INF 1000000000

using namespace std;

struct node
{
    int x, y;
    node() { }
    node(int a, int b) { x = a, y = b; }
}p1[N], p2[N];
struct edge
{
    int fr, to, w, cap, flow, next;
}e[M];
int n, m, num, sum, stat[10][10];
int p[N], flag[N], d[N], last[N], a[N];
void add(int x, int y, int z, int w)
{
    e[++num].fr = x;
    e[num].to = y;
    e[num].w = w;
    e[num].cap = z;
    e[num].next = p[x];
    e[num].flow = 0;
    p[x] = num;
}
void init()
{
    int x, y;
    num = 1;
    m = 2 * n + 1;
    memset(stat, 0, sizeof stat);
    for (int i = 1; i <= sum; ++i)
    {
        scanf("%d %d", &x, &y);
        stat[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
        if (stat[i][j])
        {
            add(i, j+n, 1, 1);
            add(j+n, i, 0, -1);
        }
        else
        {
            add(i, j+n, 1, 0);
            add(j+n, i, 0, 0);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        add(0, i, 2, 0);
        add(i, 0, 0, 0);
        add(i+n, m, 2, 0);
        add(m, i+n, 0, 0);
    }
}
bool spfa(int s, int t, int &cost, int &flow)
{
    for (int i = 1; i <= m; ++i)
    d[i] = INF, flag[i] = 0;
    last[s] = 0; d[s] = 0; a[s] = INF;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        flag[x] = 0;
        for (int i = p[x]; i; i = e[i].next)
        {
            int k = e[i].to;
            if (e[i].cap > e[i].flow && d[k] > d[x] + e[i].w)
            {
                d[k] = d[x] + e[i].w;
                last[k] = i;
                a[k] = min(a[x], e[i].cap-e[i].flow);
                if (!flag[k])
                {
                    flag[k] = 1;
                    q.push(k);
                }
            }
        }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += d[t];
    int x = t;
    while(x != s)
    {
        e[last[x]].flow += a[t];
        e[last[x]^1].flow -= a[t];
        x = e[last[x]].fr;
    }
    return true;
}
int mincost(int s, int t)
{
    int cost = 0, flow = 0;
    while(spfa(s, t, cost, flow)) continue;
    return cost;
}
void deal()
{
    int ans = mincost(0, m);
    printf("%d\n", ans);
    for (int i = 1;  i <= m; ++i)
    p[i] = 0;
}
int main()
{
    while(scanf("%d %d", &n, &sum) != EOF)
    {
        init();
        deal();
    }
    return 0;
}
