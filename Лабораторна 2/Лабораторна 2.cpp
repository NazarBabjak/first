#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lincedlist.h"
using namespace std;

//створює порожній список
LIST MAKENULL(LIST L) {
    L = newnode();
    L->next = NULL;
    return L;
}

//повертає позицію, яка слідує одразу після позиціх n в n-елементному списку
position END(LIST L) {
    position q = L;
    while (q->next != NULL)
        q = q->next;
    return q;
}

//оператор вставляє елемент x в позицію p в списку L
LIST INSERT(elementtype x, position p, LIST L) {
    position tmp;
    tmp = p->next;
    p->next = newnode();
    p->next->element = x;
    p->next->next = tmp;
    return L;
}


//визначає позицію елемента x в списку L
position LOCATE(elementtype x, LIST L) {
    position p = L;
    while (p->next != NULL) {
        if (p->next->element == x)
            return p;
        else p = p->next;
    }
    return END(L);
}

//повертає елемент, що знаходиться в позиції p в списку L
elementtype RETRIEVE(position p, LIST L) {
    return p->element;
}

//видаляє елемент в позиції p із списку L
LIST DELETE(position p, LIST L) {
    p->next = p->next->next;
    return L;
}

//повертає наступну позицію від позиції p в списку L
position NEXT(position p, LIST L) {
    if (p->next != NULL)
        return p->next;
    return NONE;
}
//повертає першу позицію в списку, якщо список порожній - повертається END(L)
position FIRST(LIST L) {

    if (L == NULL)
        return END(L);
    else
    return L;
}


int main() {
    LIST L= *new LIST;
    L = MAKENULL(L);
    INSERT('a', FIRST(L), L);
    INSERT('b', FIRST(L)->next, L);
    INSERT('d', END(L), L);
    INSERT('c', NEXT(LOCATE('b', L), L), L);
    DELETE(LOCATE('a', L), L);
    printlist(L);
    system("pause");
    return 0;
}