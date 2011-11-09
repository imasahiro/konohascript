using konoha.curl.*;

void main (String[] args)
{
	o = new OutputStream("./tmp");
	Curl c = new Curl();
	c.setOpt(Curl.URL,"http://sourceforge.jp/projects/konoha/");
	c.setOpt(Curl.FILE, o);
	res = c.perform();
	OUT << res << EOL;
}
