// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif

#include <windows.h>
#include <winbase.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#include <direct.h>
#include <vector>

#include "winmain.h"
#include "StrTok.h"
#include "Xsocket.h"
#include "Client.h"
#include "Npc.h"
#include "Map.h"
#include "ActionID.h"
#include "UserMessages.h"
#include "NetMessages.h"
#include "MessageIndex.h"
#include "Misc.h"
#include "Msg.h"
#include "Magic.h"
#include "Skill.h"
#include "DynamicObject.h"
#include "DelayEvent.h"
#include "Version.h"
#include "Fish.h"
#include "DynamicObject.h"
#include "DynamicObjectID.h"
#include "Portion.h"
#include "Mineral.h"
#include "Quest.h"
#include "BuildItem.h"
#include "TeleportLoc.h"
#include "GlobalDef.h"
#include "TempNpcItem.h"
#include "PartyManager.h"
#include "MobCounter.h"

#define DEF_MAXADMINS				50
#define DEF_MAXMAPS					100
#define DEF_MAXAGRICULTURE			200
#define DEF_MAXNPCTYPES				200
#define DEF_MAXBUILDITEMS			300
#define DEF_SERVERSOCKETBLOCKLIMIT	300
#define DEF_MAXBANNED				500
#define DEF_MAXNPCITEMS				1000
#define DEF_MAXCLIENTS				2000
#define DEF_MAXCLIENTLOGINSOCK		2000
#define DEF_MAXNPCS					5000
#define DEF_MAXITEMTYPES			5000
#define DEF_CLIENTTIMEOUT			10000
#define DEF_SPUPTIME				10000
#define DEF_POISONTIME				12000
#define DEF_HPUPTIME				15000
#define DEF_MPUPTIME				20000
#define DEF_HUNGERTIME				60000
#define DEF_NOTICETIME				80000
#define DEF_SUMMONTIME				300000
#define DEF_AUTOSAVETIME			600000
#define MAX_HELDENIANTOWER			200

#define DEF_EXPSTOCKTIME		1000*10		// ExpStock을 계산하는 시간 간격 
#define DEF_MSGQUENESIZE		100000		// 메시지 큐 사이즈 10만개 
#define DEF_AUTOEXPTIME			1000*60*6	// 자동으로 경험치가 올라가는 시간간격 
#define DEF_TOTALLEVELUPPOINT	3			// 레벨업시 할당하는 총 포인트 수 


#define DEF_MAXDYNAMICOBJECTS	60000
#define DEF_MAXDELAYEVENTS		60000
#define DEF_GUILDSTARTRANK		12

#define DEF_SSN_LIMIT_MULTIPLY_VALUE	2	// SSN-limit 곱하는 수 

#define DEF_MAXNOTIFYMSGS		300			// 최대 공지사항 메시지 
#define DEF_MAXSKILLPOINTS		700			// 스킬 포인트의 총합 
#define DEF_NIGHTTIME			30

#define DEF_CHARPOINTLIMIT		1000		// 각각의 특성치의 최대값 
#define DEF_RAGPROTECTIONTIME	7000		// 몇 초 이상 지나면 랙으로 부터 보호를 받는지 
#define DEF_MAXREWARDGOLD		99999999	// 포상금 최대치 

#define DEF_ATTACKAI_NORMAL				1	// 무조건 공격 
#define DEF_ATTACKAI_EXCHANGEATTACK		2	// 교환 공격 - 후퇴 
#define DEF_ATTACKAI_TWOBYONEATTACK		3	// 2-1 공격, 후퇴 

#define DEF_MAXFISHS					200
#define DEF_MAXMINERALS					200
#define	DEF_MAXCROPS					200
#define DEF_MAXENGAGINGFISH				30  // 한 물고기에 낚시를 시도할 수 있는 최대 인원 
#define DEF_MAXPORTIONTYPES				500 // 최대 포션 정의 갯수 

#define DEF_SPECIALEVENTTIME			300000 //600000 // 10분
#define DEF_MAXQUESTTYPE				200
#define DEF_DEF_MAXHELDENIANDOOR			10

#define DEF_MAXSUBLOGSOCK				10

#define DEF_ITEMLOG_GIVE				1
#define DEF_ITEMLOG_DROP				2
#define DEF_ITEMLOG_GET					3
#define DEF_ITEMLOG_DEPLETE				4
#define DEF_ITEMLOG_NEWGENDROP			5
#define DEF_ITEMLOG_DUPITEMID			6

// New 07/05/2004
#define DEF_ITEMLOG_BUY					7
#define DEF_ITEMLOG_SELL				8
#define DEF_ITEMLOG_RETRIEVE			9
#define DEF_ITEMLOG_DEPOSIT				10
#define DEF_ITEMLOG_EXCHANGE			11
#define DEF_ITEMLOG_MAKE				13
#define DEF_ITEMLOG_SUMMONMONSTER		14
#define DEF_ITEMLOG_POISONED			15
#define DEF_ITEMLOG_REPAIR				17
#define DEF_ITEMLOG_SKILLLEARN			12
#define DEF_ITEMLOG_MAGICLEARN			16
#define DEF_ITEMLOG_USE					32

#define DEF_MAXDUPITEMID				100

#define DEF_MAXGUILDS					1000 // 동시에 접속할 수 있는 길드수 
#define DEF_MAXONESERVERUSERS			800	// 800 // 한 서버에서 허용할 수 있는 최대 사용자수. 초과된 경우 부활존 혹은 블리딩 아일, 농경지로 보내진다.

#define DEF_MAXGATESERVERSTOCKMSGSIZE	10000

#define DEF_MAXCONSTRUCTNUM				10
#define DEF_MAXSCHEDULE					10
#define DEF_MAXAPOCALYPSE				7
#define DEF_MAXHELDENIAN				10

//v1.4311-3  사투장의 최대 숫자
#define DEF_MAXFIGHTZONE 10 

//============================
#define DEF_LEVELLIMIT		20				// 체험판 레벨 제한치!!!			
//============================

//============================
#define DEF_MINIMUMHITRATIO 15				// 최저 명중 확률 
//============================		

//============================
#define DEF_MAXIMUMHITRATIO	99				// 최대 명중 확률
//============================

//============================
#define DEF_PLAYERMAXLEVEL	180				// 최대 레벨: Npc.cfg 파일에 설정되어 있지 않을 경우 m_iPlayerMaxLevel에 입력된다.
//============================

//============================
// New Changed 12/05/2004
#define DEF_GMGMANACONSUMEUNIT	15			// Grand Magic Generator 마나 흡수 단위.
//============================

#define DEF_MAXCONSTRUCTIONPOINT 30000		// 최대 소환 포인트 
#define DEF_MAXSUMMONPOINTS		 30000
#define DEF_MAXWARCONTRIBUTION	 200000


// MOG Definitions - 3.51
// Level up MSG
#define MSGID_LEVELUPSETTINGS				0x11A01000
// 2003-04-14 지존 포인트를 레벨 수정에 쓸수 있다...
// Stat Point Change MSG
#define MSGID_STATECHANGEPOINT				0x11A01001

//#define DEF_NOTIFY_STATECHANGE_FAILED 0x11A01002
//#define DEF_NOTIFY_SETTING_FAILED 0x11A01003
//#define DEF_NOTIFY_STATECHANGE_SUCCESS 0x11A01004
//#define DEF_NOTIFY_SETTING_SUCCESS 0x11A01005

//Mine
//#define DEF_NOTIFY_SETTING_FAILED 0x11A01003
//#define DEF_NOTIFY_SETTING_SUCCESS 0x11A01005
//2.24
//#define DEF_NOTIFY_SETTING_FAILED 0xBB4
//#define DEF_NOTIFY_SETTING_SUCCESS 0xBB3


#define DEF_STR 0x01
#define DEF_DEX 0x02
#define DEF_INT 0x03
#define DEF_VIT 0x04
#define DEF_MAG 0x05
#define DEF_CHR 0x06

#define DEF_TEST 0xFFFF0000
//#define DEF_TESTSERVER

#define NO_MSGSPEEDCHECK


using namespace std;
typedef unsigned long long u64;
typedef signed long long i64;
typedef unsigned long u32;
typedef signed long i32;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned char u8;
typedef signed char i8;


template <typename T>
static bool In(const T& value, std::initializer_list<T> values) {
	return std::any_of(values.begin(), values.end(),
		[&value](const T& x) { return x == value; });
}

template <typename T>
static bool NotIn(const T& value, std::initializer_list<T> values) {
	return !In(value, values);
}


template <typename T, class = typename enable_if<!is_pointer<T>::value>::type >
static void Push(char*& cp, T value) {
	auto p = (T*)cp;
	*p = (T)value;
	cp += sizeof(T);
}

template <typename T, class = typename enable_if<!is_pointer<T>::value>::type >
static void Pop(char*& cp, T& v) {
	T* p = (T*)cp;
	v = *p;
	cp += sizeof(T);
}

static void Push(char*& dest, const char* src, u32 len) {
	memcpy(dest, src, len);
	dest += len;
}

static void Push(char*& dest, const char* src) {

	strcpy(dest, src);
	dest += strlen(src) + 1;
}

static void Push(char*& dest, const string& str) {
	strcpy(dest, str.c_str());
	dest += str.length() + 1;
}

static void Pop(char*& src, char* dest, u32 len) {
	memcpy(dest, src, len);
	src += len;
}
static void Pop(char*& src, char* dest) {

	u32 len = strlen(src) + 1;
	memcpy(dest, src, len);
	src += len;
}

static void Pop(char*& src, string& str) {
	str = src;
	src += str.length() + 1;
}


struct LoginClient
{
	LoginClient(HWND hWnd)
	{
		_sock = NULL;
		_sock = new class XSocket(hWnd, DEF_CLIENTSOCKETBLOCKLIMIT);
		_sock->bInitBufferSize(DEF_MSGBUFFERSIZE);
		_timeout_tm = 0;
	}

	u32 _timeout_tm;
	~LoginClient();
	XSocket* _sock;
	char _ip[21];
};


class CGame  
{
public:

	void RequestMobKills(int client);

	void RequestNoticementHandler(int iClientH);
	BOOL bSendClientConfig(int iClientH, char* cFile);

	LoginClient* _lclients[DEF_MAXCLIENTLOGINSOCK];

	bool bAcceptLogin(XSocket* sock);

	void PartyOperation(char* pData);

	void SetHeldenianMode();
	void AdminOrder_GetFightzoneTicket(int iClientH);
	void AutomatedHeldenianTimer();
	void LocalStartHeldenianMode(short sV1, short sV2, DWORD dwHeldenianGUID);
	void GlobalStartHeldenianMode();
	void HeldenianWarEnder();
	void HeldenianWarStarter();
	BOOL UpdateHeldenianStatus();
	void _CreateHeldenianGUID(DWORD dwHeldenianGUID, int iWinnerSide);
	void ManualStartHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void ManualEndHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void NotifyStartHeldenianMode();

	BOOL _bCheckCharacterData(int iClientH);
	//BOOL _bDecodeNpcItemConfigFileContents(char * pData, DWORD dwMsgSize);
	void GlobalUpdateConfigs(char cConfigType);
	void LocalUpdateConfigs(char cConfigType);
	//void UpdateHeldenianStatus();
	void GlobalEndHeldenianMode();
	void LocalEndHeldenianMode();
	BOOL bNotifyHeldenianWinner();
	void RemoveHeldenianNpc(int iNpcH);
	void RemoveOccupyFlags(int iMapIndex);
	void RequestHeldenianTeleport(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL bCheckHeldenianMap(int sAttackerH, int iMapIndex, char cType);
	void SetHeroFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetInhibitionCastingFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	//void CalculateEnduranceDecrement(short sTargetH, short sAttackerH, char cTargetType, int iArmorType);
	BOOL bCalculateEnduranceDecrement(short sTargetH, short sAttackerH, char cTargetType, int iArmorType);
	char _cCheckHeroItemEquipped(int iClientH);
	BOOL bPlantSeedBag(int iMapIndex, int dX, int dY, int iItemEffectValue1, int iItemEffectValue2, int iClientH);
	void _CheckFarmingAction(short sAttackerH, short sTargetH, BOOL bType);

	
	void ApocalypseEnder();
	
	BOOL bReadScheduleConfigFile(char *pFn);

	BOOL bReadHeldenianGUIDFile(char * cFn);
	BOOL bReadApocalypseGUIDFile(char * cFn);

	void _CreateApocalypseGUID(DWORD dwApocalypseGUID);
	void LocalEndApocalypse();
	void LocalStartApocalypse(DWORD dwApocalypseGUID);
	void GlobalEndApocalypseMode();
	
	
	// Lists
	BOOL bReadBannedListConfigFile(char *pFn);
	BOOL bReadAdminListConfigFile(char *pFn);

	void AdminOrder_CheckStats(int iClientH, char *pData,DWORD dwMsgSize);
	void Command_RedBall(int iClientH, char *pData,DWORD dwMsgSize);
	void Command_BlueBall(int iClientH, char *pData,DWORD dwMsgSize);
	void Command_YellowBall(int iClientH, char* pData, DWORD dwMsgSize);

	// Crusade
	void ManualEndCrusadeMode(int iWinnerSide); // 2.17 (x) 2.14 ( )
	void CrusadeWarStarter();
	BOOL bReadCrusadeGUIDFile(char * cFn);
	void _CreateCrusadeGUID(DWORD dwCrusadeGUID, int iWinnerSide);
	void GlobalStartCrusadeMode();
	void GSM_SetGuildTeleportLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void SyncMiddlelandMapInfo();
	void RemoveCrusadeStructures();
	void _SendMapStatus(int iClientH);
	void MapStatusHandler(int iClientH, int iMode, char * pMapName);
	void SelectCrusadeDutyHandler(int iClientH, int iDuty);
	void RequestSummonWarUnitHandler(int iClientH, int dX, int dY, char cType, char cNum, char cMode);
	void RequestGuildTeleportHandler(int iClientH);
	void RequestSetGuildTeleportLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void MeteorStrikeHandler(int iMapIndex);
	void _LinkStrikePointMapIndex();
	void MeteorStrikeMsgHandler(char cAttackerSide);
	void _NpcBehavior_GrandMagicGenerator(int iNpcH);
	void CollectedManaHandler(WORD wAresdenMana, WORD wElvineMana);
	void SendCollectedMana();
	void CreateCrusadeStructures();
	void _GrandMagicLaunchMsgSend(int iType, char cAttackerSide);
	void GrandMagicResultHandler(char *cMapName, int iCrashedStructureNum, int iStructureDamageAmount, int iCasualities, int iActiveStructure, int iTotalStrikePoints, char * cData);
	void CalcMeteorStrikeEffectHandler(int iMapIndex);
	void DoMeteorStrikeDamageHandler(int iMapIndex);
	void RequestSetGuildConstructLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void GSM_SetGuildConstructLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void GSM_ConstructionPoint(int iGuildGUID, int iPoint);
	void CheckCommanderConstructionPoint(int iClientH);
	BOOL bReadCrusadeStructureConfigFile(char * cFn);
	void SaveOccupyFlagData();
	void LocalEndCrusadeMode(int iWinnerSide);
	void LocalStartCrusadeMode(DWORD dwGuildGUID);
	void CheckCrusadeResultCalculation(int iClientH);
	void CheckHeldenianResultCalculation(int iClientH);
	BOOL _bNpcBehavior_Detector(int iNpcH);
	BOOL _bNpcBehavior_ManaCollector(int iNpcH);
	BOOL __bSetConstructionKit(int iMapIndex, int dX, int dY, int iType, int iTimeCost, int iClientH);

	void AdminOrder_SummonGuild(int iClientH, char * pData, DWORD dwMsgSize);

	// Acidx commands
	void AdminOrder_Time(int iClientH, char * pData, DWORD dwMsgSize);
	
	void AdminOrder_Pushplayer(int iClientH, char * pData, DWORD dwMsgSize);

	void AdminOrder_CheckRep(int iClientH, char *pData,DWORD dwMsgSize);

	void SetForceRecallTime(int iClientH);
	void ApplyCombatKilledPenalty(int iClientH, int cPenaltyLevel, BOOL bIsSAattacked);

	void AdminOrder_ClearNpc(int iClientH);

	// Settings.cfg
	BOOL bReadSettingsConfigFile(char * cFn);

	//  BOOL bReadTeleportConfigFile(char * cFn);
	//	void RequestTeleportD2Handler(int iClientH, char * pData);
	
	// Daryl - AdminSettings.cfg
	BOOL bReadAdminSetConfigFile(char * cFn);


	// Hack Checks
	BOOL bCheckClientMoveFrequency(int iClientH, DWORD dwClientTime);
	BOOL bCheckClientMagicFrequency(int iClientH, DWORD dwClientTime);
	BOOL bCheckClientAttackFrequency(int iClientH, DWORD dwClientTime);

	// BOOL bCheckClientInvisibility(short iClientH);

	//Hypnotoad functions
	void SetDefenseShieldFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetMagicProtectionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetProtectionFromArrowFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetIllusionMovementFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetIllusionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);

	void RequestChangePlayMode(int iClientH);
	void GetHeroMantleHandler(int iClientH,int iItemID,char * pString);
	void AdminOrder_Weather(int iClientH, char * pData, DWORD dwMsgSize);
	
	void SendMsg(short sOwnerH, char cOwnerType, BOOL bStatus, long lPass);
	BOOL bCheckMagicInt(int iClientH);
	BOOL bChangeState(char cStateChange, char* cStr, char *cVit,char *cDex,char *cInt,char *cMag,char *cChar);
	void StateChangeHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetStatus(int iClientH, char *pData, DWORD dwMsgSize);
	
	void SetPoisonFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void GayDave(char cDave[350], char cInput[350]);
	void AdminOrder_SummonStorm(int iClientH, char* pData, DWORD dwMsgSize);
	
	void AdminOrder_SummonDeath(int iClientH);
	void AdminOrder_SetZerk(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetFreeze(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Kill(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Revive(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetObserverMode(int iClientH);
	void AdminOrder_EnableAdminCommand(int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_CreateItem(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Summon(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonAll(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonPlayer(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_UnsummonDemon(int iClientH);
	void AdminOrder_UnsummonAll(int iClientH);
	void AdminOrder_SetAttackMode(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonDemon(int iClientH);
	void AdminOrder_SetInvi(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Polymorph(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_GetNpcStatus(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CheckIP(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CreateFish(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Teleport(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_ReserveFightzone(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CloseConn(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CallGuard(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_DisconnectAll(int iClientH, char * pData, DWORD dwMsgSize);

	BOOL bCopyItemContents(class CItem * pOriginal, class CItem * pCopy);
	int  iGetMapLocationSide(char * pMapName);
	void ChatMsgHandlerGSM(int iMsgType, int iV1, char * pName, char * pData, DWORD dwMsgSize);
	void RemoveClientShortCut(int iClientH);
	BOOL bAddClientShortCut(int iClientH);

	void GSM_RequestFindCharacter(WORD wReqServerID, WORD wReqClientH, char *pName, char * pFinder); // New 16/05/2001 Changed
	void ServerStockMsgHandler(char * pData);
	void SendStockMsgToGateServer();
	BOOL bStockMsgToGateServer(char * pData, DWORD dwSize);
	void RequestHelpHandler(int iClientH);
	
	void CheckConnectionHandler(int iClientH, char *pData);

	void AgingMapSectorInfo();
	void UpdateMapSectorInfo();
	BOOL bGetItemNameWhenDeleteNpc(int & iItemID, short sNpcType);
	int iGetItemWeight(class CItem * pItem, int iCount);
	void CancelQuestHandler(int iClientH);
	void ActivateSpecialAbilityHandler(int iClientH);
	void EnergySphereProcessor(BOOL bIsAdminCreate = FALSE, int iClientH = NULL);
	BOOL bCheckEnergySphereDestination(int iNpcH, short sAttackerH, char cAttackerType);
	void JoinPartyHandler(int iClientH, int iV1, char *pMemberName);
	void CreateNewPartyHandler(int iClientH);
	void _DeleteRandomOccupyFlag(int iMapIndex);
	void RequestSellItemListHandler(int iClientH, char * pData);
	void RequestRestartHandler(int iClientH);
	int iRequestPanningMapDataRequest(int iClientH, char * pData);
	void GetMagicAbilityHandler(int iClientH);
	void Effect_Damage_Spot_DamageMove(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sAtkX, short sAtkY, short sV1, short sV2, short sV3, BOOL bExp, int iAttr);
	void _TamingHandler(int iClientH, int iSkillNum, char cMapIndex, int dX, int dY);
	void RequestCheckAccountPasswordHandler(char * pData, DWORD dwMsgSize);
	int _iTalkToNpcResult_Guard(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void SetIceFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void _bDecodeNoticementFileContents(char * pData, DWORD dwMsgSize);
	void RequestNoticementHandler(int iClientH, char * pData);
	void _AdjustRareItemValue(class CItem * pItem);
	BOOL _bCheckDupItemID(class CItem * pItem);
	BOOL _bDecodeDupItemIDFileContents(char * pData, DWORD dwMsgSize);
	void NpcDeadItemGenerator(int iNpcH, short sAttackerH, char cAttackerType);
	int  iGetPlayerABSStatus(int iWhatH, int iRecvH);
	void CheckSpecialEvent(int iClientH);
	char _cGetSpecialAbility(int iKindSA);
	void BuildItemHandler(int iClientH, char * pData);
	BOOL _bDecodeBuildItemConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bCheckSubLogSocketIndex();
	void _CheckGateSockConnection();
	void OnSubLogRead(int iIndex);
	void OnSubLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void _CheckStrategicPointOccupyStatus(char cMapIndex);
	void GetMapInitialPoint(int iMapIndex, short * pX, short * pY, char * pPlayerLocation = NULL);
	int  iGetMaxHP(int iClientH);
	int  iGetMaxMP(int iClientH);
	int  iGetMaxSP(int iClientH);
	void _ClearQuestStatus(int iClientH);
	BOOL _bCheckItemReceiveCondition(int iClientH, class CItem * pItem);
	void SendItemNotifyMsg(int iClientH, WORD wMsgType, class CItem * pItem, int iV1);
	
	int _iTalkToNpcResult_WTower(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_WHouse(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_BSmith(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GShop(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GuildHall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	BOOL _bCheckIsQuestCompleted(int iClientH);
	void _CheckQuestEnvironment(int iClientH);
	void _SendQuestContents(int iClientH);
	void QuestAcceptedHandler(int iClientH);
	BOOL _bDecodeQuestConfigFileContents(char * pData, DWORD dwMsgSize);
	
	void CancelExchangeItem(int iClientH);
	BOOL bAddItem(int iClientH, class CItem * pItem, char cMode);
	void ConfirmExchangeItem(int iClientH);
	void SetExchangeItem(int iClientH, int iItemIndex, int iAmount);
	void ExchangeItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);

	void _BWM_Command_Shutup(char * pData);
	void _BWM_Init(int iClientH, char * pData);
	void CheckUniqueItemEquipment(int iClientH);
	void _SetItemPos(int iClientH, char * pData);
	
	BOOL _bDecodeOccupyFlagSaveFileContents(char * pData, DWORD dwMsgSize);
	void GetOccupyFlagHandler(int iClientH);
	int  _iComposeFlagStatusContents(char * pData);
	void SetSummonMobAction(int iClientH, int iMode, DWORD dwMsgSize, char * pData = NULL);
	BOOL __bSetOccupyFlag(char cMapIndex, int dX, int dY, int iSide, int iEKNum, int iClientH, BOOL bAdminFlag);
	BOOL _bDepleteDestTypeItemUseEffect(int iClientH, int dX, int dY, short sItemIndex, short sDestItemID);
	void SetDownSkillIndexHandler(int iClientH, int iSkillIndex);
	int iGetComboAttackBonus(int iSkill, int iComboCount);
	int  _iGetWeaponSkillType(int iClientH);
	void CheckFireBluring(char cMapIndex, int sX, int sY);
	void NpcTalkHandler(int iClientH, int iWho);
	BOOL bDeleteMineral(int iIndex);
	void _CheckMiningAction(int iClientH, int dX, int dY);
	int iCreateMineral(char cMapIndex, int tX, int tY, char cLevel);
	void MineralGenerator();
	void LocalSavePlayerData(int iClientH);
	BOOL _bDecodePortionConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReqCreatePortionHandler(int iClientH, char * pData);
	void ReqCreateCraftingHandler(int iClientH, char* pData);
	void _CheckAttackType(int iClientH, short * spType);
	BOOL bOnClose();
	void ForceDisconnectAccount(char * pAccountName, WORD wCount);
	void NpcRequestAssistance(int iNpcH);
	void ToggleSafeAttackModeHandler(int iClientH);
	void SetBerserkFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetHasteFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SpecialEventHandler();
	
	int iGetNpcRelationship_SendEvent(int iNpcH, int iOpponentH);
	int _iForcePlayerDisconect(int iNum);
	int iGetMapIndex(char * pMapName);
	int iGetNpcRelationship(int iWhatH, int iRecvH);
	int iGetPlayerRelationship(int iClientH, int iOpponentH);
	int iGetWhetherMagicBonusEffect(short sType, char cWheatherStatus);
	void WhetherProcessor();
	int _iCalcPlayerNum(char cMapIndex, short dX, short dY, char cRadius);
	void FishGenerator();
	void ReqGetFishThisTimeHandler(int iClientH);
	void FishProcessor();
	int iCheckFish(int iClientH, char cMapIndex, short dX, short dY);
	BOOL bDeleteFish(int iHandle, int iDelMode);
	int  iCreateFish(char cMapIndex, short sX, short sY, short sDifficulty, class CItem * pItem, int iDifficulty, DWORD dwLastTime);
	void UserCommand_DissmissGuild(int iClientH, char * pData, DWORD dwMsgSize);
	void UserCommand_BanGuildsman(int iClientH, char * pData, DWORD dwMsgSize);
	int iGetExpLevel(DWORD iExp);
	void ___RestorePlayerRating(int iClientH);
	void CalcExpStock(int iClientH);
	void ResponseSavePlayerDataReplyHandler(char * pData, DWORD dwMsgSize);
	void NoticeHandler();
	BOOL bReadNotifyMsgListFile(char * cFn);
	void SetPlayerReputation(int iClientH, char * pMsg, char cValue, DWORD dwMsgSize);
	void ShutUpPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckDayOrNightMode();
	BOOL bCheckBadWord(char * pString);
	BOOL bCheckResistingPoisonSuccess(short sOwnerH, char cOwnerType);
	void PoisonEffect(int iClientH, int iV1);
	void bSetNpcAttackMode(char * cName, int iTargetH, char cTargetType, BOOL bIsPermAttack);
	BOOL _bGetIsPlayerHostile(int iClientH, int sOwnerH);
	BOOL bAnalyzeCriminalAction(int iClientH, short dX, short dY, BOOL bIsCheck = FALSE);
	void RequestAdminUserMode(int iClientH, char * pData);
	int _iGetPlayerNumberOnSpot(short dX, short dY, char cMapIndex, char cRange);
	void CalcTotalItemEffect(int iClientH, int iEquipItemID, BOOL bNotify = TRUE);
	void ___RestorePlayerCharacteristics(int iClientH);
	void GetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void SetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void ToggleWhisperPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckAndNotifyPlayerConnection(int iClientH, char * pMsg, DWORD dwSize);
	int iCalcTotalWeight(int iClientH);
	void ReqRepairItemCofirmHandler(int iClientH, char cItemID, char * pString);
	void ReqRepairItemHandler(int iClientH, char cItemID, char cRepairWhom, char * pString);
	void ReqSellItemConfirmHandler(int iClientH, char cItemID, int iNum, char * pString);
	void ReqSellItemHandler(int iClientH, char cItemID, char cSellToWhom, int iNum, char * pItemName);
	void UseSkillHandler(int iClientH, int iV1, int iV2, int iV3);
	int  iCalculateUseSkillItemEffect(int iOwnerH, char cOwnerType, char cOwnerSkill, int iSkillNum, char cMapIndex, int dX, int dY);
	void ClearSkillUsingStatus(int iClientH);
	void DynamicObjectEffectProcessor();
	int _iGetTotalClients();
	void SendObjectMotionRejectMsg(int iClientH);
	void SetInvisibilityFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	BOOL bRemoveFromDelayEventList(int iH, char cType, int iEffectType);
	void DelayEventProcessor();
	BOOL bRegisterDelayEvent(int iDelayType, int iEffectType, DWORD dwLastTime, int iTargetH, char cTargetType, char cMapIndex, int dX, int dY, int iV1, int iV2, int iV3);
	int iGetFollowerNumber(short sOwnerH, char cOwnerType);
	int  _iCalcSkillSSNpoint(int iLevel);
	void OnKeyUp(WPARAM wParam, LPARAM lParam);
	void OnKeyDown(WPARAM wParam, LPARAM lParam);
	BOOL bCheckTotalSkillMasteryPoints(int iClientH, int iSkill);
	BOOL bSetItemToBankItem(int iClientH, class CItem * pItem);
	void NpcMagicHandler(int iNpcH, short dX, short dY, short sType);
	BOOL bCheckResistingIceSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio);
	BOOL bCheckResistingMagicSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio);
	void Effect_SpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_SpDown_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_HpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_Damage_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3, BOOL bExp, int iAttr = NULL);
	void Effect_Damage_Spot_Type2(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sAtkX, short sAtkY, short sV1, short sV2, short sV3, BOOL bExp, int iAttr);
	void UseItemHandler(int iClientH, short sItemIndex, short dX, short dY, short sDestItemID);
	void NpcBehavior_Stop(int iNpcH);
	void ItemDepleteHandler(int iClientH, short sItemIndex, BOOL bIsUseItemResult);
	int _iGetArrowItemIndex(int iClientH);
	void RequestFullObjectData(int iClientH, char * pData);
	void DeleteNpc(int iNpcH);
	void CalcNextWayPointDestination(int iNpcH);
	void MobGenerator();
	void CalculateSSN_SkillIndex(int iClientH, short sSkillIndex, int iValue);
	void CalculateSSN_ItemIndex(int iClientH, short sWeaponIndex, int iValue);
	void CheckDynamicObjectList();
	int  iAddDynamicObjectList(short sOwner, char cOwnerType, short sType, char cMapIndex, short sX, short sY, DWORD dwLastTime, int iV1 = NULL);
	int _iCalcMaxLoad(int iClientH);
	void GetRewardMoneyHandler(int iClientH);
	void _PenaltyItemDrop(int iClientH, int iTotal, BOOL bIsSAattacked = FALSE);
	//void ApplyCombatKilledPenalty(int iClientH, char cPenaltyLevel, BOOL bIsSAattacked = FALSE);
	void EnemyKillRewardHandler(int iAttackerH, int iClientH);
	void PK_KillRewardHandler(short sAttackerH, short sVictumH);
	void ApplyPKpenalty(short sAttackerH, short sVictumH);
	BOOL bSetItemToBankItem(int iClientH, short sItemIndex);
	void RequestRetrieveItemHandler(int iClientH, char * pData);
	void RequestCivilRightHandler(int iClientH, char * pData);
	BOOL bCheckLimitedUser(int iClientH);
	void LevelUpSettingsHandler(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 선언 함수  사투장 예약 함수 선언 FightzoneReserveHandler
	void FightzoneReserveHandler(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL bCheckLevelUp(int iClientH);
	DWORD iGetLevelExp(int iLevel);
	void TimeManaPointsUp(int iClientH);
	void TimeStaminarPointsUp(int iClientH);
	void Quit();
	BOOL __bReadMapInfo(int iMapIndex);
	BOOL bBankItemToPlayer(int iClientH, short sItemIndex);
	BOOL bPlayerItemToBank(int iClientH, short sItemIndex);
	int  _iGetSkillNumber(char * pSkillName);
	void TrainSkillResponse(BOOL bSuccess, int iClientH, int iSkillNum, int iSkillLevel);
	int _iGetMagicNumber(char * pMagicName, int * pReqInt, int * pCost);
	void RequestStudyMagicHandler(int iClientH, char * pName, BOOL bIsPurchase = TRUE);
	BOOL _bDecodeSkillConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bDecodeMagicConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseFollowMode(short sOwnerH, char cOwnerType);
	BOOL bSetNpcFollowMode(char * pName, char * pFollowName, char cFollowOwnerType);
	void RequestTeleportHandler(int iClientH, char * pData, char * cMapName = NULL, int dX = -1, int dY = -1);
	void PlayerMagicHandler(int iClientH, int dX, int dY, short sType, BOOL bItemEffect = FALSE, int iV1 = NULL);
	int  iClientMotion_Magic_Handler(int iClientH, short sX, short sY, char cDir);
	void SendMsgToGateServer(DWORD dwMsg, int iClientH, char * pData = NULL);
	void OnGateRead();
	void OnGateSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void ToggleCombatModeHandler(int iClientH);
	void GuildNotifyHandler(char * pData, DWORD dwMsgSize);
	void SendGuildMsg(int iClientH, WORD wNotifyMsgType, short sV1, short sV2, char * pString);
	void DelayEventProcess();
	void TimeHitPointsUp(int iClientH);
	void CalculateGuildEffect(int iVictimH, char cVictimType, short sAttackerH);
	void OnStartGameSignal();
	DWORD iDice(DWORD iThrow, DWORD iRange);
	BOOL _bInitNpcAttr(class CNpc * pNpc, char * pNpcName, short sClass, char cSA);
	BOOL _bDecodeNpcConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseItemHandler(int iClientH, short sItemIndex, BOOL bNotice);
	void ClientKilledHandler(int iClientH, int iAttackerH, char cAttackerType, short sDamage);
	int  SetItemCount(int iClientH, char * pItemName, DWORD dwCount);
	int  SetItemCount(int iClientH, int iItemIndex, DWORD dwCount);
	DWORD dwGetItemCount(int iClientH, char * pName);
	void DismissGuildRejectHandler(int iClientH, char * pName);
	void DismissGuildApproveHandler(int iClientH, char * pName);
	void JoinGuildRejectHandler(int iClientH, char * pName);			    
	void JoinGuildApproveHandler(int iClientH, char * pName);
	void SendNotifyMsg(int iFromH, int iToH, WORD wMsgType, DWORD sV1, DWORD sV2, DWORD sV3, char * pString, DWORD sV4 = NULL, DWORD sV5 = NULL, DWORD sV6 = NULL, DWORD sV7 = NULL, DWORD sV8 = NULL, DWORD sV9 = NULL, char * pString2 = NULL);
	void GiveItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);
	void RequestPurchaseItemHandler(int iClientH, char * pItemName, int iNum);
	void ResponseDisbandGuildHandler(char * pData, int iType);
	void RequestDisbandGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestCreateNewGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void ResponseCreateNewGuildHandler(char * pData, int iType);
	int  iClientMotion_Stop_Handler(int iClientH, short sX, short sY, char cDir);

	void RequestCreateNewGuild(int iClientH, char* pData);
	void RequestDisbandGuild(int iClientH, char* pData);
	
	BOOL bEquipItemHandler(int iClientH, short sItemIndex, BOOL bNotify = TRUE);
	BOOL _bAddClientItemList(int iClientH, class CItem * pItem, int * pDelReq);
	int  iClientMotion_GetItem_Handler(int iClientH, short sX, short sY, char cDir);
	void DropItemHandler(int iClientH, short sItemIndex, int iAmount, char * pItemName, BOOL bByPlayer = TRUE);
	void ClientCommonHandler(int iClientH, char * pData);
	BOOL __fastcall bGetMsgQuene(char * pFrom, char * pData, DWORD * pMsgSize, int * pIndex, char * pKey);
	void MsgProcess();
	BOOL __fastcall bPutMsgQuene(char cFrom, char * pData, DWORD dwMsgSize, int iIndex, char cKey);
	void NpcBehavior_Flee(int iNpcH);
	int iGetDangerValue(int iNpcH, short dX, short dY);
	void NpcBehavior_Dead(int iNpcH);
	void NpcKilledHandler(short sAttackerH, char cAttackerType, int iNpcH, short sDamage);
	//int  iCalculateAttackEffect(short sTargetH, char cTargetType, short sAttackerH, char cAttackerType, int tdX, int tdY, int iAttackMode, BOOL bNearAttack = FALSE);
	DWORD iCalculateAttackEffect(short sTargetH, char cTargetType, short sAttackerH, char cAttackerType, int tdX, int tdY, int iAttackMode, BOOL bNearAttack = FALSE, BOOL bIsDash = FALSE, BOOL bArrowUse = FALSE);
	void RemoveFromTarget(short sTargetH, char cTargetType, int iCode = NULL);
	void NpcBehavior_Attack(int iNpcH);
	void TargetSearch(int iNpcH, short * pTarget, char * pTargetType);
	void NpcBehavior_Move(int iNpcH);
	BOOL bGetEmptyPosition(short * pX, short * pY, char cMapIndex);
	char cGetNextMoveDir(short sX, short sY, short dstX, short dstY, char cMapIndex, char cTurn, int * pError);
	int  iClientMotion_Attack_Handler(int iClientH, short sX, short sY, short dX, short dY, short wType, char cDir, WORD wTargetObjectID, BOOL bResponse = TRUE, BOOL bIsDash = FALSE);
	void ChatMsgHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void NpcProcess();
	int bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sClass, char cSA, char cMoveType, int * poX, int * poY, char * pWaypointList, RECT * pArea, int iSpotMobIndex, char cChangeSide, BOOL bHideGenMode, BOOL bIsSummoned = FALSE, BOOL bFirmBerserk = FALSE, BOOL bIsMaster = FALSE, int iGuildGUID = NULL);
	//BOOL bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sX, short sY);
	BOOL _bReadMapInfoFiles(int iMapIndex);
	
	BOOL _bGetIsStringIsNumber(char * pStr);
	BOOL _bInitItemAttr(class CItem * pItem, char * pItemName);
	BOOL bReadProgramConfigFile(char * cFn, bool ismaps);
	void GameProcess();
	void InitPlayerData(int iClientH, char * pData, DWORD dwSize);
	void ResponsePlayerDataHandler(char * pData, DWORD dwSize);
	BOOL bSendMsgToLS(DWORD dwMsg, int iClientH, BOOL bFlag = TRUE, char *pData = NULL);
	void OnMainLogRead();
	void OnMainLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void CheckClientResponseTime();
	void OnTimer(char cType);
	int iComposeMoveMapData(short sX, short sY, int iClientH, char cDir, char * pData);
	void SendEventToNearClient_TypeB(DWORD dwMsgID, WORD wMsgType, char cMapIndex, short sX, short sY, short sV1, short sV2, short sV3, short sV4 = NULL);
	void SendEventToNearClient_TypeB(DWORD dwMsgID, WORD wMsgType, char cMapIndex, short sX, short sY, short sV1, short sV2, short sV3, DWORD dwV4 = NULL);
	void SendEventToNearClient_TypeA(short sOwnerH, char cOwnerType, DWORD dwMsgID, WORD wMsgType, short sV1, short sV2, short sV3);
	void DeleteClient(int iClientH, BOOL bSave, BOOL bNotify, BOOL bCountLogout = TRUE, BOOL bForceCloseConn = FALSE);
	int  iComposeInitMapData(short sX, short sY, int iClientH, char * pData);
	void RequestInitDataHandler(int iClientH, char * pData, char cKey);
	void RequestInitPlayerHandler(int iClientH, char * pData, char cKey);
	int iClientMotion_Move_Handler(int iClientH, short sX, short sY, char cDir, char cMoveType);
	void ClientMotionHandler(int iClientH, char * pData);
	void DisplayInfo(HDC hdc);
	void OnClientRead(int iClientH);
	BOOL bInit();
	void OnClientSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL bAccept(class XSocket * pXSock);
	void GetFightzoneTicketHandler(int iClientH);
	void FightzoneReserveProcessor() ;

	// New 06/05/2004
	// Upgrades
	BOOL bCheckIsItemUpgradeSuccess(int iClientH, int iItemIndex, int iSomH, BOOL bBonus = FALSE);
	void RequestItemUpgradeHandler(int iClientH, int iItemIndex);

	
	
	//Party Codes
	void RequestCreatePartyHandler(int iClientH);
	void PartyOperationResultHandler(char *pData);
	void PartyOperationResult_Create(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Join(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Dismiss(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Delete(int iPartyID);
	void RequestJoinPartyHandler(int iClientH, char *pData, DWORD dwMsgSize);
	void RequestDismissPartyHandler(int iClientH);
	void GetPartyInfoHandler(int iClientH);
	void PartyOperationResult_Info(int iClientH, char * pName, int iTotal, char *pNameList);
	void RequestDeletePartyHandler(int iClientH);
	void RequestAcceptJoinPartyHandler(int iClientH, int iResult);
	void GetExp(int iClientH, DWORD iExp, BOOL bIsAttackerOwn = FALSE);

	// New 07/05/2004
	// Guild Codes
	void RequestGuildNameHandler(int iClientH, int iObjectID, int iIndex);

	// Item Logs
	BOOL _bItemLog(int iAction,int iClientH , char * cName, class CItem * pItem);
	BOOL _bItemLog(int iAction,int iGiveH, int iRecvH, class CItem * pItem,BOOL bForceItemLog = FALSE);
	BOOL _bCheckGoodItem( class CItem * pItem );

	BOOL bCheckAndConvertPlusWeaponItem(int iClientH, int iItemIndex);
	void ArmorLifeDecrement(int iAttackerH, int iTargetH, char cOwnerType, int iValue);

	// MultiDrops
	BOOL bGetMultipleItemNamesWhenDeleteNpc(short sNpcType, int iProbability, int iMin, int iMax, short sBaseX, short sBaseY,
											   int iItemSpreadType, int iSpreadRange,
											   int *iItemIDs, POINT *BasePos, int *iNumItem);

	// Player shutup
	void GSM_RequestShutupPlayer(char * pGMName,WORD wReqServerID, WORD wReqClientH, WORD wTime,char * pPlayer );

	// PK Logs
	BOOL _bPKLog(int iAction,int iAttackerH , int iVictumH, char * pNPC);

	//HBest code
	void AddGizon(int iClientH);
	void CheckTimeOut(int iClientH);
	void SetTimeOut(int iClientH);
	void ForceRecallProcess();
	void SkillCheck(int sTargetH);
	BOOL IsEnemyZone(int i);

	CGame(HWND hWnd);
	virtual ~CGame();

	char m_cServerName[11];
	char m_cGameServerAddr[16];
	char m_cGameServerAddrInternal[16];
	char m_cGameServerAddrExternal[16];
	int  m_iGameServerMode;
	char m_cLogServerAddr[16];
	char m_cGateServerAddr[16];
	int  m_iGameServerPort;
	int  m_iLogServerPort;
	int  m_iGateServerPort;

	DWORD  m_iLimitedUserExp, m_iLevelExp20;

//private:
	BOOL _bDecodeItemConfigFileContents(char * pData, DWORD dwMsgSize);
	int _iComposePlayerDataFileContents(int iClientH, char * pData);
	BOOL _bDecodePlayerDatafileContents(int iClientH, char * pData, DWORD dwSize);
	BOOL _bRegisterMap(char * pName);

	class CClient * m_pClientList[DEF_MAXCLIENTS];
	class CNpc    * m_pNpcList[DEF_MAXNPCS];
	class CMap    * m_pMapList[DEF_MAXMAPS];
	class CNpcItem * m_pTempNpcItem[DEF_MAXNPCITEMS];
	class CDynamicObject * m_pDynamicObjectList[DEF_MAXDYNAMICOBJECTS];
	class CDelayEvent    * m_pDelayEventList[DEF_MAXDELAYEVENTS];

	class CMsg    * m_pMsgQuene[DEF_MSGQUENESIZE];
	int             m_iQueneHead, m_iQueneTail;
	int             m_iTotalMaps;
	//class XSocket * m_pMainLogSock, * m_pGateSock;
	//int				m_iGateSockConnRetryTimes;
	class CMisc     m_Misc;
	BOOL			m_bIsGameStarted;
	//BOOL            m_bIsLogSockAvailable, m_bIsGateSockAvailable;
	BOOL			m_bIsItemAvailable, m_bIsBuildItemAvailable, m_bIsNpcAvailable, m_bIsMagicAvailable;
	BOOL			m_bIsSkillAvailable, m_bIsPortionAvailable, m_bIsQuestAvailable, m_bIsTeleportAvailable;
	class CItem   * m_pItemConfigList[DEF_MAXITEMTYPES];
	class CNpc    * m_pNpcConfigList[DEF_MAXNPCTYPES];
	class CMagic  * m_pMagicConfigList[DEF_MAXMAGICTYPE];
	class CSkill  * m_pSkillConfigList[DEF_MAXSKILLTYPE];
	class CQuest  * m_pQuestConfigList[DEF_MAXQUESTTYPE];
	//class CTeleport * m_pTeleportConfigList[DEF_MAXTELEPORTTYPE];

	class XSocket* _lsock;

	class PartyManager* m_pPartyManager;

	void OnClientLoginRead(int h);
	void DeleteLoginClient(int h);

	std::vector<LoginClient*> _lclients_disconn;

	char            m_pMsgBuffer[DEF_MSGBUFFERSIZE+1];

	HWND  m_hWnd;
	int   m_iTotalClients, m_iMaxClients, m_iTotalGameServerClients, m_iTotalGameServerMaxClients;
	int   m_iTotalBots, m_iMaxBots, m_iTotalGameServerBots, m_iTotalGameServerMaxBots;
	SYSTEMTIME m_MaxUserSysTime;

	BOOL  m_bF1pressed, m_bF4pressed, m_bF12pressed, m_bF5pressed;
	BOOL  m_bOnExitProcess;
	DWORD m_dwExitProcessTime;

	DWORD m_dwWhetherTime, m_dwGameTime1, m_dwGameTime2, m_dwGameTime3, m_dwGameTime4, m_dwGameTime5, m_dwGameTime6, m_dwFishTime;
	
	// Crusade Schedule
	BOOL m_bIsCrusadeWarStarter;
	BOOL m_bIsApocalypseStarter;
	int m_iLatestCrusadeDayOfWeek;

	char  m_cDayOrNight;
 	int   m_iSkillSSNpoint[102];

	class CMsg * m_pNoticeMsgList[DEF_MAXNOTIFYMSGS];
	int   m_iTotalNoticeMsg, m_iPrevSendNoticeMsg;
	DWORD m_dwNoticeTime, m_dwSpecialEventTime;
	BOOL  m_bIsSpecialEventTime;
	char  m_cSpecialEventType;

	DWORD m_iLevelExpTable[1000];	//New 22/10/04

 	class CFish * m_pFish[DEF_MAXFISHS];
	class CPortion * m_pPortionConfigList[DEF_MAXPORTIONTYPES];
	class CPortion* m_pCraftingConfigList[DEF_MAXPORTIONTYPES];

	BOOL  m_bIsServerShutdowned;
	char  m_cShutDownCode;
	class CMineral * m_pMineral[DEF_MAXMINERALS];

	int   m_iMiddlelandMapIndex; 
	int   m_iAresdenMapIndex;		// 아레스덴 맵 인덱스 
	int	  m_iElvineMapIndex;		// 엘바인 맵 인덱스
	int   m_iBTFieldMapIndex;
	int   m_iGodHMapIndex;
	int   m_iAresdenOccupyTiles;
	int   m_iElvineOccupyTiles;
	int   m_iCurMsgs, m_iMaxMsgs;

	DWORD m_dwCanFightzoneReserveTime ;

	int  m_iFightZoneReserve[DEF_MAXFIGHTZONE] ;
	int  m_iFightzoneNoForceRecall  ;

	struct {
		__int64 iFunds;
		__int64 iCrimes;
		__int64 iWins;

	} m_stCityStatus[3];
	
	int	  m_iStrategicStatus;
	
	class XSocket * m_pSubLogSock[DEF_MAXSUBLOGSOCK];
	int   m_iSubLogSockInitIndex;
	BOOL  m_bIsSubLogSockAvailable[DEF_MAXSUBLOGSOCK];
	int	  m_iCurSubLogSockIndex;
	int   m_iSubLogSockFailCount;
	int   m_iSubLogSockActiveCount;	
	int   m_iAutoRebootingCount;

	class CBuildItem * m_pBuildItemList[DEF_MAXBUILDITEMS];
	class CItem * m_pDupItemIDList[DEF_MAXDUPITEMID];

	char * m_pNoticementData;
	DWORD  m_dwNoticementDataSize;

	DWORD  m_dwMapSectorInfoTime;
	int    m_iMapSectorInfoUpdateCount;

	// Crusade 처리용
	int	   m_iCrusadeCount;	
	BOOL   m_bIsCrusadeMode;		
	BOOL   m_bIsApocalypseMode;
	// Daryl - Chat logging option
	BOOL m_bLogChatOption;

	struct {
		char cMapName[11];	
		char cType;			
		int  dX, dY;		

	} m_stCrusadeStructures[DEF_MAXCRUSADESTRUCTURES];

	
	int m_iCollectedMana[3];
	int m_iAresdenMana, m_iElvineMana;

	class CTeleportLoc m_pGuildTeleportLoc[DEF_MAXGUILDS];
	//

	WORD  m_wServerID_GSS;
	char  m_cGateServerStockMsg[DEF_MAXGATESERVERSTOCKMSGSIZE];
	int   m_iIndexGSS;

	int m_iLastCrusadeWinner; 	// New 13/05/2004
	struct {
		int iCrashedStructureNum;
		int iStructureDamageAmount;
		int iCasualties;
	} m_stMeteorStrikeResult;

	struct {
		char cType;		
		char cSide;		
		short sX, sY;	
	} m_stMiddleCrusadeStructureInfo[DEF_MAXCRUSADESTRUCTURES];

	struct {
		char m_cBannedIPaddress[21];
	} m_stBannedList[DEF_MAXBANNED];

	struct {
		char m_cGMName[11];
	} m_stAdminList[DEF_MAXADMINS];

	// Crusade Scheduler
	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stCrusadeWarSchedule[DEF_MAXSCHEDULE];

	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stApocalypseScheduleStart[DEF_MAXAPOCALYPSE];

	struct {
		int iDay;
		int StartiHour;
		int StartiMinute;
		int EndiHour;
		int EndiMinute;
	} m_stHeldenianSchedule[DEF_MAXHELDENIAN];

	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stApocalypseScheduleEnd[DEF_MAXAPOCALYPSE];

	int m_iTotalMiddleCrusadeStructures;
 
	int m_iClientShortCut[DEF_MAXCLIENTS+1];

	int m_iNpcConstructionPoint[DEF_MAXNPCTYPES];
	DWORD m_dwCrusadeGUID;
	short m_sLastCrusadeDate;
	int   m_iCrusadeWinnerSide;
	int   m_iPlayerMaxLevel;

	struct  {
		int iTotalMembers;
		int iIndex[9];
	}m_stPartyInfo[DEF_MAXCLIENTS];

	// Daryl - Admin level adjustments
	int m_iAdminLevelWho;
	int m_iAdminLevelGMKill;
	int m_iAdminLevelGMRevive;
	int m_iAdminLevelGMCloseconn;
	int m_iAdminLevelGMCheckRep;
	int m_iAdminLevelEnergySphere;
	int m_iAdminLevelShutdown;
	int m_iAdminLevelObserver;
	int m_iAdminLevelShutup;
	int m_iAdminLevelCallGaurd;
	int m_iAdminLevelSummonDemon;
	int m_iAdminLevelSummonDeath;
	int m_iAdminLevelReserveFightzone;
	int m_iAdminLevelCreateFish;
	int m_iAdminLevelTeleport;
	int m_iAdminLevelCheckIP;
	int m_iAdminLevelPolymorph;
	int m_iAdminLevelSetInvis;
	int m_iAdminLevelSetZerk;
	int m_iAdminLevelSetIce;
	int m_iAdminLevelGetNpcStatus;
	int m_iAdminLevelSetAttackMode;
	int m_iAdminLevelUnsummonAll;
	int m_iAdminLevelUnsummonDemon;
	int m_iAdminLevelSummon;
	int m_iAdminLevelSummonAll;
	int m_iAdminLevelSummonPlayer;
	int m_iAdminLevelDisconnectAll;
	int m_iAdminLevelEnableCreateItem;
	int m_iAdminLevelCreateItem;
	int m_iAdminLevelStorm;
	int m_iAdminLevelWeather;
	int m_iAdminLevelSetStatus;
	int m_iAdminLevelGoto;
	int m_iAdminLevelMonsterCount;
	int m_iAdminLevelSetRecallTime;
	int m_iAdminLevelUnsummonBoss;
	int m_iAdminLevelClearNpc;
	int m_iAdminLevelTime;
	int m_iAdminLevelPushPlayer;
	int m_iAdminLevelSummonGuild;
	int m_iAdminLevelCheckStatus;
	int m_iAdminLevelCleanMap;

	// 09/26/2004
	short m_sSlateSuccessRate;

	// 17/05/2004
	short m_sForceRecallTime;

	// 22/05/2004
	int	 m_iPrimaryDropRate, m_iSecondaryDropRate;

	// 25/05/2004
	int m_iFinalShutdownCount;

	// New 06/07/2004
	BOOL m_bEnemyKillMode;
	int m_iEnemyKillAdjust;
	BOOL m_bAdminSecurity;
	
	// Configurable Raid Time 
	short m_sRaidTimeMonday; 
	short m_sRaidTimeTuesday; 
	short m_sRaidTimeWednesday; 
	short m_sRaidTimeThursday; 
	short m_sRaidTimeFriday; 
	short m_sRaidTimeSaturday; 
	short m_sRaidTimeSunday; 

	BOOL m_bManualTime;
	int m_iSummonGuildCost;
	
	// Apocalypse
	BOOL	m_bIsApocalyseMode;
	BOOL	m_bIsHeldenianMode;
	BOOL	m_bIsHeldenianTeleport;
	char	m_cHeldenianType;

	DWORD m_dwApocalypseGUID;
	
	// Slate exploit
	int m_sCharPointLimit;

	// Limit Checks
	short m_sCharStatLimit;
	BOOL m_bAllow100AllSkill;
	short m_sCharSkillLimit;
	char m_cRepDropModifier;
	char  m_cSecurityNumber[11];
	short m_sMaxPlayerLevel;
	
	BOOL var_89C, var_8A0;
	char m_cHeldenianVictoryType, m_sLastHeldenianWinner, m_cHeldenianModeType;
	int m_iHeldenianAresdenDead, m_iHeldenianElvineDead, var_A38, var_88C;
	int m_iHeldenianAresdenLeftTower, m_iHeldenianElvineLeftTower;
	DWORD m_dwHeldenianGUID, m_dwHeldenianStartHour, m_dwHeldenianStartMinute, m_dwHeldenianStartTime, m_dwHeldenianFinishTime;
	BOOL m_bReceivedItemList;
	BOOL m_bHeldenianInitiated;
	BOOL m_bHeldenianRunning;

private:
	int __iSearchForQuest(int iClientH, int iWho, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_Cityhall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void _ClearExchangeStatus(int iToH);
	int _iGetItemSpaceLeft(int iClientH);

public:
	void AdminOrder_GoTo(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_MonsterCount(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_SetForceRecallTime(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_UnsummonBoss(int iClientH);
	void RemoveCrusadeNpcs(void);
	void RemoveCrusadeRecallTime(void);
	BOOL _bCrusadeLog(int iAction,int iClientH,int iData, char * cName);
	int iGetPlayerABSStatus(int iClientH);
	BOOL _bInitItemAttr(class CItem * pItem, int iItemID);
	void ReqCreateSlateHandler(int iClientH, char* pData);
	void SetSlateFlag(int iClientH, short sType, bool bFlag);
	void CheckForceRecallTime(int iClientH);
	void SetPlayingStatus(int iClientH);
	void ForceChangePlayMode(int iClientH, bool bNotify);
	void ShowVersion(int iClientH);
	void ShowClientMsg(int iClientH, char* pMsg);
	void RequestResurrectPlayer(int iClientH, bool bResurrect);
	void LoteryHandler(int iClientH);
	void SetSkillAll(int iClientH,char * pData, DWORD dwMsgSize);
	
	/*void GetAngelMantleHandler(int iClientH,int iItemID,char * pString);
	void CheckAngelUnequip(int iClientH, int iAngelID);
	int iAngelEquip(int iClientH);*/

	void SetAngelFlag(short sOwnerH, char cOwnerType, int iStatus, int iTemp);
	void GetAngelHandler(int iClientH, char* pData, DWORD dwMsgSize);

	void RequestEnchantUpgradeHandler(int client, DWORD type, DWORD lvl, int iType);
	int GetRequiredLevelForUpgrade(DWORD value);
	void RequestItemEnchantHandler(int iClientH, int sDestItemID, int iType);
	void RequestItemDisenchantHandler(int iClientH, int iItemIndex);
	char* GetShardDesc(DWORD dwType);
	char* GetFragmentDesc(DWORD dwType);
	char* GetShardName(DWORD dwType);
	char* GetFragmentName(DWORD dwType);

	void requestRebirth(int client);
	void switchRebirth(int client);
	void calcStatsPoints(int client);
	void unequipItems(int client);
	void copyStats(int client);
	void restoreStats(int client);
	void copyLevel(int client);
	void copyExp(int client);
	void copyStatsPoints(int client);
	void calculatePoints(int client);
	void AutoSkill(int iClientH);
};

#endif // !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
