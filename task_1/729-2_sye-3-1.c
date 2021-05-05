#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

typedef struct list
{
    struct node *head;
}list;

void init(list* l)
{
    l->head = NULL;
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
    node* v=l->head;
    if (is_empty(l) == false)
        l->head = new;
    else if (is_empty(l) == true)
    {
        while (v->next != NULL)
        {
            v=v->next;
        }
        v->next = new;
    }

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
        printf("%d\n", v->value);

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

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = l->head;
    l->head=new;
    return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
{
    node* new;
    new = (node*)malloc(sizeof(node));
    new->value = value;
    new->next = n->next;
    n->next=new;
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

// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int value)
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
            l->head=v2->next;
        else if (v2->next == NULL)
        {
            free(v2);
            v1->next=NULL;
        }
        else
        {
            v1->next=v2->next;
            free(v2);
        }
    }
    return 0;
}

void clear(struct list* l)
{
    node* tmp=NULL;
    while (l->head->next != NULL)
    {
        tmp = l->head;
        l->head=l->head->next;
        free(tmp);
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
    print(&a);

    (void)scanf("%d", &n);
    push_front(&a, n);
    print(&a);

    (void)scanf("%d %d", &n, &x);
    y = nomer(&a, n);
    if (y==0)
        print(&a);
    else
    {
        insert_after(y, x);
        print(&a);
    }

    (void)scanf("%d", &x);
    remove_node(&a, x);
    print(&a);

    clear(&a);
    print(&a);
    return 0;
}