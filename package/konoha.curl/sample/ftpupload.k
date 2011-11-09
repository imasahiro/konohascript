using konoha.curl.*;

OutputStream ous = new OutputStream(file, "r");
string file = "tmp";
string url = "ftp://username:password@hogehoge.com/" + file;
Curl curl = new Curl();
curl.setOpt(Curl.UPLOAD, true);
curl.setOpt(Curl.URL, url);
curl.setOpt(Curl.INFILE, ous);
curl.perform();
