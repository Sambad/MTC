#pragma once

typedef void (FuncIntCallBack*)(void);
class ModuleTimer
{
    public:
    ModuleTimer(IntCallBack *pIntProcess);
    ~ModuleTimer(void);

    vu32 *reg_AA;

    FuncIntCallBack *m_pIntProcess;
}