#ifndef _USERSLOGIN_PRIVATE_H
#define _USERSLOGIN_PRIVATE_H

#define MAX_INFO_LENGTH (10)

typedef struct
{
    c8_t strUsername[MAX_INFO_LENGTH];
    c8_t strPassword[MAX_INFO_LENGTH];
} UserInfo_t;

#endif //_USERSLOGIN_PRIVATE_H
