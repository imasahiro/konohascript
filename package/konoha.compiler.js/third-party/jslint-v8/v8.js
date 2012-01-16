
for (i = 0; i < JSLINT.errors.length; i += 1) {
    e = JSLINT.errors[i];
    if (e) {
        print('Lint at line ' + e.line + ' character ' +
                e.character + ': ' + e.reason);
    }
}
