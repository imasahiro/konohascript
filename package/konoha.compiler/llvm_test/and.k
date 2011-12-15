using konoha.compiler.*;

boolean and_1(boolean b1, boolean b2, boolean b3, boolean b4) {
    return b1 && b2;
}
boolean and_2(boolean b1, boolean b2, boolean b3, boolean b4) {
    return b1 && b2 && b3;
}
boolean and_3(boolean b1, boolean b2, boolean b3, boolean b4) {
    return b1 && (b2 && b3);
}
boolean and_4(boolean b1, boolean b2, boolean b3, boolean b4) {
    return b1 && (b2 && b3) && b4;
}

