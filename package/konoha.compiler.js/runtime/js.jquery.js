document.write("<script type='text/javascript' src='jquery-1.7.1.min.js'></script>");
js.Offset = function(rawptr) {
    this.rawptr = rawptr;
}
js.Offset.prototype = new konoha.Object();
js.Offset.prototype._new = function(rawptr) {
    this.rawptr = rawptr;
}
js.Offset.prototype.getTop = function() {
    return this.rawptr.top;
}
js.Offset.prototype.getLeft = function() {
    return this.rawptr.left;
}

js.jquery = {};
var initJQuery = function() {
    var verifyArgs = function(args) {
        for (var i = 0; i < args.length; i++) {
            if (args[i].rawptr) {
                args[i] = args[i].rawptr;
            }
        }
        return args;
    }
    var jquery = function(rawptr) {
        this.rawptr = rawptr;
    }
    jquery.prototype = new konoha.Object();
    jquery.konohaclass = "js.jquery.JQuery";
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
    jquery.prototype.getAttr = function(arg) {
        return new konoha.String(this.rawptr.attr(arg.rawptr));
    }
    jquery.prototype.attr = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
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
        var args = verifyArgs(Array.prototype.slice.call(arguments));
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
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.filter.apply(this.rawptr, args));
    }
    jquery.prototype.is = function(expr) {
        return this.rawptr.is(expr.rawptr);
    }
    jquery.prototype.opnot = function(expr) {
        return this.rawptr.not(expr.rawptr);
    }
    jquery.prototype.slice = function() {
        return new jquery(this.rawptr.slice.apply(this.rawptr, Array.prototype.slice.call(arguments)));
    }
    jquery.prototype.add = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.add.apply(this.rawptr, args));
    }
    jquery.prototype.children = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.children.apply(this.rawptr, args));
    }
    jquery.prototype.closest = function() {
        var args  =verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.closest.apply(this.rawptr, args));
    }
    jquery.prototype.contents = function() {
        return new jquery(this.rawptr.contents());
    }
    jquery.prototype.find = function(expr) {
        return new jquery(this.rawptr.find(expr.rawptr));
    }
    jquery.prototype.next = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.next.apply(this.rawptr, args));
    }
    jquery.prototype.nextAll = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.nextAll.apply(this.rawptr, args));
    }
    jquery.prototype.parent = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.parent.apply(this.rawptr, args));
    }
    jquery.prototype.parents = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.parents.apply(this.rawptr, args));
    }
    jquery.prototype.prev = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.prev.apply(this.rawptr, args));
    }
    jquery.prototype.prevAll = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.prevAll.apply(this.rawptr, args));
    }
    jquery.prototype.siblings = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
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
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.append.apply(this.rawptr, args));
    }
    jquery.prototype.appendTo = function(content) {
        return new jquery(this.rawptr.appendTo(content.rawptr));
    }
    jquery.prototype.prepend = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.prepend.apply(this.rawptr, args));
    }
    jquery.prototype.prependTo = function(content) {
        return new jquery(this.rawptr.prependTo(content.rawptr));
    }
    jquery.prototype.after = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.after.apply(this.rawptr, args));
    }
    jquery.prototype.before = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.before.apply(this.rawptr, args));
    }
    jquery.prototype.insertAfter = function(content) {
        return new jquery(this.rawptr.insertAfter(content.rawptr));
    }
    jquery.prototype.insertBefore = function(content) {
        return new jquery(this.rawptr.insertBefore(content.rawptr));
    }
    jquery.prototype.wrap = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.wrap.apply(this.rawptr, args));
    }
    jquery.prototype.wrapAll = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.wrapAll.apply(this.rawptr, args));
    }
    jquery.prototype.wrapInner = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.wrapInner.apply(this.rawptr, args));
    }
    jquery.prototype.replaceWith = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.replaceWith.apply(this.rawptr, args));
    }
    jquery.prototype.replaceAll = function(selector) {
        return new jquery(this.rawptr.replaceAll(selector.rawptr));
    }
    jquery.prototype.empty = function() {
        return new jquery(this.rawptr.empty());
    }
    jquery.prototype.remove = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.remove.apply(this.rawptr, args));
    }
    jquery.prototype.clone = function() {
        return new jquery(this.rawptr.clone.apply(this.rawptr, Array.prototype.slice.call(arguments)));
    }

    /* CSS */
    jquery.prototype.getcss = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new konoha.String(this.rawptr.css.apply(this.rawptr, args));
    }
    jquery.prototype.css = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        return new jquery(this.rawptr.css.apply(this.rawptr, args));
    }
    jquery.prototype.offset = function() {
        return new js.Offset(this.rawptr.offset());
    }
    jquery.prototype.position = function() {
        return new js.Offset(this.rawptr.position());
    }
    jquery.prototype.scrollTop = function() {
        return this.rawptr.scrollTop.apply(this.rawptr, Array.prototype.slice.call(arguments));
    }
    jquery.prototype.scrollLeft = function() {
        return this.rawptr.scrollLeft.apply(this.rawptr, Array.prototype.slice.call(arguments));
    }
    jquery.prototype.height = function() {
        return this.rawptr.height.apply(this.rawptr, Array.prototype.slice.call(arguments));
    }
    jquery.prototype.width = function() {
        return this.rawptr.width.apply(this.rawptr, Array.prototype.slice.call(arguments));
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

    /* Events */
    jquery.prototype.ready = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.ready.apply(this.rawptr, args);
    }
    jquery.prototype.bind = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.bind.apply(this.rawptr, args);
    }
    jquery.prototype.one = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.one.apply(this.rawptr, args);
    }
    jquery.prototype.trigger = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.trigger.apply(this.rawptr, args);
    }
    jquery.prototype.triggerHandler = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.triggerHandler.apply(this.rawptr, args);
    }
    jquery.prototype.unbind = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.unbind.apply(this.rawptr, args);
    }
    jquery.prototype.hover = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.hover.apply(this.rawptr, args);
    }
    jquery.prototype.toggleEvent = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        args = verifyArgs(args[0]);
        this.rawptr.toggle.apply(this.rawptr, args);
    }
    jquery.prototype.live = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.live.apply(this.rawptr, args);
    }
    jquery.prototype.die = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.die.apply(this.rawptr, args);
    }
    jquery.prototype.blur = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.blur.apply(this.rawptr, args);
        } else {
            this.rawptr.blur(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.change = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.change.apply(this.rawptr, args);
        } else {
            this.rawptr.change(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.click = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.click.apply(this.rawptr, args);
        } else {
            this.rawptr.click(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.dblclick = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.dblclick.apply(this.rawptr, args);
        } else {
            this.rawptr.dblclick(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.error = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.error.apply(this.rawptr, args);
        } else {
            this.rawptr.error(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.focus = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.focus.apply(this.rawptr, args);
        } else {
            this.rawptr.focus(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.keydown = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.keydown.apply(this.rawptr, args);
        } else {
            this.rawptr.keydown(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.keypress = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.keypress.apply(this.rawptr, args);
        } else {
            this.rawptr.keypress(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.keyup = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.keyup.apply(this.rawptr, args);
        } else {
            this.rawptr.keyup(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.load = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.load.apply(this.rawptr, args);
        } else {
            this.rawptr.load(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }

    }
    jquery.prototype.mousedown = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.mousedown.apply(this.rawptr, args);
        } else {
            this.rawptr.mousedown(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.mousemove = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.mousemove.apply(this.rawptr, args);
        } else {
            this.rawptr.mousemove(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.mouseout = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.mouseout.apply(this.rawptr, args);
        } else {
            this.rawptr.mouseout(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.mouseover = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.mouseover.apply(this.rawptr, args);
        } else {
            this.rawptr.mouseover(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.mouseup = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.mouseup.apply(this.rawptr, args);
        } else {
            this.rawptr.mouseup(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.resize = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.resize.apply(this.rawptr, args);
        } else {
            this.rawptr.resize(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.scroll = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.scroll.apply(this.rawptr, args);
        } else {
            this.rawptr.scroll(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.select = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.select.apply(this.rawptr, args);
        } else {
            this.rawptr.select(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.submit = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.submit.apply(this.rawptr, args);
        } else {
            this.rawptr.select(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    jquery.prototype.unload = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (args.length == 0) {
            this.rawptr.unload.apply(this.rawptr, args);
        } else {
            this.rawptr.unload(function(e) {
                    args[0].apply(new js.dom.Element(this), [new js.jquery.JEvent(e)]);
                    });
        }
    }
    /* Effects */
    jquery.prototype.show = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.show.apply(this.rawptr, args);
    }
    jquery.prototype.hide = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.hide.apply(this.rawptr, args);
    }
    jquery.prototype.toggle = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.toggle.apply(this.rawptr, args);
    }
    jquery.prototype.slideDown = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.slideDown.apply(this.rawptr, args);
    }
    jquery.prototype.slideUp = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.slideUp.apply(this.rawptr, args);
    }
    jquery.prototype.slideToggle = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.slideToggle.apply(this.rawptr, args);
    }
    jquery.prototype.fadeIn = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.fadeIn.apply(this.rawptr, args);
    }
    jquery.prototype.fadeOut = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.fadeOut.apply(this.rawptr, args);
    }
    jquery.prototype.fadeTo = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        this.rawptr.fadeTo.apply(this.rawptr, args);
    }
    jquery.prototype._new = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (arguments.length == 1) {
            this.rawptr = new $(args[0]);
        } else if (arguments.length == 2) {
            this.rawptr = new $(args[0], args[1]);
        } else {
            throw ("Script !!");
        }
        return this;
    }
    return jquery;
}
js.jquery.JQuery = new initJQuery();
js.jquery.JEvent = new function() {
    var jevent = function(rawptr) {
        this.rawptr = rawptr;
    }
    jevent.prototype = new konoha.Object();
    jevent.konohaclass = "js.jquery.JEvent";
    jevent.prototype.type = function() {
        return new konoha.String(this.rawptr.type);
    }
    jevent.prototype.target = function() {
        return new konoha.dom.Element(this.rawptr.target);
    }
    jevent.prototype.relatedTarget = function() {
        return new konoha.dom.Element(this.rawptr.relatedTarget);
    }
    jevent.prototype.currentTarget = function() {
        return new konoha.dom.Element(this.rawptr.currentTarget);
    }
    jevent.prototype.pageX = function() {
        return this.rawptr.pageX;
    }
    jevent.prototype.pageY = function() {
        return this.rawptr.pageY;
    }
    jevent.prototype.timeStamp = function() {
        return this.rawptr.timeStamp;
    }
    jevent.prototype.preventDefault = function() {
        return new jevent(this.rawptr.preventDefault());
    }
    jevent.prototype.isDefaultPrevented = function() {
        return this.rawptr.isDefaultPrevented();
    }
    jevent.prototype.stopPropagation = function() {
        return new jevent(this.rawptr.stopPropagation());
    }
    jevent.prototype.isPropagationStopped = function() {
        return this.rawptr.isPropagationStopped();
    }
    jevent.prototype.stopImmediatePropagation = function() {
        return new jevent(this.rawptr.stopImmediatePropagation());
    }
    jevent.prototype.isImmediatePropagationStopped = function() {
        return this.rawptr.isImmediatePropagationStopped();
    }
    jevent.prototype._new = function() {
        var args = verifyArgs(Array.prototype.slice.call(arguments));
        if (arguments.length == 1) {
            this.rawptr = new $(args[0]);
        } else if (arguments.length == 2) {
            this.rawptr = new $(args[0], args[1]);
        } else {
            throw ("Script !!");
        }
        return this;
    }
    return jevent;
}();
