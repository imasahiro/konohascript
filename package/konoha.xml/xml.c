/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)      2008-      Konoha Team konohaken@googlegroups.com
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

#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xmlreader.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

#define p_cptr(a)   (sfp[0].p)->rawptr

///* ------------------------------------------------------------------------ */
///* [XmlDoc] */
//
//static void XmlDoc_init(CTX ctx, knh_RawPtr_t *po)
//{
//	po->rawptr = NULL;
//}
//
//static void XmlDoc_free(CTX ctx, knh_RawPtr_t *po)
//{
//	if (po->rawptr != NULL) {
//		xmlFreeDoc((xmlDocPtr)po->rawptr);
//		po->rawptr = NULL;
//	}
//}
//
//static void XmlDoc_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
//{
//	XmlDoc_free(ctx, po);
//}
//
//DEFAPI(void) defXmlDoc(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
//{
//	cdef->name = "XmlDoc";
//	cdef->init = XmlDoc_init;
//	cdef->free = XmlDoc_free;
//	cdef->checkout = XmlDoc_checkout;
//}
//
////static knh_IntData_t XmlDocConstint[] = {
////		{"TYPE_NONE",         XML_READER_TYPE_NONE},
////		{"TYPE_ELEMENT",      XML_READER_TYPE_ELEMENT},
////		{"TYPE_ATTRIBUTE",    XML_READER_TYPE_ATTRIBUTE},
////		{"TYPE_TEXT",         XML_READER_TYPE_TEXT},
////		{"TYPE_CDATA",        XML_READER_TYPE_CDATA},
////		{"TYPE_REFERENCE",    XML_READER_TYPE_ENTITY_REFERENCE},
////		{"TYPE_ENTITY",       XML_READER_TYPE_ENTITY},
////		{"TYPE_PROCESSING_INSTRUCTION",  XML_READER_TYPE_PROCESSING_INSTRUCTION},
////		{"TYPE_COMMENT",      XML_READER_TYPE_COMMENT},
////		{"TYPE_DOCUMENT",     XML_READER_TYPE_DOCUMENT},
////		{"TYPE_DOCUMENT_TYPE",XML_READER_TYPE_DOCUMENT_TYPE},
////		{"TYPE_DOCUMENT_FRAGMENT",      XML_READER_TYPE_DOCUMENT_FRAGMENT},
////		{"TYPE_NOTATION",     XML_READER_TYPE_NOTATION},
////		{"TYPE_WHITESPACE",   XML_READER_TYPE_WHITESPACE},
////		{"TYPE_SIGNIFICANT_WHITESPACE", XML_READER_TYPE_SIGNIFICANT_WHITESPACE},
////		{"TYPE_END_ELEMENT",  XML_READER_TYPE_END_ELEMENT},
////		{"TYPE_END_ENTITY",   XML_READER_TYPE_END_ENTITY},
////		{"TYPE_XML_DECLATION",XML_READER_TYPE_XML_DECLARATION},
////		{NULL} // end of const
////};
////
////DEFAPI(void) constXmlDoc(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
////{
////	kapi->loadIntClassConst(ctx, cid, XmlDocConstint);
////}
//
////## @Native @Throwable XmlDoc XmlDoc.new(String version, XmlDoc _);
//METHOD XmlDoc_new(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	xmlChar* version = String_to(xmlChar*, sfp[1]);
//	xmlDocPtr doc = xmlNewDoc(version);
//	knh_RawPtr_t *po = new_RawPtr(ctx, sfp[2].p, doc);
//	RETURN_(po);
//}

//METHOD Xml_setAttr(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar *name  = String_to(xmlChar*, sfp[1]);
//    xmlChar *value = String_to(xmlChar*, sfp[2]);
//    xmlNewDocProp(doc, name, value);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//METHOD Xml_createNode(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar *name = String_to(xmlChar*, sfp[1]);
//    doc->children = xmlNewDocNode(doc, NULL, name , NULL);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",doc->children,NULL));
//}
//
//METHOD Xml_getRoot(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlNodePtr node = xmlDocGetRootElement(doc);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",node,NULL));
//}
//
//METHOD Xml_dump(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar* ret;
//    int   size;
//    xmlDocDumpMemory(doc,&ret,&size);
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//METHOD Xml_dumpEnc(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    char* enc = String_to(char*, sfp[1]);
//    xmlChar* ret;
//    int   size;
//    xmlDocDumpMemoryEnc(doc,&ret,&size,enc);
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
///* XmlNode */
//METHOD XmlNode_createNode(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr parent = Glue_to(xmlNodePtr, sfp[0]);
//    xmlChar *name = String_to(xmlChar*, sfp[1]);
//    xmlChar *val  = String_to(xmlChar*, sfp[2]);
//
//    xmlNodePtr node = xmlNewChild(parent, NULL, name, val);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",node,NULL));
//}
//
//METHOD XmlNode_addChild(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr parent = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr child  = (xmlNodePtr) p_cptr(sfp[1]);
//    xmlAddChild(parent,child);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//METHOD XmlNode_setAttr(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar *name = String_to(xmlChar *, sfp[1]);
//    xmlChar *val  = String_to(xmlChar *, sfp[2]);
//    xmlSetProp(node,name,val);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//METHOD XmlNode_getContent(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar* ret = (xmlChar *)"";
//    if(node->content){
//        ret = node->content;
//        fprintf(stdout,"[%s]\n",(char*)node->content);
//    }
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//METHOD XmlNode_getName(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar* ret = (xmlChar *)"";
//    if(node->name){
//        ret = (xmlChar *)node->name;
//    }
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//METHOD XmlNode_getAttr(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar *name = String_to(xmlChar *, sfp[1]);
//    xmlChar *ret  = (xmlChar *)"";
//    if(node->properties){
//        ret  = xmlGetProp(node,name);
//    }
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//
//METHOD XmlNode_getChild(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node  = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr child = (xmlNodePtr) node->children;
//    if(child == NULL){
//        KNH_THROW__T(ctx, "XmlNode: dont have child!");
//    }
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",child,NULL));
//}
//
//METHOD XmlNode_getNext(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr next = (xmlNodePtr) node->next;
//    if(next == NULL){
//        KNH_THROW__T(ctx, "XmlNode: dont have next!");
//    }
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",next,NULL));
//}
//
//METHOD XmlNode_hasChild(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    if(node->children) {
//        KNH_RETURN_boolean(ctx, sfp, 1);
//    }
//    KNH_RETURN_boolean(ctx, sfp, 0);
//}
//
//METHOD XmlNode_hasNext(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    if(node->next) {
//        KNH_RETURN_boolean(ctx, sfp, 1);
//    }
//    KNH_RETURN_boolean(ctx, sfp, 0);
//}
//
///*
//static xmlDocPtr document = NULL;
//METHOD XmlNode_dump(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlElemDump(stdout,document,node);
//    KNH_RETURN_void(ctx,sfp);
//}
//*/
//
///* XPath */
//static void knh_xpath_gfree(Ctx *ctx, knh_Glue_t *g)
//{
//    xmlXPathContextPtr xctx = (xmlXPathContextPtr) g->ptr;
//    xmlXPathFreeContext(xctx);
//    xmlCleanupParser();
//}
//
//METHOD XPath_new(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = (xmlDocPtr) p_cptr(sfp[1]);
//    xmlXPathContextPtr xctx;
//    if (!(xctx = xmlXPathNewContext(doc))) {
//        KNH_THROW__T(ctx, "XPATH: cant create xmlXPathContext");
//    }
//    knh_Glue_init(ctx,sfp[0].glue,xctx,knh_xpath_gfree);
//    RETURN_(sfp[0].o);
//}
//
//METHOD XPath_find(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//    xmlXPathContextPtr xctx = (xmlXPathContextPtr) p_cptr(sfp[0]);
//    xmlChar *xpath = String_to(xmlChar *, sfp[1]);
//    xmlNodePtr node = NULL;
//    xmlXPathObjectPtr xpobj;
//    if (!(xpobj = xmlXPathEvalExpression( xpath, xctx))) {
//        fprintf(stderr,"xpath:%s",(char*)xpath);
//        KNH_THROW__T(ctx, "XPATH: cant execute xmlXPathEvalExpression");
//    }
//    if (!xmlXPathNodeSetIsEmpty(xpobj->nodesetval)) {
//        node = xmlXPathNodeSetItem(xpobj->nodesetval, 0);
//    }
//    xmlXPathFreeObject(xpobj);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",node,NULL));
//}

/* ------------------------------------------------------------------------ */
/* [XmlReader] */

static void XmlReader_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void XmlReader_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		xmlFreeTextReader((xmlTextReaderPtr)po->rawptr);
		po->rawptr = NULL;
	}
}

static void XmlReader_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
{
	XmlReader_free(ctx, po);
}

//## @Native class Dir;

DEFAPI(void) defXmlReader(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "XmlReader";
	cdef->init = XmlReader_init;
	cdef->free = XmlReader_free;
	cdef->checkout = XmlReader_checkout;
}

static knh_IntData_t XmlReaderConstint[] = {
		{"TYPE_NONE",         XML_READER_TYPE_NONE},
		{"TYPE_ELEMENT",      XML_READER_TYPE_ELEMENT},
		{"TYPE_ATTRIBUTE",    XML_READER_TYPE_ATTRIBUTE},
		{"TYPE_TEXT",         XML_READER_TYPE_TEXT},
		{"TYPE_CDATA",        XML_READER_TYPE_CDATA},
		{"TYPE_REFERENCE",    XML_READER_TYPE_ENTITY_REFERENCE},
		{"TYPE_ENTITY",       XML_READER_TYPE_ENTITY},
		{"TYPE_PROCESSING_INSTRUCTION",  XML_READER_TYPE_PROCESSING_INSTRUCTION},
		{"TYPE_COMMENT",      XML_READER_TYPE_COMMENT},
		{"TYPE_DOCUMENT",     XML_READER_TYPE_DOCUMENT},
		{"TYPE_DOCUMENT_TYPE",XML_READER_TYPE_DOCUMENT_TYPE},
		{"TYPE_DOCUMENT_FRAGMENT",      XML_READER_TYPE_DOCUMENT_FRAGMENT},
		{"TYPE_NOTATION",     XML_READER_TYPE_NOTATION},
		{"TYPE_WHITESPACE",   XML_READER_TYPE_WHITESPACE},
		{"TYPE_SIGNIFICANT_WHITESPACE", XML_READER_TYPE_SIGNIFICANT_WHITESPACE},
		{"TYPE_END_ELEMENT",  XML_READER_TYPE_END_ELEMENT},
		{"TYPE_END_ENTITY",   XML_READER_TYPE_END_ENTITY},
		{"TYPE_XML_DECLATION",XML_READER_TYPE_XML_DECLARATION},
		{NULL} // end of const
};

DEFAPI(void) constXmlReader(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadIntClassConst(ctx, cid, XmlReaderConstint);
}

//## @Native @Throwable XmlReader XmlReader.new(String path, NameSpace _, XmlReader _);
METHOD XmlReader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char path[K_PATHMAX];
	knh_String_ospath(ctx, sfp[1].s, sfp[2].ns, path, sizeof(path));
	KNH_RESET_ERRNO();
	xmlTextReaderPtr reader = xmlNewTextReaderFilename(path);
	knh_RawPtr_t *po = new_RawPtr(ctx, sfp[3].p, reader);
	if(reader == NULL) {
		LOGDATA = {sDATA("uri", S_tochar(sfp[1].s)), sDATA("ospath", (const char*)path), __ERRNO__};
		LIB_Failed("xmlNewTextReader", "IO!!");
	}
	RETURN_(po);
}

//## @Native void XmlReader.close();
METHOD XmlReader_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr)(sfp[0].p)->rawptr;
	if(reader != NULL) {
		xmlTextReaderClose(reader);
	}
	RETURNvoid_();
}

//## @Native String XmlReader.getQuoteChar();
METHOD XmlReader_getQuoteChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char buf[4] = {0};
	const char* ret = NULL;
	if(reader != NULL) {
		int ch = xmlTextReaderQuoteChar(reader);
		buf[0] = ch;
		ret = (const char*)buf;
	}
	RETURN_(new_String(ctx, ret));
}

//## @Native boolean XmlReader.read();
METHOD XmlReader_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = 0;
	if(reader != NULL) {
		ret = xmlTextReaderRead(reader);
	}
	RETURNb_(ret);
}

//## @Native int XmlReader.readState();
METHOD XmlReader_readState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderReadState(reader) : 0;
	RETURNi_(ret);
}

//## @Native int XmlReader.nodeType();
METHOD XmlReader_nodeType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderNodeType(reader) : 0;
	RETURNi_(ret);
}

//## @Native boolean XmlReader.isNamespaceDecl();
METHOD XmlReader_isNamespaceDecl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderIsNamespaceDecl(reader) : 0;
	RETURNi_(ret);
}

//## @Native int XmlReader.isEmptyElement();
METHOD XmlReader_isEmptyElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderIsEmptyElement(reader) : 0;
	RETURNi_(ret);
}

//## @Native boolean XmlReader.hasAttributes();
METHOD XmlReader_hasAttributes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderHasAttributes(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.hasValue();
METHOD XmlReader_hasValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderHasValue(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.getDepth();
METHOD XmlReader_getDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderDepth(reader) : 0;
	RETURNb_(ret);
}

//## @Native int XmlReader.getAttributeCount();
METHOD XmlReader_getAttributeCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderAttributeCount(reader) : 0;
	RETURNi_(ret);
}

//## @Native boolean XmlReader.moveToFirstAttribute();
METHOD XmlReader_moveToFirstAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderMoveToFirstAttribute(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.moveToNextAttribute();
METHOD XmlReader_moveToNextAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderMoveToNextAttribute(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.moveToElement();
METHOD XmlReader_moveToElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderMoveToElement(reader) : 0;
	RETURNb_(ret);
}

//## @Native String XmlReader.constBaseUri();
METHOD XmlReader_constBaseUri(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstBaseUri(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constEncoding();
METHOD XmlReader_constEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*)xmlTextReaderConstEncoding(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constValue();
METHOD XmlReader_constValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstValue(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constNamespaceUri();
METHOD XmlReader_constNamespaceUri(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstNamespaceUri(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constLocalName();
METHOD XmlReader_constLocalName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstLocalName(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constName();
METHOD XmlReader_constName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstName(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constXmlLang();
METHOD XmlReader_constXmlLang(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstXmlLang(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constPrefix();
METHOD XmlReader_constPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstPrefix(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}


//## @Native String XmlReader.getAttribute();
METHOD XmlReader_getAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	xmlChar * ns = String_to(xmlChar *, sfp[1]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttribute(reader,ns) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.getAttributeNo(int numer);
METHOD XmlReader_getAttributeNo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int num = (int)(sfp[1].ivalue);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttributeNo(reader, num) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.getAttributeNs(String ns, String name);
METHOD XmlReader_getAttributeNs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	xmlChar* ns   = String_to(xmlChar*, sfp[1]);
	xmlChar* name = String_to(xmlChar*, sfp[2]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttributeNs(reader,ns,name) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.lookupNameSpace(String ns);
METHOD XmlReader_lookupNameSpace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	xmlChar* ns   = String_to(xmlChar*, sfp[1]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderLookupNamespace(reader,ns) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native int XmlReader.normalization();
METHOD XmlReader_normalization(CTX ctx, knh_sfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) p_cptr(sfp[0]);
	int ret = (reader != NULL) ? xmlTextReaderNormalization(reader) : 0;
	RETURNi_(ret);
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.xml");
}

#endif

#ifdef __cplusplus
}
#endif
