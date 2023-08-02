
# include "stdio.h"

void change_val(int *x)
{
    *x = 4;
}

int main()
{
    int x = 3;
    change_val(&x);
    printf("%d", x);

}