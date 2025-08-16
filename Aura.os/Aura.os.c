#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct car{  
   char data;
   struct car *next;
} car;


typedef struct his{
	int num;
	struct his *next;
        struct car *down;
} his;

void scan( char input[], struct his *head){
                  
	int j=1;
	bool con = true;
	struct his *line;
	struct his *this;
	struct car *column;
	struct car *last;	

	line= (his *)malloc(sizeof(his));
	 this = head;
	while(con == true){
		if(this->next == NULL){
			con = false;
		}
		else{
	           this=this->next;
         	   j++;
		}   
	}
	this->next = line;
	line->num = j;
	line->next = NULL;
	line->down = NULL;
        
	for(int i=0; i<strlen(input); i++){

	column= (car *)malloc(sizeof(car));
	      if(con == false){ // this is for linking the two linked-lists
		      this->down=column;
		      con = true;
	      }
	      if(i != 0){
		      last->next=column;
	      }
	   column->data=input[i];
	   column->next=NULL;
	   last=column;
	}
}
void print(his head){

	struct his *this;
	struct car *this0;
	this= head.next;

	while(this->next != NULL){
         printf("%d- ",this->num);
	 this0= this->down;
	   while(this0 != NULL){
	    printf("%c",this0->data);
            this0=this0->next;
	   }
	 printf(".\n");
	 this=this->next;
	}
}
bool commandes( int a, his head){
     char *stuf[][5] = { 
	     {"ls","-l",NULL},
	     {"date",NULL,NULL},
	     {"pwd",NULL,NULL},
	     {"clear",NULL,NULL},
     };
     pid_t pid=fork();

     if(pid > 0){ // for parent process
	     int status;
           pid_t cpid=wait(&status);
     }
     else if(pid == 0){ // for child process
      switch(a){
        case 5:
	      execvp("clear", stuf[3]);
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
	case 6:
	     printf("exit= exit the shell.\nwhere= pwd.\ntime= date.\nsearch= ls -l.\nempty= clear.\ncmd= show commandes.\n");
	     _exit(0);
	break; 
	case 4:
	     print(head);
	     _exit(0);
	break;      
      }
     }
     else{ printf("there is a problem.\n");} // if fork faild
	return false;
}
int detect( char input[]){
	char e[]= "exit"; // a=0
        char w[]= "where"; // a=2
	char t[]= "time"; // a=1
	char s[]= "search"; //  a=3
        char h[]= "history"; // a=4
	char p[]= "empty";  // a=5
	char m[]= "cmd"; //  a=6
        bool c = false;

    while(c != true){ // this loop is made to see if the input is valide 
      
        if(input[0] == 'e'){
                 if(strlen(input) == 5){
			 for(int i=0; i<strlen(input); i++){
				 if(input[i] == p[i]){
					 if(i == strlen(input) -1){
						 return 5;
					 }
				 }
				 else{return 404;}
			 }

		 }
		else if(strlen(input) != 4 && strlen(input) != 5){
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
		            else if(input[0] == 'c'){
				    if(strlen(input) != 3){
					    return 404;
				    }
				    else{
                                          for(int i=0; i < strlen(input); i++ ){
						  if(input[i] == m[i]){
							  if(i == strlen(input) -1){
								  return 6;
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
  char input[1000];
  
  his head;
  head.num=0;
  head.next=NULL;
  head.down=NULL;
  
  printf("If you want to see the commandes type cmd.\n");
  while(control != true){ // this loop made for forcing the user to type exit to leave the code
	
      printf("Aura~os~£ ");
      scanf("%s",input);

   scan(input, &head);
   a=detect(input);
//   printf("%d\n",a);
     if(a == 0){
	     return 333;
     }
          else if(a != 404){
              commandes(a, head);
               } 
               else{ 
	           printf("!?! Wrong input, there is no --%s-- in Aura.os commandes.\n",input);
               }
  }
return 333;
}
