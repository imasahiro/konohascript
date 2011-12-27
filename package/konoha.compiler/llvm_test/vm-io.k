/*
 * io write
 */

K=10;
M=K*K;
G=M*K;

String s(int l) {
    String ret = "";
    if(l/K == 0) {
        ret = l + "";
    } else if(l/M == 0) {
        ret = l/K + "k";
    } else if(l/G == 0) {
        ret = l/M + "m";
    } else {
        ret = l/G + "g";
    }
    return ret;

}

void main (String[] args) {
    int[] len = [1*K, 2*K, 5*K, 1*M, 2*M, 5*M, 1*G];
    foreach(int n in len) {
        String f = s(n);
        print f;
        OutputStream ous = new OutputStream("data." + f + ".txt", "w");
        for (int i=0; i < n; i++) {
            ous <<< "a";
        }
        ous.flush();
        ous.close();
    }
}

