#ifndef _VIRTUAL_CLOTH_TRYON_COMMUNICATION_SOCKET_H_
#define _VIRTUAL_CLOTH_TRYON_COMMUNICATION_SOCKET_H_
#include "InitSock.h" 
#include <stdio.h> 
#include <iostream>


class View3D;

class CommunicationSocket
{
public:
	CInitSock initSock;     // 初始化Winsock库
	View3D*		m_p3DView;

	//用于测试是否能够控制该项目场景中相机的旋转角度
	float m_f3DViewAngle;



public:
	CommunicationSocket();
	~CommunicationSocket();
	void CommunicationClientServer();
};
#endif