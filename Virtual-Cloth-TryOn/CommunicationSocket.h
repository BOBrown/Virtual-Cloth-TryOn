#ifndef _VIRTUAL_CLOTH_TRYON_COMMUNICATION_SOCKET_H_
#define _VIRTUAL_CLOTH_TRYON_COMMUNICATION_SOCKET_H_
#include "InitSock.h" 
#include <stdio.h> 
#include <iostream>


class View3D;

class CommunicationSocket
{
public:
	CInitSock initSock;     // ��ʼ��Winsock��
	View3D*		m_p3DView;

	//���ڲ����Ƿ��ܹ����Ƹ���Ŀ�������������ת�Ƕ�
	float m_f3DViewAngle;



public:
	CommunicationSocket();
	~CommunicationSocket();
	void CommunicationClientServer();
};
#endif