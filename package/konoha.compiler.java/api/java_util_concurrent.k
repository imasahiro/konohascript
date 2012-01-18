/* converted from java package java.util.concurrent */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_lang_Enum;
class Java_lang_Exception;
class Java_lang_IllegalStateException;
class Java_lang_Runnable;
class Java_lang_RuntimeException;
class Java_lang_Thread;
class Java_lang_Thread_UncaughtExceptionHandler;
class Java_lang_Throwable;
class Java_security_PrivilegedAction;
class Java_security_PrivilegedExceptionAction;
class Java_util_AbstractCollection;
class Java_util_AbstractMap;
class Java_util_AbstractQueue;
class Java_util_AbstractSet;
class Java_util_Collection;
class Java_util_Comparator;
class Java_util_Enumeration;
class Java_util_Iterator;
class Java_util_List;
class Java_util_ListIterator;
class Java_util_Map;
class Java_util_Map_Entry;
class Java_util_NavigableMap;
class Java_util_NavigableSet;
class Java_util_Random;
class Java_util_SortedMap;
class Java_util_SortedSet;
class Java_util_concurrent_ForkJoinPool_ForkJoinWorkerThreadFactory;
class Java_util_concurrent_ForkJoinPool_ManagedBlocker;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_util_concurrent_AbstractExecutorService;
class Java_util_concurrent_ArrayBlockingQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_BlockingDeque;
class Java_util_concurrent_BlockingQueue;
class Java_util_concurrent_BrokenBarrierException extends Java_lang_Exception;
class Java_util_concurrent_Callable;
class Java_util_concurrent_CancellationException extends Java_lang_IllegalStateException;
class Java_util_concurrent_CompletionService;
class Java_util_concurrent_ConcurrentHashMap extends Java_util_AbstractMap;
class Java_util_concurrent_ConcurrentLinkedDeque extends Java_util_AbstractCollection;
class Java_util_concurrent_ConcurrentLinkedQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_ConcurrentMap;
class Java_util_concurrent_ConcurrentNavigableMap;
class Java_util_concurrent_ConcurrentSkipListMap extends Java_util_AbstractMap;
class Java_util_concurrent_ConcurrentSkipListSet extends Java_util_AbstractSet;
class Java_util_concurrent_CopyOnWriteArrayList;
class Java_util_concurrent_CopyOnWriteArraySet extends Java_util_AbstractSet;
class Java_util_concurrent_CountDownLatch;
class Java_util_concurrent_CyclicBarrier;
class Java_util_concurrent_DelayQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_Delayed;
class Java_util_concurrent_Exchanger;
class Java_util_concurrent_ExecutionException extends Java_lang_Exception;
class Java_util_concurrent_Executor;
class Java_util_concurrent_ExecutorCompletionService;
class Java_util_concurrent_ExecutorService;
class Java_util_concurrent_Executors;
class Java_util_concurrent_ForkJoinPool extends Java_util_concurrent_AbstractExecutorService;
class Java_util_concurrent_ForkJoinTask;
class Java_util_concurrent_ForkJoinWorkerThread extends Java_lang_Thread;
class Java_util_concurrent_Future;
class Java_util_concurrent_FutureTask;
class Java_util_concurrent_LinkedBlockingDeque extends Java_util_AbstractQueue;
class Java_util_concurrent_LinkedBlockingQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_LinkedTransferQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_Phaser;
class Java_util_concurrent_PriorityBlockingQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_RecursiveAction extends Java_util_concurrent_ForkJoinTask;
class Java_util_concurrent_RecursiveTask extends Java_util_concurrent_ForkJoinTask;
class Java_util_concurrent_RejectedExecutionException extends Java_lang_RuntimeException;
class Java_util_concurrent_RejectedExecutionHandler;
class Java_util_concurrent_RunnableFuture;
class Java_util_concurrent_RunnableScheduledFuture;
class Java_util_concurrent_ScheduledExecutorService;
class Java_util_concurrent_ScheduledFuture;
class Java_util_concurrent_ThreadPoolExecutor extends Java_util_concurrent_AbstractExecutorService;
class Java_util_concurrent_ScheduledThreadPoolExecutor extends Java_util_concurrent_ThreadPoolExecutor;
class Java_util_concurrent_Semaphore;
class Java_util_concurrent_SynchronousQueue extends Java_util_AbstractQueue;
class Java_util_concurrent_ThreadFactory;
class Java_util_concurrent_ThreadLocalRandom extends Java_util_Random;
class Java_util_concurrent_TimeUnit extends Java_lang_Enum;
class Java_util_concurrent_TimeoutException extends Java_lang_Exception;
class Java_util_concurrent_TransferQueue;

/*------------------------------------------------------------*/
/* class java.util.concurrent.AbstractExecutorService */
class Java_util_concurrent_AbstractExecutorService {
	/*-- Method --*/
	@Virtual @Overload Java_util_List invokeAll(Java_util_Collection p0);
	@Virtual @Overload Java_util_List invokeAll(Java_util_Collection p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object invokeAny(Java_util_Collection p0);
	@Virtual @Overload Object invokeAny(Java_util_Collection p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_util_concurrent_Callable p0);
}
Java_util_concurrent_AbstractExecutorService Java_util_concurrent_AbstractExecutorService.new();
/* class java.util.concurrent.ArrayBlockingQueue */
class Java_util_concurrent_ArrayBlockingQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object take();
}
@Overload Java_util_concurrent_ArrayBlockingQueue Java_util_concurrent_ArrayBlockingQueue.new(int p0);
@Overload Java_util_concurrent_ArrayBlockingQueue Java_util_concurrent_ArrayBlockingQueue.new(int p0, boolean p1);
@Overload Java_util_concurrent_ArrayBlockingQueue Java_util_concurrent_ArrayBlockingQueue.new(int p0, boolean p1, Java_util_Collection p2);
/* interface java.util.concurrent.BlockingDeque */
class Java_util_concurrent_BlockingDeque {
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload Object element();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean offerFirst(Object p0);
	@Virtual @Overload boolean offerFirst(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean offerLast(Object p0);
	@Virtual @Overload boolean offerLast(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object peek();
	@Virtual @Overload Object poll();
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object pollFirst(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object pollLast(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void push(Object p0);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload void putFirst(Object p0);
	@Virtual @Overload void putLast(Object p0);
	@Virtual @Overload Object remove();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload boolean removeFirstOccurrence(Object p0);
	@Virtual @Overload boolean removeLastOccurrence(Object p0);
	@Virtual @Overload int size();
	@Virtual @Overload Object take();
	@Virtual @Overload Object takeFirst();
	@Virtual @Overload Object takeLast();
}
/* interface java.util.concurrent.BlockingQueue */
class Java_util_concurrent_BlockingQueue {
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Object p0);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload Object take();
}
/* class java.util.concurrent.BrokenBarrierException */
class Java_util_concurrent_BrokenBarrierException extends Java_lang_Exception {
}
@Overload Java_util_concurrent_BrokenBarrierException Java_util_concurrent_BrokenBarrierException.new();
@Overload Java_util_concurrent_BrokenBarrierException Java_util_concurrent_BrokenBarrierException.new(String p0);
/* interface java.util.concurrent.Callable */
class Java_util_concurrent_Callable {
	/*-- Method --*/
	@Virtual @Overload Object call();
}
/* class java.util.concurrent.CancellationException */
class Java_util_concurrent_CancellationException extends Java_lang_IllegalStateException {
}
@Overload Java_util_concurrent_CancellationException Java_util_concurrent_CancellationException.new();
@Overload Java_util_concurrent_CancellationException Java_util_concurrent_CancellationException.new(String p0);
/* interface java.util.concurrent.CompletionService */
class Java_util_concurrent_CompletionService {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_Future poll();
	@Virtual @Overload Java_util_concurrent_Future poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_util_concurrent_Callable p0);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_Future take();
}
/* class java.util.concurrent.ConcurrentHashMap */
class Java_util_concurrent_ConcurrentHashMap extends Java_util_AbstractMap {
	/*-- Method --*/
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload Java_util_Enumeration elements();
	@Virtual @Overload Java_util_Enumeration keys();
	@Virtual @Overload Object putIfAbsent(Object p0, Object p1);
	@Virtual @Overload boolean remove(Object p0, Object p1);
	@Virtual @Overload boolean replace(Object p0, Object p1, Object p2);
	@Virtual @Overload Object replace(Object p0, Object p1);
}
@Overload Java_util_concurrent_ConcurrentHashMap Java_util_concurrent_ConcurrentHashMap.new(int p0, float p1, int p2);
@Overload Java_util_concurrent_ConcurrentHashMap Java_util_concurrent_ConcurrentHashMap.new(int p0, float p1);
@Overload Java_util_concurrent_ConcurrentHashMap Java_util_concurrent_ConcurrentHashMap.new(int p0);
@Overload Java_util_concurrent_ConcurrentHashMap Java_util_concurrent_ConcurrentHashMap.new();
@Overload Java_util_concurrent_ConcurrentHashMap Java_util_concurrent_ConcurrentHashMap.new(Java_util_Map p0);
/* class java.util.concurrent.ConcurrentLinkedDeque */
class Java_util_concurrent_ConcurrentLinkedDeque extends Java_util_AbstractCollection {
	/*-- Method --*/
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
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
@Overload Java_util_concurrent_ConcurrentLinkedDeque Java_util_concurrent_ConcurrentLinkedDeque.new();
@Overload Java_util_concurrent_ConcurrentLinkedDeque Java_util_concurrent_ConcurrentLinkedDeque.new(Java_util_Collection p0);
/* class java.util.concurrent.ConcurrentLinkedQueue */
class Java_util_concurrent_ConcurrentLinkedQueue extends Java_util_AbstractQueue {
}
@Overload Java_util_concurrent_ConcurrentLinkedQueue Java_util_concurrent_ConcurrentLinkedQueue.new();
@Overload Java_util_concurrent_ConcurrentLinkedQueue Java_util_concurrent_ConcurrentLinkedQueue.new(Java_util_Collection p0);
/* interface java.util.concurrent.ConcurrentMap */
class Java_util_concurrent_ConcurrentMap {
	/*-- Method --*/
	@Virtual @Overload Object putIfAbsent(Object p0, Object p1);
	@Virtual @Overload boolean remove(Object p0, Object p1);
	@Virtual @Overload boolean replace(Object p0, Object p1, Object p2);
	@Virtual @Overload Object replace(Object p0, Object p1);
}
/* interface java.util.concurrent.ConcurrentNavigableMap */
class Java_util_concurrent_ConcurrentNavigableMap {
	/*-- Method --*/
	@Virtual @Overload Java_util_NavigableSet descendingKeySet();
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap descendingMap();
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap headMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap headMap(Object p0);
	@Virtual @Overload Java_util_NavigableSet keySet();
	@Virtual @Overload Java_util_NavigableSet navigableKeySet();
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap subMap(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap tailMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap tailMap(Object p0);
}
/* class java.util.concurrent.ConcurrentSkipListMap */
class Java_util_concurrent_ConcurrentSkipListMap extends Java_util_AbstractMap {
	/*-- Method --*/
	@Virtual @Overload Java_util_Map_Entry ceilingEntry(Object p0);
	@Virtual @Overload Object ceilingKey(Object p0);
	@Virtual @Overload Java_util_concurrent_ConcurrentSkipListMap clone();
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Java_util_NavigableSet descendingKeySet();
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap descendingMap();
	@Virtual @Overload Java_util_NavigableMap descendingMap();
	@Virtual @Overload Java_util_Map_Entry firstEntry();
	@Virtual @Overload Object firstKey();
	@Virtual @Overload Java_util_Map_Entry floorEntry(Object p0);
	@Virtual @Overload Object floorKey(Object p0);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap headMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap headMap(Object p0);
	@Virtual @Overload Java_util_SortedMap headMap(Object p0);
	@Virtual @Overload Java_util_NavigableMap headMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_Map_Entry higherEntry(Object p0);
	@Virtual @Overload Object higherKey(Object p0);
	@Virtual @Overload Java_util_Map_Entry lastEntry();
	@Virtual @Overload Object lastKey();
	@Virtual @Overload Java_util_Map_Entry lowerEntry(Object p0);
	@Virtual @Overload Object lowerKey(Object p0);
	@Virtual @Overload Java_util_NavigableSet navigableKeySet();
	@Virtual @Overload Java_util_Map_Entry pollFirstEntry();
	@Virtual @Overload Java_util_Map_Entry pollLastEntry();
	@Virtual @Overload Object putIfAbsent(Object p0, Object p1);
	@Virtual @Overload boolean remove(Object p0, Object p1);
	@Virtual @Overload boolean replace(Object p0, Object p1, Object p2);
	@Virtual @Overload Object replace(Object p0, Object p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap subMap(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_SortedMap subMap(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableMap subMap(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap tailMap(Object p0, boolean p1);
	@Virtual @Overload Java_util_concurrent_ConcurrentNavigableMap tailMap(Object p0);
	@Virtual @Overload Java_util_SortedMap tailMap(Object p0);
	@Virtual @Overload Java_util_NavigableMap tailMap(Object p0, boolean p1);
}
@Overload Java_util_concurrent_ConcurrentSkipListMap Java_util_concurrent_ConcurrentSkipListMap.new();
@Overload Java_util_concurrent_ConcurrentSkipListMap Java_util_concurrent_ConcurrentSkipListMap.new(Java_util_Comparator p0);
@Overload Java_util_concurrent_ConcurrentSkipListMap Java_util_concurrent_ConcurrentSkipListMap.new(Java_util_Map p0);
@Overload Java_util_concurrent_ConcurrentSkipListMap Java_util_concurrent_ConcurrentSkipListMap.new(Java_util_SortedMap p0);
/* class java.util.concurrent.ConcurrentSkipListSet */
class Java_util_concurrent_ConcurrentSkipListSet extends Java_util_AbstractSet {
	/*-- Method --*/
	@Virtual @Overload Object ceiling(Object p0);
	@Virtual @Overload Java_util_concurrent_ConcurrentSkipListSet clone();
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload Java_util_NavigableSet descendingSet();
	@Virtual @Overload Object first();
	@Virtual @Overload Object floor(Object p0);
	@Virtual @Overload Java_util_NavigableSet headSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_NavigableSet headSet(Object p0);
	@Virtual @Overload Java_util_SortedSet headSet(Object p0);
	@Virtual @Overload Object higher(Object p0);
	@Virtual @Overload Object last();
	@Virtual @Overload Object lower(Object p0);
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Java_util_NavigableSet subSet(Object p0, boolean p1, Object p2, boolean p3);
	@Virtual @Overload Java_util_NavigableSet subSet(Object p0, Object p1);
	@Virtual @Overload Java_util_SortedSet subSet(Object p0, Object p1);
	@Virtual @Overload Java_util_NavigableSet tailSet(Object p0, boolean p1);
	@Virtual @Overload Java_util_NavigableSet tailSet(Object p0);
	@Virtual @Overload Java_util_SortedSet tailSet(Object p0);
}
@Overload Java_util_concurrent_ConcurrentSkipListSet Java_util_concurrent_ConcurrentSkipListSet.new();
@Overload Java_util_concurrent_ConcurrentSkipListSet Java_util_concurrent_ConcurrentSkipListSet.new(Java_util_Comparator p0);
@Overload Java_util_concurrent_ConcurrentSkipListSet Java_util_concurrent_ConcurrentSkipListSet.new(Java_util_Collection p0);
@Overload Java_util_concurrent_ConcurrentSkipListSet Java_util_concurrent_ConcurrentSkipListSet.new(Java_util_SortedSet p0);
/* class java.util.concurrent.CopyOnWriteArrayList */
class Java_util_concurrent_CopyOnWriteArrayList {
	/*-- Method --*/
	@Virtual @Overload boolean add(Object p0);
	@Virtual @Overload void add(int p0, Object p1);
	@Virtual @Overload boolean addAll(Java_util_Collection p0);
	@Virtual @Overload boolean addAll(int p0, Java_util_Collection p1);
	@Virtual @Overload int addAllAbsent(Java_util_Collection p0);
	@Virtual @Overload boolean addIfAbsent(Object p0);
	@Virtual @Overload void clear();
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean contains(Object p0);
	@Virtual @Overload boolean containsAll(Java_util_Collection p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Object get(int p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload int indexOf(Object p0);
	@Virtual @Overload int indexOf(Object p0, int p1);
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload int lastIndexOf(Object p0);
	@Virtual @Overload int lastIndexOf(Object p0, int p1);
	@Virtual @Overload Java_util_ListIterator listIterator();
	@Virtual @Overload Java_util_ListIterator listIterator(int p0);
	@Virtual @Overload Object remove(int p0);
	@Virtual @Overload boolean remove(Object p0);
	@Virtual @Overload boolean removeAll(Java_util_Collection p0);
	@Virtual @Overload boolean retainAll(Java_util_Collection p0);
	@Virtual @Overload Object set(int p0, Object p1);
	@Virtual @Overload int size();
	@Virtual @Overload Java_util_List subList(int p0, int p1);
	@Virtual @Overload Object[] toArray();
	@Virtual @Overload Object[] toArray(Object[] p0);
	@Virtual @Overload String toString();
}
@Overload Java_util_concurrent_CopyOnWriteArrayList Java_util_concurrent_CopyOnWriteArrayList.new();
@Overload Java_util_concurrent_CopyOnWriteArrayList Java_util_concurrent_CopyOnWriteArrayList.new(Java_util_Collection p0);
@Overload Java_util_concurrent_CopyOnWriteArrayList Java_util_concurrent_CopyOnWriteArrayList.new(Object[] p0);
/* class java.util.concurrent.CopyOnWriteArraySet */
class Java_util_concurrent_CopyOnWriteArraySet extends Java_util_AbstractSet {
}
@Overload Java_util_concurrent_CopyOnWriteArraySet Java_util_concurrent_CopyOnWriteArraySet.new();
@Overload Java_util_concurrent_CopyOnWriteArraySet Java_util_concurrent_CopyOnWriteArraySet.new(Java_util_Collection p0);
/* class java.util.concurrent.CountDownLatch */
class Java_util_concurrent_CountDownLatch {
	/*-- Method --*/
	@Virtual @Overload void await();
	@Virtual @Overload boolean await(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void countDown();
	@Virtual @Overload long getCount();
	@Virtual @Overload String toString();
}
Java_util_concurrent_CountDownLatch Java_util_concurrent_CountDownLatch.new(int p0);
/* class java.util.concurrent.CyclicBarrier */
class Java_util_concurrent_CyclicBarrier {
	/*-- Method --*/
	@Virtual @Overload int await();
	@Virtual @Overload int await(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload int getNumberWaiting();
	@Virtual @Overload int getParties();
	@Virtual @Overload boolean isBroken();
	@Virtual @Overload void reset();
}
@Overload Java_util_concurrent_CyclicBarrier Java_util_concurrent_CyclicBarrier.new(int p0, Java_lang_Runnable p1);
@Overload Java_util_concurrent_CyclicBarrier Java_util_concurrent_CyclicBarrier.new(int p0);
/* class java.util.concurrent.DelayQueue */
class Java_util_concurrent_DelayQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload boolean add(Java_util_concurrent_Delayed p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Java_util_concurrent_Delayed p0);
	@Virtual @Overload boolean offer(Java_util_concurrent_Delayed p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_Delayed poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Java_util_concurrent_Delayed p0);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Java_util_concurrent_Delayed take();
	@Virtual @Overload Object take();
}
@Overload Java_util_concurrent_DelayQueue Java_util_concurrent_DelayQueue.new();
@Overload Java_util_concurrent_DelayQueue Java_util_concurrent_DelayQueue.new(Java_util_Collection p0);
/* interface java.util.concurrent.Delayed */
class Java_util_concurrent_Delayed {
	/*-- Method --*/
	@Virtual @Overload long getDelay(Java_util_concurrent_TimeUnit p0);
}
/* class java.util.concurrent.Exchanger */
class Java_util_concurrent_Exchanger {
	/*-- Method --*/
	@Virtual @Overload Object exchange(Object p0);
	@Virtual @Overload Object exchange(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
}
Java_util_concurrent_Exchanger Java_util_concurrent_Exchanger.new();
/* class java.util.concurrent.ExecutionException */
class Java_util_concurrent_ExecutionException extends Java_lang_Exception {
}
@Overload Java_util_concurrent_ExecutionException Java_util_concurrent_ExecutionException.new(String p0, Java_lang_Throwable p1);
@Overload Java_util_concurrent_ExecutionException Java_util_concurrent_ExecutionException.new(Java_lang_Throwable p0);
/* interface java.util.concurrent.Executor */
class Java_util_concurrent_Executor {
	/*-- Method --*/
	@Virtual @Overload void execute(Java_lang_Runnable p0);
}
/* class java.util.concurrent.ExecutorCompletionService */
class Java_util_concurrent_ExecutorCompletionService {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_Future poll();
	@Virtual @Overload Java_util_concurrent_Future poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_util_concurrent_Callable p0);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_Future take();
}
@Overload Java_util_concurrent_ExecutorCompletionService Java_util_concurrent_ExecutorCompletionService.new(Java_util_concurrent_Executor p0);
@Overload Java_util_concurrent_ExecutorCompletionService Java_util_concurrent_ExecutorCompletionService.new(Java_util_concurrent_Executor p0, Java_util_concurrent_BlockingQueue p1);
/* interface java.util.concurrent.ExecutorService */
class Java_util_concurrent_ExecutorService {
	/*-- Method --*/
	@Virtual @Overload boolean awaitTermination(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Java_util_List invokeAll(Java_util_Collection p0);
	@Virtual @Overload Java_util_List invokeAll(Java_util_Collection p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object invokeAny(Java_util_Collection p0);
	@Virtual @Overload Object invokeAny(Java_util_Collection p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean isShutdown();
	@Virtual @Overload boolean isTerminated();
	@Virtual @Overload void shutdown();
	@Virtual @Overload Java_util_List shutdownNow();
	@Virtual @Overload Java_util_concurrent_Future submit(Java_util_concurrent_Callable p0);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_Future submit(Java_lang_Runnable p0);
}
/* class java.util.concurrent.Executors */
class Java_util_concurrent_Executors {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_Callable callable(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_Callable callable(Java_lang_Runnable p0);
	@Virtual @Overload Java_util_concurrent_Callable callable(Java_security_PrivilegedAction p0);
	@Virtual @Overload Java_util_concurrent_Callable callable(Java_security_PrivilegedExceptionAction p0);
	@Virtual @Overload Java_util_concurrent_ThreadFactory defaultThreadFactory();
	@Virtual @Overload Java_util_concurrent_ExecutorService newCachedThreadPool();
	@Virtual @Overload Java_util_concurrent_ExecutorService newCachedThreadPool(Java_util_concurrent_ThreadFactory p0);
	@Virtual @Overload Java_util_concurrent_ExecutorService newFixedThreadPool(int p0);
	@Virtual @Overload Java_util_concurrent_ExecutorService newFixedThreadPool(int p0, Java_util_concurrent_ThreadFactory p1);
	@Virtual @Overload Java_util_concurrent_ScheduledExecutorService newScheduledThreadPool(int p0);
	@Virtual @Overload Java_util_concurrent_ScheduledExecutorService newScheduledThreadPool(int p0, Java_util_concurrent_ThreadFactory p1);
	@Virtual @Overload Java_util_concurrent_ExecutorService newSingleThreadExecutor();
	@Virtual @Overload Java_util_concurrent_ExecutorService newSingleThreadExecutor(Java_util_concurrent_ThreadFactory p0);
	@Virtual @Overload Java_util_concurrent_ScheduledExecutorService newSingleThreadScheduledExecutor();
	@Virtual @Overload Java_util_concurrent_ScheduledExecutorService newSingleThreadScheduledExecutor(Java_util_concurrent_ThreadFactory p0);
	@Virtual @Overload Java_util_concurrent_Callable privilegedCallable(Java_util_concurrent_Callable p0);
	@Virtual @Overload Java_util_concurrent_Callable privilegedCallableUsingCurrentClassLoader(Java_util_concurrent_Callable p0);
	@Virtual @Overload Java_util_concurrent_ThreadFactory privilegedThreadFactory();
	@Virtual @Overload Java_util_concurrent_ExecutorService unconfigurableExecutorService(Java_util_concurrent_ExecutorService p0);
	@Virtual @Overload Java_util_concurrent_ScheduledExecutorService unconfigurableScheduledExecutorService(Java_util_concurrent_ScheduledExecutorService p0);
}
/* class java.util.concurrent.ForkJoinPool */
class Java_util_concurrent_ForkJoinPool extends Java_util_concurrent_AbstractExecutorService {
	/*-- Method --*/
	@Virtual @Overload void execute(Java_util_concurrent_ForkJoinTask p0);
	@Virtual @Overload int getActiveThreadCount();
	@Virtual @Overload boolean getAsyncMode();
	@Virtual @Overload Java_util_concurrent_ForkJoinPool_ForkJoinWorkerThreadFactory getFactory();
	@Virtual @Overload int getParallelism();
	@Virtual @Overload int getPoolSize();
	@Virtual @Overload int getQueuedSubmissionCount();
	@Virtual @Overload long getQueuedTaskCount();
	@Virtual @Overload int getRunningThreadCount();
	@Virtual @Overload long getStealCount();
	@Virtual @Overload Java_lang_Thread_UncaughtExceptionHandler getUncaughtExceptionHandler();
	@Virtual @Overload boolean hasQueuedSubmissions();
	@Virtual @Overload Object invoke(Java_util_concurrent_ForkJoinTask p0);
	@Virtual @Overload boolean isQuiescent();
	@Virtual @Overload boolean isTerminating();
	@Virtual @Overload void managedBlock(Java_util_concurrent_ForkJoinPool_ManagedBlocker p0);
	@Virtual @Overload Java_util_concurrent_ForkJoinTask submit(Java_util_concurrent_ForkJoinTask p0);
}
@Overload Java_util_concurrent_ForkJoinPool Java_util_concurrent_ForkJoinPool.new();
@Overload Java_util_concurrent_ForkJoinPool Java_util_concurrent_ForkJoinPool.new(int p0);
@Overload Java_util_concurrent_ForkJoinPool Java_util_concurrent_ForkJoinPool.new(int p0, Java_util_concurrent_ForkJoinPool_ForkJoinWorkerThreadFactory p1, Java_lang_Thread_UncaughtExceptionHandler p2, boolean p3);
/* class java.util.concurrent.ForkJoinTask */
class Java_util_concurrent_ForkJoinTask {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_ForkJoinTask adapt(Java_lang_Runnable p0);
	@Virtual @Overload Java_util_concurrent_ForkJoinTask adapt(Java_lang_Runnable p0, Object p1);
	@Virtual @Overload Java_util_concurrent_ForkJoinTask adapt(Java_util_concurrent_Callable p0);
	@Virtual @Overload boolean cancel(boolean p0);
	@Virtual @Overload void complete(Object p0);
	@Virtual @Overload void completeExceptionally(Java_lang_Throwable p0);
	@Virtual @Overload Java_util_concurrent_ForkJoinTask fork();
	@Virtual @Overload Object get();
	@Virtual @Overload Object get(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Java_lang_Throwable getException();
	@Virtual @Overload Java_util_concurrent_ForkJoinPool getPool();
	@Virtual @Overload int getQueuedTaskCount();
	@Virtual @Overload Object getRawResult();
	@Virtual @Overload int getSurplusQueuedTaskCount();
	@Virtual @Overload void helpQuiesce();
	@Virtual @Overload boolean inForkJoinPool();
	@Virtual @Overload Object invoke();
	@Virtual @Overload void invokeAll(Java_util_concurrent_ForkJoinTask p0, Java_util_concurrent_ForkJoinTask p1);
	@Virtual @Overload void invokeAll(Java_util_concurrent_ForkJoinTask[] p0);
	@Virtual @Overload Java_util_Collection invokeAll(Java_util_Collection p0);
	@Virtual @Overload boolean isCancelled();
	@Virtual @Overload boolean isCompletedAbnormally();
	@Virtual @Overload boolean isCompletedNormally();
	@Virtual @Overload boolean isDone();
	@Virtual @Overload Object join();
	@Virtual @Overload void quietlyInvoke();
	@Virtual @Overload void quietlyJoin();
	@Virtual @Overload void reinitialize();
	@Virtual @Overload boolean tryUnfork();
}
Java_util_concurrent_ForkJoinTask Java_util_concurrent_ForkJoinTask.new();
/* class java.util.concurrent.ForkJoinWorkerThread */
class Java_util_concurrent_ForkJoinWorkerThread extends Java_lang_Thread {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_ForkJoinPool getPool();
	@Virtual @Overload int getPoolIndex();
}
/* interface java.util.concurrent.Future */
class Java_util_concurrent_Future {
	/*-- Method --*/
	@Virtual @Overload boolean cancel(boolean p0);
	@Virtual @Overload Object get();
	@Virtual @Overload Object get(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload boolean isCancelled();
	@Virtual @Overload boolean isDone();
}
/* class java.util.concurrent.FutureTask */
class Java_util_concurrent_FutureTask {
	/*-- Method --*/
	@Virtual @Overload boolean cancel(boolean p0);
	@Virtual @Overload Object get();
	@Virtual @Overload Object get(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload boolean isCancelled();
	@Virtual @Overload boolean isDone();
	@Virtual @Overload void run();
}
@Overload Java_util_concurrent_FutureTask Java_util_concurrent_FutureTask.new(Java_util_concurrent_Callable p0);
@Overload Java_util_concurrent_FutureTask Java_util_concurrent_FutureTask.new(Java_lang_Runnable p0, Object p1);
/* class java.util.concurrent.LinkedBlockingDeque */
class Java_util_concurrent_LinkedBlockingDeque extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload void addFirst(Object p0);
	@Virtual @Overload void addLast(Object p0);
	@Virtual @Overload Java_util_Iterator descendingIterator();
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload Object getFirst();
	@Virtual @Overload Object getLast();
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean offerFirst(Object p0);
	@Virtual @Overload boolean offerFirst(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload boolean offerLast(Object p0);
	@Virtual @Overload boolean offerLast(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object peekFirst();
	@Virtual @Overload Object peekLast();
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object pollFirst();
	@Virtual @Overload Object pollFirst(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object pollLast();
	@Virtual @Overload Object pollLast(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload Object pop();
	@Virtual @Overload void push(Object p0);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload void putFirst(Object p0);
	@Virtual @Overload void putLast(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object removeFirst();
	@Virtual @Overload boolean removeFirstOccurrence(Object p0);
	@Virtual @Overload Object removeLast();
	@Virtual @Overload boolean removeLastOccurrence(Object p0);
	@Virtual @Overload Object take();
	@Virtual @Overload Object takeFirst();
	@Virtual @Overload Object takeLast();
}
@Overload Java_util_concurrent_LinkedBlockingDeque Java_util_concurrent_LinkedBlockingDeque.new();
@Overload Java_util_concurrent_LinkedBlockingDeque Java_util_concurrent_LinkedBlockingDeque.new(int p0);
@Overload Java_util_concurrent_LinkedBlockingDeque Java_util_concurrent_LinkedBlockingDeque.new(Java_util_Collection p0);
/* class java.util.concurrent.LinkedBlockingQueue */
class Java_util_concurrent_LinkedBlockingQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object take();
}
@Overload Java_util_concurrent_LinkedBlockingQueue Java_util_concurrent_LinkedBlockingQueue.new();
@Overload Java_util_concurrent_LinkedBlockingQueue Java_util_concurrent_LinkedBlockingQueue.new(int p0);
@Overload Java_util_concurrent_LinkedBlockingQueue Java_util_concurrent_LinkedBlockingQueue.new(Java_util_Collection p0);
/* class java.util.concurrent.LinkedTransferQueue */
class Java_util_concurrent_LinkedTransferQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload int getWaitingConsumerCount();
	@Virtual @Overload boolean hasWaitingConsumer();
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object take();
	@Virtual @Overload void transfer(Object p0);
	@Virtual @Overload boolean tryTransfer(Object p0);
	@Virtual @Overload boolean tryTransfer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
}
@Overload Java_util_concurrent_LinkedTransferQueue Java_util_concurrent_LinkedTransferQueue.new();
@Overload Java_util_concurrent_LinkedTransferQueue Java_util_concurrent_LinkedTransferQueue.new(Java_util_Collection p0);
/* class java.util.concurrent.Phaser */
class Java_util_concurrent_Phaser {
	/*-- Method --*/
	@Virtual @Overload int arrive();
	@Virtual @Overload int arriveAndAwaitAdvance();
	@Virtual @Overload int arriveAndDeregister();
	@Virtual @Overload int awaitAdvance(int p0);
	@Virtual @Overload int awaitAdvanceInterruptibly(int p0);
	@Virtual @Overload int awaitAdvanceInterruptibly(int p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload int bulkRegister(int p0);
	@Virtual @Overload void forceTermination();
	@Virtual @Overload int getArrivedParties();
	@Virtual @Overload Java_util_concurrent_Phaser getParent();
	@Virtual @Overload int getPhase();
	@Virtual @Overload int getRegisteredParties();
	@Virtual @Overload Java_util_concurrent_Phaser getRoot();
	@Virtual @Overload int getUnarrivedParties();
	@Virtual @Overload boolean isTerminated();
	@Virtual @Overload int register();
	@Virtual @Overload String toString();
}
@Overload Java_util_concurrent_Phaser Java_util_concurrent_Phaser.new();
@Overload Java_util_concurrent_Phaser Java_util_concurrent_Phaser.new(int p0);
@Overload Java_util_concurrent_Phaser Java_util_concurrent_Phaser.new(Java_util_concurrent_Phaser p0);
@Overload Java_util_concurrent_Phaser Java_util_concurrent_Phaser.new(Java_util_concurrent_Phaser p0, int p1);
/* class java.util.concurrent.PriorityBlockingQueue */
class Java_util_concurrent_PriorityBlockingQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload Java_util_Comparator comparator();
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object take();
}
@Overload Java_util_concurrent_PriorityBlockingQueue Java_util_concurrent_PriorityBlockingQueue.new();
@Overload Java_util_concurrent_PriorityBlockingQueue Java_util_concurrent_PriorityBlockingQueue.new(int p0);
@Overload Java_util_concurrent_PriorityBlockingQueue Java_util_concurrent_PriorityBlockingQueue.new(int p0, Java_util_Comparator p1);
@Overload Java_util_concurrent_PriorityBlockingQueue Java_util_concurrent_PriorityBlockingQueue.new(Java_util_Collection p0);
/* class java.util.concurrent.RecursiveAction */
class Java_util_concurrent_RecursiveAction extends Java_util_concurrent_ForkJoinTask {
}
Java_util_concurrent_RecursiveAction Java_util_concurrent_RecursiveAction.new();
/* class java.util.concurrent.RecursiveTask */
class Java_util_concurrent_RecursiveTask extends Java_util_concurrent_ForkJoinTask {
}
Java_util_concurrent_RecursiveTask Java_util_concurrent_RecursiveTask.new();
/* class java.util.concurrent.RejectedExecutionException */
class Java_util_concurrent_RejectedExecutionException extends Java_lang_RuntimeException {
}
@Overload Java_util_concurrent_RejectedExecutionException Java_util_concurrent_RejectedExecutionException.new();
@Overload Java_util_concurrent_RejectedExecutionException Java_util_concurrent_RejectedExecutionException.new(String p0);
@Overload Java_util_concurrent_RejectedExecutionException Java_util_concurrent_RejectedExecutionException.new(String p0, Java_lang_Throwable p1);
@Overload Java_util_concurrent_RejectedExecutionException Java_util_concurrent_RejectedExecutionException.new(Java_lang_Throwable p0);
/* interface java.util.concurrent.RejectedExecutionHandler */
class Java_util_concurrent_RejectedExecutionHandler {
	/*-- Method --*/
	@Virtual @Overload void rejectedExecution(Java_lang_Runnable p0, Java_util_concurrent_ThreadPoolExecutor p1);
}
/* interface java.util.concurrent.RunnableFuture */
class Java_util_concurrent_RunnableFuture {
	/*-- Method --*/
	@Virtual @Overload void run();
}
/* interface java.util.concurrent.RunnableScheduledFuture */
class Java_util_concurrent_RunnableScheduledFuture {
	/*-- Method --*/
	@Virtual @Overload boolean isPeriodic();
}
/* interface java.util.concurrent.ScheduledExecutorService */
class Java_util_concurrent_ScheduledExecutorService {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_ScheduledFuture schedule(Java_lang_Runnable p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture schedule(Java_util_concurrent_Callable p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture scheduleAtFixedRate(Java_lang_Runnable p0, long p1, long p2, Java_util_concurrent_TimeUnit p3);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture scheduleWithFixedDelay(Java_lang_Runnable p0, long p1, long p2, Java_util_concurrent_TimeUnit p3);
}
/* interface java.util.concurrent.ScheduledFuture */
class Java_util_concurrent_ScheduledFuture {
}
/* class java.util.concurrent.ScheduledThreadPoolExecutor */
class Java_util_concurrent_ScheduledThreadPoolExecutor extends Java_util_concurrent_ThreadPoolExecutor {
	/*-- Method --*/
	@Virtual @Overload boolean getContinueExistingPeriodicTasksAfterShutdownPolicy();
	@Virtual @Overload boolean getExecuteExistingDelayedTasksAfterShutdownPolicy();
	@Virtual @Overload boolean getRemoveOnCancelPolicy();
	@Virtual @Overload Java_util_concurrent_ScheduledFuture schedule(Java_lang_Runnable p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture schedule(Java_util_concurrent_Callable p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture scheduleAtFixedRate(Java_lang_Runnable p0, long p1, long p2, Java_util_concurrent_TimeUnit p3);
	@Virtual @Overload Java_util_concurrent_ScheduledFuture scheduleWithFixedDelay(Java_lang_Runnable p0, long p1, long p2, Java_util_concurrent_TimeUnit p3);
	@Virtual @Overload void setContinueExistingPeriodicTasksAfterShutdownPolicy(boolean p0);
	@Virtual @Overload void setExecuteExistingDelayedTasksAfterShutdownPolicy(boolean p0);
	@Virtual @Overload void setRemoveOnCancelPolicy(boolean p0);
}
@Overload Java_util_concurrent_ScheduledThreadPoolExecutor Java_util_concurrent_ScheduledThreadPoolExecutor.new(int p0);
@Overload Java_util_concurrent_ScheduledThreadPoolExecutor Java_util_concurrent_ScheduledThreadPoolExecutor.new(int p0, Java_util_concurrent_ThreadFactory p1);
@Overload Java_util_concurrent_ScheduledThreadPoolExecutor Java_util_concurrent_ScheduledThreadPoolExecutor.new(int p0, Java_util_concurrent_RejectedExecutionHandler p1);
@Overload Java_util_concurrent_ScheduledThreadPoolExecutor Java_util_concurrent_ScheduledThreadPoolExecutor.new(int p0, Java_util_concurrent_ThreadFactory p1, Java_util_concurrent_RejectedExecutionHandler p2);
/* class java.util.concurrent.Semaphore */
class Java_util_concurrent_Semaphore {
	/*-- Method --*/
	@Virtual @Overload void acquire();
	@Virtual @Overload void acquire(int p0);
	@Virtual @Overload void acquireUninterruptibly();
	@Virtual @Overload void acquireUninterruptibly(int p0);
	@Virtual @Overload int availablePermits();
	@Virtual @Overload int drainPermits();
	@Virtual @Overload int getQueueLength();
	@Virtual @Overload boolean hasQueuedThreads();
	@Virtual @Overload boolean isFair();
	@Virtual @Overload void release();
	@Virtual @Overload void release(int p0);
	@Virtual @Overload String toString();
	@Virtual @Overload boolean tryAcquire();
	@Virtual @Overload boolean tryAcquire(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload boolean tryAcquire(int p0);
	@Virtual @Overload boolean tryAcquire(int p0, long p1, Java_util_concurrent_TimeUnit p2);
}
@Overload Java_util_concurrent_Semaphore Java_util_concurrent_Semaphore.new(int p0);
@Overload Java_util_concurrent_Semaphore Java_util_concurrent_Semaphore.new(int p0, boolean p1);
/* class java.util.concurrent.SynchronousQueue */
class Java_util_concurrent_SynchronousQueue extends Java_util_AbstractQueue {
	/*-- Method --*/
	@Virtual @Overload int drainTo(Java_util_Collection p0);
	@Virtual @Overload int drainTo(Java_util_Collection p0, int p1);
	@Virtual @Overload boolean offer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
	@Virtual @Overload Object poll(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void put(Object p0);
	@Virtual @Overload int remainingCapacity();
	@Virtual @Overload Object take();
}
@Overload Java_util_concurrent_SynchronousQueue Java_util_concurrent_SynchronousQueue.new();
@Overload Java_util_concurrent_SynchronousQueue Java_util_concurrent_SynchronousQueue.new(boolean p0);
/* interface java.util.concurrent.ThreadFactory */
class Java_util_concurrent_ThreadFactory {
	/*-- Method --*/
	@Virtual @Overload Java_lang_Thread newThread(Java_lang_Runnable p0);
}
/* class java.util.concurrent.ThreadLocalRandom */
class Java_util_concurrent_ThreadLocalRandom extends Java_util_Random {
	/*-- Method --*/
	@Virtual @Overload Java_util_concurrent_ThreadLocalRandom current();
	@Virtual @Overload double nextDouble(double p0);
	@Virtual @Overload double nextDouble(double p0, double p1);
	@Virtual @Overload int nextInt(int p0, int p1);
	@Virtual @Overload long nextLong(long p0);
	@Virtual @Overload long nextLong(long p0, long p1);
}
/* class java.util.concurrent.ThreadPoolExecutor */
class Java_util_concurrent_ThreadPoolExecutor extends Java_util_concurrent_AbstractExecutorService {
	/*-- Method --*/
	@Virtual @Overload void allowCoreThreadTimeOut(boolean p0);
	@Virtual @Overload boolean allowsCoreThreadTimeOut();
	@Virtual @Overload int getActiveCount();
	@Virtual @Overload long getCompletedTaskCount();
	@Virtual @Overload int getCorePoolSize();
	@Virtual @Overload long getKeepAliveTime(Java_util_concurrent_TimeUnit p0);
	@Virtual @Overload int getLargestPoolSize();
	@Virtual @Overload int getMaximumPoolSize();
	@Virtual @Overload int getPoolSize();
	@Virtual @Overload Java_util_concurrent_BlockingQueue getQueue();
	@Virtual @Overload Java_util_concurrent_RejectedExecutionHandler getRejectedExecutionHandler();
	@Virtual @Overload long getTaskCount();
	@Virtual @Overload Java_util_concurrent_ThreadFactory getThreadFactory();
	@Virtual @Overload boolean isTerminating();
	@Virtual @Overload int prestartAllCoreThreads();
	@Virtual @Overload boolean prestartCoreThread();
	@Virtual @Overload void purge();
	@Virtual @Overload boolean remove(Java_lang_Runnable p0);
	@Virtual @Overload void setCorePoolSize(int p0);
	@Virtual @Overload void setKeepAliveTime(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void setMaximumPoolSize(int p0);
	@Virtual @Overload void setRejectedExecutionHandler(Java_util_concurrent_RejectedExecutionHandler p0);
	@Virtual @Overload void setThreadFactory(Java_util_concurrent_ThreadFactory p0);
}
@Overload Java_util_concurrent_ThreadPoolExecutor Java_util_concurrent_ThreadPoolExecutor.new(int p0, int p1, long p2, Java_util_concurrent_TimeUnit p3, Java_util_concurrent_BlockingQueue p4);
@Overload Java_util_concurrent_ThreadPoolExecutor Java_util_concurrent_ThreadPoolExecutor.new(int p0, int p1, long p2, Java_util_concurrent_TimeUnit p3, Java_util_concurrent_BlockingQueue p4, Java_util_concurrent_ThreadFactory p5);
@Overload Java_util_concurrent_ThreadPoolExecutor Java_util_concurrent_ThreadPoolExecutor.new(int p0, int p1, long p2, Java_util_concurrent_TimeUnit p3, Java_util_concurrent_BlockingQueue p4, Java_util_concurrent_RejectedExecutionHandler p5);
@Overload Java_util_concurrent_ThreadPoolExecutor Java_util_concurrent_ThreadPoolExecutor.new(int p0, int p1, long p2, Java_util_concurrent_TimeUnit p3, Java_util_concurrent_BlockingQueue p4, Java_util_concurrent_ThreadFactory p5, Java_util_concurrent_RejectedExecutionHandler p6);
/* class java.util.concurrent.TimeUnit */
class Java_util_concurrent_TimeUnit extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload long convert(long p0, Java_util_concurrent_TimeUnit p1);
	@Virtual @Overload void sleep(long p0);
	@Virtual @Overload void timedJoin(Java_lang_Thread p0, long p1);
	@Virtual @Overload void timedWait(Object p0, long p1);
	@Virtual @Overload long toDays(long p0);
	@Virtual @Overload long toHours(long p0);
	@Virtual @Overload long toMicros(long p0);
	@Virtual @Overload long toMillis(long p0);
	@Virtual @Overload long toMinutes(long p0);
	@Virtual @Overload long toNanos(long p0);
	@Virtual @Overload long toSeconds(long p0);
	@Virtual @Overload Java_util_concurrent_TimeUnit valueOf(String p0);
	@Virtual @Overload Java_util_concurrent_TimeUnit[] values();
}
/* class java.util.concurrent.TimeoutException */
class Java_util_concurrent_TimeoutException extends Java_lang_Exception {
}
@Overload Java_util_concurrent_TimeoutException Java_util_concurrent_TimeoutException.new();
@Overload Java_util_concurrent_TimeoutException Java_util_concurrent_TimeoutException.new(String p0);
/* interface java.util.concurrent.TransferQueue */
class Java_util_concurrent_TransferQueue {
	/*-- Method --*/
	@Virtual @Overload int getWaitingConsumerCount();
	@Virtual @Overload boolean hasWaitingConsumer();
	@Virtual @Overload void transfer(Object p0);
	@Virtual @Overload boolean tryTransfer(Object p0);
	@Virtual @Overload boolean tryTransfer(Object p0, long p1, Java_util_concurrent_TimeUnit p2);
}

/*------------------------------------------------------------*/
/* short names */
AbstractExecutorService = Java_util_concurrent_AbstractExecutorService
ArrayBlockingQueue = Java_util_concurrent_ArrayBlockingQueue
BlockingDeque = Java_util_concurrent_BlockingDeque
BlockingQueue = Java_util_concurrent_BlockingQueue
BrokenBarrierException = Java_util_concurrent_BrokenBarrierException
Callable = Java_util_concurrent_Callable
CancellationException = Java_util_concurrent_CancellationException
CompletionService = Java_util_concurrent_CompletionService
ConcurrentHashMap = Java_util_concurrent_ConcurrentHashMap
ConcurrentLinkedDeque = Java_util_concurrent_ConcurrentLinkedDeque
ConcurrentLinkedQueue = Java_util_concurrent_ConcurrentLinkedQueue
ConcurrentMap = Java_util_concurrent_ConcurrentMap
ConcurrentNavigableMap = Java_util_concurrent_ConcurrentNavigableMap
ConcurrentSkipListMap = Java_util_concurrent_ConcurrentSkipListMap
ConcurrentSkipListSet = Java_util_concurrent_ConcurrentSkipListSet
CopyOnWriteArrayList = Java_util_concurrent_CopyOnWriteArrayList
CopyOnWriteArraySet = Java_util_concurrent_CopyOnWriteArraySet
CountDownLatch = Java_util_concurrent_CountDownLatch
CyclicBarrier = Java_util_concurrent_CyclicBarrier
DelayQueue = Java_util_concurrent_DelayQueue
Delayed = Java_util_concurrent_Delayed
Exchanger = Java_util_concurrent_Exchanger
ExecutionException = Java_util_concurrent_ExecutionException
Executor = Java_util_concurrent_Executor
ExecutorCompletionService = Java_util_concurrent_ExecutorCompletionService
ExecutorService = Java_util_concurrent_ExecutorService
Executors = Java_util_concurrent_Executors
ForkJoinPool = Java_util_concurrent_ForkJoinPool
ForkJoinTask = Java_util_concurrent_ForkJoinTask
ForkJoinWorkerThread = Java_util_concurrent_ForkJoinWorkerThread
Future = Java_util_concurrent_Future
FutureTask = Java_util_concurrent_FutureTask
LinkedBlockingDeque = Java_util_concurrent_LinkedBlockingDeque
LinkedBlockingQueue = Java_util_concurrent_LinkedBlockingQueue
LinkedTransferQueue = Java_util_concurrent_LinkedTransferQueue
Phaser = Java_util_concurrent_Phaser
PriorityBlockingQueue = Java_util_concurrent_PriorityBlockingQueue
RecursiveAction = Java_util_concurrent_RecursiveAction
RecursiveTask = Java_util_concurrent_RecursiveTask
RejectedExecutionException = Java_util_concurrent_RejectedExecutionException
RejectedExecutionHandler = Java_util_concurrent_RejectedExecutionHandler
RunnableFuture = Java_util_concurrent_RunnableFuture
RunnableScheduledFuture = Java_util_concurrent_RunnableScheduledFuture
ScheduledExecutorService = Java_util_concurrent_ScheduledExecutorService
ScheduledFuture = Java_util_concurrent_ScheduledFuture
ScheduledThreadPoolExecutor = Java_util_concurrent_ScheduledThreadPoolExecutor
Semaphore = Java_util_concurrent_Semaphore
SynchronousQueue = Java_util_concurrent_SynchronousQueue
ThreadFactory = Java_util_concurrent_ThreadFactory
ThreadLocalRandom = Java_util_concurrent_ThreadLocalRandom
ThreadPoolExecutor = Java_util_concurrent_ThreadPoolExecutor
TimeUnit = Java_util_concurrent_TimeUnit
TimeoutException = Java_util_concurrent_TimeoutException
TransferQueue = Java_util_concurrent_TransferQueue
