
#include "test.hpp"
#include "Read_M3U8.hpp"
#include "analyseTS.hpp"




void function(std::string File, std::string Position , std::string url ) {
	
	
	std::string M3u8FilePosition=Position+File+".m3u8";
	std::string M3u8HeadPosition = Position+File+"_head.txt";
	std::string M3u8FileName = "/" + File + ".m3u8";

	mgc::proxy::HttpClient *http = mgc::proxy::HttpClient::getInstance();

	
	std::string strBytes = "0-";
	if (http->httpGet(url, strBytes, M3u8FilePosition, M3u8HeadPosition, M3u8FileName))
	{
		
	}
	else
		std::cout << "error" << std::endl;


	// std::string TS_URL= Read(fileString,dstUrl);
	std::vector<std::string> TS_Name = Read(M3u8FilePosition, M3u8FileName);

	std::string TsFilePosition, TSHeadPosition;


	TSHeadPosition = Position + File + "_ts.txt";


	for (int i = 0; i < TS_Name.size(); i++) {
		// TS_file="/Users/afk/test/urltest/test-subtitles/video/";	
		TS_Name[i] = TS_Name[i].substr(0, TS_Name[i].find(".ts") + 3);
		TsFilePosition = Position + TS_Name[i];
		// TS_file=fileString.append(".ts");
		if (http->httpGet(url, strBytes, TsFilePosition, TSHeadPosition, TS_Name[i]))
		{
			//std::cout << return_msg <<std::endl;
		}
		else
			std::cout << "error" << std::endl;
	}


	return;
}