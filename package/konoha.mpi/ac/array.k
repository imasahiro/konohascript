using konoha.mpi.*;

a = [1,2,3,4,5,6,7,8,9];

assure "Array.reshape" {
    a.reshape([3,3]);
    /*
      [a00, a01, a02]
      [a10, a11, a12]
      [a20, a21, a22]

      [1,2,3]
      [4,5,6]
      [7,8,9]
    */
    assert(a[1,2] == 6);
}

assure "Array.rows" {
    c = a.rows(1, 2);
    /*
      [c00, c01, c02]
      [c10, c11, c12]

      [4,5,6]
      [7,8,9]

      shape:
      [2,3]
    */
    assert(c.shape == [2,3]);
    assert(c[1,0] == 7);
}

assure "Array.cols" {
    d = a.cols(1, 2);
    /*
      [d00, d01]
      [d10, d11]
      [d20, d21]

      [2,3]
      [5,6]
      [8,9]

      shape:
      [3,2]
    */
    assert(d.shape == [3,2]);
    assert(d[1,0] == 5);
}

x = [1,2,3,4,5,6,7,8];
assure "Array.reshape: 3D" {
    x.reshape([2,2,2]);
    /*
      [1,2,
      3,4]
      [5,6,
      7,8]
    */
    assert(x[1,1,1] == 8);
}

y = [1,2,
     3,4,
     5,6,
     7,8,
     9,10,
     11,12,
     13,14,
     15,16];
assure "Array.reshape: 4D" {
    y.reshape([2,2,2,2]);
    /*
      [1,2,
      3,4]
      [5,6,
      7,8]

      [9,10,
      11,12]
      [13,14,
      15,16]
    */
    assert(y[1,1,1,1] == 16);
}

z = [ 1, 2,
      3, 4,
      5, 6,
      7, 8,
      9,10,
     11,12,
     13,14,
     15,16];
z.reshape([8,2]);
assure "Array.cycle" {
    e = z.cycle(2,4);
    /*
      [ 5, 6,
      13,14]
    */
    assert(e.shape == [2,2]);
    assert(e == [5, 6,
                 13, 14]);
}

v = [1,2,3,
     4,5,6,
     7,8,9];
v.reshape([3,3]);
assure "Array.trans" {
    f = v.trans();
    /*
      [1,4,7,
      2,5,8,
      3,6,9]
    */
    assert(f.shape == [3,3]);
    assert(f == [1,4,7,
                 2,5,8,
                 3,6,9]);
}
