/**
 * quicksort
 */
include "_bench.k";
N=1024 * 1024 * 2;
/*
 * The Original Code is 
 * Copyright (C) 2002 Lorenzo Allegrucci (lenstra@tiscalinet.it)
 * Licensed under the GPL
 *
 * Ported to Konoha by Masahiro Ide.
 */

VERBOSE = false;

/**
 * quick_sort - Sort in the range [l, r]
 */
void quick_sort(String[] a, int l, int r)
{
    String p, tmp, min, max;

    int i = l;
    int j = r;
    int m = (l + r) / 2;

    if (a[m] >= a[l]) {
        max = a[m];
        min = a[l];
    } else {
        max = a[l];
        min = a[m];
    }

    if (a[r] >= max) {
        p = max;
    }
    else {
        if (a[r] >= min)
            p = a[r];
        else
            p = min;
    }

    do {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (l < j) {
        quick_sort(a, l, j);
    }
    if (i < r) {
        quick_sort(a, i, r);
    }
}


void do_qsort(int n, int s)
{
    int errors = 0;
    int i;
    String[] a = new String[n];

    System.setRandomSeed(s);
    if (VERBOSE)
        OUT.println("seed = " + s);

    for (i = 0; i < n; i++) {
        a[i] = (String) Int.random();
    }

    if (VERBOSE) {
        OUT.println("sorting... ");
    }
    quick_sort(a, 0, n - 1);
    if (VERBOSE) {
        OUT.println("done.");
    }

    if (VERBOSE) {
        OUT.println("verify... ");
    }
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            errors++;
            ERR.println("ERROR: i = "+i);
        }
    }
    if (VERBOSE) {
        OUT.println("done.");
    }

    if (errors > 0) {
        OUT.println(" *** WARNING ***  " + errors + " errors.");
    }
}

class Sort extends BenchMarkTask {
    Sort() {
        this.name = "quicksort";
    }
    @Override void run() {
        int nr_elems = N;
        int seed     = 140175100;
        //print nr_elems, seed;
        do_qsort(nr_elems, seed);
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Sort();
    bm.run();
}
