#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <stdio.h>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define relasi(P) (P)->relasi
#define first(L) ((L).first)
#define last(L) ((L).last)
using namespace std;

typedef film infotypefilm;
typedef struct elmlist_film *addressfilm;
struct film{
    string namafilm;
    int tahun_terbit;
};
struct elmlist_film {
    infotypefilm info;
    addressfilm next;
    addressfilm prev;
    addressrelasi relasi;
};
struct listfilm{
    addressfilm first;
    addressfilm last;
};

typedef artis infotypeartis;
typedef struct elmlist_artis *addressartis;
struct artis{
    string namaartis;
    int tahun_lahir;
};
struct elmlist_artis {
    infotypeartis info;
    addressartis next;
};
struct listartis{
    addressartis first;
};

typedef struct elmlist_relasi *addressrelasi;
struct elmlist_relasi {
    addressartis nextartis;
    addressrelasi next;
};

void createListfilm(listfilm &L);
void createListartis(listartis &L);
addressfilm alokasifilm(string nama, int tahun);
addressartis alokasiartis(string nama, int tahun);
addressrelasi createElmRelasi(addressartis A);
void insertFirstfilm(listfilm &L, addressfilm P);
void insertLastfilm(listfilm &L, addressfilm P, addressrelasi Q);
void insertAfterfilm(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec, addressrelasi Q);

#endif
