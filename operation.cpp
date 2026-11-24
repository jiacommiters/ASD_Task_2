
#include "list.h"
#include "operation.h"


void insert_sorted(List &L, infotype x) {
    /**
    * IS : List may be empty
    * PR : insert an infotype x into an already sorted List L
    *      so that the elements inside List L is still sorted in ascending order,
    *      procedure must also check if such number is already exists (No Duplicate number),
    *      allocate new element only if the conditions are met
    * FS : elements in List L sorted in ascending order, x is inside List L
    */

    //-------------your code here-------------
    address P = first(L);
    address Prec = NULL;

    while (P != NULL && info(P) < x) {
        Prec = P;
        P = next(P);
    }

    if (P != NULL && info(P) == x) {
        return;
    }

    address Q = allocate(x);
    if (Prec == NULL) {
        insertFirst(L, Q);
    } else {
        insertAfter(L, Prec, Q);
    if (first(L) == NULL || x < info(first(L))) {
        insertFirst(L, allocate(x));
        return;
    }
    if (info(first(L)) == x) {
        return;
    }
    address Prec = first(L);
    while (next(Prec) != NULL && info(next(Prec)) < x) {
        Prec = next(Prec);
    }
    if (next(Prec) == NULL || info(next(Prec)) != x) {
        insertAfter(L, Prec, allocate(x));
    }
    //----------------------------------------
}
