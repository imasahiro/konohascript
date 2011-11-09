using konoha.curl.*;

String res = "";
Curl curl = new Curl();
curl.setOpt(Curl.URL, "http://www.googel.com");
curl.setOpt(Curl.DATA, res);
curl.perform();
print res;
