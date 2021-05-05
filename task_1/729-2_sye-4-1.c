#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}node;

typedef struct list
{
    struct node *head;
    struct node *tail;
}list;

void init(list* l)
{
    l->head = NULL;
    l->tail = NULL;
}

// проверка на пустоту списка
bool is_empty(list *l)
{
    if (l->head != NULL)
        return true;
    else return false;
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if (is_empty(l) == false)
    {
        l->head = new;
        l->tail = new;
    }
    else
    {
        new->prev = l->tail;
        l->tail->next = new;
    }
    l->tail=new;
    return 0;
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list* l)
{
    node* v=l->head;
    if (is_empty(l) == true)
    {
        while (v->next != NULL)
        {
            printf("%d ", v->value);
            v=v->next;
        }
        printf("%d\n", l->tail->value);
    }
}

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value)
{
    node* v=l->head;
    while (v != NULL)
    {
        if(v->value==value)
            return v;
        v=v->next;
    }
    return NULL;
}


// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l)
{
    node* v=l->tail;
    if (is_empty(l) == true)
    {
        while (v->prev != NULL)
        {
            printf("%d ", v->value);
            v=v->prev;
        }
        printf("%d\n", l->head->value);
    }
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = l->head;
    new->prev=NULL;
    l->head->prev=new;
    l->head=new;
    return 0;
}

node* nomer(list* l, int n)
{
    node* v =l->head;
    int i;
    for (i=1; i<n; i++)
    {
        if (v->next == NULL && i!=n-1)
        {
            return 0;
        }
        else
            v=v->next;
    }
    return v;
}


// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = n->next;
    new->prev=n;
    if(n->next != NULL)
        n->next->prev=new;
    else l->tail=new;
    n->next=new;
    return 0;
}

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = n;
    new->prev=n->prev;
    if(n->prev != NULL)
        n->prev->next=new;
    else l->head=new;
    n->prev=new;

    return 0;
}

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_first(list *l, int value)
{
    node* v2 =l->head;
    node* v1;
    while (v2->value != value && v2->next != NULL)
    {
        v1=v2;
        v2=v1->next;
    }
    if(v2->value == value)
    {
        if (v2 == l->head)
        {
            l->head=v2->next;
            l->head->prev=NULL;
        }
        else if (v2->next == NULL)
        {
            free(v2);
            l->tail=v1;
            v1->next=NULL;
        }
        else
        {
            v1->next=v2->next;
            v2->next->prev=v1;
            free(v2);
        }
    }
    return 0;
}

// удалить последний элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_last(list *l, int value)
{
    node* v2 =l->tail;
    node* v1;
    while (v2->value != value && v2->prev != NULL)
    {
        v1=v2;
        v2=v1->prev;
    }
    if(v2->value == value)
    {
        if (v2 == l->head)
        {
            l->head=v1;
            l->head->prev=NULL;
        }
        else if (v2->next == NULL)
        {
            free(v2);
            l->tail=v2->prev;
            v2->prev->next=NULL;
        }
        else
        {
            v2->next->prev=v2->prev;
            v2->prev->next=v2->next;
            free(v2);
        }
    }
    return 0;
}

void clear(struct list* l)
{
    node* v=l->head;
    while (v->next != NULL)
    {
        v = l->head;
        l->head=l->head->next;
        free(v);
    }
    init(l);
}


int main()
{
    int n, x, i, x1, x2, x3;
    struct list a;
    node* y;
    init(&a);
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i = i + 1)
    {
        (void)scanf("%d", &x);
        push_back(&a, x);
    }
    print(&a);

    (void)scanf("%d %d %d", &x1, &x2, &x3);
    y=find(&a, x1);
    if(y!=NULL)
        printf("%d ", 1);
    else printf("%d ", 0);
    y=find(&a, x2);
    if(y!=NULL)
        printf("%d ", 1);
    else printf("%d ",0);
    y=find(&a, x3);
    if(y!=NULL)
        printf("%d\n", 1);
    else printf("%d\n", 0);

    (void)scanf("%d", &n);
    push_back(&a, n);
    print_invers(&a);

    (void)scanf("%d", &n);
    push_front(&a, n);
    print(&a);

    (void)scanf("%d %d", &n, &x);
    if (n>=1)
    {
        y = nomer(&a, n);
        if (y==0)
            print_invers(&a);
        else
        {
            insert_after(&a, y, x);
            print_invers(&a);
        }
    }
    else print_invers(&a);



    (void)scanf("%d %d", &n, &x);
    if (n>=1)
    {
        y = nomer(&a, n);
        if (y==0)
            print(&a);
        else
        {
            insert_before(&a, y, x);
            print(&a);
        }
    }
    else
        print(&a);

    (void)scanf("%d", &x);
    remove_first(&a, x);
    print_invers(&a);

    (void)scanf("%d", &x);
    remove_last(&a, x);
    print(&a);

    clear(&a);
    print(&a);
    print_invers(&a);

    return 0;
}

