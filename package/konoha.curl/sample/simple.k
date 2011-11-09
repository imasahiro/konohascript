using konoha.curl.*;

Curl curl = new Curl();
curl.setOpt(Curl.URL, "curl.haxx.se");
curl.perform();
