#pragma once

#include "includes.h"
#define MAX_CURVE_SIZE      (10 * 1024)

#define SUPPORT_CURVE_ON_RAM    

#define MAX_HEADER_LENGTH   32
#define TIMER_CLOCK_FREQ    18000000    //18M

const u8 CuveInfoHeader[MAX_HEADER_LENGTH] = "Header: Curve Info V1.0";
const u8 CuveDataHeader[MAX_HEADER_LENGTH] = "Header: Curve Data V1.0";

class Curve
{
    public:
    Curve(u32 pCurveInfoHeaderAddr, u32 pCurveDataHeaderAddr);  //Force convert to u8* pointer in the function
    ~Curve(void);

    bool ParseCurveInfo(u8 *pCuveInfoBuf);
    bool CheckCurveDataInFlash(u16 *pCurveDataFlashAddr);

    bool GenerateCurve(u16 AccTime, s32 StartSpeed, s32 EndSpeed);

    private:
    bool WriteCurveDataToFlash(u16 pCurveAddr, s32 curve_length);
    bool bGerating;
    bool bCurveDone;
    s32 m_CurveLength;
    u16 m_CurveBuffer[MAX_CURVE_SIZE];

    u8 *m_CurveInfoHeaderAddr;
    u8 *m_CurveDataHeaderAddr;
    u16 *m_CurveInfoAddr;
    u16 *m_CurveDataAddr;
}

