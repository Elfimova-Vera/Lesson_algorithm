#include <stdio.h>
// 1)

void sort (int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        sort(s_arr, first, right);
        sort(s_arr, left, last);
    }
}

// 2)
void busketSort (int* arr,int len) {
    const int MAX = len;
    const int B = 10;
    
    int buskets[B][MAX+1];
    for (int i = 0; i < B;++i){
        buskets[i][MAX]= 0;
    }
    
    for (int k = 0; k < len; ++k){
        if (arr[k] % 2 == 0) {
    
    for (int digit= 1; digit<1000000000; digit*= 10) {
        for (int i = 0; i < MAX; ++i){
            int d = (arr[i]/digit % B);
            
            int counter = buskets[d][MAX];
            buskets[d][counter] = arr[i];
            counter++;
            buskets[d][MAX]= counter;
        }
        int idx = 0;
        for (int i = 0; i < B;++i){
        for (int j = 0; j<buskets[i][MAX]; ++j){
            arr[idx++] = buskets[i][j];
        }
            buskets[i][MAX] = 0;
        }
    }
            ///
        }
///
    }}


int main(int argc, const char * argv[]) {
    
    /*1). Описать в коде улучшенный алгоритм быстрой сортировки - описана в видео "Быстрая Сортировка. Улучшения."*/
     
     
    /*2). Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
     Пример: массив [0 2 8 3 4 6 5 9 8 2 7 3] превратить в массив [0 2 2 3 4 6 5 9 8 8 7 3]
     Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и функции, необходимые для реализации сортировок*/
    
    const int SIZE = 30;
    int arr[SIZE] = {9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,1,2};
    
    busketSort(arr,SIZE);
    
    for (int i = 0; i < SIZE; i++)
           printf("%d ", arr[i]);
       printf("\n");
    
    sort(arr,0,SIZE-1);
    
    for (int i = 0; i < SIZE; i++)
           printf("%d ", arr[i]);
       printf("\n");
    
   
    return 0;
}
