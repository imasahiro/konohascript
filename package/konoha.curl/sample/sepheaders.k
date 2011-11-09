using konoha.curl.*;

OutputStream ous = new OutputStream("./tmp", "w");
Curl c = new Curl();
c.setOpt(Curl.URL, "http://curl.haxx.se");
c.setOpt(Curl.NOPROGRESS, true);
c.setOpt(Curl.WRITEHEADER, ous);
c.perform();
