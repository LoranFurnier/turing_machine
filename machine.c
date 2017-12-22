#include <stdio.h>
#include <stdlib.h>
#define plus 10
FILE *file;
    char command[255];
    char *path;
    int *band=NULL;
    int place=0;
    int size=10;
void movl(){
    int i, a;
    place--;
    if(place<0){
        size+=plus;
        band = (int *)realloc(band, size * sizeof(int));
        printf("\nATTENTION!\nTO DO A 'MOVL' COMMAND WE MOVE ALL THE BAND TO THE RIGHT\nNOW ALL THE PLACES HAVE NEW NUMBERS, WHICH DIFFERS IN '%d'", plus);
        place+=plus;
        for(i=0; i<size; i++){
            a = band[i];
            band[i] = band[plus+i];
            band[plus+i] = a;
        }
    }
    printf("\nNOW YOU ARE IN CELL №%d", place);
}
void movr(){
    place++;
    if(place>size){
        size+=plus;
        band = (int *)realloc(band, size * sizeof(int));
        printf("\nATTENTION!\nTO DO A 'MOVR' COMMAND WE MAKE WHITE SPACE TO THE RIGHT");
    }
    printf("\nNOW YOU ARE IN CELL №%d", place);
}
void inc(){
    band[place]++;
    if(band[place]>255){
        printf("\nYOU CAN'T DO THIS!\nYOU'RE TRYING TO MAKE THE VALUE OF CELL №%d GREATER, THAN 255\nYOU HAVE BEEN WARNED\nNOW BAND CELL №%d IS 0", place, place);
        band[place]=0;
    }
    printf("\nNOW CELL№%d'S VALUE IS %d", place, band[place]);
}
void dec(){
    band[place]--;
    if(band[place]<0){
        printf("\nYOU CAN'T DO THIS!\nYOU'RE TRYING TO MAKE THE VALUE OF CELL №%d SMALLER, THAN 0\nYOU HAVE BEEN WARNED\nNOW BAND CELL №%d IS 0", place, place);
        band[place]=0;
    }
     printf("\nNOW CELL№%d'S VALUE IS %d", place, band[place]);
}
void show(){
    printf("\nATTENTION!\nTHE 'PRINT' COMMAND IS BEING CALLED!\nCELL №%d'S VALUE IS %d", place, band[place]);
}
void capture(){
    char c;
    printf("ATTENTION!\nA 'GET' COMMAND IS BEING CALLED!\nNOW TYPE HERE 1 BYTE OF INFORMATION TO BE PUT INTO CELL №%d!: ", place);
    c = getchar();
    band[place]=(int)c;
    if(band[place]>255){
        printf("\nYOU CAN'T DO THIS!\nYOU'RE TRYING TO MAKE THE VALUE OF CELL №%d GREATER, THAN 255\nYOU HAVE BEEN WARNED\nNOW BAND CELL №%d IS 0", place, place);
        band[place]=0;
    }
}
void showchar(){
    printf("\nATTENTION!\nTHE 'PRINT' COMMAND IS BEING CALLED!\nCELL №%d ASCII VALUE IS %c", place, (char)band[place]);
}
int argument(char *str){
    if((str=="inc") || (str=="INC")){
        return 1;
    } else if((str=="dec") || (str=="DEC")){
        return 2;
    } else if((str=="movl") || (str=="MOVL")){
        return 3;
    } else if((str=="movr") || (str=="MOVR")){
        return 4;
    } else if((str=="print") || (str=="PRINT")){
        return 5;
    } else if((str=="get") || (str=="GET")){
        return 6;
    } else if((str=="printc") || (str=="PRINTC")){
        return 7;
    }
    return 0;
}
int main(int argc, char *argv[]){
    file = fopen(&argv[1], "rb");
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
        fgets(&command, 254, file);
        switch(argument(command)){
            case 1:
            {
                inc();
                break;
            }
            case 2:
            {
                dec();
                break;
            }
            case 3:
            {
                movl();
                break;
            }
            case 4:
            {
                movr();
                break;
            }
            case 5:
            {
                show();
                break;
            }
            case 6:
            {
                capture();
                break;
            }
            case 7:
            {
                showchar();
                break;
            }
    }
    fclose(file);
}
return 0;
}
