var konoha = function() {
}
konoha.Object = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Object.prototype.konohaclass = "konoha.Object";
konoha.Object.prototype.getClass = function() {
    return new Class(this.konohaclass);
}
konoha.Object.prototype.toString = function() {
    return this.rawptr;
}


konoha.Class = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Class.prototype = new konoha.Object();
konoha.Class.konohaclass = "konoha.Class";
/* OutputStream */
konoha.OutputStream = function(isCwb) {
    this.cwb = "";
    this.println = function() {
        document.write(this.cwb);
        this.cwb = "";
        for (var i=0; i < arguments.length; i++) {
            if (arguments[i].replace) {
                arguments[i] = arguments[i].replace("\n", "<br>\n");
            }
            if (arguments[i].rawptr) {
                document.write(arguments[i].toString());
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
                document.write(arguments[i].toString());
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
                    document.write(arguments[i].toString());
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
                    this.cwb += arguments[i].toString();
                } else {
                    this.cwb += arguments[i];
                }
            }
        }
    }
    this.tostr = function() {
        var res = this.cwb;
        this.cwb = "";
        return new konoha.String(res);
    }
}
konoha.OutputStream.prototype = new konoha.Object();
konoha.OutputStream.konohaclass = "konoha.OutputStream";

/* System */
konoha.System = function() {
}
konoha.System.prototype = new konoha.Object();
konoha.System.konohaclass = "konoha.System";
konoha.System.getOut = function() {
    var os = new konoha.OutputStream(false);
    return os;
}
konoha.System.getErr = function() {
    var os = new konoha.OutputStream(false);
    return os;
}

/* Map */
konoha.Map = function(rawptr) {
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
konoha.Map.prototype = new konoha.Object();
konoha.Map.konohaclass = "konoha.Map";


/* Array */
konoha.Array = function(rawptr) {
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
    this.toString = function() {
        var res = '[';
        for(var i = 0; i < this.rawptr.length; i++) {
            res += this.rawptr[i].toString();
            if (i != this.rawptr.length-1) {
                res += ', ';
            }
        }
        res += ']';
        return res;
    }
}
konoha.Array.prototype = new konoha.Object();
konoha.Array.konohaclass = "konoha.Array";
/* Iterator */
konoha.Iterator = function(rawptr) {
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
konoha.Iterator.prototype = new konoha.Object();
konoha.Iterator.konohaclass = "konoha.Iterator";

/* String */
konoha.String = function(rawptr) {
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
        return new konoha.String(res);
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
            res.push(new konoha.String(element));
        }
        return new konoha.Array(res);
    }
    this.split = function(re) {
        var list = this.rawptr.split(re.rawptr);
        var res = [];
        for (element in list) {
            res.push(new konoha.String(element));
        }
        return new konoha.Array(res);
    }
    this.search = function(re) {
        return this.rawptr.search(re.rawptr);
    }
    this.replace = function(source, target) {
        return new konoha.String(this.rawptr.replace(source.rawptr, target.rawptr));
    }
    this.getSize = function() {
        return this.rawptr.length;
    }
}
konoha.String.prototype = new konoha.Object();
konoha.String.konohaclass = "konoha.String";

/* Regex */
konoha.Regex = function(rawptr) {
    this.rawptr = rawptr;
    this.new = function(pattern, option) {
        this.rawptr = new RegExp(pattern.rawptr, option.rawptr);
        return this;
    }
}
konoha.Regex.prototype = new konoha.Object();
konoha.Regex.konohaclass = "konoha.Regex";
/* Number */
konoha.Number = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Number.prototype = new konoha.Object();
konoha.Number.konohaclass = "konoha.Number";

/* Int */
konoha.Int = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Int.prototype = new konoha.Number();
konoha.Int.konohaclass = "konoha.Int";

konoha.Int.random = function() {
    return Math.random();
}
konoha.Int.format = function(i, format) {
    switch (format.rawptr) {
        case "%x":
            return new konoha.String(i.toString(16));
        case "%02x":
            var res = '00' + i.toString(16);
            return new konoha.String(res.substring(res.length-2, res.length));
    }
}

/* Float */
konoha.Float = function(rawptr) {
    this.rawptr = rawptr;
}
konoha.Float.prototype = new konoha.Number();
konoha.Float.konohaclass = "konoha.Float";

konoha.Float.random = function() {
    return Math.random();
}
