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
class Xml;
class XmlNode;
class XPath;

Xml     Xml.new(String version);
void    Xml.setAttr(String name,String value);
XmlNode Xml.createNode(String name);
String  Xml.dump();
String  Xml.dumpEnc(String enc);
XmlNode Xml.getRoot();

XmlNode XmlNode.createNode(String name,String value);
void    XmlNode.addChild(XmlNode child);
void    XmlNode.setAttr(String name,String value);
Boolean XmlNode.hasChild();
Boolean XmlNode.hasNext();
XmlNode XmlNode.getChild();
XmlNode XmlNode.getNext();
String  XmlNode.getName();
String  XmlNode.getAttr(String name);
String  XmlNode.getContent();
void    XmlNode.dump();

XPath   XPath.new(Xml xml);
XmlNode XPath.find(String xpath);
***/

include "lib:gluelink";

@Native class XmlReader;
@Native XmlReader XmlReader.new(String filename, XmlReader _);
@Native void XmlReader.close();
@Native String XmlReader.getQuoteChar();
@Native Boolean XmlReader.read();
@Native int XmlReader.readState();
@Native int XmlReader.nodeType();
@Native int XmlReader.isNamespaceDecl();
@Native int XmlReader.isEmptyElement();
@Native int XmlReader.getAttributeCount();
@Native boolean XmlReader.hasAttributes();
@Native boolean XmlReader.hasValue();
@Native boolean XmlReader.getDepth();
@Native boolean XmlReader.moveToFirstAttribute();
@Native boolean XmlReader.moveToNextAttribute();
@Native boolean XmlReader.moveToElement();
@Native String  XmlReader.constBaseUri();
@Native String  XmlReader.constEncoding();
@Native String  XmlReader.constValue();
@Native String  XmlReader.constNamespaceUri();
@Native String  XmlReader.constLocalName();
@Native String  XmlReader.constName();
@Native String  XmlReader.constXmlLang();
@Native String  XmlReader.constPrefix();
@Native String  XmlReader.getAttribute();
@Native String  XmlReader.getAttributeNo(int numer);
@Native String  XmlReader.getAttributeNs(String ns, String name);
@Native String  XmlReader.lookupNameSpace(String ns);
@Native int XmlReader.normalization();

