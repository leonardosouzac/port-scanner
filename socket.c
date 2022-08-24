#include <stdio.h>
#include <sys/types.h>    // AF_INET, SOCK_STREAM
#include <sys/socket.h>   // socket(), connect()
#include <netinet/in.h>   // struct sockaddr_in
#include <arpa/inet.h>    // htons(), inet_addr()
#include <unistd.h>       // close()
//#include <netdb.h>

main()
{
	int meusocket;
	int conecta;

	struct sockaddr_in alvo;

	meusocket = socket(AF_INET, SOCK_STREAM, 0);
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(8080);
	alvo.sin_addr.s_addr = inet_addr("192.168.0.1");

	conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

	if(conecta == 0)
	{
		printf("Porta aberta\n");
		close(meusocket);
		close(conecta);
	}
	else
	{
		printf("Porta fechada\n");
	}
}