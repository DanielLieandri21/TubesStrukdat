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
    string namafilm;
    int tahun_terbit;
};
struct artis{
    string namaartis;
    int tahun_lahir;
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

void createListfilm(listfilm &L);
void createListartis(listartis &L);
addressfilm alokasifilm(string nama, int tahun, addressrelasi Q);
addressartis alokasiartis(string nama, int tahun);
addressrelasi createElmRelasi(addressartis Q);
void insertFirstfilm(listfilm &L, addressfilm P);
void insertLastfilm(listfilm &L, addressfilm P);
void insertAfterfilm(listfilm &L, addressfilm P, addressfilm Y, addressfilm Prec);
void insertFirstartis(listartis &L, addressartis P);
void insertLastartis(listartis &L, addressartis P, addressartis Y);
void insertAfterartis(listartis &L, addressartis P, addressartis Y, addressartis Prec);

#endif
