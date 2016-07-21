#include <cstdio>
#include <map>
#define N 100000 + 10

using namespace std;

typedef long long LL;
map<int, LL>f;
int n, m, s[N][18];
inline int gcd(const int &x, const int &y)
{
    if (!y) return x;
    return gcd(y, x%y);
}
void read(int &x)
{
    x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9')
    {
        x = (x<<3) + (x<<1) + c - '0';
        c = getchar();
    }
}
void init()
{
    read(n);
    for (int i = 1; i <= n; ++i)
    read(s[i][0]);
    for (int j = 1; (1<<j) <= n; ++j)
    for (int i = 1; i + (1<<(j-1)) <= n; ++i)
    s[i][j] = gcd(s[i][j-1], s[i+(1<<(j-1))][j-1]);
}
int cal(int l, int r)
{
    int h = 0, len = r - l + 1;
    while((1<<(h+1)) <= len) ++h;
    return gcd(s[l][h], s[r-(1<<h)+1][h]);
}
int get(int v, int st)
{
    int l = st, r = n;
    while(l < r)
    {
        int mid = (l+r+1) >> 1;
        int tmp = cal(st, mid);
        if (tmp < v) r = mid - 1;
        else l = mid;
    }
    return l;
}
void pre_work()
{
    for (int l = 1; l <= n; ++l)
    {
        int r = l;
        while(r <= n)
        {

            int tmp = cal(l, r);
            int pl = get(tmp, l);
            f[tmp] += pl - r + 1;
            r = pl + 1;
        }
    }
}
void deal()
{
    int l, r;
    f.clear();
    pre_work();
    read(m);
    while(m--)
    {
        read(l), read(r);
        int ans = cal(l, r);
        printf("%d %I64d\n", ans, f[ans]);
    }
}
int main()
{
    int t, i = 0;
    read(t);
    while(t--)
    {
        printf("Case #%d:\n", ++i);
        init();
        deal();
    }
    return 0;
}
