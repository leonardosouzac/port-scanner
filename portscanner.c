#include <arpa/inet.h>  // htons(), inet_addr()
#include <netinet/in.h> // struct sockaddr_in
#include <stdio.h>
#include <sys/socket.h> // socket(), connect()
#include <sys/types.h>  // AF_INET, SOCK_STREAM
#include <unistd.h>     // close()
//#include <netdb.h>

int main(int argc, char *argv[]) {
  int meusocket;
  int conecta;
  int port;
  int i = 0;
  int final = 65535;

  for (i = 0; i < 65535; i++) {

    struct sockaddr_in alvo;

    meusocket = socket(AF_INET, SOCK_STREAM, 0);
    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(i);
    alvo.sin_addr.s_addr = inet_addr("192.168.0.1");

    conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

    if (conecta == 0) {
      printf("Porta %d aberta\n", i);
      close(meusocket);
      close(conecta);
    } else {
      printf("Porta %d fechada\n", i);
    }
  }
}