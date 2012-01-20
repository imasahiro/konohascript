/* converted from java package java.awt.event */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_awt_AWTEvent;
class Java_awt_Adjustable;
class Java_awt_Component;
class Java_awt_Container;
class Java_awt_ItemSelectable;
class Java_awt_Point;
class Java_awt_Rectangle;
class Java_awt_Window;
class Java_awt_font_TextHitInfo;
class Java_lang_Exception;
class Java_lang_Runnable;
class Java_lang_Throwable;
class Java_text_AttributedCharacterIterator;
class Java_util_EventListenerProxy;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_awt_event_AWTEventListener;
class Java_awt_event_AWTEventListenerProxy extends Java_util_EventListenerProxy;
class Java_awt_event_ActionEvent extends Java_awt_AWTEvent;
class Java_awt_event_ActionListener;
class Java_awt_event_AdjustmentEvent extends Java_awt_AWTEvent;
class Java_awt_event_AdjustmentListener;
class Java_awt_event_ComponentAdapter;
class Java_awt_event_ComponentEvent extends Java_awt_AWTEvent;
class Java_awt_event_ComponentListener;
class Java_awt_event_ContainerAdapter;
class Java_awt_event_ContainerEvent extends Java_awt_event_ComponentEvent;
class Java_awt_event_ContainerListener;
class Java_awt_event_FocusAdapter;
class Java_awt_event_FocusEvent extends Java_awt_event_ComponentEvent;
class Java_awt_event_FocusListener;
class Java_awt_event_HierarchyBoundsAdapter;
class Java_awt_event_HierarchyBoundsListener;
class Java_awt_event_HierarchyEvent extends Java_awt_AWTEvent;
class Java_awt_event_HierarchyListener;
class Java_awt_event_InputEvent extends Java_awt_event_ComponentEvent;
class Java_awt_event_InputMethodEvent extends Java_awt_AWTEvent;
class Java_awt_event_InputMethodListener;
class Java_awt_event_InvocationEvent extends Java_awt_AWTEvent;
class Java_awt_event_ItemEvent extends Java_awt_AWTEvent;
class Java_awt_event_ItemListener;
class Java_awt_event_KeyAdapter;
class Java_awt_event_KeyEvent extends Java_awt_event_InputEvent;
class Java_awt_event_KeyListener;
class Java_awt_event_MouseAdapter;
class Java_awt_event_MouseEvent extends Java_awt_event_InputEvent;
class Java_awt_event_MouseListener;
class Java_awt_event_MouseMotionAdapter;
class Java_awt_event_MouseMotionListener;
class Java_awt_event_MouseWheelEvent extends Java_awt_event_MouseEvent;
class Java_awt_event_MouseWheelListener;
class Java_awt_event_PaintEvent extends Java_awt_event_ComponentEvent;
class Java_awt_event_TextEvent extends Java_awt_AWTEvent;
class Java_awt_event_TextListener;
class Java_awt_event_WindowAdapter;
class Java_awt_event_WindowEvent extends Java_awt_event_ComponentEvent;
class Java_awt_event_WindowFocusListener;
class Java_awt_event_WindowListener;
class Java_awt_event_WindowStateListener;

/*------------------------------------------------------------*/
/* interface java.awt.event.AWTEventListener */
class Java_awt_event_AWTEventListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void eventDispatched(Java_awt_AWTEvent p0);
}

/* class java.awt.event.AWTEventListenerProxy */
class Java_awt_event_AWTEventListenerProxy extends Java_util_EventListenerProxy {
	// implements java.awt.event.AWTEventListener
	/*-- Method --*/
	@Virtual @Overload void eventDispatched(Java_awt_AWTEvent p0);
	@Virtual @Overload long getEventMask();
}
Java_awt_event_AWTEventListenerProxy Java_awt_event_AWTEventListenerProxy.new(long p0, Java_awt_event_AWTEventListener p1);

/* class java.awt.event.ActionEvent */
class Java_awt_event_ActionEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload String getActionCommand();
	@Virtual @Overload int getModifiers();
	@Virtual @Overload long getWhen();
}
@Overload Java_awt_event_ActionEvent Java_awt_event_ActionEvent.new(Object p0, int p1, String p2);
@Overload Java_awt_event_ActionEvent Java_awt_event_ActionEvent.new(Object p0, int p1, String p2, int p3);
@Overload Java_awt_event_ActionEvent Java_awt_event_ActionEvent.new(Object p0, int p1, String p2, long p3, int p4);

/* interface java.awt.event.ActionListener */
class Java_awt_event_ActionListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void actionPerformed(Java_awt_event_ActionEvent p0);
}

/* class java.awt.event.AdjustmentEvent */
class Java_awt_event_AdjustmentEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Adjustable getAdjustable();
	@Virtual @Overload int getAdjustmentType();
	@Virtual @Overload int getValue();
	@Virtual @Overload boolean getValueIsAdjusting();
}
@Overload Java_awt_event_AdjustmentEvent Java_awt_event_AdjustmentEvent.new(Java_awt_Adjustable p0, int p1, int p2, int p3);
@Overload Java_awt_event_AdjustmentEvent Java_awt_event_AdjustmentEvent.new(Java_awt_Adjustable p0, int p1, int p2, int p3, boolean p4);

/* interface java.awt.event.AdjustmentListener */
class Java_awt_event_AdjustmentListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void adjustmentValueChanged(Java_awt_event_AdjustmentEvent p0);
}

/* class java.awt.event.ComponentAdapter */
class Java_awt_event_ComponentAdapter {
	// implements java.awt.event.ComponentListener
	/*-- Method --*/
	@Virtual @Overload void componentHidden(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentMoved(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentResized(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentShown(Java_awt_event_ComponentEvent p0);
}
Java_awt_event_ComponentAdapter Java_awt_event_ComponentAdapter.new();

/* class java.awt.event.ComponentEvent */
class Java_awt_event_ComponentEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Component getComponent();
}
Java_awt_event_ComponentEvent Java_awt_event_ComponentEvent.new(Java_awt_Component p0, int p1);

/* interface java.awt.event.ComponentListener */
class Java_awt_event_ComponentListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void componentHidden(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentMoved(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentResized(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentShown(Java_awt_event_ComponentEvent p0);
}

/* class java.awt.event.ContainerAdapter */
class Java_awt_event_ContainerAdapter {
	// implements java.awt.event.ContainerListener
	/*-- Method --*/
	@Virtual @Overload void componentAdded(Java_awt_event_ContainerEvent p0);
	@Virtual @Overload void componentRemoved(Java_awt_event_ContainerEvent p0);
}
Java_awt_event_ContainerAdapter Java_awt_event_ContainerAdapter.new();

/* class java.awt.event.ContainerEvent */
class Java_awt_event_ContainerEvent extends Java_awt_event_ComponentEvent {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Component getChild();
	@Virtual @Overload Java_awt_Container getContainer();
}
Java_awt_event_ContainerEvent Java_awt_event_ContainerEvent.new(Java_awt_Component p0, int p1, Java_awt_Component p2);

/* interface java.awt.event.ContainerListener */
class Java_awt_event_ContainerListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void componentAdded(Java_awt_event_ContainerEvent p0);
	@Virtual @Overload void componentRemoved(Java_awt_event_ContainerEvent p0);
}

/* class java.awt.event.FocusAdapter */
class Java_awt_event_FocusAdapter {
	// implements java.awt.event.FocusListener
	/*-- Method --*/
	@Virtual @Overload void focusGained(Java_awt_event_FocusEvent p0);
	@Virtual @Overload void focusLost(Java_awt_event_FocusEvent p0);
}
Java_awt_event_FocusAdapter Java_awt_event_FocusAdapter.new();

/* class java.awt.event.FocusEvent */
class Java_awt_event_FocusEvent extends Java_awt_event_ComponentEvent {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Component getOppositeComponent();
	@Virtual @Overload boolean isTemporary();
}
@Overload Java_awt_event_FocusEvent Java_awt_event_FocusEvent.new(Java_awt_Component p0, int p1, boolean p2, Java_awt_Component p3);
@Overload Java_awt_event_FocusEvent Java_awt_event_FocusEvent.new(Java_awt_Component p0, int p1, boolean p2);
@Overload Java_awt_event_FocusEvent Java_awt_event_FocusEvent.new(Java_awt_Component p0, int p1);

/* interface java.awt.event.FocusListener */
class Java_awt_event_FocusListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void focusGained(Java_awt_event_FocusEvent p0);
	@Virtual @Overload void focusLost(Java_awt_event_FocusEvent p0);
}

/* class java.awt.event.HierarchyBoundsAdapter */
class Java_awt_event_HierarchyBoundsAdapter {
	// implements java.awt.event.HierarchyBoundsListener
	/*-- Method --*/
	@Virtual @Overload void ancestorMoved(Java_awt_event_HierarchyEvent p0);
	@Virtual @Overload void ancestorResized(Java_awt_event_HierarchyEvent p0);
}
Java_awt_event_HierarchyBoundsAdapter Java_awt_event_HierarchyBoundsAdapter.new();

/* interface java.awt.event.HierarchyBoundsListener */
class Java_awt_event_HierarchyBoundsListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void ancestorMoved(Java_awt_event_HierarchyEvent p0);
	@Virtual @Overload void ancestorResized(Java_awt_event_HierarchyEvent p0);
}

/* class java.awt.event.HierarchyEvent */
class Java_awt_event_HierarchyEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload long getChangeFlags();
	@Virtual @Overload Java_awt_Component getChanged();
	@Virtual @Overload Java_awt_Container getChangedParent();
	@Virtual @Overload Java_awt_Component getComponent();
}
@Overload Java_awt_event_HierarchyEvent Java_awt_event_HierarchyEvent.new(Java_awt_Component p0, int p1, Java_awt_Component p2, Java_awt_Container p3);
@Overload Java_awt_event_HierarchyEvent Java_awt_event_HierarchyEvent.new(Java_awt_Component p0, int p1, Java_awt_Component p2, Java_awt_Container p3, long p4);

/* interface java.awt.event.HierarchyListener */
class Java_awt_event_HierarchyListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void hierarchyChanged(Java_awt_event_HierarchyEvent p0);
}

/* class java.awt.event.InputEvent */
class Java_awt_event_InputEvent extends Java_awt_event_ComponentEvent {
	/*-- Method --*/
	@Virtual @Overload void consume();
	@Virtual @Overload int getMaskForButton(int p0);
	@Virtual @Overload int getModifiers();
	@Virtual @Overload int getModifiersEx();
	@Virtual @Overload String getModifiersExText(int p0);
	@Virtual @Overload long getWhen();
	@Virtual @Overload boolean isAltDown();
	@Virtual @Overload boolean isAltGraphDown();
	@Virtual @Overload boolean isConsumed();
	@Virtual @Overload boolean isControlDown();
	@Virtual @Overload boolean isMetaDown();
	@Virtual @Overload boolean isShiftDown();
}

/* class java.awt.event.InputMethodEvent */
class Java_awt_event_InputMethodEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload void consume();
	@Virtual @Overload Java_awt_font_TextHitInfo getCaret();
	@Virtual @Overload int getCommittedCharacterCount();
	@Virtual @Overload Java_text_AttributedCharacterIterator getText();
	@Virtual @Overload Java_awt_font_TextHitInfo getVisiblePosition();
	@Virtual @Overload long getWhen();
	@Virtual @Overload boolean isConsumed();
}
@Overload Java_awt_event_InputMethodEvent Java_awt_event_InputMethodEvent.new(Java_awt_Component p0, int p1, long p2, Java_text_AttributedCharacterIterator p3, int p4, Java_awt_font_TextHitInfo p5, Java_awt_font_TextHitInfo p6);
@Overload Java_awt_event_InputMethodEvent Java_awt_event_InputMethodEvent.new(Java_awt_Component p0, int p1, Java_text_AttributedCharacterIterator p2, int p3, Java_awt_font_TextHitInfo p4, Java_awt_font_TextHitInfo p5);
@Overload Java_awt_event_InputMethodEvent Java_awt_event_InputMethodEvent.new(Java_awt_Component p0, int p1, Java_awt_font_TextHitInfo p2, Java_awt_font_TextHitInfo p3);

/* interface java.awt.event.InputMethodListener */
class Java_awt_event_InputMethodListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void caretPositionChanged(Java_awt_event_InputMethodEvent p0);
	@Virtual @Overload void inputMethodTextChanged(Java_awt_event_InputMethodEvent p0);
}

/* class java.awt.event.InvocationEvent */
class Java_awt_event_InvocationEvent extends Java_awt_AWTEvent {
	// implements java.awt.ActiveEvent
	/*-- Method --*/
	@Virtual @Overload void dispatch();
	@Virtual @Overload Java_lang_Exception getException();
	@Virtual @Overload Java_lang_Throwable getThrowable();
	@Virtual @Overload long getWhen();
	@Virtual @Overload boolean isDispatched();
}
@Overload Java_awt_event_InvocationEvent Java_awt_event_InvocationEvent.new(Object p0, Java_lang_Runnable p1);
@Overload Java_awt_event_InvocationEvent Java_awt_event_InvocationEvent.new(Object p0, Java_lang_Runnable p1, Object p2, boolean p3);

/* class java.awt.event.ItemEvent */
class Java_awt_event_ItemEvent extends Java_awt_AWTEvent {
	/*-- Method --*/
	@Virtual @Overload Object getItem();
	@Virtual @Overload Java_awt_ItemSelectable getItemSelectable();
	@Virtual @Overload int getStateChange();
}
Java_awt_event_ItemEvent Java_awt_event_ItemEvent.new(Java_awt_ItemSelectable p0, int p1, Object p2, int p3);

/* interface java.awt.event.ItemListener */
class Java_awt_event_ItemListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void itemStateChanged(Java_awt_event_ItemEvent p0);
}

/* class java.awt.event.KeyAdapter */
class Java_awt_event_KeyAdapter {
	// implements java.awt.event.KeyListener
	/*-- Method --*/
	@Virtual @Overload void keyPressed(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyReleased(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyTyped(Java_awt_event_KeyEvent p0);
}
Java_awt_event_KeyAdapter Java_awt_event_KeyAdapter.new();

/* class java.awt.event.KeyEvent */
class Java_awt_event_KeyEvent extends Java_awt_event_InputEvent {
	/*-- Method --*/
	@Virtual @Overload int getExtendedKeyCode();
	@Virtual @Overload int getExtendedKeyCodeForChar(int p0);
	@Virtual @Overload int getKeyChar();
	@Virtual @Overload int getKeyCode();
	@Virtual @Overload int getKeyLocation();
	@Virtual @Overload String getKeyModifiersText(int p0);
	@Virtual @Overload String getKeyText(int p0);
	@Virtual @Overload boolean isActionKey();
	@Virtual @Overload void setKeyChar(int p0);
	@Virtual @Overload void setKeyCode(int p0);
}
@Overload Java_awt_event_KeyEvent Java_awt_event_KeyEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6);
@Overload Java_awt_event_KeyEvent Java_awt_event_KeyEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5);
@Overload Java_awt_event_KeyEvent Java_awt_event_KeyEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4);

/* interface java.awt.event.KeyListener */
class Java_awt_event_KeyListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void keyPressed(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyReleased(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyTyped(Java_awt_event_KeyEvent p0);
}

/* class java.awt.event.MouseAdapter */
class Java_awt_event_MouseAdapter {
	// implements java.awt.event.MouseListener, java.awt.event.MouseWheelListener, java.awt.event.MouseMotionListener
	/*-- Method --*/
	@Virtual @Overload void mouseClicked(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseDragged(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseEntered(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseExited(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseMoved(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mousePressed(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseReleased(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseWheelMoved(Java_awt_event_MouseWheelEvent p0);
}
Java_awt_event_MouseAdapter Java_awt_event_MouseAdapter.new();

/* class java.awt.event.MouseEvent */
class Java_awt_event_MouseEvent extends Java_awt_event_InputEvent {
	/*-- Method --*/
	@Virtual @Overload int getButton();
	@Virtual @Overload int getClickCount();
	@Virtual @Overload Java_awt_Point getLocationOnScreen();
	@Virtual @Overload String getMouseModifiersText(int p0);
	@Virtual @Overload Java_awt_Point getPoint();
	@Virtual @Overload int getX();
	@Virtual @Overload int getXOnScreen();
	@Virtual @Overload int getY();
	@Virtual @Overload int getYOnScreen();
	@Virtual @Overload boolean isPopupTrigger();
	@Virtual @Overload void translatePoint(int p0, int p1);
}
@Overload Java_awt_event_MouseEvent Java_awt_event_MouseEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, boolean p7, int p8);
@Overload Java_awt_event_MouseEvent Java_awt_event_MouseEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, boolean p7);
@Overload Java_awt_event_MouseEvent Java_awt_event_MouseEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, int p7, int p8, boolean p9, int p10);

/* interface java.awt.event.MouseListener */
class Java_awt_event_MouseListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void mouseClicked(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseEntered(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseExited(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mousePressed(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseReleased(Java_awt_event_MouseEvent p0);
}

/* class java.awt.event.MouseMotionAdapter */
class Java_awt_event_MouseMotionAdapter {
	// implements java.awt.event.MouseMotionListener
	/*-- Method --*/
	@Virtual @Overload void mouseDragged(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseMoved(Java_awt_event_MouseEvent p0);
}
Java_awt_event_MouseMotionAdapter Java_awt_event_MouseMotionAdapter.new();

/* interface java.awt.event.MouseMotionListener */
class Java_awt_event_MouseMotionListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void mouseDragged(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseMoved(Java_awt_event_MouseEvent p0);
}

/* class java.awt.event.MouseWheelEvent */
class Java_awt_event_MouseWheelEvent extends Java_awt_event_MouseEvent {
	/*-- Method --*/
	@Virtual @Overload double getPreciseWheelRotation();
	@Virtual @Overload int getScrollAmount();
	@Virtual @Overload int getScrollType();
	@Virtual @Overload int getUnitsToScroll();
	@Virtual @Overload int getWheelRotation();
}
@Overload Java_awt_event_MouseWheelEvent Java_awt_event_MouseWheelEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, boolean p7, int p8, int p9, int p10);
@Overload Java_awt_event_MouseWheelEvent Java_awt_event_MouseWheelEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, int p7, int p8, boolean p9, int p10, int p11, int p12);
@Overload Java_awt_event_MouseWheelEvent Java_awt_event_MouseWheelEvent.new(Java_awt_Component p0, int p1, long p2, int p3, int p4, int p5, int p6, int p7, int p8, boolean p9, int p10, int p11, int p12, double p13);

/* interface java.awt.event.MouseWheelListener */
class Java_awt_event_MouseWheelListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void mouseWheelMoved(Java_awt_event_MouseWheelEvent p0);
}

/* class java.awt.event.PaintEvent */
class Java_awt_event_PaintEvent extends Java_awt_event_ComponentEvent {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Rectangle getUpdateRect();
	@Virtual @Overload void setUpdateRect(Java_awt_Rectangle p0);
}
Java_awt_event_PaintEvent Java_awt_event_PaintEvent.new(Java_awt_Component p0, int p1, Java_awt_Rectangle p2);

/* class java.awt.event.TextEvent */
class Java_awt_event_TextEvent extends Java_awt_AWTEvent {
}
Java_awt_event_TextEvent Java_awt_event_TextEvent.new(Object p0, int p1);

/* interface java.awt.event.TextListener */
class Java_awt_event_TextListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void textValueChanged(Java_awt_event_TextEvent p0);
}

/* class java.awt.event.WindowAdapter */
class Java_awt_event_WindowAdapter {
	// implements java.awt.event.WindowListener, java.awt.event.WindowStateListener, java.awt.event.WindowFocusListener
	/*-- Method --*/
	@Virtual @Overload void windowActivated(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowClosed(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowClosing(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowDeactivated(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowDeiconified(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowGainedFocus(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowIconified(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowLostFocus(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowOpened(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowStateChanged(Java_awt_event_WindowEvent p0);
}
Java_awt_event_WindowAdapter Java_awt_event_WindowAdapter.new();

/* class java.awt.event.WindowEvent */
class Java_awt_event_WindowEvent extends Java_awt_event_ComponentEvent {
	/*-- Method --*/
	@Virtual @Overload int getNewState();
	@Virtual @Overload int getOldState();
	@Virtual @Overload Java_awt_Window getOppositeWindow();
	@Virtual @Overload Java_awt_Window getWindow();
}
@Overload Java_awt_event_WindowEvent Java_awt_event_WindowEvent.new(Java_awt_Window p0, int p1, Java_awt_Window p2, int p3, int p4);
@Overload Java_awt_event_WindowEvent Java_awt_event_WindowEvent.new(Java_awt_Window p0, int p1, Java_awt_Window p2);
@Overload Java_awt_event_WindowEvent Java_awt_event_WindowEvent.new(Java_awt_Window p0, int p1, int p2, int p3);
@Overload Java_awt_event_WindowEvent Java_awt_event_WindowEvent.new(Java_awt_Window p0, int p1);

/* interface java.awt.event.WindowFocusListener */
class Java_awt_event_WindowFocusListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void windowGainedFocus(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowLostFocus(Java_awt_event_WindowEvent p0);
}

/* interface java.awt.event.WindowListener */
class Java_awt_event_WindowListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void windowActivated(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowClosed(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowClosing(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowDeactivated(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowDeiconified(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowIconified(Java_awt_event_WindowEvent p0);
	@Virtual @Overload void windowOpened(Java_awt_event_WindowEvent p0);
}

/* interface java.awt.event.WindowStateListener */
class Java_awt_event_WindowStateListener {
	// implements java.util.EventListener
	/*-- Method --*/
	@Virtual @Overload void windowStateChanged(Java_awt_event_WindowEvent p0);
}


/*------------------------------------------------------------*/
/* short names */
AWTEventListener = Java_awt_event_AWTEventListener
AWTEventListenerProxy = Java_awt_event_AWTEventListenerProxy
ActionEvent = Java_awt_event_ActionEvent
ActionListener = Java_awt_event_ActionListener
AdjustmentEvent = Java_awt_event_AdjustmentEvent
AdjustmentListener = Java_awt_event_AdjustmentListener
ComponentAdapter = Java_awt_event_ComponentAdapter
ComponentEvent = Java_awt_event_ComponentEvent
ComponentListener = Java_awt_event_ComponentListener
ContainerAdapter = Java_awt_event_ContainerAdapter
ContainerEvent = Java_awt_event_ContainerEvent
ContainerListener = Java_awt_event_ContainerListener
FocusAdapter = Java_awt_event_FocusAdapter
FocusEvent = Java_awt_event_FocusEvent
FocusListener = Java_awt_event_FocusListener
HierarchyBoundsAdapter = Java_awt_event_HierarchyBoundsAdapter
HierarchyBoundsListener = Java_awt_event_HierarchyBoundsListener
HierarchyEvent = Java_awt_event_HierarchyEvent
HierarchyListener = Java_awt_event_HierarchyListener
InputEvent = Java_awt_event_InputEvent
InputMethodEvent = Java_awt_event_InputMethodEvent
InputMethodListener = Java_awt_event_InputMethodListener
InvocationEvent = Java_awt_event_InvocationEvent
ItemEvent = Java_awt_event_ItemEvent
ItemListener = Java_awt_event_ItemListener
KeyAdapter = Java_awt_event_KeyAdapter
KeyEvent = Java_awt_event_KeyEvent
KeyListener = Java_awt_event_KeyListener
MouseAdapter = Java_awt_event_MouseAdapter
MouseEvent = Java_awt_event_MouseEvent
MouseListener = Java_awt_event_MouseListener
MouseMotionAdapter = Java_awt_event_MouseMotionAdapter
MouseMotionListener = Java_awt_event_MouseMotionListener
MouseWheelEvent = Java_awt_event_MouseWheelEvent
MouseWheelListener = Java_awt_event_MouseWheelListener
PaintEvent = Java_awt_event_PaintEvent
TextEvent = Java_awt_event_TextEvent
TextListener = Java_awt_event_TextListener
WindowAdapter = Java_awt_event_WindowAdapter
WindowEvent = Java_awt_event_WindowEvent
WindowFocusListener = Java_awt_event_WindowFocusListener
WindowListener = Java_awt_event_WindowListener
WindowStateListener = Java_awt_event_WindowStateListener
