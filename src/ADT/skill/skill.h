/* File: skill.h */
/* ADT Skill mengimplementasikan ADT List linier */

#ifndef __SKILL_H__
#define __SKILL_H__

#include "../../boolean.h"

extern char * BUFF_AKTIF;

typedef int Skillnb;
typedef struct { 
    char * Nama;
} aSkill;

typedef struct {
    aSkill TI [10]; 
    int Neff; 
} sSkill;

typedef struct tTabSkill *Skill;
typedef struct tTabSkill { 
	sSkill skillset;
	Skillnb info;
	Skill Next;
	Skill Prev;
} GetSkill;
typedef struct {
	Skill First;
	Skill Last;
} TabSkill; 

#define Info(P) (P)->info
#define Next(E) (E)->Next
#define Prev(P) (P)->Prev
#define First(S) ((S).First)
#define Last(S) ((S).Last)

/* Akses skill pemain */
#define SkillSet(S) (S)->skillset
#define LenSkill(S) (S).Neff
#define ElmtSkill(S,i) ((S).TI[(i)].Nama)

/* =======================|   Opening Game   |=================================== */

boolean IsEmpty (TabSkill L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (TabSkill *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/* =======================| Manajemen Memori  |================================== */
Skill Alokasi (Skillnb X);
/* Mengirimkan Skill hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Skill tidak nil. */
/* Jika alokasi gagal, mengirimkan Nil. */

void Dealokasi (Skill P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Skill P */

/* =======================|    Akses Skill    |================================== */
Skill Search (TabSkill L, Skillnb X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan Skill elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

sSkill DedicateSkill(char * Nama);
/* Membuat skillset baru dan memberikannya ke SkillSet(P)*/

boolean FindSkill(sSkill S, char * X);
/* Mengirimkan True jika skill X ditemukan di S */

void AddSkill (sSkill *S, char * X);
/* Menambahkan skill X ke skillset pemain */

void DelSkill (sSkill *S, int Idx);
/* Menghapus ElmtSkill(*S,Idx) dari skillset pemain */

void ShowSkill(sSkill S);
/* Menampilkan semua skill yang DIMILIKI pemain */

char * GenerateSkill(Skillnb X);
/* Menghasilkan nama skill yang di-randomized */

void GenerateBuff(TabSkill L, Skillnb X);
/* Menghasilkan BUFF_AKTIF dari skill yang DIMILIKI pemain */
/* Skill yang DIMILIKI pemain dapat diakses dengan SkillSet(S) */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (TabSkill *L, Skillnb X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (TabSkill *L, Skillnb X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (TabSkill *L, Skillnb *X);
/* I.S. TabSkill L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (TabSkill *L, Skillnb *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (TabSkill *L, Skill P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen dengan Skill P sebagai elemen pertama */
void InsertLast (TabSkill *L, Skill P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (TabSkill *L, Skill P, Skill Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (TabSkill *L, Skill P, Skill nSkill);
/* I.S. nSkill pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat nSkill */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (TabSkill *L, Skill *P);
/* I.S. TabSkill tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (TabSkill *L, Skill *P);
/* I.S. TabSkill tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (TabSkill *L, Skillnb X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list Skill P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* TabSkill mungkin menjadi kosong karena penghapusan */
void DelAfter (TabSkill *L, Skill *SkillEl, Skill Prec);
/* I.S. TabSKill tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      SkillEl adalah alamat elemen list yang dihapus  */
void DelBefore (TabSkill *L, Skill *SkillEl, Skill nSkill);
/* I.S. TabSkill tidak kosong. nSkill adalah anggota list. */
/* F.S. Menghapus Prev(nSkill): */
/*      SkillEl adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (TabSkill L);
/* I.S. TabSkill mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (TabSkill L);
/* I.S. TabSkill mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void WriteBackupDataSkill(TabSkill Ts);
/* Menyimpan data skill: aSkill & NEff */
/* Data disimpan ke dalam backup_skill.txt */
/* Baris ke-1: Banyaknya skill (M)
   M baris selanjutnya berisi nama skill */
/* Pencatatan dilanjutkan sampai S = Nil */

void LoadSkill(TabSkill *Ts);
/* Load semua skill yang dimiliki pemain */

#endif