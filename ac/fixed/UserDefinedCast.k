
class Ball(int weight);
class Cube(int weight);

Ball : (int i) {
    return new Ball(i);
}

int : (Ball b) {
    return b.weight;
}

Cube : (Ball b) {
    return new Cube(b.weight / 10);
}

assure "UserDefinedCast" {
    i = 100;
    b = (Ball)i;
    assert b.weight == i;

    j = (int)new Ball(i);
    assert j == i;

    bl = (Cube)((Ball)i);
    assert bl.weight == i/10;
}
