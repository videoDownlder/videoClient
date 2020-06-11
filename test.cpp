
#include "test.hpp"
#include "Read_M3U8.hpp"
#include "analyseTS.hpp"



void function (std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
    //
    //std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
    std::string return_msg;
    std::string strBytes=" 0-";
    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
    {
        std::cout << return_msg <<std::endl;
    }
    else
        std::cout<<"error"<<std::endl;
    
    
   // std::string TS_URL= Read(fileString,dstUrl);
    std::vector<std::string> TS_URL=Read(fileString, dstUrl);
    
    std::string TS_file,TS_head;
    
    
    TS_head=headString.append("_ts.txt");
    
    
    for (int i =0; i<TS_URL.size(); i++) {
       // TS_file="/Users/afk/test/urltest/test-subtitles/video/";
        TS_file="D:\\c++\\video\\";
		TS_URL[i] = TS_URL[i].substr(0, TS_URL[i].find(".ts")+3);
        TS_file=TS_file.append(TS_URL[i]);
       // TS_file=fileString.append(".ts");
        if (http->httpGet(url , return_msg,strBytes,TS_file,TS_head,TS_URL[i],dstPort))
        {
            //std::cout << return_msg <<std::endl;
        }
        else
            std::cout<<"error"<<std::endl;
    }
    
    
   // int answer=analyseTS(TS_file);
    
  //  std::cout<<answer<<std::endl;
    
    return ;
}
