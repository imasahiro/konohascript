/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

include "lib:gluelink";

@Native class Socket;
@Native class ServerSocket;

/* Socket */
@Native Socket Socket.new(String host, int port=80);
@Native InputStream Socket.getInputStream();
@Native OutputStream Socket.getOutputStream();
@Native void Socket.close();

@Native boolean Socket.getKeepAlive();
@Native int Socket.getLocalPort();
//@Native int Socket.getPort();
@Native boolean Socket.getReuseAddress();
@Native int Socket.getSendBufferSize();
@Native int Socket.getSoTimeout();

@Native void Socket.setKeepAlive(boolean on);
@Native void Socket.setReuseAddress(boolean on);
@Native void Socket.setSendBufferSize(int size);
@Native void Socket.setSoTimeout(int msec);

@Native boolean Socket.isClosed();

/* ServerSocket */
@Native ServerSocket ServerSocket.new(int port, int maxConnection);
@Native Socket ServerSocket.accept(NameSpace ns);
@Native void ServerSocket.close();

@Native int ServerSocket.getLocalPort();
@Native int ServerSocket.getReceiveBufferSize();
@Native boolean ServerSocket.getReuseAddress();
@Native int ServerSocket.getSoTimeout();

@Native void ServerSocket.setReceiveBufferSize(int size);
@Native void ServerSocket.setReuseAddress(boolean on);
@Native void ServerSocket.setSoTimeout(int msec);

//@Native boolean ServerSocket.isBound();
@Native boolean ServerSocket.isClosed();

//@Native void ServerSocket.setPerformancePreerences(int connectionTime, int latency, int bandwidth);
@Native void ServerSocket.setReceiveBufferSize (int size);
@Native void ServerSocket.setReuseAddress(boolean on);
