/*
 * CreateTree
 * http://www.cs.cmu.edu/~spoons/gc/benchmarks.html
 */
include "_bench.k";

class Node {
    public Node left, right;
    public int i = 0, j = 0;
    public Node(Node l, Node r) {
        left = l;
        right = r;
    }
}


PRINT = false;
public class GCBench extends BenchMarkTask {

    public const int kStretchTreeDepth    = 18;  // about 16Mb
    public const int kLongLivedTreeDepth  = 16;  // about 4Mb
    public const int kArraySize  = 500000;  // about 4Mb
    public const int kMinTreeDepth = 4;
    public const int kMaxTreeDepth = 16;

    GCBench() {
        this.name = "tree";
    }
    // Nodes used by a tree of a given size
    static int treeSize(int i) {
        return ((1 << (i + 1)) - 1);
    }

    // Number of iterations to use for a given tree depth
    static int numIters(int i) {
        return 2 * treeSize(kStretchTreeDepth) / treeSize(i);
    }

    // Build tree top down, assigning to older objects. 
    static void populate(int iDepth, Node thisNode) {
        if (iDepth<=0) {
            return;
        } else {
            iDepth--;
            thisNode.left  = new Node();
            thisNode.right = new Node();
            populate (iDepth, thisNode.left);
            populate (iDepth, thisNode.right);
        }
    }

    // Build tree bottom-up
    static Node makeTree(int iDepth) {
        if (iDepth<=0) {
            return new Node();
        } else {
            return new Node(makeTree(iDepth-1), makeTree(iDepth-1));
        }
    }

    static void printDiagnostics() {
        //if (PRINT) {
        //    int lTotalMemory = System.getTotalMemory();
        //    System.out.println(" Total memory available=" + lTotalMemory + " bytes");
        //}
    }

    static void timeConstruction(int depth) {
        double tStart, tFinish;
        int    iNumIters = numIters(depth);
        Node   tempTree;

        if (PRINT) {
            System.out.println("Creating " + iNumIters + " trees of depth " + depth);
        }
        tStart = System.getTime();
        for (int i = 0; i < iNumIters; ++i) {
            tempTree = new Node();
            populate(depth, tempTree);
            tempTree = null;
        }
        tFinish = System.getTime();
        if (PRINT) {
            System.out.println("\tTop down construction took " + (tFinish - tStart) + "secs");
        }
        tStart = System.getTime();
        for (int i = 0; i < iNumIters; ++i) {
            tempTree = makeTree(depth);
            tempTree = null;
        }
        tFinish = System.getTime();
        if (PRINT) {
            System.out.println("\tBottom up construction took " + (tFinish - tStart) + "secs");
        }

    }

    @Override void run() {
        Node   longLivedTree;
        Node   tempTree;
        double tStart, tFinish;
        double tElapsed;

        if (PRINT) {
            System.out.println(
                    " Stretching memory with a binary tree of depth "
                    + kStretchTreeDepth);
        }
        printDiagnostics();
        tStart = System.getTime();

        // Stretch the memory space quickly
        tempTree = makeTree(kStretchTreeDepth);
        tempTree = null;

        // Create a long lived objects
        if (PRINT) {
            System.out.println(
                    " Creating a long-lived binary tree of depth " +
                    kLongLivedTreeDepth);
        }
        longLivedTree = new Node();
        populate(kLongLivedTreeDepth, longLivedTree);

        // Create long-lived array, filling half of it
        if (PRINT) {
            System.out.println(
                    " Creating a long-lived array of "
                    + kArraySize + " doubles");
        }
        double[] array = new double[kArraySize];
        for (int i = 1; i < kArraySize/2; ++i) {
            array[i] = 1.0/i;
        }
        printDiagnostics();

        for (int d = kMinTreeDepth; d <= kMaxTreeDepth; d += 2) {
            timeConstruction(d);
        }

        if (longLivedTree == null || array[1000] != 1.0/1000) {
            if (PRINT) {
                System.out.println("Failed");
                // fake reference to LongLivedTree
                // and array
                // to keep them from being optimized away
            }
        }

        tFinish = System.getTime();
        tElapsed = tFinish-tStart;
        printDiagnostics();
        if (PRINT) {
            System.out.println("Completed in " + tElapsed + "s.");
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new GCBench();
    bm.run();
}
