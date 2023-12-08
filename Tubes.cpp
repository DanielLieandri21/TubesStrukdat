#include "Tubes.h"

void createListfilm(listfilm &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createListartis(listartis &L){
    first(L) = NULL;
}

addressfilm alokasifilm(string nama, int tahun, addressrelasi Q){
    addressfilm P = new elmlist_film;
    info(P).namafilm = nama;
    info(P).tahun_terbit = tahun;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = Q;
    return P;
}
addressartis alokasiartis(string nama, int tahun){
    addressartis P = new elmlist_artis;
    info(P).namaartis = nama;
    info(P).tahun_lahir = tahun;
    next(P) = NULL;
    return P;
}
addressrelasi createElmRelasi(addressartis A){
    addressrelasi P = new elmlist_relasi;
    nextartis(P) = A;
    next(P) = NULL;
    return P;
}
void insertFirstfilm(listfilm &L, addressfilm P, addressrelasi Q){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        first(L) = P;
        relasi(L) = Q;
    }
}
void insertLastfilm(listfilm &L, addressfilm P, addressrelasi Q){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        last(L) = P;
        relasi(L) = Q;
    }
}
void insertAfterfilm(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec, addressrelasi Q){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        Prec = first(L);
        while (next(Prec) != Y){
            Prec = next(Prec);
        }
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(Prec)) = P;
        relasi(L) = Q;
    }
}
void insertFirstartis(listartis &L, addressartis P, addressrelasi Q){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
        Q = nextartis(P);
    }
}
void insertLastartis(listartis &L, addressartis P, addressartis Y, addressrelasi Q){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Y = first(L);
        while (next(Y) != NULL){
            Y = next(Y);
        }
        next(Y) = P;
        Q = nextartis(P);
    }
}
void insertAfterartis(listartis &L, addressartis P, addressartis Y, addressartis Prec, addressrelasi Q){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Prec = first(L);
        while (next(Prec) != Y){
            Prec = next(Prec);
        }
        next(P) = next(Prec);
        next(Prec) = P;
        Q = nextartis(P);
    }
}
