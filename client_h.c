#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[2]){

  //char *ip = "127.0.0.1";  /* need ip address and port no. we using the local host or local address $ any port no. greater tthan 5000 since it is standred */
  //int port = 5566;
  int port;
  port=atoi(argv[2]);
/*now variable & structure*/
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;
  char buffer[1024]; /* since we need to transfer information one to nother so to store iinformtion we have buffer*/
  int n;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = INADDR_ANY;

  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  printf("Connected to the server.\n");

  			//start your code from here
  			
  int dataatrec[10];   //record the data to be recieved
  int test[10];	//data to be tested
  int p,p1,p2,p4;	// p to find the error
  
  printf(" the recieved data is:");
  for(int i=0;i<7;i++)
  {
  	n=read(sock,&dataatrec[i], sizeof(int));
  
  
  if(n<0)
  	perror("\nerror on data recieved data\n");
  	printf("%d", dataatrec[i]);
  	
  }			
  
  printf("\nplease enter the data you want to test");
  for(int i=0; i<7;i++)
  	scanf("%d",&test[i]);
  	
  p1=test[6]^test[4]^test[2]^test[0];
  p2=test[5]^test[4]^test[1]^test[0];
  p4=test[3]^test[0]^test[2]^test[1];	
  
  p=(4*p4)+(2*p2)+p1;
  
  printf("the data for testing is");
  	for(int i=0;i<7;i++)
  		printf("%d", test[i]);	
  		
  if(p==0)
  {
  	printf("no error");
  }
  else
  {
  	printf("\nthe error is at position %d",p);
  	printf("the correct data is:");
  	if(test[7-p]==0)
  		test[7-p]=1;
  	else
  		test[7-p]=0;
  	
  	for(int i=0;i<7;i++)
  	{
  		printf("%d", test[i]);
  	}
  }	
  			
  			
  			//end your code here

  close(sock);
  printf("Disconnected from the server.\n");

  return 0;

}
