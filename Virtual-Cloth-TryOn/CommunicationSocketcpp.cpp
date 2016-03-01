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
	// �����׽��� 
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" Failed socket() \n");
	}

	// Ҳ�������������bind������һ�����ص�ַ 
	// ����ϵͳ�����Զ����� 

	// ��дԶ�̵�ַ��Ϣ 
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// ע�⣬����Ҫ��д����������TCPServer�������ڻ�����IP��ַ 
	// �����ļ����û����������ֱ��ʹ127.0.0.1������Ϊ211.66.11.31������ 
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.191.2");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" Failed connect() \n");
	}

	char buff[256];
	char szText[256];

	while (TRUE)
	{
		//�ӷ������˽������� 
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("���յ����ݣ�%s\n", buff);

			int ang = 0;
			//���ø��ַ��������ӽǿ���
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

		// ��������˷������� 
		//gets_s(szText);
		//szText[255] = '\0';
		//::send(s, szText, strlen(szText), 0);//�����Ƶķ�ʽ��������

	}

	// �ر��׽��� 
	::closesocket(s);
}