#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

int main(){

 char e[]= {"cd"};

  pid_t pid=fork();

  if(pid>0){
	  int s;
	  pid_t cpid=wait(s);
  }
  else{

      execvp("cd",e);
  }










}
