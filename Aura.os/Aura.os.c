#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdbool.h>
#include<string.h>


bool commandes( int a){
     char *stuf[][5] = { 
	     {"ls","-l",NULL},
	     {"date",NULL,NULL},
	     {"pwd",NULL,NULL},
     };
     pid_t pid=fork();

     if(pid > 0){ // for parent process
	     int status;
           pid_t cpid=wait(&status);
     }
     else if(pid == 0){ // for child process
      switch(a){
        case 0:
               return true;
	       _exit(0);
	break;
	case 1:
              execvp("date", stuf[1]);
	break;
	case 2:
              execvp("pwd", stuf[2]);
	break;
	case 3:
              execvp("ls", stuf[0]);
	break;
	case 4:
              printf("not ready yet.\n");
	break;
      }
     }
     else{ printf("there is a problem.\n");} // if fork faild
	//return false;
}
int detect( char input[]){
	char e[]= "exit"; // a=0
        char w[]= "where"; // a=2
	char t[]= "time"; // a=1
	char s[]= "search"; //  a=3
        char h[]= "history"; // a=4
        bool c = false;

    while(c != true){ // this loop is made to see if the input is valide 
      
        if(input[0] == 'e'){
		if(strlen(input) != 4){
			return 404;
		}
		else{
			for(int i=0; i<strlen(input); i++){
				if(input[i] == e[i]){
					if(i == 3){
						return 0;
					}
				}
				else{return 404;}
			}
		}
	}
	else if(input[0] == 't'){
		if(strlen(input) != 4){
			return 404;
		}
		else{
			for(int i=0; i<strlen(input); i++){
				if(input[i] == t[i]){
					if(i == 3){
                                           return 1;
					}
				}
				else{return 404;}
			}
		}

	     }
	     else if(input[0] == 'w'){
		     if(strlen(input) != 5){
			     return 404;
		     }
		     else{
			     for(int i=0; i<strlen(input); i++){
				     if(input[i] == w[i]){
					     if( i == strlen(input) -1){
						     return 2;
					     }
				     }
				     else{return 404;}
			     }
		     }
	          }
	          else if(input[0] == 's'){
			  if(strlen(input) != 6){
				  return 404;
			  }
			  else{
				  for(int i=0; i < strlen(input); i++){
                                            if(input[i] == s[i]){
						    if(i == strlen(input) -1){
							    return 3;
						    }
					    }
					    else{return 404;}
				  }
			  }

		       }
		       else if(input[0] == 'h'){
			       if(strlen(input) != 7){
			                return 404;
		               }
			       else{
                                     for(int i=0; i < strlen(input); i++){
					     if( input[i] == h[i]){
						     if(i == strlen(input) -1){
							     return 4;
						     }
					     }
					     else{return 404;}
				     }
			       }
			}     
	else{return 404;}
     }
}





int main(){
 int a;
  bool control=false;
  char input[100];

  while(control != true){ // this loop made for forcing the user to type exit to leave the code
	
      printf("Aura~os~£ ");
      scanf("%s",input);
  
   a=detect(input);
//   printf("%d\n",a);
     if(a != 404){
          control = commandes(a);
	  if(control == true){ printf("1\n");
	  }
	  else{ printf("0\n");
	  }
     } 
     else{ 
	     printf("!?! Wrong input, there is no --%s-- in Aura.os commandes.\n",input);
     }



  }










return 333;
}
