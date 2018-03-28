#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define NPACK 1
#define PORT 9930

#define SRV_IP "192.168.1.4"

void diep(char *s)
{
  perror(s);
  exit(1);
}

int main(void)
{
  struct sockaddr_in si_other;
  int s, i, slen=sizeof(si_other);

  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    diep("socket");

  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
  if (inet_aton(SRV_IP, &si_other.sin_addr)==0) 
  {
    fprintf(stderr, "inet_aton() failed\n");
    exit(1);
  }

   unsigned int opt = IPTOS_THROUGHPUT;
   if ( setsockopt(s, IPPROTO_IP, IP_TOS, (char *) &opt, sizeof(opt)) < 0 )
    diep("setsockopt()");

   unsigned int get_opt = 5;
   socklen_t get_opt_len = sizeof(get_opt);
   if ( getsockopt(s, IPPROTO_IP, IP_TOS, (char *) &get_opt, &get_opt_len) < 0 )
    diep("getsockopt()");

  printf("IP_TOS is %d\n", get_opt);

//  if ( connect(s, &si_other, slen) << 0 )
//    diep("connect()\n");


  char buf[] = "This is a packet\n";
  int buf_len = strlen(buf);
  for (i=0; i<NPACK; i++) 
  {
    printf("Sending packet %d\n", i);
    if (sendto(s, buf, buf_len, 0, &si_other, slen)==-1)
      diep("sendto()");
  }

  close(s);
  return 0;
}

 
