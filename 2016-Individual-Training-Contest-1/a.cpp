#include <cstdio>
#include <algorithm>
#define N 3000 + 10

using namespace std;

int n, cnt, a[N], b[N], l[N], r[N];
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
}
void deal()
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i]) continue;
        for (int j = i + 1; j <= n; ++j)
        if (a[j] == b[i])
        {
            ++cnt;
            l[cnt] = i - 1;
            r[cnt] = j - 1;
            swap(a[i], a[j]);
            break;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
    printf("%d %d\n", l[i], r[i]);
}
int main()
{
    init();
    deal();
    return 0;
}
