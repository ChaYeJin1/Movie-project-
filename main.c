#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //��ȭ ������ �ҷ����� ���� ���� ������  
	char input [100];
	int input1;
	float input2;
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

	//2. program start
	fp=fopen("movie.dat","r+"); //��ȭ ������ ��� ���� ���� 
		
    fgets(input, sizeof(input), fp); //movie.dat���� ���ڿ��� �б�
	 
    for(i=0; i<100; i++)
	{
	 fscanf(fp,"%s %s %d %f", movies[i].name, movies[i].country, &movies[i].runtime, &movies[i].score); //����ü�� �ޱ� 
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
	        for(i=0; i<100; i++)
            {
                printf("\nprinting all the movies in the list.....\n\n\n");
            	scanf("%s %s %d %f", movies[i].name, movies[i].country, &movies[i].runtime, &movies[i].score);
	        } 
			
			break;
				
		case 2: //print movies of specific country
			for(i=0; i<100; i++)
            {
            	printf("country : ");
            	scanf("%s", &movies[i].country);
	        } 
            break;
				
		case 3: //print movies with long runtime
			for(i=0; i<100; i++)
            {
            	printf("runtime : ");
            	scanf("%d", &movies[i].runtime);
	        } 
            break;
				
		case 4: //print movies with high score
			for(i=0; i<100; i++)
            {
            	printf("score : ");
            	scanf("%f", &movies[i].score);
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
