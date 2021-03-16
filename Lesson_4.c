#include  <stdio.h>
#include  <math.h>
 

// 1. перевод чисел из десятичной системы в двоичную
int bin_to_dec(int val, int n)
{
    return val ? bin_to_dec(val/10, n+1) + (val%10 * pow(2.0, n) ) : 0;
}

// 2. возведения числа [a] в степень [b]
double power(double a, long b) {
   if(b == 0) return 1.0;
   if(b < 0) return 1.0 / (a * power (1.0 / a, b + 1));
   return a * power(a, b - 1);
}

 
int main(void)
{
    // 1.перевод чисел из десятичной системы в двоичную
    int d;
    
    scanf("%d", &d);
    
    printf("%d\n", bin_to_dec(d, 0));
    
    // 2. возведения числа [a] в степень [b]
    
    double a;
    long b;
    while (scanf ("%lf %ld", &a, &b) == 2) {
       printf("%16.16lf\n", power (a, b));
    }
    
    
    return 0;
}


// 3
int Power(int x, int c)
{ int x_s = x;
    for (int i = 1; i < c; i++)
    x *= x_s;
    return x; }



/* 4. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка)

 
 #include  <stdio.h>
 #include  <math.h>
 
 int main()
{
    int x, y, x1, y1;
 
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&x1);
    scanf("%d",&y1);
 
    
    if (((abs(x - x1) == 1) && ((y - y1) == 0)) ||
        ((abs(y - y1) == 1) && ((x - x1) == 0)) ||
        ((abs(x - x1) == 1) && (abs(y - y1) == 1)))
    {
    printf ("YES\n");
    }
    else
    {
    printf ("NO\n");
    }
 
    return 0;
}
 
*/
