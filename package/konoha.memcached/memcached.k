/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  imasahiro - Masahiro Ide, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
// **************************************************************************

include "lib:gluelink";

/* low-level API */
@Native class Memcache;
@Native @Public Memcache Memcache.new (Path pth);

/* Incrementing and decrementing values */

/* Deleting data from a server */
@Native @Public Boolean Memcache.delete(String key, int expiration_sec);
@Native @Public Boolean Memcache.delete_by_key(String group_key, String key, int expiration_sec);

/* Determine if a keys exists */
//@Native @Public Boolean Memcache.exist(String key);
//@Native @Public Boolean Memcache.exist_by_key(String group_key, String key);

/* Flushing client buffers */
@Native @Public Boolean Memcache.flushBuffers();

/* Wiping clean the contents of a server */
@Native @Public Boolean Memcache.flush(int expiration_sec);

/* Retrieving data from the server */

/* working with result sets */

/* Store, replace, add, or atoically add data to the server */
@Native @Public void Memcache.set (String key, String value, int expiration_sec, int falgs);
@Native @Public void Memcache.add (String key, String value, int expiration_sec, int flags);
@Native @Public void Memcache.replace (String key, String value, int expiration_sec, int flags);
@Native @Public void Memcache.set_by_key (String group_key, String key, String value, int expiration_sec, int flags);
@Native @Public void Memcache.add_by_key (String group_key, String key, String value, int expiration_sec, int flags);
@Native @Public void Memcache.replace_by_key (String group_key, String key, String value, int expiration_sec, int flags);

/* appending or prepending to data on the server */
@Native @Public Boolean Memcache.prepend(String key, String vlaue, int expiration_sec, int flags);
@Native @Public Boolean Memcache.append(String key, String vlaue, int expiration_sec, int flags);
@Native @Public Boolean Memcache.prepend_by_key(String group_key, String key, String vlaue, int expiration_sec, int flags);
@Native @Public Boolean Memcache.append_by_key(String group_key, String key, String vlaue, int expiration_sec, int flags);

/* working with data on the server in an atomic fashion */



