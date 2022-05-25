#pragma once
#include <vector>
#include <list>
#include <map>
using namespace std;
enum
{
	DIRUP=1,
	DIRDOWN=2,
	DIRLEFT=3,
	DIRRIGHT=4
};
typedef struct SnakeBoyRect
{
	int lx;//���Ͻ�
	int ly;//���Ͻ�
	int rx;//���½�
	int ry;//���½�
}SnakeRect;
typedef struct GUNINFOMATION
{
	POINT GunPos;
	BOOL  bIsHide;
	int GunSpeed;
	GUNINFOMATION()
	{
		GunPos.x=GunPos.y=-1;
		bIsHide=FALSE;
		GunSpeed=-1;
	}
}GunInfo;
//���˾���100  ���˽ṹ��
typedef struct ARMYINFOMATION
{
	POINT pos;
	int nSpeedX;
	int nSpeedY;
	BOOL bHideSign;
	ARMYINFOMATION()
	{
		pos.x=pos.y=-1;
		nSpeedY=nSpeedX=-1;
		bHideSign=TRUE;
	}
}ArmyInfo;
typedef struct MANSPEEDSTRUCT
{
	int MaxX;
	int MaxY;
	int MinX;
	int MinY;
}SpeedStruct;
typedef struct FISHINFOSTRUCT
{
	POINT pos;
	int nSpeedX;
	int nSpeedY;
	int nLife;//��0 �������ֵ =0 ����
}FISHINFO;
typedef struct STRUCTINIKEYINFO 
{
	CString strKey;
	CString strValue;
	CString strComment;
}INIKEYINFO;