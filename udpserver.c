/* 
 * udpserver.c - A simple UDP echo server 
 * usage: udpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h> /* required for the definition of bool in C99 */
#include "aes.h"
#include "aes.c"
#include <math.h>
#include "rc4.h"
#include "rc4.c"
#include "chacha20.h"
#include "chacha20.c"
#include <memory.h>
#include <time.h>

#define BUFSIZE 2041 //1024

/*
 * error - wrapper for perror
 */
  int numofT=5000000000000000;

void udpservererror(char *msg) {
  perror(msg);
  exit(1);
}
// a simple hex-print routine. could be modified to print 16 bytes-per-line
static void hex_print(uint8_t* pv,uint16_t s,uint16_t len)
{
 uint8_t * p = pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        unsigned int i ;
        for (i=s; i<len;++i)
        printf("%02x ", p[i]);

    }
printf("\n\n");
}


int udpserver(int argc, char **argv) {



  int sockfd; /* socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
   char buf[BUFSIZE]; /* message buf */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */



  /* 
   * check command line arguments 
   */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* 
   * socket: create the parent socket 
   */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) 
    udpservererror("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
         (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(sockfd, (struct sockaddr *) &serveraddr, 
       sizeof(serveraddr)) < 0) 
    udpservererror("ERROR on binding");

  /* 
   * main loop: wait for a datagram, then echo it
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /*
     * recvfrom: receive a UDP datagram from a client
     */
    bzero(buf, BUFSIZE);
    n = recvfrom(sockfd, buf, BUFSIZE, 0,
         (struct sockaddr *) &clientaddr, &clientlen);
    if (n < 0)
      udpservererror("ERROR in recvfrom");


    uint8_t i;
    uint8_t j;

 
uint8_t * a=(uint8_t *)buf;

printf("\n--------------------------------------------------------\n");
printf("Header: \n");
hex_print(a, 0,10);
printf("Data received: \n");
hex_print((uint8_t *)buf, 10,n-2);
  printf("\n\n");

unsigned char copy[n-12];
 BYTE out[n-12]; 
for ( j = 0; j < n-12; j++){
for (i = 10; i < n-2; i++){
  out[j] = buf[i];
  copy[j] = buf[i];
      j++;

 }}
printf("copy: \n");
hex_print((uint8_t *)copy, 0,n-12);
  printf("\n\n");
printf("out:\n");
 hex_print((uint8_t *)out, 0,n-12);

//printf("\n================this is for AES CTR---------------------------------------------\n");
//WORD key_schedule[60];
	//BYTE encrypt[128];
	//BYTE decrypt[128];
//BYTE iv[1][16] = {
//{0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,
//0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff},
	//};
	//BYTE key[1][32] = {
//{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
//0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
//0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
//0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
	//};
 //aes_key_setup(key[0], key_schedule, 256);
 //aes_decrypt_ctr(out, n-12, decrypt, key_schedule, 256, iv[0]);
//printf("Decrypted data :\n");
//hex_print((uint8_t *)decrypt, 0,n-12);

//printf("\n================this is for AES CBC---------------------------------------------\n");

//WORD key_schedule[60];
	//BYTE encrypt[128];
	//BYTE decrypt[128];
//BYTE iv[1][16] = {
//{0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,
//0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff},
	//};
	//BYTE key[1][32] = {
//{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
//0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
//0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
//0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
	//};
 //aes_key_setup(key[0], key_schedule, 256);
 //aes_decrypt_cbc(out, n-12, decrypt, key_schedule, 256, iv[0]);
//printf("Decrypted data :\n");
//hex_print((uint8_t *)decrypt, 0,n-12);








//printf("\n================this is for chacha20---------------------------------------------\n");
 //uint8_t key[] = {
     //   0x00, 0x01, 0x02, 0x03,
      // 0x04, 0x05, 0x06, 0x07,
      // 0x08, 0x09, 0x0a, 0x0b,
     //  0x0c, 0x0d, 0x0e, 0x0f,
      //  0x10, 0x11, 0x12, 0x13,
      //  0x14, 0x15, 0x16, 0x17,
      //  0x18, 0x19, 0x1a, 0x1b,
      //  0x1c, 0x1d, 0x1e, 0x1f
   // };
//uint8_t nonce[] = {
      // 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00
  // };
 //uint8_t decrypt[n-12];
//ChaCha20XOR(key, 1, nonce, (uint8_t *)out, (uint8_t *)decrypt, n-12);

 
// printf("Decrypted data:\n");
 //hex_print((uint8_t *)decrypt, 0,n-12);


//printf("\n================this is for RC4------------------------------------------------\n");

  
//unsigned char user_key[] = {
       // 0x00, 0x01, 0x02, 0x03,
       //0x04, 0x05, 0x06, 0x07,
      // 0x08, 0x09, 0x0a, 0x0b,
      // 0x0c, 0x0d, 0x0e, 0x0f,
      //  0x10, 0x11, 0x12, 0x13,
      //  0x14, 0x15, 0x16, 0x17,
       //0x18, 0x19, 0x1a, 0x1b,
       //0x1c, 0x1d, 0x1e, 0x1f
   // };
//unsigned char decrypt[n-12];

      // unsigned char decrypt_key[RC4_TABLE_LENGTH];
      // rc4_generate_key(decrypt_key, user_key, 32);

//printf("decrypt_key size :%d\n", sizeof decrypt_key);

      // rc4_decrypt(decrypt_key, copy, decrypt, n-12);
//printf("decrypt_key :\n");
//hex_print((uint8_t *)decrypt_key, 0,256);
//printf("decrypted data:\n");
//hex_print((uint8_t *)decrypt, 0,n-12);
   

    /* 
     * gethostbyaddr: determine who sent the datagram
     */
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
              sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      udpservererror("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      udpservererror("ERROR on inet_ntoa\n");
   // printf("server received datagram from %s (%s)\n",hostp->h_name, hostaddrp);
    //printf("server received %d/%d bytes: %s\n", strlen(buf), n, buf);
    
    /* 
     * sendto: echo the input back to the client 
     */
    n = sendto(sockfd, buf, n, 0, 
           (struct sockaddr *) &clientaddr, clientlen);
    if (n < 0) 
      udpservererror("ERROR in sendto");
  }
}


int main(int argc, char **argv) {
  int status;
  status = udpserver(argc, argv);
  
  return status;
}
