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


/**
 * ホスト名を取得する
 * @return 取得したホスト名
 */
String! System.getHostName();

/**
 * ユーザ名を取得する
 * @return 取得したユーザ名
 */
String System.getLogin();

/**
 * 呼び出し元のプロセスの実ユーザIDを取得する
 * @return 取得したユーザID
 */
int System.getUid();


/**
 * 呼び出し元のプロセスの実効ユーザIDを取得する
 * @return 取得した実効ユーザID
 */
int System.getEuid();

/**
 * 呼び出し元のプロセスの実グループIDを取得する
 * @return 取得した実効グループID
 */
int System.getGid();

/**
 * 呼び出し元のプロセスの実効グループIDを取得する
 * @return 取得した実効グループID
 */
int System.getEgid();


/**
 * 呼び出し元のプロセスのプロセスIDを取得する
 * @return 取得したプロセスID
 */
int System.getPid();

/**
 * 呼び出し元のプロセスの親プロセスのプロセスIDを取得する
 * @return 取得したプロセスID
 */
int System.getPPid();

/**
 * 任意のプロセスにシグナルを送る
 * @param pid プロセスID
 * @param signal シグナル
 */
void System.kill(int pid, int signal);

/**
 * 任意のプロセスにシグナルを送る
 * @param pid プロセスID
 * @param signal シグナル
 */
int System.kill_return_int(int pid, int signal);

/**
 * 指定の秒数だけ呼び出し元のプロセスを休止する
 * @param sec 指定する時間(秒)
 */
void System.sleep(Int sec);

/**
 * 指定の秒数だけ呼び出し元のプロセスを休止する
 * @param msec 指定する時間(ミリ秒)
 */
void System.usleep(int sec);

/**
 * 現在の作業ディレクトリ名の取得
 * @return 現在の作業ディレクトリ名
 */
String! System.getCwd();

/**
 * 作業ディレクトリの変更
 * @param dirname 変更先へのパス
 */
void System.chDir(String dirname);

/**
 * 再起動する
 */
void System.reboot();

/**
 * SIGSEGVのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigSegv(Closure c);

/**
 * SIGTSTPのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigTstp(Closure c);

/**
 * SIGBUSのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigBus(Closure c);

/**
 * SIGKILLのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigKill(Closure c);

/**
 * SIGINTのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigInt(Closure c);

/**
 * SIGCHLDのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigChld(Closure c);

/**
 * SIGPIPEのシグナルハンドラを登録する
 * @param c 登録する関数のクロージャ
 */
void System.setSigPipe(Closure c);

/**
 * 呼び出し元にシグナルを送る
 * @param signal 送るシグナル
 */
void System.raise(int signal);

/**
 * 子プロセスを作る
 * @return 子プロセスなら0 親プロセスなら子プロセスのpid
 */
int System.fork();

/**
 * 子プロセスの終了を待つ
 * @return 終了した子プロセスのpid
 */
int System.wait();

/**
 * プロセスIDがpidの子プロセスの終了を待つ
 * @param pid プロセスID
 * @param opt オプション
 * @return 終了した子プロセスのstatus または 子プロセスのPID
 */
int System.waitPid(int pid, Int? opt);

/** temporary for et2009
 * システム関数を呼び出す
 * @param cmd　コマンド
 * @return 終了ステータス
 */
int System.system(String cmd);

