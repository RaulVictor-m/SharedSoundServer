#pragma once 

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>


typedef int  ss_socket;
typedef int  ss_socket_conn;


ss_socket		ss_socket_init();
void 			ss_socket_stop			(ss_socket server);
void 			ss_socket_conn_close	(ss_socket_conn conn);
int				ss_socket_conn_read		(ss_socket_conn conn, void *data, size_t size);
int				ss_socket_conn_write	(ss_socket_conn conn, void *data, size_t size);
ss_socket_conn 	ss_socket_conn_acpt		(ss_socket server);
