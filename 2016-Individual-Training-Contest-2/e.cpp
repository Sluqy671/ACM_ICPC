#include <cstdio>

using namespace std;

int main()
{
    int n, m, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        if (n > m)
        {
            int tmp = n;
            n = m;
            m = tmp;
        }
        if (n < 3) printf("No\n");
        else
        {
            int v1 = m * (n-2), v2 = n * (m-2);
            int maxs = 2 * n * m, flag = 0;
            if (maxs % v1 == 0 && maxs % v2 == 0)
            {
                printf("Yes\n");
                continue;
            }
            for (int i = 0; i <= 2 * m; ++i)
            {
                int tmp = maxs - i * v1;
                if (tmp < 0) break;
                if (tmp % v2 == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
