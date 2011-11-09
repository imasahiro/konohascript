using konoha.curl.*;

string filename = "curl-7.9.2.tar.gz";
OutputStream ous = new OutputStream(filename, "w");
Curl curl = new Curl();
curl.setOpt(Curl.URL, "ftp://ftp.sunet.se/pub/www/utilities/curl/" + filename);
curl.setOpt(Curl.POST, true);
curl.setOpt(Curl.FILE, ous);
curl.setOpt(Curl.VERBOSE, true);
curl.perform();
