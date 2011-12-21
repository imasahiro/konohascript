
function __Object__(obj) {
    this.konohaclass = "konoha.Object";
    this.obj = obj;

}
__Object__.prototype.getClass = function() {
    return new __Class__(this.konohaclass);
}
__Object__.prototype.__toString = function() {
    return this.obj;
}


__Class__.prototype = new __Object__();
function __Class__(obj) {
    this.konohaclass = "konoha.Class";
    this.obj = obj;
}
/* OutputStream */
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
            if (arguments[i].obj) {
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
            document.write(arguments[i].obj);
            if (arguments[i].obj) {
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
                if (arguments[i].obj) {
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
                if (arguments[i].obj) {
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
function __Map__(obj) {
    this.konohaclass = "konoha.Map";
    this.obj = obj = {};
    this.new = function(init) {
        return this;
    }
    this.set = function(key, value) {
        this.obj[key.obj] = value;
    }
    this.get = function(key) {
        var obj = this.obj[key.obj];
        if (obj == null) {
            return 0;
        }
        return obj;
    }
    this.remove = function(key) {
        delete this.obj[key.obj];
    }
    this.keys = function() {
        var res = [];
        for(var elem in this.obj) {
            res.push(elem);
        }
        return res;
    }
    this.getSize = function() {
        var res = 0;
        for(var elem in this.obj) {
            res ++;
        }
        return res;
    }
}


/* Array */
function __Array__(obj) {
    this.konohaclass = "konoha.Array";
    if (obj != null) {
        this.obj = obj;
        this.capacity = obj.length;
    }
    this.new_ARRAY = function(initCapacity) {
        this.obj = new Array(initCapacity);
        for(var i = 0; i < initCapacity; i++) {
            this.obj[i] = 0;
        }
        this.capacity = initCapacity;
        return this;
    }

    this.new_LIST = function() {
        this.capacity = arguments.length;
        this.obj = new Array(this.capacity);
        for (var i = 0; i < arguments.length; i++) {
            this.obj[i] = arguments[i];
        }
        return this;
    }
    this.get = function(n) {
        if (n >= 0 && n < this.capacity) {
            return this.obj[n];
        } else {
            throw('Script!!');
        }
    }
    this.set = function(n, v) {
        if (n >= 0 && n < this.capacity) {
            this.obj[n] = v;
        } else {
            throw('Script!!');
        }
    }
    this.getSize = function() {
        return this.capacity;
    }
    this.add = function(v) {
        this.capacity++;
        this.obj.push(v);
    }
    this.remove = function(n) {
        if (n >= 0 && n < this.capacity) {
            this.obj.spice(n, n+1);
            this.capacity--;
        } else {
            throw('Script!!');
        }
    }
    this.__toString = function() {
        var res = '[';
        for(var i = 0; i < this.obj.length; i++) {
            res += this.obj[i].__toString();
            if (i != this.obj.length-1) {
                res += ', ';
            }
        }
        res += ']';
        return res;
    }
}

/* String */
__String__.prototype = new __Object__();
function __String__(obj) {
    this.konohaclass = "konoha.String";
    this.obj = obj;
    this.equals = function(str) {
        return this.obj == str.obj;
    }
    this.startsWith = function(str) {
        return this.obj.indexOf(str.obj) == 0;
    }
    this.endsWith = function(str) {
        var correctIndex = this.obj.length - str.obj.length;
        return this.obj.lastIndexOf(str.obj) == correctIndex;
    }
    this.concat = function() {
        var res = this.obj;
        for (var i = 0; i < arguments.length; i++) {
            if (arguments[i].obj) {
                res += arguments[i].obj;
            } else {
                res += arguments[i];
            }
        }
        return new __String__(res);
    }
    this.indexOf = function(str) {
        return this.obj.indexOf(str.obj);
    }
    this.lastIndexOf = function(str) {
        return this.obj.lastIndexOf(str.obj);
    }
    this.match = function (re) {
        var list = this.obj.match(re.obj);
        var res = [];
        for (element in list) {
            res.push(new __String__(element));
        }
        return new __Array__(res);
    }
    this.split = function(re) {
        var list = this.obj.split(re.obj);
        var res = [];
        for (element in list) {
            res.push(new __String__(element));
        }
        return new __Array__(res);
    }
    this.search = function(re) {
        return this.obj.search(re.obj);
    }
    this.replace = function(source, target) {
        return new __String__(this.obj.replace(source.obj, target.obj));
    }
    this.getSize = function() {
        return this.obj.length;
    }
}

/* Regex */
__Regex__.prototype = new __Object__();
function __Regex__(obj) {
    this.konohaclass = "konoha.Regex";
    this.obj = obj;
    this.new = function(pattern, option) {
        this.obj = new RegExp(pattern.obj, option.obj);
        return this;
    }
}
/* Number */
__Number__.prototype = new __Object__();
function __Number__(obj) {
    this.konohaclass = "konoha.Number";
    this.obj = obj;
}

/* Int */
__Int__.prototype = new __Number__();
function __Int__(obj) {
    this.konohaclass = "konoha.Int";
    this.obj = obj;
}

__Int__.random = function() {
    return Math.random();
}
__Int__.format = function(i, format) {
    switch (format.obj) {
        case "%x":
            return new __String__(i.toString(16));
        case "%02x":
            var res = '00' + i.toString(16);
            return new __String__(res.substring(res.length-2, res.length));
    }
}

/* Float */
function __Float__(obj) {
    this.konohaclass = "konoha.Int";
    this.obj = obj;
}

__Float__.random = function() {
    return Math.random();
}
