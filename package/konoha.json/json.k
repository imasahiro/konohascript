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
//  uh - Yutaro Hiraoka, Yokohama National University, Japan
//  imasahiro - Masahiro Ide, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

include "lib:gluelink";

@Native class Json;

/**
 * create new Json object
 * @return     Json object
 */
@Native @Static Json Json.new();

/**
 * get value object from an attribute name
 * @param key  attribute name of String
 * @return     value of dynamic object (Literal/Array/Json)
 */
@Native var Json.get(String key, Class _);

/**
 * set value object with an attribute name
 * @param key  attribute name of String
 * @param val  value of dynamic object (Literal/Array/Json)
 */
@Native void Json.set(String key, dynamic val);

/**
 * delete value ovject by an attribute name
 * @param key  string name of target attribute
 */
@Native void Json.delete(String key);

/**
 * transform Json String into Json object
 * @param str  Json String
 * @return     Json object
 */
@Native @Static Json Json.parse(String str);

/**
 * transform Json object into Json String
 * @return     Json String
 */
@Native String Json.stringify();

/**
 * get an array set of string name of attributes
 * @return     Array of attribute name Strings
 */
@Native Array<String> Json.getKeys();

/**
 * check if value object is existed from its attribute name
 * @return     true if attribute is existed
 */
@Native boolean Json.opHAS(String key);

/**
 * get Konoha Map Object transformed from Json
 * @return    Map of converted Json Object
 */
@Native @Public Json Map.toJson();

@Native @Public String Map.toJsonString();

/**
  * Stream API
  */
@Native @Public Tvar InputStream.readJson(Class _);
@Native @Public void OutputStream.writeJson(Object data);

@Native @Public void Bytes.writeJson(Object data);
@Native @Public Tvar Bytes.readJson(int offset, int len, Class _);
