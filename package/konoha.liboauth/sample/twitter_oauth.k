using konoha.liboauth.*;

String consumer_key      = "your_consumer_key";
String consumer_secret   = "your_consumer_secret";
String request_token_url = "https://api.twitter.com/oauth/request_token";
String authorize_url     = "https://api.twitter.com/oauth/authorize";
String access_token_url  = "https://api.twitter.com/oauth/access_token";

if (consumer_key == "your_consumer_key" || consumer_secret == "your_consumer_secret") {
	OUT << "Please set your consumer_key and consumer_secret before executing ";
	OUT << "this script." << EOL;
	exit(0);
}

// step 1: Make a request from consumer.
Consumer consumer = new Consumer(consumer_key, consumer_secret);
Client client = new Client(consumer);
Map<String,String> ret = client.request(request_token_url, "GET");

OUT << "=== Request Token ==="                                   << EOL;
OUT << "oauth_token: "        + ret["oauth_token"]               << EOL;
OUT << "oauth_token_secret: " + ret["oauth_token_secret"] + "\n" << EOL;

// step 2: Access URL and get a PIN number.
OUT << "Go to the link in your browser: "                          << EOL;
OUT << authorize_url + "?oauth_token=" + ret["oauth_token"] + "\n" << EOL;
String pin = readLine("Input PIN code: ");

// step 3: Make a request from request token and verifier(PIN).
RequestToken rtoken = new RequestToken(ret["oauth_token"], ret["oauth_token_secret"]);
client = new Client(consumer, rtoken);
ret = client.request(access_token_url, "POST", {"oauth_verifier": pin});

OUT << "=== Access Token ===" << EOL;
OUT << "oauth_token: "        + ret["oauth_token"]        << EOL;
OUT << "oauth_token_secret: " + ret["oauth_token_secret"] << EOL;
OUT << "screen_name: "        + ret["screen_name"]        << EOL;
OUT << "user_id: "            + ret["user_id"]            << EOL;
