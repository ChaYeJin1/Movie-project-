#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   
   FILE *fp; //��ȭ ������ �ҷ����� ���� ���� ������  
   struct movie //����ü ���� 
   {
   char name[200]; //��ȭ ���� 
   char country[10]; //���� 
   int runtime; //�� �ð� 
   float score; //���� 
   };
   struct movie movies[100]; //����ü ���� ����(movies��� ��ü ����) 
   int exit_flag = 0; //while ���� ���� ���� 
   int option; //�ɼ� ���� �� 
   int i=0; //i �ʱ�ȭ 
   int j=0; //j �ʱ�ȭ 
   struct movie key[1];

   //2. program start
   fp=fopen("C:\\code\\Movie(project)\\movie(project)\\movie(project)\\Movie-project-\\movie(data).dat","r+"); //��ȭ ������ ��� ���� ���� 
       
   for(i=0;i<10;i++)
   {
    fscanf(fp,"%s %s %d %f\n", movies[i].name, movies[i].country, &movies[i].runtime, &movies[i].score); //����ü�� �ޱ�
   }
    fclose(fp); //���� ������ �ݱ�

   
   while(exit_flag == 0)
   {
      printf("----------Menu----------\n");
      printf("1. print all the movies\n");
      printf("2. search for specific country movies\n");
      printf("3. search for specific runtime movies\n");
      printf("4. search for specific score movies\n");
      printf("5. exit\n");
      printf("----------Menu----------\n");
      printf("select an option : ");
      scanf("%d", &option);
            
   switch(option)
   {
    case 1: //print all the movies
        printf("\nprinting all the movies in the list.....\n\n\n");
        printf("----------------------------------------\n");
            for(i=0;i<10;i++)
	           {
                  printf("Name : %s/country : %s/running time : %d/score : %0.2f\n", movies[i].name, movies[i].country, movies[i].runtime, movies[i].score);
                  printf("----------------------------------------\n");
               }
            printf("totally %d movies are listed !\n", i);
            break;
            
    case 2: //print movies of specific country
        printf("country : ");
        scanf("%s",&key[0].country);//���� ���ڸ� �Է¹޴� ����
            for(j=0;j<10;j++){//����Ǿ��ִ� �����Ϳ� �Է¹��� ������ ��
               if(!strcmp(movies[j].country,key[0].country))
			   {//��� �����Ϳ��� ���ϸ鼭 ���� ��ȭ���� ���
                  printf("Name : %s/country : %s/running time : %d/score : %0.2f\n", movies[j].name, movies[j].country, movies[j].runtime, movies[j].score);
                  printf("----------------------------------------\n");
               }
            }
            break;
                  
      case 3: //print movies with long runtime
        printf("runtime : ");
        scanf("%d", &key[0].runtime);//��Ÿ���� �Է¹��� 
            for(j=0;j<10;j++)
			{//����Ǿ��ִ� �����Ϳ� �Է¹��� ��Ÿ���� ��
               if(movies[j].runtime>=key[0].runtime)
			   {//�Է¹��� ��Ÿ�Ӻ��� �� ��ȭ�� ���
                  printf("Name : %s/country : %s/running time : %d/score : %0.2f\n", movies[j].name, movies[j].country, movies[j].runtime, movies[j].score);
                  printf("----------------------------------------\n");
               }
            }
            break;
            
      case 4: //print movies with high score
        printf("score : ");
        scanf("%f", &key[0].score);
            for(j=0;j<10;j++){// ������ �Է¹޾Ƽ� �Է¹��� �������� ���� ��ȭ�� ��� 
               if(movies[j].score>=key[0].score)
			   {
                  printf("Name : %s/country : %s/running time : %d/score : %0.2f\n", movies[j].name, movies[j].country, movies[j].runtime, movies[j].score);
                  printf("----------------------------------------\n");
               }
            }
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
