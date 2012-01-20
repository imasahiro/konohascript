using js.dom.*;
class Offset {
    Offset(int top, int left);
    int getTop();
    int getLeft();
}
class JQuery {
    /* Core */
    @Overload JQuery (String expression, Document context);
    @Overload JQuery (String expression, Element context);
    @Overload JQuery (String expression, NodeList context);
    @Overload JQuery (String expression, jQuery context);
    @Overload JQuery (String html);
    @Overload JQuery (Element  element);
    @Overload JQuery (NodeList elements);
              //JQyery (callback)

    /* Selectors */
              void     each_(Method callback);
              int      size();
              String   getSelector();
              Node     getContext();
              NodeList getNodeList();
              Node     getNode(int index);
              //int      index(Element elemtnt);

    /* Attributes */
    @Overload JQuery   attr(String name);
    @Overload JQuery   attr(Map<String, dynamic> properties);
    @Overload JQuery   attr(String key, dynamic value);
              JQuery   removeAttr(String name);
              JQuery   addClass(String className);
              JQuery   removeClass(String className);
    @Overload JQuery   toggleClass(String className);
    @Overload JQuery   toggleClass(String className, Boolean flagSwitch);
              String   getHTML();
              JQuery   html(String val);
              String   getText();
              JQuery   text(String val);
              Array    getVal();
              JQuery   val(String val);

    /* Traversing */
              JQuery   eq(int position);
              Boolean  hasClass(String className);
    @Overload JQuery   filter(int expr);
    @Overload JQuery   filter(String expr);
    @Overload JQuery   filter(Method callback);
              Boolean  is(String expr);
              //JQuery   map();
              JQuery not(String expr);
    @Overload JQuery slice(int start);
    @Overload JQuery slice(int start, int end);
    @Overload JQuery add(String expr);
    @Overload JQuery add(Element expr);
    @Overload JQuery add(Node expr);
    @Overload JQuery add(NodeList expr);
    @Overload JQuery children(String expr);
    @Overload JQuery children();
    @Overload JQuery closest(String expr);
    @Overload JQuery closest();
              JQuery contents();
              JQuery find(String expr);
    @Overload JQuery next(String expr);
    @Overload JQuery next();
    @Overload JQuery nextAll(String expr);
    @Overload JQuery nextAll();
    @Overload JQuery parent(String expr);
    @Overload JQuery parent();
    @Overload JQuery parents(String expr);
    @Overload JQuery parents();
    @Overload JQuery prev(String expr);
    @Overload JQuery prev();
    @Overload JQuery prevAll(String expr);
    @Overload JQuery prevAll();
    @Overload JQuery siblings(String expr);
    @Overload JQuery siblings();
              JQuery andSelf();
              JQuery end();

    /* Manipulation */
    @Overload JQuery append(String content);
    @Overload JQuery append(Element content);
    @Overload JQuery append(JQuery content);
              JQuery appendTo(String content);
    @Overload JQuery prepend(String content);
    @Overload JQuery prepend(Element content);
    @Overload JQuery prepend(JQuery content);
              JQuery prependTo(String content);
    @Overload JQuery after(String content);
    @Overload JQuery after(Element content);
    @Overload JQuery after(JQuery content);
    @Overload JQuery before(String content);
    @Overload JQuery before(Element content);
    @Overload JQuery before(JQuery content);
              JQuery insertAfter(String content);
              JQuery insertBefore(String content);
    @Overload JQuery wrap(String html);
    @Overload JQuery wrap(Element elem);
    @Overload JQuery wrapAll(String elem);
    @Overload JQuery wrapAll(Element elem);
    @Overload JQuery wrapInner(String elem);
    @Overload JQuery wrapInner(Element elem);
    @Overload JQuery replaceWith(String content);
    @Overload JQuery replaceWith(Element content);
    @Overload JQuery replaceWith(JQuery content);
              JQuery replaceAll(String selector);
              JQuery empty();
    @Overload JQuery remove(String expr);
    @Overload JQuery remove();
    @Overload JQuery clone();
    @Overload JQuery clone(Boolean flag);

    /* CSS */

    @Overload String css(String name);
    @Overload String css(Map<String, dynamic> properties);
    @Overload String css(String name, dynamic value);
              Offset offset();
              Offset position();
    @Overload int    scrollTop();
    @Overload int    scrollTop(int val);
    @Overload int    scrollLeft();
    @Overload int    scrollLeft(int val);
    @Overload int    height();
    @Overload int    height(int val);
    @Overload int    width();
    @Overload int    width(int val);
              int    innerHeight();
              int    innerWidth();
              int    outerHeight();
              int    outerWidth();

    /* Events */

    /* Effects */
    @Overload void show();
    @Overload void show(int speed);
    @Overload void show(String speed);
    @Overload void show(int speed, Method callback);
    @Overload void show(String speed, Method callback);
    @Overload void hide();
    @Overload void hide(int speed);
    @Overload void hide(String speed);
    @Overload void hide(int speed, Method callback);
    @Overload void hide(String speed, Method callback);
    @Overload void toggle();
    @Overload void toggle(Boolean flagSwitch);
    @Overload void toggle(int speed);
    @Overload void toggle(String speed);
    @Overload void toggle(int speed, Method callback);
    @Overload void toggle(String speed, Method callback);
    @Overload void slideDown();
    @Overload void slideDown(Method callback);
    @Overload void slideDown(int speed);
    @Overload void slideDown(String speed);
    @Overload void slideDown(int speed, Method callback);
    @Overload void slideDown(String speed, Method callback);
    @Overload void slideUp();
    @Overload void slideUp(Method callback);
    @Overload void slideUp(int speed);
    @Overload void slideUp(String speed);
    @Overload void slideUp(int speed, Method callback);
    @Overload void slideUp(String speed, Method callback);
    @Overload void slideToggle();
    @Overload void slideToggle(Method callback);
    @Overload void slideToggle(int speed);
    @Overload void slideToggle(String speed);
    @Overload void slideToggle(int speed, Method callback);
    @Overload void slideToggle(String speed, Method callback);
    @Overload void fadeIn();
    @Overload void fadeIn(Method callback);
    @Overload void fadeIn(int speed);
    @Overload void fadeIn(String speed);
    @Overload void fadeIn(int speed, Method callback);
    @Overload void fadeIn(String speed, Method callback);
    @Overload void fadeOut();
    @Overload void fadeOut(Method callback);
    @Overload void fadeOut(int speed);
    @Overload void fadeOut(String speed);
    @Overload void fadeOut(int speed, Method callback);
    @Overload void fadeOut(String speed, Method callback);
    @Overload void fadeTo(int speed, int opacity);
    @Overload void fadeTo(String speed, int opacity);
    @Overload void fadeTo(int speed, Method callback);
    @Overload void fadeTo(String speed, int opacity, Method callback);
              //void animate();
              //void stop();
              //void queue();
              //void dequeue();
}
