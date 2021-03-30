//  Lesson_9

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char * brackets_check(const char * s) {
    switch ( *s ) {
        case '\0' :
        case ')' :
        case '}' :
        case ']' :
            return (char*)s;
        case '(' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == ')' ) ? brackets_check(ret + 1) : (char*)s;
        }
        case '{' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == '}' ) ? brackets_check(ret + 1) : (char*)s;
        }
        case '[' : {
            char * ret = brackets_check(s + 1);
            return ( *ret == ']' ) ? brackets_check(ret + 1) : (char*)s;
        }
        default :
            return brackets_check(s + 1);
    }
}


//задание 1

#define SZ 10

typedef struct {
    int pr;
    int dat;
}Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init(){
    for (int i = 0; i < SZ;++i){
        arr[i]=NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat){
    Node *node = (Node*) malloc((sizeof(Node)));
    node->dat = dat;
    node->pr = pr;
    int flag;
    if(items == 0){
        arr[tail++] = node;
        items++;
    } else if(items == SZ){
        printf("%s /n", "Queue is full");
        return;
    }else{
        int i = 0;
        int idx = 0;
        Node *tmp;
        for( i = head; i < tail; ++i)
        {
            idx = i % SZ;
            if (arr[idx]-> pr > pr)
                break;
            else idx++;
        }
        flag = idx % SZ;
        i++;
        tmp = arr[idx];
        arr[idx] = arr[flag];
        arr[flag] = tmp;
        i++;
    }
    arr[flag] = node;
    items++;
    tail++;
}

Node* rem(){
    if (items == 0){
        return NULL;
    } else{
        int idx = head++ % SZ;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

//задание 2
const int SIZE =(sizeof(int))*8;

int bits[SIZE];

int cursor = -1;
int Stack[SIZE];

bool push(int data){
    if (cursor<SIZE){
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

int pop() {
    if (cursor!= -1) {
        return Stack[cursor--];
    }else{
        printf("%s \n", "Stack is empty");
        return -1;
    }
}


 int main(int argc, const char * argv[]) {
     
   
     
     //задание 2

  int number;
    
    printf("Write the number: ");
    scanf("%d",&number);

    /*  do {
     push(stk, value%n);
     value = value /n;  //было n вместо 2
   } while(value > 0);
   do {
       printf("%f",pop(stk));
   } while(isempty(stk)==0);
   getchar(); getchar();
   return 0;
 }
*/
    
    
  int bits[SIZE];  //создаем массив, чтобы записывать 0 и 1 чила,*8 чтобы узнать размер в битах
   

    for (int i = 0; i < SIZE; ++i)
    {
        //находим самый младший разряд (0) числа
        if (number%2==0)
        {  //если число четно, то последний бит равен 0
            bits[i] = 0;
        } else
        {
            //если число не четно, то последний бит равен 1
            bits[i] = 1;
        }
        //делим само число на 2, чтобы сдвинуть на новый (1) разряд
        number = number/2;
    }
   
    
    for (int i = SIZE-1; i >= 0; --i)
    {
        push(bits[i]);
    }
     
     pop();
     
    /* for (int i = SIZE-1; i >= 0; --i)
     {
         printf("%d",bits[i]);
     }*/
 }
     
    
   
   
        
    
    
    
   



