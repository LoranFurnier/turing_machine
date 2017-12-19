#include <stdio.h>
#define plus 25

int main(int argc, char *argv[]){
    FILE *file;
    char command[255];
    char *path;
    file = fopen(argv[1], "rb");
    path="0";
    while(f1==NULL){
    if (path!="0"){
        printf("You're not a good comrade, i see... '%s' isn't file we look for\n", &path);
     }
     printf("Be a good comrade and show the KGB your file: ");
     scanf("%s", &path);
     f1 = fopen(&path, "rb");
   }
    fgets(command, 255, file);
    
    fclose(file);
}