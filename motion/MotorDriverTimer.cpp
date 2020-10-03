#include "MotorDriverTimer.h"
#include "MotionDataType.h"

MotorDriverTimer::MotorDriverTimer(ModuleTimer_PWM * pTimer, ModuleGpioOutput pDir, ModuleGpioOutput pEnable)
{
    m_pTimer = pTimer;
    m_pDir = pDir;
    m_pEnable = pEnable;
}
MotorDriverTimer::~MotorDriverTimer()
{
    m_pTimer = NULL;
    m_pDir = NULL;
    m_pEnable = NULL;
}
bool MotorDriverTimer::SetParamAndMove(const MOVE_PARAM *pMoveParam, const MOTOR_CONFIG pMotorConfig)
{
    if(!pMoveParam->bContinuous && (0==pMoveParam->MoveDistance))
        return false;

    if(MoveDir_ToOrig == pMoveParam->MoveDir)
    {
        if(pMotorConfig->bMoveDirReverse)
            m_pDir->SetToHigh();
        else
            m_pDir->SetToLow();
    }
    else if(MoveDir_ToTerm == pMoveParam->MoveDir)
    {
        if(pMotorConfig->bMoveDirReverse)
            m_pDir->SetToHigh();
        else
            m_pDir->SetToHigh();
    }
    else
        assert_do(false, return false);

    
    if(pMoveParam->bContinuous)

}
bool MotorDriverTimer::Stop(void)
bool MotorDriverTimer::EStop(void)
s32 MotorDriverTimer::GetPosition() const
void MotorDriverTimer::SetPosition(s32 position)
bool MotorDriverTimer::bIsRunning(void)


void MotorDriverTimer::IntProcess_Pulse(void)

bool MotorDriverTimer::Start(void)

void MotorDriverTimer::ChangeSegment(void)