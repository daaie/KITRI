#include "stdio.h"

#include "winsock2.h"
#pragma comment(lib, "ws2_32.lib")
 
#define DESIRED_WINSOCK_VERSION        0x0202
#define MINIMUM_WINSOCK_VERSION        0x0001
 
#define MAXBUF 256

int main()
{
    SOCKET m_client_socket;
    WSADATA wsadata;
    struct sockaddr_in server_addr;
    char buffer[MAXBUF] = {0, };
 
    // ������ �ʱ�ȭ
    if(!WSAStartup(DESIRED_WINSOCK_VERSION, &wsadata)){
       if(wsadata.wVersion < MINIMUM_WINSOCK_VERSION){
          WSACleanup();
          exit(1);
       }
    }
 
    // ������ ����
    m_client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(m_client_socket == INVALID_SOCKET){
       printf("socket error : ");
       WSACleanup();
       exit(1);
    }
 
    // ������ ������ �ּ� ����
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.18.30");
    server_addr.sin_port = htons(2100);
 
    // ������ �ּҷ� ����
    if(connect(m_client_socket, (LPSOCKADDR)&server_addr, sizeof(server_addr)) != 0){
       printf("connect error : ");
       exit(1);
    }

    // ������ ó��
    recv(m_client_socket, buffer, MAXBUF, 0);
 
    // ������ ����
    closesocket(m_client_socket);
 
    // �޾ƿ� ���ڿ��� ȭ�鿡 ���
    printf("\nrecv : %s\n\n", buffer);
    return 0;
}