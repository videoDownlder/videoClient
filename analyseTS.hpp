

#ifndef analyseTS_hpp
#define analyseTS_hpp

#include <stdio.h>

#include<iostream>

bool JudgeBitIsOne(unsigned short ucData, unsigned short ucFlag);

bool IsIDR(FILE *file) ;
bool IsVideo(FILE *file) ;
int TS_FirstFrame(FILE *file) ;
int analyseTS(std::string fileName);

#endif /* analyseTS_hpp */
