#include <stdio.h>
#include <stdlib.h>
#define plus 25
FILE *file;
    char command[255];
    char *path;
    int *band=NULL;
    int place=0;
    int size=10;
void makebigger(){
    
}
void movl(){
    place--;
    if(place<0){
        size+=plus;
        band = (int *)realloc(band, (plus+size) * sizeof(int));
    }
    printf("NOW YOU ARE IN CELL №%d", place);
}
void inc(){
    band[place]++;
    if(band[place]>255){
        printf("YOU CAN'T DO THIS!\nYOU'RE TRYING TO MAKE THE VALUE OF CELL №%d GREATER, THAN 255\nYOU HAVE BEEN WARNED\nNOW BAND CELL №%d IS 0", place, place);
        band[place]=0;
    }
}
void dec(){
    band[place]--;
    if(band[place]<0){
        printf("YOU CAN'T DO THIS!\nYOU'RE TRYING TO MAKE THE VALUE OF CELL №%d SMALLER, THAN 0\nYOU HAVE BEEN WARNED\nNOW BAND CELL №%d IS 0", place, place);
        band[place]=0;
    }
}
void show(){
    printf("CELL №%d'S VALUE IS %d", place, band[place]);
}
void capture(){
    char c;
    printf("ATTENTION!\nA 'GET' COMMAND IS BEING CALLED!\nNOW TYPE HERE 1 BYTE OF INFORMATION TO BE PUT INTO CELL №%d!: ", place);
    c = getchar();
    band[place]=(int)c;
}
int main(int argc, char *argv[]){
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
    while(!feof(file)){
        fgets(command, 255, file);
       
    }
    fclose(file);
}