#include <cstdio>
#include <algorithm>
#define N 100 + 5

using namespace std;

int n, m, s1[N], s2[N];
int main()
{
    scanf("%d %d", &n, &m);
    if (n == 1 && m == 0)
    {
        printf("0\n0\n");
        return 0;
    }
    if (!m || 9 * n < m) printf("-1 -1\n");
    else
    {
        int last = m, mini = 0, maxs = 9;
        for (int i = 1; i <= n; ++i)
        for (int j = mini; j <= 9; ++j)
        {
            if (i == 1 && !j) continue;
            if (9 * (n-i) < last - j) continue;
            printf("%d", j);
            last -= j;
            if (i != 1) mini = j;
            break;
        }
        putchar('\n');
        last = m;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = maxs; j >= 0; j--)
            if (last >= j)
            {
                maxs = j;
                printf("%d", j);
                last -= j;
                break;
            }
        }
    }
    return 0;
}
