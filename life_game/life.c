#include "life.h"

void life(char ***new, char **old, int wier, int kol){

    int i,j,k,l,licznik=0;
    for(i=1;i<wier-1;i++){
        for(j=1;j<kol-1;j++){
        	licznik=0;
            for(k=i-1;k<=i+1;k++){
                for(l=j-1;l<=j+1;l++){
                    if(k!=i || l!=j)
                        if(old[k][l]=='*'){
							licznik++;
						}
                }
            }
            if(old[i][j]=='*'){
                if(licznik==2 || licznik==3){
					(*new)[i][j]='*';
				}
                else{
					(*new)[i][j]=' ';
				}
            }
            if(old[i][j]==' '){
                if(licznik==3){
					(*new)[i][j]='*';
				}
                else{
					(*new)[i][j]=' ';
				}
            }
        }
    }
}
