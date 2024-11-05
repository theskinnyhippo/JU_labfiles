#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main() {
    short int n = 0, m = 0;
    int len = 100;
    unsigned int addrlen;
    unsigned short serv_port = 25000;
    short sockfd, connfd;
    char serv_ip[] = "127.0.0.1";
    char mesg[100], stext[100];

    struct sockaddr_in servaddr, clientaddr;
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_aton(serv_ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(serv_port);

    if (bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    listen(sockfd, 1);
    connfd = accept(sockfd, (struct sockaddr *) &clientaddr, &addrlen);

    while (1) {
        n = read(connfd, mesg, len);
        if (n != -1) {
            mesg[n] = '\0';  // Null terminate the received string
            printf("\n\t\t\t**receive success**\n");
            printf("Client: %s \n", mesg);

            printf("Enter a message: ");
            if (fgets(stext, sizeof(stext), stdin) != NULL) {
                stext[strcspn(stext, "\n")] = '\0';  // Remove the newline character from fgets
                m = write(connfd, stext, strlen(stext));
                if (m != -1)
                    printf("\n\t\t\t**send success**\n");
                else
                    perror("\n\t\t\t**send failure**");
            }
        } else {
            perror("\n\t\t\t**receive failure**");
        }
    }
    close(sockfd);
    return 0;
}

