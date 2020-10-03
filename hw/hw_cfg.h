#pragma once
#define HW_CFG_USART_NUM    4
#define HW_CFG_TIMER_NUM    4

class CHwCfg 
{
    public:
    CHwCfg(void);
    ~CHwCfg(void);

    virtual void SystemConfig(void);
    virtual void FlashAddrConfig(void);
    
    virtual void config_usart(ModuleTimer &pUsart, TypedefUSART *USARTx);
    virtual void config_timer_PWM(ModuleTimer &pTimer, TypeDefTimer *TIMx);
    virtual void config_CAN(ModuleTimer &pCan, TypedefCAN *CANx);
    virtual void config_Flash(ModuleFlash &pFlash);

    private:
    void config_usart_common(void);
}