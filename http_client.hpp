

#ifndef http_client_hpp
#define http_client_hpp

#include <stdio.h>



#include <string>
#include <functional>

#include <errno.h>
#include <fcntl.h>
#include <iostream>

#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>
#include <winsock2.h>
#include <string.h>
#include <WS2tcpip.h>
#pragma comment( lib, "ws2_32.lib")


//#define INVALID_SOCKET (-1)
#define BUFSIZE (8192)
#define URLSIZE (2048)

namespace mgc {
    namespace proxy{
        class HttpClient{
        public:
            HttpClient(int iSocket,bool cancel);
            ~HttpClient();
            
            static HttpClient *getInstance();
            void debugOut(std::string fmt,...);
            int httpGet(std::string strUrl,std::string &strResponse,std::string strBytes,std::string fileString,std::string headString,std::string dstUrl,std::string dstPort);
            int httpPost(std::string strUrl,std::string strData,std::string &strResponse,std::string strBytes,std::string fileString,std::string headString,std::string dstUrl,std::string dstPort);
            int differ(std::string strfile1,long site,std::string strfile2);//返回1表示比对成功，返回0表示比对失败
            void cancel();
            void begin();
            void run();
         //   void * _run_thread(void *p);
           
           
            
        private:
            int httpResquestExec(std::string strMethod,std::string strUrl,std::string strData,std::string &strResponse,std::string strBytes,std::string fileString,std::string headString,std::string dstUrl,std::string dstPort);
            std::string httpHeadCreate(std::string strMethod,std::string strUrl,std::string strData,std::string strBytes,std::string dstUrl,std::string dstPort);
            std::string httpDataTransmit(std::string strHttpHead, int isSocFd,std::string fileString,std::string headString);

            int getPortFromUrl(std::string strUrl);
            std::string getIpFromUrl(std::string strUrl);
            std::string getParamFromUrl(std::string strUrl);
            std::string getHostAddFromUrl(std::string strUrl);
            
            int socketFdCheck(const int iSockFd);
            
            int m_iSocketFd;
            
            bool _cancel=0;//0表示正常运行，1为断点。
            
    
        };
     
    }
}


#endif /* http_client_hpp */
