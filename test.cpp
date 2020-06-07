////
////  test.cpp
////  Http_Client
////
////  Created by afk on 2019/7/17.
////  Copyright © 2019年 mgc. All rights reserved.
////
//
#include "test.hpp"
#include "Read_M3U8.hpp"
#include "analyseTS.hpp"

//void function1(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
////
//    //std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes=" 0-";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
////    sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}


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
    
    
    TS_head=headString.append(".txt");
    
    
    for (int i =0; i<TS_URL.size(); i++) {
       // TS_file="/Users/afk/test/urltest/test-subtitles/video/";
        TS_file="/Users/afk/test/urltest/1/";
        TS_file=TS_file.append(TS_URL[i].substr(TS_URL[i].find("media/")+6,TS_URL[i].find("ts?")-TS_URL[i].find("media/")-4));
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
//
////请求部分range测试
////请求range2K对齐，单个block
////curl -H "Range:bytes=2048-2097151"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////写、读取缓存正常
//
//void function2(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="2048-2097151";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    //sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
//
////请求range2K对齐，跨多个block
////curl -H "Range:bytes=6293504-11536384"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////写、读取缓存正常
//
//void function3(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//  //  std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="6293504-11536384";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//   //sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
//
////请求range非2K对齐，单个block
////curl -H "Range:bytes=2049-2097151"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////按照2K对齐写，即写了4096-2097151范围内的数据
////curl -H "Range:bytes=4096-2097151"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////读取正确的缓存字节数
//
//void function4(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="2049-2097151";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//
//    //sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
//
////请求range非2K对齐，跨多个block
////curl -H "Range:bytes=2049-5244927"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////按照2K对齐写，即写了4096-5244927范围内的数据，跨三个block
////curl -H "Range:bytes=4096-5244927"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////读取正确的缓存字节数
//
//void function5(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//    //std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="2049-5244927";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//
//    //sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
//
////请求起始index小于现有缓存开始的index
////curl -H "Range:bytes=4096-5244927"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常缓存数据
////curl -H "Range:bytes=2048-5244927"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////因为起始index所在chunk的offset为0，所以按照现有逻辑需要重新请求数据：2048-5244927，符合预期，但有浪费，需优化。
//
//void function6(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="4096-5244927";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    strBytes="2048-5244927";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//   // sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
//
////请求起始index大于或等于现有缓存开始的index，请求结束index大于现有缓存的结束index
////curl -H "Range:bytes=4096-5244927"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常缓存数据
////curl -H "Range:bytes=4096-6290432"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////读取缓存数据，并请求没有的数据：5244928-6290432 符合预期
//
//void function7(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//   std::string strBytes="4096-5244927";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//     strBytes="4096-6290432";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//   // sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
////现有缓存分段中间有空白，请求起始index大于或等于现有缓存开始的index，请求结束index处于空白区域内
////curl -H "Range:bytes=0-2097151"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////curl -H "Range:bytes=2101248-4194303"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常缓存0-2097151、2101248-4194303的数据
////curl -H "Range:bytes=2048-2100000"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常读取缓存数据2048-2097151，请求2097152-2100000
//
//
//void function8(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="0-2097151";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    strBytes="2101248-4194303";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    //sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
////现有缓存分段中间有空白，请求起始index大于或等于现有缓存开始的index，请求结束index大于第二段缓存开始index
////curl -H "Range:bytes=0-2097151"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////curl -H "Range:bytes=2101248-4194303"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常缓存0-2097151、2101248-4194303的数据
////curl -H "Range:bytes=2048-4100000"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////正常读取缓存数据2048-2097151，请求2097152-4100000，按照现有逻辑不会读取第二段缓存，会有浪费，需优化。
//
//void function9(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//
//  //  std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="0-2097151";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    strBytes="2101248-4194303";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//    strBytes="2048-4100000";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//
//   // sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
//
////curl -H "Range:bytes=0-12582911"  --proxy http://127.0.0.1:9876/ --user-agent "hello" http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4
////请求范围跨6个block
//
//void function10(std::string src,long offset,std::string dst,std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort){
//    mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();
//    
//   // std::string url = "http://127.0.0.1:9876/";//"http://127.0.0.1:9876/";
//    std::string return_msg;
//    std::string strBytes="0-12582911";
//    if (http->httpGet(url , return_msg,strBytes,fileString,headString,dstUrl,dstPort))
//    {
//        std::cout << return_msg <<std::endl;
//    }
//    else
//        std::cout<<"error"<<std::endl;
//    
//    
//    sleep(15);
//    int c=http->mgc::proxy::HttpClient::differ(src,offset,dst);
//    
//    std::cout<<"return"<<std::endl;
//    std::cout<<c<<std::endl;
//}
