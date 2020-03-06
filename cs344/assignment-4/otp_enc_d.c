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
	char characters[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
	//char characters[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char letter;
	char decrypt[150000];
	char trash[150000];
	int total=0;
	char found;
	pid_t child;
	int flag;
	int check;

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

	// Get the message from the client and display it
	memset(buffer, '\0', sizeof(buffer));
	while(strstr(buffer, "@@")==NULL) {
	charsRead = recv(establishedConnectionFD, buffer, sizeof(buffer)-1, 0); // Read the client's message from the socket


	strcat(buffer, "@@"); //append @@ so that the while loop can end

	//printf("SERVER: I received this from the client: \"%s\"\n", buffer);
}

if (charsRead < 0) error("ERROR reading from socket");
int i;

if(buffer[0]!='e') { //if not talking to encryption client
	charsRead = send(establishedConnectionFD, "error", 6, 0); // Send success back

}
else {
	for(i=0; i<strlen(buffer); i++) {
		buffer[i]=buffer[i+1]; //shifts values inside array one to the left, erasing validation char
	}


int x, a=0, y=0;
memset(key, '\0', sizeof(key));
for(x=0; x<strlen(buffer); x++) {
	if(buffer[x]=='?') { //if char signifying beginning of key found, set a to 1
		a=1;
		continue;

}
if(a==0) { //before char signifying beginning of key is found, store in message array
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


			n=((val+val2) % 27);
			ciphertext[j]=characters[n];


		}


memset(buffer, '\0', sizeof(buffer));


strcat(ciphertext, "@@");


do{

	// Send a Success message back to the client
	charsRead = send(establishedConnectionFD, ciphertext, strlen(ciphertext), 0); // Send success back
	//if (charsRead < 0) error("ERROR writing to socket");

	total=total+charsRead;

}while(total<strlen(key));
close(establishedConnectionFD); // Close the existing socket which is connected to the client

}//end of checking wrong port
else if(child < 0){
	fprintf(stderr, "fork went wrong\n");

	_exit(1);
}
}
}

	close(listenSocketFD); // Close the listening socket
	return 0;
}
