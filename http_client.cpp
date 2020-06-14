
#include "http_client.hpp"

namespace mgc {
    namespace proxy{
        HttpClient::HttpClient(int iSocket,bool cancel):m_iSocketFd(iSocket),_cancel(cancel)
        {
           
        }

        HttpClient::~HttpClient(){}
//
        HttpClient *HttpClient::getInstance()
        {
            HttpClient *http=new HttpClient(INVALID_SOCKET,0);
            if(http)
            {
                return http;
            }
            return nullptr;
        }
        
        void HttpClient::cancel(){
            this->_cancel=1;
            return;
        }
        
        void HttpClient::begin(){
            this->_cancel=0;
            return;
        }
        
        
        
        int HttpClient::httpGet(std::string strUrl, std::string &strResponse,std::string strBytes,std::string fileString,std::string headString,std::string dstUrl)
        {
            return httpResquestExec("GET", strUrl, "", strResponse,strBytes,fileString,headString,dstUrl);
        }


        int HttpClient::httpResquestExec(std::string strMethod, std::string strUrl, std::string strData, std::string &strResponse,std::string strBytes,std::string fileString,std::string headString,std::string dstUrl)
        {
            if (strUrl=="") {
                debugOut("URL为空");
                return 0;
            }

            if (strUrl.size()>URLSIZE) {
                debugOut("URL不能超过2048");
                return 0;
            }
           // strUrl="http://www.csdn.net/\r\n";
            
           // strUrl="http://hlsmgspvod.miguvideo.com";
            std::string strHttpHead=httpHeadCreate(strMethod, strUrl, strData,strBytes,dstUrl);

            if(m_iSocketFd!=-1)
            {
                std::string strResult=httpDataTransmit(strHttpHead, m_iSocketFd,fileString,headString);
            

                if(strResult!="")
                {
                    strResponse=strResult;
                    return 1;
                }
            }

			WORD wVersionRequested;
			WSADATA wsaData;
			int err;
			wVersionRequested = MAKEWORD(1, 1);
			err = WSAStartup(wVersionRequested, &wsaData);
			if (err != 0)
			{
				debugOut("\n\n-----TCP WSAStartup failed------\n\n");
				return S_FALSE;
			}
			

            m_iSocketFd=INVALID_SOCKET;
            m_iSocketFd=socket(AF_INET,SOCK_STREAM,0);

            if (m_iSocketFd<0) {
                debugOut("socket error",errno,strerror(errno));
                return 0;
            }

            int iPort=getPortFromUrl(strUrl);

            if(iPort<0)
            {
                debugOut("获取URL端口失败");
                return 0;
            }

            std::string strIP=getIpFromUrl(strUrl);

            if(strIP=="")
            {
                debugOut("从URL获取IP地址失败");
                return 0;
            }

            struct sockaddr_in servaddr;

			memset(&servaddr, 0, sizeof(servaddr));

            servaddr.sin_family=AF_INET;
            servaddr.sin_port=htons(iPort);

            if (inet_pton(AF_INET,strIP.data(),&servaddr.sin_addr)<=0) {
                debugOut("inet_pton error!Error code:%d,Error message:%s\n",errno,strerror(errno));
				closesocket(m_iSocketFd);
                m_iSocketFd=INVALID_SOCKET;
                return 0;
            }

//          
            int iRet=connect(m_iSocketFd, (struct sockaddr*)&servaddr, sizeof(servaddr));
            if (iRet==0) {

				std::string strResult;
				strResult=httpDataTransmit(strHttpHead, m_iSocketFd,fileString,headString);
                if (NULL==strResult.c_str()) {
					closesocket(m_iSocketFd);
                    m_iSocketFd=INVALID_SOCKET;
                    return 0;
                }
                else{
                    strResponse=strResult;
                    return 1;
                }
            }
            else if(iRet<0){
                std::cout<<"connect error "<<std::endl;
                std::cout<<errno<<std::endl;
                return 0;
            }

            iRet=socketFdCheck(m_iSocketFd);
            if(iRet>0){
                std::string strResult=httpDataTransmit(strHttpHead, m_iSocketFd,fileString,headString);
                if (strResult=="") {
					closesocket(m_iSocketFd);
                    m_iSocketFd=INVALID_SOCKET;
                    return 0;
                }
                else{
                    strResponse=strResult;
                    return 1;
                }

            }
            else{
				closesocket(m_iSocketFd);
                m_iSocketFd=INVALID_SOCKET;
                return 0;
            }

            return 1;
        }

        std::string HttpClient::httpHeadCreate(std::string strMethod, std::string strUrl, std::string strData,std::string strBytes,std::string dstUrl)
        {
//            std::string strHost=getHostAddFromUrl(strUrl);
//            std::string strParam=getParamFromUrl(strUrl);

            std::string strHttpHead;

            strHttpHead.append(strMethod);
            strHttpHead.append(" ");
    


            strHttpHead.append(dstUrl);
     
            strHttpHead.append(" ");
            strHttpHead.append("HTTP/1.1\r\n");
            strHttpHead.append("User-Agent: MGPlayer4Android/v9.9.2.29\r\n");
            strHttpHead.append("Accept: */*\r\n");
            strHttpHead.append("Range: bytes=0-\r\n");
            strHttpHead.append("Connection: close\r\n");
            strHttpHead.append("Host: hlsmgspvod.miguvideo.com:8080\r\n");
            strHttpHead.append("Icy-MetaData: 1\r\n");\
            strHttpHead.append("Best-Effort: true\r\n");
            strHttpHead.append("DownloadRate: 20000\r\n");
            
     
            strHttpHead.append("\r\n");
            
           // std::cout<<strHttpHead<<std::endl;

            return strHttpHead;
        }

        std::string HttpClient::httpDataTransmit(std::string strHttpHead, int isSocFd,std::string fileString,std::string headString)
        {
            char *head=(char *)strHttpHead.data();
            //std::cout<<head<<std::endl;
            long ret=send(isSocFd, head, strlen(head), 0);
//            std::cout<<isSocFd<<std::endl;
            std::cout<<head<<std::endl;
//            std::cout<<strlen(head)+1<<std::endl;
            if(ret<0)
            {
                debugOut("send error !Error code:",errno,strerror(errno));
				closesocket(isSocFd);
                return "";
            }

            std::ofstream outFile(fileString,std::ios_base::binary);
            std::ofstream outHead(headString,std::ios_base::binary);
           // int i=0;
           // ret=recv(isSocFd, (void *)buf, BUFSIZE, 0);

            char * recvBuf = new char[1024];
			char *buf = new char[BUFSIZE];
            int j=0;
            //接收head文件
            while (this->_cancel==0){
                memset(recvBuf, 0, 1024);
                recvBuf[1023]='\0';
                ret = recv(isSocFd, recvBuf,1023, 0);
                if (ret > 0){
                  //  strncat(buf, recvBuf, ret);

                 //  std::cout<<recvBuf<<std::endl;
                    std::string r=recvBuf;
                   // std::cout<<r<<std::endl;
                    if (recvBuf[0]=='H') {
                        int i=r.find("\r\n\r\n");
                        i=i+3;
                        while  (j<i){
                            outHead<<recvBuf[j];
                            std::cout<<recvBuf[j];
                            j++;
                        }
                        outHead.close();
                        break;
                    }
//
                    outHead.close();
                    break;
                }
                else {
                    outHead.close();
                    break;
                }
            }
            for (int i=j+1; i<ret; i++) {
                //std::cout<<recvBuf[i]<<std::endl;
                outFile<<recvBuf[i];
            }
            free(recvBuf);
//
           
            while (1) {
              //  i++;
                
               // std::cout<<i<<std::endl;
            memset(buf, 0, BUFSIZE);
            buf[BUFSIZE-1]='\0';
                
              
            ret=recv(isSocFd, buf, BUFSIZE, 0);
        
            if(ret>0){
              //  std::string strRecv=buf;
                outFile.write(buf, ret);
               // std::cout<<"i:"<<i<<std::endl;
               // i++;
                
            
            }
            else if (ret<=0){
                if(errno==EINTR||errno==EWOULDBLOCK||errno==EAGAIN)
                {
                
                    continue;
                }else{
					closesocket(isSocFd);
                    free(buf);
                    outFile.close();
                
                    return "";
                }

                }
            }
            
            
         //   sleep(1);
            
            
            return "";
        }

        std::string HttpClient::getHostAddFromUrl(std::string strUrl){
            char url[URLSIZE]={0};
            strcpy(url, strUrl.c_str());
            char *strAddr=strstr(url, "http://");
            if(strAddr==NULL){
                strAddr=strstr(url, "http://");
                if (strAddr!=NULL) {
                    strAddr+=8;
                }
            }
            else{
                strAddr+= 7;
            }
            if(strAddr==NULL)
            {
                strAddr=url;
            }

            char *strHostAddr=new char[strlen(strAddr)+1];

            memset(strHostAddr, 0, strlen(strAddr)+1);
            for (int i=0;i<strlen(strAddr)+1; i++) {
                if(strAddr[i]=='/')
                {
                    break;
                }
                else{
                    strHostAddr[i]=strAddr[i];
                }
            }

            std::string host=strHostAddr;
            free(strHostAddr);
            return host;

        }

        std::string HttpClient::getParamFromUrl(std::string strUrl){

            char url[URLSIZE]={0};
            strcpy(url, strUrl.c_str());

            char* strAddr=strstr(url, "http://");

            if (strAddr==NULL) {
                strAddr=strstr(url, "http://");
                if (strAddr!=NULL) {
                    strAddr+=8;
                }
            }
            else{
                strAddr +=7;
            }
            if(strAddr==NULL){
                strAddr=url;
            }

            char *strParam = new char[strlen(strAddr)+1];

            memset(strParam, 0, strlen(strAddr)+1);

            int iPos=-1;

            for(int i=0;i<strlen(strAddr)+1;i++)
            {
                if(strAddr[i]=='/')
                {
                    iPos=i;
                    break;
                }
            }
            if (iPos==-1) {
                strcpy(strParam, "");
            }
            else{
                strcpy(strParam, strAddr+iPos+1);
            }

            std::string param=strParam;
            free(strParam);
            return param;
        }


        int HttpClient::getPortFromUrl(std::string strUrl)
        {
            int nPort = -1;
            char *strHostAddr = (char *)getHostAddFromUrl(strUrl).data();

            if (strHostAddr == NULL)
            {
                return -1;
            }

            char strAddr[URLSIZE] = {0};
            strcpy(strAddr, strHostAddr);
            char *strPort = strchr(strAddr, ':');
            if (strPort == NULL)
            {
                nPort = 8002;
            }
            else
            {
                nPort = atoi(++strPort);
            }
            return nPort;
        }

        std::string HttpClient::getIpFromUrl(std::string strUrl)
        {

            std::string url = getHostAddFromUrl(strUrl);
            char *strHostAddr = (char *)url.data();
            char *strAddr = new char[strlen(strHostAddr) + 1];
            memset(strAddr, 0, strlen(strAddr)+1);
            int nCount = 0;
            int nFlag = 0;
            for (int i = 0; i < strlen(strAddr) + 1; i++)
            {
                if (strHostAddr[i] == ':')
                {
                    break;
                }
                strAddr[i] = strHostAddr[i];
                if (strHostAddr[i] == '.')
                {
                    nCount++;
                    continue;
                }
                if (nFlag == 1)
                {
                    continue;
                }
                if ((strHostAddr[i] >= 0)||(strHostAddr[i] <= '9'))
                {
                    nFlag = 0;
                }
                else
                {
                    nFlag = 1;
                }
            }
            if (strlen(strAddr) <= 1)
            {
                return NULL;
            }

            //判断是否为点分十进制IP,否则通过域名获取IP
            if ((nCount == 3) && (nFlag == 0))
            {
                return strAddr;
            }
            else
            {
                struct hostent *he = gethostbyname(strAddr);
                free(strAddr);
                if (he == NULL)
                {
                    return NULL;
                }
                else
                {
                    struct in_addr** addr_list = (struct in_addr **)he->h_addr_list;
                    for (int i = 0; addr_list[i] != NULL; i++)
                    {
                        return inet_ntoa(*addr_list[i]);
                    }
                    return NULL;
                }
            }
        }

        int HttpClient::socketFdCheck(const int iSockFd)
        {
            struct timeval timeout ;
            fd_set rset,wset;
            FD_ZERO(&rset);
            FD_ZERO(&wset);
            FD_SET(iSockFd, &rset);
            FD_SET(iSockFd, &wset);
            timeout.tv_sec = 3;
            timeout.tv_usec = 500;
            int iRet = select(iSockFd+1, &rset, &wset, NULL, &timeout);
            if(iRet > 0)
            {
                //判断SocketFd是否为可写不可读状态

                int iW = FD_ISSET(iSockFd,&wset);
                int iR = FD_ISSET(iSockFd,&rset);
                if(iW && !iR)
                {
                    char error[4] = "";
                    socklen_t len = sizeof(error);
                    int ret = getsockopt(iSockFd,SOL_SOCKET,SO_ERROR,error,&len);
                    if(ret == 0)
                    {
                        if(!strcmp(error, ""))
                        {
                            return iRet;//表示已经准备好的描述符数
                        }
                        else
                        {
                            debugOut("%s %s %d\tgetsockopt error code:%d,error message:%s", __FILE__, __FUNCTION__, __LINE__, errno, strerror(errno));
                        }
                    }
                    else
                    {
                        debugOut("%s %s %d\tgetsockopt failed. error code:%d,error message:%s", __FILE__, __FUNCTION__, __LINE__, errno, strerror(errno));
                    }
                }
                else
                {
                    debugOut("%s %s %d\tsockFd是否在可写字符集中：%d，是否在可读字符集中：%d\t(0表示不在)\n", __FILE__, __FUNCTION__, __LINE__, iW, iR);
                }
            }
            else if(iRet == 0)
            {
                return 0;//表示超时
            }
            else
            {
                return -1;//select出错，所有描述符集清0
            }
            return -2;//其他错误
        }
        void HttpClient::debugOut(std::string fmt, ...)
        {
            #ifdef __DEBUG__
            va_list ap;
            va_start(ap, fmt);
            vprintf(fmt.c_str(), ap);
            va_end(ap);
            #endif
        }





        int HttpClient::differ(std::string strfile1, long site, std::string strfile2){
            long camlen=0;

            std::ifstream oragefile(strfile1,std::ios_base::binary);
            std::ifstream camfile(strfile2,std::ios_base::binary);

            if(!oragefile.is_open())
            {
                return 0;
            }

            if (!camfile.is_open()) {
                return 0;
            }

            camfile.seekg(0,std::ios::end);
          //  oragefile.seekg(0,std::ios::end);
          //  long int ll=oragefile.tellg();
            long int len=1000000;
            camfile.seekg(0,std::ios_base::beg);
            oragefile.seekg(site,std::ios_base::beg);


            char *oragesite=new char[8192];
            char *camsite=new char[8192];

//camfile.open(strfile1.data());

            while (len>0) {
                if (len>8192) {
                    camlen=8192;
                }
                else
                    camlen=len;


                len-=8192;
              //  memset(oragesite, 0xFF, 8192);
                //memset(camsite, 0xFF, 8192);
            oragefile.read(&oragesite[0],camlen);
//                int r1 = oragefile.
              //  std::cout<<(int)oragesite[0]<<","<<(int)oragesite[1]<<","<<(int)oragesite[2]<<","<<(int)oragesite[3]<<","<<(int)oragesite[4]<<std::endl;
            camfile.read(&camsite[0],camlen);
//                int r2 =
//            std::out<<"r2:"<<r2<<std::endl;
            if (memcmp(oragesite, camsite, camlen)) {
                std::cout<<"error"<<std::endl;
                oragefile.close();
                camfile.close();
                return 0;
            }
            }

            oragefile.close();
            camfile.close();
            return 1;
        }

    }
}
