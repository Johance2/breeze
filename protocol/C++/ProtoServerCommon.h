 
#ifndef _PROTOSERVERCOMMON_H_ 
#define _PROTOSERVERCOMMON_H_ 
 
 
struct Route //路由信息  
{ 
    unsigned long long uID;  
    std::string token;  
    unsigned int expire;  
    Route() 
    { 
        uID = 0; 
        expire = 0; 
    } 
    Route(const unsigned long long & uID, const std::string & token, const unsigned int & expire) 
    { 
        this->uID = uID; 
        this->token = token; 
        this->expire = expire; 
    } 
}; 
inline zsummer::proto4z::WriteStream & operator << (zsummer::proto4z::WriteStream & ws, const Route & data) 
{ 
    ws << data.uID;  
    ws << data.token;  
    ws << data.expire;  
    return ws; 
} 
inline zsummer::proto4z::ReadStream & operator >> (zsummer::proto4z::ReadStream & rs, Route & data) 
{ 
        rs >> data.uID;  
        rs >> data.token;  
        rs >> data.expire;  
    return rs; 
} 
 
enum  : unsigned short 
{ 
    ETRIGGER_USER_LOGIN = 0, //用户登录, 用户ID  
    ETRIGGER_USER_LOGOUT = 1, //用户登出, 用户ID  
}; 
 
#endif 