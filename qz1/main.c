#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>

FILE* lottery_txt;
FILE* bin;
static int currentCount;

void countTimes(){
    int read[1];
    int write[1];    
    if((bin = fopen("bin.txt", "r")) == NULL){
        bin = fopen("bin.txt", "wb+");
        write[0] = 1;       
        fwrite(write, sizeof(int), 1, bin);
    }
    else{
        bin = fopen("bin.txt", "rb+");
        fseek(bin, 0, SEEK_SET);
        fread(read, sizeof(int), 1, bin);
        fclose(bin);    
        write[0] = read[0] + 1;
        bin = fopen("bin.txt", "wb+");
        fwrite(write, sizeof(int), 1, bin);
    }
    fclose(bin);
    currentCount = write[0];
}  

void get_6_RandNum(){
    int r[12];
    int i = 0, j, box;
    while(i<=5){
        box = rand()%69+1;
        for(j = 0; j < i; j++){
            if(box == r[j])break;
        }
        if(j == i){
            r[i] = box; i++;
        }
    }
    for (int a = 0; a < 6; ++a) {
        for (int b = 0; b < a; ++b) {
              if (r[b] > r[a]) {
            int temp = r[b];
            r[b] = r[a];
            r[a] = temp;
            }    
           }
    }
    r[6] = rand()%10+1;
    for(j = 0; j <= 6; j++){
        fprintf(lottery_txt,"%02d ",r[j]);
    }
}
void Delay(unsigned int secs){
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int main(){
    int a,i=5;
    char currentName[80];
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:5");
    for(int t = 1; t <= 3; t++){
        Delay(1);
        printf(".");
    }
    Delay(1);
    printf("已為您購買的5組樂透組合輸出至lotto.txt");

    srand(time(NULL));
    countTimes();
    sprintf(currentName, "lotto[%04d].txt", currentCount);
    lottery_txt = fopen(currentName,"w+");
    time_t now;
    time(&now);
    char* dt = ctime(&now);
    dt[strlen(dt)-1]=0;
    fprintf(lottery_txt,"========= lotto649 =========\n= %s =\n", dt);
    fprintf(lottery_txt,"========+ No.%05d +========\n", currentCount);
    for(a = 1; a <= i; a++){
        fprintf(lottery_txt,"= [%d]:", a);
        get_6_RandNum();
        fprintf(lottery_txt,"=\n");
    }
    for(; a <= 5; a++)fprintf(lottery_txt,"= [%d]:== == == == == == == =\n", a);
    fprintf(lottery_txt,"========= csie@CGU =========\n");
    fclose(lottery_txt);
}