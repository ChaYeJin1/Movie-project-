#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char buffer[100]; // 파일을 읽을 때 사용할 임시 공간
	char input [100];
	int input1;
	float input2;
	struct movie
	{
	char name[200]; //movie name
	char country[10]; //movie country
	int runtime; //movie runtime
	float score; //movie score
	};
	struct movie movies[100];
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	int i=0;
	int word;
	int arg;

	//2. program start
	fp=fopen("sample.txt","r+");
		
    fgets(input, sizeof(input), fp); //sample.txt에서 문자열을 읽음
            
    fscanf(fp,"%s %s %d %lf", movies[i].name, movies[i].country, &movies[i].runtime, &movies[i].score);
        
    fclose(fp); //파일 포인터 닫기

	
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
            	scanf("%s", &movies[i].runtime);
	        } 
            break;
				
		case 4: //print movies with high score
			for(i=0; i<100; i++)
            {
            	printf("score : ");
            	scanf("%s", &movies[i].score);
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
