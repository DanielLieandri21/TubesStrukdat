#include "Tubes.h"

void createList_Film(listfilm &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createList_Artis(listartis &L){
    first(L) = NULL;
}

addressfilm alokasi_Film(string nama, int tahun, addressrelasi Q){
    addressfilm P = new elmlist_film;
    info(P).namaFilm = nama;
    info(P).tahun_Terbit = tahun;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = Q;
    return P;
}
addressartis alokasi_Artis(string nama, int tahun){
    addressartis P = new elmlist_artis;
    info(P).namaArtis = nama;
    info(P).tahun_Lahir = tahun;
    next(P) = NULL;
    return P;
}
addressrelasi createElm_Relasi(addressartis Q){
    addressrelasi P = new elmlist_relasi;
    nextartis(P) = Q;
    next(P) = NULL;
    return P;
}
void insertFirst_Film(listfilm &L, addressfilm P){
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
void insertLast_Film(listfilm &L, addressfilm P){
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
void insertAfter_Film(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec){
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
void insertFirst_Artis(listartis &L, addressartis P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertLast_Artis(listartis &L, addressartis P, addressartis Y){
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
void insertAfter_Artis(listartis &L, addressartis P, addressartis Y, addressartis Prec){
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
void deleteFirst_Film(listfilm &L, addressfilm P, addressfilm Q){
    if (first(L) == NULL && last(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = first(L);
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = next(P);
        first(L) = next(P);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteLast_Film(listfilm &L, addressfilm P, addressfilm Q){
    if (first(L) == NULL && last(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = first(L);
        while (next(P) != first(L)){
            Q = P;
            P = next(P);
        }
        next(Q) = first(L);
        last(L) = Q;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfter_Film(listfilm &L, addressfilm P, addressfilm Q, addressfilm Prec){
    if (first(L) == NULL && last(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = first(L);
        while (next(P) != Q){
            Prec = P;
            P = next(P);
        }
        next(Prec) = Q;
        prev(Q) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteFirst_Artis(listartis &L, addressartis P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLast_Artis(listartis &L, addressartis P, addressartis Q){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        Q = first(L);
        while (next(Q) != NULL){
            P = Q;
            Q = next(Q);
        }
        next(P) = NULL;
    }
}
void deleteAfter_Artis(listartis &L, addressartis P, addressartis Q, addressartis Prec){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        while (next(P) != Q){
            Prec = P;
            P = next(P);
        }
        next(Prec) = Q;
        next(P) = NULL;
    }
}
