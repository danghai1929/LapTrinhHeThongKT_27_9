#include <iostream>
#include <conio.h>
#include <pthread.h>

void ham2()
{
	char c,c_save='#';
	while(1)
	{
		FILE *fp=fopen("..\\dulieu.txt","rt");// ghi cuoi file
		if(fp==NULL)
			continue;
		if(feof(fp))
		{
			fclose(fp);
			continue;
		}
		else
		{
			c=fgetc(fp);
			if(c!=c_save)
				printf("%c\n",c);
			c_save=c;
			if(c=='!')
				break;
		}
					
		//dong file
		fclose(fp);
	}//while
}

void * fun_thread2(void *data)
{
    ham2(); 
}

int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_2;
    
    printf("Hello: CT2\n");
    // create thread
    pthread_create(&thrd_2,NULL,fun_thread2,NULL);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
