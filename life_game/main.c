#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "array.h"
#include "life.h"
#define WIER 22
#define KOL 80

int main(){
	
	
	char c;
    char** tab_old=create(WIER,KOL);
    if(tab_old==NULL){
		return -1;
	}
    if(wypelnij(tab_old,WIER,KOL)==-1){
		return -1;
	}
    char** tab_new;
    tab_new=create(WIER,KOL);
    if(tab_new==NULL){
		return -1;
	}

    do
    {
        printf("1 - Wykonaj n ruchow gry w zycie\n2 - Zakoncz program\n");
        scanf(" %c",&c);
        system("clear");
        if(c=='1')
        {
        	int n;
            printf("Podaj liczbe ruchow\n");
            scanf("%d",&n);
            system("clear");
            pokaz(tab_old,WIER,KOL);
            sleep(1);
            system("clear");
            while(n>0)
            {

                life(&tab_new,tab_old,WIER,KOL);
                pokaz(tab_new,WIER,KOL);
                copy(&tab_old,tab_new,WIER,KOL);
                sleep(1);
                system("clear");
                n--;
            }
        }
        else{
			if(c!='1' && c!='2'){
				printf("Wpisz prawidlowe polecenie\n");
			}
		}

    }while(c!='2');
    
    if(wypisz(tab_new,WIER,KOL)==-1){
		return -1;
	}

    delete(&tab_old,WIER);
    delete(&tab_new,WIER);
return 0;
}
