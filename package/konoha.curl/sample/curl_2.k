/*
 * package curl sample file
 *
 */

using konoha.curl.*;
boolean ret;
OutputStream o = new OutputStream("a.png","w");
Curl c = new Curl();
c.setOpt(Curl.URL,"http://www.google.co.jp/images/nav_logo4.png");
c.setOpt(Curl.FILE,o);
ret = c.perform();
if ( ret ) {
	OUT << "[CURLINFO]" << EOL;
	OUT << "  REQUEST_SIZE   : " << c.getInfo(Curl.INFO_REQUEST_SIZE) << EOL;
	OUT << "  SIZE_DOWNLOAD  : " << c.getInfo(Curl.INFO_SIZE_DOWNLOAD) << EOL;
	OUT << "  SPEED_DOWNLOAD : " << c.getInfo(Curl.INFO_SPEED_DOWNLOAD) << EOL;
	OUT << "  CONTENT_TYPE   : " << c.getInfo(Curl.INFO_CONTENT_TYPE) << EOL;
}
o.close();
