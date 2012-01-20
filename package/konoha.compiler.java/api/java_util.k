/* converted from java package java.util */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_io_File;
class Java_io_IOException;
class Java_io_InputStream;
class Java_io_OutputStream;
class Java_io_PrintStream;
class Java_io_PrintWriter;
class Java_io_Reader;
class Java_io_Writer;
class Java_lang_Appendable;
class Java_lang_ClassLoader;
class Java_lang_Enum;
class Java_lang_Error;
class Java_lang_Exception;
class Java_lang_IllegalArgumentException;
class Java_lang_IllegalStateException;
class Java_lang_Readable;
class Java_lang_RuntimeException;
class Java_lang_Throwable;
class Java_math_BigDecimal;
class Java_math_BigInteger;
class Java_nio_ByteBuffer;
class Java_nio_LongBuffer;
class Java_nio_channels_ReadableByteChannel;
class Java_nio_file_Path;
class Java_security_BasicPermission;
class Java_util_Locale_Category;
class Java_util_Map_Entry;
class Java_util_ResourceBundle_Control;
class Java_util_regex_MatchResult;
class Java_util_regex_Pattern;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_util_AbstractCollection;
class Java_util_AbstractList extends Java_util_AbstractCollection;
class Java_util_AbstractMap;
class Java_util_AbstractQueue extends Java_util_AbstractCollection;
class Java_util_AbstractSequentialList extends Java_util_AbstractList;
class Java_util_AbstractSet extends Java_util_AbstractCollection;
class Java_util_ArrayDeque extends Java_util_AbstractCollection;
class Java_util_ArrayList extends Java_util_AbstractList;
class Java_util_Arrays;
class Java_util_BitSet;
class Java_util_Calendar;
class Java_util_Collection;
class Java_util_Collections;
class Java_util_Comparator;
class Java_util_ConcurrentModificationException extends Java_lang_RuntimeException;
class Java_util_Currency;
class Java_util_Date;
class Java_util_Deque;
class Java_util_Dictionary;
class Java_util_IllegalFormatException extends Java_lang_IllegalArgumentException;
class Java_util_DuplicateFormatFlagsException extends Java_util_IllegalFormatException;
class Java_util_EmptyStackException extends Java_lang_RuntimeException;
class Java_util_EnumMap extends Java_util_AbstractMap;
class Java_util_EnumSet extends Java_util_AbstractSet;
class Java_util_Enumeration;
class Java_util_EventListener;
class Java_util_EventListenerProxy;
class Java_util_EventObject;
class Java_util_FormatFlagsConversionMismatchException extends Java_util_IllegalFormatException;
class Java_util_Formattable;
class Java_util_FormattableFlags;
class Java_util_Formatter;
class Java_util_FormatterClosedException extends Java_lang_IllegalStateException;
class Java_util_GregorianCalendar extends Java_util_Calendar;
class Java_util_HashMap extends Java_util_AbstractMap;
class Java_util_HashSet extends Java_util_AbstractSet;
class Java_util_Hashtable extends Java_util_Dictionary;
class Java_util_IdentityHashMap extends Java_util_AbstractMap;
class Java_util_IllegalFormatCodePointException extends Java_util_IllegalFormatException;
class Java_util_IllegalFormatConversionException extends Java_util_IllegalFormatException;
class Java_util_IllegalFormatFlagsException extends Java_util_IllegalFormatException;
class Java_util_IllegalFormatPrecisionException extends Java_util_IllegalFormatException;
class Java_util_IllegalFormatWidthException extends Java_util_IllegalFormatException;
class Java_util_IllformedLocaleException extends Java_lang_RuntimeException;
class Java_util_NoSuchElementException extends Java_lang_RuntimeException;
class Java_util_InputMismatchException extends Java_util_NoSuchElementException;
class Java_util_InvalidPropertiesFormatException extends Java_io_IOException;
class Java_util_Iterator;
class Java_util_LinkedHashMap extends Java_util_HashMap;
class Java_util_LinkedHashSet extends Java_util_HashSet;
class Java_util_LinkedList extends Java_util_AbstractSequentialList;
class Java_util_List;
class Java_util_ListIterator;
class Java_util_ResourceBundle;
class Java_util_ListResourceBundle extends Java_util_ResourceBundle;
class Java_util_Locale;
class Java_util_Map;
class Java_util_MissingFormatArgumentException extends Java_util_IllegalFormatException;
class Java_util_MissingFormatWidthException extends Java_util_IllegalFormatException;
class Java_util_MissingResourceException extends Java_lang_RuntimeException;
class Java_util_NavigableMap;
class Java_util_NavigableSet;
class Java_util_Objects;
class Java_util_Observable;
class Java_util_Observer;
class Java_util_PriorityQueue extends Java_util_AbstractQueue;
class Java_util_Properties extends Java_util_Hashtable;
class Java_util_PropertyPermission extends Java_security_BasicPermission;
class Java_util_PropertyResourceBundle extends Java_util_ResourceBundle;
class Java_util_Queue;
class Java_util_Random;
class Java_util_RandomAccess;
class Java_util_Scanner;
class Java_util_ServiceConfigurationError extends Java_lang_Error;
class Java_util_ServiceLoader;
class Java_util_Set;
class Java_util_TimeZone;
class Java_util_SimpleTimeZone extends Java_util_TimeZone;
class Java_util_SortedMap;
class Java_util_SortedSet;
class Java_util_Vector extends Java_util_AbstractList;
class Java_util_Stack extends Java_util_Vector;
class Java_util_StringTokenizer;
class Java_util_Timer;
class Java_util_TimerTask;
class Java_util_TooManyListenersException extends Java_lang_Exception;
class Java_util_TreeMap extends Java_util_AbstractMap;
class Java_util_TreeSet extends Java_util_AbstractSet;
class Java_util_UUID;
class Java_util_UnknownFormatConversionException extends Java_util_IllegalFormatException;
class Java_util_UnknownFormatFlagsException extends Java_util_IllegalFormatException;
class Java_util_WeakHashMap extends Java_util_AbstractMap;

/*------------------------------------------------------------*/
/* class java.util.AbstractCollection */
class Java_util_AbstractCollection {
	// implements java.util.Collection
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload boolean addAll(Java_util_Collection p0);
	@Virtual @Overload void clear();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsAll(Java_util_Collection p0);
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload boolean removeAll(Java_util_Collection p0);
	@Virtual @Overload boolean retainAll(Java_util_Collection p0);
	@Virtual @Overload int size();
	@Virtual @Overload Object[] toArray();
	@Virtual @Overload Object[] toArray(Object[] p0);
	@Virtual @Overload String toString();
}

/* class java.util.AbstractList */
class Java_util_AbstractList extends Java_util_AbstractCollection {
	// implements java.util.List
	/*-- Method --*/
	@Virtual @Overload void add(int p0, Object p1);
	@Virtual @Overload boolean addAll(int p0, Java_util_Collection p1);
	@Virtual @Overload Object get(int p0);
	@Virtual @Overload int indexOf(Object p0);
	@Virtual @Overload int lastIndexOf(Object p0);
	@Virtual @Overload Java_util_ListIterator listIterator();
	@Virtual @Overload Java_util_ListIterator listIterator(int p0);
	@Virtual @Overload Object remove(int p0);
	@Virtual @Overload Object set(int p0, Object p1);
	@Virtual @Overload Java_util_List subList(int p0, int p1);
}

/* class java.util.AbstractMap */
class Java_util_AbstractMap {
	// implements java.util.Map
	/*-- Method --*/
	@Virtual @Overload void clear();
	@Virtual @Overload boolean containsKey(Object p0);
	@Virtual @Overload boolean containsValue(Object p0);
	@Virtual @Overload Java_util_Set entrySet();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Object get(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Set keySet();
	@Virtual @Overload Object put(Object p0, Object p1);
	@Virtual @Overload void putAll(Java_util_Map p0);
	@Virtual @Overload Object remove(Object p0);
	@Virtual @Overload int size();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_util_Collection values();
}

/* class java.util.AbstractQueue */
class Java_util_AbstractQueue extends Java_util_AbstractCollection {
	// implements java.util.Queue
	/*-- Method --*/
	@Virtual @Overload Object element();
	@Virtual @Overload Object remove();
}

/* class java.util.AbstractSequentialList */
class Java_util_AbstractSequentialList extends Java_util_AbstractList {
}

/* class java.util.AbstractSet */
class Java_util_AbstractSet extends Java_util_AbstractCollection {
	// implements java.util.Set
}

/* class java.util.ArrayDeque */
class Java_util_ArrayDeque extends Java_util_AbstractCollection {
	// implements java.util.Deque, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
	@Virtual @Overload Java_util_ArrayDeque clone();
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Object element();
	@Virtual @Overload Object getFirst();
	@Virtual @Overload Object getLast();
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload boolean offerFirst(Object p0);
	@Virtual @Overload boolean offerLast(Object p0);
	@Virtual @Overload Object peek();
	@Virtual @Overload Object peekFirst();
	@Virtual @Overload Object peekLast();
	@Virtual @Overload Object poll();
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Object pop();
	@Virtual @Overload void push(Object p0);
	@Virtual @Overload Object remove();
	@Virtual @Overload Object removeFirst();
	@Virtual @Overload boolean removeFirstOccurrence(Object p0);
	@Virtual @Overload Object removeLast();
	@Virtual @Overload boolean removeLastOccurrence(Object p0);
}
@Overload Java_util_ArrayDeque Java_util_ArrayDeque.new();
@Overload Java_util_ArrayDeque Java_util_ArrayDeque.new(int p0);
@Overload Java_util_ArrayDeque Java_util_ArrayDeque.new(Java_util_Collection p0);

/* class java.util.ArrayList */
class Java_util_ArrayList extends Java_util_AbstractList {
	// implements java.util.List, java.util.RandomAccess, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload void ensureCapacity(int p0);
	@Virtual @Overload void trimToSize();
}
@Overload Java_util_ArrayList Java_util_ArrayList.new(int p0);
@Overload Java_util_ArrayList Java_util_ArrayList.new();
@Overload Java_util_ArrayList Java_util_ArrayList.new(Java_util_Collection p0);

/* class java.util.Arrays */
class Java_util_Arrays {
	/*-- Method --*/
	@Virtual @Overload Java_util_List asList(Object[] p0);
	@Virtual @Overload int binarySearch(long[] p0, long p1);
	@Virtual @Overload int binarySearch(long[] p0, int p1, int p2, long p3);
	@Virtual @Overload int binarySearch(int[] p0, int p1);
	@Virtual @Overload int binarySearch(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload int binarySearch(int[] p0, int p1);
	@Virtual @Overload int binarySearch(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload int binarySearch(int[] p0, int p1);
	@Virtual @Overload int binarySearch(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload int binarySearch(int[] p0, int p1);
	@Virtual @Overload int binarySearch(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload int binarySearch(double[] p0, double p1);
	@Virtual @Overload int binarySearch(double[] p0, int p1, int p2, double p3);
	@Virtual @Overload int binarySearch(float[] p0, float p1);
	@Virtual @Overload int binarySearch(float[] p0, int p1, int p2, float p3);
	@Virtual @Overload int binarySearch(Object[] p0, Object p1);
	@Virtual @Overload int binarySearch(Object[] p0, int p1, int p2, Object p3);
	@Virtual @Overload int binarySearch(Object[] p0, Object p1, Java_util_Comparator p2);
	@Virtual @Overload int binarySearch(Object[] p0, int p1, int p2, Object p3, Java_util_Comparator p4);
	@Virtual @Overload Object[] copyOf(Object[] p0, int p1);
	@Virtual @Overload Object[] copyOf(Object[] p0, int p1, Class p2);
	@Virtual @Overload int[] copyOf(int[] p0, int p1);
	@Virtual @Overload int[] copyOf(int[] p0, int p1);
	@Virtual @Overload int[] copyOf(int[] p0, int p1);
	@Virtual @Overload long[] copyOf(long[] p0, int p1);
	@Virtual @Overload int[] copyOf(int[] p0, int p1);
	@Virtual @Overload float[] copyOf(float[] p0, int p1);
	@Virtual @Overload double[] copyOf(double[] p0, int p1);
	@Virtual @Overload boolean[] copyOf(boolean[] p0, int p1);
	@Virtual @Overload Object[] copyOfRange(Object[] p0, int p1, int p2);
	@Virtual @Overload Object[] copyOfRange(Object[] p0, int p1, int p2, Class p3);
	@Virtual @Overload int[] copyOfRange(int[] p0, int p1, int p2);
	@Virtual @Overload int[] copyOfRange(int[] p0, int p1, int p2);
	@Virtual @Overload int[] copyOfRange(int[] p0, int p1, int p2);
	@Virtual @Overload long[] copyOfRange(long[] p0, int p1, int p2);
	@Virtual @Overload int[] copyOfRange(int[] p0, int p1, int p2);
	@Virtual @Overload float[] copyOfRange(float[] p0, int p1, int p2);
	@Virtual @Overload double[] copyOfRange(double[] p0, int p1, int p2);
	@Virtual @Overload boolean[] copyOfRange(boolean[] p0, int p1, int p2);
	@Virtual @Overload boolean deepEquals(Object[] p0, Object[] p1);
	@Virtual @Overload int deepHashCode(Object[] p0);
	@Virtual @Overload String deepToString(Object[] p0);
	@Virtual @Overload boolean equals(long[] p0, long[] p1);
	@Virtual @Overload boolean equals(int[] p0, int[] p1);
	@Virtual @Overload boolean equals(int[] p0, int[] p1);
	@Virtual @Overload boolean equals(int[] p0, int[] p1);
	@Virtual @Overload boolean equals(int[] p0, int[] p1);
	@Virtual @Overload boolean equals(boolean[] p0, boolean[] p1);
	@Virtual @Overload boolean equals(double[] p0, double[] p1);
	@Virtual @Overload boolean equals(float[] p0, float[] p1);
	@Virtual @Overload boolean equals(Object[] p0, Object[] p1);
	@Virtual @Overload void fill(long[] p0, long p1);
	@Virtual @Overload void fill(long[] p0, int p1, int p2, long p3);
	@Virtual @Overload void fill(int[] p0, int p1);
	@Virtual @Overload void fill(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload void fill(int[] p0, int p1);
	@Virtual @Overload void fill(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload void fill(int[] p0, int p1);
	@Virtual @Overload void fill(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload void fill(int[] p0, int p1);
	@Virtual @Overload void fill(int[] p0, int p1, int p2, int p3);
	@Virtual @Overload void fill(boolean[] p0, boolean p1);
	@Virtual @Overload void fill(boolean[] p0, int p1, int p2, boolean p3);
	@Virtual @Overload void fill(double[] p0, double p1);
	@Virtual @Overload void fill(double[] p0, int p1, int p2, double p3);
	@Virtual @Overload void fill(float[] p0, float p1);
	@Virtual @Overload void fill(float[] p0, int p1, int p2, float p3);
	@Virtual @Overload void fill(Object[] p0, Object p1);
	@Virtual @Overload void fill(Object[] p0, int p1, int p2, Object p3);
	//@Virtual @Overload int hashCode(long[] p0);
	//@Virtual @Overload int hashCode(int[] p0);
	//@Virtual @Overload int hashCode(int[] p0);
	//@Virtual @Overload int hashCode(int[] p0);
	//@Virtual @Overload int hashCode(int[] p0);
	//@Virtual @Overload int hashCode(boolean[] p0);
	//@Virtual @Overload int hashCode(float[] p0);
	//@Virtual @Overload int hashCode(double[] p0);
	//@Virtual @Overload int hashCode(Object[] p0);
	@Virtual @Overload void sort(int[] p0);
	@Virtual @Overload void sort(int[] p0, int p1, int p2);
	@Virtual @Overload void sort(long[] p0);
	@Virtual @Overload void sort(long[] p0, int p1, int p2);
	@Virtual @Overload void sort(int[] p0);
	@Virtual @Overload void sort(int[] p0, int p1, int p2);
	@Virtual @Overload void sort(int[] p0);
	@Virtual @Overload void sort(int[] p0, int p1, int p2);
	@Virtual @Overload void sort(int[] p0);
	@Virtual @Overload void sort(int[] p0, int p1, int p2);
	@Virtual @Overload void sort(float[] p0);
	@Virtual @Overload void sort(float[] p0, int p1, int p2);
	@Virtual @Overload void sort(double[] p0);
	@Virtual @Overload void sort(double[] p0, int p1, int p2);
	@Virtual @Overload void sort(Object[] p0);
	@Virtual @Overload void sort(Object[] p0, int p1, int p2);
	@Virtual @Overload void sort(Object[] p0, Java_util_Comparator p1);
	@Virtual @Overload void sort(Object[] p0, int p1, int p2, Java_util_Comparator p3);
	@Virtual @Overload String toString(long[] p0);
	@Virtual @Overload String toString(int[] p0);
	@Virtual @Overload String toString(int[] p0);
	@Virtual @Overload String toString(int[] p0);
	@Virtual @Overload String toString(int[] p0);
	@Virtual @Overload String toString(boolean[] p0);
	@Virtual @Overload String toString(float[] p0);
	@Virtual @Overload String toString(double[] p0);
	@Virtual @Overload String toString(Object[] p0);
}

/* class java.util.BitSet */
class Java_util_BitSet {
	// implements java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void and(Java_util_BitSet p0);
	@Virtual @Overload void andNot(Java_util_BitSet p0);
	@Virtual @Overload int cardinality();
	@Virtual @Overload void clear(int p0);
	@Virtual @Overload void clear(int p0, int p1);
	@Virtual @Overload void clear();
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload void flip(int p0);
	@Virtual @Overload void flip(int p0, int p1);
	@Virtual @Overload boolean get(int p0);
	@Virtual @Overload Java_util_BitSet get(int p0, int p1);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean intersects(Java_util_BitSet p0);
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload int length();
	@Virtual @Overload int nextClearBit(int p0);
	@Virtual @Overload int nextSetBit(int p0);
	@Virtual @Overload void or(Java_util_BitSet p0);
	@Virtual @Overload int previousClearBit(int p0);
	@Virtual @Overload int previousSetBit(int p0);
	@Virtual @Overload void set(int p0);
	@Virtual @Overload void set(int p0, boolean p1);
	@Virtual @Overload void set(int p0, int p1);
	@Virtual @Overload void set(int p0, int p1, boolean p2);
	@Virtual @Overload int size();
	@Virtual @Overload int[] toByteArray();
	@Virtual @Overload long[] toLongArray();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_util_BitSet valueOf(long[] p0);
	@Virtual @Overload Java_util_BitSet valueOf(Java_nio_LongBuffer p0);
	@Virtual @Overload Java_util_BitSet valueOf(int[] p0);
	@Virtual @Overload Java_util_BitSet valueOf(Java_nio_ByteBuffer p0);
	@Virtual @Overload void xor(Java_util_BitSet p0);
}
@Overload Java_util_BitSet Java_util_BitSet.new();
@Overload Java_util_BitSet Java_util_BitSet.new(int p0);

/* class java.util.Calendar */
class Java_util_Calendar {
	// implements java.io.Serializable, java.lang.Cloneable, java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload void add(int p0, int p1);
	@Virtual @Overload boolean after(Object p0);
	@Virtual @Overload boolean before(Object p0);
	@Virtual @Overload void clear();
	@Virtual @Overload void clear(int p0);
	@Virtual @Overload Object clone();
	@Virtual @Overload int compareTo(Java_util_Calendar p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int get(int p0);
	@Virtual @Overload int getActualMaximum(int p0);
	@Virtual @Overload int getActualMinimum(int p0);
	@Virtual @Overload Java_util_Locale[] getAvailableLocales();
	@Virtual @Overload String getDisplayName(int p0, int p1, Java_util_Locale p2);
	@Virtual @Overload Java_util_Map getDisplayNames(int p0, int p1, Java_util_Locale p2);
	@Virtual @Overload int getFirstDayOfWeek();
	@Virtual @Overload int getGreatestMinimum(int p0);
	@Virtual @Overload Java_util_Calendar getInstance();
	@Virtual @Overload Java_util_Calendar getInstance(Java_util_TimeZone p0);
	@Virtual @Overload Java_util_Calendar getInstance(Java_util_Locale p0);
	@Virtual @Overload Java_util_Calendar getInstance(Java_util_TimeZone p0, Java_util_Locale p1);
	@Virtual @Overload int getLeastMaximum(int p0);
	@Virtual @Overload int getMaximum(int p0);
	@Virtual @Overload int getMinimalDaysInFirstWeek();
	@Virtual @Overload int getMinimum(int p0);
	@Virtual @Overload Java_util_Date getTime();
	@Virtual @Overload long getTimeInMillis();
	@Virtual @Overload Java_util_TimeZone getTimeZone();
	@Virtual @Overload int getWeekYear();
	@Virtual @Overload int getWeeksInWeekYear();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isLenient();
	@Virtual @Overload boolean isSet(int p0);
	@Virtual @Overload boolean isWeekDateSupported();
	@Virtual @Overload void roll(int p0, boolean p1);
	@Virtual @Overload void roll(int p0, int p1);
	@Virtual @Overload void set(int p0, int p1);
	@Virtual @Overload void set(int p0, int p1, int p2);
	@Virtual @Overload void set(int p0, int p1, int p2, int p3, int p4);
	@Virtual @Overload void set(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void setFirstDayOfWeek(int p0);
	@Virtual @Overload void setLenient(boolean p0);
	@Virtual @Overload void setMinimalDaysInFirstWeek(int p0);
	@Virtual @Overload void setTime(Java_util_Date p0);
	@Virtual @Overload void setTimeInMillis(long p0);
	@Virtual @Overload void setTimeZone(Java_util_TimeZone p0);
	@Virtual @Overload void setWeekDate(int p0, int p1, int p2);
	@Virtual @Overload String toString();
}

/* interface java.util.Collection */
class Java_util_Collection {
	// implements java.lang.Iterable
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload boolean addAll(Java_util_Collection p0);
	@Virtual @Overload void clear();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsAll(Java_util_Collection p0);
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload boolean removeAll(Java_util_Collection p0);
	@Virtual @Overload boolean retainAll(Java_util_Collection p0);
	@Virtual @Overload int size();
	@Virtual @Overload Object[] toArray();
	@Virtual @Overload Object[] toArray(Object[] p0);
}

/* class java.util.Collections */
class Java_util_Collections {
	/*-- Method --*/
	@Virtual @Overload boolean addAll(Java_util_Collection p0, Object[] p1);
	@Virtual @Overload Java_util_Queue asLifoQueue(Java_util_Deque p0);
	@Virtual @Overload int binarySearch(Java_util_List p0, Object p1);
	@Virtual @Overload int binarySearch(Java_util_List p0, Object p1, Java_util_Comparator p2);
	@Virtual @Overload Java_util_Collection checkedCollection(Java_util_Collection p0, Class p1);
	@Virtual @Overload Java_util_List checkedList(Java_util_List p0, Class p1);
	@Virtual @Overload Java_util_Map checkedMap(Java_util_Map p0, Class p1, Class p2);
	@Virtual @Overload Java_util_Set checkedSet(Java_util_Set p0, Class p1);
	@Virtual @Overload Java_util_SortedMap checkedSortedMap(Java_util_SortedMap p0, Class p1, Class p2);
	@Virtual @Overload Java_util_SortedSet checkedSortedSet(Java_util_SortedSet p0, Class p1);
	@Virtual @Overload void copy(Java_util_List p0, Java_util_List p1);
	@Virtual @Overload boolean disjoint(Java_util_Collection p0, Java_util_Collection p1);
	@Virtual @Overload Java_util_Enumeration emptyEnumeration();
	@Virtual @Overload Java_util_Iterator emptyIterator();
	@Virtual @Overload Java_util_List emptyList();
	@Virtual @Overload Java_util_ListIterator emptyListIterator();
	@Virtual @Overload Java_util_Map emptyMap();
	@Virtual @Overload Java_util_Set emptySet();
	@Virtual @Overload Java_util_Enumeration enumeration(Java_util_Collection p0);
	@Virtual @Overload void fill(Java_util_List p0, Object p1);
	@Virtual @Overload int frequency(Java_util_Collection p0, Object p1);
	@Virtual @Overload int indexOfSubList(Java_util_List p0, Java_util_List p1);
	@Virtual @Overload int lastIndexOfSubList(Java_util_List p0, Java_util_List p1);
	@Virtual @Overload Java_util_ArrayList list(Java_util_Enumeration p0);
	@Virtual @Overload Object max(Java_util_Collection p0);
	@Virtual @Overload Object max(Java_util_Collection p0, Java_util_Comparator p1);
	@Virtual @Overload Object min(Java_util_Collection p0);
	@Virtual @Overload Object min(Java_util_Collection p0, Java_util_Comparator p1);
	@Virtual @Overload Java_util_List nCopies(int p0, Object p1);
	@Virtual @Overload Java_util_Set newSetFromMap(Java_util_Map p0);
	@Virtual @Overload boolean replaceAll(Java_util_List p0, Object p1, Object p2);
	@Virtual @Overload void reverse(Java_util_List p0);
	@Virtual @Overload Java_util_Comparator reverseOrder();
	@Virtual @Overload Java_util_Comparator reverseOrder(Java_util_Comparator p0);
	@Virtual @Overload void rotate(Java_util_List p0, int p1);
	@Virtual @Overload void shuffle(Java_util_List p0);
	@Virtual @Overload void shuffle(Java_util_List p0, Java_util_Random p1);
	@Virtual @Overload Java_util_Set singleton(Object p0);
	@Virtual @Overload Java_util_List singletonList(Object p0);
	@Virtual @Overload Java_util_Map singletonMap(Object p0, Object p1);
	@Virtual @Overload void sort(Java_util_List p0);
	@Virtual @Overload void sort(Java_util_List p0, Java_util_Comparator p1);
	@Virtual @Overload void swap(Java_util_List p0, int p1, int p2);
	@Virtual @Overload Java_util_Collection synchronizedCollection(Java_util_Collection p0);
	@Virtual @Overload Java_util_List synchronizedList(Java_util_List p0);
	@Virtual @Overload Java_util_Map synchronizedMap(Java_util_Map p0);
	@Virtual @Overload Java_util_Set synchronizedSet(Java_util_Set p0);
	@Virtual @Overload Java_util_SortedMap synchronizedSortedMap(Java_util_SortedMap p0);
	@Virtual @Overload Java_util_SortedSet synchronizedSortedSet(Java_util_SortedSet p0);
	@Virtual @Overload Java_util_Collection unmodifiableCollection(Java_util_Collection p0);
	@Virtual @Overload Java_util_List unmodifiableList(Java_util_List p0);
	@Virtual @Overload Java_util_Map unmodifiableMap(Java_util_Map p0);
	@Virtual @Overload Java_util_Set unmodifiableSet(Java_util_Set p0);
	@Virtual @Overload Java_util_SortedMap unmodifiableSortedMap(Java_util_SortedMap p0);
	@Virtual @Overload Java_util_SortedSet unmodifiableSortedSet(Java_util_SortedSet p0);
}

/* interface java.util.Comparator */
class Java_util_Comparator {
	/*-- Method --*/
	@Virtual @Overload int compare(Object p0, Object p1);
	@Virtual @Overload boolean equals(Object p0);
}

/* class java.util.ConcurrentModificationException */
class Java_util_ConcurrentModificationException extends Java_lang_RuntimeException {
}
@Overload Java_util_ConcurrentModificationException Java_util_ConcurrentModificationException.new();
@Overload Java_util_ConcurrentModificationException Java_util_ConcurrentModificationException.new(String p0);
@Overload Java_util_ConcurrentModificationException Java_util_ConcurrentModificationException.new(Java_lang_Throwable p0);
@Overload Java_util_ConcurrentModificationException Java_util_ConcurrentModificationException.new(String p0, Java_lang_Throwable p1);

/* class java.util.Currency */
class Java_util_Currency {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_util_Set getAvailableCurrencies();
	@Virtual @Overload String getCurrencyCode();
	@Virtual @Overload int getDefaultFractionDigits();
	@Virtual @Overload String getDisplayName();
	@Virtual @Overload String getDisplayName(Java_util_Locale p0);
	@Virtual @Overload Java_util_Currency getInstance(String p0);
	@Virtual @Overload Java_util_Currency getInstance(Java_util_Locale p0);
	@Virtual @Overload int getNumericCode();
	@Virtual @Overload String getSymbol();
	@Virtual @Overload String getSymbol(Java_util_Locale p0);
	@Virtual @Overload String toString();
}

/* class java.util.Date */
class Java_util_Date {
	// implements java.io.Serializable, java.lang.Cloneable, java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload boolean after(Java_util_Date p0);
	@Virtual @Overload boolean before(Java_util_Date p0);
	@Virtual @Overload Object clone();
	@Virtual @Overload int compareTo(Java_util_Date p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload long getTime();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void setTime(long p0);
	@Virtual @Overload String toString();
}
@Overload Java_util_Date Java_util_Date.new();
@Overload Java_util_Date Java_util_Date.new(long p0);
@Overload Java_util_Date Java_util_Date.new(int p0, int p1, int p2);
@Overload Java_util_Date Java_util_Date.new(int p0, int p1, int p2, int p3, int p4);
@Overload Java_util_Date Java_util_Date.new(int p0, int p1, int p2, int p3, int p4, int p5);
@Overload Java_util_Date Java_util_Date.new(String p0);

/* interface java.util.Deque */
class Java_util_Deque {
	// implements java.util.Queue
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Object element();
	@Virtual @Overload Object getFirst();
	@Virtual @Overload Object getLast();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload boolean offerFirst(Object p0);
	@Virtual @Overload boolean offerLast(Object p0);
	@Virtual @Overload Object peek();
	@Virtual @Overload Object peekFirst();
	@Virtual @Overload Object peekLast();
	@Virtual @Overload Object poll();
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Object pop();
	@Virtual @Overload void push(Object p0);
	@Virtual @Overload Object remove();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload Object removeFirst();
	@Virtual @Overload boolean removeFirstOccurrence(Object p0);
	@Virtual @Overload Object removeLast();
	@Virtual @Overload boolean removeLastOccurrence(Object p0);
	@Virtual @Overload int size();
}

/* class java.util.Dictionary */
class Java_util_Dictionary {
	/*-- Method --*/
	@Virtual @Overload Java_util_Enumeration elements();
	@Virtual @Overload Object get(Object p0);
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Enumeration keys();
	@Virtual @Overload Object put(Object p0, Object p1);
	@Virtual @Overload Object remove(Object p0);
	@Virtual @Overload int size();
}
Java_util_Dictionary Java_util_Dictionary.new();

/* class java.util.DuplicateFormatFlagsException */
class Java_util_DuplicateFormatFlagsException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getFlags();
}
Java_util_DuplicateFormatFlagsException Java_util_DuplicateFormatFlagsException.new(String p0);

/* class java.util.EmptyStackException */
class Java_util_EmptyStackException extends Java_lang_RuntimeException {
}
Java_util_EmptyStackException Java_util_EmptyStackException.new();

/* class java.util.EnumMap */
class Java_util_EnumMap extends Java_util_AbstractMap {
	// implements java.io.Serializable, java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Java_util_EnumMap clone();
	@Virtual @Overload Object clone();
	@Virtual @Overload Object put(Java_lang_Enum p0, Object p1);
}
@Overload Java_util_EnumMap Java_util_EnumMap.new(Class p0);
@Overload Java_util_EnumMap Java_util_EnumMap.new(Java_util_EnumMap p0);
@Overload Java_util_EnumMap Java_util_EnumMap.new(Java_util_Map p0);

/* class java.util.EnumSet */
class Java_util_EnumSet extends Java_util_AbstractSet {
	// implements java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_util_EnumSet allOf(Class p0);
	@Virtual @Overload Java_util_EnumSet clone();
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_EnumSet complementOf(Java_util_EnumSet p0);
	@Virtual @Overload Java_util_EnumSet copyOf(Java_util_EnumSet p0);
	@Virtual @Overload Java_util_EnumSet copyOf(Java_util_Collection p0);
	@Virtual @Overload Java_util_EnumSet noneOf(Class p0);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0, Java_lang_Enum p1);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0, Java_lang_Enum p1, Java_lang_Enum p2);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0, Java_lang_Enum p1, Java_lang_Enum p2, Java_lang_Enum p3);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0, Java_lang_Enum p1, Java_lang_Enum p2, Java_lang_Enum p3, Java_lang_Enum p4);
	@Virtual @Overload Java_util_EnumSet of(Java_lang_Enum p0, Java_lang_Enum[] p1);
	@Virtual @Overload Java_util_EnumSet range(Java_lang_Enum p0, Java_lang_Enum p1);
}

/* interface java.util.Enumeration */
class Java_util_Enumeration {
	/*-- Method --*/
	@Virtual @Overload boolean hasMoreElements();
	@Virtual @Overload Object nextElement();
}

/* interface java.util.EventListener */
class Java_util_EventListener {
}

/* class java.util.EventListenerProxy */
class Java_util_EventListenerProxy {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload Java_util_EventListener getListener();
}
Java_util_EventListenerProxy Java_util_EventListenerProxy.new(Java_util_EventListener p0);

/* class java.util.EventObject */
class Java_util_EventObject {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object getSource();
	@Virtual @Overload String toString();
}
Java_util_EventObject Java_util_EventObject.new(Object p0);

/* class java.util.FormatFlagsConversionMismatchException */
class Java_util_FormatFlagsConversionMismatchException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload int getConversion();
	@Virtual @Overload String getFlags();
}
Java_util_FormatFlagsConversionMismatchException Java_util_FormatFlagsConversionMismatchException.new(String p0, int p1);

/* interface java.util.Formattable */
class Java_util_Formattable {
	/*-- Method --*/
	@Virtual @Overload void formatTo(Java_util_Formatter p0, int p1, int p2, int p3);
}

/* class java.util.FormattableFlags */
class Java_util_FormattableFlags {
}

/* class java.util.Formatter */
class Java_util_Formatter {
	// implements java.io.Closeable, java.io.Flushable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload void flush();
	//@Virtual @Overload Java_util_Formatter format(String p0, Object[] p1);
	//@Virtual @Overload Java_util_Formatter format(Java_util_Locale p0, String p1, Object[] p2);
	@Virtual @Overload Java_io_IOException ioException();
	@Virtual @Overload Java_util_Locale locale();
	@Virtual @Overload Java_lang_Appendable out();
	@Virtual @Overload String toString();
}
@Overload Java_util_Formatter Java_util_Formatter.new();
@Overload Java_util_Formatter Java_util_Formatter.new(Java_lang_Appendable p0);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_util_Locale p0);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_lang_Appendable p0, Java_util_Locale p1);
@Overload Java_util_Formatter Java_util_Formatter.new(String p0);
@Overload Java_util_Formatter Java_util_Formatter.new(String p0, String p1);
@Overload Java_util_Formatter Java_util_Formatter.new(String p0, String p1, Java_util_Locale p2);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_File p0);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_File p0, String p1);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_File p0, String p1, Java_util_Locale p2);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_PrintStream p0);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_OutputStream p0);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_OutputStream p0, String p1);
@Overload Java_util_Formatter Java_util_Formatter.new(Java_io_OutputStream p0, String p1, Java_util_Locale p2);

/* class java.util.FormatterClosedException */
class Java_util_FormatterClosedException extends Java_lang_IllegalStateException {
}
Java_util_FormatterClosedException Java_util_FormatterClosedException.new();

/* class java.util.GregorianCalendar */
class Java_util_GregorianCalendar extends Java_util_Calendar {
	/*-- Method --*/
	@Virtual @Overload Java_util_Date getGregorianChange();
	@Virtual @Overload boolean isLeapYear(int p0);
	@Virtual @Overload void setGregorianChange(Java_util_Date p0);
}
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new();
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(Java_util_TimeZone p0);
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(Java_util_Locale p0);
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(Java_util_TimeZone p0, Java_util_Locale p1);
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(int p0, int p1, int p2);
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(int p0, int p1, int p2, int p3, int p4);
@Overload Java_util_GregorianCalendar Java_util_GregorianCalendar.new(int p0, int p1, int p2, int p3, int p4, int p5);

/* class java.util.HashMap */
class Java_util_HashMap extends Java_util_AbstractMap {
	// implements java.util.Map, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
}
@Overload Java_util_HashMap Java_util_HashMap.new(int p0, float p1);
@Overload Java_util_HashMap Java_util_HashMap.new(int p0);
@Overload Java_util_HashMap Java_util_HashMap.new();
@Overload Java_util_HashMap Java_util_HashMap.new(Java_util_Map p0);

/* class java.util.HashSet */
class Java_util_HashSet extends Java_util_AbstractSet {
	// implements java.util.Set, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
}
@Overload Java_util_HashSet Java_util_HashSet.new();
@Overload Java_util_HashSet Java_util_HashSet.new(Java_util_Collection p0);
@Overload Java_util_HashSet Java_util_HashSet.new(int p0, float p1);
@Overload Java_util_HashSet Java_util_HashSet.new(int p0);

/* class java.util.Hashtable */
class Java_util_Hashtable extends Java_util_Dictionary {
	// implements java.util.Map, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void clear();
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsKey(Object p0);
	@Virtual @Overload boolean containsValue(Object p0);
	@Virtual @Overload Java_util_Set entrySet();
	@Virtual @Overload Java_util_Set keySet();
	@Virtual @Overload void putAll(Java_util_Map p0);
	@Virtual @Overload Java_util_Collection values();
}
@Overload Java_util_Hashtable Java_util_Hashtable.new(int p0, float p1);
@Overload Java_util_Hashtable Java_util_Hashtable.new(int p0);
@Overload Java_util_Hashtable Java_util_Hashtable.new();
@Overload Java_util_Hashtable Java_util_Hashtable.new(Java_util_Map p0);

/* class java.util.IdentityHashMap */
class Java_util_IdentityHashMap extends Java_util_AbstractMap {
	// implements java.util.Map, java.io.Serializable, java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
}
@Overload Java_util_IdentityHashMap Java_util_IdentityHashMap.new();
@Overload Java_util_IdentityHashMap Java_util_IdentityHashMap.new(int p0);
@Overload Java_util_IdentityHashMap Java_util_IdentityHashMap.new(Java_util_Map p0);

/* class java.util.IllegalFormatCodePointException */
class Java_util_IllegalFormatCodePointException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload int getCodePoint();
}
Java_util_IllegalFormatCodePointException Java_util_IllegalFormatCodePointException.new(int p0);

/* class java.util.IllegalFormatConversionException */
class Java_util_IllegalFormatConversionException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload Class getArgumentClass();
	@Virtual @Overload int getConversion();
}
Java_util_IllegalFormatConversionException Java_util_IllegalFormatConversionException.new(int p0, Class p1);

/* class java.util.IllegalFormatException */
class Java_util_IllegalFormatException extends Java_lang_IllegalArgumentException {
}

/* class java.util.IllegalFormatFlagsException */
class Java_util_IllegalFormatFlagsException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getFlags();
}
Java_util_IllegalFormatFlagsException Java_util_IllegalFormatFlagsException.new(String p0);

/* class java.util.IllegalFormatPrecisionException */
class Java_util_IllegalFormatPrecisionException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload int getPrecision();
}
Java_util_IllegalFormatPrecisionException Java_util_IllegalFormatPrecisionException.new(int p0);

/* class java.util.IllegalFormatWidthException */
class Java_util_IllegalFormatWidthException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload int getWidth();
}
Java_util_IllegalFormatWidthException Java_util_IllegalFormatWidthException.new(int p0);

/* class java.util.IllformedLocaleException */
class Java_util_IllformedLocaleException extends Java_lang_RuntimeException {
	/*-- Method --*/
	@Virtual @Overload int getErrorIndex();
}
@Overload Java_util_IllformedLocaleException Java_util_IllformedLocaleException.new();
@Overload Java_util_IllformedLocaleException Java_util_IllformedLocaleException.new(String p0);
@Overload Java_util_IllformedLocaleException Java_util_IllformedLocaleException.new(String p0, int p1);

/* class java.util.InputMismatchException */
class Java_util_InputMismatchException extends Java_util_NoSuchElementException {
}
@Overload Java_util_InputMismatchException Java_util_InputMismatchException.new();
@Overload Java_util_InputMismatchException Java_util_InputMismatchException.new(String p0);

/* class java.util.InvalidPropertiesFormatException */
class Java_util_InvalidPropertiesFormatException extends Java_io_IOException {
}
@Overload Java_util_InvalidPropertiesFormatException Java_util_InvalidPropertiesFormatException.new(Java_lang_Throwable p0);
@Overload Java_util_InvalidPropertiesFormatException Java_util_InvalidPropertiesFormatException.new(String p0);

/* interface java.util.Iterator */
class Java_util_Iterator {
	/*-- Method --*/
	@Virtual @Overload boolean hasNext();
	@Virtual @Overload Object next();
	@Virtual @Overload void remove();
}

/* class java.util.LinkedHashMap */
class Java_util_LinkedHashMap extends Java_util_HashMap {
	// implements java.util.Map
}
@Overload Java_util_LinkedHashMap Java_util_LinkedHashMap.new(int p0, float p1);
@Overload Java_util_LinkedHashMap Java_util_LinkedHashMap.new(int p0);
@Overload Java_util_LinkedHashMap Java_util_LinkedHashMap.new();
@Overload Java_util_LinkedHashMap Java_util_LinkedHashMap.new(Java_util_Map p0);
@Overload Java_util_LinkedHashMap Java_util_LinkedHashMap.new(int p0, float p1, boolean p2);

/* class java.util.LinkedHashSet */
class Java_util_LinkedHashSet extends Java_util_HashSet {
	// implements java.util.Set, java.lang.Cloneable, java.io.Serializable
}
@Overload Java_util_LinkedHashSet Java_util_LinkedHashSet.new(int p0, float p1);
@Overload Java_util_LinkedHashSet Java_util_LinkedHashSet.new(int p0);
@Overload Java_util_LinkedHashSet Java_util_LinkedHashSet.new();
@Overload Java_util_LinkedHashSet Java_util_LinkedHashSet.new(Java_util_Collection p0);

/* class java.util.LinkedList */
class Java_util_LinkedList extends Java_util_AbstractSequentialList {
	// implements java.util.List, java.util.Deque, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Object element();
	@Virtual @Overload Object getFirst();
	@Virtual @Overload Object getLast();
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload boolean offerFirst(Object p0);
	@Virtual @Overload boolean offerLast(Object p0);
	@Virtual @Overload Object peek();
	@Virtual @Overload Object peekFirst();
	@Virtual @Overload Object peekLast();
	@Virtual @Overload Object poll();
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Object pop();
	@Virtual @Overload void push(Object p0);
	@Virtual @Overload Object remove();
	@Virtual @Overload Object removeFirst();
	@Virtual @Overload boolean removeFirstOccurrence(Object p0);
	@Virtual @Overload Object removeLast();
	@Virtual @Overload boolean removeLastOccurrence(Object p0);
}
@Overload Java_util_LinkedList Java_util_LinkedList.new();
@Overload Java_util_LinkedList Java_util_LinkedList.new(Java_util_Collection p0);

/* interface java.util.List */
class Java_util_List {
	// implements java.util.Collection
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload void add(int p0, Object p1);
	@Virtual @Overload boolean addAll(Java_util_Collection p0);
	@Virtual @Overload boolean addAll(int p0, Java_util_Collection p1);
	@Virtual @Overload void clear();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsAll(Java_util_Collection p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Object get(int p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload int indexOf(Object p0);
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload int lastIndexOf(Object p0);
	@Virtual @Overload Java_util_ListIterator listIterator();
	@Virtual @Overload Java_util_ListIterator listIterator(int p0);
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload Object remove(int p0);
	@Virtual @Overload boolean removeAll(Java_util_Collection p0);
	@Virtual @Overload boolean retainAll(Java_util_Collection p0);
	@Virtual @Overload Object set(int p0, Object p1);
	@Virtual @Overload int size();
	@Virtual @Overload Java_util_List subList(int p0, int p1);
	@Virtual @Overload Object[] toArray();
	@Virtual @Overload Object[] toArray(Object[] p0);
}

/* interface java.util.ListIterator */
class Java_util_ListIterator {
	// implements java.util.Iterator
	/*-- Method --*/
	@Virtual @Overload void add(Object p0);
	@Virtual @Overload boolean hasNext();
	@Virtual @Overload boolean hasPrevious();
	@Virtual @Overload Object next();
	@Virtual @Overload int nextIndex();
	@Virtual @Overload Object previous();
	@Virtual @Overload int previousIndex();
	@Virtual @Overload void remove();
	@Virtual @Overload void set(Object p0);
}

/* class java.util.ListResourceBundle */
class Java_util_ListResourceBundle extends Java_util_ResourceBundle {
	/*-- Method --*/
	@Virtual @Overload Object handleGetObject(String p0);
}
Java_util_ListResourceBundle Java_util_ListResourceBundle.new();

/* class java.util.Locale */
class Java_util_Locale {
	// implements java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_util_Locale forLanguageTag(String p0);
	@Virtual @Overload Java_util_Locale[] getAvailableLocales();
	@Virtual @Overload String getCountry();
	@Virtual @Overload Java_util_Locale getDefault();
	@Virtual @Overload Java_util_Locale getDefault(Java_util_Locale_Category p0);
	@Virtual @Overload String getDisplayCountry();
	@Virtual @Overload String getDisplayCountry(Java_util_Locale p0);
	@Virtual @Overload String getDisplayLanguage();
	@Virtual @Overload String getDisplayLanguage(Java_util_Locale p0);
	@Virtual @Overload String getDisplayName();
	@Virtual @Overload String getDisplayName(Java_util_Locale p0);
	@Virtual @Overload String getDisplayScript();
	@Virtual @Overload String getDisplayScript(Java_util_Locale p0);
	@Virtual @Overload String getDisplayVariant();
	@Virtual @Overload String getDisplayVariant(Java_util_Locale p0);
	@Virtual @Overload String getExtension(int p0);
	@Virtual @Overload Java_util_Set getExtensionKeys();
	@Virtual @Overload String getISO3Country();
	@Virtual @Overload String getISO3Language();
	@Virtual @Overload String[] getISOCountries();
	@Virtual @Overload String[] getISOLanguages();
	@Virtual @Overload String getLanguage();
	@Virtual @Overload String getScript();
	@Virtual @Overload Java_util_Set getUnicodeLocaleAttributes();
	@Virtual @Overload Java_util_Set getUnicodeLocaleKeys();
	@Virtual @Overload String getUnicodeLocaleType(String p0);
	@Virtual @Overload String getVariant();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void setDefault(Java_util_Locale p0);
	@Virtual @Overload void setDefault(Java_util_Locale_Category p0, Java_util_Locale p1);
	@Virtual @Overload String toLanguageTag();
	@Virtual @Overload String toString();
}
@Overload Java_util_Locale Java_util_Locale.new(String p0, String p1, String p2);
@Overload Java_util_Locale Java_util_Locale.new(String p0, String p1);
@Overload Java_util_Locale Java_util_Locale.new(String p0);

/* interface java.util.Map */
class Java_util_Map {
	/*-- Method --*/
	@Virtual @Overload void clear();
	@Virtual @Overload boolean containsKey(Object p0);
	@Virtual @Overload boolean containsValue(Object p0);
	@Virtual @Overload Java_util_Set entrySet();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Object get(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Set keySet();
	@Virtual @Overload Object put(Object p0, Object p1);
	@Virtual @Overload void putAll(Java_util_Map p0);
	@Virtual @Overload Object remove(Object p0);
	@Virtual @Overload int size();
	@Virtual @Overload Java_util_Collection values();
}

/* class java.util.MissingFormatArgumentException */
class Java_util_MissingFormatArgumentException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getFormatSpecifier();
}
Java_util_MissingFormatArgumentException Java_util_MissingFormatArgumentException.new(String p0);

/* class java.util.MissingFormatWidthException */
class Java_util_MissingFormatWidthException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getFormatSpecifier();
}
Java_util_MissingFormatWidthException Java_util_MissingFormatWidthException.new(String p0);

/* class java.util.MissingResourceException */
class Java_util_MissingResourceException extends Java_lang_RuntimeException {
	/*-- Method --*/
	@Virtual @Overload String getClassName();
	@Virtual @Overload String getKey();
}
Java_util_MissingResourceException Java_util_MissingResourceException.new(String p0, String p1, String p2);

/* interface java.util.NavigableMap */
class Java_util_NavigableMap {
	// implements java.util.SortedMap
	/*-- Method --*/
	@Virtual @Overload Java_util_Map_Entry ceilingEntry(Object p0);
	@Virtual @Overload Object ceilingKey(Object p0);
	@Virtual @Overload Java_util_NavigableSet descendingKeySet();
	@Virtual @Overload Java_util_NavigableMap descendingMap();
	@Virtual @Overload Java_util_Map_Entry firstEntry();
	@Virtual @Overload Java_util_Map_Entry floorEntry(Object p0);
	@Virtual @Overload Object floorKey(Object p0);
	@Virtual @Overload Java_util_NavigableMap headMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedMap headMap(Object p0);
	@Virtual @Overload Java_util_Map_Entry higherEntry(Object p0);
	@Virtual @Overload Object higherKey(Object p0);
	@Virtual @Overload Java_util_Map_Entry lastEntry();
	@Virtual @Overload Java_util_Map_Entry lowerEntry(Object p0);
	@Virtual @Overload Object lowerKey(Object p0);
	@Virtual @Overload Java_util_NavigableSet navigableKeySet();
	@Virtual @Overload Java_util_Map_Entry pollFirstEntry();
	@Virtual @Overload Java_util_Map_Entry pollLastEntry();
	@Virtual @Overload Java_util_NavigableMap subMap(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_SortedMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableMap tailMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedMap tailMap(Object p0);
}

/* interface java.util.NavigableSet */
class Java_util_NavigableSet {
	// implements java.util.SortedSet
	/*-- Method --*/
	@Virtual @Overload Object ceiling(Object p0);
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Java_util_NavigableSet descendingSet();
	@Virtual @Overload Object floor(Object p0);
	@Virtual @Overload Java_util_NavigableSet headSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedSet headSet(Object p0);
	@Virtual @Overload Object higher(Object p0);
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload Object lower(Object p0);
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Java_util_NavigableSet subSet(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_SortedSet subSet(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableSet tailSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedSet tailSet(Object p0);
}

/* class java.util.NoSuchElementException */
class Java_util_NoSuchElementException extends Java_lang_RuntimeException {
}
@Overload Java_util_NoSuchElementException Java_util_NoSuchElementException.new();
@Overload Java_util_NoSuchElementException Java_util_NoSuchElementException.new(String p0);

/* class java.util.Objects */
class Java_util_Objects {
	/*-- Method --*/
	@Virtual @Overload int compare(Object p0, Object p1, Java_util_Comparator p2);
	@Virtual @Overload boolean deepEquals(Object p0, Object p1);
	@Virtual @Overload boolean equals(Object p0, Object p1);
	@Virtual @Overload int hash(Object[] p0);
	//@Virtual @Overload int hashCode(Object p0);
	@Virtual @Overload Object requireNonNull(Object p0);
	@Virtual @Overload Object requireNonNull(Object p0, String p1);
	@Virtual @Overload String toString(Object p0);
	@Virtual @Overload String toString(Object p0, String p1);
}

/* class java.util.Observable */
class Java_util_Observable {
	/*-- Method --*/
	@Virtual @Overload void addObserver(Java_util_Observer p0);
	@Virtual @Overload int countObservers();
	@Virtual @Overload void deleteObserver(Java_util_Observer p0);
	@Virtual @Overload void deleteObservers();
	@Virtual @Overload boolean hasChanged();
	@Virtual @Overload void notifyObservers();
	@Virtual @Overload void notifyObservers(Object p0);
}
Java_util_Observable Java_util_Observable.new();

/* interface java.util.Observer */
class Java_util_Observer {
	/*-- Method --*/
	@Virtual @Overload void update(Java_util_Observable p0, Object p1);
}

/* class java.util.PriorityQueue */
class Java_util_PriorityQueue extends Java_util_AbstractQueue {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_util_Comparator comparator();
}
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new();
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new(int p0);
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new(int p0, Java_util_Comparator p1);
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new(Java_util_Collection p0);
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new(Java_util_PriorityQueue p0);
@Overload Java_util_PriorityQueue Java_util_PriorityQueue.new(Java_util_SortedSet p0);

/* class java.util.Properties */
class Java_util_Properties extends Java_util_Hashtable {
	/*-- Method --*/
	@Virtual @Overload String getProperty(String p0);
	@Virtual @Overload String getProperty(String p0, String p1);
	@Virtual @Overload void list(Java_io_PrintStream p0);
	@Virtual @Overload void list(Java_io_PrintWriter p0);
	@Virtual @Overload void load(Java_io_Reader p0);
	@Virtual @Overload void load(Java_io_InputStream p0);
	@Virtual @Overload void loadFromXML(Java_io_InputStream p0);
	@Virtual @Overload Java_util_Enumeration propertyNames();
	@Virtual @Overload Object setProperty(String p0, String p1);
	@Virtual @Overload void store(Java_io_Writer p0, String p1);
	@Virtual @Overload void store(Java_io_OutputStream p0, String p1);
	@Virtual @Overload void storeToXML(Java_io_OutputStream p0, String p1);
	@Virtual @Overload void storeToXML(Java_io_OutputStream p0, String p1, String p2);
	@Virtual @Overload Java_util_Set stringPropertyNames();
}
@Overload Java_util_Properties Java_util_Properties.new();
@Overload Java_util_Properties Java_util_Properties.new(Java_util_Properties p0);

/* class java.util.PropertyPermission */
class Java_util_PropertyPermission extends Java_security_BasicPermission {
}
Java_util_PropertyPermission Java_util_PropertyPermission.new(String p0, String p1);

/* class java.util.PropertyResourceBundle */
class Java_util_PropertyResourceBundle extends Java_util_ResourceBundle {
	/*-- Method --*/
	@Virtual @Overload Object handleGetObject(String p0);
}
@Overload Java_util_PropertyResourceBundle Java_util_PropertyResourceBundle.new(Java_io_InputStream p0);
@Overload Java_util_PropertyResourceBundle Java_util_PropertyResourceBundle.new(Java_io_Reader p0);

/* interface java.util.Queue */
class Java_util_Queue {
	// implements java.util.Collection
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload Object element();
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload Object peek();
	@Virtual @Overload Object poll();
	@Virtual @Overload Object remove();
}

/* class java.util.Random */
class Java_util_Random {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean nextBoolean();
	@Virtual @Overload void nextBytes(int[] p0);
	@Virtual @Overload double nextDouble();
	@Virtual @Overload float nextFloat();
	@Virtual @Overload double nextGaussian();
	@Virtual @Overload int nextInt();
	@Virtual @Overload int nextInt(int p0);
	@Virtual @Overload long nextLong();
	@Virtual @Overload void setSeed(long p0);
}
@Overload Java_util_Random Java_util_Random.new();
@Overload Java_util_Random Java_util_Random.new(long p0);

/* interface java.util.RandomAccess */
class Java_util_RandomAccess {
}

/* class java.util.ResourceBundle */
class Java_util_ResourceBundle {
	/*-- Method --*/
	@Virtual @Overload void clearCache();
	@Virtual @Overload void clearCache(Java_lang_ClassLoader p0);
	@Virtual @Overload boolean containsKey(String p0);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0, Java_util_ResourceBundle_Control p1);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0, Java_util_Locale p1);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0, Java_util_Locale p1, Java_util_ResourceBundle_Control p2);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0, Java_util_Locale p1, Java_lang_ClassLoader p2);
	@Virtual @Overload Java_util_ResourceBundle getBundle(String p0, Java_util_Locale p1, Java_lang_ClassLoader p2, Java_util_ResourceBundle_Control p3);
	@Virtual @Overload Java_util_Enumeration getKeys();
	@Virtual @Overload Java_util_Locale getLocale();
	@Virtual @Overload Object getObject(String p0);
	@Virtual @Overload String getString(String p0);
	@Virtual @Overload String[] getStringArray(String p0);
	@Virtual @Overload Java_util_Set keySet();
}
Java_util_ResourceBundle Java_util_ResourceBundle.new();

/* class java.util.Scanner */
class Java_util_Scanner {
	// implements java.util.Iterator, java.io.Closeable
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload Java_util_regex_Pattern delimiter();
	@Virtual @Overload String findInLine(String p0);
	@Virtual @Overload String findInLine(Java_util_regex_Pattern p0);
	@Virtual @Overload String findWithinHorizon(String p0, int p1);
	@Virtual @Overload String findWithinHorizon(Java_util_regex_Pattern p0, int p1);
	@Virtual @Overload boolean hasNext();
	@Virtual @Overload boolean hasNext(String p0);
	@Virtual @Overload boolean hasNext(Java_util_regex_Pattern p0);
	@Virtual @Overload boolean hasNextBigDecimal();
	@Virtual @Overload boolean hasNextBigInteger();
	@Virtual @Overload boolean hasNextBigInteger(int p0);
	@Virtual @Overload boolean hasNextBoolean();
	@Virtual @Overload boolean hasNextByte();
	@Virtual @Overload boolean hasNextByte(int p0);
	@Virtual @Overload boolean hasNextDouble();
	@Virtual @Overload boolean hasNextFloat();
	@Virtual @Overload boolean hasNextInt();
	@Virtual @Overload boolean hasNextInt(int p0);
	@Virtual @Overload boolean hasNextLine();
	@Virtual @Overload boolean hasNextLong();
	@Virtual @Overload boolean hasNextLong(int p0);
	@Virtual @Overload boolean hasNextShort();
	@Virtual @Overload boolean hasNextShort(int p0);
	@Virtual @Overload Java_io_IOException ioException();
	@Virtual @Overload Java_util_Locale locale();
	@Virtual @Overload Java_util_regex_MatchResult match();
	@Virtual @Overload String next();
	@Virtual @Overload String next(String p0);
	@Virtual @Overload String next(Java_util_regex_Pattern p0);
	@Virtual @Overload Object next();
	@Virtual @Overload Java_math_BigDecimal nextBigDecimal();
	@Virtual @Overload Java_math_BigInteger nextBigInteger();
	@Virtual @Overload Java_math_BigInteger nextBigInteger(int p0);
	@Virtual @Overload boolean nextBoolean();
	@Virtual @Overload int nextByte();
	@Virtual @Overload int nextByte(int p0);
	@Virtual @Overload double nextDouble();
	@Virtual @Overload float nextFloat();
	@Virtual @Overload int nextInt();
	@Virtual @Overload int nextInt(int p0);
	@Virtual @Overload String nextLine();
	@Virtual @Overload long nextLong();
	@Virtual @Overload long nextLong(int p0);
	@Virtual @Overload int nextShort();
	@Virtual @Overload int nextShort(int p0);
	@Virtual @Overload int radix();
	@Virtual @Overload void remove();
	@Virtual @Overload Java_util_Scanner reset();
	@Virtual @Overload Java_util_Scanner skip(Java_util_regex_Pattern p0);
	@Virtual @Overload Java_util_Scanner skip(String p0);
	@Virtual @Overload String toString();
	@Virtual @Overload Java_util_Scanner useDelimiter(Java_util_regex_Pattern p0);
	@Virtual @Overload Java_util_Scanner useDelimiter(String p0);
	@Virtual @Overload Java_util_Scanner useLocale(Java_util_Locale p0);
	@Virtual @Overload Java_util_Scanner useRadix(int p0);
}
@Overload Java_util_Scanner Java_util_Scanner.new(Java_lang_Readable p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_io_InputStream p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_io_InputStream p0, String p1);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_io_File p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_io_File p0, String p1);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_nio_file_Path p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_nio_file_Path p0, String p1);
@Overload Java_util_Scanner Java_util_Scanner.new(String p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_nio_channels_ReadableByteChannel p0);
@Overload Java_util_Scanner Java_util_Scanner.new(Java_nio_channels_ReadableByteChannel p0, String p1);

/* class java.util.ServiceConfigurationError */
class Java_util_ServiceConfigurationError extends Java_lang_Error {
}
@Overload Java_util_ServiceConfigurationError Java_util_ServiceConfigurationError.new(String p0);
@Overload Java_util_ServiceConfigurationError Java_util_ServiceConfigurationError.new(String p0, Java_lang_Throwable p1);

/* class java.util.ServiceLoader */
class Java_util_ServiceLoader {
	// implements java.lang.Iterable
	/*-- Method --*/
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload Java_util_ServiceLoader load(Class p0, Java_lang_ClassLoader p1);
	@Virtual @Overload Java_util_ServiceLoader load(Class p0);
	@Virtual @Overload Java_util_ServiceLoader loadInstalled(Class p0);
	@Virtual @Overload void reload();
	@Virtual @Overload String toString();
}

/* interface java.util.Set */
class Java_util_Set {
	// implements java.util.Collection
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload boolean addAll(Java_util_Collection p0);
	@Virtual @Overload void clear();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsAll(Java_util_Collection p0);
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload boolean removeAll(Java_util_Collection p0);
	@Virtual @Overload boolean retainAll(Java_util_Collection p0);
	@Virtual @Overload int size();
	@Virtual @Overload Object[] toArray();
	@Virtual @Overload Object[] toArray(Object[] p0);
}

/* class java.util.SimpleTimeZone */
class Java_util_SimpleTimeZone extends Java_util_TimeZone {
	/*-- Method --*/
	@Virtual @Overload void setDSTSavings(int p0);
	@Virtual @Overload void setEndRule(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setEndRule(int p0, int p1, int p2);
	@Virtual @Overload void setEndRule(int p0, int p1, int p2, int p3, boolean p4);
	@Virtual @Overload void setStartRule(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setStartRule(int p0, int p1, int p2);
	@Virtual @Overload void setStartRule(int p0, int p1, int p2, int p3, boolean p4);
	@Virtual @Overload void setStartYear(int p0);
}
@Overload Java_util_SimpleTimeZone Java_util_SimpleTimeZone.new(int p0, String p1);
@Overload Java_util_SimpleTimeZone Java_util_SimpleTimeZone.new(int p0, String p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
@Overload Java_util_SimpleTimeZone Java_util_SimpleTimeZone.new(int p0, String p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);
@Overload Java_util_SimpleTimeZone Java_util_SimpleTimeZone.new(int p0, String p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12);

/* interface java.util.SortedMap */
class Java_util_SortedMap {
	// implements java.util.Map
	/*-- Method --*/
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Java_util_Set entrySet();
	@Virtual @Overload Object firstKey();
	@Virtual @Overload Java_util_SortedMap headMap(Object p0);
	@Virtual @Overload Java_util_Set keySet();
	@Virtual @Overload Object lastKey();
	@Virtual @Overload Java_util_SortedMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_SortedMap tailMap(Object p0);
	@Virtual @Overload Java_util_Collection values();
}

/* interface java.util.SortedSet */
class Java_util_SortedSet {
	// implements java.util.Set
	/*-- Method --*/
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Object first();
	@Virtual @Overload Java_util_SortedSet headSet(Object p0);
	@Virtual @Overload Object last();
	@Virtual @Overload Java_util_SortedSet subSet(Object p0, Object p1);
	@Virtual @Overload Java_util_SortedSet tailSet(Object p0);
}

/* class java.util.Stack */
class Java_util_Stack extends Java_util_Vector {
	/*-- Method --*/
	@Virtual @Overload boolean empty();
	@Virtual @Overload Object peek();
	@Virtual @Overload Object pop();
	@Virtual @Overload Object push(Object p0);
	@Virtual @Overload int search(Object p0);
}
Java_util_Stack Java_util_Stack.new();

/* class java.util.StringTokenizer */
class Java_util_StringTokenizer {
	// implements java.util.Enumeration
	/*-- Method --*/
	@Virtual @Overload int countTokens();
	@Virtual @Overload boolean hasMoreElements();
	@Virtual @Overload boolean hasMoreTokens();
	@Virtual @Overload Object nextElement();
	@Virtual @Overload String nextToken();
	@Virtual @Overload String nextToken(String p0);
}
@Overload Java_util_StringTokenizer Java_util_StringTokenizer.new(String p0, String p1, boolean p2);
@Overload Java_util_StringTokenizer Java_util_StringTokenizer.new(String p0, String p1);
@Overload Java_util_StringTokenizer Java_util_StringTokenizer.new(String p0);

/* class java.util.TimeZone */
class Java_util_TimeZone {
	// implements java.io.Serializable, java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload String[] getAvailableIDs(int p0);
	@Virtual @Overload String[] getAvailableIDs();
	@Virtual @Overload int getDSTSavings();
	@Virtual @Overload Java_util_TimeZone getDefault();
	@Virtual @Overload String getDisplayName();
	@Virtual @Overload String getDisplayName(Java_util_Locale p0);
	@Virtual @Overload String getDisplayName(boolean p0, int p1);
	@Virtual @Overload String getDisplayName(boolean p0, int p1, Java_util_Locale p2);
	@Virtual @Overload String getID();
	@Virtual @Overload int getOffset(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload int getOffset(long p0);
	@Virtual @Overload int getRawOffset();
	@Virtual @Overload Java_util_TimeZone getTimeZone(String p0);
	@Virtual @Overload boolean hasSameRules(Java_util_TimeZone p0);
	@Virtual @Overload boolean inDaylightTime(Java_util_Date p0);
	@Virtual @Overload boolean observesDaylightTime();
	@Virtual @Overload void setDefault(Java_util_TimeZone p0);
	@Virtual @Overload void setID(String p0);
	@Virtual @Overload void setRawOffset(int p0);
	@Virtual @Overload boolean useDaylightTime();
}
Java_util_TimeZone Java_util_TimeZone.new();

/* class java.util.Timer */
class Java_util_Timer {
	/*-- Method --*/
	@Virtual @Overload void cancel();
	@Virtual @Overload int purge();
	@Virtual @Overload void schedule(Java_util_TimerTask p0, long p1);
	@Virtual @Overload void schedule(Java_util_TimerTask p0, Java_util_Date p1);
	@Virtual @Overload void schedule(Java_util_TimerTask p0, long p1, long p2);
	@Virtual @Overload void schedule(Java_util_TimerTask p0, Java_util_Date p1, long p2);
	@Virtual @Overload void scheduleAtFixedRate(Java_util_TimerTask p0, long p1, long p2);
	@Virtual @Overload void scheduleAtFixedRate(Java_util_TimerTask p0, Java_util_Date p1, long p2);
}
@Overload Java_util_Timer Java_util_Timer.new();
@Overload Java_util_Timer Java_util_Timer.new(boolean p0);
@Overload Java_util_Timer Java_util_Timer.new(String p0);
@Overload Java_util_Timer Java_util_Timer.new(String p0, boolean p1);

/* class java.util.TimerTask */
class Java_util_TimerTask {
	// implements java.lang.Runnable
	/*-- Method --*/
	@Virtual @Overload boolean cancel();
	@Virtual @Overload void run();
	@Virtual @Overload long scheduledExecutionTime();
}

/* class java.util.TooManyListenersException */
class Java_util_TooManyListenersException extends Java_lang_Exception {
}
@Overload Java_util_TooManyListenersException Java_util_TooManyListenersException.new();
@Overload Java_util_TooManyListenersException Java_util_TooManyListenersException.new(String p0);

/* class java.util.TreeMap */
class Java_util_TreeMap extends Java_util_AbstractMap {
	// implements java.util.NavigableMap, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_util_Map_Entry ceilingEntry(Object p0);
	@Virtual @Overload Object ceilingKey(Object p0);
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Java_util_NavigableSet descendingKeySet();
	@Virtual @Overload Java_util_NavigableMap descendingMap();
	@Virtual @Overload Java_util_Map_Entry firstEntry();
	@Virtual @Overload Object firstKey();
	@Virtual @Overload Java_util_Map_Entry floorEntry(Object p0);
	@Virtual @Overload Object floorKey(Object p0);
	@Virtual @Overload Java_util_NavigableMap headMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedMap headMap(Object p0);
	@Virtual @Overload Java_util_Map_Entry higherEntry(Object p0);
	@Virtual @Overload Object higherKey(Object p0);
	@Virtual @Overload Java_util_Map_Entry lastEntry();
	@Virtual @Overload Object lastKey();
	@Virtual @Overload Java_util_Map_Entry lowerEntry(Object p0);
	@Virtual @Overload Object lowerKey(Object p0);
	@Virtual @Overload Java_util_NavigableSet navigableKeySet();
	@Virtual @Overload Java_util_Map_Entry pollFirstEntry();
	@Virtual @Overload Java_util_Map_Entry pollLastEntry();
	@Virtual @Overload Java_util_NavigableMap subMap(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_SortedMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableMap tailMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedMap tailMap(Object p0);
}
@Overload Java_util_TreeMap Java_util_TreeMap.new();
@Overload Java_util_TreeMap Java_util_TreeMap.new(Java_util_Comparator p0);
@Overload Java_util_TreeMap Java_util_TreeMap.new(Java_util_Map p0);
@Overload Java_util_TreeMap Java_util_TreeMap.new(Java_util_SortedMap p0);

/* class java.util.TreeSet */
class Java_util_TreeSet extends Java_util_AbstractSet {
	// implements java.util.NavigableSet, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object ceiling(Object p0);
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Java_util_NavigableSet descendingSet();
	@Virtual @Overload Object first();
	@Virtual @Overload Object floor(Object p0);
	@Virtual @Overload Java_util_NavigableSet headSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedSet headSet(Object p0);
	@Virtual @Overload Object higher(Object p0);
	@Virtual @Overload Object last();
	@Virtual @Overload Object lower(Object p0);
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Java_util_NavigableSet subSet(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_SortedSet subSet(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableSet tailSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_SortedSet tailSet(Object p0);
}
@Overload Java_util_TreeSet Java_util_TreeSet.new();
@Overload Java_util_TreeSet Java_util_TreeSet.new(Java_util_Comparator p0);
@Overload Java_util_TreeSet Java_util_TreeSet.new(Java_util_Collection p0);
@Overload Java_util_TreeSet Java_util_TreeSet.new(Java_util_SortedSet p0);

/* class java.util.UUID */
class Java_util_UUID {
	// implements java.io.Serializable, java.lang.Comparable
	/*-- Method --*/
	@Virtual @Overload int clockSequence();
	@Virtual @Overload int compareTo(Java_util_UUID p0);
	@Virtual @Overload int compareTo(Object p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_util_UUID fromString(String p0);
	@Virtual @Overload long getLeastSignificantBits();
	@Virtual @Overload long getMostSignificantBits();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload Java_util_UUID nameUUIDFromBytes(int[] p0);
	@Virtual @Overload long node();
	@Virtual @Overload Java_util_UUID randomUUID();
	@Virtual @Overload long timestamp();
	@Virtual @Overload String toString();
	@Virtual @Overload int variant();
	@Virtual @Overload int version();
}
Java_util_UUID Java_util_UUID.new(long p0, long p1);

/* class java.util.UnknownFormatConversionException */
class Java_util_UnknownFormatConversionException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getConversion();
}
Java_util_UnknownFormatConversionException Java_util_UnknownFormatConversionException.new(String p0);

/* class java.util.UnknownFormatFlagsException */
class Java_util_UnknownFormatFlagsException extends Java_util_IllegalFormatException {
	/*-- Method --*/
	@Virtual @Overload String getFlags();
}
Java_util_UnknownFormatFlagsException Java_util_UnknownFormatFlagsException.new(String p0);

/* class java.util.Vector */
class Java_util_Vector extends Java_util_AbstractList {
	// implements java.util.List, java.util.RandomAccess, java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addElement(Object p0);
	@Virtual @Overload int capacity();
	@Virtual @Overload Object clone();
	@Virtual @Overload void copyInto(Object[] p0);
	@Virtual @Overload Object elementAt(int p0);
	@Virtual @Overload Java_util_Enumeration elements();
	@Virtual @Overload void ensureCapacity(int p0);
	@Virtual @Overload Object firstElement();
	@Virtual @Overload int indexOf(Object p0, int p1);
	@Virtual @Overload void insertElementAt(Object p0, int p1);
	@Virtual @Overload Object lastElement();
	@Virtual @Overload int lastIndexOf(Object p0, int p1);
	@Virtual @Overload void removeAllElements();
	@Virtual @Overload boolean removeElement(Object p0);
	@Virtual @Overload void removeElementAt(int p0);
	@Virtual @Overload void setElementAt(Object p0, int p1);
	@Virtual @Overload void setSize(int p0);
	@Virtual @Overload void trimToSize();
}
@Overload Java_util_Vector Java_util_Vector.new(int p0, int p1);
@Overload Java_util_Vector Java_util_Vector.new(int p0);
@Overload Java_util_Vector Java_util_Vector.new();
@Overload Java_util_Vector Java_util_Vector.new(Java_util_Collection p0);

/* class java.util.WeakHashMap */
class Java_util_WeakHashMap extends Java_util_AbstractMap {
	// implements java.util.Map
}
@Overload Java_util_WeakHashMap Java_util_WeakHashMap.new(int p0, float p1);
@Overload Java_util_WeakHashMap Java_util_WeakHashMap.new(int p0);
@Overload Java_util_WeakHashMap Java_util_WeakHashMap.new();
@Overload Java_util_WeakHashMap Java_util_WeakHashMap.new(Java_util_Map p0);


/*------------------------------------------------------------*/
/* short names */
AbstractCollection = Java_util_AbstractCollection
AbstractList = Java_util_AbstractList
AbstractMap = Java_util_AbstractMap
AbstractQueue = Java_util_AbstractQueue
AbstractSequentialList = Java_util_AbstractSequentialList
AbstractSet = Java_util_AbstractSet
ArrayDeque = Java_util_ArrayDeque
ArrayList = Java_util_ArrayList
Arrays = Java_util_Arrays
BitSet = Java_util_BitSet
Calendar = Java_util_Calendar
Collection = Java_util_Collection
Collections = Java_util_Collections
Comparator = Java_util_Comparator
ConcurrentModificationException = Java_util_ConcurrentModificationException
Currency = Java_util_Currency
Date = Java_util_Date
Deque = Java_util_Deque
Dictionary = Java_util_Dictionary
DuplicateFormatFlagsException = Java_util_DuplicateFormatFlagsException
EmptyStackException = Java_util_EmptyStackException
EnumMap = Java_util_EnumMap
EnumSet = Java_util_EnumSet
Enumeration = Java_util_Enumeration
EventListener = Java_util_EventListener
EventListenerProxy = Java_util_EventListenerProxy
EventObject = Java_util_EventObject
FormatFlagsConversionMismatchException = Java_util_FormatFlagsConversionMismatchException
Formattable = Java_util_Formattable
FormattableFlags = Java_util_FormattableFlags
Formatter = Java_util_Formatter
FormatterClosedException = Java_util_FormatterClosedException
GregorianCalendar = Java_util_GregorianCalendar
HashMap = Java_util_HashMap
HashSet = Java_util_HashSet
Hashtable = Java_util_Hashtable
IdentityHashMap = Java_util_IdentityHashMap
IllegalFormatCodePointException = Java_util_IllegalFormatCodePointException
IllegalFormatConversionException = Java_util_IllegalFormatConversionException
IllegalFormatException = Java_util_IllegalFormatException
IllegalFormatFlagsException = Java_util_IllegalFormatFlagsException
IllegalFormatPrecisionException = Java_util_IllegalFormatPrecisionException
IllegalFormatWidthException = Java_util_IllegalFormatWidthException
IllformedLocaleException = Java_util_IllformedLocaleException
InputMismatchException = Java_util_InputMismatchException
InvalidPropertiesFormatException = Java_util_InvalidPropertiesFormatException
Iterator = Java_util_Iterator
LinkedHashMap = Java_util_LinkedHashMap
LinkedHashSet = Java_util_LinkedHashSet
LinkedList = Java_util_LinkedList
List = Java_util_List
ListIterator = Java_util_ListIterator
ListResourceBundle = Java_util_ListResourceBundle
Locale = Java_util_Locale
Map = Java_util_Map
MissingFormatArgumentException = Java_util_MissingFormatArgumentException
MissingFormatWidthException = Java_util_MissingFormatWidthException
MissingResourceException = Java_util_MissingResourceException
NavigableMap = Java_util_NavigableMap
NavigableSet = Java_util_NavigableSet
NoSuchElementException = Java_util_NoSuchElementException
Objects = Java_util_Objects
Observable = Java_util_Observable
Observer = Java_util_Observer
PriorityQueue = Java_util_PriorityQueue
Properties = Java_util_Properties
PropertyPermission = Java_util_PropertyPermission
PropertyResourceBundle = Java_util_PropertyResourceBundle
Queue = Java_util_Queue
Random = Java_util_Random
RandomAccess = Java_util_RandomAccess
ResourceBundle = Java_util_ResourceBundle
Scanner = Java_util_Scanner
ServiceConfigurationError = Java_util_ServiceConfigurationError
ServiceLoader = Java_util_ServiceLoader
Set = Java_util_Set
SimpleTimeZone = Java_util_SimpleTimeZone
SortedMap = Java_util_SortedMap
SortedSet = Java_util_SortedSet
Stack = Java_util_Stack
StringTokenizer = Java_util_StringTokenizer
TimeZone = Java_util_TimeZone
Timer = Java_util_Timer
TimerTask = Java_util_TimerTask
TooManyListenersException = Java_util_TooManyListenersException
TreeMap = Java_util_TreeMap
TreeSet = Java_util_TreeSet
UUID = Java_util_UUID
UnknownFormatConversionException = Java_util_UnknownFormatConversionException
UnknownFormatFlagsException = Java_util_UnknownFormatFlagsException
Vector = Java_util_Vector
WeakHashMap = Java_util_WeakHashMap
