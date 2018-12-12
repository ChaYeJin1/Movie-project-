#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10 //파일에 들어있는 영화(정보)의 수 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   FILE *fp; //영화 정보를 불러오기 위한 파일 포인터  
   struct movie //구조체 정의 
   {
   char name[200]; //영화 제목 
   char country[100]; //국가 
   int runtime; //상영 시간 
   float score; //평점 
   };
   struct movie movies[100]; //구조체 변수 선언(movies라는 실체 생성) 
   int exit_flag = 0; //while 구문 변수 선언 
   int option; //옵션 선택 시 
   int i=0; //i 초기화 
   int j=0; //j 초기화
   int cnt=0; //case 2인 경우, 출력되는 영화 데이터 카운트 
   int cnt1=0; //case 3인 경우, 출력되는 영화 데이터 카운트 
   int cnt2=0; //case 4인 경우, 출력되는 영화 데이터 카운트 
   struct movie key[1];

   //2. program start
   fp=fopen("C:\\code\\Movie(project)\\movie(project)\\movie(project)\\Movie-project-\\movie(data).dat","r+"); //영화 정보가 담긴 파일 열기 
   printf("Reading the data files...\n"); 
       
   for(i=0;i<MAX;i++)
   {
    fscanf(fp,"%s %s %d %f\n", &movies[i].name, &movies[i].country, &movies[i].runtime, &movies[i].score); //구조체로 받기
   }
   
    fclose(fp); //파일 포인터 닫기
    printf("Read done ! %d items are read\n\n\n", i);
    
    
   while(exit_flag == 0)
   {
      printf("----------Menu----------\n");
      printf("1. print all the movies\n");
      printf("2. search for specific country movies\n");
      printf("3. search for specific runtime movies\n");
      printf("4. search for specific score movies\n");
      printf("5. exit\n");
      printf("----------Menu----------\n\n");
      printf("select an option : ");
      scanf("%d", &option);
            
   switch(option)
   {
    case 1: //print all the movies
        printf("\nprinting all the movies in the list.....\n\n\n");
        printf("----------------------------------------\n");
            for(i=0;i<MAX;i++)//파일에 저장된 영화의 수(MAX) 만큼 for문으로 한줄씩 입력받음  
	           {
                printf("Name : %s (%s)\n", movies[i].name, movies[i].country);
                printf("running time : %d score : %0.6f\n", movies[i].runtime, movies[i].score);
                printf("----------------------------------------\n");
               }
            printf("totally %d movies are listed !\n\n\n", i);
            break;
            
    case 2: //print movies of specific country
        printf("country : ");
        scanf("%s",&key[0].country);//국가를 입력받음 
        cnt=0;
            for(j=0;j<MAX;j++)
			{//저장되어있는 데이터와 입력받은 변수를 비교
               if(!strcmp(movies[j].country,key[0].country))
			   {//모든 데이터에서 비교하면서 같은 영화 정보 출력
                printf("Name : %s (%s)\n", movies[j].name, movies[j].country); 
                printf("running time : %d score : %0.6f\n", movies[j].runtime, movies[j].score); 
                printf("----------------------------------------\n");
                cnt++;
               }
            }
            printf("totally %d movies are listed !\n\n\n", cnt);
            break;
                  
      case 3: //print movies with long runtime
        printf("runtime : "); 
        scanf("%d", &key[0].runtime);//런타임을 입력받음 
        cnt1=0;
            for(j=0;j<MAX;j++)
			{//저장되어있는 데이터와 입력받은 런타임을 비교
               if(movies[j].runtime>=key[0].runtime)
			   {//입력받은 런타임보다 긴 영화를 출력
                printf("Name : %s (%s)\n", movies[j].name, movies[j].country); 
                printf("running time : %d score : %0.6f\n", movies[j].runtime, movies[j].score); 
                printf("----------------------------------------\n");
                cnt1++;
               }
            }
            printf("totally %d movies are listed !\n\n\n", cnt1);
            break;
            
      case 4: //print movies with high score
        printf("score : ");
        scanf("%f", &key[0].score);//평점을 입력받음 
        cnt2=0;
            for(j=0;j<MAX;j++)
			{//저장되어있는 데이터와 입력받은 평점을 비교
               if(movies[j].score>=key[0].score)
			   {//입력받은 평정보다 평점이 높은 영화를 출력 
                printf("Name : %s (%s)\n", movies[j].name, movies[j].country); 
                printf("running time : %d score : %0.6f\n", movies[j].runtime, movies[j].score); 
                printf("----------------------------------------\n");
                cnt2++;
               }
            }
            printf("totally %d movies are listed !\n\n\n", cnt2);
            break;
            
      case 5:
        printf("\n\nBye!\n\n");
        exit_flag = 1;
        break;
            
      default:
        printf("wrong command! input again\n");
        break;
            
            }

   }
   
   return 0;
}
