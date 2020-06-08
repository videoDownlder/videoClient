
#define _CRT_SECURE_NO_WARNINGS

#include "analyseTS.hpp"





typedef unsigned char UINT8;

bool JudgeBitIsOne(unsigned short ucData, unsigned short ucFlag)
{
    
    //    std::cout << "ucData::" << std::hex << ucData << std::endl;
    //    std::cout << "ucFlag:" << std::hex << ucFlag << std::endl;
    if (0x0000 == ucData)
        return false;
    else if (ucData == ucFlag)
        return true;
    
    return false;
}

bool IsIDR(FILE *file) {
    unsigned num = 0;
    for (int i = 0; i < 180; i++) {
        fread(&num, sizeof(char), 1, file);
        if (num ==0X65)
        {
            fseek(file, 180-sizeof(char)*(i-1), 1);
            return 1;
        }
        //        else
        //            std::cout << std::hex << num << std::endl;
    }
    
    
    return 0;
}

bool IsVideo(FILE *file) {
    
    //fseek(file, -2, 1);
    unsigned short num = 0;
    fseek(file, 5, 1);
    //char num1 ;
    fread(&num, sizeof(char),1,file);
    
    std::cout << "VIDEO:"<<std::hex << num << std::endl;
    fseek(file, -8, 1);
    if(num==0xE0)
        return 1;
    
    
    return 0;
}


int TS_FirstFrame(FILE *file) {
    int FirstBit;
    int LastBit;
    FILE *First = file;
    //fseek(First, 376, 0);
    
    unsigned short num;
    unsigned short num1;
    
    unsigned char c;
    
    FILE *test = file;
    
    while (First!=NULL)
    {
        int bitNum = 188;
        
        fread(&num, sizeof(short), 1, First);
        std::cout <<"pes:"<< std::hex << num << std::endl;
        
        if (JudgeBitIsOne((num & 0x4000), 0x4000)) {//判断是否带pes
            
            FILE *PatPmt = First;
            
            if (IsVideo(PatPmt))  //判断是否是视频帧，如果是返回1，不是返回0
            {
                if (IsIDR(PatPmt)) {   //判断是否是IDR，如果是返回1，不是返回0
                    fseek(First, 188, 1);
                    fread(&num, sizeof(short), 1, First);
                    std::cout << std::hex << num << std::endl;
                    
                    while (!JudgeBitIsOne((num & 0x4000), 0x4000))
                    {
                        fseek(First, 188 - sizeof(short), 1);
                        fread(&num, sizeof(short), 1, First);
                        bitNum += 188;
                    }
                    
                    return bitNum;
                }
            }
            else
            {
                fseek(First,188, 1);
                //continue;
            }
        }
        else
        {
            fseek(First, 188-sizeof(short), 1);
        }
    }
    
    return 0;
}

int analyseTS(std::string fileName)
{
    FILE *file = fopen(fileName.c_str(), "rb");
    if (file == NULL) {
        std::cout << "文件打开失败" << std::endl;
        return 0;
    }
    std::cout << "文件打开成功" << std::endl;
    
    int c = TS_FirstFrame(file);
    std::cout << "answer" << std::endl;
    std::cout <<std::dec<<c<< std::endl;
    
    
    return c;
}
