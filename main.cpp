//
//  main.cpp
//  Http_Client
//
//  Created by afk on 2019/7/11.
//  Copyright © 2019年 mgc. All rights reserved.
//

#include <iostream>
//#include "http_client.hpp"
#include "test.hpp"
#include "http_client.hpp"
#include "Read_M3U8.hpp"
//


int main(int argc, const char * argv[]) {
    // insert code here...
    
//    function1("/Users/afk/1.mp4", 0, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function2("/Users/afk/1.mp4", 2048, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function3("/Users/afk/1.mp4",6293504, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function4("/Users/afk/1.mp4", 2049, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function5("/Users/afk/1.mp4", 2049, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function6("/Users/afk/1.mp4", 2048, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function7("/Users/afk/1.mp4",4096, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function8("/Users/afk/1.mp4", 0, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function9("/Users/afk/1.mp4", 0, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //function10("/Users/afk/1.mp4", 0, "/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/2.mp4","/Users/afk/test/urltest/test/head","http://127.0.0.1:9876/"," http://117.131.17.227:40000/_uploads/videos/huanglesong.mp4 HTTP/1.1 \r\n","Host: 117.131.17.227:40000");
    //http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5102/992/285/5102992285/media/5102992285_5007549535_455.mp4.m3u8?msisdn=15021885880&mdspid=&spid=800033&netType=4&sid=5501110683&pid=2028597139&timestamp=20200513091618&Channel_ID=0116_2500070200-99000-200300240100002&ProgramID=676230163&ParentNodeID=-99&assertID=5501110683&client_ip=221.181.101.37&SecurityKey=20200513091618&imei=862853039888085&promotionId=&mvid=5102992285&mcid=1001&mpid=130000118051&playurlVersion=WX-A1-0.0.3&userid=1099927003&jmhm=15021885880&videocodec=h264&encrypt=ae052900f8b05fe98db03e2c80772097&jid=16BC3883EA089D148C5A88079248DD531589332629641V&is_advertise=0&sjid=subsession_1589332630176
    //http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5102/992/285/5102992285/media/5102992285_5007549666_95.mg001.mp4.m3u8?msisdn=15021885880&mdspid=&spid=800033&netType=4&sid=5501110683&pid=2028597139&timestamp=20200513135229&Channel_ID=0116_2500070200-99000-200300240100002&ProgramID=676230163&ParentNodeID=-99&assertID=5501110683&client_ip=221.181.101.37&SecurityKey=20200513135229&imei=862853039888085&promotionId=b8375fe2-be74-4c66-a2aa-f86fbd62f7de&mvid=5102992285&mcid=1001&mpid=130000118051&playurlVersion=WX-A1-0.0.3&userid=1099927003&jmhm=15021885880&videocodec=h265&encrypt=28dc24d5076eb86b6214a64fcc1cc957&jid=16BC3883EA089D148C5A88079248DD531589349148573V&is_advertise=0&sjid=subsession_1589349150582
    
    ///http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/3002/175/833/3002175833/media/3002175833_5006185389_594.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600239&netType=4&sid=3002175841&pid=2028597139&timestamp=20200513164059&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=664299248&ParentNodeID=-99&assertID=3002175841&client_ip=221.181.101.37&SecurityKey=20200513164059&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=3002175833&mcid=1000&mpid=130000009086&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h265&encrypt=a303f3c664653147a6df2bc8077df462
    
    
    //http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/3002/175/833/3002175833/media/3002175833_5007614359_180.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600239&netType=4&sid=3002175841&pid=2028597139&timestamp=20200513164059&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=664299248&ParentNodeID=-99&assertID=3002175841&client_ip=221.181.101.37&SecurityKey=20200513164059&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=3002175833&mcid=1000&mpid=130000009086&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=&encrypt=2fa79711df4e15d64f4e66072fcb1785

    ////HTTP/1.1 660
    
    ////http://gslbdzmmgspvod.miguvideo.com/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761_1015006397_356.m3u8?msisdn=15206112939&mdspid=&spid=800033&netType=4&sid=1502878475&pid=2028597139&timestamp=20200513165045&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=657703197&ParentNodeID=-99&assertID=1502878475&client_ip=221.181.101.37&SecurityKey=20200513165045&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=1003538761&mcid=1000&mpid=130000014492&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h264&encrypt=600c88c64353fbdc7e88aba6d3e2af6c
    
    
    ///http://gslbdzmmgspvod.miguvideo.com/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761_1015006397_356.m3u8?msisdn=15206112939&mdspid=&spid=800033&netType=4&sid=1502878475&pid=2028597139&timestamp=20200513211245&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=657703197&ParentNodeID=-99&assertID=1502878475&client_ip=221.181.101.37&SecurityKey=20200513211245&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=1003538761&mcid=1000&mpid=130000014492&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h264&encrypt=a00afe8de95c272ad1f18d1568525341
    
    ///多音轨多字幕
    //http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/video/video.m3u8
   // http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/audio/eng/index.m3u8
   // http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/audio/italy/index.m3u8
   // http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/subtitles/chi/index.m3u8
   // http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/subtitles/eng/index.m3u8
    //void function (std::string fileString,std::string headString,std::string url,std::string dstUrl,std::string dstPort)
    
    ///http://dzmmgspvod.miguvideo.com:80/depository_sjq/asset/zhengshi/1003/538/761/1003538761/media/1003538761sim356hls_20190611213940/audio/eng/out_10.ts
    
    ///http://gslbmgspvod.miguvideo.com/depository_yqv/asset/zhengshi/3002/175/833/3002175833/media/3002175833_5007614359_180.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600239&netType=4&sid=3002175841&pid=2028597139&timestamp=20200514185031&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=664299248&ParentNodeID=-99&assertID=3002175841&client_ip=221.181.101.37&SecurityKey=20200514185031&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=3002175833&mcid=1000&mpid=130000009086&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=&encrypt=136cbb01fd9b6ec91eb6942186ae2aed
    
    
    ///"http://gslbmgspvod.miguvideo.com/depository_yqv/asset/zhengshi/5101/131/546/5101131546/media/5101131546_5007638811_95.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600058&netType=4&sid=5500422775&pid=2028600738&timestamp=20200515091352&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=650018525&ParentNodeID=-99&assertID=5500422775&client_ip=221.181.101.37&SecurityKey=20200515091352&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=5101131546&mcid=1000&mpid=130000062083&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h265&encrypt=c631de9a6bd04850f5987bd8b263b913  h265
    
    ////http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5101/131/546/5101131546/media/5101131546_5007638811_95.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600058&netType=4&sid=5500422775&pid=2028600738&timestamp=20200515091352&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=650018525&ParentNodeID=-99&assertID=5500422775&client_ip=221.181.101.37&SecurityKey=20200515091352&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=4A16FD2D-965D-41B0-8FBE-CFAA796B3628&mvid=5101131546&mcid=1000&mpid=130000062083&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h265&encrypt=c631de9a6bd04850f5987bd8b263b913
    
    ///http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5102/934/744/5102934744/media/5102934744_5007311425_594.mg001.mp4.m3u8?msisdn=15021885880&mdspid=&spid=600463&netType=4&sid=5501093915&pid=2028597139&timestamp=20200515171050&Channel_ID=0116_2500070200-99000-200300240100002&ProgramID=674358658&ParentNodeID=-99&assertID=5501093915&client_ip=221.181.101.37&SecurityKey=20200515171050&imei=862853039888085&promotionId=8cfd0c08-9e3b-478e-939f-46e6ee9c2f49&mvid=5102934744&mcid=1001&mpid=130000138348&playurlVersion=WX-A1-0.0.3&userid=1099927003&jmhm=15021885880&videocodec=h265&encrypt=7c1108ed7dcd1ac598320227f67e582f&jid=16BC3883EA089D148C5A88079248DD531589533848093Q&sjid=subsession_1589533849348
    
    ///"http://gslbmgspvod.miguvideo.com/depository_yqv/asset/zhengshi/1004/943/156/1004943156/media/1004943156_1028554556_455.mp4?msisdn=15206112939&mdspid=&spid=800033&netType=4&sid=1504242012&pid=2028597139&timestamp=20200518153608&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=676486112&ParentNodeID=-99&assertID=1504242012&client_ip=221.181.101.37&SecurityKey=20200518153608&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=6DB43CA2-B1EA-4BFB-BBBE-E01D10E43169&mvid=1004943156&mcid=1000&mpid=130000007333&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h264&encrypt=b165f0eeedc1b2f29db5498d30b8d472
    
    
    
   /// http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/1004/943/156/1004943156/media/1004943156_1028554556_455.mp4?msisdn=15206112939&mdspid=&spid=800033&netType=4&sid=1504242012&pid=2028597139&timestamp=20200518153608&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=676486112&ParentNodeID=-99&assertID=1504242012&client_ip=221.181.101.37&SecurityKey=20200518153608&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=6DB43CA2-B1EA-4BFB-BBBE-E01D10E43169&mvid=1004943156&mcid=1000&mpid=130000007333&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h264&encrypt=b165f0eeedc1b2f29db5498d30b8d472
    
    ///http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/1004/943/156/1004943156/media/1004943156_1028554556_455.mp4?msisdn=15206112939&mdspid=&spid=800033&netType=4&sid=1504242012&pid=2028597139&timestamp=20200518153608&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=676486112&ParentNodeID=-99&assertID=1504242012&client_ip=221.181.101.37&SecurityKey=20200518153608&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=6DB43CA2-B1EA-4BFB-BBBE-E01D10E43169&mvid=1004943156&mcid=1000&mpid=130000007333&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h264&encrypt=b165f0eeedc1b2f29db5498d30b8d472
    
    ///http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5102/736/121/5102736121/media/5102736121_5006850685_95.mg001.mp4.m3u8?msisdn=15021885880&mdspid=&spid=800033&netType=4&sid=5500981756&pid=2028597139&timestamp=20200525181806&Channel_ID=0116_2500070200-99000-200300240100002&ProgramID=667433316&ParentNodeID=-99&assertID=5500981756&client_ip=221.181.101.37&SecurityKey=20200525181806&imei=865392044235393&promotionId=31fb5549-9589-45b6-a096-87997d14b3df&mvid=5102736121&mcid=1001&mpid=130000061996&playurlVersion=WX-A1-0.0.3&userid=1099927003&jmhm=15021885880&videocodec=h265&encrypt=66e24add6e29c51d87d25dcf5cb6c4e3&jid=2A5E1C1C7A94DF7BA4FCFB594D7C9D071590401886103V&is_advertise=0&sjid=subsession_1590401887234
    
    ///http://hlsmgspvod.miguvideo.com:8080/depository_yqv/asset/zhengshi/5101/131/546/5101131546/media/5101131546_5007638931_180.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600058&netType=4&sid=5500422775&pid=2028600738&timestamp=20200604092622&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=650018525&ParentNodeID=-99&assertID=5500422775&client_ip=221.181.101.37&SecurityKey=20200604092622&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=6DB43CA2-B1EA-4BFB-BBBE-E01D10E43169&mvid=5101131546&mcid=1000&mpid=130000062083&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=&encrypt=61bc32e999e7e7e1aa779a8b09d93dc2
    
    
    
    function("/Users/afk/test/urltest/1/db.m3u8","/Users/afk/test/urltest/1/head","http://hlsmgspvod.miguvideo.com","/depository_yqv/asset/zhengshi/5101/131/546/5101131546/media/5101131546_5007668524_96.mg001.mp4.m3u8?msisdn=15206112939&mdspid=&spid=600058&netType=4&sid=5500422775&pid=2028600738&timestamp=20200604092622&Channel_ID=0116_2504070200-99000-200300020100001&ProgramID=650018525&ParentNodeID=-99&assertID=5500422775&client_ip=221.181.101.37&SecurityKey=20200604092622&imei=B600A9EF-1E04-4D8B-ABB5-4903EC626EF1&promotionId=6DB43CA2-B1EA-4BFB-BBBE-E01D10E43169&mvid=5101131546&mcid=1000&mpid=130000062083&playurlVersion=WX-A1-0.0.3&userid=335266594&jmhm=15206112939&videocodec=h265&encrypt=1f171523fa2bb788164e2171f833f628","Host: hlsmgspvod.miguvideo.com:8080");
    
    return 0;
   
}
