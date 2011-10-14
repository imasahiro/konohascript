/* The Great Computer Language Shootout
   http://shootout.alioth.debian.org/
   contributed by Kimio Kuramitsu
*/

using konoha.thread.*;

MINDEPTH = 4;

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

void binarytree_main(int id, int n) {
	int maxDepth = (MINDEPTH + 2 > n) ? MINDEPTH + 2 : n;
	int stretchDepth = maxDepth + 1;
	int check = bottomUpTree(0,stretchDepth).itemCheck();
	OUT <<< "[" <<< id <<< "] stretch tree of depth " <<< stretchDepth <<< "\t check: " <<< check <<< EOL;
	TreeNode longLivedTree = bottomUpTree(0,maxDepth);
	for (int depth = MINDEPTH; depth <= maxDepth; depth += 2) {
		int iterations = 1 << (maxDepth - depth + MINDEPTH);
		check = 0;
		for (i=1; i<= iterations; i++){
			check += bottomUpTree(i, depth).itemCheck();
			check += bottomUpTree(-i, depth).itemCheck();
		}
		OUT <<< "[" <<< id <<< "] " <<< (iterations*2) + "\t trees of depth " + depth + "\t check: " + check <<< EOL;
	}
	OUT <<< "[" <<< id <<< "] long lived tree of depth " + maxDepth + "\t check: "+ longLivedTree.itemCheck() <<< EOL;
}

void main(String[] args) {
	n = 20;
	if (args.size > 0) n = (int)args[0];

	t = 4;
	if (args.size > 1) t = (int)args[1];
	OUT <<< "thread count = " <<< t <<< EOL;

	for(i=0; i<t; i++) {
		Thread.spawn(binarytree_main, [i, n]);
	}
}

