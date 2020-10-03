#pragma once

typedef enum
{
	LimitMode_MaxLength,
	LimitMode_NoLimit,
}LIMIT_MODE;

struct MOTOR_CONFIG
{
	bool bNeedInit;
	bool bFindOrig;
	bool bFindTerm;
	bool bMoveToPosition;
	u8 InitIndex;
	s32 MoveBack;

	LIMIT_MODE LimitMode;
	s32 MaxLength;

	s32 MotorScaleNum;
	s32 MotorScaleDen;

	u8 SensorNum;
	s32 OrigSensorArea;
	s32 TermSensorArea;
	bool bOrigSenEnable;
	bool bTermSenEnable;
	bool bOrigHighAvial;
	bool bTermHighAvial;

	
	bool bUseEncoder;
	bool bEncoderReverse;
	bool bMoveDirReverse;

	bool bAutoSetSensorPosition;


	MOTOR_CONFIG()
	{
		bNeedInit = false;
		bFindOrig = true;
		bFindTerm = false;
		bMoveToPosition = 0;
		InitIndex = 1;
		MoveBack = 1000;

		LimitMode = LimitMode_MaxLength;
		MaxLength = 50000;

		MotorScaleNum = 1000;
		MotorScaleDen = 1000;

		SensorNum = 2;
		OrigSensorArea = 200;
		TermSensorArea = 200;
		bOrigSenEnable = true;
		bTermSenEnable = true;
		bOrigHighAvial = true;
		bTermHighAvial = true;
		
		bUseEncoder = false;
		bEncoderReverse = false ;
		bMoveDirReverse = false;

		bAutoSetSensorPosition = true;
	}

}


typedef enum
{
	MoveState_Idle,
	MoveState_Start,
	MoveState_WaitMoveOver,
	MoveState_Stop,
}MOVE_STATE;

typedef enum
{
	MotorStatus_OK,
	MotorStatus_SensorError,
	MotorStatus_PositionError,
}MOTOR_STATUS; 

typedef enum
{
	MoveDir_ToOrig,
	MoveDir_ToTerm,
}MOVE_DIR;

typedef enum
{
	FixMoveType_FindSensor,
	FixMoveType_MoveToSensor,
	FixMoveType_MoveToPosition,
}FIX_MOVE_TYPE;


struct MOVE_PARAM
{
	MOTOR_STATUS MotorStatus;
	MOVE_STATE MoveState;

	MOVE_DIR MoveDir;
	s32 MoveDistance;
	s32 SetPosition;
	s32 StartSpeed;
	s32 EndSpeed;
	s32 AccTime;

	bool bInitOK;
	bool bAtOrig;
	bool bAtTerm;

	bool bRunning;
	bool bMannalStop;
	bool bComplete;	

	bool bContinuous;
	bool bStartByContinue;
	
	bool bCheckTargetSensor;
	FIX_MOVE_TYPE FixMoveType;
	u8 TargetSensor;
	s32 TargetPosition;

}



