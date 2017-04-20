#include<stdio.h>
#include<stdlib.h>
#include "array.h"

void delete(char ***tab, int n){
	int i;
	for(i=0;i<n;i++){
		free((*tab)[i]);
	}
	free(*tab);
	*tab=NULL;
}

char ** create(int wier,int kol){
	int i,j;
	char **tab;
	tab=(char**)malloc(wier*sizeof(char*));
	if(tab==NULL){
		return NULL;
	}
	for(i=0;i<wier;i++){
		tab[i]=(char*)malloc(kol*sizeof(char));
		if(tab[i]==NULL){
			delete(&tab,i);
			return NULL;
		}
	}
	
	for(i=0;i<wier;i++){
        for(j=0; j<kol; j++){
            tab[i][j]=' ';
        }
    }
    return tab;
}

char ** resize(char ***old,int wier,int kol){
	
	int i=0,j=0,k=0,l=0;
	char ** new;
	while((*old)[i]!=NULL){
		while(old[i][j]!=NULL){
			j++;
		}
		i++;
	}
	if(kol<j || wier<i){
			return NULL;
	}
	new=create(wier,kol);
	if(new==NULL){
		return NULL;
	}
	while((*old)[k]!=NULL){
		l=0;
		while(old[k][l]!=NULL){
			new[k][l]=(*old)[k][l];
			l++;
		}
		k++;
	}
	delete(old,j);
	return new;
	
}

void at(int wier, int kol,char **tab){
	printf("%c ",tab[wier][kol]);
}

void insert(int wier, int kol,char **tab,int n){
	tab[wier][kol]=n;
}


void pokaz(char **tab, int wier, int kol){
	int i,j;
	printf("\n");
	for(i=0;i<wier;i++)
	{
		for(j=0;j<kol;j++){
			at(i,j,tab);
		}
		printf("\n");
	}
}

int wypelnij(char **tab, int wier, int kol){
    int x=0,y=0;
    FILE* fp;
    fp=fopen("danewe.txt","r");
    if(fp==NULL){
		printf("Nie mozna otworzyc pliku wejscioweo");
		return -1;
	}
    while(feof(fp)==0){
       fscanf(fp,"%i",&x);
       fscanf(fp,"%i",&y);
       if(x>wier || y>kol){
           printf("Wspolrzedne wykraczaja poza zakres tablicy");
           return -1;
       }
       tab[x][y]='*';
    }
    fclose(fp);

return 0;
}

void copy(char ***new, char **old, int wier, int kol){
    int i,j;
    for(i=0;i<wier;i++){
        for(j=0;j<kol;j++)
        {
            (*new)[i][j]=old[i][j];
        }
    }
}

int wypisz(char **tab, int wier, int kol){
    int i,j;
    FILE* wyj;
    wyj=fopen("danewy.txt", "w");
    if(wyj==NULL){
		printf("Nie mozna otworzyc pliku wyjsciowego");
		return -1;
	}
    for(i=0;i<wier;i++)
	{
		for(j=0;j<kol;j++){
			fputc(tab[i][j],wyj);
		}
		fputc('\n',wyj);
	}
    fclose(wyj);
	return 0;
}
