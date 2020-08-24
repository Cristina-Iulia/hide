#include <stdio.h>


void decript(FILE *f){

  //read the header of the file
  unsigned char c;
  int d1,d2;
    fscanf(f,"%c%d",&c,&d1);
    fscanf(f,"%d %d",&d1,&d2);
    fscanf(f,"%d",&d1);

printf("\n");
  while(c!=0x0){
    c=0x0;
    int nr_bit=1;
    while(nr_bit<=8){
      unsigned char green;
      fscanf(f,"%d %d %d",&d1,&green,&d2);
      green=green<<(nr_bit-1);
      c=c|green;
      nr_bit++;
    }
    printf("%c",c );
  }

}
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
  FILE *fp=fopen("encripted.ppm","r");


  if(!fp){
    printf("\nError at accesing file\n");
    return 0;
  }


decript(fp);

return 0;
}
