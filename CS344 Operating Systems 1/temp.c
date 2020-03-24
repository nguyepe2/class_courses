#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>


void error(const char *msg) { perror(msg); exit(1); } // Error function used for reporting issues

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
	char letter;
	char decrypt[150000];
	char trash[150000];
	int total=0;



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

	// Accept a connection, blocking if one is not available until one connects
	sizeOfClientInfo = sizeof(clientAddress); // Get the size of the address for the client that will connect
	establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); // Accept
	if (establishedConnectionFD < 0) error("ERROR on accept");

	// Get the message from the client and display it
	memset(buffer, '\0', sizeof(buffer));
	while(strstr(buffer, "@@")==NULL) {
	charsRead = recv(establishedConnectionFD, buffer, sizeof(buffer)-1, 0); // Read the client's message from the socket
	//token=strtok(buffer, strip);
	//printf("%s\n", token);
	//strcat(message, token); //store message inside of message array

	//token=strtok(buffer, end);
	//printf("%s\n", token);
	//strcat(key, token); //store key inside of key array

	//strcat(buffer, "@@"); //append @@ so that the while loop can end

	//printf("SERVER: I received this from the client: \"%s\"\n", buffer);
}

if (charsRead < 0) error("ERROR reading from socket");
//int x;
//for(x=0; x<strlen(buffer); x++) {
	token=strtok(buffer, strip);
	strcat(message, token); //store message inside of message array

	token=strtok(NULL, end);
	strcat(key, token); //store key inside of key array

//}

printf("%s\n", message);

	int i;
	if(message[0]=='e') {
		printf("talking to enc\n");
		for(i=0; i<strlen(message); i++) {
			message[i]=message[i+1]; //shifts values inside array one to the left, erasing validation char
		}
	}
	else {
		printf("not talking to the right process\n");
	}

	printf("message with e: %s\n", message);
	printf("key: %s\n", key);
//check for bad chars inside of message
//int i;
for(i=0; i<strlen(message); i++) {
	int j=0;
	while(message[i]!=characters[j]) {
		j++;
	}
	if(j>strlen(characters)) {
		printf("bad char detected! exiting...\n");
		exit(1);
	}
}
//check values inside of key array
/*int x;
for(x=0; x<strlen(key); x++) {
	printf("%c", key[x]);
}
printf("\n");
*/
printf("start of ciphertext: \n");
if(strlen(key) >= strlen(message)) {
	int i, val;
	for(i=0; i<strlen(message); i++) {
		 int j=0, k=0;
		while(message[i]!=characters[j]) {
			j++; //j represents numerical value of message's characters
		}
		while(key[i]!=characters[k]) {
			k++; //k represents numerical value of key's characters
		}
		val=((j + k) % 27); //store numerical value of encrypted char in val
		ciphertext[i]=characters[val];
		//letter=((message[i]+key[i])-65) % 27;
		//ciphertext[i]=characters[letter];
		printf("%c", ciphertext[i]);
		//printf("message val: %d\n", j);
		//printf("key val: %d\n", k);

	}
	printf("\n");

//start of testing decrypt
	for(i=0; i<strlen(message); i++) {

		int j=0, k=0;
	 while(ciphertext[i]!=characters[j]) {
		 j++; //j represents numerical value of message's characters
	 }
	 while(key[i]!=characters[k]) {
		 k++; //k represents numerical value of key's characters
	 }
	 val=((j+27 - k+27) % 27); //store numerical value of encrypted char in val
	 decrypt[i]=characters[val];

	 printf("%c", decrypt[i]);

	}
	printf("\n");



}
else {
	printf("Error: key is too short\n");
}

//do{

	// Send a Success message back to the client
	charsRead = send(establishedConnectionFD, ciphertext, strlen(ciphertext), 0); // Send success back
	//charsRead = send(establishedConnectionFD, "this is the part i'm testing", 39, 0); // Send success back
	//if (charsRead < 0) error("ERROR writing to socket");
	//printf("amount of chars written: %d\n", total);

	total=total+charsRead;

//}while(total<strlen(key));
	close(establishedConnectionFD); // Close the existing socket which is connected to the client
	close(listenSocketFD); // Close the listening socket
	return 0;
}
