using konoha.memcached.*;
using konoha.posix.*;

Memcache ctxid_memcache = new Memcache($PREPROCESS_HOST, 11211);
ctxid_memcache.set($PREPROCESS_DTASK + ":" + System.getHostname(), CTX.getTrace(), 0, 0);
String g_path = "/tmp/dtask.log";
OutputStream g_ous = new OutputStream(g_path, "a");
g_ous << "task_start:" << $PREPROCESS_DTASK << EOL;
g_ous.close();



