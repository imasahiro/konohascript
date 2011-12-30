
function __Object__(rawptr) {
    this.konohaclass = "konoha.Object";
    this.rawptr = rawptr;

}
__Object__.prototype.getClass = function() {
    return new __Class__(this.konohaclass);
}
__Object__.prototype.__toString = function() {
    return this.rawptr;
}


__Class__.prototype = new __Object__();
function __Class__(rawptr) {
    this.konohaclass = "konoha.Class";
    this.rawptr = rawptr;
}
/* OutputStream */
__OutputStream__.prototype = new __Object__();
function __OutputStream__(isCwb) {
    this.konohaclass = "konoha.OutputStream";
    this.cwb = "";
    this.println = function() {
        document.write(this.cwb);
        this.cwb = "";
        for (var i=0; i < arguments.length; i++) {
            if (arguments[i].replace) {
                arguments[i] = arguments[i].replace("\n", "<br>\n");
            }
            if (arguments[i].rawptr) {
                document.write(arguments[i].__toString());
            } else {
                document.write(arguments[i]);
            }
        }
        document.write("<br>");
    }
    this.print = function() {
        document.write(this.cwb);
        this.cwb = "";
        for (var i=0; i < arguments.length; i++) {
            if (arguments[i].replace) {
                arguments[i] = arguments[i].replace("\n", "<br>\n");
            }
            document.write(arguments[i].rawptr);
            if (arguments[i].rawptr) {
                document.write(arguments[i].__toString());
            } else {
                document.write(arguments[i]);
            }

        }
    }

    if (!isCwb) {
        this.send = function() {
            document.write(this.cwb);
            this.cwb = "";
            for (var i = 0; i < arguments.length; i++) {
                if (arguments[i].replace) {
                    arguments[i] = arguments[i].replace("\n", "<br>\n");
                }
                if (arguments[i].rawptr) {
                    document.write(arguments[i].__toString());
                } else {
                    document.write(arguments[i]);
                }
            }
        }
    } else {
        this.send = function() {
            for (var i = 0; i < arguments.length; i++) {
                if (arguments[i].replace) {
                    arguments[i] = arguments[i].replace("\n", "<br>\n");
                }
                if (arguments[i].rawptr) {
                    this.cwb += arguments[i].__toString();
                } else {
                    this.cwb += arguments[i];
                }
            }
        }
    }
    this.tostr = function() {
        var res = this.cwb;
        this.cwb = "";
        return new __String__(res);
    }
}

/* System */
__System__.prototype = new __Object__();
function __System__() {
    this.konohaclass = "konoha.System";
}
__System__.getOut = function() {
    os = new __OutputStream__(false);
    return os;
}
__System__.getErr = function() {
    os = new __OutputStream__(false);
    return os;
}

/* Map */
__Map__.prototype = new __Object__();
function __Map__(rawptr) {
    this.konohaclass = "konoha.Map";
    this.rawptr = rawptr = {};
    this.new = function(init) {
        return this;
    }
    this.set = function(key, value) {
        this.rawptr[key.rawptr] = value;
    }
    this.get = function(key) {
        var obj = this.rawptr[key.rawptr];
        if (obj == null) {
            return 0;
        }
        return obj;
    }
    this.remove = function(key) {
        delete this.rawptr[key.rawptr];
    }
    this.keys = function() {
        var res = [];
        for(var elem in this.rawptr) {
            res.push(elem);
        }
        return res;
    }
    this.getSize = function() {
        var res = 0;
        for(var elem in this.rawptr) {
            res ++;
        }
        return res;
    }
}


/* Array */
__Array__.prototype = new __Object__();
function __Array__(rawptr) {
    this.konohaclass = "konoha.Array";
    if (rawptr != null) {
        this.rawptr = rawptr;
        this.capacity = rawptr.length;
    }
    this.new_ARRAY = function(initCapacity) {
        this.rawptr = new Array(initCapacity);
        for(var i = 0; i < initCapacity; i++) {
            this.rawptr[i] = 0;
        }
        this.capacity = initCapacity;
        return this;
    }

    this.new_LIST = function() {
        this.capacity = arguments.length;
        this.rawptr = new Array(this.capacity);
        for (var i = 0; i < arguments.length; i++) {
            this.rawptr[i] = arguments[i];
        }
        return this;
    }
    this.get = function(n) {
        if (n >= 0 && n < this.capacity) {
            return this.rawptr[n];
        } else {
            throw('Script!!');
        }
    }
    this.set = function(n, v) {
        if (n >= 0 && n < this.capacity) {
            this.rawptr[n] = v;
        } else {
            throw('Script!!');
        }
    }
    this.getSize = function() {
        return this.capacity;
    }
    this.add = function(v) {
        this.capacity++;
        this.rawptr.push(v);
    }
    this.remove = function(n) {
        if (n >= 0 && n < this.capacity) {
            this.rawptr.spice(n, n+1);
            this.capacity--;
        } else {
            throw('Script!!');
        }
    }
    this.__toString = function() {
        var res = '[';
        for(var i = 0; i < this.rawptr.length; i++) {
            res += this.rawptr[i].__toString();
            if (i != this.rawptr.length-1) {
                res += ', ';
            }
        }
        res += ']';
        return res;
    }
}
/* Iterator */
__Iterator__.prototype = new __Object__();
function __Iterator__(rawptr) {
    this.rawptr = rawptr;
    this.cur = 0;
    this.capacity = rawptr.getSize();
    this.next = function() {
        if (this.cur == this.capacity) {
            return null;
        } else {
            var res = rawptr.get(this.cur);
            this.cur++;
            return res;
        }
    }
}

/* String */
__String__.prototype = new __Object__();
function __String__(rawptr) {
    this.konohaclass = "konoha.String";
    this.rawptr = rawptr;
    this.equals = function(str) {
        return this.rawptr == str.rawptr;
    }
    this.startsWith = function(str) {
        return this.rawptr.indexOf(str.rawptr) == 0;
    }
    this.endsWith = function(str) {
        var correctIndex = this.rawptr.length - str.rawptr.length;
        return this.rawptr.lastIndexOf(str.rawptr) == correctIndex;
    }
    this.concat = function() {
        var res = this.rawptr;
        for (var i = 0; i < arguments.length; i++) {
            if (arguments[i].rawptr) {
                res += arguments[i].rawptr;
            } else {
                res += arguments[i];
            }
        }
        return new __String__(res);
    }
    this.indexOf = function(str) {
        return this.rawptr.indexOf(str.rawptr);
    }
    this.lastIndexOf = function(str) {
        return this.rawptr.lastIndexOf(str.rawptr);
    }
    this.match = function (re) {
        var list = this.rawptr.match(re.rawptr);
        var res = [];
        for (element in list) {
            res.push(new __String__(element));
        }
        return new __Array__(res);
    }
    this.split = function(re) {
        var list = this.rawptr.split(re.rawptr);
        var res = [];
        for (element in list) {
            res.push(new __String__(element));
        }
        return new __Array__(res);
    }
    this.search = function(re) {
        return this.rawptr.search(re.rawptr);
    }
    this.replace = function(source, target) {
        return new __String__(this.rawptr.replace(source.rawptr, target.rawptr));
    }
    this.getSize = function() {
        return this.rawptr.length;
    }
}

/* Regex */
__Regex__.prototype = new __Object__();
function __Regex__(rawptr) {
    this.konohaclass = "konoha.Regex";
    this.rawptr = rawptr;
    this.new = function(pattern, option) {
        this.rawptr = new RegExp(pattern.rawptr, option.rawptr);
        return this;
    }
}
/* Number */
__Number__.prototype = new __Object__();
function __Number__(rawptr) {
    this.konohaclass = "konoha.Number";
    this.rawptr = rawptr;
}

/* Int */
__Int__.prototype = new __Number__();
function __Int__(rawptr) {
    this.konohaclass = "konoha.Int";
    this.rawptr = rawptr;
}

__Int__.random = function() {
    return Math.random();
}
__Int__.format = function(i, format) {
    switch (format.rawptr) {
        case "%x":
            return new __String__(i.toString(16));
        case "%02x":
            var res = '00' + i.toString(16);
            return new __String__(res.substring(res.length-2, res.length));
    }
}

/* Float */
function __Float__(rawptr) {
    this.konohaclass = "konoha.Int";
    this.rawptr = rawptr;
}

__Float__.random = function() {
    return Math.random();
}
