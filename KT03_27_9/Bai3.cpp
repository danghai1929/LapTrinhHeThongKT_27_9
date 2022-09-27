#include <iostream>
#include <conio.h>
#include <pthread.h>
#include<windows.h> 
using namespace std;
char c;
void ham1()
{
	while(1)
	{
		c=getch();
		if(c=='!')
			break;
		printf("%c\n",c);
		Sleep(5);
	}//while
}

void * fun_thread1(void *data)
{
    ham1(); 
}

void ham2()
{
	while(1)
	{
		if(c == '!')
			break;
		//printf("Beep!");
		Beep(523,2000);
		Sleep(1);
	}
}

void * fun_thread2(void *data)
{
    ham2(); 
}

int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1 , thrd_2;
    // create thread
    pthread_create(&thrd_1,NULL,fun_thread1,NULL);   
    pthread_create(&thrd_2,NULL,fun_thread2,NULL);
	pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
