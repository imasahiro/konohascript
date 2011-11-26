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
#define USE_STRUCT_Path  1
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

///* ------------------------------------------------------------------------ */
///* [XmlDoc] */
//
//static void XmlDoc_init(CTX ctx, kRawPtr *po)
//{
//	po->rawptr = NULL;
//}
//
//static void XmlDoc_free(CTX ctx, kRawPtr *po)
//{
//	if (po->rawptr != NULL) {
//		xmlFreeDoc((xmlDocPtr)po->rawptr);
//		po->rawptr = NULL;
//	}
//}
//
//static void XmlDoc_checkout(CTX ctx, kRawPtr *po, int isFailed)
//{
//	XmlDoc_free(ctx, po);
//}
//
//DEFAPI(void) defXmlDoc(CTX ctx, kclass_t cid, kclassdef_t *cdef)
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
////DEFAPI(void) constXmlDoc(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
////{
////	kapi->loadClassIntConst(ctx, cid, XmlDocConstint);
////}
//
////## @Native @Throwable XmlDoc XmlDoc.new(String version, XmlDoc _);
//KMETHOD XmlDoc_new(CTX ctx, ksfp_t *sfp _RIX)
//{
//	xmlChar* version = String_to(xmlChar*, sfp[1]);
//	xmlDocPtr doc = xmlNewDoc(version);
//	kRawPtr *po = new_RawPtr(ctx, sfp[2].p, doc);
//	RETURN_(po);
//}

//KMETHOD Xml_setAttr(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar *name  = String_to(xmlChar*, sfp[1]);
//    xmlChar *value = String_to(xmlChar*, sfp[2]);
//    xmlNewDocProp(doc, name, value);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//KMETHOD Xml_createNode(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar *name = String_to(xmlChar*, sfp[1]);
//    doc->children = xmlNewDocNode(doc, NULL, name , NULL);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",doc->children,NULL));
//}
//
//KMETHOD Xml_getRoot(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlNodePtr node = xmlDocGetRootElement(doc);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",node,NULL));
//}
//
//KMETHOD Xml_dump(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlDocPtr doc = Glue_to(xmlDocPtr, sfp[0]);
//    xmlChar* ret;
//    int   size;
//    xmlDocDumpMemory(doc,&ret,&size);
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//KMETHOD Xml_dumpEnc(CTX ctx, ksfp_t *sfp _RIX)
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
//KMETHOD XmlNode_createNode(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr parent = Glue_to(xmlNodePtr, sfp[0]);
//    xmlChar *name = String_to(xmlChar*, sfp[1]);
//    xmlChar *val  = String_to(xmlChar*, sfp[2]);
//
//    xmlNodePtr node = xmlNewChild(parent, NULL, name, val);
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",node,NULL));
//}
//
//KMETHOD XmlNode_addChild(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr parent = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr child  = (xmlNodePtr) p_cptr(sfp[1]);
//    xmlAddChild(parent,child);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//KMETHOD XmlNode_setAttr(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar *name = String_to(xmlChar *, sfp[1]);
//    xmlChar *val  = String_to(xmlChar *, sfp[2]);
//    xmlSetProp(node,name,val);
//    KNH_RETURN_void(ctx,sfp);
//}
//
//KMETHOD XmlNode_getContent(CTX ctx, ksfp_t *sfp _RIX)
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
//KMETHOD XmlNode_getName(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlChar* ret = (xmlChar *)"";
//    if(node->name){
//        ret = (xmlChar *)node->name;
//    }
//    KNH_RETURN(ctx, sfp, new_String(ctx, B((char*)ret), NULL));
//}
//
//KMETHOD XmlNode_getAttr(CTX ctx, ksfp_t *sfp _RIX)
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
//KMETHOD XmlNode_getChild(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node  = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr child = (xmlNodePtr) node->children;
//    if(child == NULL){
//        KNH_THROW__T(ctx, "XmlNode: dont have child!");
//    }
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",child,NULL));
//}
//
//KMETHOD XmlNode_getNext(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node = (xmlNodePtr) p_cptr(sfp[0]);
//    xmlNodePtr next = (xmlNodePtr) node->next;
//    if(next == NULL){
//        KNH_THROW__T(ctx, "XmlNode: dont have next!");
//    }
//    RETURN_(new_Glue(ctx,(char*)"libxml2.XmlNode",next,NULL));
//}
//
//KMETHOD XmlNode_hasChild(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    if(node->children) {
//        KNH_RETURN_boolean(ctx, sfp, 1);
//    }
//    KNH_RETURN_boolean(ctx, sfp, 0);
//}
//
//KMETHOD XmlNode_hasNext(CTX ctx, ksfp_t *sfp _RIX)
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
//KMETHOD XmlNode_dump(CTX ctx, ksfp_t *sfp _RIX)
//{
//    xmlNodePtr node= (xmlNodePtr) p_cptr(sfp[0]);
//    xmlElemDump(stdout,document,node);
//    KNH_RETURN_void(ctx,sfp);
//}
//*/
//
///* XPath */
//static void knh_xpath_gfree(CTX ctx, knh_Glue_t *g)
//{
//    xmlXPathContextPtr xctx = (xmlXPathContextPtr) g->ptr;
//    xmlXPathFreeContext(xctx);
//    xmlCleanupParser();
//}
//
//KMETHOD XPath_new(CTX ctx, ksfp_t *sfp _RIX)
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
//KMETHOD XPath_find(CTX ctx, ksfp_t *sfp _RIX)
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

static void XmlReader_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void XmlReader_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		xmlFreeTextReader((xmlTextReaderPtr)po->rawptr);
		po->rawptr = NULL;
	}
}

static void XmlReader_checkout(CTX ctx, kRawPtr *po, int isFailed)
{
	XmlReader_free(ctx, po);
}

DEFAPI(void) defXmlReader(CTX ctx, kclass_t cid, kclassdef_t *cdef)
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

DEFAPI(void) constXmlReader(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, XmlReaderConstint);
}

//## @Native @Throwable XmlReader XmlReader.new(Path _);
KMETHOD XmlReader_new(CTX ctx, ksfp_t *sfp _RIX)
{
	kPath *pth = sfp[1].pth;
	xmlTextReaderPtr reader = xmlNewTextReaderFilename(pth->ospath);
	kRawPtr *po = new_ReturnCppObject(ctx, sfp, reader, NULL);
	if(reader == NULL) {
		KNH_NTHROW2(ctx, sfp, "IO!!", "xmlNewTextReader", K_FAILED,
				KNH_LDATA(LOG_s("urn", S_totext(pth->urn)), LOG_s("ospath", pth->ospath)));
	}
	RETURN_(po);
}

//## @Native void XmlReader.close();
KMETHOD XmlReader_close(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr)(sfp[0].p)->rawptr;
	if(reader != NULL) {
		xmlTextReaderClose(reader);
	}
	RETURNvoid_();
}

//## @Native String XmlReader.getQuoteChar();
KMETHOD XmlReader_getQuoteChar(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
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
KMETHOD XmlReader_read(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr)(sfp[0].p)->rawptr;
	int ret = 0;
	if(reader != NULL) {
		ret = xmlTextReaderRead(reader);
	}
	RETURNb_(ret);
}

//## @Native int XmlReader.readState();
KMETHOD XmlReader_readState(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderReadState(reader) : 0;
	RETURNi_(ret);
}

//## @Native int XmlReader.nodeType();
KMETHOD XmlReader_nodeType(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderNodeType(reader) : 0;
	RETURNi_(ret);
}

//## @Native boolean XmlReader.isNamespaceDecl();
KMETHOD XmlReader_isNamespaceDecl(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderIsNamespaceDecl(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.isEmptyElement();
KMETHOD XmlReader_isEmptyElement(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderIsEmptyElement(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.hasAttributes();
KMETHOD XmlReader_hasAttributes(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderHasAttributes(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.hasValue();
KMETHOD XmlReader_hasValue(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderHasValue(reader) : 0;
	RETURNb_(ret);
}

//## @Native int XmlReader.getDepth();
KMETHOD XmlReader_getDepth(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderDepth(reader) : 0;
	RETURNi_(ret);
}

//## @Native int XmlReader.getAttributeCount();
KMETHOD XmlReader_getAttributeCount(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderAttributeCount(reader) : 0;
	RETURNi_(ret);
}

//## @Native boolean XmlReader.moveToFirstAttribute();
KMETHOD XmlReader_moveToFirstAttribute(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderMoveToFirstAttribute(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.moveToNextAttribute();
KMETHOD XmlReader_moveToNextAttribute(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderMoveToNextAttribute(reader) : 0;
	RETURNb_(ret);
}

//## @Native boolean XmlReader.moveToElement();
KMETHOD XmlReader_moveToElement(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderMoveToElement(reader) : 0;
	RETURNb_(ret);
}

//## @Native String XmlReader.constBaseUri();
KMETHOD XmlReader_constBaseUri(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstBaseUri(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constEncoding();
KMETHOD XmlReader_constEncoding(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*)xmlTextReaderConstEncoding(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constValue();
KMETHOD XmlReader_constValue(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstValue(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constNamespaceUri();
KMETHOD XmlReader_constNamespaceUri(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstNamespaceUri(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constLocalName();
KMETHOD XmlReader_constLocalName(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstLocalName(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constName();
KMETHOD XmlReader_constName(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstName(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constXmlLang();
KMETHOD XmlReader_constXmlLang(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstXmlLang(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.constPrefix();
KMETHOD XmlReader_constPrefix(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	char* ret = (reader != NULL) ? (char*) xmlTextReaderConstPrefix(reader) : NULL;
	RETURN_(new_String(ctx, ret));
}


//## @Native String XmlReader.getAttribute();
KMETHOD XmlReader_getAttribute(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	xmlChar * ns = String_to(xmlChar *, sfp[1]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttribute(reader,ns) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.getAttributeNo(int numer);
KMETHOD XmlReader_getAttributeNo(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int num = (int)(sfp[1].ivalue);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttributeNo(reader, num) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.getAttributeNs(String ns, String name);
KMETHOD XmlReader_getAttributeNs(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	xmlChar* ns   = String_to(xmlChar*, sfp[1]);
	xmlChar* name = String_to(xmlChar*, sfp[2]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderGetAttributeNs(reader,ns,name) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native String XmlReader.lookupNameSpace(String ns);
KMETHOD XmlReader_lookupNameSpace(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	xmlChar* ns   = String_to(xmlChar*, sfp[1]);
	char* ret = (reader != NULL) ? (char*) xmlTextReaderLookupNamespace(reader,ns) : NULL;
	RETURN_(new_String(ctx, ret));
}

//## @Native int XmlReader.normalization();
KMETHOD XmlReader_normalization(CTX ctx, ksfp_t *sfp _RIX)
{
	xmlTextReaderPtr reader = (xmlTextReaderPtr) (sfp[0].p)->rawptr;
	int ret = (reader != NULL) ? xmlTextReaderNormalization(reader) : 0;
	RETURNi_(ret);
}

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.xml");
}

#endif

#ifdef __cplusplus
}
#endif
