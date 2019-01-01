tcp_net_server: tcp_net_server.o tcp_net_socket.o
	cc -o tcp_net_server tcp_net_server.o tcp_net_socket.o
tcp_net_client: tcp_net_client.o tcp_net_socket.o
	cc -o tcp_net_client tcp_net_client.o tcp_net_socket.o

tcp_net_server.o: tcp_net_server.c tcp_net_socket.h
	cc -c tcp_net_server.c
tcp_net_client.o: tcp_net_client.c tcp_net_socket.h
	cc -c tcp_net_client.c

tcp_net_socket.o: tcp_net_socket.c
	cc -c tcp_net_socket.c

