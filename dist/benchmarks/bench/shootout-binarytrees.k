/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/
   contributed by Kimio Kuramitsu
*/

include "_bench.k";
MINDEPTH = 4;
N=20;

class TreeNode {
	TreeNode left, right;
	int item;
	
	TreeNode(TreeNode left, TreeNode right, int item) {
		_left = left;
		_right = right;
		_item = item;
	}
	
	int itemCheck(){
		// if necessary deallocate here
		if(_left == null) return _item;
		return _item + _left.itemCheck() - _right.itemCheck();
	}
}

TreeNode bottomUpTree(int item, int depth){
	if (depth > 0){
		return new TreeNode(bottomUpTree(2*item-1, depth-1), bottomUpTree(2*item, depth-1), item);
	}
	else {
		return new TreeNode(null, null, item);
	}
}

class Binarytrees extends BenchMarkTask {
	Binarytrees() {
		this.name = "Binarytrees";
	}
	@Override void run() {
		int n = N;
		int maxDepth = (MINDEPTH + 2 > n) ? MINDEPTH + 2 : n;
		int stretchDepth = maxDepth + 1;
		int check = bottomUpTree(0,stretchDepth).itemCheck();
		OUT.println("stretch tree of depth " + stretchDepth + "\t check: " + check);
		TreeNode longLivedTree = bottomUpTree(0,maxDepth);
		for (int depth = MINDEPTH; depth <= maxDepth; depth += 2) {
			int iterations = 1 << (maxDepth - depth + MINDEPTH);
			check = 0;
			for (int i=1; i<= iterations; i++){
				check += bottomUpTree(i, depth).itemCheck();
				check += bottomUpTree(-i, depth).itemCheck();
			}
			OUT.println((iterations*2) + "\t trees of depth " + depth + "\t check: " + check);
		}
		OUT.println("long lived tree of depth " + maxDepth + "\t check: "+ longLivedTree.itemCheck());
	}
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new Binarytrees());
    bm.run();
}

