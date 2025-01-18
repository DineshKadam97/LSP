#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");

  printf("Received signal is %d\n",signo);
}

int main()
{
  printf("Able to receive the signal\n");
  signal(SIGINT, sig_handler); //miscall dilyavar gharatun nigha //kill system call is used to send the signal and after sensing the signal 
                               //jar signal handle kela nahi tar process marte
                               // signal pathvnyasathi PID and signal ch naav mahiti pahije
                               // junya Unix madhey 19 hote ata 32 signal aahet

  while(1) 
	    sleep(1);
  return 0;
}
