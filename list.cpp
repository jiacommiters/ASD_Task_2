
#include "list.h"

void createList(List &L) {
    first(L) = NULL;
};

address allocate(infotype x) {
   address P = new elmlist; 
    info(P) = x;
    next(P) = NULL;
    return P;
};

void deallocate(address &P) {
    delete P;
    P = NULL;
};

void insertFirst(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        next(P) = NULL;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
};

void insertLast(List &L, address P) {
   if (first(L) == NULL) {
        first(L) = P;
        next(P) = NULL;
    } else {
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    }
};

address findElm(List L, infotype x) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteLast(List &L, address &P) {
    if (first(L) != NULL) {
        if(next(first(L)) == NULL) {
            P = first(L);
            first(L) = NULL;
        } else {
            address Q = first(L);
            while (next(next(Q)) != NULL) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
};

void deleteFirst(List &L, address &P) {
   if (first(L) != NULL) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
};

void printInfo(List L) {
   address P = first(L);
    while (P != NULL) {
        cout << info(P) << ", ";
        P = next(P);
    }
    cout << endl;
};

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
};

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
};
