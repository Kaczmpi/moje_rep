#ifndef array_h
#define array_h

char ** create(int wier,int col);
char ** resize(char ***old,int wier,int col);
void at(int wier, int kol,char **tab);
void insert(int wier, int kol,char **tab,int n);
void delete(char ***tab, int n);
void pokaz(char **tab, int wier, int kol);
int wypelnij(char **tab, int wier, int kol);
void copy(char ***new, char **old, int wier, int kol);
int wypisz(char **tab, int wier, int kol);


#endif
