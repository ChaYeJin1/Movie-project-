#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10 //���Ͽ� ����ִ� ��ȭ(����)�� �� 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   FILE *fp; //��ȭ ������ �ҷ����� ���� ���� ������  
   struct movie //����ü ���� 
   {
   char name[200]; //��ȭ ���� 
   char country[100]; //���� 
   int runtime; //�� �ð� 
   float score; //���� 
   };
   struct movie movies[100]; //����ü ���� ����(movies��� ��ü ����) 
   int exit_flag = 0; //while ���� ���� ���� 
   int option; //�ɼ� ���� �� 
   int i=0; //i �ʱ�ȭ 
   int j=0; //j �ʱ�ȭ
   int cnt=0; //case 2�� ���, ��µǴ� ��ȭ ������ ī��Ʈ 
   int cnt1=0; //case 3�� ���, ��µǴ� ��ȭ ������ ī��Ʈ 
   int cnt2=0; //case 4�� ���, ��µǴ� ��ȭ ������ ī��Ʈ 
   struct movie key[1];

   //2. program start
   fp=fopen("C:\\code\\Movie(project)\\movie(project)\\movie(project)\\Movie-project-\\movie(data).dat","r+"); //��ȭ ������ ��� ���� ���� 
   printf("Reading the data files...\n"); 
       
   for(i=0;i<MAX;i++)
   {
    fscanf(fp,"%s %s %d %f\n", &movies[i].name, &movies[i].country, &movies[i].runtime, &movies[i].score); //����ü�� �ޱ�
   }
   
    fclose(fp); //���� ������ �ݱ�
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
            for(i=0;i<MAX;i++)//���Ͽ� ����� ��ȭ�� ��(MAX) ��ŭ for������ ���پ� �Է¹���  
	           {
                printf("Name : %s (%s)\n", movies[i].name, movies[i].country);
                printf("running time : %d score : %0.6f\n", movies[i].runtime, movies[i].score);
                printf("----------------------------------------\n");
               }
            printf("totally %d movies are listed !\n\n\n", i);
            break;
            
    case 2: //print movies of specific country
        printf("country : ");
        scanf("%s",&key[0].country);//������ �Է¹��� 
            for(j=0;j<MAX;j++)
			{//����Ǿ��ִ� �����Ϳ� �Է¹��� ������ ��
               if(!strcmp(movies[j].country,key[0].country))
			   {//��� �����Ϳ��� ���ϸ鼭 ���� ��ȭ ���� ���
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
        scanf("%d", &key[0].runtime);//��Ÿ���� �Է¹��� 
            for(j=0;j<MAX;j++)
			{//����Ǿ��ִ� �����Ϳ� �Է¹��� ��Ÿ���� ��
               if(movies[j].runtime>=key[0].runtime)
			   {//�Է¹��� ��Ÿ�Ӻ��� �� ��ȭ�� ���
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
        scanf("%f", &key[0].score);//������ �Է¹��� 
            for(j=0;j<MAX;j++)
			{//����Ǿ��ִ� �����Ϳ� �Է¹��� ������ ��
               if(movies[j].score>=key[0].score)
			   {//�Է¹��� �������� ������ ���� ��ȭ�� ��� 
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
