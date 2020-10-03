#pragma once 
#include "usart.h"

class CHwIfs
{
    public:
    virtual CHwIfs(void)
    virtual ~CHwIfs(void)

    virtual void SystemInit(void);
    virtual void ModuleInit(void);

    CHwCfg *m_pHwCfg;
    //CUsart *m_pUsart[HW_CFG_USART_NUM];
    ModuleTimer *m_pModuleTimer;
    ModuleUsart *m_pModuleUsart;
    ModuleFlash *m_pModuleFlash;

}