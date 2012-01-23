/* converted from java package java.io */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_io_ObjectInputStream_GetField;
class Java_io_ObjectOutputStream_PutField;
class Java_lang_Appendable;
class Java_lang_CharSequence;
class Java_lang_Error;
class Java_lang_Exception;
class Java_lang_StringBuffer;
class Java_lang_Throwable;
class Java_net_URI;
class Java_nio_CharBuffer;
class Java_nio_channels_FileChannel;
class Java_nio_charset_Charset;
class Java_nio_charset_CharsetDecoder;
class Java_nio_charset_CharsetEncoder;
class Java_nio_file_Path;
class Java_security_BasicPermission;
class Java_security_Permission;
class Java_util_Enumeration;
class Java_util_Locale;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_io_InputStream;
class Java_io_FilterInputStream extends Java_io_InputStream;
class Java_io_BufferedInputStream extends Java_io_FilterInputStream;
class Java_io_OutputStream;
class Java_io_FilterOutputStream extends Java_io_OutputStream;
class Java_io_BufferedOutputStream extends Java_io_FilterOutputStream;
class Java_io_Reader;
class Java_io_BufferedReader extends Java_io_Reader;
class Java_io_Writer;
class Java_io_BufferedWriter extends Java_io_Writer;
class Java_io_ByteArrayInputStream extends Java_io_InputStream;
class Java_io_ByteArrayOutputStream extends Java_io_OutputStream;
class Java_io_CharArrayReader extends Java_io_Reader;
class Java_io_CharArrayWriter extends Java_io_Writer;
class Java_io_IOException extends Java_lang_Exception;
class Java_io_CharConversionException extends Java_io_IOException;
class Java_io_Closeable;
class Java_io_Console;
class Java_io_DataInput;
class Java_io_DataInputStream extends Java_io_FilterInputStream;
class Java_io_DataOutput;
class Java_io_DataOutputStream extends Java_io_FilterOutputStream;
class Java_io_EOFException extends Java_io_IOException;
class Java_io_Externalizable;
class Java_io_File;
class Java_io_FileDescriptor;
class Java_io_FileFilter;
class Java_io_FileInputStream extends Java_io_InputStream;
class Java_io_FileNotFoundException extends Java_io_IOException;
class Java_io_FileOutputStream extends Java_io_OutputStream;
class Java_io_FilePermission extends Java_security_Permission;
class Java_io_InputStreamReader extends Java_io_Reader;
class Java_io_FileReader extends Java_io_InputStreamReader;
class Java_io_OutputStreamWriter extends Java_io_Writer;
class Java_io_FileWriter extends Java_io_OutputStreamWriter;
class Java_io_FilenameFilter;
class Java_io_FilterReader extends Java_io_Reader;
class Java_io_FilterWriter extends Java_io_Writer;
class Java_io_Flushable;
class Java_io_IOError extends Java_lang_Error;
class Java_io_InterruptedIOException extends Java_io_IOException;
class Java_io_ObjectStreamException extends Java_io_IOException;
class Java_io_InvalidClassException extends Java_io_ObjectStreamException;
class Java_io_InvalidObjectException extends Java_io_ObjectStreamException;
class Java_io_LineNumberReader extends Java_io_BufferedReader;
class Java_io_NotActiveException extends Java_io_ObjectStreamException;
class Java_io_NotSerializableException extends Java_io_ObjectStreamException;
class Java_io_ObjectInput;
class Java_io_ObjectInputStream extends Java_io_InputStream;
class Java_io_ObjectInputValidation;
class Java_io_ObjectOutput;
class Java_io_ObjectOutputStream extends Java_io_OutputStream;
class Java_io_ObjectStreamClass;
class Java_io_ObjectStreamConstants;
class Java_io_ObjectStreamField;
class Java_io_OptionalDataException extends Java_io_ObjectStreamException;
class Java_io_PipedInputStream extends Java_io_InputStream;
class Java_io_PipedOutputStream extends Java_io_OutputStream;
class Java_io_PipedReader extends Java_io_Reader;
class Java_io_PipedWriter extends Java_io_Writer;
class Java_io_PrintStream extends Java_io_FilterOutputStream;
class Java_io_PrintWriter extends Java_io_Writer;
class Java_io_PushbackInputStream extends Java_io_FilterInputStream;
class Java_io_PushbackReader extends Java_io_FilterReader;
class Java_io_RandomAccessFile;
class Java_io_SequenceInputStream extends Java_io_InputStream;
class Java_io_Serializable;
class Java_io_SerializablePermission extends Java_security_BasicPermission;
class Java_io_StreamCorruptedException extends Java_io_ObjectStreamException;
class Java_io_StreamTokenizer;
class Java_io_StringReader extends Java_io_Reader;
class Java_io_StringWriter extends Java_io_Writer;
class Java_io_SyncFailedException extends Java_io_IOException;
class Java_io_UTFDataFormatException extends Java_io_IOException;
class Java_io_UnsupportedEncodingException extends Java_io_IOException;
class Java_io_WriteAbortedException extends Java_io_ObjectStreamException;

/*------------------------------------------------------------*/
/* class java.io.BufferedInputStream */
class Java_io_BufferedInputStream extends Java_io_FilterInputStream {
}
@Overload Java_io_BufferedInputStream Java_io_BufferedInputStream.new(Java_io_InputStream p0);
@Overload Java_io_BufferedInputStream Java_io_BufferedInputStream.new(Java_io_InputStream p0, int p1);

/* class java.io.BufferedOutputStream */
class Java_io_BufferedOutputStream extends Java_io_FilterOutputStream {
}
@Overload Java_io_BufferedOutputStream Java_io_BufferedOutputStream.new(Java_io_OutputStream p0);
@Overload Java_io_BufferedOutputStream Java_io_BufferedOutputStream.new(Java_io_OutputStream p0, int p1);

/* class java.io.BufferedReader */
class Java_io_BufferedReader extends Java_io_Reader {
	/*-- Method --*/
	@Virtual @Overload String readLine();
}
@Overload Java_io_BufferedReader Java_io_BufferedReader.new(Java_io_Reader p0, int p1);
@Overload Java_io_BufferedReader Java_io_BufferedReader.new(Java_io_Reader p0);

/* class java.io.BufferedWriter */
class Java_io_BufferedWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload void newLine();
}
@Overload Java_io_BufferedWriter Java_io_BufferedWriter.new(Java_io_Writer p0);
@Overload Java_io_BufferedWriter Java_io_BufferedWriter.new(Java_io_Writer p0, int p1);

/* class java.io.ByteArrayInputStream */
class Java_io_ByteArrayInputStream extends Java_io_InputStream {
}
@Overload Java_io_ByteArrayInputStream Java_io_ByteArrayInputStream.new(int[] p0);
@Overload Java_io_ByteArrayInputStream Java_io_ByteArrayInputStream.new(int[] p0, int p1, int p2);

/* class java.io.ByteArrayOutputStream */
class Java_io_ByteArrayOutputStream extends Java_io_OutputStream {
	/*-- Method --*/
	@Virtual @Overload void reset();
	@Virtual @Overload int size();
	@Virtual @Overload int[] toByteArray();
	@Virtual @Overload String toString(String p0);
	@Virtual @Overload void writeTo(Java_io_OutputStream p0);
}
@Overload Java_io_ByteArrayOutputStream Java_io_ByteArrayOutputStream.new();
@Overload Java_io_ByteArrayOutputStream Java_io_ByteArrayOutputStream.new(int p0);

/* class java.io.CharArrayReader */
class Java_io_CharArrayReader extends Java_io_Reader {
}
@Overload Java_io_CharArrayReader Java_io_CharArrayReader.new(int[] p0);
@Overload Java_io_CharArrayReader Java_io_CharArrayReader.new(int[] p0, int p1, int p2);

/* class java.io.CharArrayWriter */
class Java_io_CharArrayWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload void reset();
	@Virtual @Overload int size();
	@Virtual @Overload int[] toCharArray();
	@Virtual @Overload void writeTo(Java_io_Writer p0);
}
@Overload Java_io_CharArrayWriter Java_io_CharArrayWriter.new();
@Overload Java_io_CharArrayWriter Java_io_CharArrayWriter.new(int p0);

/* class java.io.CharConversionException */
class Java_io_CharConversionException extends Java_io_IOException {
}
@Overload Java_io_CharConversionException Java_io_CharConversionException.new();
@Overload Java_io_CharConversionException Java_io_CharConversionException.new(String p0);

/* interface java.io.Closeable */
class Java_io_Closeable {
	// implements java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload void close();
}

/* class java.io.Console */
class Java_io_Console {
	// implements java.io.Flushable
	/*-- Method --*/
	@Virtual @Overload void flush();
	//@Virtual @Overload Java_io_Console format(String p0, Object[] p1);
	@Virtual @Overload Java_io_Console printf(String p0, Object[] p1);
	@Virtual @Overload String readLine(String p0, Object[] p1);
	@Virtual @Overload String readLine();
	@Virtual @Overload int[] readPassword(String p0, Object[] p1);
	@Virtual @Overload int[] readPassword();
	@Virtual @Overload Java_io_Reader reader();
	@Virtual @Overload Java_io_PrintWriter writer();
}

/* interface java.io.DataInput */
class Java_io_DataInput {
	/*-- Method --*/
	@Virtual @Overload boolean readBoolean();
	@Virtual @Overload int readByte();
	@Virtual @Overload int readChar();
	@Virtual @Overload double readDouble();
	@Virtual @Overload float readFloat();
	@Virtual @Overload void readFully(int[] p0);
	@Virtual @Overload void readFully(int[] p0, int p1, int p2);
	@Virtual @Overload int readInt();
	@Virtual @Overload String readLine();
	@Virtual @Overload long readLong();
	@Virtual @Overload int readShort();
	@Virtual @Overload String readUTF();
	@Virtual @Overload int readUnsignedByte();
	@Virtual @Overload int readUnsignedShort();
	@Virtual @Overload int skipBytes(int p0);
}

/* class java.io.DataInputStream */
class Java_io_DataInputStream extends Java_io_FilterInputStream {
	// implements java.io.DataInput
	/*-- Method --*/
	@Virtual @Overload boolean readBoolean();
	@Virtual @Overload int readByte();
	@Virtual @Overload int readChar();
	@Virtual @Overload double readDouble();
	@Virtual @Overload float readFloat();
	@Virtual @Overload void readFully(int[] p0);
	@Virtual @Overload void readFully(int[] p0, int p1, int p2);
	@Virtual @Overload int readInt();
	@Virtual @Overload long readLong();
	@Virtual @Overload int readShort();
	@Virtual @Overload String readUTF();
	@Virtual @Overload String readUTF(Java_io_DataInput p0);
	@Virtual @Overload int readUnsignedByte();
	@Virtual @Overload int readUnsignedShort();
	@Virtual @Overload int skipBytes(int p0);
}
Java_io_DataInputStream Java_io_DataInputStream.new(Java_io_InputStream p0);

/* interface java.io.DataOutput */
class Java_io_DataOutput {
	/*-- Method --*/
	@Virtual @Overload void write(int p0);
	@Virtual @Overload void write(int[] p0);
	@Virtual @Overload void write(int[] p0, int p1, int p2);
	@Virtual @Overload void writeBoolean(boolean p0);
	@Virtual @Overload void writeByte(int p0);
	@Virtual @Overload void writeBytes(String p0);
	@Virtual @Overload void writeChar(int p0);
	@Virtual @Overload void writeChars(String p0);
	@Virtual @Overload void writeDouble(double p0);
	@Virtual @Overload void writeFloat(float p0);
	@Virtual @Overload void writeInt(int p0);
	@Virtual @Overload void writeLong(long p0);
	@Virtual @Overload void writeShort(int p0);
	@Virtual @Overload void writeUTF(String p0);
}

/* class java.io.DataOutputStream */
class Java_io_DataOutputStream extends Java_io_FilterOutputStream {
	// implements java.io.DataOutput
	/*-- Method --*/
	@Virtual @Overload int size();
	@Virtual @Overload void writeBoolean(boolean p0);
	@Virtual @Overload void writeByte(int p0);
	@Virtual @Overload void writeBytes(String p0);
	@Virtual @Overload void writeChar(int p0);
	@Virtual @Overload void writeChars(String p0);
	@Virtual @Overload void writeDouble(double p0);
	@Virtual @Overload void writeFloat(float p0);
	@Virtual @Overload void writeInt(int p0);
	@Virtual @Overload void writeLong(long p0);
	@Virtual @Overload void writeShort(int p0);
	@Virtual @Overload void writeUTF(String p0);
}
Java_io_DataOutputStream Java_io_DataOutputStream.new(Java_io_OutputStream p0);

/* class java.io.EOFException */
class Java_io_EOFException extends Java_io_IOException {
}
@Overload Java_io_EOFException Java_io_EOFException.new();
@Overload Java_io_EOFException Java_io_EOFException.new(String p0);

/* interface java.io.Externalizable */
class Java_io_Externalizable {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void readExternal(Java_io_ObjectInput p0);
	@Virtual @Overload void writeExternal(Java_io_ObjectOutput p0);
}

/* class java.io.File */
class Java_io_File {
	// implements java.io.Serializable, java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload boolean canExecute();
	@Virtual @Overload boolean canRead();
	@Virtual @Overload boolean canWrite();
	@Virtual @Overload int compareTo(Java_io_File p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean createNewFile();
	@Virtual @Overload Java_io_File createTempFile(String p0, String p1, Java_io_File p2);
	@Virtual @Overload Java_io_File createTempFile(String p0, String p1);
	@Virtual @Overload boolean delete();
	@Virtual @Overload void deleteOnExit();
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload boolean exists();
	@Virtual @Overload Java_io_File getAbsoluteFile();
	@Virtual @Overload String getAbsolutePath();
	@Virtual @Overload Java_io_File getCanonicalFile();
	@Virtual @Overload String getCanonicalPath();
	@Virtual @Overload long getFreeSpace();
	@Virtual @Overload String getName();
	@Virtual @Overload String getParent();
	@Virtual @Overload Java_io_File getParentFile();
	@Virtual @Overload String getPath();
	@Virtual @Overload long getTotalSpace();
	@Virtual @Overload long getUsableSpace();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isAbsolute();
	@Virtual @Overload boolean isDirectory();
	@Virtual @Overload boolean isFile();
	@Virtual @Overload boolean isHidden();
	@Virtual @Overload long lastModified();
	@Virtual @Overload long length();
	@Virtual @Overload String[] list();
	@Virtual @Overload String[] list(Java_io_FilenameFilter p0);
	@Virtual @Overload Java_io_File[] listFiles();
	@Virtual @Overload Java_io_File[] listFiles(Java_io_FilenameFilter p0);
	@Virtual @Overload Java_io_File[] listFiles(Java_io_FileFilter p0);
	@Virtual @Overload Java_io_File[] listRoots();
	@Virtual @Overload boolean mkdir();
	@Virtual @Overload boolean mkdirs();
	@Virtual @Overload boolean renameTo(Java_io_File p0);
	@Virtual @Overload boolean setExecutable(boolean p0, boolean p1);
	@Virtual @Overload boolean setExecutable(boolean p0);
	@Virtual @Overload boolean setLastModified(long p0);
	@Virtual @Overload boolean setReadOnly();
	@Virtual @Overload boolean setReadable(boolean p0, boolean p1);
	@Virtual @Overload boolean setReadable(boolean p0);
	@Virtual @Overload boolean setWritable(boolean p0, boolean p1);
	@Virtual @Overload boolean setWritable(boolean p0);
	@Virtual @Overload Java_nio_file_Path toPath();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_net_URI toURI();
}
@Overload Java_io_File Java_io_File.new(String p0);
@Overload Java_io_File Java_io_File.new(String p0, String p1);
@Overload Java_io_File Java_io_File.new(Java_io_File p0, String p1);
@Overload Java_io_File Java_io_File.new(Java_net_URI p0);

/* class java.io.FileDescriptor */
class Java_io_FileDescriptor {
	/*-- Method --*/
	@Virtual @Overload void sync();
	@Virtual @Overload boolean valid();
}
Java_io_FileDescriptor Java_io_FileDescriptor.new();

/* interface java.io.FileFilter */
class Java_io_FileFilter {
	/*-- Method --*/
	@Virtual @Overload boolean accept(Java_io_File p0);
}

/* class java.io.FileInputStream */
class Java_io_FileInputStream extends Java_io_InputStream {
	/*-- Method --*/
	@Virtual @Overload Java_nio_channels_FileChannel getChannel();
	@Virtual @Overload Java_io_FileDescriptor getFD();
}
@Overload Java_io_FileInputStream Java_io_FileInputStream.new(String p0);
@Overload Java_io_FileInputStream Java_io_FileInputStream.new(Java_io_File p0);
@Overload Java_io_FileInputStream Java_io_FileInputStream.new(Java_io_FileDescriptor p0);

/* class java.io.FileNotFoundException */
class Java_io_FileNotFoundException extends Java_io_IOException {
}
@Overload Java_io_FileNotFoundException Java_io_FileNotFoundException.new();
@Overload Java_io_FileNotFoundException Java_io_FileNotFoundException.new(String p0);

/* class java.io.FileOutputStream */
class Java_io_FileOutputStream extends Java_io_OutputStream {
	/*-- Method --*/
	@Virtual @Overload Java_nio_channels_FileChannel getChannel();
	@Virtual @Overload Java_io_FileDescriptor getFD();
}
@Overload Java_io_FileOutputStream Java_io_FileOutputStream.new(String p0);
@Overload Java_io_FileOutputStream Java_io_FileOutputStream.new(String p0, boolean p1);
@Overload Java_io_FileOutputStream Java_io_FileOutputStream.new(Java_io_File p0);
@Overload Java_io_FileOutputStream Java_io_FileOutputStream.new(Java_io_File p0, boolean p1);
@Overload Java_io_FileOutputStream Java_io_FileOutputStream.new(Java_io_FileDescriptor p0);

/* class java.io.FilePermission */
class Java_io_FilePermission extends Java_security_Permission {
	// implements java.io.Serializable
}
Java_io_FilePermission Java_io_FilePermission.new(String p0, String p1);

/* class java.io.FileReader */
class Java_io_FileReader extends Java_io_InputStreamReader {
}
@Overload Java_io_FileReader Java_io_FileReader.new(String p0);
@Overload Java_io_FileReader Java_io_FileReader.new(Java_io_File p0);
@Overload Java_io_FileReader Java_io_FileReader.new(Java_io_FileDescriptor p0);

/* class java.io.FileWriter */
class Java_io_FileWriter extends Java_io_OutputStreamWriter {
}
@Overload Java_io_FileWriter Java_io_FileWriter.new(String p0);
@Overload Java_io_FileWriter Java_io_FileWriter.new(String p0, boolean p1);
@Overload Java_io_FileWriter Java_io_FileWriter.new(Java_io_File p0);
@Overload Java_io_FileWriter Java_io_FileWriter.new(Java_io_File p0, boolean p1);
@Overload Java_io_FileWriter Java_io_FileWriter.new(Java_io_FileDescriptor p0);

/* interface java.io.FilenameFilter */
class Java_io_FilenameFilter {
	/*-- Method --*/
	@Virtual @Overload boolean accept(Java_io_File p0, String p1);
}

/* class java.io.FilterInputStream */
class Java_io_FilterInputStream extends Java_io_InputStream {
}

/* class java.io.FilterOutputStream */
class Java_io_FilterOutputStream extends Java_io_OutputStream {
}
Java_io_FilterOutputStream Java_io_FilterOutputStream.new(Java_io_OutputStream p0);

/* class java.io.FilterReader */
class Java_io_FilterReader extends Java_io_Reader {
}

/* class java.io.FilterWriter */
class Java_io_FilterWriter extends Java_io_Writer {
}

/* interface java.io.Flushable */
class Java_io_Flushable {
	/*-- Method --*/
	@Virtual @Overload void flush();
}

/* class java.io.IOError */
class Java_io_IOError extends Java_lang_Error {
}
Java_io_IOError Java_io_IOError.new(Java_lang_Throwable p0);

/* class java.io.IOException */
class Java_io_IOException extends Java_lang_Exception {
}
@Overload Java_io_IOException Java_io_IOException.new();
@Overload Java_io_IOException Java_io_IOException.new(String p0);
@Overload Java_io_IOException Java_io_IOException.new(String p0, Java_lang_Throwable p1);
@Overload Java_io_IOException Java_io_IOException.new(Java_lang_Throwable p0);

/* class java.io.InputStream */
class Java_io_InputStream {
	// implements java.io.Closeable
	/*-- Method --*/
	@Virtual @Overload int available();
	@Virtual @Overload void close();
	@Virtual @Overload void mark(int p0);
	@Virtual @Overload boolean markSupported();
	@Virtual @Overload int read();
	@Virtual @Overload int read(int[] p0);
	@Virtual @Overload int read(int[] p0, int p1, int p2);
	@Virtual @Overload void reset();
	@Virtual @Overload long skip(long p0);
}
Java_io_InputStream Java_io_InputStream.new();

/* class java.io.InputStreamReader */
class Java_io_InputStreamReader extends Java_io_Reader {
	/*-- Method --*/
	@Virtual @Overload String getEncoding();
}
@Overload Java_io_InputStreamReader Java_io_InputStreamReader.new(Java_io_InputStream p0);
@Overload Java_io_InputStreamReader Java_io_InputStreamReader.new(Java_io_InputStream p0, String p1);
@Overload Java_io_InputStreamReader Java_io_InputStreamReader.new(Java_io_InputStream p0, Java_nio_charset_Charset p1);
@Overload Java_io_InputStreamReader Java_io_InputStreamReader.new(Java_io_InputStream p0, Java_nio_charset_CharsetDecoder p1);

/* class java.io.InterruptedIOException */
class Java_io_InterruptedIOException extends Java_io_IOException {
}
@Overload Java_io_InterruptedIOException Java_io_InterruptedIOException.new();
@Overload Java_io_InterruptedIOException Java_io_InterruptedIOException.new(String p0);

/* class java.io.InvalidClassException */
class Java_io_InvalidClassException extends Java_io_ObjectStreamException {
}
@Overload Java_io_InvalidClassException Java_io_InvalidClassException.new(String p0);
@Overload Java_io_InvalidClassException Java_io_InvalidClassException.new(String p0, String p1);

/* class java.io.InvalidObjectException */
class Java_io_InvalidObjectException extends Java_io_ObjectStreamException {
}
Java_io_InvalidObjectException Java_io_InvalidObjectException.new(String p0);

/* class java.io.LineNumberReader */
class Java_io_LineNumberReader extends Java_io_BufferedReader {
	/*-- Method --*/
	@Virtual @Overload int getLineNumber();
	@Virtual @Overload void setLineNumber(int p0);
}
@Overload Java_io_LineNumberReader Java_io_LineNumberReader.new(Java_io_Reader p0);
@Overload Java_io_LineNumberReader Java_io_LineNumberReader.new(Java_io_Reader p0, int p1);

/* class java.io.NotActiveException */
class Java_io_NotActiveException extends Java_io_ObjectStreamException {
}
@Overload Java_io_NotActiveException Java_io_NotActiveException.new(String p0);
@Overload Java_io_NotActiveException Java_io_NotActiveException.new();

/* class java.io.NotSerializableException */
class Java_io_NotSerializableException extends Java_io_ObjectStreamException {
}
@Overload Java_io_NotSerializableException Java_io_NotSerializableException.new(String p0);
@Overload Java_io_NotSerializableException Java_io_NotSerializableException.new();

/* interface java.io.ObjectInput */
class Java_io_ObjectInput {
	// implements java.io.DataInput, java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload int available();
	@Virtual @Overload void close();
	@Virtual @Overload int read();
	@Virtual @Overload int read(int[] p0);
	@Virtual @Overload int read(int[] p0, int p1, int p2);
	@Virtual @Overload Object readObject();
	@Virtual @Overload long skip(long p0);
}

/* class java.io.ObjectInputStream */
class Java_io_ObjectInputStream extends Java_io_InputStream {
	// implements java.io.ObjectInput, java.io.ObjectStreamConstants
	/*-- Method --*/
	@Virtual @Overload void defaultReadObject();
	@Virtual @Overload boolean readBoolean();
	@Virtual @Overload int readByte();
	@Virtual @Overload int readChar();
	@Virtual @Overload double readDouble();
	@Virtual @Overload Java_io_ObjectInputStream_GetField readFields();
	@Virtual @Overload float readFloat();
	@Virtual @Overload void readFully(int[] p0);
	@Virtual @Overload void readFully(int[] p0, int p1, int p2);
	@Virtual @Overload int readInt();
	@Virtual @Overload long readLong();
	@Virtual @Overload Object readObject();
	@Virtual @Overload int readShort();
	@Virtual @Overload String readUTF();
	@Virtual @Overload Object readUnshared();
	@Virtual @Overload int readUnsignedByte();
	@Virtual @Overload int readUnsignedShort();
	@Virtual @Overload void registerValidation(Java_io_ObjectInputValidation p0, int p1);
	@Virtual @Overload int skipBytes(int p0);
}
Java_io_ObjectInputStream Java_io_ObjectInputStream.new(Java_io_InputStream p0);

/* interface java.io.ObjectInputValidation */
class Java_io_ObjectInputValidation {
	/*-- Method --*/
	@Virtual @Overload void validateObject();
}

/* interface java.io.ObjectOutput */
class Java_io_ObjectOutput {
	// implements java.io.DataOutput, java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload void flush();
	@Virtual @Overload void write(int p0);
	@Virtual @Overload void write(int[] p0);
	@Virtual @Overload void write(int[] p0, int p1, int p2);
	@Virtual @Overload void writeObject(Object p0);
}

/* class java.io.ObjectOutputStream */
class Java_io_ObjectOutputStream extends Java_io_OutputStream {
	// implements java.io.ObjectOutput, java.io.ObjectStreamConstants
	/*-- Method --*/
	@Virtual @Overload void defaultWriteObject();
	@Virtual @Overload Java_io_ObjectOutputStream_PutField putFields();
	@Virtual @Overload void reset();
	@Virtual @Overload void useProtocolVersion(int p0);
	@Virtual @Overload void writeBoolean(boolean p0);
	@Virtual @Overload void writeByte(int p0);
	@Virtual @Overload void writeBytes(String p0);
	@Virtual @Overload void writeChar(int p0);
	@Virtual @Overload void writeChars(String p0);
	@Virtual @Overload void writeDouble(double p0);
	@Virtual @Overload void writeFields();
	@Virtual @Overload void writeFloat(float p0);
	@Virtual @Overload void writeInt(int p0);
	@Virtual @Overload void writeLong(long p0);
	@Virtual @Overload void writeObject(Object p0);
	@Virtual @Overload void writeShort(int p0);
	@Virtual @Overload void writeUTF(String p0);
	@Virtual @Overload void writeUnshared(Object p0);
}
Java_io_ObjectOutputStream Java_io_ObjectOutputStream.new(Java_io_OutputStream p0);

/* class java.io.ObjectStreamClass */
class Java_io_ObjectStreamClass {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Class forClass();
	@Virtual @Overload Java_io_ObjectStreamField getField(String p0);
	@Virtual @Overload Java_io_ObjectStreamField[] getFields();
	@Virtual @Overload String getName();
	@Virtual @Overload long getSerialVersionUID();
	@Virtual @Overload Java_io_ObjectStreamClass lookup(Class p0);
	@Virtual @Overload Java_io_ObjectStreamClass lookupAny(Class p0);
	@Virtual @Overload String toString();
}

/* interface java.io.ObjectStreamConstants */
class Java_io_ObjectStreamConstants {
}

/* class java.io.ObjectStreamException */
class Java_io_ObjectStreamException extends Java_io_IOException {
}

/* class java.io.ObjectStreamField */
class Java_io_ObjectStreamField {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload String getName();
	@Virtual @Overload int getOffset();
	@Virtual @Overload Class getType();
	@Virtual @Overload int getTypeCode();
	@Virtual @Overload String getTypeString();
	@Virtual @Overload boolean isPrimitive();
	@Virtual @Overload boolean isUnshared();
	@Virtual @Overload String toString();
}
@Overload Java_io_ObjectStreamField Java_io_ObjectStreamField.new(String p0, Class p1);
@Overload Java_io_ObjectStreamField Java_io_ObjectStreamField.new(String p0, Class p1, boolean p2);

/* class java.io.OptionalDataException */
class Java_io_OptionalDataException extends Java_io_ObjectStreamException {
}

/* class java.io.OutputStream */
class Java_io_OutputStream {
	// implements java.io.Closeable, java.io.Flushable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload void flush();
	@Virtual @Overload void write(int p0);
	@Virtual @Overload void write(int[] p0);
	@Virtual @Overload void write(int[] p0, int p1, int p2);
}
Java_io_OutputStream Java_io_OutputStream.new();

/* class java.io.OutputStreamWriter */
class Java_io_OutputStreamWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload String getEncoding();
}
@Overload Java_io_OutputStreamWriter Java_io_OutputStreamWriter.new(Java_io_OutputStream p0, String p1);
@Overload Java_io_OutputStreamWriter Java_io_OutputStreamWriter.new(Java_io_OutputStream p0);
@Overload Java_io_OutputStreamWriter Java_io_OutputStreamWriter.new(Java_io_OutputStream p0, Java_nio_charset_Charset p1);
@Overload Java_io_OutputStreamWriter Java_io_OutputStreamWriter.new(Java_io_OutputStream p0, Java_nio_charset_CharsetEncoder p1);

/* class java.io.PipedInputStream */
class Java_io_PipedInputStream extends Java_io_InputStream {
	/*-- Method --*/
	@Virtual @Overload void connect(Java_io_PipedOutputStream p0);
}
@Overload Java_io_PipedInputStream Java_io_PipedInputStream.new(Java_io_PipedOutputStream p0);
@Overload Java_io_PipedInputStream Java_io_PipedInputStream.new(Java_io_PipedOutputStream p0, int p1);
@Overload Java_io_PipedInputStream Java_io_PipedInputStream.new();
@Overload Java_io_PipedInputStream Java_io_PipedInputStream.new(int p0);

/* class java.io.PipedOutputStream */
class Java_io_PipedOutputStream extends Java_io_OutputStream {
	/*-- Method --*/
	@Virtual @Overload void connect(Java_io_PipedInputStream p0);
}
@Overload Java_io_PipedOutputStream Java_io_PipedOutputStream.new(Java_io_PipedInputStream p0);
@Overload Java_io_PipedOutputStream Java_io_PipedOutputStream.new();

/* class java.io.PipedReader */
class Java_io_PipedReader extends Java_io_Reader {
	/*-- Method --*/
	@Virtual @Overload void connect(Java_io_PipedWriter p0);
}
@Overload Java_io_PipedReader Java_io_PipedReader.new(Java_io_PipedWriter p0);
@Overload Java_io_PipedReader Java_io_PipedReader.new(Java_io_PipedWriter p0, int p1);
@Overload Java_io_PipedReader Java_io_PipedReader.new();
@Overload Java_io_PipedReader Java_io_PipedReader.new(int p0);

/* class java.io.PipedWriter */
class Java_io_PipedWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload void connect(Java_io_PipedReader p0);
}
@Overload Java_io_PipedWriter Java_io_PipedWriter.new(Java_io_PipedReader p0);
@Overload Java_io_PipedWriter Java_io_PipedWriter.new();

/* class java.io.PrintStream */
class Java_io_PrintStream extends Java_io_FilterOutputStream {
	// implements java.lang.Appendable, java.io.Closeable
	/*-- Method --*/
	@Virtual @Overload Java_io_PrintStream append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_io_PrintStream append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_io_PrintStream append(int p0);
	@Virtual @Overload Java_lang_Appendable append(int p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload boolean checkError();
	//@Virtual @Overload Java_io_PrintStream format(String p0, Object[] p1);
	//@Virtual @Overload Java_io_PrintStream format(Java_util_Locale p0, String p1, Object[] p2);
	//@Virtual @Overload void print(boolean p0);
	//@Virtual @Overload void print(int p0);
	//@Virtual @Overload void print(int p0);
	//@Virtual @Overload void print(long p0);
	//@Virtual @Overload void print(float p0);
	//@Virtual @Overload void print(double p0);
	//@Virtual @Overload void print(int[] p0);
	//@Virtual @Overload void print(String p0);
	//@Virtual @Overload void print(Object p0);
	@Virtual @Overload Java_io_PrintStream printf(String p0, Object[] p1);
	@Virtual @Overload Java_io_PrintStream printf(Java_util_Locale p0, String p1, Object[] p2);
	@Virtual @Overload void println();
	@Virtual @Overload void println(boolean p0);
	@Virtual @Overload void println(int p0);
	@Virtual @Overload void println(int p0);
	@Virtual @Overload void println(long p0);
	@Virtual @Overload void println(float p0);
	@Virtual @Overload void println(double p0);
	@Virtual @Overload void println(int[] p0);
	@Virtual @Overload void println(String p0);
	@Virtual @Overload void println(Object p0);
}
@Overload Java_io_PrintStream Java_io_PrintStream.new(Java_io_OutputStream p0);
@Overload Java_io_PrintStream Java_io_PrintStream.new(Java_io_OutputStream p0, boolean p1);
@Overload Java_io_PrintStream Java_io_PrintStream.new(Java_io_OutputStream p0, boolean p1, String p2);
@Overload Java_io_PrintStream Java_io_PrintStream.new(String p0);
@Overload Java_io_PrintStream Java_io_PrintStream.new(String p0, String p1);
@Overload Java_io_PrintStream Java_io_PrintStream.new(Java_io_File p0);
@Overload Java_io_PrintStream Java_io_PrintStream.new(Java_io_File p0, String p1);

/* class java.io.PrintWriter */
class Java_io_PrintWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload boolean checkError();
	//@Virtual @Overload Java_io_PrintWriter format(String p0, Object[] p1);
	//@Virtual @Overload Java_io_PrintWriter format(Java_util_Locale p0, String p1, Object[] p2);
	//@Virtual @Overload void print(boolean p0);
	//@Virtual @Overload void print(int p0);
	//@Virtual @Overload void print(int p0);
	//@Virtual @Overload void print(long p0);
	//@Virtual @Overload void print(float p0);
	//@Virtual @Overload void print(double p0);
	//@Virtual @Overload void print(int[] p0);
	//@Virtual @Overload void print(String p0);
	//@Virtual @Overload void print(Object p0);
	@Virtual @Overload Java_io_PrintWriter printf(String p0, Object[] p1);
	@Virtual @Overload Java_io_PrintWriter printf(Java_util_Locale p0, String p1, Object[] p2);
	@Virtual @Overload void println();
	@Virtual @Overload void println(boolean p0);
	@Virtual @Overload void println(int p0);
	@Virtual @Overload void println(int p0);
	@Virtual @Overload void println(long p0);
	@Virtual @Overload void println(float p0);
	@Virtual @Overload void println(double p0);
	@Virtual @Overload void println(int[] p0);
	@Virtual @Overload void println(String p0);
	@Virtual @Overload void println(Object p0);
}
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_Writer p0);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_Writer p0, boolean p1);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_OutputStream p0);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_OutputStream p0, boolean p1);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(String p0);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(String p0, String p1);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_File p0);
@Overload Java_io_PrintWriter Java_io_PrintWriter.new(Java_io_File p0, String p1);

/* class java.io.PushbackInputStream */
class Java_io_PushbackInputStream extends Java_io_FilterInputStream {
	/*-- Method --*/
	@Virtual @Overload void unread(int p0);
	@Virtual @Overload void unread(int[] p0, int p1, int p2);
	@Virtual @Overload void unread(int[] p0);
}
@Overload Java_io_PushbackInputStream Java_io_PushbackInputStream.new(Java_io_InputStream p0, int p1);
@Overload Java_io_PushbackInputStream Java_io_PushbackInputStream.new(Java_io_InputStream p0);

/* class java.io.PushbackReader */
class Java_io_PushbackReader extends Java_io_FilterReader {
	/*-- Method --*/
	@Virtual @Overload void unread(int p0);
	@Virtual @Overload void unread(int[] p0, int p1, int p2);
	@Virtual @Overload void unread(int[] p0);
}
@Overload Java_io_PushbackReader Java_io_PushbackReader.new(Java_io_Reader p0, int p1);
@Overload Java_io_PushbackReader Java_io_PushbackReader.new(Java_io_Reader p0);

/* class java.io.RandomAccessFile */
class Java_io_RandomAccessFile {
	// implements java.io.DataOutput, java.io.DataInput, java.io.Closeable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload Java_nio_channels_FileChannel getChannel();
	@Virtual @Overload Java_io_FileDescriptor getFD();
	@Virtual @Overload long getFilePointer();
	@Virtual @Overload long length();
	@Virtual @Overload int read();
	@Virtual @Overload int read(int[] p0, int p1, int p2);
	@Virtual @Overload int read(int[] p0);
	@Virtual @Overload boolean readBoolean();
	@Virtual @Overload int readByte();
	@Virtual @Overload int readChar();
	@Virtual @Overload double readDouble();
	@Virtual @Overload float readFloat();
	@Virtual @Overload void readFully(int[] p0);
	@Virtual @Overload void readFully(int[] p0, int p1, int p2);
	@Virtual @Overload int readInt();
	@Virtual @Overload String readLine();
	@Virtual @Overload long readLong();
	@Virtual @Overload int readShort();
	@Virtual @Overload String readUTF();
	@Virtual @Overload int readUnsignedByte();
	@Virtual @Overload int readUnsignedShort();
	@Virtual @Overload void seek(long p0);
	@Virtual @Overload void setLength(long p0);
	@Virtual @Overload int skipBytes(int p0);
	@Virtual @Overload void write(int p0);
	@Virtual @Overload void write(int[] p0);
	@Virtual @Overload void write(int[] p0, int p1, int p2);
	@Virtual @Overload void writeBoolean(boolean p0);
	@Virtual @Overload void writeByte(int p0);
	@Virtual @Overload void writeBytes(String p0);
	@Virtual @Overload void writeChar(int p0);
	@Virtual @Overload void writeChars(String p0);
	@Virtual @Overload void writeDouble(double p0);
	@Virtual @Overload void writeFloat(float p0);
	@Virtual @Overload void writeInt(int p0);
	@Virtual @Overload void writeLong(long p0);
	@Virtual @Overload void writeShort(int p0);
	@Virtual @Overload void writeUTF(String p0);
}
@Overload Java_io_RandomAccessFile Java_io_RandomAccessFile.new(String p0, String p1);
@Overload Java_io_RandomAccessFile Java_io_RandomAccessFile.new(Java_io_File p0, String p1);

/* class java.io.Reader */
class Java_io_Reader {
	// implements java.lang.Readable, java.io.Closeable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload void mark(int p0);
	@Virtual @Overload boolean markSupported();
	@Virtual @Overload int read(Java_nio_CharBuffer p0);
	@Virtual @Overload int read();
	@Virtual @Overload int read(int[] p0);
	@Virtual @Overload int read(int[] p0, int p1, int p2);
	@Virtual @Overload boolean ready();
	@Virtual @Overload void reset();
	@Virtual @Overload long skip(long p0);
}

/* class java.io.SequenceInputStream */
class Java_io_SequenceInputStream extends Java_io_InputStream {
}
@Overload Java_io_SequenceInputStream Java_io_SequenceInputStream.new(Java_util_Enumeration p0);
@Overload Java_io_SequenceInputStream Java_io_SequenceInputStream.new(Java_io_InputStream p0, Java_io_InputStream p1);

/* interface java.io.Serializable */
class Java_io_Serializable {
}

/* class java.io.SerializablePermission */
class Java_io_SerializablePermission extends Java_security_BasicPermission {
}
@Overload Java_io_SerializablePermission Java_io_SerializablePermission.new(String p0);
@Overload Java_io_SerializablePermission Java_io_SerializablePermission.new(String p0, String p1);

/* class java.io.StreamCorruptedException */
class Java_io_StreamCorruptedException extends Java_io_ObjectStreamException {
}
@Overload Java_io_StreamCorruptedException Java_io_StreamCorruptedException.new(String p0);
@Overload Java_io_StreamCorruptedException Java_io_StreamCorruptedException.new();

/* class java.io.StreamTokenizer */
class Java_io_StreamTokenizer {
	/*-- Method --*/
	@Virtual @Overload void commentChar(int p0);
	@Virtual @Overload void eolIsSignificant(boolean p0);
	@Virtual @Overload int lineno();
	@Virtual @Overload void lowerCaseMode(boolean p0);
	@Virtual @Overload int nextToken();
	@Virtual @Overload void ordinaryChar(int p0);
	@Virtual @Overload void ordinaryChars(int p0, int p1);
	@Virtual @Overload void parseNumbers();
	@Virtual @Overload void pushBack();
	@Virtual @Overload void quoteChar(int p0);
	@Virtual @Overload void resetSyntax();
	@Virtual @Overload void slashSlashComments(boolean p0);
	@Virtual @Overload void slashStarComments(boolean p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void whitespaceChars(int p0, int p1);
	@Virtual @Overload void wordChars(int p0, int p1);
}
@Overload Java_io_StreamTokenizer Java_io_StreamTokenizer.new(Java_io_InputStream p0);
@Overload Java_io_StreamTokenizer Java_io_StreamTokenizer.new(Java_io_Reader p0);

/* class java.io.StringReader */
class Java_io_StringReader extends Java_io_Reader {
}
Java_io_StringReader Java_io_StringReader.new(String p0);

/* class java.io.StringWriter */
class Java_io_StringWriter extends Java_io_Writer {
	/*-- Method --*/
	@Virtual @Overload Java_lang_StringBuffer getBuffer();
}
@Overload Java_io_StringWriter Java_io_StringWriter.new();
@Overload Java_io_StringWriter Java_io_StringWriter.new(int p0);

/* class java.io.SyncFailedException */
class Java_io_SyncFailedException extends Java_io_IOException {
}
Java_io_SyncFailedException Java_io_SyncFailedException.new(String p0);

/* class java.io.UTFDataFormatException */
class Java_io_UTFDataFormatException extends Java_io_IOException {
}
@Overload Java_io_UTFDataFormatException Java_io_UTFDataFormatException.new();
@Overload Java_io_UTFDataFormatException Java_io_UTFDataFormatException.new(String p0);

/* class java.io.UnsupportedEncodingException */
class Java_io_UnsupportedEncodingException extends Java_io_IOException {
}
@Overload Java_io_UnsupportedEncodingException Java_io_UnsupportedEncodingException.new();
@Overload Java_io_UnsupportedEncodingException Java_io_UnsupportedEncodingException.new(String p0);

/* class java.io.WriteAbortedException */
class Java_io_WriteAbortedException extends Java_io_ObjectStreamException {
}
Java_io_WriteAbortedException Java_io_WriteAbortedException.new(String p0, Java_lang_Exception p1);

/* class java.io.Writer */
class Java_io_Writer {
	// implements java.lang.Appendable, java.io.Closeable, java.io.Flushable
	/*-- Method --*/
	@Virtual @Overload Java_io_Writer append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_io_Writer append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_io_Writer append(int p0);
	@Virtual @Overload Java_lang_Appendable append(int p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload void close();
	@Virtual @Overload void flush();
	@Virtual @Overload void write(int p0);
	@Virtual @Overload void write(int[] p0);
	@Virtual @Overload void write(int[] p0, int p1, int p2);
	@Virtual @Overload void write(String p0);
	@Virtual @Overload void write(String p0, int p1, int p2);
}


/*------------------------------------------------------------*/
/* short names */
BufferedInputStream = Java_io_BufferedInputStream
BufferedOutputStream = Java_io_BufferedOutputStream
BufferedReader = Java_io_BufferedReader
BufferedWriter = Java_io_BufferedWriter
ByteArrayInputStream = Java_io_ByteArrayInputStream
ByteArrayOutputStream = Java_io_ByteArrayOutputStream
CharArrayReader = Java_io_CharArrayReader
CharArrayWriter = Java_io_CharArrayWriter
CharConversionException = Java_io_CharConversionException
Closeable = Java_io_Closeable
Console = Java_io_Console
DataInput = Java_io_DataInput
DataInputStream = Java_io_DataInputStream
DataOutput = Java_io_DataOutput
DataOutputStream = Java_io_DataOutputStream
EOFException = Java_io_EOFException
Externalizable = Java_io_Externalizable
File = Java_io_File
FileDescriptor = Java_io_FileDescriptor
FileFilter = Java_io_FileFilter
FileInputStream = Java_io_FileInputStream
FileNotFoundException = Java_io_FileNotFoundException
FileOutputStream = Java_io_FileOutputStream
FilePermission = Java_io_FilePermission
FileReader = Java_io_FileReader
FileWriter = Java_io_FileWriter
FilenameFilter = Java_io_FilenameFilter
FilterInputStream = Java_io_FilterInputStream
FilterOutputStream = Java_io_FilterOutputStream
FilterReader = Java_io_FilterReader
FilterWriter = Java_io_FilterWriter
Flushable = Java_io_Flushable
IOError = Java_io_IOError
IOException = Java_io_IOException
InputStream = Java_io_InputStream
InputStreamReader = Java_io_InputStreamReader
InterruptedIOException = Java_io_InterruptedIOException
InvalidClassException = Java_io_InvalidClassException
InvalidObjectException = Java_io_InvalidObjectException
LineNumberReader = Java_io_LineNumberReader
NotActiveException = Java_io_NotActiveException
NotSerializableException = Java_io_NotSerializableException
ObjectInput = Java_io_ObjectInput
ObjectInputStream = Java_io_ObjectInputStream
ObjectInputValidation = Java_io_ObjectInputValidation
ObjectOutput = Java_io_ObjectOutput
ObjectOutputStream = Java_io_ObjectOutputStream
ObjectStreamClass = Java_io_ObjectStreamClass
ObjectStreamConstants = Java_io_ObjectStreamConstants
ObjectStreamException = Java_io_ObjectStreamException
ObjectStreamField = Java_io_ObjectStreamField
OptionalDataException = Java_io_OptionalDataException
OutputStream = Java_io_OutputStream
OutputStreamWriter = Java_io_OutputStreamWriter
PipedInputStream = Java_io_PipedInputStream
PipedOutputStream = Java_io_PipedOutputStream
PipedReader = Java_io_PipedReader
PipedWriter = Java_io_PipedWriter
PrintStream = Java_io_PrintStream
PrintWriter = Java_io_PrintWriter
PushbackInputStream = Java_io_PushbackInputStream
PushbackReader = Java_io_PushbackReader
RandomAccessFile = Java_io_RandomAccessFile
Reader = Java_io_Reader
SequenceInputStream = Java_io_SequenceInputStream
Serializable = Java_io_Serializable
SerializablePermission = Java_io_SerializablePermission
StreamCorruptedException = Java_io_StreamCorruptedException
StreamTokenizer = Java_io_StreamTokenizer
StringReader = Java_io_StringReader
StringWriter = Java_io_StringWriter
SyncFailedException = Java_io_SyncFailedException
UTFDataFormatException = Java_io_UTFDataFormatException
UnsupportedEncodingException = Java_io_UnsupportedEncodingException
WriteAbortedException = Java_io_WriteAbortedException
Writer = Java_io_Writer
