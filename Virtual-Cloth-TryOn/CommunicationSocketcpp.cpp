#include "stdafx.h"
#include "CommunicationSocket.h"

CommunicationSocket::CommunicationSocket()
{
	m_f3DViewAngle = 0;
	m_p3DView = NULL;
}

CommunicationSocket::~CommunicationSocket()
{
	delete m_p3DView;
}

void CommunicationSocket::CommunicationClientServer()
{
	// 创建套节字 
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" Failed socket() \n");
	}

	// 也可以在这里调用bind函数绑定一个本地地址 
	// 否则系统将会自动安排 

	// 填写远程地址信息 
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// 注意，这里要填写服务器程序（TCPServer程序）所在机器的IP地址 
	// 如果你的计算机没有联网，用直接使127.0.0.1（本机为211.66.11.31）即可 
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.191.2");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" Failed connect() \n");
	}

	char buff[256];
	char szText[256];

	while (TRUE)
	{
		//从服务器端接收数据 
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("接收到数据：%s\n", buff);

			int ang = 0;
			//利用该字符串进行视角控制
			for (int i = 0; buff[i] != '\0'; i++)
			{
				int radix = 1;
				for (int j = 0; j < nRecv - 1 - i; j++)
				{
					radix = radix * 10;
				}
				ang = ang + (buff[i] - '0')*radix;
			}
		}

		// 向服务器端发送数据 
		//gets_s(szText);
		//szText[255] = '\0';
		//::send(s, szText, strlen(szText), 0);//二进制的方式发送数据

	}

	// 关闭套节字 
	::closesocket(s);
}