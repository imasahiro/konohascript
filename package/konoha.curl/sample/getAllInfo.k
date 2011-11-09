/*    try All fields in Curl.getInfo()    */

using konoha.curl.*;

void printAllInfo(Curl c) {
	OUT << "[HEADER_SIZE]        : " << c.getInfo(Curl.INFO_HEADER_SIZE) << EOL;
	OUT << "[REQUEST_SIZE]       : " << c.getInfo(Curl.INFO_REQUEST_SIZE) << EOL;
	OUT << "[REDIRECT_TIME]      : " << c.getInfo(Curl.INFO_REDIRECT_TIME) << EOL;
	OUT << "[TOTAL_TIME]         : " << c.getInfo(Curl.INFO_TOTAL_TIME) << EOL;
	OUT << "[NAMELOOKUP_TIME]    : " << c.getInfo(Curl.INFO_NAMELOOKUP_TIME) << EOL;
	OUT << "[CONNECT_TIME]       : " << c.getInfo(Curl.INFO_CONNECT_TIME) << EOL;
	OUT << "[PRETRANSFER_TIME]   : " << c.getInfo(Curl.INFO_PRETRANSFER_TIME) << EOL;
	OUT << "[STARTTRANSFER_TIME] : " << c.getInfo(Curl.INFO_STARTTRANSFER_TIME) << EOL;
	OUT << "[SIZE_UPLOAD]        : " << c.getInfo(Curl.INFO_SIZE_UPLOAD) << EOL;
	OUT << "[SIZE_DOWNLOAD]      : " << c.getInfo(Curl.INFO_SIZE_DOWNLOAD) << EOL;
	OUT << "[SPEED_UPLOAD]       : " << c.getInfo(Curl.INFO_SPEED_UPLOAD) << EOL;
	OUT << "[SPEED_DOWNLOAD]     : " << c.getInfo(Curl.INFO_SPEED_DOWNLOAD) << EOL;
	OUT << "[EFFECTIVE_URL]      : " << c.getInfo(Curl.INFO_EFFECTIVE_URL) << EOL;
	OUT << "[CONTENT_TYPE]       : " << c.getInfo(Curl.INFO_CONTENT_TYPE) << EOL;
}

void main(String[] args) {
	Curl c = new Curl();
	c.setOpt(Curl.URL, "http://www.google.com");
	c.setOpt(Curl.HTTPGET, "GET");
	c.perform();
	printAllInfo(c);
}
