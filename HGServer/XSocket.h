// XSocket.h: interface for the XSocket class.
//
//////////////////////////////////////////////////////////////////////

// ����� Ȯ���ڵ�� 1����Ʈ, ũ��� WORD�� ����Ǿ���. �� ����� �� 3����Ʈ 


#if !defined(AFX_XSOCKET_H__F9D1BA42_7338_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_XSOCKET_H__F9D1BA42_7338_11D2_A8E6_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define _WINSOCK2API_
//#define  FD_SETSIZE 2000
#include <windows.h>
#include <windowsx.h>
#include <winsock2.h>
//#include <winsock.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include "DebugDialog.h"
#include <iostream>
#include <strstream>
#include <string>

#define DEF_XSOCK_LISTENSOCK			1
#define DEF_XSOCK_NORMALSOCK			2				
#define DEF_XSOCK_SHUTDOWNEDSOCK		3				

#define DEF_XSOCKSTATUS_READINGHEADER	11
#define DEF_XSOCKSTATUS_READINGBODY		12

#define DEF_XSOCKEVENT_SOCKETMISMATCH			-121	// ���� �̺�Ʈ�� ������ ���� �ٸ���. (�̷� ��찡?)
#define DEF_XSOCKEVENT_CONNECTIONESTABLISH		-122	// ������ �̷�� ����.
#define DEF_XSOCKEVENT_RETRYINGCONNECTION		-123	// ������ �ٽ� �õ��ϴ� ���̴�.
#define DEF_XSOCKEVENT_ONREAD					-124	// �޽����� �д� ���̴�. 
#define DEF_XSOCKEVENT_READCOMPLETE				-125	// �ϳ��� �޽����� ������ �����ߴ�.
#define DEF_XSOCKEVENT_UNKNOWN					-126	// �˼����� �̺�Ʈ�̴�.
#define DEF_XSOCKEVENT_SOCKETCLOSED				-127	// ������ ������. 
#define DEF_XSOCKEVENT_BLOCK					-128	// �޽����� �����ٰ� ������ ������ �����̴�.
#define DEF_XSOCKEVENT_SOCKETERROR				-129	// ���Ͽ� ������ �߻��ߴ�. �̰�� Ŭ������ �����Ͽ��� �Ѵ�.
#define DEF_XSOCKEVENT_CRITICALERROR			-130    // ġ������ ������ ���α׷� ��ü�� ����� �Ѵ�.
#define DEF_XSOCKEVENT_NOTINITIALIZED			-131	// Ŭ������ �ʱ�ȭ ���� ���� ���·� ���ƴ�.
#define DEF_XSOCKEVENT_MSGSIZETOOLARGE			-132	// �������� �ϴ� �޽����� ����� �ʹ� ũ��.
#define DEF_XSOCKEVENT_CONFIRMCODENOTMATCH		-133	// Ȯ���ڵ尡 ��ġ���� �ʴ´�. �����Ǿ�� �Ѵ�.
#define DEF_XSOCKEVENT_QUENEFULL                -134    // ���� ť�� ������ ����.
#define DEF_XSOCKEVENT_UNSENTDATASENDBLOCK		-135    // ť�� �ִ� �����͸� �����ٰ� �� ������ �ɷȴ�. 
#define DEF_XSOCKEVENT_UNSENTDATASENDCOMPLETE	-136	// ť�� �ִ� ��� �����͸� ���´�.

#define DEF_XSOCKBLOCKLIMIT						300		// �� Ŭ���� ������ ?���̻� ���ϵǸ� ���̻� �����͸� ������ �� ����. 	

class XSocket  
{
public:
	int iGetPeerAddress(char * pAddrString);
	char * pGetRcvDataPointer(DWORD * pMsgSize, char * pKey = NULL);
	SOCKET iGetSocket();
	BOOL bAccept(class XSocket * pXSock, unsigned int uiMsg);
	BOOL bListen(char * pAddr, int iPort, unsigned int uiMsg);
	int iSendMsg(char * cData, DWORD dwSize, char cKey = NULL);
	BOOL bConnect(char * pAddr, int iPort, unsigned int uiMsg);
	int  iOnSocketEvent(WPARAM wParam, LPARAM lParam);
	BOOL bInitBufferSize(DWORD dwBufferSize);
	XSocket(HWND hWnd, int iBlockLimit);
	virtual ~XSocket();

	int  m_WSAErr;
	BOOL m_bIsAvailable;

	bool m_bIsWriteEnabled;

private:
	void _CloseConn();
	
	int _iSendUnsentData();
	int _iRegisterUnsentData(char * cData, int iSize);
	int _iSend(char * cData, int iSize, BOOL bSaveFlag);
	int _iSend_ForInternalUse(char * cData, int iSize);
	int _iOnRead();
	
	char   m_cType;
	char * m_pRcvBuffer;
	char * m_pSndBuffer;
	DWORD  m_dwBufferSize;
	
	SOCKET m_Sock;
	char   m_cStatus;
	DWORD  m_dwReadSize;
	DWORD  m_dwTotalReadSize;
	char   m_pAddr[30];
	int    m_iPortNum;

	char * m_pUnsentDataList[DEF_XSOCKBLOCKLIMIT];
	int    m_iUnsentDataSize[DEF_XSOCKBLOCKLIMIT];
	short  m_sHead, m_sTail;

	unsigned int m_uiMsg;
	HWND         m_hWnd;

	int			 m_iBlockLimit;
};


BOOL _InitWinsock();
void _TermWinsock();

#endif // !defined(AFX_XSOCKET_H__F9D1BA42_7338_11D2_A8E6_00001C7030A6__INCLUDED_)
