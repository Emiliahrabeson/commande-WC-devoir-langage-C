#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

void open (FILE** fic,int argc, char* argv[]){
    if(argc==2){
        *fic=fopen(argv[1],"r");
        if(fic == NULL){
            printf("erreur d'ouverture\n");
            exit(1);
        }
    }
    else if(argc==3){ 
        *fic=fopen(argv[2],"r");
        if(fic == NULL){
            printf("erreur d'ouverture\n");
            exit(1);
        }
    }
    else if(argc==4){ 
        *fic=fopen(argv[4],"r");
        if(fic == NULL){
            printf("erreur d'ouverture\n");
            exit(1);
        }
    }
}

void no_option (FILE* fic,int argc ,char* argv[]){
    int count_ligne= 0;
    int count_char = 0;
    int count_word = 0;
    char chaine[255];
    char line;
    int oct = sizeof(line);
    if (argc == 2){
         while((feof(fic)) != 1){
             fgets(chaine,255,fic);
             count_ligne++;
         }
          rewind(fic);
        while ((line = fgetc(fic)) != EOF){
             count_char++;
              if(line != ' '){
                 oct++;
               }
        }
        while (feof(fic) != 1){
            fscanf(fic,"%s",chaine);
            count_word++;
        }
         printf("le nombre de lignes dans %s est %d\n",argv[1],count_ligne);
         printf("le nombre de caractères dans %s est %d\n",argv[1],count_char);
         printf("le nombre de mot dans %s est %d\n",argv[1],count_word);
         printf("le nombre d'octets de %s est %d\n",argv[1],oct-1);
     }
}

void carac (FILE* fic, char* argv[]){
    int count_char = 0;
    char line;
     if( strcmp("-m",argv[1]) == 0){
            while ((line = fgetc(fic)) != EOF){
              count_char++;
            }
        printf("le nombre de caractère dans %s est %d\n",argv[2],count_char);
     } 
}

void word (FILE* fic, char* argv[]){
    char chaine[255];
    int count_word=0;
    if( strcmp("-w",argv[1]) == 0){
        while (feof(fic) != 1){
            fscanf(fic,"%s",chaine);
            count_word++;
        }
        
        printf("le nombre de mot dans %s est %d\n",argv[2],count_word);
        exit(1);
    }
}

void octet (FILE* fic, char* argv[]){
    char line;
    int oct = sizeof(line);
    if( strcmp("-c",argv[1]) == 0){
             while ((line = fgetc(fic)) != EOF){
                 if(line != ' '){
                    oct++;
                 }
             }
     printf("le nombre d'octets de %s est %d\n",argv[2],oct);
    }
}

void ligne (FILE* fic, char* argv[]){
    int count_ligne = 0;
    char chaine[255];
    if( strcmp("-l",argv[1]) == 0){
        while((feof(fic)) != 1){
            fgets(chaine,255,fic);
            count_ligne++;
        }
        printf("le nombre de ligne dans %s est %d\n",argv[2],count_ligne);
    }
}

void max_line (FILE* fic, char* chaine, char* argv[]){
    int max = 0,i,j=0;
    rewind(fic);
    int n = 0;
    if( strcmp("-L",argv[1]) == 0){
        while((feof(fic)) != 1){
            fgets(chaine,255,fic);
            n++;
        }
    rewind(fic);
    int *tab = NULL;
    tab = malloc(n*sizeof(int));
    while ((fgets(chaine,100,fic)) != NULL){
        tab[j] = strlen(chaine);
        j++;
    }
    max = tab[0];
    for(i=0; i<n; i++){
        if(max<tab[i]){
            max = tab[i];
        }
    }
    printf("Nombre de caractere maximale dans une ligne: %d\n",max);
    free(tab);

    }
 }

