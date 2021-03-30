
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

//задание 1

char * check(const char * simv) {
    switch ( *simv ) {
        case '\0' :
        case ')' :
        case '}' :
        case ']' :
            return (char*)simv;
        case '(' : {
            char * ret = check(simv + 1);
            return ( *ret == ')' ) ? check(ret + 1) : (char*)simv;
        }
        case '{' : {
            char * ret = check(simv + 1);
            return ( *ret == '}' ) ? check(ret + 1) : (char*)simv;
        }
        case '[' : {
            char * ret = check(simv + 1);
            return ( *ret == ']' ) ? check(ret + 1) : (char*)simv;
        }
        default :
            return check(simv + 1);
    }
}
 
//задание 2


struct list
{
  int field; // поле данных
  struct list *ptr; // указатель на следующий элемент
};

//ввод списка
struct list * init(int a) // а- значение первого узла
{
  struct list *lst;
  // выделение памяти под корень списка
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->ptr = NULL; // это последний узел списка
  return(lst);
}

//вывод списка
void listprint(struct list* lst)
{
    struct list* p;
    p = lst;
    do {
        printf("%d ", p->field);  // вывод значения элемента p
        p = p->ptr;        // переход к следующему элементу
    } while (p != NULL);
}
    

// Задание 3  сортировка

typedef struct _list list_t;
struct _list {
    uint8_t value;
    list_t  *next;
};


list_t* sort_list ( list_t* list )
{
    list_t* heads[257] = {0};
    list_t* tails[257] = {0};

    // O(N) loop
    for ( list_t* it = list; it != 0; it = it -> next ) {
        list_t* next = it -> next;

        if ( heads[ it -> value ] == 0 ) {
            heads[ it -> value ] = it;
        } else {
            tails[ it -> value ] -> next = it;
        }

        tails[ it -> value ] = it;
    }

    list_t* result = 0;
    for ( size_t i = 255; i-- > 0; ) {
            if ( tails[i] ) {
                tails[i] -> next = result;
                result = heads[i];
            }
        }

        return result;
    }

list_t* make_list ( char* string )
{
    list_t head;

    for ( list_t* it = &head; *string; it = it -> next, ++string ) {
        it -> next = malloc ( sizeof ( list_t ) );
        it -> next -> value = ( uint8_t ) * string;
        it -> next -> next = 0;
    }

    return head.next;
}
void free_list ( list_t* list )
{
    for ( list_t* it = list; it != 0; ) {
        list_t* next = it -> next;
        free ( it );
        it = next;
    }
}

void print_list ( list_t* list )
{
    printf ( "[ " );

    if ( list ) {
        printf ( "%c", list -> value );

        for ( list_t* it = list -> next; it != 0; it = it -> next )
            printf ( ", %c", it -> value );
    }

    printf ( " ]\n" );
}
      


int main(int nargs, char** args) {
   
    //задание 1
    
        char buf[BUFSIZ];
        
        while ( printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n' )
            printf("%s\n", ( *check(buf) ) ? "False" : "True");
       
    //задание 2
    
    Node *copyList(Node *head)
    {
        for (Node* cur = head; cur != NULL; cur = cur->next) {
            Node* dup = (Node*)malloc(sizeof(Node));
            dup->data = cur->data;
            dup->next = cur->random;
            cur->random = dup;
        }
        Node* result = head->random;
        for (Node* cur = head; cur != NULL; cur = cur->next) {
            Node* dup = cur->random;
            dup->random = dup->next->random;
        }
        for (Node* cur = head; cur != NULL; cur = cur->next) {
            Node* dup = cur->random;
            cur->random = dup->next;
            dup->next = cur->next ? cur->next->random : NULL;
        }
        return result;
    }
    
   //задание 3
    list_t* list = make_list ( nargs > 1 ? args[1] : "wibble" );


        print_list (list);

        list_t* sorted = sort_list (list);


        print_list (sorted);

        free_list (list);
    
        return 0;
    }
    

