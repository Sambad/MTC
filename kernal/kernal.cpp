#include "kernal.h"

CKernal::CKernal(void)
{

}

void CKernal::Init(void)
{
    pHwIfs = new CHwIfs();
}