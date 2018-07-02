#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/file.h>


int main(){
	
	const char* dockerName = getenv("DOCKER_NAME");
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer [10];

  	
  	
	
		
	FILE* myfile = fopen("folder/arquivo.txt", "a+");
	int descriptor = fileno(myfile);
	
        for(int i = 0 ; i < 3;i++){
	   if(flock(descriptor, LOCK_EX) == 0){
        	char text[50]={};
		time (&rawtime);	
		timeinfo = localtime (&rawtime);
  		strftime (buffer,10,"%X.",timeinfo);
		strcat(text,"\nCONTAINER =");
		strcat(text,dockerName);
		strcat(text," Hora ="); 	
		strcat(text,buffer);
		printf("%s",text);	
		fputs(text, myfile);
		fseek(myfile, 0, SEEK_SET);	
		char p = fgetc(myfile);
		printf ("%c", p);
		sleep(1);
		flock(descriptor, LOCK_UN);
		}
	}
        fclose(myfile);
  	

   return 0;
}
