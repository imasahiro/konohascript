/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2005-2009, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Software Foundation
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU General Public License 2.0      (with    KONOHA_UNDER_GPL2)
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

include "lib:gluelink";

// system
@Public @Native String System.getHostName();
@Public @Native Map System.uname();
@Public @Native String System.getDomainName();


// user, group
@Public @Native String System.getLogin();
@Public @Native int System.getUid();
@Public @Native int System.getEuid();
@Public @Native int System.getGid();
@Public @Native int System.getEgid();

@Public @Native Array<int> System.getGroups();
//@Public @Restricted @Native boolean System.setGroups(int pid, Array<int> groups);

// process 
@Public @Native int System.getPid();
@Public @Native int System.getPPid();
@Public @Native int System.getPgid(int pid);
@Public @Native int System.sleep(int sec);
@Public @Native boolean System.usleep(int sec);

//@Public @Restricted @Native boolean System.setPgid(int pid, int pgid);

// resource usage
@Public @Native Map System.getResourceUsage(int who);
@Public @Native Map System.getRlimit(int rtype);


// file system
@Public @Restricted @Native boolean System.link(Path path, Path path2);
@Public @Restricted @Native boolean System.symlink(Path path, Path path2);
@Public @Restricted @Native boolean System.rename(Path path, Path path2);
@Public @Restricted @Native boolean System.unlink(Path path);

@Public @Native boolean System.truncate(Path path, int length);

@Public @Native Map System.stat(Path path);
@Public @Native String System.readlink(Path path);
@Public @Restricted @Native boolean System.chmod(Path path, int mode);
@Public @Restricted @Native boolean System.chown(Path path, int owner, int group);
@Public @Restricted @Native int System.access(Path path, int mode);
@Public @Native void System.sync();

@Public @Native String System.getCwd();
@Public @Native boolean System.chdir(Path path);
@Public @Restricted @Native boolean System.chroot(Path path);
@Public @Restricted @Native boolean System.mkdir(Path path, int mode);
@Public @Restricted @Native boolean System.rmdir(Path path);

@Public @Native int System.getPriority(int which, int who);
@Public @Restricted @Native boolean System.setPriority(int which, int who, int pri);


// memory
@Public @Native int System.getPageSize();


// DIR
@Public @Native class Dir;
@Public @Native @Throwable Dir System.openDir(Path path);
@Public @Native @Iterative String Dir.readName();
@Public @Native void Dir.close();
@Public @Native @Iterative Map Dir.read();

//FILE Stream
@Public @Native class DFile;
@Public @Native @Throwable DFile System.fopen(Path path, String mode);

@Public @Native int DFile.getC();
@Public @Native int DFile.read(Bytes buf, int offset, int len);
@Public @Native boolean DFile.putC(int ch);
@Public @Native int DFile.write(Bytes buf, int offset, int len);
@Public @Native void DFile.close();

// FILE low-level
@Public @Native int DFile.lseek(int offset, int whence);
@Public @Restricted @Native boolean DFile.truncate(int length);
@Public @Restricted @Native boolean DFile.chmod(int mode);
@Public @Restricted @Native boolean DFile.chown(int owner, int group);
//@Public @Native boolean DFile.dup2(DFile f, DFile f2);
//@Public @Restricted @Native boolean DFile.fcntl
//@Public @Restricted @Native int DFile.ioctl(int request, String arg);
@Public @Restricted @Native boolean DFile.flock(int operation);
@Public @Restricted @Native boolean DFile.sync();



//include func:SystemCONST;

