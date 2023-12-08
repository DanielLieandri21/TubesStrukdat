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
addressrelasi createElmRelasi(addressartis Q){
    addressrelasi P = new elmlist_relasi;
    nextartis(P) = Q;
    next(P) = NULL;
    return P;
}
void insertFirstfilm(listfilm &L, addressfilm P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastfilm(listfilm &L, addressfilm P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        last(L) = P;
    }
}
void insertAfterfilm(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec){
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
    }
}
void insertFirstartis(listartis &L, addressartis P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertLastartis(listartis &L, addressartis P, addressartis Y){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Y = first(L);
        while (next(Y) != NULL){
            Y = next(Y);
        }
        next(Y) = P;
    }
}
void insertAfterartis(listartis &L, addressartis P, addressartis Y, addressartis Prec){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Prec = first(L);
        while (next(Prec) != Y){
            Prec = next(Prec);
        }
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
