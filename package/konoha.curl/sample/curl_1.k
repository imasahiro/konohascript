/*
 * package curl sample file
 *
 */
using konoha.curl.*;

Curl c = new Curl();
//c.setOpt(Curl.URL,"http://sourceforge.jp/projects/konoha/");
c.setOpt(Curl.URL,"http://localhost");
c.perform();
