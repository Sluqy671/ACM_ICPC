#include <cstdio>
#include <algorithm>
#define N 3000 + 10

using namespace std;

typedef long long LL;
LL n, x, y, tmp, sum;
int main()
{
    int t, ans;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%I64d", &n);
        sum = x = y = 1;
        while(sum <= n)
        {
            ++ans;
            tmp = y;
            y = x;
            x += tmp;
            sum += x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
