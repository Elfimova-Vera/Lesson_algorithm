#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// 1) Реализовать пузырьковую сортировку двумерного массива

const int ROW = 3;
const int COL = 3;
int arr[ROW][COL];
int buff = 0;

void sort (int arr[][COL], int ROW, int COL){
    
    bool exit = false;

while(!exit){
exit = true;
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (arr[i][j]>arr[i][j+1])
            {buff = arr[i][j];
                arr[i][j] =arr[i][j+1];
                arr[i][j+1] = buff;
                exit = false;
            }
        }}
}}

// 2)

double f(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

/* int seek_substring_KMP (char s[], char p[])
{
    int i, j, N, M;
    N = strlen(s);
    M = strlen(p);

    // Динамический массив какой-то длины М
    int *d = (int*)malloc(M * sizeof(int));

    // Вычисление префикс-функции
    d[0] = 0;
    for(i = 1, j = 0; i < M; i++)
    {
        while(j > 0 && p[j] != p[i])
            j = d[j-1];
        if(p[j] == p[i])
            j++;
        d[i] = j;
    }
    // Поиск
    for(i = 0, j = 0; i < N; i++)
    {
        while(j > 0 && p[j] != s[i])
            j = d[j - 1];
        if(p[j] == s[i])
            j++;
        if(j == M)
        {
            free(d);
            return i - j + 1;
        }
    }
    free(d);
    return -1;
}*/

    int main(const int argc, const char** argv) {
   
   /* const int ROW = 3;
    const int COL = 3;
    int arr[ROW][COL];
    int buff = 0; */
    //int arr[ROW][COL] = {{1,9,2},{5,7,6},{4,3,8}};
    
        for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            arr[i][j]=rand()%10;
        }
    }
        
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%d \n", arr[i][j]);
        }
    }
        
        sort (arr,ROW, COL);
    
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%d \n \t", arr[i][j]);
        }}
        
// 2
       
        double a[11], y;
           for (int i = 0; i < 11; i++)
            scanf("%lf", &a[i]);

           for (int i = 10; i >= 0; i--) {
               y = f(a[i]);
               if (y > 400)
                   printf("%d TOO LARGE\n", i);
               else
                   printf("%d %.16g\n", i, y);
           }
    
}



 


