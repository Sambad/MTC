#include "CurveGernator.h"

Curve::Curve(u32 pCurveInfoHeaderAddr, u32 pCurveDataHeaderAddr)  //Force convert to u8* pointer in the function
{
    assert(pCurveInfoHeaderAddr != NULL);
    assert(pCurveDataHeaderAddr != NULL);

    m_CurveInfoHeaderAddr = (u8 *)pCurveInfoHeaderAddr;
    m_CurveDataHeaderAddr = (u8 *)pCurveDataHeaderAddr;

    m_CurveInfoAddr = (u16 *)(pCurveInfoHeaderAddr + MAX_HEADER_LENGTH);
    m_CurveDataAddr = (u16 *)(pCurveDataHeaderAddr + MAX_HEADER_LENGTH);

}
Curve::~Curve(void)
{ 
    m_CurveInfoHeaderAddr = NULL;
    m_CurveDataHeaderAddr = NULL;
    m_CurveInfoAddr = NULL;
    m_CurveDataAddr = NULL;
} 
 
bool Curve::ParseCurveInfo(u8 *pCuveInfoBuf)
{
    return true;
}
bool Curve::CheckCurveDataInFlash(u16 *pCurveDataFlashAddr)
{
    return true;
}
bool Curve::GenerateCurveOnRam(u16 AccTime, s32 StartSpeed, s32 EndSpeed)
{
    
}
const double CurvatureTimePercent = 0.4;   
const u16 MaxTimerRegValue = 0xff;
bool Curve::GenerateCurve(u32 clk, double AccTime, double StartSpeed, double EndSpeed)
{
    assert_do(AccTime <= 30, return false)
    assert_do(StartSpeed <= EndSpeed, return false)

    double SpeedFreq;
    double SpeedPeriod;
    double Acc, dAcc;
    double TimeStamp_AAccEnd, TimeStamp_DAccStart;
    double dAccTime;
    double CurrentTime;
    double MaxAcc;
    double J;

    u16 SpeedPeriodToReg;

    TimeStamp_AAccEnd   = AccTime * (1 - CurvatureTimePercent) / 2;  
    TimeStamp_ADccStart = AccTime * (1 + CurvatureTimePercent) / 2;  
    MaxAcc = (EndSpped - StartSpeed) * 2 / ((1 + CurvatureTimePercent) * AccTime);
    J = 2 * MaxAcc / (( 1 - CurvatureTimerPercent) * AccTime);

    do
    {
        SpeedFreq = StartSpeed;
        SpeedPeriod = 1 / SpeedFreq;
        if(SpeedPeriod > MaxTimerRegValue)
            SpeedPeriod = MaxTimerRegValue;
        SpeedPeriodToReg = (u16)SpeedPeriod;

        dAccTime = SpeedPeriod;
        CurrentTime += dAccTime;

        if(CurrentTime <= TimeStamp_AAccEnd)
            dAcc = J * dAccTime;
        else if ((CurrentTime > TimeStamp_AAccEnd) && (CurrentTime <= TimeStamp_DAccStart) )
            dAcc = 0;
        else if (CurrentTime > TimeStamp_DAccStart)
            dAcc = (-1) * J * dAccTime;

        SpeedFreq += dAcc;

    }while(SpeedFreq < EndSpeed);
}




}
bool Curve::WriteCurveDataToFlash(u16 pCurveAddr, s32 curve_length);