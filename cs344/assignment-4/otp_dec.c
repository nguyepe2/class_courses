#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <ctype.h>

void error(const char *msg) { perror(msg); exit(0); } // Error function used for reporting issues

int main(int argc, char *argv[])
{
	int socketFD, portNumber, charsWritten, charsRead;
	struct sockaddr_in serverAddress;
	struct hostent* serverHostInfo;
	char buffer[150000];
	char *host[2];
	host[0]="localhost";
	char package[150000];
	memset(package, '\0', sizeof(package));
	int checksend = -5;
	FILE *thing;
	char lines[150000];
	char *status;
	char strip[2]="\n";
	char* token;
	char characters[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
	int i;
	char encrypt[150000];
	char end[2]="!";
	char printing[150000];


/* move values of plaintext, key, and string "@@" into package array */

strcat(package, "d");

//put plaintext contents into package array
	thing=fopen(argv[1], "r");
	if(thing!=NULL) {
		do {
			fgets(lines, sizeof(lines), thing);
			token=strtok(lines, strip);
			while(token!=NULL) {
			strcat(package, token);
			token=strtok(NULL, strip);
		}
	}while(status!=NULL);
	fclose(thing);

//checks to make sure that plaintext contains valid chars
	for(i=0; i<strlen(package); i++) {
		if(isalpha(package[i]) || package[i]==characters[26]) {

		}
		else {
			printf("is not valid char\n");
			fflush(stdout);
			exit(1);
		}
	}


	strcat(package, "?"); // '?' signifies where plaintext ends
}

//put key contents into package array
thing=fopen(argv[2], "r");
if(thing!=NULL) {
	do {
		fgets(lines, sizeof(lines), thing);
		token=strtok(lines, strip);
		while(token!=NULL) {
		strcat(package, token);
		token=strtok(NULL, strip);
	}
}while(status!=NULL);
fclose(thing);


}

	strcat(package, "@@");

	int total=0;

	if (argc < 4) { fprintf(stderr,"USAGE: %s plaintext key port\n", argv[0]); exit(0); } // Check usage & args

	// Set up the server address struct
	memset((char*)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[3]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverHostInfo = gethostbyname(host[0]); // Convert the machine name into a special form of address
	if (serverHostInfo == NULL) { fprintf(stderr, "CLIENT: ERROR, no such host\n"); exit(0); }
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length); // Copy in the address

	// Set up the socket
	socketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (socketFD < 0) error("CLIENT: ERROR opening socket");

	// Connect to server
	if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to address
		error("CLIENT: ERROR connecting");

	// Get input message from user
	/*printf("CLIENT: Enter text to send to the server, and then hit enter: ");
	memset(buffer, '\0', sizeof(buffer)); // Clear out the buffer array
	fgets(buffer, sizeof(buffer) - 1, stdin); // Get input from the user, trunc to buffer - 1 chars, leaving \0
	buffer[strcspn(buffer, "\n")] = '\0'; // Remove the trailing \n that fgets adds
 */
	// Send message to server

do{
	int checkSend = -5;  // Bytes remaining in send buffer

	do{
	  ioctl(socketFD, TIOCOUTQ, &checksend);  // Check the send buffer for this socket
	  //printf("checkSend: %d\n", checkSend);  // Out of curiosity, check how many remaining bytes there are:
	}while (checksend > 0);

	if (checksend < 0)  // Check if we actually stopped the loop because of an error
  error("ioctl error");

	charsWritten = send(socketFD, package, strlen(package), 0); // Write to the server
	if (charsWritten < 0) error("CLIENT: ERROR writing to socket");

	//if (charsWritten < strlen(package)) printf("CLIENT: WARNING: Not all data written to socket!\n");
	total=total+charsWritten;

}while(total < strlen(package));

	// Get return message from server
	while(strstr(buffer, "@@")==NULL) {
	memset(buffer, '\0', sizeof(buffer)); // Clear out the buffer again for reuse
	charsRead = recv(socketFD, buffer, sizeof(buffer)-1, 0); // Read data from the socket, leaving \0 at end

	if(strcmp(buffer, "error")==0) {
		printf("otp_dec cannot use otp_enc_d\n");
		fflush(stdout);
		exit(2);
	}

	if (charsRead < 0) error("CLIENT: ERROR reading from socket");
}

	token=strtok(buffer, "@@");

	strcat(printing, token);

	printf("%s\n", printing);
	fflush(stdout);
	memset(buffer, '\0', sizeof(buffer)); // Clear out the buffer again for reuse
	memset(printing, '\0', sizeof(printing)); // Clear out the buffer again for reuse

	close(socketFD); // Close the socket
	return 0;
}
