#include <iostream>
#include <conio.h>
#include <pthread.h>
using namespace std;

void ham1()
{
	char c;
	while(1)
	{
		c=getch();
		FILE *fp=fopen("..\\dulieu.txt","w+t");// ghi cuoi file
		if(fp==NULL)
			continue;
		fprintf(fp,"%c",c);
		fclose(fp);
		printf("%c\n",c);
		if(c=='#')
			break;
	}//while
}

void * fun_thread1(void *data)
{
    ham1(); 
}

int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1;
   
   	printf("Hello: CT1\n");
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,NULL);
    pthread_join(thrd_1, (void **)&status);
    system("PAUSE");
    return 1;
}
