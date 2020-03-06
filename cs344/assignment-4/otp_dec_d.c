#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>


void error(const char *msg) { perror(msg); exit(1); } // Error function used for reporting issues

int pidArray[100];
int x=0;

int main(int argc, char *argv[])
{
	int listenSocketFD, establishedConnectionFD, portNumber, charsRead;
	socklen_t sizeOfClientInfo;
	char buffer[150000];
	struct sockaddr_in serverAddress, clientAddress;
	char strip[2]="?";
	char end[2]="!";
	char validate[2]="e";
	char* token;
	char message[150000];
	char key[150000];
	char ciphertext[150000];
	//char characters[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
	char characters[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char letter;
	char decrypt[150000];
	char trash[150000];
	int total=0;
	char found;
	pid_t child;


	if (argc < 2) { fprintf(stderr,"USAGE: %s port\n", argv[0]); exit(1); } // Check usage & args

	// Set up the address struct for this process (the server)
	memset((char *)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[1]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverAddress.sin_addr.s_addr = INADDR_ANY; // Any address is allowed for connection to this process

	// Set up the socket
	listenSocketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (listenSocketFD < 0) error("ERROR opening socket");

	// Enable the socket to begin listening
	if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to port
		error("ERROR on binding");
	listen(listenSocketFD, 5); // Flip the socket on - it can now receive up to 5 connections

	int run;
	for(run=0; run < 100; run++) {

	// Accept a connection, blocking if one is not available until one connects
	sizeOfClientInfo = sizeof(clientAddress); // Get the size of the address for the client that will connect
	establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); // Accept
	if (establishedConnectionFD < 0) error("ERROR on accept");

	charsRead = recv(establishedConnectionFD, buffer, 1, 0); // Read the client's message from the socket

	if(buffer[0]!='d') {
		charsRead = send(establishedConnectionFD, "wrong port", 11, 0); // Send error message back to client

		_exit(2);
	}


	// Get the message from the client and display it
	memset(buffer, '\0', sizeof(buffer));
	while(strstr(buffer, "@@")==NULL) {
	charsRead = recv(establishedConnectionFD, buffer, sizeof(buffer)-1, 0); // Read the client's message from the socket

	if (charsRead < 0) error("ERROR reading from socket");

	//printf("SERVER: I received this from the client: \"%s\"\n", buffer);
}


int x, a=0, y=0;
memset(key, '\0', sizeof(key));
for(x=0; x<strlen(buffer); x++) {
	if(buffer[x]=='?') {
		a=1;
		continue;

}
if(a==0) {
	message[x]=buffer[x];
}

else if(buffer[x]=='@')
	continue;

else {
	key[y]=buffer[x];
	y++;
}


}

	child=fork();

	if(child==0) {

	int i;

		int val=0, val2=0, n;
		int j, k;


		for(j=0; j<strlen(message); j++) {
			for(k=0; k < 27; k++) {
				if(message[j]==characters[k]) {

					val=k;
				}
				if(key[j]==characters[k]) {

					val2=k;
				}


			}


			n=((val+27-val2+27) % 27);

			//printf("%d\n", n);
			ciphertext[j]=characters[n];


		}




memset(buffer, '\0', sizeof(buffer));


strcat(ciphertext, "@@");
//printf("ciphertext: %s\n", ciphertext);


do{

	// Send a Success message back to the client
	charsRead = send(establishedConnectionFD, ciphertext, strlen(ciphertext), 0); // Send success back
	//charsRead = send(establishedConnectionFD, "this is the part i'm testing", 39, 0); // Send success back
	//if (charsRead < 0) error("ERROR writing to socket");
	//printf("amount of chars written: %d\n", total);

	total=total+charsRead;

}while(total<strlen(key));
close(establishedConnectionFD); // Close the existing socket which is connected to the client

}//if child == 0

	else if(child < 0){
		fprintf(stderr, "fork went wrong\n");

		_exit(1);
	}
}

	close(listenSocketFD); // Close the listening socket
	return 0;
}
