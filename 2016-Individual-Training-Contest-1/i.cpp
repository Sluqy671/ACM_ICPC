#include <cstdio>
#include <set>
using namespace std;

typedef long long LL;
set<LL>s;
int q[20];
LL n, maxs;
void get(int x, int aim, int a,int b)
{
    if (x == aim + 1)
    {
        LL tmp = 0;
        for (int i = 1; i <= aim; ++i)
        {
            tmp *= 10;
            tmp += q[i];
        }
        s.insert(tmp);
        maxs = tmp;
        return;
    }
    if (a)
    {
        q[x] = 4;
        get(x+1, aim, a-1, b);
    }
    if (b)
    {
        q[x] = 7;
        get(x+1, aim, a, b-1);
    }
}
void pre_work()
{
    for (int i = 1; i <= 9; ++i)
    get(1, 2*i, i, i);
}
int main()
{
    int t;
    pre_work();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d", &n);
        if (n > maxs)
        {
            printf("44444444447777777777\n");
            continue;
        }
        printf("%I64d\n", *s.lower_bound(n));
    }
    return 0;
}
