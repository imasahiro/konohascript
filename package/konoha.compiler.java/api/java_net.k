/* converted from java package java.net */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_io_IOException;
class Java_io_InputStream;
class Java_io_InterruptedIOException;
class Java_io_OutputStream;
class Java_lang_ClassLoader;
class Java_lang_Enum;
class Java_lang_Exception;
class Java_net_Authenticator_RequestorType;
class Java_net_Proxy_Type;
class Java_nio_channels_DatagramChannel;
class Java_nio_channels_ServerSocketChannel;
class Java_nio_channels_SocketChannel;
class Java_security_BasicPermission;
class Java_security_Permission;
class Java_security_Principal;
class Java_security_SecureClassLoader;
class Java_security_cert_Certificate;
class Java_util_Enumeration;
class Java_util_List;
class Java_util_Map;
class Java_util_jar_Attributes;
class Java_util_jar_JarEntry;
class Java_util_jar_JarFile;
class Java_util_jar_Manifest;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_net_Authenticator;
class Java_net_SocketException extends Java_io_IOException;
class Java_net_BindException extends Java_net_SocketException;
class Java_net_CacheRequest;
class Java_net_CacheResponse;
class Java_net_ConnectException extends Java_net_SocketException;
class Java_net_ContentHandler;
class Java_net_ContentHandlerFactory;
class Java_net_CookieHandler;
class Java_net_CookieManager extends Java_net_CookieHandler;
class Java_net_CookiePolicy;
class Java_net_CookieStore;
class Java_net_DatagramPacket;
class Java_net_DatagramSocket;
class Java_net_DatagramSocketImpl;
class Java_net_DatagramSocketImplFactory;
class Java_net_FileNameMap;
class Java_net_HttpCookie;
class Java_net_HttpRetryException extends Java_io_IOException;
class Java_net_URLConnection;
class Java_net_HttpURLConnection extends Java_net_URLConnection;
class Java_net_IDN;
class Java_net_InetAddress;
class Java_net_Inet4Address extends Java_net_InetAddress;
class Java_net_Inet6Address extends Java_net_InetAddress;
class Java_net_SocketAddress;
class Java_net_InetSocketAddress extends Java_net_SocketAddress;
class Java_net_InterfaceAddress;
class Java_net_JarURLConnection extends Java_net_URLConnection;
class Java_net_MalformedURLException extends Java_io_IOException;
class Java_net_MulticastSocket extends Java_net_DatagramSocket;
class Java_net_NetPermission extends Java_security_BasicPermission;
class Java_net_NetworkInterface;
class Java_net_NoRouteToHostException extends Java_net_SocketException;
class Java_net_PasswordAuthentication;
class Java_net_PortUnreachableException extends Java_net_SocketException;
class Java_net_ProtocolException extends Java_io_IOException;
class Java_net_ProtocolFamily;
class Java_net_Proxy;
class Java_net_ProxySelector;
class Java_net_ResponseCache;
class Java_net_SecureCacheResponse extends Java_net_CacheResponse;
class Java_net_ServerSocket;
class Java_net_Socket;
class Java_net_SocketImpl;
class Java_net_SocketImplFactory;
class Java_net_SocketOption;
class Java_net_SocketOptions;
class Java_net_SocketPermission extends Java_security_Permission;
class Java_net_SocketTimeoutException extends Java_io_InterruptedIOException;
class Java_net_StandardProtocolFamily extends Java_lang_Enum;
class Java_net_StandardSocketOptions;
class Java_net_URI;
class Java_net_URISyntaxException extends Java_lang_Exception;
class Java_net_URL;
class Java_net_URLClassLoader extends Java_security_SecureClassLoader;
class Java_net_URLDecoder;
class Java_net_URLEncoder;
class Java_net_URLStreamHandler;
class Java_net_URLStreamHandlerFactory;
class Java_net_UnknownHostException extends Java_io_IOException;
class Java_net_UnknownServiceException extends Java_io_IOException;

/*------------------------------------------------------------*/
/* class java.net.Authenticator */
class Java_net_Authenticator {
	/*-- Method --*/
	@Virtual @Overload Java_net_PasswordAuthentication requestPasswordAuthentication(Java_net_InetAddress p0, int p1, String p2, String p3, String p4);
	@Virtual @Overload Java_net_PasswordAuthentication requestPasswordAuthentication(String p0, Java_net_InetAddress p1, int p2, String p3, String p4, String p5);
	@Virtual @Overload Java_net_PasswordAuthentication requestPasswordAuthentication(String p0, Java_net_InetAddress p1, int p2, String p3, String p4, String p5, Java_net_URL p6, Java_net_Authenticator_RequestorType p7);
	@Virtual @Overload void setDefault(Java_net_Authenticator p0);
}
Java_net_Authenticator Java_net_Authenticator.new();
/* class java.net.BindException */
class Java_net_BindException extends Java_net_SocketException {
}
@Overload Java_net_BindException Java_net_BindException.new(String p0);
@Overload Java_net_BindException Java_net_BindException.new();
/* class java.net.CacheRequest */
class Java_net_CacheRequest {
	/*-- Method --*/
	@Virtual @Overload void abort();
	@Virtual @Overload Java_io_OutputStream getBody();
}
Java_net_CacheRequest Java_net_CacheRequest.new();
/* class java.net.CacheResponse */
class Java_net_CacheResponse {
	/*-- Method --*/
	@Virtual @Overload Java_io_InputStream getBody();
	@Virtual @Overload Java_util_Map getHeaders();
}
Java_net_CacheResponse Java_net_CacheResponse.new();
/* class java.net.ConnectException */
class Java_net_ConnectException extends Java_net_SocketException {
}
@Overload Java_net_ConnectException Java_net_ConnectException.new(String p0);
@Overload Java_net_ConnectException Java_net_ConnectException.new();
/* class java.net.ContentHandler */
class Java_net_ContentHandler {
	/*-- Method --*/
	@Virtual @Overload Object getContent(Java_net_URLConnection p0);
	@Virtual @Overload Object getContent(Java_net_URLConnection p0, Class[] p1);
}
Java_net_ContentHandler Java_net_ContentHandler.new();
/* interface java.net.ContentHandlerFactory */
class Java_net_ContentHandlerFactory {
	/*-- Method --*/
	@Virtual @Overload Java_net_ContentHandler createContentHandler(String p0);
}
/* class java.net.CookieHandler */
class Java_net_CookieHandler {
	/*-- Method --*/
	@Virtual @Overload Java_util_Map get(Java_net_URI p0, Java_util_Map p1);
	@Virtual @Overload Java_net_CookieHandler getDefault();
	@Virtual @Overload void put(Java_net_URI p0, Java_util_Map p1);
	@Virtual @Overload void setDefault(Java_net_CookieHandler p0);
}
Java_net_CookieHandler Java_net_CookieHandler.new();
/* class java.net.CookieManager */
class Java_net_CookieManager extends Java_net_CookieHandler {
	/*-- Method --*/
	@Virtual @Overload Java_net_CookieStore getCookieStore();
	@Virtual @Overload void setCookiePolicy(Java_net_CookiePolicy p0);
}
@Overload Java_net_CookieManager Java_net_CookieManager.new();
@Overload Java_net_CookieManager Java_net_CookieManager.new(Java_net_CookieStore p0, Java_net_CookiePolicy p1);
/* interface java.net.CookiePolicy */
class Java_net_CookiePolicy {
	/*-- Method --*/
	@Virtual @Overload boolean shouldAccept(Java_net_URI p0, Java_net_HttpCookie p1);
}
/* interface java.net.CookieStore */
class Java_net_CookieStore {
	/*-- Method --*/
	@Virtual @Overload void add(Java_net_URI p0, Java_net_HttpCookie p1);
	@Virtual @Overload Java_util_List get(Java_net_URI p0);
	@Virtual @Overload Java_util_List getCookies();
	@Virtual @Overload Java_util_List getURIs();
	@Virtual @Overload boolean remove(Java_net_URI p0, Java_net_HttpCookie p1);
	@Virtual @Overload boolean removeAll();
}
/* class java.net.DatagramPacket */
class Java_net_DatagramPacket {
	/*-- Method --*/
	@Virtual @Overload Java_net_InetAddress getAddress();
	@Virtual @Overload int[] getData();
	@Virtual @Overload int getLength();
	@Virtual @Overload int getOffset();
	@Virtual @Overload int getPort();
	@Virtual @Overload Java_net_SocketAddress getSocketAddress();
	@Virtual @Overload void setAddress(Java_net_InetAddress p0);
	@Virtual @Overload void setData(int[] p0, int p1, int p2);
	@Virtual @Overload void setData(int[] p0);
	@Virtual @Overload void setLength(int p0);
	@Virtual @Overload void setPort(int p0);
	@Virtual @Overload void setSocketAddress(Java_net_SocketAddress p0);
}
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1, int p2);
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1);
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1, int p2, Java_net_InetAddress p3, int p4);
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1, int p2, Java_net_SocketAddress p3);
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1, Java_net_InetAddress p2, int p3);
@Overload Java_net_DatagramPacket Java_net_DatagramPacket.new(int[] p0, int p1, Java_net_SocketAddress p2);
/* class java.net.DatagramSocket */
class Java_net_DatagramSocket {
	/*-- Method --*/
	@Virtual @Overload void bind(Java_net_SocketAddress p0);
	@Virtual @Overload void close();
	@Virtual @Overload void connect(Java_net_InetAddress p0, int p1);
	@Virtual @Overload void connect(Java_net_SocketAddress p0);
	@Virtual @Overload void disconnect();
	@Virtual @Overload boolean getBroadcast();
	@Virtual @Overload Java_nio_channels_DatagramChannel getChannel();
	@Virtual @Overload Java_net_InetAddress getInetAddress();
	@Virtual @Overload Java_net_InetAddress getLocalAddress();
	@Virtual @Overload int getLocalPort();
	@Virtual @Overload Java_net_SocketAddress getLocalSocketAddress();
	@Virtual @Overload int getPort();
	@Virtual @Overload int getReceiveBufferSize();
	@Virtual @Overload Java_net_SocketAddress getRemoteSocketAddress();
	@Virtual @Overload boolean getReuseAddress();
	@Virtual @Overload int getSendBufferSize();
	@Virtual @Overload int getSoTimeout();
	@Virtual @Overload int getTrafficClass();
	@Virtual @Overload boolean isBound();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload boolean isConnected();
	@Virtual @Overload void receive(Java_net_DatagramPacket p0);
	@Virtual @Overload void send(Java_net_DatagramPacket p0);
	@Virtual @Overload void setBroadcast(boolean p0);
	@Virtual @Overload void setDatagramSocketImplFactory(Java_net_DatagramSocketImplFactory p0);
	@Virtual @Overload void setReceiveBufferSize(int p0);
	@Virtual @Overload void setReuseAddress(boolean p0);
	@Virtual @Overload void setSendBufferSize(int p0);
	@Virtual @Overload void setSoTimeout(int p0);
	@Virtual @Overload void setTrafficClass(int p0);
}
@Overload Java_net_DatagramSocket Java_net_DatagramSocket.new();
@Overload Java_net_DatagramSocket Java_net_DatagramSocket.new(Java_net_SocketAddress p0);
@Overload Java_net_DatagramSocket Java_net_DatagramSocket.new(int p0);
@Overload Java_net_DatagramSocket Java_net_DatagramSocket.new(int p0, Java_net_InetAddress p1);
/* class java.net.DatagramSocketImpl */
class Java_net_DatagramSocketImpl {
}
Java_net_DatagramSocketImpl Java_net_DatagramSocketImpl.new();
/* interface java.net.DatagramSocketImplFactory */
class Java_net_DatagramSocketImplFactory {
	/*-- Method --*/
	@Virtual @Overload Java_net_DatagramSocketImpl createDatagramSocketImpl();
}
/* interface java.net.FileNameMap */
class Java_net_FileNameMap {
	/*-- Method --*/
	@Virtual @Overload String getContentTypeFor(String p0);
}
/* class java.net.HttpCookie */
class Java_net_HttpCookie {
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean domainMatches(String p0, String p1);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload String getComment();
	@Virtual @Overload String getCommentURL();
	@Virtual @Overload boolean getDiscard();
	@Virtual @Overload String getDomain();
	@Virtual @Overload long getMaxAge();
	@Virtual @Overload String getName();
	@Virtual @Overload String getPath();
	@Virtual @Overload String getPortlist();
	@Virtual @Overload boolean getSecure();
	@Virtual @Overload String getValue();
	@Virtual @Overload int getVersion();
	@Virtual @Overload boolean hasExpired();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isHttpOnly();
	@Virtual @Overload Java_util_List parse(String p0);
	@Virtual @Overload void setComment(String p0);
	@Virtual @Overload void setCommentURL(String p0);
	@Virtual @Overload void setDiscard(boolean p0);
	@Virtual @Overload void setDomain(String p0);
	@Virtual @Overload void setHttpOnly(boolean p0);
	@Virtual @Overload void setMaxAge(long p0);
	@Virtual @Overload void setPath(String p0);
	@Virtual @Overload void setPortlist(String p0);
	@Virtual @Overload void setSecure(boolean p0);
	@Virtual @Overload void setValue(String p0);
	@Virtual @Overload void setVersion(int p0);
	@Virtual @Overload String toString();
}
Java_net_HttpCookie Java_net_HttpCookie.new(String p0, String p1);
/* class java.net.HttpRetryException */
class Java_net_HttpRetryException extends Java_io_IOException {
	/*-- Method --*/
	@Virtual @Overload String getLocation();
	@Virtual @Overload String getReason();
	@Virtual @Overload int responseCode();
}
@Overload Java_net_HttpRetryException Java_net_HttpRetryException.new(String p0, int p1);
@Overload Java_net_HttpRetryException Java_net_HttpRetryException.new(String p0, int p1, String p2);
/* class java.net.HttpURLConnection */
class Java_net_HttpURLConnection extends Java_net_URLConnection {
	/*-- Method --*/
	@Virtual @Overload void disconnect();
	@Virtual @Overload Java_io_InputStream getErrorStream();
	@Virtual @Overload boolean getFollowRedirects();
	@Virtual @Overload boolean getInstanceFollowRedirects();
	@Virtual @Overload String getRequestMethod();
	@Virtual @Overload int getResponseCode();
	@Virtual @Overload String getResponseMessage();
	@Virtual @Overload void setChunkedStreamingMode(int p0);
	@Virtual @Overload void setFixedLengthStreamingMode(int p0);
	@Virtual @Overload void setFixedLengthStreamingMode(long p0);
	@Virtual @Overload void setFollowRedirects(boolean p0);
	@Virtual @Overload void setInstanceFollowRedirects(boolean p0);
	@Virtual @Overload void setRequestMethod(String p0);
	@Virtual @Overload boolean usingProxy();
}
/* class java.net.IDN */
class Java_net_IDN {
	/*-- Method --*/
	@Virtual @Overload String toASCII(String p0, int p1);
	@Virtual @Overload String toASCII(String p0);
	@Virtual @Overload String toUnicode(String p0, int p1);
	@Virtual @Overload String toUnicode(String p0);
}
/* class java.net.Inet4Address */
class Java_net_Inet4Address extends Java_net_InetAddress {
}
/* class java.net.Inet6Address */
class Java_net_Inet6Address extends Java_net_InetAddress {
	/*-- Method --*/
	@Virtual @Overload Java_net_Inet6Address getByAddress(String p0, int[] p1, Java_net_NetworkInterface p2);
	@Virtual @Overload Java_net_Inet6Address getByAddress(String p0, int[] p1, int p2);
	@Virtual @Overload int getScopeId();
	@Virtual @Overload Java_net_NetworkInterface getScopedInterface();
	@Virtual @Overload boolean isIPv4CompatibleAddress();
}
/* class java.net.InetAddress */
class Java_net_InetAddress {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int[] getAddress();
	@Virtual @Overload Java_net_InetAddress[] getAllByName(String p0);
	@Virtual @Overload Java_net_InetAddress getByAddress(String p0, int[] p1);
	@Virtual @Overload Java_net_InetAddress getByAddress(int[] p0);
	@Virtual @Overload Java_net_InetAddress getByName(String p0);
	@Virtual @Overload String getCanonicalHostName();
	@Virtual @Overload String getHostAddress();
	@Virtual @Overload String getHostName();
	@Virtual @Overload Java_net_InetAddress getLocalHost();
	@Virtual @Overload Java_net_InetAddress getLoopbackAddress();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isAnyLocalAddress();
	@Virtual @Overload boolean isLinkLocalAddress();
	@Virtual @Overload boolean isLoopbackAddress();
	@Virtual @Overload boolean isMCGlobal();
	@Virtual @Overload boolean isMCLinkLocal();
	@Virtual @Overload boolean isMCNodeLocal();
	@Virtual @Overload boolean isMCOrgLocal();
	@Virtual @Overload boolean isMCSiteLocal();
	@Virtual @Overload boolean isMulticastAddress();
	@Virtual @Overload boolean isReachable(int p0);
	@Virtual @Overload boolean isReachable(Java_net_NetworkInterface p0, int p1, int p2);
	@Virtual @Overload boolean isSiteLocalAddress();
	@Virtual @Overload String toString();
}
/* class java.net.InetSocketAddress */
class Java_net_InetSocketAddress extends Java_net_SocketAddress {
	/*-- Method --*/
	@Virtual @Overload Java_net_InetSocketAddress createUnresolved(String p0, int p1);
	@Virtual @Overload Java_net_InetAddress getAddress();
	@Virtual @Overload String getHostName();
	@Virtual @Overload String getHostString();
	@Virtual @Overload int getPort();
	@Virtual @Overload boolean isUnresolved();
}
@Overload Java_net_InetSocketAddress Java_net_InetSocketAddress.new(int p0);
@Overload Java_net_InetSocketAddress Java_net_InetSocketAddress.new(Java_net_InetAddress p0, int p1);
@Overload Java_net_InetSocketAddress Java_net_InetSocketAddress.new(String p0, int p1);
/* class java.net.InterfaceAddress */
class Java_net_InterfaceAddress {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_net_InetAddress getAddress();
	@Virtual @Overload Java_net_InetAddress getBroadcast();
	@Virtual @Overload int getNetworkPrefixLength();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
}
/* class java.net.JarURLConnection */
class Java_net_JarURLConnection extends Java_net_URLConnection {
	/*-- Method --*/
	@Virtual @Overload Java_util_jar_Attributes getAttributes();
	@Virtual @Overload Java_security_cert_Certificate[] getCertificates();
	@Virtual @Overload String getEntryName();
	@Virtual @Overload Java_util_jar_JarEntry getJarEntry();
	@Virtual @Overload Java_util_jar_JarFile getJarFile();
	@Virtual @Overload Java_net_URL getJarFileURL();
	@Virtual @Overload Java_util_jar_Attributes getMainAttributes();
	@Virtual @Overload Java_util_jar_Manifest getManifest();
}
/* class java.net.MalformedURLException */
class Java_net_MalformedURLException extends Java_io_IOException {
}
@Overload Java_net_MalformedURLException Java_net_MalformedURLException.new();
@Overload Java_net_MalformedURLException Java_net_MalformedURLException.new(String p0);
/* class java.net.MulticastSocket */
class Java_net_MulticastSocket extends Java_net_DatagramSocket {
	/*-- Method --*/
	@Virtual @Overload Java_net_InetAddress getInterface();
	@Virtual @Overload boolean getLoopbackMode();
	@Virtual @Overload Java_net_NetworkInterface getNetworkInterface();
	@Virtual @Overload int getTimeToLive();
	@Virtual @Overload void joinGroup(Java_net_InetAddress p0);
	@Virtual @Overload void joinGroup(Java_net_SocketAddress p0, Java_net_NetworkInterface p1);
	@Virtual @Overload void leaveGroup(Java_net_InetAddress p0);
	@Virtual @Overload void leaveGroup(Java_net_SocketAddress p0, Java_net_NetworkInterface p1);
	@Virtual @Overload void setInterface(Java_net_InetAddress p0);
	@Virtual @Overload void setLoopbackMode(boolean p0);
	@Virtual @Overload void setNetworkInterface(Java_net_NetworkInterface p0);
	@Virtual @Overload void setTimeToLive(int p0);
}
@Overload Java_net_MulticastSocket Java_net_MulticastSocket.new();
@Overload Java_net_MulticastSocket Java_net_MulticastSocket.new(int p0);
@Overload Java_net_MulticastSocket Java_net_MulticastSocket.new(Java_net_SocketAddress p0);
/* class java.net.NetPermission */
class Java_net_NetPermission extends Java_security_BasicPermission {
}
@Overload Java_net_NetPermission Java_net_NetPermission.new(String p0);
@Overload Java_net_NetPermission Java_net_NetPermission.new(String p0, String p1);
/* class java.net.NetworkInterface */
class Java_net_NetworkInterface {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_net_NetworkInterface getByIndex(int p0);
	@Virtual @Overload Java_net_NetworkInterface getByInetAddress(Java_net_InetAddress p0);
	@Virtual @Overload Java_net_NetworkInterface getByName(String p0);
	@Virtual @Overload String getDisplayName();
	@Virtual @Overload int[] getHardwareAddress();
	@Virtual @Overload int getIndex();
	@Virtual @Overload Java_util_Enumeration getInetAddresses();
	@Virtual @Overload Java_util_List getInterfaceAddresses();
	@Virtual @Overload int getMTU();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_util_Enumeration getNetworkInterfaces();
	@Virtual @Overload Java_net_NetworkInterface getParent();
	@Virtual @Overload Java_util_Enumeration getSubInterfaces();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isLoopback();
	@Virtual @Overload boolean isPointToPoint();
	@Virtual @Overload boolean isUp();
	@Virtual @Overload boolean isVirtual();
	@Virtual @Overload boolean supportsMulticast();
	@Virtual @Overload String toString();
}
/* class java.net.NoRouteToHostException */
class Java_net_NoRouteToHostException extends Java_net_SocketException {
}
@Overload Java_net_NoRouteToHostException Java_net_NoRouteToHostException.new(String p0);
@Overload Java_net_NoRouteToHostException Java_net_NoRouteToHostException.new();
/* class java.net.PasswordAuthentication */
class Java_net_PasswordAuthentication {
	/*-- Method --*/
	@Virtual @Overload int[] getPassword();
	@Virtual @Overload String getUserName();
}
Java_net_PasswordAuthentication Java_net_PasswordAuthentication.new(String p0, int[] p1);
/* class java.net.PortUnreachableException */
class Java_net_PortUnreachableException extends Java_net_SocketException {
}
@Overload Java_net_PortUnreachableException Java_net_PortUnreachableException.new(String p0);
@Overload Java_net_PortUnreachableException Java_net_PortUnreachableException.new();
/* class java.net.ProtocolException */
class Java_net_ProtocolException extends Java_io_IOException {
}
@Overload Java_net_ProtocolException Java_net_ProtocolException.new(String p0);
@Overload Java_net_ProtocolException Java_net_ProtocolException.new();
/* interface java.net.ProtocolFamily */
class Java_net_ProtocolFamily {
	/*-- Method --*/
	@Virtual @Overload String name();
}
/* class java.net.Proxy */
class Java_net_Proxy {
	/*-- Method --*/
	@Virtual @Overload Java_net_SocketAddress address();
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_net_Proxy_Type type();
}
Java_net_Proxy Java_net_Proxy.new(Java_net_Proxy_Type p0, Java_net_SocketAddress p1);
/* class java.net.ProxySelector */
class Java_net_ProxySelector {
	/*-- Method --*/
	@Virtual @Overload void connectFailed(Java_net_URI p0, Java_net_SocketAddress p1, Java_io_IOException p2);
	@Virtual @Overload Java_net_ProxySelector getDefault();
	@Virtual @Overload Java_util_List select(Java_net_URI p0);
	@Virtual @Overload void setDefault(Java_net_ProxySelector p0);
}
Java_net_ProxySelector Java_net_ProxySelector.new();
/* class java.net.ResponseCache */
class Java_net_ResponseCache {
	/*-- Method --*/
	@Virtual @Overload Java_net_CacheResponse get(Java_net_URI p0, String p1, Java_util_Map p2);
	@Virtual @Overload Java_net_ResponseCache getDefault();
	@Virtual @Overload Java_net_CacheRequest put(Java_net_URI p0, Java_net_URLConnection p1);
	@Virtual @Overload void setDefault(Java_net_ResponseCache p0);
}
Java_net_ResponseCache Java_net_ResponseCache.new();
/* class java.net.SecureCacheResponse */
class Java_net_SecureCacheResponse extends Java_net_CacheResponse {
	/*-- Method --*/
	@Virtual @Overload String getCipherSuite();
	@Virtual @Overload Java_util_List getLocalCertificateChain();
	@Virtual @Overload Java_security_Principal getLocalPrincipal();
	@Virtual @Overload Java_security_Principal getPeerPrincipal();
	@Virtual @Overload Java_util_List getServerCertificateChain();
}
Java_net_SecureCacheResponse Java_net_SecureCacheResponse.new();
/* class java.net.ServerSocket */
class Java_net_ServerSocket {
	/*-- Method --*/
	@Virtual @Overload Java_net_Socket accept();
	@Virtual @Overload void bind(Java_net_SocketAddress p0);
	@Virtual @Overload void bind(Java_net_SocketAddress p0, int p1);
	@Virtual @Overload void close();
	@Virtual @Overload Java_nio_channels_ServerSocketChannel getChannel();
	@Virtual @Overload Java_net_InetAddress getInetAddress();
	@Virtual @Overload int getLocalPort();
	@Virtual @Overload Java_net_SocketAddress getLocalSocketAddress();
	@Virtual @Overload int getReceiveBufferSize();
	@Virtual @Overload boolean getReuseAddress();
	@Virtual @Overload int getSoTimeout();
	@Virtual @Overload boolean isBound();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload void setPerformancePreferences(int p0, int p1, int p2);
	@Virtual @Overload void setReceiveBufferSize(int p0);
	@Virtual @Overload void setReuseAddress(boolean p0);
	@Virtual @Overload void setSoTimeout(int p0);
	@Virtual @Overload void setSocketFactory(Java_net_SocketImplFactory p0);
	@Virtual @Overload String toString();
}
@Overload Java_net_ServerSocket Java_net_ServerSocket.new();
@Overload Java_net_ServerSocket Java_net_ServerSocket.new(int p0);
@Overload Java_net_ServerSocket Java_net_ServerSocket.new(int p0, int p1);
@Overload Java_net_ServerSocket Java_net_ServerSocket.new(int p0, int p1, Java_net_InetAddress p2);
/* class java.net.Socket */
class Java_net_Socket {
	/*-- Method --*/
	@Virtual @Overload void bind(Java_net_SocketAddress p0);
	@Virtual @Overload void close();
	@Virtual @Overload void connect(Java_net_SocketAddress p0);
	@Virtual @Overload void connect(Java_net_SocketAddress p0, int p1);
	@Virtual @Overload Java_nio_channels_SocketChannel getChannel();
	@Virtual @Overload Java_net_InetAddress getInetAddress();
	@Virtual @Overload Java_io_InputStream getInputStream();
	@Virtual @Overload boolean getKeepAlive();
	@Virtual @Overload Java_net_InetAddress getLocalAddress();
	@Virtual @Overload int getLocalPort();
	@Virtual @Overload Java_net_SocketAddress getLocalSocketAddress();
	@Virtual @Overload boolean getOOBInline();
	@Virtual @Overload Java_io_OutputStream getOutputStream();
	@Virtual @Overload int getPort();
	@Virtual @Overload int getReceiveBufferSize();
	@Virtual @Overload Java_net_SocketAddress getRemoteSocketAddress();
	@Virtual @Overload boolean getReuseAddress();
	@Virtual @Overload int getSendBufferSize();
	@Virtual @Overload int getSoLinger();
	@Virtual @Overload int getSoTimeout();
	@Virtual @Overload boolean getTcpNoDelay();
	@Virtual @Overload int getTrafficClass();
	@Virtual @Overload boolean isBound();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload boolean isConnected();
	@Virtual @Overload boolean isInputShutdown();
	@Virtual @Overload boolean isOutputShutdown();
	@Virtual @Overload void sendUrgentData(int p0);
	@Virtual @Overload void setKeepAlive(boolean p0);
	@Virtual @Overload void setOOBInline(boolean p0);
	@Virtual @Overload void setPerformancePreferences(int p0, int p1, int p2);
	@Virtual @Overload void setReceiveBufferSize(int p0);
	@Virtual @Overload void setReuseAddress(boolean p0);
	@Virtual @Overload void setSendBufferSize(int p0);
	@Virtual @Overload void setSoLinger(boolean p0, int p1);
	@Virtual @Overload void setSoTimeout(int p0);
	@Virtual @Overload void setSocketImplFactory(Java_net_SocketImplFactory p0);
	@Virtual @Overload void setTcpNoDelay(boolean p0);
	@Virtual @Overload void setTrafficClass(int p0);
	@Virtual @Overload void shutdownInput();
	@Virtual @Overload void shutdownOutput();
	@Virtual @Overload String toString();
}
@Overload Java_net_Socket Java_net_Socket.new();
@Overload Java_net_Socket Java_net_Socket.new(Java_net_Proxy p0);
@Overload Java_net_Socket Java_net_Socket.new(String p0, int p1);
@Overload Java_net_Socket Java_net_Socket.new(Java_net_InetAddress p0, int p1);
@Overload Java_net_Socket Java_net_Socket.new(String p0, int p1, Java_net_InetAddress p2, int p3);
@Overload Java_net_Socket Java_net_Socket.new(Java_net_InetAddress p0, int p1, Java_net_InetAddress p2, int p3);
@Overload Java_net_Socket Java_net_Socket.new(String p0, int p1, boolean p2);
@Overload Java_net_Socket Java_net_Socket.new(Java_net_InetAddress p0, int p1, boolean p2);
/* class java.net.SocketAddress */
class Java_net_SocketAddress {
}
Java_net_SocketAddress Java_net_SocketAddress.new();
/* class java.net.SocketException */
class Java_net_SocketException extends Java_io_IOException {
}
@Overload Java_net_SocketException Java_net_SocketException.new(String p0);
@Overload Java_net_SocketException Java_net_SocketException.new();
/* class java.net.SocketImpl */
class Java_net_SocketImpl {
	/*-- Method --*/
	@Virtual @Overload String toString();
}
Java_net_SocketImpl Java_net_SocketImpl.new();
/* interface java.net.SocketImplFactory */
class Java_net_SocketImplFactory {
	/*-- Method --*/
	@Virtual @Overload Java_net_SocketImpl createSocketImpl();
}
/* interface java.net.SocketOption */
class Java_net_SocketOption {
	/*-- Method --*/
	@Virtual @Overload String name();
	@Virtual @Overload Class type();
}
/* interface java.net.SocketOptions */
class Java_net_SocketOptions {
	/*-- Method --*/
	@Virtual @Overload Object getOption(int p0);
	@Virtual @Overload void setOption(int p0, Object p1);
}
/* class java.net.SocketPermission */
class Java_net_SocketPermission extends Java_security_Permission {
}
Java_net_SocketPermission Java_net_SocketPermission.new(String p0, String p1);
/* class java.net.SocketTimeoutException */
class Java_net_SocketTimeoutException extends Java_io_InterruptedIOException {
}
@Overload Java_net_SocketTimeoutException Java_net_SocketTimeoutException.new(String p0);
@Overload Java_net_SocketTimeoutException Java_net_SocketTimeoutException.new();
/* class java.net.StandardProtocolFamily */
class Java_net_StandardProtocolFamily extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload Java_net_StandardProtocolFamily valueOf(String p0);
	@Virtual @Overload Java_net_StandardProtocolFamily[] values();
}
/* class java.net.StandardSocketOptions */
class Java_net_StandardSocketOptions {
}
/* class java.net.URI */
class Java_net_URI {
	/*-- Method --*/
	@Virtual @Overload int compareTo(Java_net_URI p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_net_URI create(String p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload String getAuthority();
	@Virtual @Overload String getFragment();
	@Virtual @Overload String getHost();
	@Virtual @Overload String getPath();
	@Virtual @Overload int getPort();
	@Virtual @Overload String getQuery();
	@Virtual @Overload String getRawAuthority();
	@Virtual @Overload String getRawFragment();
	@Virtual @Overload String getRawPath();
	@Virtual @Overload String getRawQuery();
	@Virtual @Overload String getRawSchemeSpecificPart();
	@Virtual @Overload String getRawUserInfo();
	@Virtual @Overload String getScheme();
	@Virtual @Overload String getSchemeSpecificPart();
	@Virtual @Overload String getUserInfo();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isAbsolute();
	@Virtual @Overload boolean isOpaque();
	@Virtual @Overload Java_net_URI normalize();
	@Virtual @Overload Java_net_URI parseServerAuthority();
	@Virtual @Overload Java_net_URI relativize(Java_net_URI p0);
	@Virtual @Overload Java_net_URI resolve(Java_net_URI p0);
	@Virtual @Overload Java_net_URI resolve(String p0);
	@Virtual @Overload String toASCIIString();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_net_URL toURL();
}
@Overload Java_net_URI Java_net_URI.new(String p0);
@Overload Java_net_URI Java_net_URI.new(String p0, String p1, String p2, int p3, String p4, String p5, String p6);
@Overload Java_net_URI Java_net_URI.new(String p0, String p1, String p2, String p3, String p4);
@Overload Java_net_URI Java_net_URI.new(String p0, String p1, String p2, String p3);
@Overload Java_net_URI Java_net_URI.new(String p0, String p1, String p2);
/* class java.net.URISyntaxException */
class Java_net_URISyntaxException extends Java_lang_Exception {
	/*-- Method --*/
	@Virtual @Overload int getIndex();
	@Virtual @Overload String getInput();
	@Virtual @Overload String getReason();
}
@Overload Java_net_URISyntaxException Java_net_URISyntaxException.new(String p0, String p1, int p2);
@Overload Java_net_URISyntaxException Java_net_URISyntaxException.new(String p0, String p1);
/* class java.net.URL */
class Java_net_URL {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload String getAuthority();
	@Virtual @Overload Object getContent();
	@Virtual @Overload Object getContent(Class[] p0);
	@Virtual @Overload int getDefaultPort();
	@Virtual @Overload String getFile();
	@Virtual @Overload String getHost();
	@Virtual @Overload String getPath();
	@Virtual @Overload int getPort();
	@Virtual @Overload String getProtocol();
	@Virtual @Overload String getQuery();
	@Virtual @Overload String getRef();
	@Virtual @Overload String getUserInfo();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload Java_net_URLConnection openConnection();
	@Virtual @Overload Java_net_URLConnection openConnection(Java_net_Proxy p0);
	@Virtual @Overload Java_io_InputStream openStream();
	@Virtual @Overload boolean sameFile(Java_net_URL p0);
	@Virtual @Overload void setURLStreamHandlerFactory(Java_net_URLStreamHandlerFactory p0);
	@Virtual @Overload String toExternalForm();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_net_URI toURI();
}
@Overload Java_net_URL Java_net_URL.new(String p0, String p1, int p2, String p3);
@Overload Java_net_URL Java_net_URL.new(String p0, String p1, String p2);
@Overload Java_net_URL Java_net_URL.new(String p0, String p1, int p2, String p3, Java_net_URLStreamHandler p4);
@Overload Java_net_URL Java_net_URL.new(String p0);
@Overload Java_net_URL Java_net_URL.new(Java_net_URL p0, String p1);
@Overload Java_net_URL Java_net_URL.new(Java_net_URL p0, String p1, Java_net_URLStreamHandler p2);
/* class java.net.URLClassLoader */
class Java_net_URLClassLoader extends Java_security_SecureClassLoader {
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload Java_net_URL findResource(String p0);
	@Virtual @Overload Java_util_Enumeration findResources(String p0);
	@Virtual @Overload Java_net_URL[] getURLs();
	@Virtual @Overload Java_net_URLClassLoader newInstance(Java_net_URL[] p0, Java_lang_ClassLoader p1);
	@Virtual @Overload Java_net_URLClassLoader newInstance(Java_net_URL[] p0);
}
@Overload Java_net_URLClassLoader Java_net_URLClassLoader.new(Java_net_URL[] p0, Java_lang_ClassLoader p1);
@Overload Java_net_URLClassLoader Java_net_URLClassLoader.new(Java_net_URL[] p0);
@Overload Java_net_URLClassLoader Java_net_URLClassLoader.new(Java_net_URL[] p0, Java_lang_ClassLoader p1, Java_net_URLStreamHandlerFactory p2);
/* class java.net.URLConnection */
class Java_net_URLConnection {
	/*-- Method --*/
	@Virtual @Overload void addRequestProperty(String p0, String p1);
	@Virtual @Overload void connect();
	@Virtual @Overload boolean getAllowUserInteraction();
	@Virtual @Overload int getConnectTimeout();
	@Virtual @Overload Object getContent();
	@Virtual @Overload Object getContent(Class[] p0);
	@Virtual @Overload String getContentEncoding();
	@Virtual @Overload int getContentLength();
	@Virtual @Overload long getContentLengthLong();
	@Virtual @Overload String getContentType();
	@Virtual @Overload long getDate();
	@Virtual @Overload boolean getDefaultAllowUserInteraction();
	@Virtual @Overload boolean getDefaultUseCaches();
	@Virtual @Overload boolean getDoInput();
	@Virtual @Overload boolean getDoOutput();
	@Virtual @Overload long getExpiration();
	@Virtual @Overload Java_net_FileNameMap getFileNameMap();
	@Virtual @Overload String getHeaderField(String p0);
	@Virtual @Overload String getHeaderField(int p0);
	@Virtual @Overload long getHeaderFieldDate(String p0, long p1);
	@Virtual @Overload int getHeaderFieldInt(String p0, int p1);
	@Virtual @Overload String getHeaderFieldKey(int p0);
	@Virtual @Overload long getHeaderFieldLong(String p0, long p1);
	@Virtual @Overload Java_util_Map getHeaderFields();
	@Virtual @Overload long getIfModifiedSince();
	@Virtual @Overload Java_io_InputStream getInputStream();
	@Virtual @Overload long getLastModified();
	@Virtual @Overload Java_io_OutputStream getOutputStream();
	@Virtual @Overload Java_security_Permission getPermission();
	@Virtual @Overload int getReadTimeout();
	@Virtual @Overload Java_util_Map getRequestProperties();
	@Virtual @Overload String getRequestProperty(String p0);
	@Virtual @Overload Java_net_URL getURL();
	@Virtual @Overload boolean getUseCaches();
	@Virtual @Overload String guessContentTypeFromName(String p0);
	@Virtual @Overload String guessContentTypeFromStream(Java_io_InputStream p0);
	@Virtual @Overload void setAllowUserInteraction(boolean p0);
	@Virtual @Overload void setConnectTimeout(int p0);
	@Virtual @Overload void setContentHandlerFactory(Java_net_ContentHandlerFactory p0);
	@Virtual @Overload void setDefaultAllowUserInteraction(boolean p0);
	@Virtual @Overload void setDefaultUseCaches(boolean p0);
	@Virtual @Overload void setDoInput(boolean p0);
	@Virtual @Overload void setDoOutput(boolean p0);
	@Virtual @Overload void setFileNameMap(Java_net_FileNameMap p0);
	@Virtual @Overload void setIfModifiedSince(long p0);
	@Virtual @Overload void setReadTimeout(int p0);
	@Virtual @Overload void setRequestProperty(String p0, String p1);
	@Virtual @Overload void setUseCaches(boolean p0);
	@Virtual @Overload String toString();
}
/* class java.net.URLDecoder */
class Java_net_URLDecoder {
	/*-- Method --*/
	@Virtual @Overload String decode(String p0, String p1);
}
Java_net_URLDecoder Java_net_URLDecoder.new();
/* class java.net.URLEncoder */
class Java_net_URLEncoder {
	/*-- Method --*/
	@Virtual @Overload String encode(String p0, String p1);
}
/* class java.net.URLStreamHandler */
class Java_net_URLStreamHandler {
}
Java_net_URLStreamHandler Java_net_URLStreamHandler.new();
/* interface java.net.URLStreamHandlerFactory */
class Java_net_URLStreamHandlerFactory {
	/*-- Method --*/
	@Virtual @Overload Java_net_URLStreamHandler createURLStreamHandler(String p0);
}
/* class java.net.UnknownHostException */
class Java_net_UnknownHostException extends Java_io_IOException {
}
@Overload Java_net_UnknownHostException Java_net_UnknownHostException.new(String p0);
@Overload Java_net_UnknownHostException Java_net_UnknownHostException.new();
/* class java.net.UnknownServiceException */
class Java_net_UnknownServiceException extends Java_io_IOException {
}
@Overload Java_net_UnknownServiceException Java_net_UnknownServiceException.new();
@Overload Java_net_UnknownServiceException Java_net_UnknownServiceException.new(String p0);

/*------------------------------------------------------------*/
/* short names */
Authenticator = Java_net_Authenticator
BindException = Java_net_BindException
CacheRequest = Java_net_CacheRequest
CacheResponse = Java_net_CacheResponse
ConnectException = Java_net_ConnectException
ContentHandler = Java_net_ContentHandler
ContentHandlerFactory = Java_net_ContentHandlerFactory
CookieHandler = Java_net_CookieHandler
CookieManager = Java_net_CookieManager
CookiePolicy = Java_net_CookiePolicy
CookieStore = Java_net_CookieStore
DatagramPacket = Java_net_DatagramPacket
DatagramSocket = Java_net_DatagramSocket
DatagramSocketImpl = Java_net_DatagramSocketImpl
DatagramSocketImplFactory = Java_net_DatagramSocketImplFactory
FileNameMap = Java_net_FileNameMap
HttpCookie = Java_net_HttpCookie
HttpRetryException = Java_net_HttpRetryException
HttpURLConnection = Java_net_HttpURLConnection
IDN = Java_net_IDN
Inet4Address = Java_net_Inet4Address
Inet6Address = Java_net_Inet6Address
InetAddress = Java_net_InetAddress
InetSocketAddress = Java_net_InetSocketAddress
InterfaceAddress = Java_net_InterfaceAddress
JarURLConnection = Java_net_JarURLConnection
MalformedURLException = Java_net_MalformedURLException
MulticastSocket = Java_net_MulticastSocket
NetPermission = Java_net_NetPermission
NetworkInterface = Java_net_NetworkInterface
NoRouteToHostException = Java_net_NoRouteToHostException
PasswordAuthentication = Java_net_PasswordAuthentication
PortUnreachableException = Java_net_PortUnreachableException
ProtocolException = Java_net_ProtocolException
ProtocolFamily = Java_net_ProtocolFamily
Proxy = Java_net_Proxy
ProxySelector = Java_net_ProxySelector
ResponseCache = Java_net_ResponseCache
SecureCacheResponse = Java_net_SecureCacheResponse
ServerSocket = Java_net_ServerSocket
Socket = Java_net_Socket
SocketAddress = Java_net_SocketAddress
SocketException = Java_net_SocketException
SocketImpl = Java_net_SocketImpl
SocketImplFactory = Java_net_SocketImplFactory
SocketOption = Java_net_SocketOption
SocketOptions = Java_net_SocketOptions
SocketPermission = Java_net_SocketPermission
SocketTimeoutException = Java_net_SocketTimeoutException
StandardProtocolFamily = Java_net_StandardProtocolFamily
StandardSocketOptions = Java_net_StandardSocketOptions
URI = Java_net_URI
URISyntaxException = Java_net_URISyntaxException
URL = Java_net_URL
URLClassLoader = Java_net_URLClassLoader
URLConnection = Java_net_URLConnection
URLDecoder = Java_net_URLDecoder
URLEncoder = Java_net_URLEncoder
URLStreamHandler = Java_net_URLStreamHandler
URLStreamHandlerFactory = Java_net_URLStreamHandlerFactory
UnknownHostException = Java_net_UnknownHostException
UnknownServiceException = Java_net_UnknownServiceException
