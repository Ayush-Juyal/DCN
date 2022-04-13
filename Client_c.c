#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(int argc,char * * argv)
{
       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;

       int i,j,keylen,msglen,k;
       char input[100],key[30],temp[30],quot[100],key1[30],
       afterror[100], sermessage[200];
     
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
     
       printf("Enter Message Data : ");
        gets(input);
        strcpy(afterror,input);
        printf("Enter Divisor : ");
        gets(key);
        keylen=strlen(key);
        msglen=strlen(input);
        char key2[keylen];
        strcpy(key2,key);
        char rem[keylen-1];
   
        strcpy(key1,key);
        for (i=0;i<keylen-1;i++) {
            input[msglen+i]='0';
        }
        for (i=0;i<keylen;i++)
         temp[i]=input[i];
        for (i=0;i<msglen;i++) {
            quot[i]=temp[0];
            if(quot[i]=='0')
            for (j=0;j<keylen;j++)
            key[j]='0'; else
            for (j=0;j<keylen;j++)
            key[j]=key1[j];
            for (j=keylen-1;j>0;j--)
            {
                if(temp[j]==key[j])
                 rem[j-1]='0'; else
                 rem[j-1]='1';
            }
            rem[keylen-1]=input[i+keylen];
            strcpy(temp,rem);
        }
       strcpy(rem,temp);
       printf("\nQuotient is : ");
       for (i=0;i<msglen;i++)
       printf("%c",quot[i]);
       printf("\nRemainder or Crc is : ");
       for (i=0;i<keylen-1;i++)
       printf("%c",rem[i]);
       rem[i]='\0';
      
      
       printf("\nDo You want introduce an Error In original Message(Press 0) : ");
       scanf("%d",&k);
       if(k==0)
       {
        printf("Enter position where do you want introduce an error : ");
        scanf("%d",&k);
        if(afterror[k-1]=='0')
        afterror[k-1]='1';
        else
        afterror[k-1]='0';
       }
       printf("\nAfter Introducing Error Original Data Will Be : ");
       printf("%s",afterror);
        
      write(sockfd,afterror,100);
      write(sockfd,rem,30);
      write(sockfd,key2,30);
    
     
      printf("\n");
      printf("\nServer Respond : \n");
      read(sockfd,sermessage,200);
      printf("%s\n\n",sermessage);
       close(sockfd);
       return 0;
}
