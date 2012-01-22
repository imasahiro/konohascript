void main (String[] args) {
    String f1 = args[0];
    String f2 = args[1];
    ins1 = new InputStream(f1);
    ins2 = new InputStream(f2);
    String[][] a1 = [];
    String[][] a2 = [];
    foreach (String line in ins1) {
        a1.add(line.split(","));
    }
    foreach (String line in ins2) {
        a2.add(line.split(","));
    }
    //print a1[0];
    for (int i=1; i < a1.size; i++) {
        //print a1[i];
        int size = a1[i].size - 1;
        for (int j=3; j < size; j++) {
            a1[i].add(a2[i][j]);
        }
        for (int j=3; j < size; j++) {
            float v1 = (float)a1[i][j];
            float v2 = (float)a2[i][j];
            float diff = (v1 - v2) / v1 * 100;
            //print v1, v2, diff;
            a1[i].add((String)diff);
        }
    }
    for (int i=0; i < a1.size; i++) {
        for (int j=0; j < a1[i].size; j++) {
            if (!a1[i][j] == "") {
                OUT.print(a1[i][j] + ",");
            }
        }
        OUT.println();
    }
}
