#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* fp;
int a[6] = {0};
void lotto(void){
   int var, isExist, n = 0;
   for(int i = 0 ; i < 6 ; i++) {
      a[i] = 0;
   }
   while(n <= 5){
      var = rand() % 69 + 1;   
      isExist = 0;   
      for(int i = 0 ; i <= n ; i++) {
         if(a[i] == var){ 
            isExist = 1;
         }
      }
         if(isExist == 0) {
         a[n] = var; n++; 
      }
   }
   for (int i = 0; i < 6; ++i) {
       for (int j = 0; j < i; ++j) {
          if (a[j] > a[i]) {
             int temp = a[j];
             a[j] = a[i];
             a[i] = temp;
          }
       }
   }
   a[5] = rand() % 10 + 1;
   for(int i = 0 ; i < 6 ; i++) {
      fprintf(fp, "%02d ", a[i]);
   }
}
int main(){
   int n=2;
   srand(time(NULL));
   printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:2 \n");
   //scanf("%d", &n);
   printf("已為您購買的2組樂透組合輸出至lotto.txt");
   fp = fopen("lotto.txt", "w+");
   fprintf(fp, "======== lotto649 =========\n");
   time_t curtime;
   time(&curtime);
   fprintf(fp, "=%s", ctime(&curtime));
   for(int i = 0 ; i < n ; i++) {
      fprintf(fp, "[%d] : " ,i+1);
      lotto();
      fprintf(fp, "\n");
   }
   for(int k = 0 ; k < (5-n) ; k++) {
      fprintf(fp, "[%d] : ", n+k+1);
      for(int j = 0 ; j < 6 ; j++) {
         fprintf(fp, "-- ");
      }
      fprintf(fp, "\n");
   }
   fprintf(fp, "======== csie@CGU =========\n");
   fclose(fp);
}