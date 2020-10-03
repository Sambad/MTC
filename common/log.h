#pragma once

#define assert( exp )   \
do{\
    if(!(exp))
    {
        keyPrint("------------------\n");\
        keyPrint("assert failed\n");\
        keyPrint("file: [%s]", __FILE__);\
        keyPrint("line: [%s]", __LINE__);\
        keyPrint("func: [%s]", __FUNCTION__);\
    }\
}while(0)

#define assert_do ( exp, do_sth)   \
do{\
    if(!(exp))
    {
        keyPrint("------------------\n");\
        keyPrint("assert failed\n");\
        keyPrint("file: [%s]", __FILE__);\
        keyPrint("line: [%s]", __LINE__);\
        keyPrint("func: [%s]", __FUNCTION__);\
        (do_sth);
    }\
}while(0)