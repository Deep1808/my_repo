#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void INThandler(int);

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("\nOUCH, did you hit Ctrl-C?\n"
            "Do you really want to quit? [y/n] ");
     c = getchar();
     if (c == 'y' || c == 'Y')
          exit(0);
     else	
     signal(SIGINT, INThandler);
     getchar(); // Get new line character
     //goto n1;
}

void func(int sockfd)
{
	char buff[MAX];
	int n;
	for (;;) {
		bzero(buff, sizeof(buff));
		printf("Deep: ");
		if (signal(SIGINT, INThandler))
		{
			printf("Client Exit...\n");
			goto n1;
			break;
		}
	
		n = 0;
		n1:	while ((buff[n++] = getchar()) != '\n')
			;
		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff));
		printf("\tRahul : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0){
			printf("Client Exit...\n");
			break;
		}
		
	}
}

int main()
{

	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("10.126.64.54");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
	func(sockfd);

	// close the socket
	//close(sockfd);
	if(close(sockfd)==0)
	{
	printf("server is closed");
	}
}

