#include <cstdio>

using namespace std;

int main()
{
    int n, t, x;
    scanf("%d", &t);
    while(t--)
    {
        bool f1 = false, f2 = false;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            if (!x) f1 = true;
            if (x == 1) f2 = true;
        }
        if (f1 && f2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
