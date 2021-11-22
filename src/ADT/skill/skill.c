#include "skill.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* =======================|   Opening Game   |=================================== */
boolean IsEmpty (TabSkill L){
    return (First(L) == Nil && Last(L) == Nil) ;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */


void CreateEmpty (TabSkill *L){
    First(*L) = Nil ;
    Last(*L) = Nil ;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/* =======================| Manajemen Memori  |================================== */
Skill Alokasi (Skillnb X){
    Skill P = (GetSkill *) malloc (sizeof(GetSkill)) ;
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        SkillSet(P) = DedicateSkill(GenerateSkill(X));
        return P;
    }
    else {
        return Nil ;
    }
}
/* Mengirimkan Skill hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Skill tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (Skill P){
    free (P) ;
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Skill P */

/* =======================|    Akses Skill    |================================== */
Skill Search (TabSkill L, Skillnb X){
    Skill P = First(L) ;
    if (IsEmpty(L)) {
        return Nil ;
    }
    else {
        while (P != Nil && Info(P) != X) {
                P = Next(P) ;
            }
        }
        return P ;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan Skill elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

sSkill DedicateSkill(char * Nama)
/* Membuat skillset baru dan memberikannya ke SkillSet(P) */
/* Digunakan ketika pemain pertama kali dibuat */
/* Inisialisasi ElmtSkill(ss, 0)=Nama */
{
    sSkill ss;
    LenSkill(ss) = 1;
    ElmtSkill(ss,0) = Nama;
    return ss;
}

boolean FindSkill(sSkill S, char * X)
/* Mengirimkan True jika skill X ditemukan di S */
{
    int i;
    for (i = 0; i < LenSkill(S); i++) {
        if (strcmp(ElmtSkill(S,i), X) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void AddSkill (sSkill *S, char * X)
/* Menambahkan skill X ke skillset pemain */
{
    if (LenSkill(*S) < 10) {
        ElmtSkill(*S, LenSkill(*S)) = X;
        LenSkill(*S)++;
    }
}

void DelSkill (sSkill *S, int Idx)
/* Menghapus ElmtSkill(*S,Idx) dari skillset pemain */
{
    /* Skema replace-mereplace */
    int i;
    if ((LenSkill(*S) - Idx-1) == 1) {
        ElmtSkill(*S,Idx-1) = '\0';
    }
    for (i = Idx-1; i < LenSkill(*S)-1; i++) {
        ElmtSkill(*S,i) = ElmtSkill(*S,i+1);
    }
    LenSkill(*S)--;
}

void ShowSkill(sSkill S)
/* Menampilkan semua skill yang DIMILIKI pemain */
{
    int i;
    printf("\n=======================|   Daftar Skill    |==================================\n");
    for (i = 0; i < LenSkill(S); i++) {
        printf("[%d] %s\n", (i+1), ElmtSkill(S,i));
    }
    printf("\n");
}

char * GenerateSkill(Skillnb X)
/* Menghasilkan nama skill yang di-randomized */
{
    char * n;
    srand(time(0));
    int rint = rand();
    if ((rint % 6) == 0) {
        n = "Mesin Penukar Posisi";
    } else if ((rint % 6) == 1) {
        n = "Cermin Pengganda";
    } else if ((rint % 6) == 2) {
        n = "Pintu Ga Ke Mana Mana";
    } else if ((rint % 6) == 3) {
        n = "Senter Pengecil Hoki";
    } else if ((rint % 6) == 4) {
        n = "Senter Pembesar Hoki";
    } else if ((rint % 6) == 5) {
        n = "Teknologi Gagal (Junk)";
    }
    printf("Congratulations Player %d! You get: %s (Skill ID: %d)\n", X, n, rint);
    return n;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (TabSkill *L, Skillnb X){
    Skill P ;
    P = Alokasi(X) ;
    if (P != Nil) {
        InsertFirst(L, P) ;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (TabSkill *L, Skillnb X){
    Skill P ;
    P = Alokasi(X) ;
    if (P != Nil) {
        InsertLast(L, P) ;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (TabSkill *L, Skillnb *X){
    Skill P ;
    DelFirst(L, &P) ;
    *X = Info(P) ;
    Dealokasi(P) ;
}
/* I.S. TabSkill L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (TabSkill *L, Skillnb *X){
    Skill P ; 
    DelLast(L, &P) ;
    *X = Info(P) ;
    Dealokasi(P) ;
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (TabSkill *L, Skill P){
    if (IsEmpty(*L)) {
        First(*L) = P ;
        Last(*L) = P ;
        Next(P) = Nil ;
        Prev(P) = Nil ; 
    }
    else {
        Prev(P) = Nil ;
        Prev(First(*L)) = P ;
        Next(P) = First(*L) ;
        First(*L) = P ;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen dengan Skill P sebagai elemen pertama */
void InsertLast (TabSkill *L, Skill P){
    if (IsEmpty(*L)) {
        InsertFirst(L, P) ;
    }
    else {
        Next(P) = Nil ;
        Next(Last(*L)) = P ;
        Prev(P) = Last(*L) ;
        Last(*L) = P ;
    }    
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (TabSkill *L, Skill P, Skill Prec){
    if (Prec == Last(*L)) {
        InsertLast(L, P) ;
    }
    else {
        Next(P) = Next(Prec) ;
        Next(Prec) = P ;
        Prev(P) = Prec ;
        Prev(Next(P)) = P ;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (TabSkill *L, Skill P, Skill nSkill){
    if (nSkill == First(*L)) {
        InsertFirst(L, P) ;
    }
    else {
        Next(Prev(nSkill)) = P ;
        Next(P) = nSkill ;
        Prev(P) = Prev(nSkill) ;
        Prev(nSkill) = P ;
    }
}
/* I.S. nSkill pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat nSkill */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (TabSkill *L, Skill *P){
    *P = First(*L) ;
    if (Next(*P) == Nil) {
        CreateEmpty(L) ;
    }
    else {
        First(*L) = Next(*P) ;
        Prev(Next(*P)) = Nil ;
    }
}
/* I.S. TabSkill tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (TabSkill *L, Skill *P){
    *P = Last(*L) ;
    if (Prev(*P) == Nil) {
        CreateEmpty(L) ;
    }
    else {
        Last(*L) = Prev(*P) ;
        Next(Prev(*P)) = Nil ;
    }
}
/* I.S. TabSkill tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (TabSkill *L, Skillnb X){
    Skill P = Search(*L, X) ;
    if (P != Nil) {
        if (P == First(*L) && P == Last(*L)) {
            CreateEmpty(L) ;
        }
        else if (P == First(*L)) {
            DelFirst(L, &P) ;
        }
        else if (P == Last(*L)) {
            DelLast(L, &P) ;
        }
        else {
            Next(Prev(P)) = Next(P) ;
            Prev(Next(P)) = Prev(P) ;
        }
        Dealokasi(P) ;
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list Skill P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* TabSkill mungkin menjadi kosong karena penghapusan */
void DelAfter (TabSkill *L, Skill *SkillEl, Skill Prec){
    *SkillEl = Next(Prec) ;
    if (*SkillEl != Nil) {
        Next(Prec) = Next(*SkillEl) ;
        if (Next(*SkillEl) != Nil) {
            Prev(Next(*SkillEl)) = Prec ;
        }
        else {
            Last(*L) = Prec ;
        }
    }
}

/* I.S. TabSKill tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      SkillEl adalah alamat elemen list yang dihapus  */
void DelBefore (TabSkill *L, Skill *SkillEl, Skill nSkill){
    *SkillEl = Prev(nSkill) ;
    if (*SkillEl != Nil) {
        Prev(nSkill) = Prev(*SkillEl) ;
        if (Prev(*SkillEl) != Nil) {
            Next(Prev(*SkillEl)) = nSkill ; 
        }
        else {
            First(*L) = nSkill ;
        }
    }
}
/* I.S. TabSkill tidak kosong. nSkill adalah anggota list. */
/* F.S. Menghapus Prev(nSkill): */
/*      SkillEl adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (TabSkill L){
    Skill P ; 
    P = First(L) ;
    printf("[") ;
    if (!IsEmpty(L)) {
        printf("%d", Info(P)) ;
        P = Next(P) ;
        while (P != Nil) {
            printf(",%d", Info(P)) ;
            P = Next(P) ;
        }
    }
    printf("]\n") ;
}
/* I.S. TabSkill mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (TabSkill L){
    Skill P ; 
    P = Last(L) ;
    printf("[") ;
    if (!IsEmpty(L)) {
        printf("%d", Info(P)) ;
        P = Prev(P) ;
        while (P != Nil) {
            printf(",%d", Info(P)) ;
            P = Prev(P) ;
        }
    }
    printf("]\n") ;
}
/* I.S. TabSkill mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */