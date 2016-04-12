/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>


void error(char *);
void Esperar(unsigned int);

int main(int argc, char *argv[])
{
    int i = 0;
     char buffer[256];
     int sockfd, numeropuerto             , clilen;
     int socketfd, socketfd2, socketfd3, socketfd4;
     struct sockaddr_in serv_addr, cli_addr;
     int n,n2,n3,n4;
     if (argc < 2) {
         fprintf(stderr,"ERROR\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) 
error("ERROR AL ABRIR SOCKET");
bzero((char *) &serv_addr, sizeof(serv_addr));
numeropuerto = atoi(argv[1]);
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port = htons(numeropuerto             );
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    error("ERROR");
     
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while(i<4){
 if(i==0){
   socketfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (socketfd < 0){
       error("ERROR EN ACEPTAR");
    }else{i=1;printf("%d\n", i);}
    }
     if(i==1){
     socketfd2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (socketfd2 < 0){
      error("ERROR EN ACEPTAR");
     }else{i++;printf("%d\n", i);}
    }
    if(i==2){
     socketfd3 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (socketfd3 < 0){
      error("ERROR EN ACEPTAR");
    }else{i++;printf("%d\n", i);}
    }
     if(i==3){
            socketfd4 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (socketfd4 < 0){
                error("ERROR EN ACEPTAR");
            }else{i++;printf("%d\n", i);}
        }
     }
     if (i==4){
     do{
        time_t epoch_time;
        struct tm *tm_p;
        epoch_time = time( NULL );
        tm_p = localtime( &epoch_time );
        int hora = tm_p->tm_hour;
        int min  = tm_p->tm_min;
        int seg  = tm_p->tm_sec;
        char dhora[] = {(hora/10)+48};
        char dmin[] = {(min/10)+48};
        char dseg[]  = {(seg/10)+48};
        char uhora[] = {(hora%10)+48};
        char umin[] = {(min%10)+48};
        char useg[]  = {(seg%10)+48};
        
        n = write(socketfd,dmin,1);
        n2 = write(socketfd2,umin,1);
        n3 = write(socketfd3,dseg,1);
        n4 = write(socketfd4,useg,1);
        Esperar             (1);
     }while(1==1);
    }
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}

//Delay
void Esperar              (unsigned int secs) 
{
  int retTime = time(0) + secs;    
  while (time(0) < retTime);   
}