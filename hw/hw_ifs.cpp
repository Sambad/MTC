#include "hw_ifs.h"

void CHwIfs::CHwIfs(void)
{
    m_pHwCfg = new CHwCfg();
    
    for(int i=0; i<HW_CFG_USART_NUM; i++)
        m_pUsart[i] = new CUsart(m_pHwCfg);
    
}