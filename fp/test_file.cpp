#include <stdio.h>
 
int main ()
{
   FILE *fp;
   int c; 
   fp = fopen("file.txt","w+");
   fputs("This is tutorialspoint.com", fp);
 
   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Language", fp);
   rewind(fp);
   fseek(fp, -1L,2);
   int lp = ftell(fp);
   lp++;
    char ch;
    FILE *fp2 = fopen("file1.txt","w+");;
	while (lp) {
   		ch = fgetc(fp);
		fputc(ch,fp2);
        printf("%c ",ch);
		fseek(fp,-2,1);
		lp--;
    } 
	printf("\n");
	rewind(fp2);
   while(1)
   {
      c = fgetc(fp2);
      if( feof(fp2))
      {
         break;
      }
      printf("%c", c); 
   }
   fclose(fp);
   
   
   return(0);
}
