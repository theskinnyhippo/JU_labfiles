#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main() {
    int sockfd, returnvalue, len = 100, n;
    unsigned int addrlen;
    unsigned short serv_port = 25000;
    char serv_ip[] = "127.0.0.1";
    char text[100];
    char rtext[100];

    struct sockaddr_in servaddr;
    addrlen = sizeof(servaddr);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serv_port);
    inet_aton(serv_ip, &servaddr.sin_addr);

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    while (1) {
        printf("Enter a message: ");
        if (fgets(text, sizeof(text), stdin) != NULL) {
            text[strcspn(text, "\n")] = '\0';  // Remove the newline character from fgets

            n = write(sockfd, text, strlen(text));
            if (returnvalue != -1) {
                printf("\n\t\t\t**message sent successfully**\n");
            } else {
                perror("\n\t\t\t**message sent failure**");
            }

            n = read(sockfd, rtext, len);
            if (n != -1) {
                rtext[n] = '\0';
                printf("Server: %s \n", rtext);
            } else {
                perror("Receive failure");
            }
        }
    }
    close(sockfd);
    return 0;
}


