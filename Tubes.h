#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define nextartis(P) (P)->nextartis
#define prev(P) (P)->prev
#define relasi(P) (P)->relasi
#define first(L) ((L).first)
#define last(L) ((L).last)
using namespace std;

typedef struct elmlist_film *addressfilm;
typedef struct elmlist_relasi *addressrelasi;
typedef struct elmlist_artis *addressartis;
struct film{
    string namaFilm;
    int tahun_Terbit;
};
struct artis{
    string namaArtis;
    int tahun_Lahir;
};
typedef film infotypefilm;
typedef artis infotypeartis;
struct elmlist_film {
    infotypefilm info;
    addressfilm next;
    addressfilm prev;
    addressrelasi relasi;
};
struct elmlist_artis {
    infotypeartis info;
    addressartis next;
};
struct elmlist_relasi {
    addressartis nextartis;
    addressrelasi next;
};
struct listartis{
    addressartis first;
};
struct listfilm{
    addressfilm first;
    addressfilm last;
};

void createList_Film(listfilm &L);
void createList_Artis(listartis &L);
addressfilm alokasi_Film(string nama, int tahun, addressrelasi Q);
addressartis alokasi_Artis(string nama, int tahun);
addressrelasi createElm_Relasi(addressartis Q);
void insertFirst_Film(listfilm &L, addressfilm P);
void insertLast_Film(listfilm &L, addressfilm P);
void insertAfter_Film(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec);
void insertFirst_Artis(listartis &L, addressartis P);
void insertLast_Artis(listartis &L, addressartis P, addressartis Y);
void insertAfter_Artis(listartis &L, addressartis P, addressartis Y, addressartis Prec);
void deleteFirst_Film(listfilm &L, addressfilm P, addressfilm Q);
void deleteLast_Film(listfilm &L, addressfilm P, addressfilm Q);
void deleteAfter_Film(listfilm &L, addressfilm P, addressfilm Q, addressfilm Prec);
void deleteFirst_Artis(listartis &L, addressartis P);
void deleteLast_Artis(listartis &L, addressartis P, addressartis Q);
void deleteAfter_Artis(listartis &L, addressartis P, addressartis Q, addressartis Prec);


#endif
