/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Yutaro Hiraoka  twitter: @utrhira
 ***************************************************************************/

String[] : (String s) {
    return s.split(" ");
}

assure "ArrayCastForeach" {
    count = 0;
    strs = (String[])"1,2,3";
    foreach (s in strs) {
        print s;
        count++;
    }
    assert count == 3;

    count = 0;
    foreach (s in (String[])"1 2 3") {
        print s;
        count++;
    }
    assert count == 3;
}
