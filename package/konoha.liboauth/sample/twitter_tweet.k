using konoha.liboauth.*;

String update_url          = "http://api.twitter.com/1/statuses/update.json";
String consumer_key        = "your_consumer_key";
String consumer_secret     = "your_consumer_secret";
String access_token        = "your_access_token";
String access_token_secret = "your_access_token_secret";

String message = readLine("Input your message (up to 140 characters): ");
Consumer consumer = new Consumer(consumer_key, consumer_secret);
RequestToken rtoken = new RequestToken(access_token, access_token_secret);
Client client = new Client(consumer, rtoken);
Map<String,String> ret = client.request(update_url, "POST", {"status": message});
