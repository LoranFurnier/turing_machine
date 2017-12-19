#include <stdio.h>
#define plus 25

int main(int argc, char *argv[]){
    FILE *file;
    char command[255];
    char *path;
    file = fopen(argv[1], "rb");
    path="0";
    while(file==NULL){
    if (path!="0"){
        printf("WRONG ONE!\nWE DON'T LOOK FOR '%s'\n", &path);
     }
     printf("TYPE HERE THE PATH TO YOUR FILE: ");
     scanf("%s", &path);
     file = fopen(&path, "rb");
   }
    fgets(command, 255, file);
    
    fclose(file);
}