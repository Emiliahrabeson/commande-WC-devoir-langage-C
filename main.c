#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

int main(int argc, char* argv[]){
    FILE* fic = NULL;
    char* chaine;
    open (&fic,argc,argv);
    no_option (fic,argc ,argv);
    carac (fic,argv);
    word (fic,argv);
    octet (fic,argv);
    word (fic,argv);
    ligne (fic,argv);
    max_line (fic, chaine,argv);
    fclose(fic);
    return 0;
}