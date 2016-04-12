 #include <stdlib.h>
 #include <strings.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <netinet/in.h>
 #include <netdb.h> 
 #include <unistd.h>
 #include <signal.h>
#define BUFFERMAX 1024



void cerrar_socket(int);
void error(char *);
void timeSleep(unsigned int);
int bandera=1;
int bandera2=1;
int socket_fd;

 
 int main(int argc, char *argv[])
 {
    int fd;
    char * myfifo = "fifo";
    mkfifo(myfifo, 0666);
    char buf[BUFFERMAX];
     int numeroPuerto, n;
 
     struct sockaddr_in serv_addr;
     struct hostent *servido;
 
     char buffer[256];
     if (argc < 3)
     {
        fprintf(stderr,"uso %s direccionip puerto\n", argv[0]);
        exit(0);
     }

     numeroPuerto = atoi(argv[2]);
     socket_fd = socket(AF_INET, SOCK_STREAM, 0);
     if (socket_fd < 0) 
         error("ERROR AL ABRIR SOCKET");
     servido = gethostbyname(argv[1]);

     if (servido == NULL) 
     {
         fprintf(stderr,"ERROR, NO HAY HOST\n");
         exit(0);
     }

     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     bcopy((char *)servido->h_addr, (char *)&serv_addr.sin_addr.s_addr, servido->h_length);
     serv_addr.sin_port = htons(numeroPuerto);
     if (connect(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
         error("ERROR CONECTANDO");


    char* arg_list[] = 
    {
    	"display",
    	"0.jpg",
    	NULL
    };

     int init = 0;
     
     pid_t pid_hijo;
     pid_hijo = fork ();
     int a = (int) getpid ();
    if (pid_hijo == 0)
    { 
     	int b = (int) getpid ();
     	execvp("display", arg_list); 
    }
    else
    {
         int c = (int) getpid ();
         pid_hijo = fork ();
        if(pid_hijo==0)
        {
         	int d = (int) getpid ();
            	int i =0;
                do
                { 
                    bzero(buffer,256);
                    n = read(socket_fd,buffer,255);
                    fd = open(myfifo, O_WRONLY);
                    
                    switch(buffer[0])
                    {
                        case '0':
                        	if(i>1)
                        	{
                            	write(fd, "0", sizeof("0"));
                        	}
                        	else
                        	{
                        		i++;
                        	}
                        break;
                        case '1':
                        	if(i>1)
                        	{
                            	write(fd, "1", sizeof("1"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '2':
                        	if(i>1)
                        	{
                            	write(fd, "2", sizeof("2"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '3':
                        	if(i>1)
                        	{
                            	write(fd, "3", sizeof("3"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '4':
                        	if(i>1)
                        	{
                            	write(fd, "4", sizeof("4"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '5':
                        	if(i>1)
                        	{
                            	write(fd, "5", sizeof("5"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '6':
                        	if(i>1)
                        	{
                            	write(fd, "6", sizeof("6"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '7':
                        	if(i>1){
                            	write(fd, "7", sizeof("7"));
                            }else{i++;}
                        break;
                        case '8':
                        	if(i>1){
                            	write(fd, "8", sizeof("8"));
                            }else{i++;}
                        break;
                        case '9':
                        	if(i>1){
                            write(fd, "9", sizeof("9"));
                            }else{i++;}
                        break;
                    }
                    close(fd);
                    if (signal(SIGINT, cerrar_socket) == SIG_ERR)
                    {
	  					printf("\nNO SE ENCONTRÓ LA SEÑAL\n");
                    }
                }while (bandera==1);   
        }
        else{
           	int e = (int) getpid ();
           	int j=0;
           	do
           	{ 
                fd = open(myfifo, O_RDONLY);
                read(fd, buf, BUFFERMAX);
                char a = buf[0];
                switch(a)
                {
                    case '0':
                      	if(j>1)
                       	{
                           	system("display -remote 0.jpg");
      	                }
                        else
                        {
                          	j++;
                        }
                            break;
                    case '1':
                       	if(j>1)
                       	{
                           	system("display -remote 1.jpg");
                        }
                        else
                        {
                           	j++;
                        }
                            break;
                        case '2':
                        	if(j>1)
                        	{
	                            system("display -remote 2.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '3':
                        	if(j>1)
                        	{
                            	system("display -remote 3.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '4':
                        	if(j>1)
                        	{
                            	system("display -remote 4.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '5':
                        	if(j>1)
                        	{
                            	system("display -remote 5.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '6':
                        	if(j>1)
                        	{
                            	system("display -remote 6.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '7':
                        	if(j>1)
                        	{
                            	system("display -remote 7.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '8':
                        	if(j>1)
                        	{
	                            system("display -remote 8.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '9':
                        	if(j>1)
                        	{
                            	system("display -remote 9.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                    }
                    close(fd);
                    if (signal(SIGINT, cerrar_socket) == SIG_ERR)
                    {
	  					printf("\nLa señal no puede ser cachada\n");
                    }
                }while (bandera2==1);
            }
        }
 }

void cerrar_socket(int signo)
{
  if (signo == SIGINT)
  {
    printf("Recibio un comando SIGINT\n");
    close(socket_fd);
    exit(1);
    bandera++;bandera2++;
  }
}

void error(char *msg)
{
     perror(msg);
     exit(0);
}