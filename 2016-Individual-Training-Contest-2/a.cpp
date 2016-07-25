#include <cstdio>

using namespace std;

typedef long long LL;
LL n;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d", &n);
        if (n % 2 == 1)
        {
            if (n == 1) printf("False\n");
            else printf("True\n");
        }
        else
        {
            if (n % 4 == 0)
            {
                if (n == 4) printf("False\n");
                else printf("True\n");
            }
            else printf("False\n");
        }
    }
    return 0;
}
