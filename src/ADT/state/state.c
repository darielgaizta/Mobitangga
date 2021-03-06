/* File: state.c */

#include <stdio.h>
#include "state.h"

void CreateEmptyState (State *S)
/* Membuat State kosong berkapasitas 100 */
{
	Top(*S) = 0;
}

boolean IsEmptyState (State S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return Top(S) == 0;
}

boolean IsFullState (State S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return Top(S) == 100;
}

/* ************ Menambahkan sebuah elemen ke State ************ */
void Push (State * S, TabPlayer Tp, TabSkill Ts)
/* Menambahkan X sebagai elemen State S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	int i = 0;
	Top(*S)++;
	Player P = FirstPlayer(Tp);
	Skill s = First(Ts);
	while (P != Nil)
	{
		StatePlayer(*S,i) = DataPlayer(P);
		StateSkill(*S,i) = SkillSet(s);
		P = NextPlayer(P);
		s = Next(s);
		i++;
	}
}

/* ************ Menghapus sebuah elemen State ************ */
void Pop (State * S, TabPlayer* Tp, TabSkill* Ts)
/* Menghapus X dari State S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	int i = 0;
	Player P = FirstPlayer(*Tp);
	Skill s = First(*Ts);
	while (P != Nil)
	{
		DataPlayer(P) = StatePlayer(*S,i);
		SkillSet(s) = StateSkill(*S,i);
		P = NextPlayer(P);
		s = Next(s);
		i++;
	}
	Top(*S)--;
}