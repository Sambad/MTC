#pragma once
#include "hw_ifs.h"

class CKernal
{
public:
    CKernal(void);
    ~CKernal(void);

    void Init(void);    

private:
    CHwIfs *pHwIfs;
}