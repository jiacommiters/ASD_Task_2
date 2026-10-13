
#include "list.h"
#include "operation.h"


void insert_sorted(List &L, infotype x) {
    if (findElm(L, x) != NULL) {
        return;
    }

    address P = allocate(x);
    if (first(L) == NULL) {
        first(L) = P;
        next(P) = NULL;
    } else if (info(P) < info(first(L))) {
        insertFirst(L, P);
    } else {
        address Q = first(L);
        while (next(Q) != NULL && info(next(Q)) < info(P)) {
            Q = next(Q);
        }
        insertAfter(L, Q, P);
    }
};
