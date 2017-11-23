#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DeclareSort(prefix, type) \
int _DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) \
{ \
    if (*(type *)a < *(type *)b) return -1; \
    return (*(type *)a > *(type *)b); \
} \
void prefix ## _sort(type *a, int n) \
{ \
    qsort(a, n, sizeof(type),  _DeclareSort_ ## prefix ## _Compare); \
}

DeclareSort(int, int)
DeclareSort(double, double)


void dosort(int n)
{
    double d[] = {
        90.0, 22.0, 61.0, 98.0, 82.0,
        82.0, 61.0, 23.0, 79.0, 81.0,
        38.0, 45.0, 32.0, 11.0, 98.0
    };
    int x[] = {
        90, 22, 61, 98, 82,
        82, 61, 23, 79, 81,
        38, 45, 32, 11, 98
    };

    int_sort(x, n);
    double_sort(d, n);

    int i;
    for (i = 0; i < n; ++i) printf("%lf ", d[i]);
    printf("\n");
    for (i = 0; i < n; ++i) printf("%i ", x[i]);
    printf("\n");
}

#define CallYourFunc(f, n) \
    f(n)

int main(void)
{
    int n = 15;
    CallYourFunc(dosort, n);

    return 0;
}
