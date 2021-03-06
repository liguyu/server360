/**
 * Joshua Elliott
 * server.h
 * CS360 - Lab 4 - Web Server
 * 
 */

#ifndef SERVER_H
#define SERVER_H

// C includes
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <unistd.h>

// C++ includes
#include <iostream>
#include <string>

// local includes
#include "handler.h"
#include "util/config/Config.h"
#include "util/logger.h"

#define MAX_EVENTS 1000
#define MAX_WAIT   1000
#define NANOSEC    1000000000.0

using namespace std;


class Server {
public:
  Server(int port, Config & config, Logger & log);
  ~Server();

  // Start the web server
  void start();

private:
  // Setup server
  void setup();

  struct sockaddr_in server,client;
  socklen_t clientlen;
  int option, port, s, c;
  int opt;
  Config & config;
  int idleTimeout;

  // map the file descriptors to their handlers
  map<int, Handler*> handlers;
  
  Logger & log;

};

#endif

