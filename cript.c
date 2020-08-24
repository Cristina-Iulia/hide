#include <stdio.h>


void encript(FILE *fp){

  fprintf(fp, "P3\n");
  fprintf(fp, "1000 1000\n");
  fprintf(fp, "255\n");
  int i=1,j=1;
  int color=0;
    char c;

    while((c=getchar())!='\n'){
        unsigned char green=0;
        int nr_bit=8;
        while(nr_bit!=0){
          unsigned char bit=0x1;
          bit=bit & c;

          green=green|bit;
          c=c>>1;
          nr_bit--;
          fprintf(fp, "%d %d %d  ",color,green,color );
          green=0;

          if(i<=10000){
              if(j<1000)j++;
              else {
                i++;
                fprintf(fp, "\n");
              }
        }
        if(color<255)
            if(i%3==0)color++;

        }

    }

    while(i<=1000){
      fprintf(fp, "\n");
      j=1;
      while(j<=1000){
        fprintf(fp, "%d 0 %d  ",color,color );
        j++;
      }
      if(color<255)
          if(i%3==0)color++;

        i++;
      }



}

int main(){
  FILE *fp=fopen("to_decript.ppm","w");


  if(!fp){
    printf("\nError at accesing file\n");
    return 0;
  }


encript(fp);

return 0;
}
