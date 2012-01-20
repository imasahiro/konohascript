/* converted from java package java.nio */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_lang_Appendable;
class Java_lang_CharSequence;
class Java_lang_IllegalStateException;
class Java_lang_RuntimeException;
class Java_lang_UnsupportedOperationException;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_nio_Buffer;
class Java_nio_BufferOverflowException extends Java_lang_RuntimeException;
class Java_nio_BufferUnderflowException extends Java_lang_RuntimeException;
class Java_nio_ByteBuffer extends Java_nio_Buffer;
class Java_nio_ByteOrder;
class Java_nio_CharBuffer extends Java_nio_Buffer;
class Java_nio_DoubleBuffer extends Java_nio_Buffer;
class Java_nio_FloatBuffer extends Java_nio_Buffer;
class Java_nio_IntBuffer extends Java_nio_Buffer;
class Java_nio_InvalidMarkException extends Java_lang_IllegalStateException;
class Java_nio_LongBuffer extends Java_nio_Buffer;
class Java_nio_MappedByteBuffer extends Java_nio_ByteBuffer;
class Java_nio_ReadOnlyBufferException extends Java_lang_UnsupportedOperationException;
class Java_nio_ShortBuffer extends Java_nio_Buffer;

/*------------------------------------------------------------*/
/* class java.nio.Buffer */
class Java_nio_Buffer {
	/*-- Method --*/
	@Virtual @Overload Object array();
	@Virtual @Overload int arrayOffset();
	@Virtual @Overload int capacity();
	@Virtual @Overload Java_nio_Buffer clear();
	@Virtual @Overload Java_nio_Buffer flip();
	@Virtual @Overload boolean hasArray();
	@Virtual @Overload boolean hasRemaining();
	@Virtual @Overload boolean isDirect();
	@Virtual @Overload boolean isReadOnly();
	@Virtual @Overload int limit();
	@Virtual @Overload Java_nio_Buffer limit(int p0);
	@Virtual @Overload Java_nio_Buffer mark();
	@Virtual @Overload int position();
	@Virtual @Overload Java_nio_Buffer position(int p0);
	@Virtual @Overload int remaining();
	@Virtual @Overload Java_nio_Buffer reset();
	@Virtual @Overload Java_nio_Buffer rewind();
}

/* class java.nio.BufferOverflowException */
class Java_nio_BufferOverflowException extends Java_lang_RuntimeException {
}
Java_nio_BufferOverflowException Java_nio_BufferOverflowException.new();

/* class java.nio.BufferUnderflowException */
class Java_nio_BufferUnderflowException extends Java_lang_RuntimeException {
}
Java_nio_BufferUnderflowException Java_nio_BufferUnderflowException.new();

/* class java.nio.ByteBuffer */
class Java_nio_ByteBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_ByteBuffer allocate(int p0);
	@Virtual @Overload Java_nio_ByteBuffer allocateDirect(int p0);
	@Virtual @Overload Java_nio_CharBuffer asCharBuffer();
	@Virtual @Overload Java_nio_DoubleBuffer asDoubleBuffer();
	@Virtual @Overload Java_nio_FloatBuffer asFloatBuffer();
	@Virtual @Overload Java_nio_IntBuffer asIntBuffer();
	@Virtual @Overload Java_nio_LongBuffer asLongBuffer();
	@Virtual @Overload Java_nio_ByteBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_ShortBuffer asShortBuffer();
	@Virtual @Overload Java_nio_ByteBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_ByteBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_ByteBuffer duplicate();
	@Virtual @Overload int get();
	@Virtual @Overload int get(int p0);
	@Virtual @Overload Java_nio_ByteBuffer get(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ByteBuffer get(int[] p0);
	@Virtual @Overload int getChar();
	@Virtual @Overload int getChar(int p0);
	@Virtual @Overload double getDouble();
	@Virtual @Overload double getDouble(int p0);
	@Virtual @Overload float getFloat();
	@Virtual @Overload float getFloat(int p0);
	@Virtual @Overload int getInt();
	@Virtual @Overload int getInt(int p0);
	@Virtual @Overload long getLong();
	@Virtual @Overload long getLong(int p0);
	@Virtual @Overload int getShort();
	@Virtual @Overload int getShort(int p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_ByteBuffer order(Java_nio_ByteOrder p0);
	@Virtual @Overload Java_nio_ByteBuffer put(int p0);
	@Virtual @Overload Java_nio_ByteBuffer put(int p0, int p1);
	@Virtual @Overload Java_nio_ByteBuffer put(Java_nio_ByteBuffer p0);
	@Virtual @Overload Java_nio_ByteBuffer put(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ByteBuffer put(int[] p0);
	@Virtual @Overload Java_nio_ByteBuffer putChar(int p0);
	@Virtual @Overload Java_nio_ByteBuffer putChar(int p0, int p1);
	@Virtual @Overload Java_nio_ByteBuffer putDouble(double p0);
	@Virtual @Overload Java_nio_ByteBuffer putDouble(int p0, double p1);
	@Virtual @Overload Java_nio_ByteBuffer putFloat(float p0);
	@Virtual @Overload Java_nio_ByteBuffer putFloat(int p0, float p1);
	@Virtual @Overload Java_nio_ByteBuffer putInt(int p0);
	@Virtual @Overload Java_nio_ByteBuffer putInt(int p0, int p1);
	@Virtual @Overload Java_nio_ByteBuffer putLong(long p0);
	@Virtual @Overload Java_nio_ByteBuffer putLong(int p0, long p1);
	@Virtual @Overload Java_nio_ByteBuffer putShort(int p0);
	@Virtual @Overload Java_nio_ByteBuffer putShort(int p0, int p1);
	@Virtual @Overload Java_nio_ByteBuffer slice();
	@Virtual @Overload Java_nio_ByteBuffer wrap(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ByteBuffer wrap(int[] p0);
}

/* class java.nio.ByteOrder */
class Java_nio_ByteOrder {
	/*-- Method --*/
	@Virtual @Overload Java_nio_ByteOrder nativeOrder();
	@Virtual @Overload String toString();
}

/* class java.nio.CharBuffer */
class Java_nio_CharBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable, java.lang.Appendable, java.lang.CharSequence, java.lang.Readable
	/*-- Method --*/
	@Virtual @Overload Java_nio_CharBuffer allocate(int p0);
	@Virtual @Overload Java_nio_CharBuffer append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_nio_CharBuffer append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer append(int p0);
	@Virtual @Overload Java_lang_Appendable append(int p0);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_lang_Appendable append(Java_lang_CharSequence p0);
	@Virtual @Overload Java_nio_CharBuffer asReadOnlyBuffer();
	@Virtual @Overload int charAt(int p0);
	@Virtual @Overload Java_nio_CharBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_CharBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_CharBuffer duplicate();
	@Virtual @Overload int get();
	@Virtual @Overload int get(int p0);
	@Virtual @Overload Java_nio_CharBuffer get(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer get(int[] p0);
	@Virtual @Overload int length();
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_CharBuffer put(int p0);
	@Virtual @Overload Java_nio_CharBuffer put(int p0, int p1);
	@Virtual @Overload Java_nio_CharBuffer put(Java_nio_CharBuffer p0);
	@Virtual @Overload Java_nio_CharBuffer put(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer put(int[] p0);
	@Virtual @Overload Java_nio_CharBuffer put(String p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer put(String p0);
	@Virtual @Overload int read(Java_nio_CharBuffer p0);
	@Virtual @Overload Java_nio_CharBuffer slice();
	@Virtual @Overload Java_nio_CharBuffer subSequence(int p0, int p1);
	@Virtual @Overload Java_lang_CharSequence subSequence(int p0, int p1);
	@Virtual @Overload Java_nio_CharBuffer wrap(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer wrap(int[] p0);
	@Virtual @Overload Java_nio_CharBuffer wrap(Java_lang_CharSequence p0, int p1, int p2);
	@Virtual @Overload Java_nio_CharBuffer wrap(Java_lang_CharSequence p0);
}

/* class java.nio.DoubleBuffer */
class Java_nio_DoubleBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_DoubleBuffer allocate(int p0);
	@Virtual @Overload Java_nio_DoubleBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_DoubleBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_DoubleBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_DoubleBuffer duplicate();
	@Virtual @Overload double get();
	@Virtual @Overload double get(int p0);
	@Virtual @Overload Java_nio_DoubleBuffer get(double[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_DoubleBuffer get(double[] p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_DoubleBuffer put(double p0);
	@Virtual @Overload Java_nio_DoubleBuffer put(int p0, double p1);
	@Virtual @Overload Java_nio_DoubleBuffer put(Java_nio_DoubleBuffer p0);
	@Virtual @Overload Java_nio_DoubleBuffer put(double[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_DoubleBuffer put(double[] p0);
	@Virtual @Overload Java_nio_DoubleBuffer slice();
	@Virtual @Overload Java_nio_DoubleBuffer wrap(double[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_DoubleBuffer wrap(double[] p0);
}

/* class java.nio.FloatBuffer */
class Java_nio_FloatBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_FloatBuffer allocate(int p0);
	@Virtual @Overload Java_nio_FloatBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_FloatBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_FloatBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_FloatBuffer duplicate();
	@Virtual @Overload float get();
	@Virtual @Overload float get(int p0);
	@Virtual @Overload Java_nio_FloatBuffer get(float[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_FloatBuffer get(float[] p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_FloatBuffer put(float p0);
	@Virtual @Overload Java_nio_FloatBuffer put(int p0, float p1);
	@Virtual @Overload Java_nio_FloatBuffer put(Java_nio_FloatBuffer p0);
	@Virtual @Overload Java_nio_FloatBuffer put(float[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_FloatBuffer put(float[] p0);
	@Virtual @Overload Java_nio_FloatBuffer slice();
	@Virtual @Overload Java_nio_FloatBuffer wrap(float[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_FloatBuffer wrap(float[] p0);
}

/* class java.nio.IntBuffer */
class Java_nio_IntBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_IntBuffer allocate(int p0);
	@Virtual @Overload Java_nio_IntBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_IntBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_IntBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_IntBuffer duplicate();
	@Virtual @Overload int get();
	@Virtual @Overload int get(int p0);
	@Virtual @Overload Java_nio_IntBuffer get(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_IntBuffer get(int[] p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_IntBuffer put(int p0);
	@Virtual @Overload Java_nio_IntBuffer put(int p0, int p1);
	@Virtual @Overload Java_nio_IntBuffer put(Java_nio_IntBuffer p0);
	@Virtual @Overload Java_nio_IntBuffer put(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_IntBuffer put(int[] p0);
	@Virtual @Overload Java_nio_IntBuffer slice();
	@Virtual @Overload Java_nio_IntBuffer wrap(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_IntBuffer wrap(int[] p0);
}

/* class java.nio.InvalidMarkException */
class Java_nio_InvalidMarkException extends Java_lang_IllegalStateException {
}
Java_nio_InvalidMarkException Java_nio_InvalidMarkException.new();

/* class java.nio.LongBuffer */
class Java_nio_LongBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_LongBuffer allocate(int p0);
	@Virtual @Overload Java_nio_LongBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_LongBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_LongBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_LongBuffer duplicate();
	@Virtual @Overload long get();
	@Virtual @Overload long get(int p0);
	@Virtual @Overload Java_nio_LongBuffer get(long[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_LongBuffer get(long[] p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_LongBuffer put(long p0);
	@Virtual @Overload Java_nio_LongBuffer put(int p0, long p1);
	@Virtual @Overload Java_nio_LongBuffer put(Java_nio_LongBuffer p0);
	@Virtual @Overload Java_nio_LongBuffer put(long[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_LongBuffer put(long[] p0);
	@Virtual @Overload Java_nio_LongBuffer slice();
	@Virtual @Overload Java_nio_LongBuffer wrap(long[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_LongBuffer wrap(long[] p0);
}

/* class java.nio.MappedByteBuffer */
class Java_nio_MappedByteBuffer extends Java_nio_ByteBuffer {
	/*-- Method --*/
	@Virtual @Overload Java_nio_MappedByteBuffer force();
	@Virtual @Overload boolean isLoaded();
	@Virtual @Overload Java_nio_MappedByteBuffer load();
}

/* class java.nio.ReadOnlyBufferException */
class Java_nio_ReadOnlyBufferException extends Java_lang_UnsupportedOperationException {
}
Java_nio_ReadOnlyBufferException Java_nio_ReadOnlyBufferException.new();

/* class java.nio.ShortBuffer */
class Java_nio_ShortBuffer extends Java_nio_Buffer {
	// implements java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload Java_nio_ShortBuffer allocate(int p0);
	@Virtual @Overload Java_nio_ShortBuffer asReadOnlyBuffer();
	@Virtual @Overload Java_nio_ShortBuffer compact();
	@Virtual @Overload int compareTo(Java_nio_ShortBuffer p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload Java_nio_ShortBuffer duplicate();
	@Virtual @Overload int get();
	@Virtual @Overload int get(int p0);
	@Virtual @Overload Java_nio_ShortBuffer get(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ShortBuffer get(int[] p0);
	@Virtual @Overload Java_nio_ByteOrder order();
	@Virtual @Overload Java_nio_ShortBuffer put(int p0);
	@Virtual @Overload Java_nio_ShortBuffer put(int p0, int p1);
	@Virtual @Overload Java_nio_ShortBuffer put(Java_nio_ShortBuffer p0);
	@Virtual @Overload Java_nio_ShortBuffer put(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ShortBuffer put(int[] p0);
	@Virtual @Overload Java_nio_ShortBuffer slice();
	@Virtual @Overload Java_nio_ShortBuffer wrap(int[] p0, int p1, int p2);
	@Virtual @Overload Java_nio_ShortBuffer wrap(int[] p0);
}


/*------------------------------------------------------------*/
/* short names */
Buffer = Java_nio_Buffer
BufferOverflowException = Java_nio_BufferOverflowException
BufferUnderflowException = Java_nio_BufferUnderflowException
ByteBuffer = Java_nio_ByteBuffer
ByteOrder = Java_nio_ByteOrder
CharBuffer = Java_nio_CharBuffer
DoubleBuffer = Java_nio_DoubleBuffer
FloatBuffer = Java_nio_FloatBuffer
IntBuffer = Java_nio_IntBuffer
InvalidMarkException = Java_nio_InvalidMarkException
LongBuffer = Java_nio_LongBuffer
MappedByteBuffer = Java_nio_MappedByteBuffer
ReadOnlyBufferException = Java_nio_ReadOnlyBufferException
ShortBuffer = Java_nio_ShortBuffer
