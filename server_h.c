#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  if(argc<2)
  {
  	printf( "port no. not provided\n");
  	exit(1);
  }
  
  //char *ip = "127.0.0.1";  /* need ip address and port no. we using the local host or local address $ any port no. greater tthan 5000 since it is standred */
  int port;
  port=atoi(argv[1]);
/*now variable & structure*/
  int server_sock, newsockfd, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  
  char buffer[1024]; /* since we need to transfer information one to nother so to store informtion we have buffer*/
  socklen_t clilen;
  int n;
/*now need to creaete tcp server*/
  server_sock = socket(AF_INET, SOCK_STREAM, 0); /*here socket function is used, here strem is used for tcp if udp then different*/
  
  /*now code for error*/  
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");  /*if program does not exit it mens tcp server creted*/

  memset(&server_addr, '\0', sizeof(server_addr));  /*address of the server_addr with null vlue with size server_addr*/
  server_addr.sin_family = AF_INET;  /*af_inet means internet version 4*/
  server_addr.sin_port = port;     /*it poertn no. specified*/
  server_addr.sin_addr.s_addr = INADDR_ANY; /*here ip refers to local address*/

  n = bind(server_sock, (struct sockaddr* )&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
  listen(server_sock, 5);
  
  clilen=sizeof(client_addr);
  printf("Listening...\n"); /* for incomming connection*/
  
  newsockfd = accept(server_sock, (struct sockaddr *) &client_addr, &clilen);
  if (newsockfd<0)
  perror("error on accept");
                                   //Lets start the coding//
 
 
 //first take the databit from the user
 int data[10];
 printf("enter the 4 data bit\n");                    // 0   1   2   3   4   5   6   
 scanf("%d",&data[0]);                               // d7  d6  d5  p4  d3  p2  p1
 scanf("%d",&data[1]);
 scanf("%d",&data[2]);
 scanf("%d",&data[4]);
 
 //now first calculate the even parity
 data[6]= data[4]^data[2]^data[0];
 data[5]= data[4]^data[1]^data[0];
 data[3]= data[0]^data[2]^data[1];
 
 //lets send it to client
 for(int i=0;i<7; i++)
 {
 	n=write(newsockfd, &data[i], sizeof(int));
 	
 	if(n<0)
 	printf("error while transmitting");
 }
 
 printf(" successfully sent the following data:");
  for (int i=0;i<7;i++)
  	{printf("%d", data[i]);}
  	
  
 
    
    
    
    
                                    //Code till this line only//
 

  

  return 0;
}
