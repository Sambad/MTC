#pragma once 
#include "hw_cfg"

enum{
    COM_STAT_IDLE,   
    COM_STAT_START_BYTE,
    COM_STAT_LENGTH,
    COM_STAT_CHECK_SUM,
    COM_STAT_PARAMS,
}COM_STAT;

struct 
{

}ComList;

class CUsart
{
    public:
    CUsart(CHwCfg *hw_config);
    ~CUsart(void);

    void CallBack_ReceiveInt(void);
    void CallBack_SendSucceedInt(void);

    ERR_CODE Send(char *buf, int length);
    ERR_CODE Recv(char *buf, int length);

    bool IsValidSize(int size);
    FifoType DeFifo(char *buf=NULL, int deFifoLength=0);

    private:
    
    CFifo *m_pFifo;
    
    

}