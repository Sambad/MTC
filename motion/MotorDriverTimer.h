#pragma once
#include "includes.h"

typedef enum
{
	SEG_ACC1,
	SEG_JOG,
	SEG_ACC2,
	SEG_UNI, 
	SEG_DEC,
	SEG_EXTRA,
}CURVE_SEGMENT;


class MotorDriverTimer
{
    public:
    MotorDriverTimer(ModuleTimer_PWM * pTimer, ModuleGpioOutput pDir, ModuleGpioOutput pEnable);
    ~MotorDriverTimer();

    virtual bool SetParamAndMove(const MOVE_PARAM *move_param, const MOTOR_CONFIG);
    virtual bool Stop(void);
    virtual bool EStop(void);
    virtual s32 GetPosition() const;
    virtual void SetPosition(s32 position);
	virtual bool bIsRunning(void);


    void IntProcess_Pulse(void);

    protected:
    bool Start(void);

    private:
    void ChangeSegment(void);

    ModuleTimer_PWM  *m_pTimer;
	ModuleGpioOutput *m_pEnable;
	ModuleGpioOutput *m_pDir;

	bool m_bRunning;
	bool m_bMannualStop;
	s32 m_Increase;
	s32 m_Position;
	vs32 *m_pRegAcc;
	vs32 *m_pRegCr;

	u16 *m_pCurveDataTable;
	s32 m_CurrentSegLength;
	s32 m_AccSegLength;
	s32 m_UniSegLength;
	s32 m_DecSegLength;

}

void MotorDriver_PulseIntProcess(void);

