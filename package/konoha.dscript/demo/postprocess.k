
g_ous = new OutputStream(g_path, "a");
g_ous << "task_end:" << $PREPROCESS_DTASK << EOL;
g_ous.close();

ctxid_memcache.delete("\"" + $PREPROCESS_DTASK + '":' + System.getHostName(), 0);

