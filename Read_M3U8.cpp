//
//  Read_M3U8.cpp
//  Http_Client
//
//  Created by afk on 2020/3/31.
//  Copyright © 2020年 mgc. All rights reserved.
//

#include "Read_M3U8.hpp"


std::vector<std::string> Read(std::string M3U8_string,std::string URL)  //读取一个m3u8文件返回ts文件指针
{
   // FILE *ts;
    
    FILE *M3U8=fopen(M3U8_string.c_str(), "r");
    
   // int num=URL.find("/video.");
    
    int num=URL.find("media/");
    std::cout<< URL.substr(0,num+6)<<std::endl;
    URL=URL.substr(0,num+6);
    std::vector<std::string> TSvector_URL;
    char n;
    std::string TS_URL;
    std::string URLM;
    while ((!feof(M3U8))&&(M3U8!=nullptr)) {
        fread(&n, sizeof(char), 1, M3U8);
        URLM=URL;
        TS_URL="";
        while (n=='\n'||n=='\r') {
            fread(&n, sizeof(char), 1, M3U8);
        }
        if (n=='#') {
            while (n!='\n') {
                fread(&n, sizeof(char), 1, M3U8);
            }
        }
        else
        {
            
            //fread(&n, sizeof(char), 1, M3U8);
            while (n=='\n'||n=='\r') {
                fread(&n, sizeof(char), 1, M3U8);
            }
            while (n!='\n'&&n!='\r') {
                TS_URL.push_back(n);
                fread(&n, sizeof(char), 1, M3U8);
                
            }
           // break;
            
            //break;
            
            URLM=URLM.append(TS_URL);
            std::cout<<URLM<<std::endl;
            TSvector_URL.push_back(URLM);
            
            if (n=='\0'||n=='\x01') {
                break;
            }
            if(TSvector_URL.size()>=696)
            {
                break;
            }
            
        }
    }
    
   //std::cout<<TS_URL<<std::endl;
    
    
    
    //TS_URL=TS_URL.append(URL);
    
    fclose(M3U8);
    
    
    return TSvector_URL;
}
