document.write("<script type='text/javascript' src='jquery-1.7.1.min.js'></script>");
js.Offset = function(rawptr) {
    this.rawptr = rawptr;
}
js.Offset.prototype = new konoha.Object();
js.Offset.prototype.new = function(top, left) {
    this.rawptr = {
     top: top,
     left: left
    };
}
js.Offset.prototype.getTop = function() {
    return this.rawptr.top;
}
js.Offset.prototype.getLeft = function() {
    return this.rawptr.left;
}

js.jquery = function(rawptr) {
}
var initJQuery = function() {
    var verifyArgs = function(args) {
        for (var i = 0; i < args.length; i++) {
            if (args[i].rawptr) {
                args[i] = args[i].rawptr;
            }
        }
        return args;
    }
    var jquery= function(rawptr) {
        this.rawptr = rawptr;
    }
    jquery.prototype = new konoha.Object();
    jquery.konohaclass = "js.jquery.JQuery";
    jquery.prototype.new = function() {
        if (arguments.length == 2) {
            this.rawptr = $(arguments[0].rawptr, arguments[1].rawptr);
        } else if (arguments.length == 1) {
            this.rawptr = $(arguments[0].rawptr);
        } else {
            throw("Script!!");
        }
    }

    /* Selectors */
    jquery.prototype.each_ = function(callback) {
        this.rawptr.each(callback.rawptr);
    }
    jquery.prototype.size = function() {
        return this.rawptr.size();
    }
    jquery.prototype.getSelector = function() {
        return new konoha.String(this.rawptr.getSelector());
    }
    jquery.prototype.getContext = function() {
        return new js.dom.Node(this.rawptr.getContext());
    }
    jquery.prototype.getNodeList = function() {
        return new js.dom.NodeList(this.rawptr.get());
    }
    jquery.prototype.getNode = function(index) {
        return new js.dom.Node(this.rawptr.get(index));
    }

    /* Attributes */
    jquery.prototype.attr = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.attr.apply(this.rawptr, args));
    }
    jquery.prototype.removeAttr = function(name) {
        return new jquery(this.rawptr.removeAttr(name.rawptr));
    }
    jquery.prototype.addClass = function(className) {
        return new jquery(this.rawptr.addClass(className.rawptr));
    }
    jquery.prototype.removeClass = function(className) {
        return new jquery(this.rawptr.removeClass(className.rawptr));
    }
    jquery.prototype.toggleClass = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.toggleClass.apply(this.rawptr, args));
    }
    jquery.prototype.getHTML = function() {
        return new konoha.String(this.rawptr.html());
    }
    jquery.prototype.html = function(val) {
        return new jquery(this.rawptr.html(val.rawptr));
    }
    jquery.prototype.getText = function() {
        return new konoha.String(this.rawptr.text());
    }
    jquery.prototype.text = function(val) {
        return new jquery(this.rawptr.text(val.rawptr));
    }
    jquery.prototype.getVal = function() {
        return new konoha.Array(this.rawptr.val())
    }
    jquery.prototype.val = function(val) {
        return new jquery(this.rawptr.val(val.rawptr));
    }

    /* Traversing */
    jquery.prototype.eq = function(position) {
        return new jquery(this.rawptr.eq(position));
    }
    jquery.prototype.filter = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.filter.apply(this.rawptr, args));
    }
    jquery.prototype.is = function(expr) {
        return this.rawptr.is(expr.rawptr);
    }
    jquery.prototype.not = function(expr) {
        return this.rawptr.not(expr.rawptr);
    }
    jquery.prototype.slice = function() {
        return new jquery(this.rawptr.slice.apply(this.rawptr, arguments));
    }
    jquery.prototype.add = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.add.apply(this.rawptr, args));
    }
    jquery.prototype.children = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.children.apply(this.rawptr, args));
    }
    jquery.prototype.closest = function() {
        var args  =verifyArgs(arguments);
        return new jquery(this.rawptr.closest.apply(this.rawptr, args));
    }
    jquery.prototype.contents = function() {
        return new jquery(this.rawptr.contents());
    }
    jquery.prototype.find = function(expr) {
        return new jquery(this.rawptr.find(expr.rawptr));
    }
    jquery.prototype.next = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.next.apply(this.rawptr, args));
    }
    jquery.prototype.nextAll = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.nextAll.apply(this.rawptr, args));
    }
    jquery.prototype.parent = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.parent.apply(this.rawptr, args));
    }
    jquery.prototype.parents = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.parents.apply(this.rawptr, args));
    }
    jquery.prototype.prev = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.prev.apply(this.rawptr, args));
    }
    jquery.prototype.prevAll = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.prevAll.apply(this.rawptr, args));
    }
    jquery.prototype.siblings = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.siblings.apply(this.rawptr, args));
    }
    jquery.prototype.andSelf = function() {
        return new jquery(this.rawptr.andSelf());
    }
    jquery.prototype.end = function() {
        return new jquery(this.rawptr.end());
    }

    /* Manipulation */
    jquery.prototype.append = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.append.apply(this.rawptr, args));
    }
    jquery.prototype.appendTo = function(content) {
        return new jquery(this.rawptr.appendTo(content.rawptr));
    }
    jquery.prototype.prepend = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.prepend.apply(this.rawptr, args));
    }
    jquery.prototype.prependTo = function(content) {
        return new jquery(this.rawptr.prependTo(content.rawptr));
    }
    jquery.prototype.after = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.after.apply(this.rawptr, args));
    }
    jquery.prototype.before = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.before.apply(this.rawptr, args));
    }
    jquery.prototype.insertAfter = function(content) {
        return new jquery(this.rawptr.insertAfter(content.rawptr));
    }
    jquery.prototype.insertBefore = function(content) {
        return new jquery(this.rawptr.insertBefore(content.rawptr));
    }
    jquery.prototype.wrap = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.wrap.apply(this.rawptr, args));
    }
    jquery.prototype.wrapAll = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.wrapAll.apply(this.rawptr, args));
    }
    jquery.prototype.wrapInner = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.wrapInner.apply(this.rawptr, args));
    }
    jquery.prototype.replaceWith = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.replaceWith.apply(this.rawptr, args));
    }
    jquery.prototype.replaceAll = function(selector) {
        return new jquery(this.rawptr.replaceAll(selector.rawptr));
    }
    jquery.prototype.empty = function() {
        return new jquery(this.rawptr.empty());
    }
    jquery.prototype.remove = function() {
        var args = verifyArgs(arguments);
        return new jquery(this.rawptr.remove.apply(this.rawptr, args));
    }
    jquery.prototype.clone = function() {
        return new jquery(this.rawptr.clone.apply(this.rawptr, arguments));
    }

    /* CSS */
    jquery.prototype.css = function() {
        var args = verifyArgs(arguments);
        return new konoha.String(this.rawptr.css.apply(this.rawptr, args));
    }
    jquery.prototype.offset = function() {
        return new js.Offset(this.rawptr.offset());
    }
    jquery.prototype.position = function() {
        return new js.Offset(this.rawptr.position());
    }
    jquery.prototype.scrollTop = function() {
        return this.rawptr.scrollTop.apply(this.rawptr, arguments);
    }
    jquery.prototype.scrollLeft = function() {
        return this.rawptr.scrollLeft.apply(this.rawptr, arguments);
    }
    jquery.prototype.height = function() {
        return this.rawptr.height.apply(this.rawptr, arguments);
    }
    jquery.prototype.width = function() {
        return this.rawptr.width.apply(this.rawptr, arguments);
    }
    jquery.prototype.innerHeight = function() {
        return this.rawptr.innerHeight();
    }
    jquery.prototype.innerWidth = function() {
        return this.rawptr.innerWidth();
    }
    jquery.prototype.outerHeight = function() {
        return this.rawptr.outerHeight();
    }
    jquery.prototype.outerWidth = function() {
        return this.rawptr.outerWidth();
    }

    /* Effects */
    jquery.prototype.show = function() {
        var args = verifyArgs(arguments);
        this.rawptr.show.apply(this.rawptr, args);
    }
    jquery.prototype.hide = function() {
        var args = verifyArgs(arguments);
        this.rawptr.hide.apply(this.rawptr, args);
    }
    jquery.prototype.toggle = function() {
        var args = verifyArgs(arguments);
        this.rawptr.toggle.apply(this.rawptr, args);
    }
    jquery.prototype.slideDown = function() {
        var args = verifyArgs(arguments);
        this.rawptr.slideDown.apply(this.rawptr, args);
    }
    jquery.prototype.slideUp = function() {
        var args = verifyArgs(arguments);
        this.rawptr.slideUp.apply(this.rawptr, args);
    }
    jquery.prototype.slideToggle = function() {
        var args = verifyArgs(arguments);
        this.rawptr.slideToggle.apply(this.rawptr, args);
    }
    jquery.prototype.fadeIn = function() {
        var args = verifyArgs(arguments);
        this.rawptr.fadeIn.apply(this.rawptr, args);
    }
    jquery.prototype.fadeOut = function() {
        var args = verifyArgs(arguments);
        this.rawptr.fadeOut.apply(this.rawptr, args);
    }
    jquery.prototype.fadeTo = function() {
        var args = verifyArgs(arguments);
        this.rawptr.fadeTo.apply(this.rawptr, args);
    }
    return jquery();
}
js.jquery.JQuery = initJQuery();
