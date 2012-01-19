/* converted from java package java.lang */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_io_Console;
class Java_io_File;
class Java_io_FileDescriptor;
class Java_io_InputStream;
class Java_io_OutputStream;
class Java_io_PrintStream;
class Java_io_PrintWriter;
class Java_lang_ProcessBuilder_Redirect;
class Java_lang_Thread_State;
class Java_lang_Thread_UncaughtExceptionHandler;
class Java_lang_annotation_Annotation;
class Java_lang_reflect_Constructor;
class Java_lang_reflect_Field;
class Java_lang_reflect_Method;
class Java_lang_reflect_Type;
class Java_lang_reflect_TypeVariable;
class Java_net_InetAddress;
class Java_net_URL;
class Java_nio_CharBuffer;
class Java_nio_channels_Channel;
class Java_nio_charset_Charset;
class Java_security_BasicPermission;
class Java_security_Permission;
class Java_security_ProtectionDomain;
class Java_util_Enumeration;
class Java_util_Iterator;
class Java_util_List;
class Java_util_Locale;
class Java_util_Map;
class Java_util_Properties;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_lang_Throwable;
class Java_lang_Error extends Java_lang_Throwable;
class Java_lang_LinkageError extends Java_lang_Error;
class Java_lang_IncompatibleClassChangeError extends Java_lang_LinkageError;
class Java_lang_AbstractMethodError extends Java_lang_IncompatibleClassChangeError;
class Java_lang_Appendable;
class Java_lang_Exception extends Java_lang_Throwable;
class Java_lang_RuntimeException extends Java_lang_Exception;
class Java_lang_ArithmeticException extends Java_lang_RuntimeException;
class Java_lang_IndexOutOfBoundsException extends Java_lang_RuntimeException;
class Java_lang_ArrayIndexOutOfBoundsException extends Java_lang_IndexOutOfBoundsException;
class Java_lang_ArrayStoreException extends Java_lang_RuntimeException;
class Java_lang_AssertionError extends Java_lang_Error;
class Java_lang_AutoCloseable;
class Java_lang_Boolean;
class Java_lang_BootstrapMethodError extends Java_lang_LinkageError;
class Java_lang_Number;
class Java_lang_Byte extends Java_lang_Number;
class Java_lang_CharSequence;
class Java_lang_Character;
class Java_lang_ClassCastException extends Java_lang_RuntimeException;
class Java_lang_ClassCircularityError extends Java_lang_LinkageError;
class Java_lang_ClassFormatError extends Java_lang_LinkageError;
class Java_lang_ClassLoader;
class Java_lang_ReflectiveOperationException extends Java_lang_Exception;
class Java_lang_ClassNotFoundException extends Java_lang_ReflectiveOperationException;
class Java_lang_ClassValue;
class Java_lang_CloneNotSupportedException extends Java_lang_Exception;
class Java_lang_Cloneable;
class Java_lang_Comparable;
class Java_lang_Compiler;
class Java_lang_Deprecated;
class Java_lang_Double extends Java_lang_Number;
class Java_lang_Enum;
class Java_lang_EnumConstantNotPresentException extends Java_lang_RuntimeException;
class Java_lang_ExceptionInInitializerError extends Java_lang_LinkageError;
class Java_lang_Float extends Java_lang_Number;
class Java_lang_IllegalAccessError extends Java_lang_IncompatibleClassChangeError;
class Java_lang_IllegalAccessException extends Java_lang_ReflectiveOperationException;
class Java_lang_IllegalArgumentException extends Java_lang_RuntimeException;
class Java_lang_IllegalMonitorStateException extends Java_lang_RuntimeException;
class Java_lang_IllegalStateException extends Java_lang_RuntimeException;
class Java_lang_IllegalThreadStateException extends Java_lang_IllegalArgumentException;
class Java_lang_ThreadLocal;
class Java_lang_InheritableThreadLocal extends Java_lang_ThreadLocal;
class Java_lang_InstantiationError extends Java_lang_IncompatibleClassChangeError;
class Java_lang_InstantiationException extends Java_lang_ReflectiveOperationException;
class Java_lang_Integer extends Java_lang_Number;
class Java_lang_VirtualMachineError extends Java_lang_Error;
class Java_lang_InternalError extends Java_lang_VirtualMachineError;
class Java_lang_InterruptedException extends Java_lang_Exception;
class Java_lang_Iterable;
class Java_lang_Long extends Java_lang_Number;
class Java_lang_Math;
class Java_lang_NegativeArraySizeException extends Java_lang_RuntimeException;
class Java_lang_NoClassDefFoundError extends Java_lang_LinkageError;
class Java_lang_NoSuchFieldError extends Java_lang_IncompatibleClassChangeError;
class Java_lang_NoSuchFieldException extends Java_lang_ReflectiveOperationException;
class Java_lang_NoSuchMethodError extends Java_lang_IncompatibleClassChangeError;
class Java_lang_NoSuchMethodException extends Java_lang_ReflectiveOperationException;
class Java_lang_NullPointerException extends Java_lang_RuntimeException;
class Java_lang_NumberFormatException extends Java_lang_IllegalArgumentException;
class Java_lang_OutOfMemoryError extends Java_lang_VirtualMachineError;
class Java_lang_Override;
class Java_lang_Package;
class Java_lang_Process;
class Java_lang_ProcessBuilder;
class Java_lang_Readable;
class Java_lang_Runnable;
class Java_lang_Runtime;
class Java_lang_RuntimePermission extends Java_security_BasicPermission;
class Java_lang_SafeVarargs;
class Java_lang_SecurityException extends Java_lang_RuntimeException;
class Java_lang_SecurityManager;
class Java_lang_Short extends Java_lang_Number;
class Java_lang_StackOverflowError extends Java_lang_VirtualMachineError;
class Java_lang_StackTraceElement;
class Java_lang_StrictMath;
class Java_lang_StringBuffer;
class Java_lang_StringBuilder;
class Java_lang_StringIndexOutOfBoundsException extends Java_lang_IndexOutOfBoundsException;
class Java_lang_SuppressWarnings;
class Java_lang_System;
class Java_lang_Thread;
class Java_lang_ThreadDeath extends Java_lang_Error;
class Java_lang_ThreadGroup;
class Java_lang_TypeNotPresentException extends Java_lang_RuntimeException;
class Java_lang_UnknownError extends Java_lang_VirtualMachineError;
class Java_lang_UnsatisfiedLinkError extends Java_lang_LinkageError;
class Java_lang_UnsupportedClassVersionError extends Java_lang_ClassFormatError;
class Java_lang_UnsupportedOperationException extends Java_lang_RuntimeException;
class Java_lang_VerifyError extends Java_lang_LinkageError;
class Java_lang_Void;

/*------------------------------------------------------------*/
/* class java.lang.AbstractMethodError */
class Java_lang_AbstractMethodError extends Java_lang_IncompatibleClassChangeError {
}
@Overload Java_lang_AbstractMethodError Java_lang_AbstractMethodError.new();
@Overload Java_lang_AbstractMethodError Java_lang_AbstractMethodError.new(String p0);
/* interface java.lang.Appendable */
class Java_lang_Appendable {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(int p0);
}
/* class java.lang.ArithmeticException */
class Java_lang_ArithmeticException extends Java_lang_RuntimeException {
}
@Overload Java_lang_ArithmeticException Java_lang_ArithmeticException.new();
@Overload Java_lang_ArithmeticException Java_lang_ArithmeticException.new(String p0);
/* class java.lang.ArrayIndexOutOfBoundsException */
class Java_lang_ArrayIndexOutOfBoundsException extends Java_lang_IndexOutOfBoundsException {
}
@Overload Java_lang_ArrayIndexOutOfBoundsException Java_lang_ArrayIndexOutOfBoundsException.new();
@Overload Java_lang_ArrayIndexOutOfBoundsException Java_lang_ArrayIndexOutOfBoundsException.new(int p0);
@Overload Java_lang_ArrayIndexOutOfBoundsException Java_lang_ArrayIndexOutOfBoundsException.new(String p0);
/* class java.lang.ArrayStoreException */
class Java_lang_ArrayStoreException extends Java_lang_RuntimeException {
}
@Overload Java_lang_ArrayStoreException Java_lang_ArrayStoreException.new();
@Overload Java_lang_ArrayStoreException Java_lang_ArrayStoreException.new(String p0);
/* class java.lang.AssertionError */
class Java_lang_AssertionError extends Java_lang_Error {
}
@Overload Java_lang_AssertionError Java_lang_AssertionError.new();
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(Object p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(boolean p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(int p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(int p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(long p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(float p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(double p0);
@Overload Java_lang_AssertionError Java_lang_AssertionError.new(String p0, Java_lang_Throwable p1);
/* interface java.lang.AutoCloseable */
class Java_lang_AutoCloseable {
	/*-- Method --*/
	@Virtual @Overload void close();
}
/* class java.lang.Boolean */
class Java_lang_Boolean {
	/*-- Method --*/
	@Virtual @Overload boolean booleanValue();
	@Virtual @Overload int compare(boolean p0, boolean p1);
	@Virtual @Overload int compareTo(Java_lang_Boolean p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload boolean getBoolean(String p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean parseBoolean(String p0);
	@Virtual @Overload String toString(boolean p0);
	@Virtual @Overload String toString();
	@Virtual @Overload Java_lang_Boolean valueOf(boolean p0);
	@Virtual @Overload Java_lang_Boolean valueOf(String p0);
}
@Overload Java_lang_Boolean Java_lang_Boolean.new(boolean p0);
@Overload Java_lang_Boolean Java_lang_Boolean.new(String p0);
/* class java.lang.BootstrapMethodError */
class Java_lang_BootstrapMethodError extends Java_lang_LinkageError {
}
@Overload Java_lang_BootstrapMethodError Java_lang_BootstrapMethodError.new();
@Overload Java_lang_BootstrapMethodError Java_lang_BootstrapMethodError.new(String p0);
@Overload Java_lang_BootstrapMethodError Java_lang_BootstrapMethodError.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_BootstrapMethodError Java_lang_BootstrapMethodError.new(Java_lang_Throwable p0);
/* class java.lang.Byte */
class Java_lang_Byte extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int compare(int p0, int p1);
	@Virtual @Overload int compareTo(Java_lang_Byte p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_lang_Byte decode(String p0);
	@Virtual @Overload int parseByte(String p0, int p1);
	@Virtual @Overload int parseByte(String p0);
	@Virtual @Overload String toString(int p0);
	@Virtual @Overload Java_lang_Byte valueOf(int p0);
	@Virtual @Overload Java_lang_Byte valueOf(String p0, int p1);
	@Virtual @Overload Java_lang_Byte valueOf(String p0);
}
@Overload Java_lang_Byte Java_lang_Byte.new(int p0);
@Overload Java_lang_Byte Java_lang_Byte.new(String p0);
/* interface java.lang.CharSequence */
class Java_lang_CharSequence {
	/*-- Method --*/
	@Virtual @Overload int charAt(int p0);
	@Virtual @Overload int length();
	@Virtual @Overload Java_lang_CharSequence subSequence(int p0, int p1);
	@Virtual @Overload String toString();
}
/* class java.lang.Character */
class Java_lang_Character {
	/*-- Method --*/
	@Virtual @Overload int charCount(int p0);
	@Virtual @Overload int charValue();
	@Virtual @Overload int codePointAt(Java_lang_CharSequence p0, int p1);
	@Virtual @Overload int codePointAt(int[] p0, int p1);
	@Virtual @Overload int codePointAt(int[] p0, int p1, int p2);
	@Virtual @Overload int codePointBefore(Java_lang_CharSequence p0, int p1);
	@Virtual @Overload int codePointBefore(int[] p0, int p1);
	@Virtual @Overload int codePointBefore(int[] p0, int p1, int p2);
	@Virtual @Overload int codePointCount(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload int codePointCount(int[] p0, int p1, int p2);
	@Virtual @Overload int compare(int p0, int p1);
	@Virtual @Overload int compareTo(Java_lang_Character p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload int digit(int p0, int p1);
	@Virtual @Overload int digit(int p0, int p1);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int forDigit(int p0, int p1);
	@Virtual @Overload int getDirectionality(int p0);
	@Virtual @Overload int getDirectionality(int p0);
	@Virtual @Overload String getName(int p0);
	@Virtual @Overload int getNumericValue(int p0);
	@Virtual @Overload int getNumericValue(int p0);
	@Virtual @Overload int getType(int p0);
	@Virtual @Overload int getType(int p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload int highSurrogate(int p0);
	@Virtual @Overload boolean isAlphabetic(int p0);
	@Virtual @Overload boolean isBmpCodePoint(int p0);
	@Virtual @Overload boolean isDefined(int p0);
	@Virtual @Overload boolean isDefined(int p0);
	@Virtual @Overload boolean isDigit(int p0);
	@Virtual @Overload boolean isDigit(int p0);
	@Virtual @Overload boolean isHighSurrogate(int p0);
	@Virtual @Overload boolean isISOControl(int p0);
	@Virtual @Overload boolean isISOControl(int p0);
	@Virtual @Overload boolean isIdentifierIgnorable(int p0);
	@Virtual @Overload boolean isIdentifierIgnorable(int p0);
	@Virtual @Overload boolean isIdeographic(int p0);
	@Virtual @Overload boolean isJavaIdentifierPart(int p0);
	@Virtual @Overload boolean isJavaIdentifierPart(int p0);
	@Virtual @Overload boolean isJavaIdentifierStart(int p0);
	@Virtual @Overload boolean isJavaIdentifierStart(int p0);
	@Virtual @Overload boolean isLetter(int p0);
	@Virtual @Overload boolean isLetter(int p0);
	@Virtual @Overload boolean isLetterOrDigit(int p0);
	@Virtual @Overload boolean isLetterOrDigit(int p0);
	@Virtual @Overload boolean isLowSurrogate(int p0);
	@Virtual @Overload boolean isLowerCase(int p0);
	@Virtual @Overload boolean isLowerCase(int p0);
	@Virtual @Overload boolean isMirrored(int p0);
	@Virtual @Overload boolean isMirrored(int p0);
	@Virtual @Overload boolean isSpaceChar(int p0);
	@Virtual @Overload boolean isSpaceChar(int p0);
	@Virtual @Overload boolean isSupplementaryCodePoint(int p0);
	@Virtual @Overload boolean isSurrogate(int p0);
	@Virtual @Overload boolean isSurrogatePair(int p0, int p1);
	@Virtual @Overload boolean isTitleCase(int p0);
	@Virtual @Overload boolean isTitleCase(int p0);
	@Virtual @Overload boolean isUnicodeIdentifierPart(int p0);
	@Virtual @Overload boolean isUnicodeIdentifierPart(int p0);
	@Virtual @Overload boolean isUnicodeIdentifierStart(int p0);
	@Virtual @Overload boolean isUnicodeIdentifierStart(int p0);
	@Virtual @Overload boolean isUpperCase(int p0);
	@Virtual @Overload boolean isUpperCase(int p0);
	@Virtual @Overload boolean isValidCodePoint(int p0);
	@Virtual @Overload boolean isWhitespace(int p0);
	@Virtual @Overload boolean isWhitespace(int p0);
	@Virtual @Overload int lowSurrogate(int p0);
	@Virtual @Overload int offsetByCodePoints(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload int offsetByCodePoints(int[] p0, int p1, int p2, int p3, int p4);
	@Virtual @Overload int reverseBytes(int p0);
	@Virtual @Overload int toChars(int p0, int[] p1, int p2);
	@Virtual @Overload int[] toChars(int p0);
	@Virtual @Overload int toCodePoint(int p0, int p1);
	@Virtual @Overload int toLowerCase(int p0);
	@Virtual @Overload int toLowerCase(int p0);
	@Virtual @Overload String toString();
	@Virtual @Overload String toString(int p0);
	@Virtual @Overload int toTitleCase(int p0);
	@Virtual @Overload int toTitleCase(int p0);
	@Virtual @Overload int toUpperCase(int p0);
	@Virtual @Overload int toUpperCase(int p0);
	@Virtual @Overload Java_lang_Character valueOf(int p0);
}
Java_lang_Character Java_lang_Character.new(int p0);
/* class java.lang.Class */
class Class {
	/*-- Method --*/
	@Virtual @Overload Class asSubclass(Class p0);
	@Virtual @Overload Object cast(Object p0);
	@Virtual @Overload boolean desiredAssertionStatus();
	@Virtual @Overload Class forName(String p0);
	@Virtual @Overload Class forName(String p0, boolean p1, Java_lang_ClassLoader p2);
	@Virtual @Overload Java_lang_annotation_Annotation getAnnotation(Class p0);
	@Virtual @Overload Java_lang_annotation_Annotation[] getAnnotations();
	@Virtual @Overload String getCanonicalName();
	@Virtual @Overload Java_lang_ClassLoader getClassLoader();
	@Virtual @Overload Class[] getClasses();
	@Virtual @Overload Class getComponentType();
	@Virtual @Overload Java_lang_reflect_Constructor getConstructor(Class[] p0);
	@Virtual @Overload Java_lang_reflect_Constructor[] getConstructors();
	@Virtual @Overload Java_lang_annotation_Annotation[] getDeclaredAnnotations();
	@Virtual @Overload Class[] getDeclaredClasses();
	@Virtual @Overload Java_lang_reflect_Constructor getDeclaredConstructor(Class[] p0);
	@Virtual @Overload Java_lang_reflect_Constructor[] getDeclaredConstructors();
	@Virtual @Overload Java_lang_reflect_Field getDeclaredField(String p0);
	@Virtual @Overload Java_lang_reflect_Field[] getDeclaredFields();
	@Virtual @Overload Java_lang_reflect_Method getDeclaredMethod(String p0, Class[] p1);
	@Virtual @Overload Java_lang_reflect_Method[] getDeclaredMethods();
	@Virtual @Overload Class getDeclaringClass();
	@Virtual @Overload Class getEnclosingClass();
	@Virtual @Overload Java_lang_reflect_Constructor getEnclosingConstructor();
	@Virtual @Overload Java_lang_reflect_Method getEnclosingMethod();
	@Virtual @Overload Object[] getEnumConstants();
	@Virtual @Overload Java_lang_reflect_Field getField(String p0);
	@Virtual @Overload Java_lang_reflect_Field[] getFields();
	@Virtual @Overload Java_lang_reflect_Type[] getGenericInterfaces();
	@Virtual @Overload Java_lang_reflect_Type getGenericSuperclass();
	@Virtual @Overload Class[] getInterfaces();
	@Virtual @Overload Java_lang_reflect_Method getMethod(String p0, Class[] p1);
	@Virtual @Overload Java_lang_reflect_Method[] getMethods();
	@Virtual @Overload int getModifiers();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_lang_Package getPackage();
	@Virtual @Overload Java_security_ProtectionDomain getProtectionDomain();
	@Virtual @Overload Java_net_URL getResource(String p0);
	@Virtual @Overload Java_io_InputStream getResourceAsStream(String p0);
	@Virtual @Overload Object[] getSigners();
	@Virtual @Overload String getSimpleName();
	@Virtual @Overload Class getSuperclass();
	@Virtual @Overload Java_lang_reflect_TypeVariable[] getTypeParameters();
	@Virtual @Overload boolean isAnnotation();
	@Virtual @Overload boolean isAnnotationPresent(Class p0);
	@Virtual @Overload boolean isAnonymousClass();
	@Virtual @Overload boolean isArray();
	@Virtual @Overload boolean isAssignableFrom(Class p0);
	@Virtual @Overload boolean isEnum();
	@Virtual @Overload boolean isInstance(Object p0);
	@Virtual @Overload boolean isInterface();
	@Virtual @Overload boolean isLocalClass();
	@Virtual @Overload boolean isMemberClass();
	@Virtual @Overload boolean isPrimitive();
	@Virtual @Overload boolean isSynthetic();
	@Virtual @Overload Object newInstance();
	@Virtual @Overload String toString();
}
/* class java.lang.ClassCastException */
class Java_lang_ClassCastException extends Java_lang_RuntimeException {
}
@Overload Java_lang_ClassCastException Java_lang_ClassCastException.new();
@Overload Java_lang_ClassCastException Java_lang_ClassCastException.new(String p0);
/* class java.lang.ClassCircularityError */
class Java_lang_ClassCircularityError extends Java_lang_LinkageError {
}
@Overload Java_lang_ClassCircularityError Java_lang_ClassCircularityError.new();
@Overload Java_lang_ClassCircularityError Java_lang_ClassCircularityError.new(String p0);
/* class java.lang.ClassFormatError */
class Java_lang_ClassFormatError extends Java_lang_LinkageError {
}
@Overload Java_lang_ClassFormatError Java_lang_ClassFormatError.new();
@Overload Java_lang_ClassFormatError Java_lang_ClassFormatError.new(String p0);
/* class java.lang.ClassLoader */
class Java_lang_ClassLoader {
	/*-- Method --*/
	@Virtual @Overload void clearAssertionStatus();
	@Virtual @Overload Java_lang_ClassLoader getParent();
	@Virtual @Overload Java_net_URL getResource(String p0);
	@Virtual @Overload Java_io_InputStream getResourceAsStream(String p0);
	@Virtual @Overload Java_util_Enumeration getResources(String p0);
	@Virtual @Overload Java_lang_ClassLoader getSystemClassLoader();
	@Virtual @Overload Java_net_URL getSystemResource(String p0);
	@Virtual @Overload Java_io_InputStream getSystemResourceAsStream(String p0);
	@Virtual @Overload Java_util_Enumeration getSystemResources(String p0);
	@Virtual @Overload Class loadClass(String p0);
	@Virtual @Overload void setClassAssertionStatus(String p0, boolean p1);
	@Virtual @Overload void setDefaultAssertionStatus(boolean p0);
	@Virtual @Overload void setPackageAssertionStatus(String p0, boolean p1);
}
/* class java.lang.ClassNotFoundException */
class Java_lang_ClassNotFoundException extends Java_lang_ReflectiveOperationException {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Throwable getException();
}
@Overload Java_lang_ClassNotFoundException Java_lang_ClassNotFoundException.new();
@Overload Java_lang_ClassNotFoundException Java_lang_ClassNotFoundException.new(String p0);
@Overload Java_lang_ClassNotFoundException Java_lang_ClassNotFoundException.new(String p0, Java_lang_Throwable p1);
/* class java.lang.ClassValue */
class Java_lang_ClassValue {
	/*-- Method --*/
	@Virtual @Overload Object get(Class p0);
	@Virtual @Overload void remove(Class p0);
}
/* class java.lang.CloneNotSupportedException */
class Java_lang_CloneNotSupportedException extends Java_lang_Exception {
}
@Overload Java_lang_CloneNotSupportedException Java_lang_CloneNotSupportedException.new();
@Overload Java_lang_CloneNotSupportedException Java_lang_CloneNotSupportedException.new(String p0);
/* interface java.lang.Cloneable */
class Java_lang_Cloneable {
}
/* interface java.lang.Comparable */
class Java_lang_Comparable {
	/*-- Method --*/
	@Virtual @Overload int compareTo(Object p0);
}
/* class java.lang.Compiler */
class Java_lang_Compiler {
	/*-- Method --*/
	@Virtual @Overload Object command(Object p0);
	@Virtual @Overload boolean compileClass(Class p0);
	@Virtual @Overload boolean compileClasses(String p0);
	@Virtual @Overload void disable();
	@Virtual @Overload void enable();
}
/* interface java.lang.Deprecated */
class Java_lang_Deprecated {
}
/* class java.lang.Double */
class Java_lang_Double extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int compare(double p0, double p1);
	@Virtual @Overload int compareTo(Java_lang_Double p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload long doubleToLongBits(double p0);
	@Virtual @Overload long doubleToRawLongBits(double p0);
	@Virtual @Overload boolean isInfinite(double p0);
	@Virtual @Overload boolean isInfinite();
	@Virtual @Overload boolean isNaN(double p0);
	@Virtual @Overload boolean isNaN();
	@Virtual @Overload double longBitsToDouble(long p0);
	@Virtual @Overload double parseDouble(String p0);
	@Virtual @Overload String toHexString(double p0);
	@Virtual @Overload String toString(double p0);
	@Virtual @Overload Java_lang_Double valueOf(String p0);
	@Virtual @Overload Java_lang_Double valueOf(double p0);
}
@Overload Java_lang_Double Java_lang_Double.new(double p0);
@Overload Java_lang_Double Java_lang_Double.new(String p0);
/* class java.lang.Enum */
class Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload int compareTo(Java_lang_Enum p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Class getDeclaringClass();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String name();
	@Virtual @Overload int ordinal();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_lang_Enum valueOf(Class p0, String p1);
}
/* class java.lang.EnumConstantNotPresentException */
class Java_lang_EnumConstantNotPresentException extends Java_lang_RuntimeException {
	/*-- Method --*/
	@Virtual @Overload String constantName();
	@Virtual @Overload Class enumType();
}
Java_lang_EnumConstantNotPresentException Java_lang_EnumConstantNotPresentException.new(Class p0, String p1);
/* class java.lang.Error */
class Java_lang_Error extends Java_lang_Throwable {
}
@Overload Java_lang_Error Java_lang_Error.new();
@Overload Java_lang_Error Java_lang_Error.new(String p0);
@Overload Java_lang_Error Java_lang_Error.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_Error Java_lang_Error.new(Java_lang_Throwable p0);
/* class java.lang.Exception */
class Java_lang_Exception extends Java_lang_Throwable {
}
@Overload Java_lang_Exception Java_lang_Exception.new();
@Overload Java_lang_Exception Java_lang_Exception.new(String p0);
@Overload Java_lang_Exception Java_lang_Exception.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_Exception Java_lang_Exception.new(Java_lang_Throwable p0);
/* class java.lang.ExceptionInInitializerError */
class Java_lang_ExceptionInInitializerError extends Java_lang_LinkageError {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Throwable getException();
}
@Overload Java_lang_ExceptionInInitializerError Java_lang_ExceptionInInitializerError.new();
@Overload Java_lang_ExceptionInInitializerError Java_lang_ExceptionInInitializerError.new(Java_lang_Throwable p0);
@Overload Java_lang_ExceptionInInitializerError Java_lang_ExceptionInInitializerError.new(String p0);
/* class java.lang.Float */
class Java_lang_Float extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int compare(float p0, float p1);
	@Virtual @Overload int compareTo(Java_lang_Float p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload int floatToIntBits(float p0);
	@Virtual @Overload int floatToRawIntBits(float p0);
	@Virtual @Overload float intBitsToFloat(int p0);
	@Virtual @Overload boolean isInfinite(float p0);
	@Virtual @Overload boolean isInfinite();
	@Virtual @Overload boolean isNaN(float p0);
	@Virtual @Overload boolean isNaN();
	@Virtual @Overload float parseFloat(String p0);
	@Virtual @Overload String toHexString(float p0);
	@Virtual @Overload String toString(float p0);
	@Virtual @Overload Java_lang_Float valueOf(String p0);
	@Virtual @Overload Java_lang_Float valueOf(float p0);
}
@Overload Java_lang_Float Java_lang_Float.new(float p0);
@Overload Java_lang_Float Java_lang_Float.new(double p0);
@Overload Java_lang_Float Java_lang_Float.new(String p0);
/* class java.lang.IllegalAccessError */
class Java_lang_IllegalAccessError extends Java_lang_IncompatibleClassChangeError {
}
@Overload Java_lang_IllegalAccessError Java_lang_IllegalAccessError.new();
@Overload Java_lang_IllegalAccessError Java_lang_IllegalAccessError.new(String p0);
/* class java.lang.IllegalAccessException */
class Java_lang_IllegalAccessException extends Java_lang_ReflectiveOperationException {
}
@Overload Java_lang_IllegalAccessException Java_lang_IllegalAccessException.new();
@Overload Java_lang_IllegalAccessException Java_lang_IllegalAccessException.new(String p0);
/* class java.lang.IllegalArgumentException */
class Java_lang_IllegalArgumentException extends Java_lang_RuntimeException {
}
@Overload Java_lang_IllegalArgumentException Java_lang_IllegalArgumentException.new();
@Overload Java_lang_IllegalArgumentException Java_lang_IllegalArgumentException.new(String p0);
@Overload Java_lang_IllegalArgumentException Java_lang_IllegalArgumentException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_IllegalArgumentException Java_lang_IllegalArgumentException.new(Java_lang_Throwable p0);
/* class java.lang.IllegalMonitorStateException */
class Java_lang_IllegalMonitorStateException extends Java_lang_RuntimeException {
}
@Overload Java_lang_IllegalMonitorStateException Java_lang_IllegalMonitorStateException.new();
@Overload Java_lang_IllegalMonitorStateException Java_lang_IllegalMonitorStateException.new(String p0);
/* class java.lang.IllegalStateException */
class Java_lang_IllegalStateException extends Java_lang_RuntimeException {
}
@Overload Java_lang_IllegalStateException Java_lang_IllegalStateException.new();
@Overload Java_lang_IllegalStateException Java_lang_IllegalStateException.new(String p0);
@Overload Java_lang_IllegalStateException Java_lang_IllegalStateException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_IllegalStateException Java_lang_IllegalStateException.new(Java_lang_Throwable p0);
/* class java.lang.IllegalThreadStateException */
class Java_lang_IllegalThreadStateException extends Java_lang_IllegalArgumentException {
}
@Overload Java_lang_IllegalThreadStateException Java_lang_IllegalThreadStateException.new();
@Overload Java_lang_IllegalThreadStateException Java_lang_IllegalThreadStateException.new(String p0);
/* class java.lang.IncompatibleClassChangeError */
class Java_lang_IncompatibleClassChangeError extends Java_lang_LinkageError {
}
@Overload Java_lang_IncompatibleClassChangeError Java_lang_IncompatibleClassChangeError.new();
@Overload Java_lang_IncompatibleClassChangeError Java_lang_IncompatibleClassChangeError.new(String p0);
/* class java.lang.IndexOutOfBoundsException */
class Java_lang_IndexOutOfBoundsException extends Java_lang_RuntimeException {
}
@Overload Java_lang_IndexOutOfBoundsException Java_lang_IndexOutOfBoundsException.new();
@Overload Java_lang_IndexOutOfBoundsException Java_lang_IndexOutOfBoundsException.new(String p0);
/* class java.lang.InheritableThreadLocal */
class Java_lang_InheritableThreadLocal extends Java_lang_ThreadLocal {
}
Java_lang_InheritableThreadLocal Java_lang_InheritableThreadLocal.new();
/* class java.lang.InstantiationError */
class Java_lang_InstantiationError extends Java_lang_IncompatibleClassChangeError {
}
@Overload Java_lang_InstantiationError Java_lang_InstantiationError.new();
@Overload Java_lang_InstantiationError Java_lang_InstantiationError.new(String p0);
/* class java.lang.InstantiationException */
class Java_lang_InstantiationException extends Java_lang_ReflectiveOperationException {
}
@Overload Java_lang_InstantiationException Java_lang_InstantiationException.new();
@Overload Java_lang_InstantiationException Java_lang_InstantiationException.new(String p0);
/* class java.lang.Integer */
class Java_lang_Integer extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int bitCount(int p0);
	@Virtual @Overload int compare(int p0, int p1);
	@Virtual @Overload int compareTo(Java_lang_Integer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_lang_Integer decode(String p0);
	@Virtual @Overload Java_lang_Integer getInteger(String p0);
	@Virtual @Overload Java_lang_Integer getInteger(String p0, int p1);
	@Virtual @Overload Java_lang_Integer getInteger(String p0, Java_lang_Integer p1);
	@Virtual @Overload int highestOneBit(int p0);
	@Virtual @Overload int lowestOneBit(int p0);
	@Virtual @Overload int numberOfLeadingZeros(int p0);
	@Virtual @Overload int numberOfTrailingZeros(int p0);
	@Virtual @Overload int parseInt(String p0, int p1);
	@Virtual @Overload int parseInt(String p0);
	@Virtual @Overload int reverse(int p0);
	@Virtual @Overload int reverseBytes(int p0);
	@Virtual @Overload int rotateLeft(int p0, int p1);
	@Virtual @Overload int rotateRight(int p0, int p1);
	@Virtual @Overload int signum(int p0);
	@Virtual @Overload String toBinaryString(int p0);
	@Virtual @Overload String toHexString(int p0);
	@Virtual @Overload String toOctalString(int p0);
	@Virtual @Overload String toString(int p0, int p1);
	@Virtual @Overload String toString(int p0);
	@Virtual @Overload Java_lang_Integer valueOf(String p0, int p1);
	@Virtual @Overload Java_lang_Integer valueOf(String p0);
	@Virtual @Overload Java_lang_Integer valueOf(int p0);
}
@Overload Java_lang_Integer Java_lang_Integer.new(int p0);
@Overload Java_lang_Integer Java_lang_Integer.new(String p0);
/* class java.lang.InternalError */
class Java_lang_InternalError extends Java_lang_VirtualMachineError {
}
@Overload Java_lang_InternalError Java_lang_InternalError.new();
@Overload Java_lang_InternalError Java_lang_InternalError.new(String p0);
/* class java.lang.InterruptedException */
class Java_lang_InterruptedException extends Java_lang_Exception {
}
@Overload Java_lang_InterruptedException Java_lang_InterruptedException.new();
@Overload Java_lang_InterruptedException Java_lang_InterruptedException.new(String p0);
/* interface java.lang.Iterable */
class Java_lang_Iterable {
	/*-- Method --*/
	@Virtual @Overload Java_util_Iterator iterator();
}
/* class java.lang.LinkageError */
class Java_lang_LinkageError extends Java_lang_Error {
}
@Overload Java_lang_LinkageError Java_lang_LinkageError.new();
@Overload Java_lang_LinkageError Java_lang_LinkageError.new(String p0);
@Overload Java_lang_LinkageError Java_lang_LinkageError.new(String p0, Java_lang_Throwable p1);
/* class java.lang.Long */
class Java_lang_Long extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int bitCount(long p0);
	@Virtual @Overload int compare(long p0, long p1);
	@Virtual @Overload int compareTo(Java_lang_Long p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_lang_Long decode(String p0);
	@Virtual @Overload Java_lang_Long getLong(String p0);
	@Virtual @Overload Java_lang_Long getLong(String p0, long p1);
	@Virtual @Overload Java_lang_Long getLong(String p0, Java_lang_Long p1);
	@Virtual @Overload long highestOneBit(long p0);
	@Virtual @Overload long lowestOneBit(long p0);
	@Virtual @Overload int numberOfLeadingZeros(long p0);
	@Virtual @Overload int numberOfTrailingZeros(long p0);
	@Virtual @Overload long parseLong(String p0, int p1);
	@Virtual @Overload long parseLong(String p0);
	@Virtual @Overload long reverse(long p0);
	@Virtual @Overload long reverseBytes(long p0);
	@Virtual @Overload long rotateLeft(long p0, int p1);
	@Virtual @Overload long rotateRight(long p0, int p1);
	@Virtual @Overload int signum(long p0);
	@Virtual @Overload String toBinaryString(long p0);
	@Virtual @Overload String toHexString(long p0);
	@Virtual @Overload String toOctalString(long p0);
	@Virtual @Overload String toString(long p0, int p1);
	@Virtual @Overload String toString(long p0);
	@Virtual @Overload Java_lang_Long valueOf(String p0, int p1);
	@Virtual @Overload Java_lang_Long valueOf(String p0);
	@Virtual @Overload Java_lang_Long valueOf(long p0);
}
@Overload Java_lang_Long Java_lang_Long.new(long p0);
@Overload Java_lang_Long Java_lang_Long.new(String p0);
/* class java.lang.Math */
class Java_lang_Math {
	/*-- Method --*/
	@Virtual @Overload double IEEEremainder(double p0, double p1);
	@Virtual @Overload int abs(int p0);
	@Virtual @Overload long abs(long p0);
	@Virtual @Overload float abs(float p0);
	@Virtual @Overload double abs(double p0);
	@Virtual @Overload double acos(double p0);
	@Virtual @Overload double asin(double p0);
	@Virtual @Overload double atan(double p0);
	@Virtual @Overload double atan2(double p0, double p1);
	@Virtual @Overload double cbrt(double p0);
	@Virtual @Overload double ceil(double p0);
	@Virtual @Overload double copySign(double p0, double p1);
	@Virtual @Overload float copySign(float p0, float p1);
	@Virtual @Overload double cos(double p0);
	@Virtual @Overload double cosh(double p0);
	@Virtual @Overload double exp(double p0);
	@Virtual @Overload double expm1(double p0);
	@Virtual @Overload double floor(double p0);
	@Virtual @Overload int getExponent(float p0);
	@Virtual @Overload int getExponent(double p0);
	@Virtual @Overload double hypot(double p0, double p1);
	@Virtual @Overload double log(double p0);
	@Virtual @Overload double log10(double p0);
	@Virtual @Overload double log1p(double p0);
	@Virtual @Overload int max(int p0, int p1);
	@Virtual @Overload long max(long p0, long p1);
	@Virtual @Overload float max(float p0, float p1);
	@Virtual @Overload double max(double p0, double p1);
	@Virtual @Overload int min(int p0, int p1);
	@Virtual @Overload long min(long p0, long p1);
	@Virtual @Overload float min(float p0, float p1);
	@Virtual @Overload double min(double p0, double p1);
	@Virtual @Overload double nextAfter(double p0, double p1);
	@Virtual @Overload float nextAfter(float p0, double p1);
	@Virtual @Overload double nextUp(double p0);
	@Virtual @Overload float nextUp(float p0);
	@Virtual @Overload double pow(double p0, double p1);
	@Virtual @Overload double random();
	@Virtual @Overload double rint(double p0);
	@Virtual @Overload int round(float p0);
	@Virtual @Overload long round(double p0);
	@Virtual @Overload double scalb(double p0, int p1);
	@Virtual @Overload float scalb(float p0, int p1);
	@Virtual @Overload double signum(double p0);
	@Virtual @Overload float signum(float p0);
	@Virtual @Overload double sin(double p0);
	@Virtual @Overload double sinh(double p0);
	@Virtual @Overload double sqrt(double p0);
	@Virtual @Overload double tan(double p0);
	@Virtual @Overload double tanh(double p0);
	@Virtual @Overload double toDegrees(double p0);
	@Virtual @Overload double toRadians(double p0);
	@Virtual @Overload double ulp(double p0);
	@Virtual @Overload float ulp(float p0);
}
/* class java.lang.NegativeArraySizeException */
class Java_lang_NegativeArraySizeException extends Java_lang_RuntimeException {
}
@Overload Java_lang_NegativeArraySizeException Java_lang_NegativeArraySizeException.new();
@Overload Java_lang_NegativeArraySizeException Java_lang_NegativeArraySizeException.new(String p0);
/* class java.lang.NoClassDefFoundError */
class Java_lang_NoClassDefFoundError extends Java_lang_LinkageError {
}
@Overload Java_lang_NoClassDefFoundError Java_lang_NoClassDefFoundError.new();
@Overload Java_lang_NoClassDefFoundError Java_lang_NoClassDefFoundError.new(String p0);
/* class java.lang.NoSuchFieldError */
class Java_lang_NoSuchFieldError extends Java_lang_IncompatibleClassChangeError {
}
@Overload Java_lang_NoSuchFieldError Java_lang_NoSuchFieldError.new();
@Overload Java_lang_NoSuchFieldError Java_lang_NoSuchFieldError.new(String p0);
/* class java.lang.NoSuchFieldException */
class Java_lang_NoSuchFieldException extends Java_lang_ReflectiveOperationException {
}
@Overload Java_lang_NoSuchFieldException Java_lang_NoSuchFieldException.new();
@Overload Java_lang_NoSuchFieldException Java_lang_NoSuchFieldException.new(String p0);
/* class java.lang.NoSuchMethodError */
class Java_lang_NoSuchMethodError extends Java_lang_IncompatibleClassChangeError {
}
@Overload Java_lang_NoSuchMethodError Java_lang_NoSuchMethodError.new();
@Overload Java_lang_NoSuchMethodError Java_lang_NoSuchMethodError.new(String p0);
/* class java.lang.NoSuchMethodException */
class Java_lang_NoSuchMethodException extends Java_lang_ReflectiveOperationException {
}
@Overload Java_lang_NoSuchMethodException Java_lang_NoSuchMethodException.new();
@Overload Java_lang_NoSuchMethodException Java_lang_NoSuchMethodException.new(String p0);
/* class java.lang.NullPointerException */
class Java_lang_NullPointerException extends Java_lang_RuntimeException {
}
@Overload Java_lang_NullPointerException Java_lang_NullPointerException.new();
@Overload Java_lang_NullPointerException Java_lang_NullPointerException.new(String p0);
/* class java.lang.Number */
class Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int byteValue();
	@Virtual @Overload double doubleValue();
	@Virtual @Overload float floatValue();
	@Virtual @Overload int intValue();
	@Virtual @Overload long longValue();
	@Virtual @Overload int shortValue();
}
Java_lang_Number Java_lang_Number.new();
/* class java.lang.NumberFormatException */
class Java_lang_NumberFormatException extends Java_lang_IllegalArgumentException {
}
@Overload Java_lang_NumberFormatException Java_lang_NumberFormatException.new();
@Overload Java_lang_NumberFormatException Java_lang_NumberFormatException.new(String p0);
/* class java.lang.Object */
class Object {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload Class getClass();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void notify();
	@Virtual @Overload void notifyAll();
	@Virtual @Overload String toString();
	@Virtual @Overload void wait(long p0);
	@Virtual @Overload void wait(long p0, int p1);
	@Virtual @Overload void wait();
}
Object Object.new();
/* class java.lang.OutOfMemoryError */
class Java_lang_OutOfMemoryError extends Java_lang_VirtualMachineError {
}
@Overload Java_lang_OutOfMemoryError Java_lang_OutOfMemoryError.new();
@Overload Java_lang_OutOfMemoryError Java_lang_OutOfMemoryError.new(String p0);
/* interface java.lang.Override */
class Java_lang_Override {
}
/* class java.lang.Package */
class Java_lang_Package {
	/*-- Method --*/
	@Virtual @Overload Java_lang_annotation_Annotation getAnnotation(Class p0);
	@Virtual @Overload Java_lang_annotation_Annotation[] getAnnotations();
	@Virtual @Overload Java_lang_annotation_Annotation[] getDeclaredAnnotations();
	@Virtual @Overload String getImplementationTitle();
	@Virtual @Overload String getImplementationVendor();
	@Virtual @Overload String getImplementationVersion();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_lang_Package getPackage(String p0);
	@Virtual @Overload Java_lang_Package[] getPackages();
	@Virtual @Overload String getSpecificationTitle();
	@Virtual @Overload String getSpecificationVendor();
	@Virtual @Overload String getSpecificationVersion();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isAnnotationPresent(Class p0);
	@Virtual @Overload boolean isCompatibleWith(String p0);
	@Virtual @Overload boolean isSealed();
	@Virtual @Overload boolean isSealed(Java_net_URL p0);
	@Virtual @Overload String toString();
}
/* class java.lang.Process */
class Java_lang_Process {
	/*-- Method --*/
	@Virtual @Overload void destroy();
	@Virtual @Overload int exitValue();
	@Virtual @Overload Java_io_InputStream getErrorStream();
	@Virtual @Overload Java_io_InputStream getInputStream();
	@Virtual @Overload Java_io_OutputStream getOutputStream();
	@Virtual @Overload int waitFor();
}
Java_lang_Process Java_lang_Process.new();
/* class java.lang.ProcessBuilder */
class Java_lang_ProcessBuilder {
	/*-- Method --*/
	@Virtual @Overload Java_lang_ProcessBuilder command(Java_util_List p0);
	@Virtual @Overload Java_lang_ProcessBuilder command(String[] p0);
	@Virtual @Overload Java_util_List command();
	@Virtual @Overload Java_io_File directory();
	@Virtual @Overload Java_lang_ProcessBuilder directory(Java_io_File p0);
	@Virtual @Overload Java_util_Map environment();
	@Virtual @Overload Java_lang_ProcessBuilder inheritIO();
	@Virtual @Overload Java_lang_ProcessBuilder redirectError(Java_lang_ProcessBuilder_Redirect p0);
	@Virtual @Overload Java_lang_ProcessBuilder redirectError(Java_io_File p0);
	@Virtual @Overload Java_lang_ProcessBuilder_Redirect redirectError();
	@Virtual @Overload boolean redirectErrorStream();
	@Virtual @Overload Java_lang_ProcessBuilder redirectErrorStream(boolean p0);
	@Virtual @Overload Java_lang_ProcessBuilder redirectInput(Java_lang_ProcessBuilder_Redirect p0);
	@Virtual @Overload Java_lang_ProcessBuilder redirectInput(Java_io_File p0);
	@Virtual @Overload Java_lang_ProcessBuilder_Redirect redirectInput();
	@Virtual @Overload Java_lang_ProcessBuilder redirectOutput(Java_lang_ProcessBuilder_Redirect p0);
	@Virtual @Overload Java_lang_ProcessBuilder redirectOutput(Java_io_File p0);
	@Virtual @Overload Java_lang_ProcessBuilder_Redirect redirectOutput();
	@Virtual @Overload Java_lang_Process start();
}
@Overload Java_lang_ProcessBuilder Java_lang_ProcessBuilder.new(Java_util_List p0);
@Overload Java_lang_ProcessBuilder Java_lang_ProcessBuilder.new(String[] p0);
/* interface java.lang.Readable */
class Java_lang_Readable {
	/*-- Method --*/
	@Virtual @Overload int read(Java_nio_CharBuffer p0);
}
/* class java.lang.ReflectiveOperationException */
class Java_lang_ReflectiveOperationException extends Java_lang_Exception {
}
@Overload Java_lang_ReflectiveOperationException Java_lang_ReflectiveOperationException.new();
@Overload Java_lang_ReflectiveOperationException Java_lang_ReflectiveOperationException.new(String p0);
@Overload Java_lang_ReflectiveOperationException Java_lang_ReflectiveOperationException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_ReflectiveOperationException Java_lang_ReflectiveOperationException.new(Java_lang_Throwable p0);
/* interface java.lang.Runnable */
class Java_lang_Runnable {
	/*-- Method --*/
	@Virtual @Overload void run();
}
/* class java.lang.Runtime */
class Java_lang_Runtime {
	/*-- Method --*/
	@Virtual @Overload void addShutdownHook(Java_lang_Thread p0);
	@Virtual @Overload int availableProcessors();
	@Virtual @Overload Java_lang_Process exec(String p0);
	@Virtual @Overload Java_lang_Process exec(String p0, String[] p1);
	@Virtual @Overload Java_lang_Process exec(String p0, String[] p1, Java_io_File p2);
	@Virtual @Overload Java_lang_Process exec(String[] p0);
	@Virtual @Overload Java_lang_Process exec(String[] p0, String[] p1);
	@Virtual @Overload Java_lang_Process exec(String[] p0, String[] p1, Java_io_File p2);
	@Virtual @Overload void exit(int p0);
	@Virtual @Overload long freeMemory();
	@Virtual @Overload void gc();
	@Virtual @Overload Java_lang_Runtime getRuntime();
	@Virtual @Overload void halt(int p0);
	@Virtual @Overload void load(String p0);
	@Virtual @Overload void loadLibrary(String p0);
	@Virtual @Overload long maxMemory();
	@Virtual @Overload boolean removeShutdownHook(Java_lang_Thread p0);
	@Virtual @Overload void runFinalization();
	@Virtual @Overload long totalMemory();
	@Virtual @Overload void traceInstructions(boolean p0);
	@Virtual @Overload void traceMethodCalls(boolean p0);
}
/* class java.lang.RuntimeException */
class Java_lang_RuntimeException extends Java_lang_Exception {
}
@Overload Java_lang_RuntimeException Java_lang_RuntimeException.new();
@Overload Java_lang_RuntimeException Java_lang_RuntimeException.new(String p0);
@Overload Java_lang_RuntimeException Java_lang_RuntimeException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_RuntimeException Java_lang_RuntimeException.new(Java_lang_Throwable p0);
/* class java.lang.RuntimePermission */
class Java_lang_RuntimePermission extends Java_security_BasicPermission {
}
@Overload Java_lang_RuntimePermission Java_lang_RuntimePermission.new(String p0);
@Overload Java_lang_RuntimePermission Java_lang_RuntimePermission.new(String p0, String p1);
/* interface java.lang.SafeVarargs */
class Java_lang_SafeVarargs {
}
/* class java.lang.SecurityException */
class Java_lang_SecurityException extends Java_lang_RuntimeException {
}
@Overload Java_lang_SecurityException Java_lang_SecurityException.new();
@Overload Java_lang_SecurityException Java_lang_SecurityException.new(String p0);
@Overload Java_lang_SecurityException Java_lang_SecurityException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_SecurityException Java_lang_SecurityException.new(Java_lang_Throwable p0);
/* class java.lang.SecurityManager */
class Java_lang_SecurityManager {
	/*-- Method --*/
	@Virtual @Overload void checkAccept(String p0, int p1);
	@Virtual @Overload void checkAccess(Java_lang_Thread p0);
	@Virtual @Overload void checkAccess(Java_lang_ThreadGroup p0);
	@Virtual @Overload void checkAwtEventQueueAccess();
	@Virtual @Overload void checkConnect(String p0, int p1);
	@Virtual @Overload void checkConnect(String p0, int p1, Object p2);
	@Virtual @Overload void checkCreateClassLoader();
	@Virtual @Overload void checkDelete(String p0);
	@Virtual @Overload void checkExec(String p0);
	@Virtual @Overload void checkExit(int p0);
	@Virtual @Overload void checkLink(String p0);
	@Virtual @Overload void checkListen(int p0);
	@Virtual @Overload void checkMemberAccess(Class p0, int p1);
	@Virtual @Overload void checkMulticast(Java_net_InetAddress p0);
	@Virtual @Overload void checkPackageAccess(String p0);
	@Virtual @Overload void checkPackageDefinition(String p0);
	@Virtual @Overload void checkPermission(Java_security_Permission p0);
	@Virtual @Overload void checkPermission(Java_security_Permission p0, Object p1);
	@Virtual @Overload void checkPrintJobAccess();
	@Virtual @Overload void checkPropertiesAccess();
	@Virtual @Overload void checkPropertyAccess(String p0);
	@Virtual @Overload void checkRead(Java_io_FileDescriptor p0);
	@Virtual @Overload void checkRead(String p0);
	@Virtual @Overload void checkRead(String p0, Object p1);
	@Virtual @Overload void checkSecurityAccess(String p0);
	@Virtual @Overload void checkSetFactory();
	@Virtual @Overload void checkSystemClipboardAccess();
	@Virtual @Overload boolean checkTopLevelWindow(Object p0);
	@Virtual @Overload void checkWrite(Java_io_FileDescriptor p0);
	@Virtual @Overload void checkWrite(String p0);
	@Virtual @Overload Object getSecurityContext();
	@Virtual @Overload Java_lang_ThreadGroup getThreadGroup();
}
Java_lang_SecurityManager Java_lang_SecurityManager.new();
/* class java.lang.Short */
class Java_lang_Short extends Java_lang_Number {
	/*-- Method --*/
	@Virtual @Overload int compare(int p0, int p1);
	@Virtual @Overload int compareTo(Java_lang_Short p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_lang_Short decode(String p0);
	@Virtual @Overload int parseShort(String p0, int p1);
	@Virtual @Overload int parseShort(String p0);
	@Virtual @Overload int reverseBytes(int p0);
	@Virtual @Overload String toString(int p0);
	@Virtual @Overload Java_lang_Short valueOf(String p0, int p1);
	@Virtual @Overload Java_lang_Short valueOf(String p0);
	@Virtual @Overload Java_lang_Short valueOf(int p0);
}
@Overload Java_lang_Short Java_lang_Short.new(int p0);
@Overload Java_lang_Short Java_lang_Short.new(String p0);
/* class java.lang.StackOverflowError */
class Java_lang_StackOverflowError extends Java_lang_VirtualMachineError {
}
@Overload Java_lang_StackOverflowError Java_lang_StackOverflowError.new();
@Overload Java_lang_StackOverflowError Java_lang_StackOverflowError.new(String p0);
/* class java.lang.StackTraceElement */
class Java_lang_StackTraceElement {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload String getClassName();
	@Virtual @Overload String getFileName();
	@Virtual @Overload int getLineNumber();
	@Virtual @Overload String getMethodName();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isNativeMethod();
	@Virtual @Overload String toString();
}
Java_lang_StackTraceElement Java_lang_StackTraceElement.new(String p0, String p1, String p2, int p3);
/* class java.lang.StrictMath */
class Java_lang_StrictMath {
	/*-- Method --*/
	@Virtual @Overload double IEEEremainder(double p0, double p1);
	@Virtual @Overload int abs(int p0);
	@Virtual @Overload long abs(long p0);
	@Virtual @Overload float abs(float p0);
	@Virtual @Overload double abs(double p0);
	@Virtual @Overload double acos(double p0);
	@Virtual @Overload double asin(double p0);
	@Virtual @Overload double atan(double p0);
	@Virtual @Overload double atan2(double p0, double p1);
	@Virtual @Overload double cbrt(double p0);
	@Virtual @Overload double ceil(double p0);
	@Virtual @Overload double copySign(double p0, double p1);
	@Virtual @Overload float copySign(float p0, float p1);
	@Virtual @Overload double cos(double p0);
	@Virtual @Overload double cosh(double p0);
	@Virtual @Overload double exp(double p0);
	@Virtual @Overload double expm1(double p0);
	@Virtual @Overload double floor(double p0);
	@Virtual @Overload int getExponent(float p0);
	@Virtual @Overload int getExponent(double p0);
	@Virtual @Overload double hypot(double p0, double p1);
	@Virtual @Overload double log(double p0);
	@Virtual @Overload double log10(double p0);
	@Virtual @Overload double log1p(double p0);
	@Virtual @Overload int max(int p0, int p1);
	@Virtual @Overload long max(long p0, long p1);
	@Virtual @Overload float max(float p0, float p1);
	@Virtual @Overload double max(double p0, double p1);
	@Virtual @Overload int min(int p0, int p1);
	@Virtual @Overload long min(long p0, long p1);
	@Virtual @Overload float min(float p0, float p1);
	@Virtual @Overload double min(double p0, double p1);
	@Virtual @Overload double nextAfter(double p0, double p1);
	@Virtual @Overload float nextAfter(float p0, double p1);
	@Virtual @Overload double nextUp(double p0);
	@Virtual @Overload float nextUp(float p0);
	@Virtual @Overload double pow(double p0, double p1);
	@Virtual @Overload double random();
	@Virtual @Overload double rint(double p0);
	@Virtual @Overload int round(float p0);
	@Virtual @Overload long round(double p0);
	@Virtual @Overload double scalb(double p0, int p1);
	@Virtual @Overload float scalb(float p0, int p1);
	@Virtual @Overload double signum(double p0);
	@Virtual @Overload float signum(float p0);
	@Virtual @Overload double sin(double p0);
	@Virtual @Overload double sinh(double p0);
	@Virtual @Overload double sqrt(double p0);
	@Virtual @Overload double tan(double p0);
	@Virtual @Overload double tanh(double p0);
	@Virtual @Overload double toDegrees(double p0);
	@Virtual @Overload double toRadians(double p0);
	@Virtual @Overload double ulp(double p0);
	@Virtual @Overload float ulp(float p0);
}
/* class java.lang.String */
class String {
	/*-- Method --*/
	@Virtual @Overload int charAt(int p0);
	@Virtual @Overload int codePointAt(int p0);
	@Virtual @Overload int codePointBefore(int p0);
	@Virtual @Overload int codePointCount(int p0, int p1);
	@Virtual @Overload int compareTo(String p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload int compareToIgnoreCase(String p0);
	@Virtual @Overload String concat(String p0);
	@Virtual @Overload boolean contains(Java_lang_CharSequence p0);
	@Virtual @Overload boolean contentEquals(Java_lang_StringBuffer p0);
	@Virtual @Overload boolean contentEquals(Java_lang_CharSequence p0);
	@Virtual @Overload String copyValueOf(int[] p0, int p1, int p2);
	@Virtual @Overload String copyValueOf(int[] p0);
	@Virtual @Overload boolean endsWith(String p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload boolean equalsIgnoreCase(String p0);
	//@Virtual @Overload String format(String p0, Object[] p1);
	//@Virtual @Overload String format(Java_util_Locale p0, String p1, Object[] p2);
	@Virtual @Overload int[] getBytes(String p0);
	@Virtual @Overload int[] getBytes(Java_nio_charset_Charset p0);
	@Virtual @Overload int[] getBytes();
	@Virtual @Overload void getChars(int p0, int p1, int[] p2, int p3);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload int indexOf(int p0);
	@Virtual @Overload int indexOf(int p0, int p1);
	@Virtual @Overload int indexOf(String p0);
	@Virtual @Overload int indexOf(String p0, int p1);
	@Virtual @Overload String intern();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload int lastIndexOf(int p0);
	@Virtual @Overload int lastIndexOf(int p0, int p1);
	@Virtual @Overload int lastIndexOf(String p0);
	@Virtual @Overload int lastIndexOf(String p0, int p1);
	@Virtual @Overload int length();
	@Virtual @Overload boolean matches(String p0);
	@Virtual @Overload int offsetByCodePoints(int p0, int p1);
	@Virtual @Overload boolean regionMatches(int p0, String p1, int p2, int p3);
	@Virtual @Overload boolean regionMatches(boolean p0, int p1, String p2, int p3, int p4);
	@Virtual @Overload String replace(int p0, int p1);
	@Virtual @Overload String replace(Java_lang_CharSequence p0, Java_lang_CharSequence p1);
	@Virtual @Overload String replaceAll(String p0, String p1);
	@Virtual @Overload String replaceFirst(String p0, String p1);
	@Virtual @Overload String[] split(String p0, int p1);
	@Virtual @Overload String[] split(String p0);
	@Virtual @Overload boolean startsWith(String p0, int p1);
	@Virtual @Overload boolean startsWith(String p0);
	@Virtual @Overload Java_lang_CharSequence subSequence(int p0, int p1);
	@Virtual @Overload String substring(int p0);
	@Virtual @Overload String substring(int p0, int p1);
	@Virtual @Overload int[] toCharArray();
	@Virtual @Overload String toLowerCase(Java_util_Locale p0);
	@Virtual @Overload String toLowerCase();
	@Virtual @Overload String toString();
	@Virtual @Overload String toUpperCase(Java_util_Locale p0);
	@Virtual @Overload String toUpperCase();
	@Virtual @Overload String trim();
	@Virtual @Overload String valueOf(Object p0);
	@Virtual @Overload String valueOf(int[] p0);
	@Virtual @Overload String valueOf(int[] p0, int p1, int p2);
	@Virtual @Overload String valueOf(boolean p0);
	@Virtual @Overload String valueOf(int p0);
	@Virtual @Overload String valueOf(int p0);
	@Virtual @Overload String valueOf(long p0);
	@Virtual @Overload String valueOf(float p0);
	@Virtual @Overload String valueOf(double p0);
}
@Overload String String.new();
@Overload String String.new(String p0);
@Overload String String.new(int[] p0);
@Overload String String.new(int[] p0, int p1, int p2);
@Overload String String.new(int[] p0, int p1, int p2);
@Overload String String.new(int[] p0, int p1, int p2, int p3);
@Overload String String.new(int[] p0, int p1);
@Overload String String.new(int[] p0, int p1, int p2, String p3);
@Overload String String.new(int[] p0, int p1, int p2, Java_nio_charset_Charset p3);
@Overload String String.new(int[] p0, String p1);
@Overload String String.new(int[] p0, Java_nio_charset_Charset p1);
@Overload String String.new(int[] p0, int p1, int p2);
@Overload String String.new(int[] p0);
@Overload String String.new(Java_lang_StringBuffer p0);
@Overload String String.new(Java_lang_StringBuilder p0);
/* class java.lang.StringBuffer */
class Java_lang_StringBuffer {
	/*-- Method --*/
	@Virtual @Overload Java_lang_StringBuffer append(Object p0);
	@Virtual @Overload Java_lang_StringBuffer append(String p0);
	@Virtual @Overload Java_lang_StringBuffer append(Java_lang_StringBuffer p0);
	@Virtual @Overload Java_lang_StringBuffer append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_StringBuffer append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_StringBuffer append(int[] p0);
	@Virtual @Overload Java_lang_StringBuffer append(int[] p0, int p1, int p2);
	@Virtual @Overload Java_lang_StringBuffer append(boolean p0);
	@Virtual @Overload Java_lang_StringBuffer append(int p0);
	@Virtual @Overload Java_lang_StringBuffer append(int p0);
	@Virtual @Overload Java_lang_StringBuffer append(long p0);
	@Virtual @Overload Java_lang_StringBuffer append(float p0);
	@Virtual @Overload Java_lang_StringBuffer append(double p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(double p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(float p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(long p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(boolean p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int[] p0, int p1, int p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int[] p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_StringBuffer p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(String p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Object p0);
	@Virtual @Overload Java_lang_Appendable append(int p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_StringBuffer appendCodePoint(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder appendCodePoint(int p0);
	@Virtual @Overload int capacity();
	@Virtual @Overload int charAt(int p0);
	@Virtual @Overload int codePointAt(int p0);
	@Virtual @Overload int codePointBefore(int p0);
	@Virtual @Overload int codePointCount(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer delete(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder delete(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer deleteCharAt(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder deleteCharAt(int p0);
	@Virtual @Overload void ensureCapacity(int p0);
	@Virtual @Overload void getChars(int p0, int p1, int[] p2, int p3);
	@Virtual @Overload int indexOf(String p0);
	@Virtual @Overload int indexOf(String p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, int[] p1, int p2, int p3);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, Object p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, String p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, int[] p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, Java_lang_CharSequence p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, Java_lang_CharSequence p1, int p2, int p3);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, boolean p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, long p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, float p1);
	@Virtual @Overload Java_lang_StringBuffer insert(int p0, double p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, double p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, float p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, long p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, boolean p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Java_lang_CharSequence p1, int p2, int p3);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Java_lang_CharSequence p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int[] p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, String p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Object p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int[] p1, int p2, int p3);
	@Virtual @Overload int lastIndexOf(String p0);
	@Virtual @Overload int lastIndexOf(String p0, int p1);
	@Virtual @Overload int length();
	@Virtual @Overload int offsetByCodePoints(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuffer replace(int p0, int p1, String p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder replace(int p0, int p1, String p2);
	@Virtual @Overload Java_lang_StringBuffer reverse();
	@Virtual @Overload Java_lang_AbstractStringBuilder reverse();
	@Virtual @Overload void setCharAt(int p0, int p1);
	@Virtual @Overload void setLength(int p0);
	@Virtual @Overload Java_lang_CharSequence subSequence(int p0, int p1);
	@Virtual @Overload String substring(int p0);
	@Virtual @Overload String substring(int p0, int p1);
	@Virtual @Overload String toString();
	@Virtual @Overload void trimToSize();
}
@Overload Java_lang_StringBuffer Java_lang_StringBuffer.new();
@Overload Java_lang_StringBuffer Java_lang_StringBuffer.new(int p0);
@Overload Java_lang_StringBuffer Java_lang_StringBuffer.new(String p0);
@Overload Java_lang_StringBuffer Java_lang_StringBuffer.new(Java_lang_CharSequence p0);
/* class java.lang.StringBuilder */
class Java_lang_StringBuilder {
	/*-- Method --*/
	@Virtual @Overload Java_lang_StringBuilder append(Object p0);
	@Virtual @Overload Java_lang_StringBuilder append(String p0);
	@Virtual @Overload Java_lang_StringBuilder append(Java_lang_StringBuffer p0);
	@Virtual @Overload Java_lang_StringBuilder append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_StringBuilder append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_StringBuilder append(int[] p0);
	@Virtual @Overload Java_lang_StringBuilder append(int[] p0, int p1, int p2);
	@Virtual @Overload Java_lang_StringBuilder append(boolean p0);
	@Virtual @Overload Java_lang_StringBuilder append(int p0);
	@Virtual @Overload Java_lang_StringBuilder append(int p0);
	@Virtual @Overload Java_lang_StringBuilder append(long p0);
	@Virtual @Overload Java_lang_StringBuilder append(float p0);
	@Virtual @Overload Java_lang_StringBuilder append(double p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(double p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(float p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(long p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(boolean p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int[] p0, int p1, int p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(int[] p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Java_lang_StringBuffer p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(String p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder append(Object p0);
	@Virtual @Overload Java_lang_Appendable append(int p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_lang_StringBuilder appendCodePoint(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder appendCodePoint(int p0);
	@Virtual @Overload int capacity();
	@Virtual @Overload int charAt(int p0);
	@Virtual @Overload int codePointAt(int p0);
	@Virtual @Overload int codePointBefore(int p0);
	@Virtual @Overload int codePointCount(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder delete(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder delete(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder deleteCharAt(int p0);
	@Virtual @Overload Java_lang_AbstractStringBuilder deleteCharAt(int p0);
	@Virtual @Overload void ensureCapacity(int p0);
	@Virtual @Overload void getChars(int p0, int p1, int[] p2, int p3);
	@Virtual @Overload int indexOf(String p0);
	@Virtual @Overload int indexOf(String p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, int[] p1, int p2, int p3);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, Object p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, String p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, int[] p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, Java_lang_CharSequence p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, Java_lang_CharSequence p1, int p2, int p3);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, boolean p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, long p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, float p1);
	@Virtual @Overload Java_lang_StringBuilder insert(int p0, double p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, double p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, float p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, long p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, boolean p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Java_lang_CharSequence p1, int p2, int p3);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Java_lang_CharSequence p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int[] p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, String p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, Object p1);
	@Virtual @Overload Java_lang_AbstractStringBuilder insert(int p0, int[] p1, int p2, int p3);
	@Virtual @Overload int lastIndexOf(String p0);
	@Virtual @Overload int lastIndexOf(String p0, int p1);
	@Virtual @Overload int length();
	@Virtual @Overload int offsetByCodePoints(int p0, int p1);
	@Virtual @Overload Java_lang_StringBuilder replace(int p0, int p1, String p2);
	@Virtual @Overload Java_lang_AbstractStringBuilder replace(int p0, int p1, String p2);
	@Virtual @Overload Java_lang_StringBuilder reverse();
	@Virtual @Overload Java_lang_AbstractStringBuilder reverse();
	@Virtual @Overload void setCharAt(int p0, int p1);
	@Virtual @Overload void setLength(int p0);
	@Virtual @Overload Java_lang_CharSequence subSequence(int p0, int p1);
	@Virtual @Overload String substring(int p0, int p1);
	@Virtual @Overload String substring(int p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void trimToSize();
}
@Overload Java_lang_StringBuilder Java_lang_StringBuilder.new();
@Overload Java_lang_StringBuilder Java_lang_StringBuilder.new(int p0);
@Overload Java_lang_StringBuilder Java_lang_StringBuilder.new(String p0);
@Overload Java_lang_StringBuilder Java_lang_StringBuilder.new(Java_lang_CharSequence p0);
/* class java.lang.StringIndexOutOfBoundsException */
class Java_lang_StringIndexOutOfBoundsException extends Java_lang_IndexOutOfBoundsException {
}
@Overload Java_lang_StringIndexOutOfBoundsException Java_lang_StringIndexOutOfBoundsException.new();
@Overload Java_lang_StringIndexOutOfBoundsException Java_lang_StringIndexOutOfBoundsException.new(String p0);
@Overload Java_lang_StringIndexOutOfBoundsException Java_lang_StringIndexOutOfBoundsException.new(int p0);
/* interface java.lang.SuppressWarnings */
class Java_lang_SuppressWarnings {
	/*-- Method --*/
	@Virtual @Overload String[] value();
}
/* class java.lang.System */
class Java_lang_System {
	/*-- Method --*/
	@Virtual @Overload void arraycopy(Object p0, int p1, Object p2, int p3, int p4);
	@Virtual @Overload String clearProperty(String p0);
	@Virtual @Overload Java_io_Console console();
	@Virtual @Overload long currentTimeMillis();
	@Virtual @Overload void exit(int p0);
	@Virtual @Overload void gc();
	@Virtual @Overload Java_util_Properties getProperties();
	@Virtual @Overload String getProperty(String p0);
	@Virtual @Overload String getProperty(String p0, String p1);
	@Virtual @Overload Java_lang_SecurityManager getSecurityManager();
	@Virtual @Overload String getenv(String p0);
	@Virtual @Overload Java_util_Map getenv();
	@Virtual @Overload int identityHashCode(Object p0);
	@Virtual @Overload Java_nio_channels_Channel inheritedChannel();
	@Virtual @Overload String lineSeparator();
	@Virtual @Overload void load(String p0);
	@Virtual @Overload void loadLibrary(String p0);
	@Virtual @Overload String mapLibraryName(String p0);
	@Virtual @Overload long nanoTime();
	@Virtual @Overload void runFinalization();
	@Virtual @Overload void setErr(Java_io_PrintStream p0);
	@Virtual @Overload void setIn(Java_io_InputStream p0);
	@Virtual @Overload void setOut(Java_io_PrintStream p0);
	@Virtual @Overload void setProperties(Java_util_Properties p0);
	@Virtual @Overload String setProperty(String p0, String p1);
	@Virtual @Overload void setSecurityManager(Java_lang_SecurityManager p0);
}
/* class java.lang.Thread */
class Java_lang_Thread {
	/*-- Method --*/
	@Virtual @Overload int activeCount();
	@Virtual @Overload void checkAccess();
	@Virtual @Overload Java_lang_Thread currentThread();
	@Virtual @Overload void dumpStack();
	@Virtual @Overload int enumerate(Java_lang_Thread[] p0);
	@Virtual @Overload Java_util_Map getAllStackTraces();
	@Virtual @Overload Java_lang_ClassLoader getContextClassLoader();
	@Virtual @Overload Java_lang_Thread_UncaughtExceptionHandler getDefaultUncaughtExceptionHandler();
	@Virtual @Overload long getId();
	@Virtual @Overload String getName();
	@Virtual @Overload int getPriority();
	@Virtual @Overload Java_lang_StackTraceElement[] getStackTrace();
	@Virtual @Overload Java_lang_Thread_State getState();
	@Virtual @Overload Java_lang_ThreadGroup getThreadGroup();
	@Virtual @Overload Java_lang_Thread_UncaughtExceptionHandler getUncaughtExceptionHandler();
	@Virtual @Overload boolean holdsLock(Object p0);
	@Virtual @Overload void interrupt();
	@Virtual @Overload boolean interrupted();
	@Virtual @Overload boolean isAlive();
	@Virtual @Overload boolean isDaemon();
	@Virtual @Overload boolean isInterrupted();
	@Virtual @Overload void join(long p0);
	@Virtual @Overload void join(long p0, int p1);
	@Virtual @Overload void join();
	@Virtual @Overload void run();
	@Virtual @Overload void setContextClassLoader(Java_lang_ClassLoader p0);
	@Virtual @Overload void setDaemon(boolean p0);
	@Virtual @Overload void setDefaultUncaughtExceptionHandler(Java_lang_Thread_UncaughtExceptionHandler p0);
	@Virtual @Overload void setName(String p0);
	@Virtual @Overload void setPriority(int p0);
	@Virtual @Overload void setUncaughtExceptionHandler(Java_lang_Thread_UncaughtExceptionHandler p0);
	@Virtual @Overload void sleep(long p0);
	@Virtual @Overload void sleep(long p0, int p1);
	@Virtual @Overload void start();
	@Virtual @Overload String toString();
	@Virtual @Overload void yield();
}
@Overload Java_lang_Thread Java_lang_Thread.new();
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_Runnable p0);
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_ThreadGroup p0, Java_lang_Runnable p1);
@Overload Java_lang_Thread Java_lang_Thread.new(String p0);
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_ThreadGroup p0, String p1);
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_Runnable p0, String p1);
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_ThreadGroup p0, Java_lang_Runnable p1, String p2);
@Overload Java_lang_Thread Java_lang_Thread.new(Java_lang_ThreadGroup p0, Java_lang_Runnable p1, String p2, long p3);
/* class java.lang.ThreadDeath */
class Java_lang_ThreadDeath extends Java_lang_Error {
}
Java_lang_ThreadDeath Java_lang_ThreadDeath.new();
/* class java.lang.ThreadGroup */
class Java_lang_ThreadGroup {
	/*-- Method --*/
	@Virtual @Overload int activeCount();
	@Virtual @Overload int activeGroupCount();
	@Virtual @Overload void checkAccess();
	@Virtual @Overload void destroy();
	@Virtual @Overload int enumerate(Java_lang_Thread[] p0);
	@Virtual @Overload int enumerate(Java_lang_Thread[] p0, boolean p1);
	@Virtual @Overload int enumerate(Java_lang_ThreadGroup[] p0);
	@Virtual @Overload int enumerate(Java_lang_ThreadGroup[] p0, boolean p1);
	@Virtual @Overload int getMaxPriority();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_lang_ThreadGroup getParent();
	@Virtual @Overload void interrupt();
	@Virtual @Overload boolean isDaemon();
	@Virtual @Overload boolean isDestroyed();
	@Virtual @Overload void list();
	@Virtual @Overload boolean parentOf(Java_lang_ThreadGroup p0);
	@Virtual @Overload void setDaemon(boolean p0);
	@Virtual @Overload void setMaxPriority(int p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void uncaughtException(Java_lang_Thread p0, Java_lang_Throwable p1);
}
@Overload Java_lang_ThreadGroup Java_lang_ThreadGroup.new(String p0);
@Overload Java_lang_ThreadGroup Java_lang_ThreadGroup.new(Java_lang_ThreadGroup p0, String p1);
/* class java.lang.ThreadLocal */
class Java_lang_ThreadLocal {
	/*-- Method --*/
	@Virtual @Overload Object get();
	@Virtual @Overload void remove();
	@Virtual @Overload void set(Object p0);
}
Java_lang_ThreadLocal Java_lang_ThreadLocal.new();
/* class java.lang.Throwable */
class Java_lang_Throwable {
	/*-- Method --*/
	@Virtual @Overload void addSuppressed(Java_lang_Throwable p0);
	@Virtual @Overload Java_lang_Throwable fillInStackTrace();
	@Virtual @Overload Java_lang_Throwable getCause();
	@Virtual @Overload String getLocalizedMessage();
	@Virtual @Overload String getMessage();
	@Virtual @Overload Java_lang_StackTraceElement[] getStackTrace();
	@Virtual @Overload Java_lang_Throwable[] getSuppressed();
	@Virtual @Overload Java_lang_Throwable initCause(Java_lang_Throwable p0);
	@Virtual @Overload void printStackTrace();
	@Virtual @Overload void printStackTrace(Java_io_PrintStream p0);
	@Virtual @Overload void printStackTrace(Java_io_PrintWriter p0);
	@Virtual @Overload void setStackTrace(Java_lang_StackTraceElement[] p0);
	@Virtual @Overload String toString();
}
@Overload Java_lang_Throwable Java_lang_Throwable.new();
@Overload Java_lang_Throwable Java_lang_Throwable.new(String p0);
@Overload Java_lang_Throwable Java_lang_Throwable.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_Throwable Java_lang_Throwable.new(Java_lang_Throwable p0);
/* class java.lang.TypeNotPresentException */
class Java_lang_TypeNotPresentException extends Java_lang_RuntimeException {
	/*-- Method --*/
	@Virtual @Overload String typeName();
}
Java_lang_TypeNotPresentException Java_lang_TypeNotPresentException.new(String p0, Java_lang_Throwable p1);
/* class java.lang.UnknownError */
class Java_lang_UnknownError extends Java_lang_VirtualMachineError {
}
@Overload Java_lang_UnknownError Java_lang_UnknownError.new();
@Overload Java_lang_UnknownError Java_lang_UnknownError.new(String p0);
/* class java.lang.UnsatisfiedLinkError */
class Java_lang_UnsatisfiedLinkError extends Java_lang_LinkageError {
}
@Overload Java_lang_UnsatisfiedLinkError Java_lang_UnsatisfiedLinkError.new();
@Overload Java_lang_UnsatisfiedLinkError Java_lang_UnsatisfiedLinkError.new(String p0);
/* class java.lang.UnsupportedClassVersionError */
class Java_lang_UnsupportedClassVersionError extends Java_lang_ClassFormatError {
}
@Overload Java_lang_UnsupportedClassVersionError Java_lang_UnsupportedClassVersionError.new();
@Overload Java_lang_UnsupportedClassVersionError Java_lang_UnsupportedClassVersionError.new(String p0);
/* class java.lang.UnsupportedOperationException */
class Java_lang_UnsupportedOperationException extends Java_lang_RuntimeException {
}
@Overload Java_lang_UnsupportedOperationException Java_lang_UnsupportedOperationException.new();
@Overload Java_lang_UnsupportedOperationException Java_lang_UnsupportedOperationException.new(String p0);
@Overload Java_lang_UnsupportedOperationException Java_lang_UnsupportedOperationException.new(String p0, Java_lang_Throwable p1);
@Overload Java_lang_UnsupportedOperationException Java_lang_UnsupportedOperationException.new(Java_lang_Throwable p0);
/* class java.lang.VerifyError */
class Java_lang_VerifyError extends Java_lang_LinkageError {
}
@Overload Java_lang_VerifyError Java_lang_VerifyError.new();
@Overload Java_lang_VerifyError Java_lang_VerifyError.new(String p0);
/* class java.lang.VirtualMachineError */
class Java_lang_VirtualMachineError extends Java_lang_Error {
}
@Overload Java_lang_VirtualMachineError Java_lang_VirtualMachineError.new();
@Overload Java_lang_VirtualMachineError Java_lang_VirtualMachineError.new(String p0);
/* class java.lang.Void */
class Java_lang_Void {
}

/*------------------------------------------------------------*/
/* short names */
AbstractMethodError = Java_lang_AbstractMethodError
Appendable = Java_lang_Appendable
ArithmeticException = Java_lang_ArithmeticException
ArrayIndexOutOfBoundsException = Java_lang_ArrayIndexOutOfBoundsException
ArrayStoreException = Java_lang_ArrayStoreException
AssertionError = Java_lang_AssertionError
AutoCloseable = Java_lang_AutoCloseable
BootstrapMethodError = Java_lang_BootstrapMethodError
Byte = Java_lang_Byte
CharSequence = Java_lang_CharSequence
Character = Java_lang_Character
ClassCastException = Java_lang_ClassCastException
ClassCircularityError = Java_lang_ClassCircularityError
ClassFormatError = Java_lang_ClassFormatError
ClassLoader = Java_lang_ClassLoader
ClassNotFoundException = Java_lang_ClassNotFoundException
ClassValue = Java_lang_ClassValue
CloneNotSupportedException = Java_lang_CloneNotSupportedException
Cloneable = Java_lang_Cloneable
Comparable = Java_lang_Comparable
Compiler = Java_lang_Compiler
Deprecated = Java_lang_Deprecated
Enum = Java_lang_Enum
EnumConstantNotPresentException = Java_lang_EnumConstantNotPresentException
Error = Java_lang_Error
Exception = Java_lang_Exception
ExceptionInInitializerError = Java_lang_ExceptionInInitializerError
IllegalAccessError = Java_lang_IllegalAccessError
IllegalAccessException = Java_lang_IllegalAccessException
IllegalArgumentException = Java_lang_IllegalArgumentException
IllegalMonitorStateException = Java_lang_IllegalMonitorStateException
IllegalStateException = Java_lang_IllegalStateException
IllegalThreadStateException = Java_lang_IllegalThreadStateException
IncompatibleClassChangeError = Java_lang_IncompatibleClassChangeError
IndexOutOfBoundsException = Java_lang_IndexOutOfBoundsException
InheritableThreadLocal = Java_lang_InheritableThreadLocal
InstantiationError = Java_lang_InstantiationError
InstantiationException = Java_lang_InstantiationException
InternalError = Java_lang_InternalError
InterruptedException = Java_lang_InterruptedException
Iterable = Java_lang_Iterable
LinkageError = Java_lang_LinkageError
Long = Java_lang_Long
NegativeArraySizeException = Java_lang_NegativeArraySizeException
NoClassDefFoundError = Java_lang_NoClassDefFoundError
NoSuchFieldError = Java_lang_NoSuchFieldError
NoSuchFieldException = Java_lang_NoSuchFieldException
NoSuchMethodError = Java_lang_NoSuchMethodError
NoSuchMethodException = Java_lang_NoSuchMethodException
NullPointerException = Java_lang_NullPointerException
Number = Java_lang_Number
NumberFormatException = Java_lang_NumberFormatException
OutOfMemoryError = Java_lang_OutOfMemoryError
Override = Java_lang_Override
Package = Java_lang_Package
Process = Java_lang_Process
ProcessBuilder = Java_lang_ProcessBuilder
Readable = Java_lang_Readable
ReflectiveOperationException = Java_lang_ReflectiveOperationException
Runnable = Java_lang_Runnable
Runtime = Java_lang_Runtime
RuntimeException = Java_lang_RuntimeException
RuntimePermission = Java_lang_RuntimePermission
SafeVarargs = Java_lang_SafeVarargs
SecurityException = Java_lang_SecurityException
SecurityManager = Java_lang_SecurityManager
Short = Java_lang_Short
StackOverflowError = Java_lang_StackOverflowError
StackTraceElement = Java_lang_StackTraceElement
StrictMath = Java_lang_StrictMath
StringBuffer = Java_lang_StringBuffer
StringBuilder = Java_lang_StringBuilder
StringIndexOutOfBoundsException = Java_lang_StringIndexOutOfBoundsException
SuppressWarnings = Java_lang_SuppressWarnings
Thread = Java_lang_Thread
ThreadDeath = Java_lang_ThreadDeath
ThreadGroup = Java_lang_ThreadGroup
ThreadLocal = Java_lang_ThreadLocal
Throwable = Java_lang_Throwable
TypeNotPresentException = Java_lang_TypeNotPresentException
UnknownError = Java_lang_UnknownError
UnsatisfiedLinkError = Java_lang_UnsatisfiedLinkError
UnsupportedClassVersionError = Java_lang_UnsupportedClassVersionError
UnsupportedOperationException = Java_lang_UnsupportedOperationException
VerifyError = Java_lang_VerifyError
VirtualMachineError = Java_lang_VirtualMachineError
Void = Java_lang_Void
