#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/uio.h>
#include<unistd.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<string.h>
#include<stdio.h>
#include <chrono>
#include "studentscode.h"
using namespace std::chrono;
using namespace std;

#define PORT 5555
#define AUTH_P 11
#define AUTH_Q 13
#define AUTH_N 143
#define AUTH_S 38
#define AUTH_R 70

int authentification(int socket){
  int s;
	char buf[1024];
  s = write(socket,buf, sizeof(buf)-1);
  if(s < 0){
    cout<<"error sending\n";
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[]) {

  int fd;
  struct sockaddr_in server;
  struct hostent *hp;
  int cnct;
  char buf[1000]={' '};

  server.sin_family=AF_INET;
  server.sin_port=htons(PORT);
  server.sin_addr.s_addr=INADDR_ANY;

  fd=socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    cout<<"Error creating socket\n";
    return 0;
  }
  if(argc<2){
      cout<<"ERROR"<< endl;
      cout<<"Use : ./client *nameofserver* as arg 1"<< endl;
      return 0;
  }

  cout<<"Socket created\n";

  hp = gethostbyname(argv[1]);
  bcopy((char *)hp->h_addr,(char *)&server.sin_addr.s_addr,hp->h_length);

  cnct = connect(fd,(struct sockaddr*)&server,sizeof(server));

  if(cnct<0){
    cout<<"Error connecting\n";
    return 0;
  }

  cout<<"Connection has been made\n";
  int rec;

  //Authentification null de connaissance client
  //printf("Authentification to the server\n");
  //authentification(fd);

  int to;
  to = creat("OverusedJokeRecu.mp4",0777);
  if(to<0){
    cout<<"Error creating destination file\n";
    return 0;
  }
  int w;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
  while((rec=recv(fd,buf,sizeof(buf),0))){
    if(rec<0){
      cout<<"Error receiving\n";
      return 0;
    }
    w=write(to,buf,rec);
  }
  high_resolution_clock::time_point t3 = high_resolution_clock::now();

  decrypt(to);

  high_resolution_clock::time_point t4 = high_resolution_clock::now();
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  long long duration = duration_cast<milliseconds>( t2 - t1 ).count();
  long long duration2 = duration_cast<milliseconds>( t4 - t3 ).count();
  cout << "Temps de decryption : " << duration2 << " ms" << endl;
  cout << "Temps total decryption et transmission : " << duration << " ms" << endl;

  close(fd);
  shutdown(fd,0);
  cout<<"Socket closed\n";

  return 0;
}