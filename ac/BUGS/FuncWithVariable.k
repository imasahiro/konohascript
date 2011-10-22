/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Yutaro Hiraoka  twitter: @utrhira
 ***************************************************************************/

int g_count = 0;
def makeGlobalCounter() {
    return function() {
        g_count += 1;
        return g_count;
    };
}

def makeLocalCounter() {
    int count = 0;
    return function() {
        count += 1;
        return count;
    };
}

assure "FuncGlobalVariable" {
    c = makeGlobalCounter();
    assert typeof(c) == Func<void=>int>;
    assert c() == 1;
}

assure "FuncLocalVariable" {
    c = makeLocalCounter();
    assert typeof(c) == Func<void=>int>;
    assert c() == 1;
}
