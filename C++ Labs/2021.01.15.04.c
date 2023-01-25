/* FIŞA 2: Codul 1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1() 
{ 
	printf("Hello\n"); 
}

void func2() 
{ 
	printf("world!\n"); 
}

_Bool func3(char *prog, char *args)
{
			if(strcmp(args,"-f1")==0)      
			{
				func1(); 
				return 1;
			}
				  
			else if(strcmp(args,"-f2")==0)
			{
				func2();
				return 1;
			}
			else 
			{      
				fprintf(stderr, "%s: illegal args: %s\n", prog, args);        
			}
			
			return 0;
}

int main(int argc, char *argv[])
{  
	char *prog = argv[0];  
	char *args = argv[1];  
	if(argc==1) 
	{    
		fprintf(stderr, "%s: no args\n", prog);    
		exit(3);  
	}  

	if(argc==2) 
		if(func3(prog, args)) printf("Returned 1\n");
		else printf("Returned 0\n");

	if(argc>2) 
	{    
		fprintf(stderr, "%s: no unit for value\n", prog);    
		exit(1);  
	}  
	exit(0);

	return 0;
}
