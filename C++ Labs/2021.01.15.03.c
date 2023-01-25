/* FIŞA 2: Codul 1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

func1() 
{ 
	printf("Hello\n"); 
}

func2() 
{ 
	printf("world!\n"); 
}

main(int argc, char *argv[])
{  
	char *prog = argv[0];  
	char *args = argv[1];  
	if(argc==1) 
	{    
		fprintf(stderr, "%s: no args\n", prog);    
		exit(3);  
	}  

	if(argc==2)
	{
		if(args[0] == '-')
		{
			printf("It's only option\n");
		}
		else
		{
			printf("It's only value\n");
		}
	}


	if(argc==3) 
		{
			if(strcmp(args,"-f1")==0)      
				func1();    
			else if(strcmp(args,"-f2")==0)      
				func2();    
			else 
			{      
				fprintf(stderr, "%s: illegal args: %s\n", prog, args);      
				exit(2);    
			}
		}

	if(argc>3) 
	{    
		fprintf(stderr, "%s: no unit for value\n", prog);    
		exit(1);  
	}  
	exit(0);
}
