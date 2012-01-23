/* converted from java package java.lang.reflect */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_lang_ClassFormatError;
class Java_lang_ClassLoader;
class Java_lang_ReflectiveOperationException;
class Java_lang_RuntimeException;
class Java_lang_Throwable;
class Java_lang_annotation_Annotation;
class Java_security_BasicPermission;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_lang_reflect_AccessibleObject;
class Java_lang_reflect_AnnotatedElement;
class Java_lang_reflect_Array;
class Java_lang_reflect_Constructor extends Java_lang_reflect_AccessibleObject;
class Java_lang_reflect_Field extends Java_lang_reflect_AccessibleObject;
class Java_lang_reflect_GenericArrayType;
class Java_lang_reflect_GenericDeclaration;
class Java_lang_reflect_GenericSignatureFormatError extends Java_lang_ClassFormatError;
class Java_lang_reflect_InvocationHandler;
class Java_lang_reflect_InvocationTargetException extends Java_lang_ReflectiveOperationException;
class Java_lang_reflect_MalformedParameterizedTypeException extends Java_lang_RuntimeException;
class Java_lang_reflect_Member;
class Java_lang_reflect_Method extends Java_lang_reflect_AccessibleObject;
class Java_lang_reflect_Modifier;
class Java_lang_reflect_ParameterizedType;
class Java_lang_reflect_Proxy;
class Java_lang_reflect_ReflectPermission extends Java_security_BasicPermission;
class Java_lang_reflect_Type;
class Java_lang_reflect_TypeVariable;
class Java_lang_reflect_UndeclaredThrowableException extends Java_lang_RuntimeException;
class Java_lang_reflect_WildcardType;

/*------------------------------------------------------------*/
/* class java.lang.reflect.AccessibleObject */
class Java_lang_reflect_AccessibleObject {
	// implements java.lang.reflect.AnnotatedElement
	/*-- Method --*/
	@Virtual @Overload Java_lang_annotation_Annotation getAnnotation(Class p0);
	@Virtual @Overload Java_lang_annotation_Annotation[] getAnnotations();
	@Virtual @Overload Java_lang_annotation_Annotation[] getDeclaredAnnotations();
	@Virtual @Overload boolean isAccessible();
	@Virtual @Overload boolean isAnnotationPresent(Class p0);
	@Virtual @Overload void setAccessible(Java_lang_reflect_AccessibleObject[] p0, boolean p1);
	@Virtual @Overload void setAccessible(boolean p0);
}

/* interface java.lang.reflect.AnnotatedElement */
class Java_lang_reflect_AnnotatedElement {
	/*-- Method --*/
	@Virtual @Overload Java_lang_annotation_Annotation getAnnotation(Class p0);
	@Virtual @Overload Java_lang_annotation_Annotation[] getAnnotations();
	@Virtual @Overload Java_lang_annotation_Annotation[] getDeclaredAnnotations();
	@Virtual @Overload boolean isAnnotationPresent(Class p0);
}

/* class java.lang.reflect.Array */
class Java_lang_reflect_Array {
	/*-- Method --*/
	@Virtual @Overload Object get(Object p0, int p1);
	@Virtual @Overload boolean getBoolean(Object p0, int p1);
	@Virtual @Overload int getByte(Object p0, int p1);
	@Virtual @Overload int getChar(Object p0, int p1);
	@Virtual @Overload double getDouble(Object p0, int p1);
	@Virtual @Overload float getFloat(Object p0, int p1);
	@Virtual @Overload int getInt(Object p0, int p1);
	@Virtual @Overload int getLength(Object p0);
	@Virtual @Overload long getLong(Object p0, int p1);
	@Virtual @Overload int getShort(Object p0, int p1);
	@Virtual @Overload Object newInstance(Class p0, int p1);
	@Virtual @Overload Object newInstance(Class p0, int[] p1);
	@Virtual @Overload void set(Object p0, int p1, Object p2);
	@Virtual @Overload void setBoolean(Object p0, int p1, boolean p2);
	@Virtual @Overload void setByte(Object p0, int p1, int p2);
	@Virtual @Overload void setChar(Object p0, int p1, int p2);
	@Virtual @Overload void setDouble(Object p0, int p1, double p2);
	@Virtual @Overload void setFloat(Object p0, int p1, float p2);
	@Virtual @Overload void setInt(Object p0, int p1, int p2);
	@Virtual @Overload void setLong(Object p0, int p1, long p2);
	@Virtual @Overload void setShort(Object p0, int p1, int p2);
}

/* class java.lang.reflect.Constructor */
class Java_lang_reflect_Constructor extends Java_lang_reflect_AccessibleObject {
	// implements java.lang.reflect.GenericDeclaration, java.lang.reflect.Member
	/*-- Method --*/
	@Virtual @Overload Class getDeclaringClass();
	@Virtual @Overload Class[] getExceptionTypes();
	@Virtual @Overload Java_lang_reflect_Type[] getGenericExceptionTypes();
	@Virtual @Overload Java_lang_reflect_Type[] getGenericParameterTypes();
	@Virtual @Overload int getModifiers();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_lang_annotation_Annotation[][] getParameterAnnotations();
	@Virtual @Overload Class[] getParameterTypes();
	@Virtual @Overload Java_lang_reflect_TypeVariable[] getTypeParameters();
	@Virtual @Overload boolean isSynthetic();
	@Virtual @Overload boolean isVarArgs();
	@Virtual @Overload Object newInstance(Object[] p0);
	@Virtual @Overload String toGenericString();
}

/* class java.lang.reflect.Field */
class Java_lang_reflect_Field extends Java_lang_reflect_AccessibleObject {
	// implements java.lang.reflect.Member
	/*-- Method --*/
	@Virtual @Overload Object get(Object p0);
	@Virtual @Overload boolean getBoolean(Object p0);
	@Virtual @Overload int getByte(Object p0);
	@Virtual @Overload int getChar(Object p0);
	@Virtual @Overload Class getDeclaringClass();
	@Virtual @Overload double getDouble(Object p0);
	@Virtual @Overload float getFloat(Object p0);
	@Virtual @Overload Java_lang_reflect_Type getGenericType();
	@Virtual @Overload int getInt(Object p0);
	@Virtual @Overload long getLong(Object p0);
	@Virtual @Overload int getModifiers();
	@Virtual @Overload String getName();
	@Virtual @Overload int getShort(Object p0);
	@Virtual @Overload Class getType();
	@Virtual @Overload boolean isEnumConstant();
	@Virtual @Overload boolean isSynthetic();
	@Virtual @Overload void set(Object p0, Object p1);
	@Virtual @Overload void setBoolean(Object p0, boolean p1);
	@Virtual @Overload void setByte(Object p0, int p1);
	@Virtual @Overload void setChar(Object p0, int p1);
	@Virtual @Overload void setDouble(Object p0, double p1);
	@Virtual @Overload void setFloat(Object p0, float p1);
	@Virtual @Overload void setInt(Object p0, int p1);
	@Virtual @Overload void setLong(Object p0, long p1);
	@Virtual @Overload void setShort(Object p0, int p1);
	@Virtual @Overload String toGenericString();
}

/* interface java.lang.reflect.GenericArrayType */
class Java_lang_reflect_GenericArrayType {
	// implements java.lang.reflect.Type
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_Type getGenericComponentType();
}

/* interface java.lang.reflect.GenericDeclaration */
class Java_lang_reflect_GenericDeclaration {
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_TypeVariable[] getTypeParameters();
}

/* class java.lang.reflect.GenericSignatureFormatError */
class Java_lang_reflect_GenericSignatureFormatError extends Java_lang_ClassFormatError {
}
Java_lang_reflect_GenericSignatureFormatError Java_lang_reflect_GenericSignatureFormatError.new();

/* interface java.lang.reflect.InvocationHandler */
class Java_lang_reflect_InvocationHandler {
	/*-- Method --*/
	@Virtual @Overload Object invoke(Object p0, Java_lang_reflect_Method p1, Object[] p2);
}

/* class java.lang.reflect.InvocationTargetException */
class Java_lang_reflect_InvocationTargetException extends Java_lang_ReflectiveOperationException {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Throwable getTargetException();
}
@Overload Java_lang_reflect_InvocationTargetException Java_lang_reflect_InvocationTargetException.new(Java_lang_Throwable p0);
@Overload Java_lang_reflect_InvocationTargetException Java_lang_reflect_InvocationTargetException.new(Java_lang_Throwable p0, String p1);

/* class java.lang.reflect.MalformedParameterizedTypeException */
class Java_lang_reflect_MalformedParameterizedTypeException extends Java_lang_RuntimeException {
}
Java_lang_reflect_MalformedParameterizedTypeException Java_lang_reflect_MalformedParameterizedTypeException.new();

/* interface java.lang.reflect.Member */
class Java_lang_reflect_Member {
	/*-- Method --*/
	@Virtual @Overload Class getDeclaringClass();
	@Virtual @Overload int getModifiers();
	@Virtual @Overload String getName();
	@Virtual @Overload boolean isSynthetic();
}

/* class java.lang.reflect.Method */
class Java_lang_reflect_Method extends Java_lang_reflect_AccessibleObject {
	// implements java.lang.reflect.GenericDeclaration, java.lang.reflect.Member
	/*-- Method --*/
	@Virtual @Overload Class getDeclaringClass();
	@Virtual @Overload Object getDefaultValue();
	@Virtual @Overload Class[] getExceptionTypes();
	@Virtual @Overload Java_lang_reflect_Type[] getGenericExceptionTypes();
	@Virtual @Overload Java_lang_reflect_Type[] getGenericParameterTypes();
	@Virtual @Overload Java_lang_reflect_Type getGenericReturnType();
	@Virtual @Overload int getModifiers();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_lang_annotation_Annotation[][] getParameterAnnotations();
	@Virtual @Overload Class[] getParameterTypes();
	@Virtual @Overload Class getReturnType();
	@Virtual @Overload Java_lang_reflect_TypeVariable[] getTypeParameters();
	@Virtual @Overload Object invoke(Object p0, Object[] p1);
	@Virtual @Overload boolean isBridge();
	@Virtual @Overload boolean isSynthetic();
	@Virtual @Overload boolean isVarArgs();
	@Virtual @Overload String toGenericString();
}

/* class java.lang.reflect.Modifier */
class Java_lang_reflect_Modifier {
	/*-- Method --*/
	@Virtual @Overload int classModifiers();
	@Virtual @Overload int constructorModifiers();
	@Virtual @Overload int fieldModifiers();
	@Virtual @Overload int interfaceModifiers();
	@Virtual @Overload boolean isAbstract(int p0);
	@Virtual @Overload boolean isFinal(int p0);
	@Virtual @Overload boolean isInterface(int p0);
	@Virtual @Overload boolean isNative(int p0);
	@Virtual @Overload boolean isPrivate(int p0);
	@Virtual @Overload boolean isProtected(int p0);
	@Virtual @Overload boolean isPublic(int p0);
	@Virtual @Overload boolean isStatic(int p0);
	@Virtual @Overload boolean isStrict(int p0);
	@Virtual @Overload boolean isSynchronized(int p0);
	@Virtual @Overload boolean isTransient(int p0);
	@Virtual @Overload boolean isVolatile(int p0);
	@Virtual @Overload int methodModifiers();
	@Virtual @Overload String toString(int p0);
}
Java_lang_reflect_Modifier Java_lang_reflect_Modifier.new();

/* interface java.lang.reflect.ParameterizedType */
class Java_lang_reflect_ParameterizedType {
	// implements java.lang.reflect.Type
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_Type[] getActualTypeArguments();
	@Virtual @Overload Java_lang_reflect_Type getOwnerType();
	@Virtual @Overload Java_lang_reflect_Type getRawType();
}

/* class java.lang.reflect.Proxy */
class Java_lang_reflect_Proxy {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_InvocationHandler getInvocationHandler(Object p0);
	@Virtual @Overload Class getProxyClass(Java_lang_ClassLoader p0, Class[] p1);
	@Virtual @Overload boolean isProxyClass(Class p0);
	@Virtual @Overload Object newProxyInstance(Java_lang_ClassLoader p0, Class[] p1, Java_lang_reflect_InvocationHandler p2);
}

/* class java.lang.reflect.ReflectPermission */
class Java_lang_reflect_ReflectPermission extends Java_security_BasicPermission {
}
@Overload Java_lang_reflect_ReflectPermission Java_lang_reflect_ReflectPermission.new(String p0);
@Overload Java_lang_reflect_ReflectPermission Java_lang_reflect_ReflectPermission.new(String p0, String p1);

/* interface java.lang.reflect.Type */
class Java_lang_reflect_Type {
}

/* interface java.lang.reflect.TypeVariable */
class Java_lang_reflect_TypeVariable {
	// implements java.lang.reflect.Type
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_Type[] getBounds();
	@Virtual @Overload Java_lang_reflect_GenericDeclaration getGenericDeclaration();
	@Virtual @Overload String getName();
}

/* class java.lang.reflect.UndeclaredThrowableException */
class Java_lang_reflect_UndeclaredThrowableException extends Java_lang_RuntimeException {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Throwable getUndeclaredThrowable();
}
@Overload Java_lang_reflect_UndeclaredThrowableException Java_lang_reflect_UndeclaredThrowableException.new(Java_lang_Throwable p0);
@Overload Java_lang_reflect_UndeclaredThrowableException Java_lang_reflect_UndeclaredThrowableException.new(Java_lang_Throwable p0, String p1);

/* interface java.lang.reflect.WildcardType */
class Java_lang_reflect_WildcardType {
	// implements java.lang.reflect.Type
	/*-- Method --*/
	@Virtual @Overload Java_lang_reflect_Type[] getLowerBounds();
	@Virtual @Overload Java_lang_reflect_Type[] getUpperBounds();
}


/*------------------------------------------------------------*/
/* short names */
AccessibleObject = Java_lang_reflect_AccessibleObject
AnnotatedElement = Java_lang_reflect_AnnotatedElement
Constructor = Java_lang_reflect_Constructor
Field = Java_lang_reflect_Field
GenericArrayType = Java_lang_reflect_GenericArrayType
GenericDeclaration = Java_lang_reflect_GenericDeclaration
GenericSignatureFormatError = Java_lang_reflect_GenericSignatureFormatError
InvocationHandler = Java_lang_reflect_InvocationHandler
InvocationTargetException = Java_lang_reflect_InvocationTargetException
MalformedParameterizedTypeException = Java_lang_reflect_MalformedParameterizedTypeException
Member = Java_lang_reflect_Member
Method = Java_lang_reflect_Method
Modifier = Java_lang_reflect_Modifier
ParameterizedType = Java_lang_reflect_ParameterizedType
Proxy = Java_lang_reflect_Proxy
ReflectPermission = Java_lang_reflect_ReflectPermission
Type = Java_lang_reflect_Type
TypeVariable = Java_lang_reflect_TypeVariable
UndeclaredThrowableException = Java_lang_reflect_UndeclaredThrowableException
WildcardType = Java_lang_reflect_WildcardType
