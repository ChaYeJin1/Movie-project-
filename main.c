#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //영화 정보를 불러오기 위한 파일 포인터  
	char input [100];
	int input1;
	float input2;
	struct movie //구조체 정의 
	{
	char name[200]; //영화 제목 
	char country[10]; //국가 
	int runtime; //상영 시간 
	float score; //평점 
	};
	struct movie movies[100]; //구조체 변수 선언(movies라는 실체 생성) 
	int exit_flag = 0; //while 구문 변수 선언 
	int option; //옵션 선택 시 
	int i=0; //i 초기화 

	//2. program start
	fp=fopen("sample.txt","r+"); //영화 정보가 담긴 파일 열기 
		
    fgets(input, sizeof(input), fp); //sample.txt에서 문자열을 읽기 
       
    fscanf(fp,"%s %s %d %f", movies[i].name, movies[i].country, &movies[i].runtime, &movies[i].score); //구조체로 받기 
        
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
