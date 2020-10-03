#include "fifo.h"
#include "log.h"

template <FifoType>
void CFifo::CFifo(int size)
{
    if(size > MAX_FIFO_SIZE)
        return;
    
    m_head=0;
    m_tail=0;

    m_size = size;

    m_buf = new <FifoType>[size];
}
void CFifo::~CFifo(void)
{
    delete m_buf;
}

bool CFifo::IsEmpty(void)
{
    return m_head == m_tail;
}

bool CFifo::IsFull(void)
{
    return (m_head + m_size) % size == (m_tail - 1) ;
}

template <FifoType>
ERR_CODE CFifo::EnFifo(FifoType  *pElement)
{
    if(IsFull())
        return ERR_FIFO_FULL;

    m_buf[m_head] = *pElement;
    
    if(++m_head > m_size)
        m_head = 0;  

    m_count ++;
    return ERR_OK;
}

template <FifoType>
ERR_CODE CFifo::DDeFifo(FifoType &element);
{
    if(IsEmpty())
        return ERR_FIFO_EMPTY;
    element = m_buf[m_tail];
    if(++m_tail > m_size)
        m_tail = 0;
    m_count -- ;
    return ERR_OK;
}
ERR_CODE CFifo::Flush(void)
{
    memset(m_buf, 0, m_size);
    m_tail = m_head;
    m_count = 0;
    return ERR_OK;
}

int CFifo::CurrentSize(void)
{
    return m_count;
}
int IsValidSize(void);
{
    return m_size - m_count;
}
