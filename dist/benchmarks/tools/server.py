import SimpleHTTPServer
import BaseHTTPServer
import os
import cgi
import datetime

class myHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
    def do_GET(self):
        if not self.path == '/':
            return SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self)
        self.send_response(200)
        self.end_headers()
        html = '''
<!DOCTYPE html><html><head>
<title>Konoha Benchmark Queue System</title>
</head><body>
<h1>Konoha Benchmark Queue System</h1>
<h2>Push Task</h2>
<form method="post" action="/">
<input name="e" type="text" placeholder="email">
<input name="g" type="text" placeholder="git://">
<input name="b" type="text" placeholder="BranchName">
<button type="submit">Push</button>
</form>
<h2>Current Queue</h2>
<table border="1">
<tr><th>Date</th><th>URL</th><th>Branch</th><th>User</th><th>Status</th></tr>
'''
        q = '';
        for line in open('KONOHA_BENCH_CURRENT'):
            data = '<tr><th>' + line.replace(',', '</th><th>') + '</th><th>CURRENT</th></tr>\n';
            q = data;
        for line in open('KONOHA_BENCH_QUEUE'):
            data = '<tr><td>' + line.replace(',', '</td><td>') + '</td><td>STOP</td></tr>\n';
            q = q + data;
        q = q + '</table>'
        log = '<h2>Benchmark Log</h2>\n';
        for f in os.listdir("."):
            if f.endswith('.csv') :
                log = log + '<a href="' + f + '">' + f + '</a><br/>\n';
        self.wfile.write(html + q + log + "</body></html>")

    def do_POST(self):
        form = cgi.FieldStorage(
            fp=self.rfile, 
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST',
                     'CONTENT_TYPE':self.headers['Content-Type'],
                     })
        self.send_response(200)
        self.send_header("Content-Type", "text/html")
        self.end_headers()
        self.wfile.write('<html><body>Job added<br/><a herf="/">HOME</a><br/>')
        for field in form.keys():
            self.wfile.write('\t%s=%s\n<br/>' % (field, form[field].value))
        self.wfile.write('</body></html>')
        v = ''
        g = form['g'].value;
        b = form['b'].value;
        e = form['e'].value;

        d = datetime.datetime.now()
        v = "%04d-%02d-%02dT%02d:%02d:%02d%+02d:%02d" % (d.year, d.month, d.day, d.hour, d.minute, d.second, 0, 9)
        v = v + ',' + g + ',' + b + ',' + e + '\n';
        f = open('KONOHA_BENCH_QUEUE', 'a')
        f.write(v)
        f.close()
        return

def check_file(filename):
    try:
        f = open(filename, 'r');
        f.close()
    except IOError:
        fw = open(filename, 'w');
        fw.close()

check_file('KONOHA_BENCH_QUEUE');
check_file('KONOHA_BENCH_CURRENT');
BaseHTTPServer.HTTPServer(('', 10080), myHandler).serve_forever()
