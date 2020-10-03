#pragma once 

#define MAX_FIFO_SIZE   512

template <FifoType>

class CFifo
{
    public:
    void CFifo(int size);
    ~CFifo(void);

    bool IsEmpty(void);
    bool IsFull(void);
    ERR_CODE EnFifo(FifoType  *pElement);
    ERR_CODE DeFifo(FifoType &element);
    bool Flush(void);
    int CurrentSize(void);
    bool IsValidSize(int size);
    
    protected:
    int m_tail;
    int m_head;
    int m_size;
    int m_count;
    FifoType *m_buf;
 }