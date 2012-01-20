/* converted from java package java.awt */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_awt_BufferCapabilities_FlipContents;
class Java_awt_Component_BaselineResizeBehavior;
class Java_awt_Desktop_Action;
class Java_awt_Dialog_ModalExclusionType;
class Java_awt_Dialog_ModalityType;
class Java_awt_GraphicsDevice_WindowTranslucency;
class Java_awt_JobAttributes_DefaultSelectionType;
class Java_awt_JobAttributes_DestinationType;
class Java_awt_JobAttributes_DialogType;
class Java_awt_JobAttributes_MultipleDocumentHandlingType;
class Java_awt_JobAttributes_SidesType;
class Java_awt_MultipleGradientPaint_ColorSpaceType;
class Java_awt_MultipleGradientPaint_CycleMethod;
class Java_awt_PageAttributes_ColorType;
class Java_awt_PageAttributes_MediaType;
class Java_awt_PageAttributes_OrientationRequestedType;
class Java_awt_PageAttributes_OriginType;
class Java_awt_PageAttributes_PrintQualityType;
class Java_awt_RenderingHints_Key;
class Java_awt_TrayIcon_MessageType;
class Java_awt_Window_Type;
class Java_awt_color_ColorSpace;
class Java_awt_datatransfer_Clipboard;
class Java_awt_dnd_DragGestureEvent;
class Java_awt_dnd_DragGestureListener;
class Java_awt_dnd_DragGestureRecognizer;
class Java_awt_dnd_DragSource;
class Java_awt_dnd_DropTarget;
class Java_awt_dnd_peer_DragSourceContextPeer;
class Java_awt_event_AWTEventListener;
class Java_awt_event_ActionEvent;
class Java_awt_event_ActionListener;
class Java_awt_event_AdjustmentEvent;
class Java_awt_event_AdjustmentListener;
class Java_awt_event_ComponentEvent;
class Java_awt_event_ComponentListener;
class Java_awt_event_ContainerEvent;
class Java_awt_event_ContainerListener;
class Java_awt_event_FocusEvent;
class Java_awt_event_FocusListener;
class Java_awt_event_HierarchyBoundsListener;
class Java_awt_event_HierarchyEvent;
class Java_awt_event_HierarchyListener;
class Java_awt_event_InputMethodEvent;
class Java_awt_event_InputMethodListener;
class Java_awt_event_ItemEvent;
class Java_awt_event_ItemListener;
class Java_awt_event_KeyEvent;
class Java_awt_event_KeyListener;
class Java_awt_event_MouseEvent;
class Java_awt_event_MouseListener;
class Java_awt_event_MouseMotionListener;
class Java_awt_event_MouseWheelEvent;
class Java_awt_event_MouseWheelListener;
class Java_awt_event_TextEvent;
class Java_awt_event_TextListener;
class Java_awt_event_WindowEvent;
class Java_awt_event_WindowFocusListener;
class Java_awt_event_WindowListener;
class Java_awt_event_WindowStateListener;
class Java_awt_font_FontRenderContext;
class Java_awt_font_GlyphVector;
class Java_awt_font_LineMetrics;
class Java_awt_geom_AffineTransform;
class Java_awt_geom_Dimension2D;
class Java_awt_geom_PathIterator;
class Java_awt_geom_Point2D;
class Java_awt_geom_Rectangle2D;
class Java_awt_im_InputContext;
class Java_awt_im_InputMethodHighlight;
class Java_awt_im_InputMethodRequests;
class Java_awt_image_BufferStrategy;
class Java_awt_image_BufferedImage;
class Java_awt_image_BufferedImageOp;
class Java_awt_image_ColorModel;
class Java_awt_image_ImageObserver;
class Java_awt_image_ImageProducer;
class Java_awt_image_Raster;
class Java_awt_image_RenderedImage;
class Java_awt_image_VolatileImage;
class Java_awt_image_WritableRaster;
class Java_awt_image_renderable_RenderableImage;
class Java_beans_PropertyChangeListener;
class Java_beans_VetoableChangeListener;
class Java_io_File;
class Java_io_FilenameFilter;
class Java_io_InputStream;
class Java_io_PrintStream;
class Java_io_PrintWriter;
class Java_lang_Character;
class Java_lang_Error;
class Java_lang_Exception;
class Java_lang_IllegalStateException;
class Java_lang_Runnable;
class Java_lang_UnsupportedOperationException;
class Java_net_URI;
class Java_net_URL;
class Java_security_BasicPermission;
class Java_text_AttributedCharacterIterator;
class Java_text_AttributedCharacterIterator_Attribute;
class Java_text_CharacterIterator;
class Java_util_Collection;
class Java_util_Enumeration;
class Java_util_EventListener;
class Java_util_EventObject;
class Java_util_List;
class Java_util_Locale;
class Java_util_Map;
class Java_util_Properties;
class Java_util_Set;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_awt_AWTError extends Java_lang_Error;
class Java_awt_AWTEvent extends Java_util_EventObject;
class Java_awt_AWTEventMulticaster;
class Java_awt_AWTException extends Java_lang_Exception;
class Java_awt_AWTKeyStroke;
class Java_awt_AWTPermission extends Java_security_BasicPermission;
class Java_awt_ActiveEvent;
class Java_awt_Adjustable;
class Java_awt_AlphaComposite;
class Java_awt_BasicStroke;
class Java_awt_BorderLayout;
class Java_awt_BufferCapabilities;
class Java_awt_Component;
class Java_awt_Button extends Java_awt_Component;
class Java_awt_Canvas extends Java_awt_Component;
class Java_awt_CardLayout;
class Java_awt_Checkbox extends Java_awt_Component;
class Java_awt_CheckboxGroup;
class Java_awt_MenuComponent;
class Java_awt_MenuItem extends Java_awt_MenuComponent;
class Java_awt_CheckboxMenuItem extends Java_awt_MenuItem;
class Java_awt_Choice extends Java_awt_Component;
class Java_awt_Color;
class Java_awt_ComponentOrientation;
class Java_awt_Composite;
class Java_awt_CompositeContext;
class Java_awt_Container extends Java_awt_Component;
class Java_awt_FocusTraversalPolicy;
class Java_awt_ContainerOrderFocusTraversalPolicy extends Java_awt_FocusTraversalPolicy;
class Java_awt_Cursor;
class Java_awt_DefaultFocusTraversalPolicy extends Java_awt_ContainerOrderFocusTraversalPolicy;
class Java_awt_KeyboardFocusManager;
class Java_awt_DefaultKeyboardFocusManager extends Java_awt_KeyboardFocusManager;
class Java_awt_Desktop;
class Java_awt_Window extends Java_awt_Container;
class Java_awt_Dialog extends Java_awt_Window;
class Java_awt_Dimension extends Java_awt_geom_Dimension2D;
class Java_awt_DisplayMode;
class Java_awt_Event;
class Java_awt_EventQueue;
class Java_awt_FileDialog extends Java_awt_Dialog;
class Java_awt_FlowLayout;
class Java_awt_Font;
class Java_awt_FontFormatException extends Java_lang_Exception;
class Java_awt_FontMetrics;
class Java_awt_Frame extends Java_awt_Window;
class Java_awt_GradientPaint;
class Java_awt_Graphics;
class Java_awt_Graphics2D extends Java_awt_Graphics;
class Java_awt_GraphicsConfigTemplate;
class Java_awt_GraphicsConfiguration;
class Java_awt_GraphicsDevice;
class Java_awt_GraphicsEnvironment;
class Java_awt_GridBagConstraints;
class Java_awt_GridBagLayout;
class Java_awt_GridBagLayoutInfo;
class Java_awt_GridLayout;
class Java_awt_HeadlessException extends Java_lang_UnsupportedOperationException;
class Java_awt_IllegalComponentStateException extends Java_lang_IllegalStateException;
class Java_awt_Image;
class Java_awt_ImageCapabilities;
class Java_awt_Insets;
class Java_awt_ItemSelectable;
class Java_awt_JobAttributes;
class Java_awt_KeyEventDispatcher;
class Java_awt_KeyEventPostProcessor;
class Java_awt_Label extends Java_awt_Component;
class Java_awt_LayoutManager;
class Java_awt_LayoutManager2;
class Java_awt_MultipleGradientPaint;
class Java_awt_LinearGradientPaint extends Java_awt_MultipleGradientPaint;
class Java_awt_List extends Java_awt_Component;
class Java_awt_MediaTracker;
class Java_awt_Menu extends Java_awt_MenuItem;
class Java_awt_MenuBar extends Java_awt_MenuComponent;
class Java_awt_MenuContainer;
class Java_awt_MenuShortcut;
class Java_awt_MouseInfo;
class Java_awt_PageAttributes;
class Java_awt_Paint;
class Java_awt_PaintContext;
class Java_awt_Panel extends Java_awt_Container;
class Java_awt_Point extends Java_awt_geom_Point2D;
class Java_awt_PointerInfo;
class Java_awt_Polygon;
class Java_awt_PopupMenu extends Java_awt_Menu;
class Java_awt_PrintGraphics;
class Java_awt_PrintJob;
class Java_awt_RadialGradientPaint extends Java_awt_MultipleGradientPaint;
class Java_awt_Rectangle extends Java_awt_geom_Rectangle2D;
class Java_awt_RenderingHints;
class Java_awt_Robot;
class Java_awt_ScrollPane extends Java_awt_Container;
class Java_awt_ScrollPaneAdjustable;
class Java_awt_Scrollbar extends Java_awt_Component;
class Java_awt_SecondaryLoop;
class Java_awt_Shape;
class Java_awt_SplashScreen;
class Java_awt_Stroke;
class Java_awt_SystemColor extends Java_awt_Color;
class Java_awt_SystemTray;
class Java_awt_TextComponent extends Java_awt_Component;
class Java_awt_TextArea extends Java_awt_TextComponent;
class Java_awt_TextField extends Java_awt_TextComponent;
class Java_awt_TexturePaint;
class Java_awt_Toolkit;
class Java_awt_Transparency;
class Java_awt_TrayIcon;

/*------------------------------------------------------------*/
/* class java.awt.AWTError */
class Java_awt_AWTError extends Java_lang_Error {
}
Java_awt_AWTError Java_awt_AWTError.new(String p0);

/* class java.awt.AWTEvent */
class Java_awt_AWTEvent extends Java_util_EventObject {
	/*-- Method --*/
	@Virtual @Overload int getID();
	@Virtual @Overload String paramString();
	@Virtual @Overload void setSource(Object p0);
}
@Overload Java_awt_AWTEvent Java_awt_AWTEvent.new(Java_awt_Event p0);
@Overload Java_awt_AWTEvent Java_awt_AWTEvent.new(Object p0, int p1);

/* class java.awt.AWTEventMulticaster */
class Java_awt_AWTEventMulticaster {
	// implements java.awt.event.ComponentListener, java.awt.event.ContainerListener, java.awt.event.FocusListener, java.awt.event.KeyListener, java.awt.event.MouseListener, java.awt.event.MouseMotionListener, java.awt.event.WindowListener, java.awt.event.WindowFocusListener, java.awt.event.WindowStateListener, java.awt.event.ActionListener, java.awt.event.ItemListener, java.awt.event.AdjustmentListener, java.awt.event.TextListener, java.awt.event.InputMethodListener, java.awt.event.HierarchyListener, java.awt.event.HierarchyBoundsListener, java.awt.event.MouseWheelListener
	/*-- Method --*/
	@Virtual @Overload void actionPerformed(Java_awt_event_ActionEvent p0);
	@Virtual @Overload Java_awt_event_ComponentListener add(Java_awt_event_ComponentListener p0, Java_awt_event_ComponentListener p1);
	@Virtual @Overload Java_awt_event_ContainerListener add(Java_awt_event_ContainerListener p0, Java_awt_event_ContainerListener p1);
	@Virtual @Overload Java_awt_event_FocusListener add(Java_awt_event_FocusListener p0, Java_awt_event_FocusListener p1);
	@Virtual @Overload Java_awt_event_KeyListener add(Java_awt_event_KeyListener p0, Java_awt_event_KeyListener p1);
	@Virtual @Overload Java_awt_event_MouseListener add(Java_awt_event_MouseListener p0, Java_awt_event_MouseListener p1);
	@Virtual @Overload Java_awt_event_MouseMotionListener add(Java_awt_event_MouseMotionListener p0, Java_awt_event_MouseMotionListener p1);
	@Virtual @Overload Java_awt_event_WindowListener add(Java_awt_event_WindowListener p0, Java_awt_event_WindowListener p1);
	@Virtual @Overload Java_awt_event_WindowStateListener add(Java_awt_event_WindowStateListener p0, Java_awt_event_WindowStateListener p1);
	@Virtual @Overload Java_awt_event_WindowFocusListener add(Java_awt_event_WindowFocusListener p0, Java_awt_event_WindowFocusListener p1);
	@Virtual @Overload Java_awt_event_ActionListener add(Java_awt_event_ActionListener p0, Java_awt_event_ActionListener p1);
	@Virtual @Overload Java_awt_event_ItemListener add(Java_awt_event_ItemListener p0, Java_awt_event_ItemListener p1);
	@Virtual @Overload Java_awt_event_AdjustmentListener add(Java_awt_event_AdjustmentListener p0, Java_awt_event_AdjustmentListener p1);
	@Virtual @Overload Java_awt_event_TextListener add(Java_awt_event_TextListener p0, Java_awt_event_TextListener p1);
	@Virtual @Overload Java_awt_event_InputMethodListener add(Java_awt_event_InputMethodListener p0, Java_awt_event_InputMethodListener p1);
	@Virtual @Overload Java_awt_event_HierarchyListener add(Java_awt_event_HierarchyListener p0, Java_awt_event_HierarchyListener p1);
	@Virtual @Overload Java_awt_event_HierarchyBoundsListener add(Java_awt_event_HierarchyBoundsListener p0, Java_awt_event_HierarchyBoundsListener p1);
	@Virtual @Overload Java_awt_event_MouseWheelListener add(Java_awt_event_MouseWheelListener p0, Java_awt_event_MouseWheelListener p1);
	@Virtual @Overload void adjustmentValueChanged(Java_awt_event_AdjustmentEvent p0);
	@Virtual @Overload void ancestorMoved(Java_awt_event_HierarchyEvent p0);
	@Virtual @Overload void ancestorResized(Java_awt_event_HierarchyEvent p0);
	@Virtual @Overload void caretPositionChanged(Java_awt_event_InputMethodEvent p0);
	@Virtual @Overload void componentAdded(Java_awt_event_ContainerEvent p0);
	@Virtual @Overload void componentHidden(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentMoved(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentRemoved(Java_awt_event_ContainerEvent p0);
	@Virtual @Overload void componentResized(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void componentShown(Java_awt_event_ComponentEvent p0);
	@Virtual @Overload void focusGained(Java_awt_event_FocusEvent p0);
	@Virtual @Overload void focusLost(Java_awt_event_FocusEvent p0);
	@Virtual @Overload Java_util_EventListener[] getListeners(Java_util_EventListener p0, Class p1);
	@Virtual @Overload void hierarchyChanged(Java_awt_event_HierarchyEvent p0);
	@Virtual @Overload void inputMethodTextChanged(Java_awt_event_InputMethodEvent p0);
	@Virtual @Overload void itemStateChanged(Java_awt_event_ItemEvent p0);
	@Virtual @Overload void keyPressed(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyReleased(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void keyTyped(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void mouseClicked(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseDragged(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseEntered(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseExited(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseMoved(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mousePressed(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseReleased(Java_awt_event_MouseEvent p0);
	@Virtual @Overload void mouseWheelMoved(Java_awt_event_MouseWheelEvent p0);
	@Virtual @Overload Java_awt_event_ComponentListener remove(Java_awt_event_ComponentListener p0, Java_awt_event_ComponentListener p1);
	@Virtual @Overload Java_awt_event_ContainerListener remove(Java_awt_event_ContainerListener p0, Java_awt_event_ContainerListener p1);
	@Virtual @Overload Java_awt_event_FocusListener remove(Java_awt_event_FocusListener p0, Java_awt_event_FocusListener p1);
	@Virtual @Overload Java_awt_event_KeyListener remove(Java_awt_event_KeyListener p0, Java_awt_event_KeyListener p1);
	@Virtual @Overload Java_awt_event_MouseListener remove(Java_awt_event_MouseListener p0, Java_awt_event_MouseListener p1);
	@Virtual @Overload Java_awt_event_MouseMotionListener remove(Java_awt_event_MouseMotionListener p0, Java_awt_event_MouseMotionListener p1);
	@Virtual @Overload Java_awt_event_WindowListener remove(Java_awt_event_WindowListener p0, Java_awt_event_WindowListener p1);
	@Virtual @Overload Java_awt_event_WindowStateListener remove(Java_awt_event_WindowStateListener p0, Java_awt_event_WindowStateListener p1);
	@Virtual @Overload Java_awt_event_WindowFocusListener remove(Java_awt_event_WindowFocusListener p0, Java_awt_event_WindowFocusListener p1);
	@Virtual @Overload Java_awt_event_ActionListener remove(Java_awt_event_ActionListener p0, Java_awt_event_ActionListener p1);
	@Virtual @Overload Java_awt_event_ItemListener remove(Java_awt_event_ItemListener p0, Java_awt_event_ItemListener p1);
	@Virtual @Overload Java_awt_event_AdjustmentListener remove(Java_awt_event_AdjustmentListener p0, Java_awt_event_AdjustmentListener p1);
	@Virtual @Overload Java_awt_event_TextListener remove(Java_awt_event_TextListener p0, Java_awt_event_TextListener p1);
	@Virtual @Overload Java_awt_event_InputMethodListener remove(Java_awt_event_InputMethodListener p0, Java_awt_event_InputMethodListener p1);
	@Virtual @Overload Java_awt_event_HierarchyListener remove(Java_awt_event_HierarchyListener p0, Java_awt_event_HierarchyListener p1);
	@Virtual @Overload Java_awt_event_HierarchyBoundsListener remove(Java_awt_event_HierarchyBoundsListener p0, Java_awt_event_HierarchyBoundsListener p1);
	@Virtual @Overload Java_awt_event_MouseWheelListener remove(Java_awt_event_MouseWheelListener p0, Java_awt_event_MouseWheelListener p1);
	@Virtual @Overload void textValueChanged(Java_awt_event_TextEvent p0);
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

/* class java.awt.AWTException */
class Java_awt_AWTException extends Java_lang_Exception {
}
Java_awt_AWTException Java_awt_AWTException.new(String p0);

/* class java.awt.AWTKeyStroke */
class Java_awt_AWTKeyStroke {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStroke(int p0);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStroke(Java_lang_Character p0, int p1);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStroke(int p0, int p1, boolean p2);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStroke(int p0, int p1);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStroke(String p0);
	@Virtual @Overload Java_awt_AWTKeyStroke getAWTKeyStrokeForEvent(Java_awt_event_KeyEvent p0);
	@Virtual @Overload int getKeyChar();
	@Virtual @Overload int getKeyCode();
	@Virtual @Overload int getKeyEventType();
	@Virtual @Overload int getModifiers();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isOnKeyRelease();
	@Virtual @Overload String toString();
}

/* class java.awt.AWTPermission */
class Java_awt_AWTPermission extends Java_security_BasicPermission {
}
@Overload Java_awt_AWTPermission Java_awt_AWTPermission.new(String p0);
@Overload Java_awt_AWTPermission Java_awt_AWTPermission.new(String p0, String p1);

/* interface java.awt.ActiveEvent */
class Java_awt_ActiveEvent {
	/*-- Method --*/
	@Virtual @Overload void dispatch();
}

/* interface java.awt.Adjustable */
class Java_awt_Adjustable {
	/*-- Method --*/
	@Virtual @Overload void addAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload int getBlockIncrement();
	@Virtual @Overload int getMaximum();
	@Virtual @Overload int getMinimum();
	@Virtual @Overload int getOrientation();
	@Virtual @Overload int getUnitIncrement();
	@Virtual @Overload int getValue();
	@Virtual @Overload int getVisibleAmount();
	@Virtual @Overload void removeAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload void setBlockIncrement(int p0);
	@Virtual @Overload void setMaximum(int p0);
	@Virtual @Overload void setMinimum(int p0);
	@Virtual @Overload void setUnitIncrement(int p0);
	@Virtual @Overload void setValue(int p0);
	@Virtual @Overload void setVisibleAmount(int p0);
}

/* class java.awt.AlphaComposite */
class Java_awt_AlphaComposite {
	// implements java.awt.Composite
	/*-- Method --*/
	@Virtual @Overload Java_awt_CompositeContext createContext(Java_awt_image_ColorModel p0, Java_awt_image_ColorModel p1, Java_awt_RenderingHints p2);
	@Virtual @Overload Java_awt_AlphaComposite derive(int p0);
	@Virtual @Overload Java_awt_AlphaComposite derive(float p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload float getAlpha();
	@Virtual @Overload Java_awt_AlphaComposite getInstance(int p0);
	@Virtual @Overload Java_awt_AlphaComposite getInstance(int p0, float p1);
	@Virtual @Overload int getRule();
	//@Virtual @Overload int hashCode();
}

/* class java.awt.BasicStroke */
class Java_awt_BasicStroke {
	// implements java.awt.Stroke
	/*-- Method --*/
	@Virtual @Overload Java_awt_Shape createStrokedShape(Java_awt_Shape p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload float[] getDashArray();
	@Virtual @Overload float getDashPhase();
	@Virtual @Overload int getEndCap();
	@Virtual @Overload int getLineJoin();
	@Virtual @Overload float getLineWidth();
	@Virtual @Overload float getMiterLimit();
	//@Virtual @Overload int hashCode();
}
@Overload Java_awt_BasicStroke Java_awt_BasicStroke.new(float p0, int p1, int p2, float p3, float[] p4, float p5);
@Overload Java_awt_BasicStroke Java_awt_BasicStroke.new(float p0, int p1, int p2, float p3);
@Overload Java_awt_BasicStroke Java_awt_BasicStroke.new(float p0, int p1, int p2);
@Overload Java_awt_BasicStroke Java_awt_BasicStroke.new(float p0);
@Overload Java_awt_BasicStroke Java_awt_BasicStroke.new();

/* class java.awt.BorderLayout */
class Java_awt_BorderLayout {
	// implements java.awt.LayoutManager2, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(Java_awt_Component p0, Object p1);
	@Virtual @Overload Object getConstraints(Java_awt_Component p0);
	@Virtual @Overload int getHgap();
	@Virtual @Overload float getLayoutAlignmentX(Java_awt_Container p0);
	@Virtual @Overload float getLayoutAlignmentY(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Component getLayoutComponent(Object p0);
	@Virtual @Overload Java_awt_Component getLayoutComponent(Java_awt_Container p0, Object p1);
	@Virtual @Overload int getVgap();
	@Virtual @Overload void invalidateLayout(Java_awt_Container p0);
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension maximumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
	@Virtual @Overload void setHgap(int p0);
	@Virtual @Overload void setVgap(int p0);
	@Virtual @Overload String toString();
}
@Overload Java_awt_BorderLayout Java_awt_BorderLayout.new();
@Overload Java_awt_BorderLayout Java_awt_BorderLayout.new(int p0, int p1);

/* class java.awt.BufferCapabilities */
class Java_awt_BufferCapabilities {
	// implements java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload Java_awt_ImageCapabilities getBackBufferCapabilities();
	@Virtual @Overload Java_awt_BufferCapabilities_FlipContents getFlipContents();
	@Virtual @Overload Java_awt_ImageCapabilities getFrontBufferCapabilities();
	@Virtual @Overload boolean isFullScreenRequired();
	@Virtual @Overload boolean isMultiBufferAvailable();
	@Virtual @Overload boolean isPageFlipping();
}
Java_awt_BufferCapabilities Java_awt_BufferCapabilities.new(Java_awt_ImageCapabilities p0, Java_awt_ImageCapabilities p1, Java_awt_BufferCapabilities_FlipContents p2);

/* class java.awt.Button */
class Java_awt_Button extends Java_awt_Component {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload String getActionCommand();
	@Virtual @Overload Java_awt_event_ActionListener[] getActionListeners();
	@Virtual @Overload String getLabel();
	@Virtual @Overload void removeActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void setActionCommand(String p0);
	@Virtual @Overload void setLabel(String p0);
}
@Overload Java_awt_Button Java_awt_Button.new();
@Overload Java_awt_Button Java_awt_Button.new(String p0);

/* class java.awt.Canvas */
class Java_awt_Canvas extends Java_awt_Component {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void createBufferStrategy(int p0);
	@Virtual @Overload void createBufferStrategy(int p0, Java_awt_BufferCapabilities p1);
	@Virtual @Overload Java_awt_image_BufferStrategy getBufferStrategy();
}
@Overload Java_awt_Canvas Java_awt_Canvas.new();
@Overload Java_awt_Canvas Java_awt_Canvas.new(Java_awt_GraphicsConfiguration p0);

/* class java.awt.CardLayout */
class Java_awt_CardLayout {
	// implements java.awt.LayoutManager2, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(Java_awt_Component p0, Object p1);
	@Virtual @Overload void first(Java_awt_Container p0);
	@Virtual @Overload int getHgap();
	@Virtual @Overload float getLayoutAlignmentX(Java_awt_Container p0);
	@Virtual @Overload float getLayoutAlignmentY(Java_awt_Container p0);
	@Virtual @Overload int getVgap();
	@Virtual @Overload void invalidateLayout(Java_awt_Container p0);
	@Virtual @Overload void last(Java_awt_Container p0);
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension maximumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void next(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void previous(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
	@Virtual @Overload void setHgap(int p0);
	@Virtual @Overload void setVgap(int p0);
	@Virtual @Overload void show(Java_awt_Container p0, String p1);
	@Virtual @Overload String toString();
}
@Overload Java_awt_CardLayout Java_awt_CardLayout.new();
@Overload Java_awt_CardLayout Java_awt_CardLayout.new(int p0, int p1);

/* class java.awt.Checkbox */
class Java_awt_Checkbox extends Java_awt_Component {
	// implements java.awt.ItemSelectable, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload Java_awt_CheckboxGroup getCheckboxGroup();
	@Virtual @Overload Java_awt_event_ItemListener[] getItemListeners();
	@Virtual @Overload String getLabel();
	@Virtual @Overload Object[] getSelectedObjects();
	@Virtual @Overload boolean getState();
	@Virtual @Overload void removeItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload void setCheckboxGroup(Java_awt_CheckboxGroup p0);
	@Virtual @Overload void setLabel(String p0);
	@Virtual @Overload void setState(boolean p0);
}
@Overload Java_awt_Checkbox Java_awt_Checkbox.new();
@Overload Java_awt_Checkbox Java_awt_Checkbox.new(String p0);
@Overload Java_awt_Checkbox Java_awt_Checkbox.new(String p0, boolean p1);
@Overload Java_awt_Checkbox Java_awt_Checkbox.new(String p0, boolean p1, Java_awt_CheckboxGroup p2);
@Overload Java_awt_Checkbox Java_awt_Checkbox.new(String p0, Java_awt_CheckboxGroup p1, boolean p2);

/* class java.awt.CheckboxGroup */
class Java_awt_CheckboxGroup {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_Checkbox getSelectedCheckbox();
	@Virtual @Overload void setSelectedCheckbox(Java_awt_Checkbox p0);
	@Virtual @Overload String toString();
}
Java_awt_CheckboxGroup Java_awt_CheckboxGroup.new();

/* class java.awt.CheckboxMenuItem */
class Java_awt_CheckboxMenuItem extends Java_awt_MenuItem {
	// implements java.awt.ItemSelectable, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload Java_awt_event_ItemListener[] getItemListeners();
	@Virtual @Overload Object[] getSelectedObjects();
	@Virtual @Overload boolean getState();
	@Virtual @Overload void removeItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload void setState(boolean p0);
}
@Overload Java_awt_CheckboxMenuItem Java_awt_CheckboxMenuItem.new();
@Overload Java_awt_CheckboxMenuItem Java_awt_CheckboxMenuItem.new(String p0);
@Overload Java_awt_CheckboxMenuItem Java_awt_CheckboxMenuItem.new(String p0, boolean p1);

/* class java.awt.Choice */
class Java_awt_Choice extends Java_awt_Component {
	// implements java.awt.ItemSelectable, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void add(String p0);
	@Virtual @Overload void addItem(String p0);
	@Virtual @Overload void addItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload String getItem(int p0);
	@Virtual @Overload int getItemCount();
	@Virtual @Overload Java_awt_event_ItemListener[] getItemListeners();
	@Virtual @Overload int getSelectedIndex();
	@Virtual @Overload String getSelectedItem();
	@Virtual @Overload Object[] getSelectedObjects();
	@Virtual @Overload void insert(String p0, int p1);
	@Virtual @Overload void remove(String p0);
	@Virtual @Overload void remove(int p0);
	@Virtual @Overload void removeAll();
	@Virtual @Overload void removeItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload void select(int p0);
	@Virtual @Overload void select(String p0);
}
Java_awt_Choice Java_awt_Choice.new();

/* class java.awt.Color */
class Java_awt_Color {
	// implements java.awt.Paint, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload int HSBtoRGB(float p0, float p1, float p2);
	@Virtual @Overload float[] RGBtoHSB(int p0, int p1, int p2, float[] p3);
	@Virtual @Overload Java_awt_Color brighter();
	@Virtual @Overload Java_awt_PaintContext createContext(Java_awt_image_ColorModel p0, Java_awt_Rectangle p1, Java_awt_geom_Rectangle2D p2, Java_awt_geom_AffineTransform p3, Java_awt_RenderingHints p4);
	@Virtual @Overload Java_awt_Color darker();
	@Virtual @Overload Java_awt_Color decode(String p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int getAlpha();
	@Virtual @Overload int getBlue();
	@Virtual @Overload Java_awt_Color getColor(String p0);
	@Virtual @Overload Java_awt_Color getColor(String p0, Java_awt_Color p1);
	@Virtual @Overload Java_awt_Color getColor(String p0, int p1);
	@Virtual @Overload float[] getColorComponents(float[] p0);
	@Virtual @Overload float[] getColorComponents(Java_awt_color_ColorSpace p0, float[] p1);
	@Virtual @Overload Java_awt_color_ColorSpace getColorSpace();
	@Virtual @Overload float[] getComponents(float[] p0);
	@Virtual @Overload float[] getComponents(Java_awt_color_ColorSpace p0, float[] p1);
	@Virtual @Overload int getGreen();
	@Virtual @Overload Java_awt_Color getHSBColor(float p0, float p1, float p2);
	@Virtual @Overload int getRGB();
	@Virtual @Overload float[] getRGBColorComponents(float[] p0);
	@Virtual @Overload float[] getRGBComponents(float[] p0);
	@Virtual @Overload int getRed();
	@Virtual @Overload int getTransparency();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
}
@Overload Java_awt_Color Java_awt_Color.new(int p0, int p1, int p2);
@Overload Java_awt_Color Java_awt_Color.new(int p0, int p1, int p2, int p3);
@Overload Java_awt_Color Java_awt_Color.new(int p0);
@Overload Java_awt_Color Java_awt_Color.new(int p0, boolean p1);
@Overload Java_awt_Color Java_awt_Color.new(float p0, float p1, float p2);
@Overload Java_awt_Color Java_awt_Color.new(float p0, float p1, float p2, float p3);
@Overload Java_awt_Color Java_awt_Color.new(Java_awt_color_ColorSpace p0, float[] p1, float p2);

/* class java.awt.Component */
class Java_awt_Component {
	// implements java.awt.image.ImageObserver, java.awt.MenuContainer, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void add(Java_awt_PopupMenu p0);
	@Virtual @Overload void addComponentListener(Java_awt_event_ComponentListener p0);
	@Virtual @Overload void addFocusListener(Java_awt_event_FocusListener p0);
	@Virtual @Overload void addHierarchyBoundsListener(Java_awt_event_HierarchyBoundsListener p0);
	@Virtual @Overload void addHierarchyListener(Java_awt_event_HierarchyListener p0);
	@Virtual @Overload void addInputMethodListener(Java_awt_event_InputMethodListener p0);
	@Virtual @Overload void addKeyListener(Java_awt_event_KeyListener p0);
	@Virtual @Overload void addMouseListener(Java_awt_event_MouseListener p0);
	@Virtual @Overload void addMouseMotionListener(Java_awt_event_MouseMotionListener p0);
	@Virtual @Overload void addMouseWheelListener(Java_awt_event_MouseWheelListener p0);
	@Virtual @Overload void addNotify();
	@Virtual @Overload void addPropertyChangeListener(Java_beans_PropertyChangeListener p0);
	@Virtual @Overload void addPropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload void applyComponentOrientation(Java_awt_ComponentOrientation p0);
	@Virtual @Overload boolean areFocusTraversalKeysSet(int p0);
	@Virtual @Overload int checkImage(Java_awt_Image p0, Java_awt_image_ImageObserver p1);
	@Virtual @Overload int checkImage(Java_awt_Image p0, int p1, int p2, Java_awt_image_ImageObserver p3);
	@Virtual @Overload boolean contains(int p0, int p1);
	@Virtual @Overload boolean contains(Java_awt_Point p0);
	@Virtual @Overload Java_awt_Image createImage(Java_awt_image_ImageProducer p0);
	@Virtual @Overload Java_awt_Image createImage(int p0, int p1);
	@Virtual @Overload Java_awt_image_VolatileImage createVolatileImage(int p0, int p1);
	@Virtual @Overload Java_awt_image_VolatileImage createVolatileImage(int p0, int p1, Java_awt_ImageCapabilities p2);
	@Virtual @Overload void dispatchEvent(Java_awt_AWTEvent p0);
	@Virtual @Overload void doLayout();
	@Virtual @Overload void enableInputMethods(boolean p0);
	@Virtual @Overload void firePropertyChange(String p0, int p1, int p2);
	@Virtual @Overload void firePropertyChange(String p0, int p1, int p2);
	@Virtual @Overload void firePropertyChange(String p0, int p1, int p2);
	@Virtual @Overload void firePropertyChange(String p0, long p1, long p2);
	@Virtual @Overload void firePropertyChange(String p0, float p1, float p2);
	@Virtual @Overload void firePropertyChange(String p0, double p1, double p2);
	@Virtual @Overload javax.accessibility.AccessibleContext getAccessibleContext();
	@Virtual @Overload float getAlignmentX();
	@Virtual @Overload float getAlignmentY();
	@Virtual @Overload Java_awt_Color getBackground();
	@Virtual @Overload int getBaseline(int p0, int p1);
	@Virtual @Overload Java_awt_Component_BaselineResizeBehavior getBaselineResizeBehavior();
	@Virtual @Overload Java_awt_Rectangle getBounds();
	@Virtual @Overload Java_awt_Rectangle getBounds(Java_awt_Rectangle p0);
	@Virtual @Overload Java_awt_image_ColorModel getColorModel();
	@Virtual @Overload Java_awt_Component getComponentAt(int p0, int p1);
	@Virtual @Overload Java_awt_Component getComponentAt(Java_awt_Point p0);
	@Virtual @Overload Java_awt_event_ComponentListener[] getComponentListeners();
	@Virtual @Overload Java_awt_ComponentOrientation getComponentOrientation();
	@Virtual @Overload Java_awt_Cursor getCursor();
	@Virtual @Overload Java_awt_dnd_DropTarget getDropTarget();
	@Virtual @Overload Java_awt_Container getFocusCycleRootAncestor();
	@Virtual @Overload Java_awt_event_FocusListener[] getFocusListeners();
	@Virtual @Overload Java_util_Set getFocusTraversalKeys(int p0);
	@Virtual @Overload boolean getFocusTraversalKeysEnabled();
	@Virtual @Overload Java_awt_Font getFont();
	@Virtual @Overload Java_awt_FontMetrics getFontMetrics(Java_awt_Font p0);
	@Virtual @Overload Java_awt_Color getForeground();
	@Virtual @Overload Java_awt_Graphics getGraphics();
	@Virtual @Overload Java_awt_GraphicsConfiguration getGraphicsConfiguration();
	@Virtual @Overload int getHeight();
	@Virtual @Overload Java_awt_event_HierarchyBoundsListener[] getHierarchyBoundsListeners();
	@Virtual @Overload Java_awt_event_HierarchyListener[] getHierarchyListeners();
	@Virtual @Overload boolean getIgnoreRepaint();
	@Virtual @Overload Java_awt_im_InputContext getInputContext();
	@Virtual @Overload Java_awt_event_InputMethodListener[] getInputMethodListeners();
	@Virtual @Overload Java_awt_im_InputMethodRequests getInputMethodRequests();
	@Virtual @Overload Java_awt_event_KeyListener[] getKeyListeners();
	@Virtual @Overload Java_util_EventListener[] getListeners(Class p0);
	@Virtual @Overload Java_util_Locale getLocale();
	@Virtual @Overload Java_awt_Point getLocation();
	@Virtual @Overload Java_awt_Point getLocation(Java_awt_Point p0);
	@Virtual @Overload Java_awt_Point getLocationOnScreen();
	@Virtual @Overload Java_awt_Dimension getMaximumSize();
	@Virtual @Overload Java_awt_Dimension getMinimumSize();
	@Virtual @Overload Java_awt_event_MouseListener[] getMouseListeners();
	@Virtual @Overload Java_awt_event_MouseMotionListener[] getMouseMotionListeners();
	@Virtual @Overload Java_awt_Point getMousePosition();
	@Virtual @Overload Java_awt_event_MouseWheelListener[] getMouseWheelListeners();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_awt_Container getParent();
	@Virtual @Overload Java_awt_Dimension getPreferredSize();
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners();
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners(String p0);
	@Virtual @Overload Java_awt_Dimension getSize();
	@Virtual @Overload Java_awt_Dimension getSize(Java_awt_Dimension p0);
	@Virtual @Overload Java_awt_Toolkit getToolkit();
	@Virtual @Overload Object getTreeLock();
	@Virtual @Overload int getWidth();
	@Virtual @Overload int getX();
	@Virtual @Overload int getY();
	@Virtual @Overload boolean hasFocus();
	@Virtual @Overload boolean imageUpdate(Java_awt_Image p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void invalidate();
	@Virtual @Overload boolean isBackgroundSet();
	@Virtual @Overload boolean isCursorSet();
	@Virtual @Overload boolean isDisplayable();
	@Virtual @Overload boolean isDoubleBuffered();
	@Virtual @Overload boolean isEnabled();
	@Virtual @Overload boolean isFocusCycleRoot(Java_awt_Container p0);
	@Virtual @Overload boolean isFocusOwner();
	@Virtual @Overload boolean isFocusable();
	@Virtual @Overload boolean isFontSet();
	@Virtual @Overload boolean isForegroundSet();
	@Virtual @Overload boolean isLightweight();
	@Virtual @Overload boolean isMaximumSizeSet();
	@Virtual @Overload boolean isMinimumSizeSet();
	@Virtual @Overload boolean isOpaque();
	@Virtual @Overload boolean isPreferredSizeSet();
	@Virtual @Overload boolean isShowing();
	@Virtual @Overload boolean isValid();
	@Virtual @Overload boolean isVisible();
	@Virtual @Overload void list();
	@Virtual @Overload void list(Java_io_PrintStream p0);
	@Virtual @Overload void list(Java_io_PrintStream p0, int p1);
	@Virtual @Overload void list(Java_io_PrintWriter p0);
	@Virtual @Overload void list(Java_io_PrintWriter p0, int p1);
	@Virtual @Overload void paint(Java_awt_Graphics p0);
	@Virtual @Overload void paintAll(Java_awt_Graphics p0);
	@Virtual @Overload boolean prepareImage(Java_awt_Image p0, Java_awt_image_ImageObserver p1);
	@Virtual @Overload boolean prepareImage(Java_awt_Image p0, int p1, int p2, Java_awt_image_ImageObserver p3);
	//@Virtual @Overload void print(Java_awt_Graphics p0);
	@Virtual @Overload void printAll(Java_awt_Graphics p0);
	@Virtual @Overload void remove(Java_awt_MenuComponent p0);
	@Virtual @Overload void removeComponentListener(Java_awt_event_ComponentListener p0);
	@Virtual @Overload void removeFocusListener(Java_awt_event_FocusListener p0);
	@Virtual @Overload void removeHierarchyBoundsListener(Java_awt_event_HierarchyBoundsListener p0);
	@Virtual @Overload void removeHierarchyListener(Java_awt_event_HierarchyListener p0);
	@Virtual @Overload void removeInputMethodListener(Java_awt_event_InputMethodListener p0);
	@Virtual @Overload void removeKeyListener(Java_awt_event_KeyListener p0);
	@Virtual @Overload void removeMouseListener(Java_awt_event_MouseListener p0);
	@Virtual @Overload void removeMouseMotionListener(Java_awt_event_MouseMotionListener p0);
	@Virtual @Overload void removeMouseWheelListener(Java_awt_event_MouseWheelListener p0);
	@Virtual @Overload void removeNotify();
	@Virtual @Overload void removePropertyChangeListener(Java_beans_PropertyChangeListener p0);
	@Virtual @Overload void removePropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload void repaint();
	@Virtual @Overload void repaint(long p0);
	@Virtual @Overload void repaint(int p0, int p1, int p2, int p3);
	@Virtual @Overload void repaint(long p0, int p1, int p2, int p3, int p4);
	@Virtual @Overload void requestFocus();
	@Virtual @Overload boolean requestFocusInWindow();
	@Virtual @Overload void revalidate();
	@Virtual @Overload void setBackground(Java_awt_Color p0);
	@Virtual @Overload void setBounds(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setBounds(Java_awt_Rectangle p0);
	@Virtual @Overload void setComponentOrientation(Java_awt_ComponentOrientation p0);
	@Virtual @Overload void setCursor(Java_awt_Cursor p0);
	@Virtual @Overload void setDropTarget(Java_awt_dnd_DropTarget p0);
	@Virtual @Overload void setEnabled(boolean p0);
	@Virtual @Overload void setFocusTraversalKeys(int p0, Java_util_Set p1);
	@Virtual @Overload void setFocusTraversalKeysEnabled(boolean p0);
	@Virtual @Overload void setFocusable(boolean p0);
	@Virtual @Overload void setFont(Java_awt_Font p0);
	@Virtual @Overload void setForeground(Java_awt_Color p0);
	@Virtual @Overload void setIgnoreRepaint(boolean p0);
	@Virtual @Overload void setLocale(Java_util_Locale p0);
	@Virtual @Overload void setLocation(int p0, int p1);
	@Virtual @Overload void setLocation(Java_awt_Point p0);
	@Virtual @Overload void setMaximumSize(Java_awt_Dimension p0);
	@Virtual @Overload void setMinimumSize(Java_awt_Dimension p0);
	@Virtual @Overload void setName(String p0);
	@Virtual @Overload void setPreferredSize(Java_awt_Dimension p0);
	@Virtual @Overload void setSize(int p0, int p1);
	@Virtual @Overload void setSize(Java_awt_Dimension p0);
	@Virtual @Overload void setVisible(boolean p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void transferFocus();
	@Virtual @Overload void transferFocusBackward();
	@Virtual @Overload void transferFocusUpCycle();
	@Virtual @Overload void update(Java_awt_Graphics p0);
	@Virtual @Overload void validate();
}

/* class java.awt.ComponentOrientation */
class Java_awt_ComponentOrientation {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_ComponentOrientation getOrientation(Java_util_Locale p0);
	@Virtual @Overload boolean isHorizontal();
	@Virtual @Overload boolean isLeftToRight();
}

/* interface java.awt.Composite */
class Java_awt_Composite {
	/*-- Method --*/
	@Virtual @Overload Java_awt_CompositeContext createContext(Java_awt_image_ColorModel p0, Java_awt_image_ColorModel p1, Java_awt_RenderingHints p2);
}

/* interface java.awt.CompositeContext */
class Java_awt_CompositeContext {
	/*-- Method --*/
	@Virtual @Overload void compose(Java_awt_image_Raster p0, Java_awt_image_Raster p1, Java_awt_image_WritableRaster p2);
	@Virtual @Overload void dispose();
}

/* class java.awt.Container */
class Java_awt_Container extends Java_awt_Component {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Component add(Java_awt_Component p0);
	@Virtual @Overload Java_awt_Component add(String p0, Java_awt_Component p1);
	@Virtual @Overload Java_awt_Component add(Java_awt_Component p0, int p1);
	@Virtual @Overload void add(Java_awt_Component p0, Object p1);
	@Virtual @Overload void add(Java_awt_Component p0, Object p1, int p2);
	@Virtual @Overload void addContainerListener(Java_awt_event_ContainerListener p0);
	@Virtual @Overload Java_awt_Component findComponentAt(int p0, int p1);
	@Virtual @Overload Java_awt_Component findComponentAt(Java_awt_Point p0);
	@Virtual @Overload Java_awt_Component getComponent(int p0);
	@Virtual @Overload int getComponentCount();
	@Virtual @Overload int getComponentZOrder(Java_awt_Component p0);
	@Virtual @Overload Java_awt_Component[] getComponents();
	@Virtual @Overload Java_awt_event_ContainerListener[] getContainerListeners();
	@Virtual @Overload Java_awt_FocusTraversalPolicy getFocusTraversalPolicy();
	@Virtual @Overload Java_awt_Insets getInsets();
	@Virtual @Overload Java_awt_LayoutManager getLayout();
	@Virtual @Overload Java_awt_Point getMousePosition(boolean p0);
	@Virtual @Overload boolean isAncestorOf(Java_awt_Component p0);
	@Virtual @Overload boolean isFocusCycleRoot();
	@Virtual @Overload boolean isFocusTraversalPolicyProvider();
	@Virtual @Overload boolean isFocusTraversalPolicySet();
	@Virtual @Overload boolean isValidateRoot();
	@Virtual @Overload void paintComponents(Java_awt_Graphics p0);
	@Virtual @Overload void printComponents(Java_awt_Graphics p0);
	@Virtual @Overload void remove(int p0);
	@Virtual @Overload void remove(Java_awt_Component p0);
	@Virtual @Overload void removeAll();
	@Virtual @Overload void removeContainerListener(Java_awt_event_ContainerListener p0);
	@Virtual @Overload void setComponentZOrder(Java_awt_Component p0, int p1);
	@Virtual @Overload void setFocusCycleRoot(boolean p0);
	@Virtual @Overload void setFocusTraversalPolicy(Java_awt_FocusTraversalPolicy p0);
	@Virtual @Overload void setFocusTraversalPolicyProvider(boolean p0);
	@Virtual @Overload void setLayout(Java_awt_LayoutManager p0);
	@Virtual @Overload void transferFocusDownCycle();
}
Java_awt_Container Java_awt_Container.new();

/* class java.awt.ContainerOrderFocusTraversalPolicy */
class Java_awt_ContainerOrderFocusTraversalPolicy extends Java_awt_FocusTraversalPolicy {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean getImplicitDownCycleTraversal();
	@Virtual @Overload void setImplicitDownCycleTraversal(boolean p0);
}
Java_awt_ContainerOrderFocusTraversalPolicy Java_awt_ContainerOrderFocusTraversalPolicy.new();

/* class java.awt.Cursor */
class Java_awt_Cursor {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_Cursor getDefaultCursor();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_awt_Cursor getPredefinedCursor(int p0);
	@Virtual @Overload Java_awt_Cursor getSystemCustomCursor(String p0);
	@Virtual @Overload int getType();
	@Virtual @Overload String toString();
}
Java_awt_Cursor Java_awt_Cursor.new(int p0);

/* class java.awt.DefaultFocusTraversalPolicy */
class Java_awt_DefaultFocusTraversalPolicy extends Java_awt_ContainerOrderFocusTraversalPolicy {
}
Java_awt_DefaultFocusTraversalPolicy Java_awt_DefaultFocusTraversalPolicy.new();

/* class java.awt.DefaultKeyboardFocusManager */
class Java_awt_DefaultKeyboardFocusManager extends Java_awt_KeyboardFocusManager {
}
Java_awt_DefaultKeyboardFocusManager Java_awt_DefaultKeyboardFocusManager.new();

/* class java.awt.Desktop */
class Java_awt_Desktop {
	/*-- Method --*/
	@Virtual @Overload void browse(Java_net_URI p0);
	@Virtual @Overload void edit(Java_io_File p0);
	@Virtual @Overload Java_awt_Desktop getDesktop();
	@Virtual @Overload boolean isDesktopSupported();
	@Virtual @Overload boolean isSupported(Java_awt_Desktop_Action p0);
	@Virtual @Overload void mail();
	@Virtual @Overload void mail(Java_net_URI p0);
	@Virtual @Overload void open(Java_io_File p0);
	//@Virtual @Overload void print(Java_io_File p0);
}

/* class java.awt.Dialog */
class Java_awt_Dialog extends Java_awt_Window {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Dialog_ModalityType getModalityType();
	@Virtual @Overload String getTitle();
	@Virtual @Overload boolean isModal();
	@Virtual @Overload boolean isResizable();
	@Virtual @Overload boolean isUndecorated();
	@Virtual @Overload void setModal(boolean p0);
	@Virtual @Overload void setModalityType(Java_awt_Dialog_ModalityType p0);
	@Virtual @Overload void setResizable(boolean p0);
	@Virtual @Overload void setTitle(String p0);
	@Virtual @Overload void setUndecorated(boolean p0);
}
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Frame p0);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Frame p0, boolean p1);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Frame p0, String p1);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Frame p0, String p1, boolean p2);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Frame p0, String p1, boolean p2, Java_awt_GraphicsConfiguration p3);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Dialog p0);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Dialog p0, String p1);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Dialog p0, String p1, boolean p2);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Dialog p0, String p1, boolean p2, Java_awt_GraphicsConfiguration p3);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Window p0);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Window p0, String p1);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Window p0, Java_awt_Dialog_ModalityType p1);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Window p0, String p1, Java_awt_Dialog_ModalityType p2);
@Overload Java_awt_Dialog Java_awt_Dialog.new(Java_awt_Window p0, String p1, Java_awt_Dialog_ModalityType p2, Java_awt_GraphicsConfiguration p3);

/* class java.awt.Dimension */
class Java_awt_Dimension extends Java_awt_geom_Dimension2D {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_Dimension getSize();
	@Virtual @Overload void setSize(Java_awt_Dimension p0);
	@Virtual @Overload void setSize(int p0, int p1);
}
@Overload Java_awt_Dimension Java_awt_Dimension.new();
@Overload Java_awt_Dimension Java_awt_Dimension.new(Java_awt_Dimension p0);
@Overload Java_awt_Dimension Java_awt_Dimension.new(int p0, int p1);

/* class java.awt.DisplayMode */
class Java_awt_DisplayMode {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Java_awt_DisplayMode p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int getBitDepth();
	@Virtual @Overload int getHeight();
	@Virtual @Overload int getRefreshRate();
	@Virtual @Overload int getWidth();
	//@Virtual @Overload int hashCode();
}
Java_awt_DisplayMode Java_awt_DisplayMode.new(int p0, int p1, int p2, int p3);

/* class java.awt.Event */
class Java_awt_Event {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean controlDown();
	@Virtual @Overload boolean metaDown();
	@Virtual @Overload boolean shiftDown();
	@Virtual @Overload String toString();
	@Virtual @Overload void translate(int p0, int p1);
}
@Overload Java_awt_Event Java_awt_Event.new(Object p0, long p1, int p2, int p3, int p4, int p5, int p6, Object p7);
@Overload Java_awt_Event Java_awt_Event.new(Object p0, long p1, int p2, int p3, int p4, int p5, int p6);
@Overload Java_awt_Event Java_awt_Event.new(Object p0, int p1, Object p2);

/* class java.awt.EventQueue */
class Java_awt_EventQueue {
	/*-- Method --*/
	@Virtual @Overload Java_awt_SecondaryLoop createSecondaryLoop();
	@Virtual @Overload Java_awt_AWTEvent getCurrentEvent();
	@Virtual @Overload long getMostRecentEventTime();
	@Virtual @Overload Java_awt_AWTEvent getNextEvent();
	@Virtual @Overload void invokeAndWait(Java_lang_Runnable p0);
	@Virtual @Overload void invokeLater(Java_lang_Runnable p0);
	@Virtual @Overload boolean isDispatchThread();
	@Virtual @Overload Java_awt_AWTEvent peekEvent();
	@Virtual @Overload Java_awt_AWTEvent peekEvent(int p0);
	@Virtual @Overload void postEvent(Java_awt_AWTEvent p0);
	@Virtual @Overload void push(Java_awt_EventQueue p0);
}
Java_awt_EventQueue Java_awt_EventQueue.new();

/* class java.awt.FileDialog */
class Java_awt_FileDialog extends Java_awt_Dialog {
	/*-- Method --*/
	@Virtual @Overload String getDirectory();
	@Virtual @Overload String getFile();
	@Virtual @Overload Java_io_FilenameFilter getFilenameFilter();
	@Virtual @Overload Java_io_File[] getFiles();
	@Virtual @Overload int getMode();
	@Virtual @Overload boolean isMultipleMode();
	@Virtual @Overload void setDirectory(String p0);
	@Virtual @Overload void setFile(String p0);
	@Virtual @Overload void setFilenameFilter(Java_io_FilenameFilter p0);
	@Virtual @Overload void setMode(int p0);
	@Virtual @Overload void setMultipleMode(boolean p0);
}
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Frame p0);
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Frame p0, String p1);
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Frame p0, String p1, int p2);
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Dialog p0);
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Dialog p0, String p1);
@Overload Java_awt_FileDialog Java_awt_FileDialog.new(Java_awt_Dialog p0, String p1, int p2);

/* class java.awt.FlowLayout */
class Java_awt_FlowLayout {
	// implements java.awt.LayoutManager, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(String p0, Java_awt_Component p1);
	@Virtual @Overload boolean getAlignOnBaseline();
	@Virtual @Overload int getAlignment();
	@Virtual @Overload int getHgap();
	@Virtual @Overload int getVgap();
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
	@Virtual @Overload void setAlignOnBaseline(boolean p0);
	@Virtual @Overload void setAlignment(int p0);
	@Virtual @Overload void setHgap(int p0);
	@Virtual @Overload void setVgap(int p0);
	@Virtual @Overload String toString();
}
@Overload Java_awt_FlowLayout Java_awt_FlowLayout.new();
@Overload Java_awt_FlowLayout Java_awt_FlowLayout.new(int p0);
@Overload Java_awt_FlowLayout Java_awt_FlowLayout.new(int p0, int p1, int p2);

/* class java.awt.FocusTraversalPolicy */
class Java_awt_FocusTraversalPolicy {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Component getComponentAfter(Java_awt_Container p0, Java_awt_Component p1);
	@Virtual @Overload Java_awt_Component getComponentBefore(Java_awt_Container p0, Java_awt_Component p1);
	@Virtual @Overload Java_awt_Component getDefaultComponent(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Component getFirstComponent(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Component getInitialComponent(Java_awt_Window p0);
	@Virtual @Overload Java_awt_Component getLastComponent(Java_awt_Container p0);
}
Java_awt_FocusTraversalPolicy Java_awt_FocusTraversalPolicy.new();

/* class java.awt.Font */
class Java_awt_Font {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean canDisplay(int p0);
	@Virtual @Overload boolean canDisplay(int p0);
	@Virtual @Overload int canDisplayUpTo(String p0);
	@Virtual @Overload int canDisplayUpTo(int[] p0, int p1, int p2);
	@Virtual @Overload int canDisplayUpTo(Java_text_CharacterIterator p0, int p1, int p2);
	@Virtual @Overload Java_awt_Font createFont(int p0, Java_io_InputStream p1);
	@Virtual @Overload Java_awt_Font createFont(int p0, Java_io_File p1);
	@Virtual @Overload Java_awt_font_GlyphVector createGlyphVector(Java_awt_font_FontRenderContext p0, String p1);
	@Virtual @Overload Java_awt_font_GlyphVector createGlyphVector(Java_awt_font_FontRenderContext p0, int[] p1);
	@Virtual @Overload Java_awt_font_GlyphVector createGlyphVector(Java_awt_font_FontRenderContext p0, Java_text_CharacterIterator p1);
	@Virtual @Overload Java_awt_font_GlyphVector createGlyphVector(Java_awt_font_FontRenderContext p0, int[] p1);
	@Virtual @Overload Java_awt_Font decode(String p0);
	@Virtual @Overload Java_awt_Font deriveFont(int p0, float p1);
	@Virtual @Overload Java_awt_Font deriveFont(int p0, Java_awt_geom_AffineTransform p1);
	@Virtual @Overload Java_awt_Font deriveFont(float p0);
	@Virtual @Overload Java_awt_Font deriveFont(Java_awt_geom_AffineTransform p0);
	@Virtual @Overload Java_awt_Font deriveFont(int p0);
	@Virtual @Overload Java_awt_Font deriveFont(Java_util_Map p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_util_Map getAttributes();
	@Virtual @Overload Java_text_AttributedCharacterIterator_Attribute[] getAvailableAttributes();
	@Virtual @Overload int getBaselineFor(int p0);
	@Virtual @Overload String getFamily();
	@Virtual @Overload String getFamily(Java_util_Locale p0);
	@Virtual @Overload Java_awt_Font getFont(Java_util_Map p0);
	@Virtual @Overload Java_awt_Font getFont(String p0);
	@Virtual @Overload Java_awt_Font getFont(String p0, Java_awt_Font p1);
	@Virtual @Overload String getFontName();
	@Virtual @Overload String getFontName(Java_util_Locale p0);
	@Virtual @Overload float getItalicAngle();
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(String p0, Java_awt_font_FontRenderContext p1);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(String p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(int[] p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(Java_text_CharacterIterator p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload Java_awt_geom_Rectangle2D getMaxCharBounds(Java_awt_font_FontRenderContext p0);
	@Virtual @Overload int getMissingGlyphCode();
	@Virtual @Overload String getName();
	@Virtual @Overload int getNumGlyphs();
	@Virtual @Overload String getPSName();
	@Virtual @Overload int getSize();
	@Virtual @Overload float getSize2D();
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(String p0, Java_awt_font_FontRenderContext p1);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(String p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(int[] p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(Java_text_CharacterIterator p0, int p1, int p2, Java_awt_font_FontRenderContext p3);
	@Virtual @Overload int getStyle();
	@Virtual @Overload Java_awt_geom_AffineTransform getTransform();
	@Virtual @Overload boolean hasLayoutAttributes();
	@Virtual @Overload boolean hasUniformLineMetrics();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isBold();
	@Virtual @Overload boolean isItalic();
	@Virtual @Overload boolean isPlain();
	@Virtual @Overload boolean isTransformed();
	@Virtual @Overload Java_awt_font_GlyphVector layoutGlyphVector(Java_awt_font_FontRenderContext p0, int[] p1, int p2, int p3, int p4);
	@Virtual @Overload String toString();
}
@Overload Java_awt_Font Java_awt_Font.new(String p0, int p1, int p2);
@Overload Java_awt_Font Java_awt_Font.new(Java_util_Map p0);

/* class java.awt.FontFormatException */
class Java_awt_FontFormatException extends Java_lang_Exception {
}
Java_awt_FontFormatException Java_awt_FontFormatException.new(String p0);

/* class java.awt.FontMetrics */
class Java_awt_FontMetrics {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload int bytesWidth(int[] p0, int p1, int p2);
	@Virtual @Overload int charWidth(int p0);
	@Virtual @Overload int charWidth(int p0);
	@Virtual @Overload int charsWidth(int[] p0, int p1, int p2);
	@Virtual @Overload int getAscent();
	@Virtual @Overload int getDescent();
	@Virtual @Overload Java_awt_Font getFont();
	@Virtual @Overload Java_awt_font_FontRenderContext getFontRenderContext();
	@Virtual @Overload int getHeight();
	@Virtual @Overload int getLeading();
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(String p0, Java_awt_Graphics p1);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(String p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(int[] p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload Java_awt_font_LineMetrics getLineMetrics(Java_text_CharacterIterator p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload int getMaxAdvance();
	@Virtual @Overload int getMaxAscent();
	@Virtual @Overload Java_awt_geom_Rectangle2D getMaxCharBounds(Java_awt_Graphics p0);
	@Virtual @Overload int getMaxDescent();
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(String p0, Java_awt_Graphics p1);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(String p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(int[] p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload Java_awt_geom_Rectangle2D getStringBounds(Java_text_CharacterIterator p0, int p1, int p2, Java_awt_Graphics p3);
	@Virtual @Overload int[] getWidths();
	@Virtual @Overload boolean hasUniformLineMetrics();
	@Virtual @Overload int stringWidth(String p0);
	@Virtual @Overload String toString();
}

/* class java.awt.Frame */
class Java_awt_Frame extends Java_awt_Window {
	// implements java.awt.MenuContainer
	/*-- Method --*/
	@Virtual @Overload int getExtendedState();
	@Virtual @Overload Java_awt_Frame[] getFrames();
	@Virtual @Overload Java_awt_Image getIconImage();
	@Virtual @Overload Java_awt_Rectangle getMaximizedBounds();
	@Virtual @Overload Java_awt_MenuBar getMenuBar();
	@Virtual @Overload int getState();
	@Virtual @Overload String getTitle();
	@Virtual @Overload boolean isResizable();
	@Virtual @Overload boolean isUndecorated();
	@Virtual @Overload void setExtendedState(int p0);
	@Virtual @Overload void setMaximizedBounds(Java_awt_Rectangle p0);
	@Virtual @Overload void setMenuBar(Java_awt_MenuBar p0);
	@Virtual @Overload void setResizable(boolean p0);
	@Virtual @Overload void setState(int p0);
	@Virtual @Overload void setTitle(String p0);
	@Virtual @Overload void setUndecorated(boolean p0);
}
@Overload Java_awt_Frame Java_awt_Frame.new();
@Overload Java_awt_Frame Java_awt_Frame.new(Java_awt_GraphicsConfiguration p0);
@Overload Java_awt_Frame Java_awt_Frame.new(String p0);
@Overload Java_awt_Frame Java_awt_Frame.new(String p0, Java_awt_GraphicsConfiguration p1);

/* class java.awt.GradientPaint */
class Java_awt_GradientPaint {
	// implements java.awt.Paint
	/*-- Method --*/
	@Virtual @Overload Java_awt_PaintContext createContext(Java_awt_image_ColorModel p0, Java_awt_Rectangle p1, Java_awt_geom_Rectangle2D p2, Java_awt_geom_AffineTransform p3, Java_awt_RenderingHints p4);
	@Virtual @Overload Java_awt_Color getColor1();
	@Virtual @Overload Java_awt_Color getColor2();
	@Virtual @Overload Java_awt_geom_Point2D getPoint1();
	@Virtual @Overload Java_awt_geom_Point2D getPoint2();
	@Virtual @Overload int getTransparency();
	@Virtual @Overload boolean isCyclic();
}
@Overload Java_awt_GradientPaint Java_awt_GradientPaint.new(float p0, float p1, Java_awt_Color p2, float p3, float p4, Java_awt_Color p5);
@Overload Java_awt_GradientPaint Java_awt_GradientPaint.new(Java_awt_geom_Point2D p0, Java_awt_Color p1, Java_awt_geom_Point2D p2, Java_awt_Color p3);
@Overload Java_awt_GradientPaint Java_awt_GradientPaint.new(float p0, float p1, Java_awt_Color p2, float p3, float p4, Java_awt_Color p5, boolean p6);
@Overload Java_awt_GradientPaint Java_awt_GradientPaint.new(Java_awt_geom_Point2D p0, Java_awt_Color p1, Java_awt_geom_Point2D p2, Java_awt_Color p3, boolean p4);

/* class java.awt.Graphics */
class Java_awt_Graphics {
	/*-- Method --*/
	@Virtual @Overload void clearRect(int p0, int p1, int p2, int p3);
	@Virtual @Overload void clipRect(int p0, int p1, int p2, int p3);
	@Virtual @Overload void copyArea(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload Java_awt_Graphics create();
	@Virtual @Overload Java_awt_Graphics create(int p0, int p1, int p2, int p3);
	@Virtual @Overload void dispose();
	@Virtual @Overload void draw3DRect(int p0, int p1, int p2, int p3, boolean p4);
	@Virtual @Overload void drawArc(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void drawBytes(int[] p0, int p1, int p2, int p3, int p4);
	@Virtual @Overload void drawChars(int[] p0, int p1, int p2, int p3, int p4);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, Java_awt_image_ImageObserver p3);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, int p3, int p4, Java_awt_image_ImageObserver p5);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, Java_awt_Color p3, Java_awt_image_ImageObserver p4);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, int p3, int p4, Java_awt_Color p5, Java_awt_image_ImageObserver p6);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, Java_awt_image_ImageObserver p9);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, Java_awt_Color p9, Java_awt_image_ImageObserver p10);
	@Virtual @Overload void drawLine(int p0, int p1, int p2, int p3);
	@Virtual @Overload void drawOval(int p0, int p1, int p2, int p3);
	@Virtual @Overload void drawPolygon(int[] p0, int[] p1, int p2);
	@Virtual @Overload void drawPolygon(Java_awt_Polygon p0);
	@Virtual @Overload void drawPolyline(int[] p0, int[] p1, int p2);
	@Virtual @Overload void drawRect(int p0, int p1, int p2, int p3);
	@Virtual @Overload void drawRoundRect(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void drawString(String p0, int p1, int p2);
	@Virtual @Overload void drawString(Java_text_AttributedCharacterIterator p0, int p1, int p2);
	@Virtual @Overload void fill3DRect(int p0, int p1, int p2, int p3, boolean p4);
	@Virtual @Overload void fillArc(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void fillOval(int p0, int p1, int p2, int p3);
	@Virtual @Overload void fillPolygon(int[] p0, int[] p1, int p2);
	@Virtual @Overload void fillPolygon(Java_awt_Polygon p0);
	@Virtual @Overload void fillRect(int p0, int p1, int p2, int p3);
	@Virtual @Overload void fillRoundRect(int p0, int p1, int p2, int p3, int p4, int p5);
	@Virtual @Overload void finalize();
	@Virtual @Overload Java_awt_Shape getClip();
	@Virtual @Overload Java_awt_Rectangle getClipBounds();
	@Virtual @Overload Java_awt_Rectangle getClipBounds(Java_awt_Rectangle p0);
	@Virtual @Overload Java_awt_Color getColor();
	@Virtual @Overload Java_awt_Font getFont();
	@Virtual @Overload Java_awt_FontMetrics getFontMetrics();
	@Virtual @Overload Java_awt_FontMetrics getFontMetrics(Java_awt_Font p0);
	@Virtual @Overload boolean hitClip(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setClip(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setClip(Java_awt_Shape p0);
	@Virtual @Overload void setColor(Java_awt_Color p0);
	@Virtual @Overload void setFont(Java_awt_Font p0);
	@Virtual @Overload void setPaintMode();
	@Virtual @Overload void setXORMode(Java_awt_Color p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void translate(int p0, int p1);
}

/* class java.awt.Graphics2D */
class Java_awt_Graphics2D extends Java_awt_Graphics {
	/*-- Method --*/
	@Virtual @Overload void addRenderingHints(Java_util_Map p0);
	@Virtual @Overload void clip(Java_awt_Shape p0);
	@Virtual @Overload void draw(Java_awt_Shape p0);
	@Virtual @Overload void drawGlyphVector(Java_awt_font_GlyphVector p0, float p1, float p2);
	@Virtual @Overload boolean drawImage(Java_awt_Image p0, Java_awt_geom_AffineTransform p1, Java_awt_image_ImageObserver p2);
	@Virtual @Overload void drawImage(Java_awt_image_BufferedImage p0, Java_awt_image_BufferedImageOp p1, int p2, int p3);
	@Virtual @Overload void drawRenderableImage(Java_awt_image_renderable_RenderableImage p0, Java_awt_geom_AffineTransform p1);
	@Virtual @Overload void drawRenderedImage(Java_awt_image_RenderedImage p0, Java_awt_geom_AffineTransform p1);
	@Virtual @Overload void drawString(String p0, float p1, float p2);
	@Virtual @Overload void drawString(Java_text_AttributedCharacterIterator p0, float p1, float p2);
	@Virtual @Overload void fill(Java_awt_Shape p0);
	@Virtual @Overload Java_awt_Color getBackground();
	@Virtual @Overload Java_awt_Composite getComposite();
	@Virtual @Overload Java_awt_GraphicsConfiguration getDeviceConfiguration();
	@Virtual @Overload Java_awt_font_FontRenderContext getFontRenderContext();
	@Virtual @Overload Java_awt_Paint getPaint();
	@Virtual @Overload Object getRenderingHint(Java_awt_RenderingHints_Key p0);
	@Virtual @Overload Java_awt_RenderingHints getRenderingHints();
	@Virtual @Overload Java_awt_Stroke getStroke();
	@Virtual @Overload Java_awt_geom_AffineTransform getTransform();
	@Virtual @Overload boolean hit(Java_awt_Rectangle p0, Java_awt_Shape p1, boolean p2);
	@Virtual @Overload void rotate(double p0);
	@Virtual @Overload void rotate(double p0, double p1, double p2);
	@Virtual @Overload void scale(double p0, double p1);
	@Virtual @Overload void setBackground(Java_awt_Color p0);
	@Virtual @Overload void setComposite(Java_awt_Composite p0);
	@Virtual @Overload void setPaint(Java_awt_Paint p0);
	@Virtual @Overload void setRenderingHint(Java_awt_RenderingHints_Key p0, Object p1);
	@Virtual @Overload void setRenderingHints(Java_util_Map p0);
	@Virtual @Overload void setStroke(Java_awt_Stroke p0);
	@Virtual @Overload void setTransform(Java_awt_geom_AffineTransform p0);
	@Virtual @Overload void shear(double p0, double p1);
	@Virtual @Overload void transform(Java_awt_geom_AffineTransform p0);
	@Virtual @Overload void translate(double p0, double p1);
}

/* class java.awt.GraphicsConfigTemplate */
class Java_awt_GraphicsConfigTemplate {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_GraphicsConfiguration getBestConfiguration(Java_awt_GraphicsConfiguration[] p0);
	@Virtual @Overload boolean isGraphicsConfigSupported(Java_awt_GraphicsConfiguration p0);
}
Java_awt_GraphicsConfigTemplate Java_awt_GraphicsConfigTemplate.new();

/* class java.awt.GraphicsConfiguration */
class Java_awt_GraphicsConfiguration {
	/*-- Method --*/
	@Virtual @Overload Java_awt_image_BufferedImage createCompatibleImage(int p0, int p1);
	@Virtual @Overload Java_awt_image_BufferedImage createCompatibleImage(int p0, int p1, int p2);
	@Virtual @Overload Java_awt_image_VolatileImage createCompatibleVolatileImage(int p0, int p1);
	@Virtual @Overload Java_awt_image_VolatileImage createCompatibleVolatileImage(int p0, int p1, int p2);
	@Virtual @Overload Java_awt_image_VolatileImage createCompatibleVolatileImage(int p0, int p1, Java_awt_ImageCapabilities p2);
	@Virtual @Overload Java_awt_image_VolatileImage createCompatibleVolatileImage(int p0, int p1, Java_awt_ImageCapabilities p2, int p3);
	@Virtual @Overload Java_awt_Rectangle getBounds();
	@Virtual @Overload Java_awt_BufferCapabilities getBufferCapabilities();
	@Virtual @Overload Java_awt_image_ColorModel getColorModel();
	@Virtual @Overload Java_awt_image_ColorModel getColorModel(int p0);
	@Virtual @Overload Java_awt_geom_AffineTransform getDefaultTransform();
	@Virtual @Overload Java_awt_GraphicsDevice getDevice();
	@Virtual @Overload Java_awt_ImageCapabilities getImageCapabilities();
	@Virtual @Overload Java_awt_geom_AffineTransform getNormalizingTransform();
	@Virtual @Overload boolean isTranslucencyCapable();
}

/* class java.awt.GraphicsDevice */
class Java_awt_GraphicsDevice {
	/*-- Method --*/
	@Virtual @Overload int getAvailableAcceleratedMemory();
	@Virtual @Overload Java_awt_GraphicsConfiguration getBestConfiguration(Java_awt_GraphicsConfigTemplate p0);
	@Virtual @Overload Java_awt_GraphicsConfiguration[] getConfigurations();
	@Virtual @Overload Java_awt_GraphicsConfiguration getDefaultConfiguration();
	@Virtual @Overload Java_awt_DisplayMode getDisplayMode();
	@Virtual @Overload Java_awt_DisplayMode[] getDisplayModes();
	@Virtual @Overload Java_awt_Window getFullScreenWindow();
	@Virtual @Overload String getIDstring();
	@Virtual @Overload int getType();
	@Virtual @Overload boolean isDisplayChangeSupported();
	@Virtual @Overload boolean isFullScreenSupported();
	@Virtual @Overload boolean isWindowTranslucencySupported(Java_awt_GraphicsDevice_WindowTranslucency p0);
	@Virtual @Overload void setDisplayMode(Java_awt_DisplayMode p0);
	@Virtual @Overload void setFullScreenWindow(Java_awt_Window p0);
}

/* class java.awt.GraphicsEnvironment */
class Java_awt_GraphicsEnvironment {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Graphics2D createGraphics(Java_awt_image_BufferedImage p0);
	@Virtual @Overload Java_awt_Font[] getAllFonts();
	@Virtual @Overload String[] getAvailableFontFamilyNames();
	@Virtual @Overload String[] getAvailableFontFamilyNames(Java_util_Locale p0);
	@Virtual @Overload Java_awt_Point getCenterPoint();
	@Virtual @Overload Java_awt_GraphicsDevice getDefaultScreenDevice();
	@Virtual @Overload Java_awt_GraphicsEnvironment getLocalGraphicsEnvironment();
	@Virtual @Overload Java_awt_Rectangle getMaximumWindowBounds();
	@Virtual @Overload Java_awt_GraphicsDevice[] getScreenDevices();
	@Virtual @Overload boolean isHeadless();
	@Virtual @Overload boolean isHeadlessInstance();
	@Virtual @Overload void preferLocaleFonts();
	@Virtual @Overload void preferProportionalFonts();
	@Virtual @Overload boolean registerFont(Java_awt_Font p0);
}

/* class java.awt.GridBagConstraints */
class Java_awt_GridBagConstraints {
	// implements java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
}
@Overload Java_awt_GridBagConstraints Java_awt_GridBagConstraints.new();
@Overload Java_awt_GridBagConstraints Java_awt_GridBagConstraints.new(int p0, int p1, int p2, int p3, double p4, double p5, int p6, int p7, Java_awt_Insets p8, int p9, int p10);

/* class java.awt.GridBagLayout */
class Java_awt_GridBagLayout {
	// implements java.awt.LayoutManager2, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(String p0, Java_awt_Component p1);
	@Virtual @Overload void addLayoutComponent(Java_awt_Component p0, Object p1);
	@Virtual @Overload Java_awt_GridBagConstraints getConstraints(Java_awt_Component p0);
	@Virtual @Overload float getLayoutAlignmentX(Java_awt_Container p0);
	@Virtual @Overload float getLayoutAlignmentY(Java_awt_Container p0);
	@Virtual @Overload int[][] getLayoutDimensions();
	@Virtual @Overload Java_awt_Point getLayoutOrigin();
	@Virtual @Overload double[][] getLayoutWeights();
	@Virtual @Overload void invalidateLayout(Java_awt_Container p0);
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Point location(int p0, int p1);
	@Virtual @Overload Java_awt_Dimension maximumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
	@Virtual @Overload void setConstraints(Java_awt_Component p0, Java_awt_GridBagConstraints p1);
	@Virtual @Overload String toString();
}
Java_awt_GridBagLayout Java_awt_GridBagLayout.new();

/* class java.awt.GridBagLayoutInfo */
class Java_awt_GridBagLayoutInfo {
	// implements java.io.Serializable
}

/* class java.awt.GridLayout */
class Java_awt_GridLayout {
	// implements java.awt.LayoutManager, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(String p0, Java_awt_Component p1);
	@Virtual @Overload int getColumns();
	@Virtual @Overload int getHgap();
	@Virtual @Overload int getRows();
	@Virtual @Overload int getVgap();
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
	@Virtual @Overload void setColumns(int p0);
	@Virtual @Overload void setHgap(int p0);
	@Virtual @Overload void setRows(int p0);
	@Virtual @Overload void setVgap(int p0);
	@Virtual @Overload String toString();
}
@Overload Java_awt_GridLayout Java_awt_GridLayout.new();
@Overload Java_awt_GridLayout Java_awt_GridLayout.new(int p0, int p1);
@Overload Java_awt_GridLayout Java_awt_GridLayout.new(int p0, int p1, int p2, int p3);

/* class java.awt.HeadlessException */
class Java_awt_HeadlessException extends Java_lang_UnsupportedOperationException {
}
@Overload Java_awt_HeadlessException Java_awt_HeadlessException.new();
@Overload Java_awt_HeadlessException Java_awt_HeadlessException.new(String p0);

/* class java.awt.IllegalComponentStateException */
class Java_awt_IllegalComponentStateException extends Java_lang_IllegalStateException {
}
@Overload Java_awt_IllegalComponentStateException Java_awt_IllegalComponentStateException.new();
@Overload Java_awt_IllegalComponentStateException Java_awt_IllegalComponentStateException.new(String p0);

/* class java.awt.Image */
class Java_awt_Image {
	/*-- Method --*/
	@Virtual @Overload void flush();
	@Virtual @Overload float getAccelerationPriority();
	@Virtual @Overload Java_awt_ImageCapabilities getCapabilities(Java_awt_GraphicsConfiguration p0);
	@Virtual @Overload Java_awt_Graphics getGraphics();
	@Virtual @Overload int getHeight(Java_awt_image_ImageObserver p0);
	@Virtual @Overload Object getProperty(String p0, Java_awt_image_ImageObserver p1);
	@Virtual @Overload Java_awt_Image getScaledInstance(int p0, int p1, int p2);
	@Virtual @Overload Java_awt_image_ImageProducer getSource();
	@Virtual @Overload int getWidth(Java_awt_image_ImageObserver p0);
	@Virtual @Overload void setAccelerationPriority(float p0);
}
Java_awt_Image Java_awt_Image.new();

/* class java.awt.ImageCapabilities */
class Java_awt_ImageCapabilities {
	// implements java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean isAccelerated();
	@Virtual @Overload boolean isTrueVolatile();
}
Java_awt_ImageCapabilities Java_awt_ImageCapabilities.new(boolean p0);

/* class java.awt.Insets */
class Java_awt_Insets {
	// implements java.lang.Cloneable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean equals(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void set(int p0, int p1, int p2, int p3);
	@Virtual @Overload String toString();
}
Java_awt_Insets Java_awt_Insets.new(int p0, int p1, int p2, int p3);

/* interface java.awt.ItemSelectable */
class Java_awt_ItemSelectable {
	/*-- Method --*/
	@Virtual @Overload void addItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload Object[] getSelectedObjects();
	@Virtual @Overload void removeItemListener(Java_awt_event_ItemListener p0);
}

/* class java.awt.JobAttributes */
class Java_awt_JobAttributes {
	// implements java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int getCopies();
	@Virtual @Overload Java_awt_JobAttributes_DefaultSelectionType getDefaultSelection();
	@Virtual @Overload Java_awt_JobAttributes_DestinationType getDestination();
	@Virtual @Overload Java_awt_JobAttributes_DialogType getDialog();
	@Virtual @Overload String getFileName();
	@Virtual @Overload int getFromPage();
	@Virtual @Overload int getMaxPage();
	@Virtual @Overload int getMinPage();
	@Virtual @Overload Java_awt_JobAttributes_MultipleDocumentHandlingType getMultipleDocumentHandling();
	@Virtual @Overload int[][] getPageRanges();
	@Virtual @Overload String getPrinter();
	@Virtual @Overload Java_awt_JobAttributes_SidesType getSides();
	@Virtual @Overload int getToPage();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void set(Java_awt_JobAttributes p0);
	@Virtual @Overload void setCopies(int p0);
	@Virtual @Overload void setCopiesToDefault();
	@Virtual @Overload void setDefaultSelection(Java_awt_JobAttributes_DefaultSelectionType p0);
	@Virtual @Overload void setDestination(Java_awt_JobAttributes_DestinationType p0);
	@Virtual @Overload void setDialog(Java_awt_JobAttributes_DialogType p0);
	@Virtual @Overload void setFileName(String p0);
	@Virtual @Overload void setFromPage(int p0);
	@Virtual @Overload void setMaxPage(int p0);
	@Virtual @Overload void setMinPage(int p0);
	@Virtual @Overload void setMultipleDocumentHandling(Java_awt_JobAttributes_MultipleDocumentHandlingType p0);
	@Virtual @Overload void setMultipleDocumentHandlingToDefault();
	@Virtual @Overload void setPageRanges(int[][] p0);
	@Virtual @Overload void setPrinter(String p0);
	@Virtual @Overload void setSides(Java_awt_JobAttributes_SidesType p0);
	@Virtual @Overload void setSidesToDefault();
	@Virtual @Overload void setToPage(int p0);
	@Virtual @Overload String toString();
}
@Overload Java_awt_JobAttributes Java_awt_JobAttributes.new();
@Overload Java_awt_JobAttributes Java_awt_JobAttributes.new(Java_awt_JobAttributes p0);
@Overload Java_awt_JobAttributes Java_awt_JobAttributes.new(int p0, Java_awt_JobAttributes_DefaultSelectionType p1, Java_awt_JobAttributes_DestinationType p2, Java_awt_JobAttributes_DialogType p3, String p4, int p5, int p6, Java_awt_JobAttributes_MultipleDocumentHandlingType p7, int[][] p8, String p9, Java_awt_JobAttributes_SidesType p10);

/* interface java.awt.KeyEventDispatcher */
class Java_awt_KeyEventDispatcher {
	/*-- Method --*/
	@Virtual @Overload boolean dispatchKeyEvent(Java_awt_event_KeyEvent p0);
}

/* interface java.awt.KeyEventPostProcessor */
class Java_awt_KeyEventPostProcessor {
	/*-- Method --*/
	@Virtual @Overload boolean postProcessKeyEvent(Java_awt_event_KeyEvent p0);
}

/* class java.awt.KeyboardFocusManager */
class Java_awt_KeyboardFocusManager {
	// implements java.awt.KeyEventDispatcher, java.awt.KeyEventPostProcessor
	/*-- Method --*/
	@Virtual @Overload void addKeyEventDispatcher(Java_awt_KeyEventDispatcher p0);
	@Virtual @Overload void addKeyEventPostProcessor(Java_awt_KeyEventPostProcessor p0);
	@Virtual @Overload void addPropertyChangeListener(Java_beans_PropertyChangeListener p0);
	@Virtual @Overload void addPropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload void addVetoableChangeListener(Java_beans_VetoableChangeListener p0);
	@Virtual @Overload void addVetoableChangeListener(String p0, Java_beans_VetoableChangeListener p1);
	@Virtual @Overload void clearGlobalFocusOwner();
	@Virtual @Overload boolean dispatchEvent(Java_awt_AWTEvent p0);
	@Virtual @Overload boolean dispatchKeyEvent(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void downFocusCycle(Java_awt_Container p0);
	@Virtual @Overload void downFocusCycle();
	@Virtual @Overload void focusNextComponent(Java_awt_Component p0);
	@Virtual @Overload void focusNextComponent();
	@Virtual @Overload void focusPreviousComponent(Java_awt_Component p0);
	@Virtual @Overload void focusPreviousComponent();
	@Virtual @Overload Java_awt_Window getActiveWindow();
	@Virtual @Overload Java_awt_Container getCurrentFocusCycleRoot();
	@Virtual @Overload Java_awt_KeyboardFocusManager getCurrentKeyboardFocusManager();
	@Virtual @Overload Java_util_Set getDefaultFocusTraversalKeys(int p0);
	@Virtual @Overload Java_awt_FocusTraversalPolicy getDefaultFocusTraversalPolicy();
	@Virtual @Overload Java_awt_Component getFocusOwner();
	@Virtual @Overload Java_awt_Window getFocusedWindow();
	@Virtual @Overload Java_awt_Component getPermanentFocusOwner();
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners();
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners(String p0);
	@Virtual @Overload Java_beans_VetoableChangeListener[] getVetoableChangeListeners();
	@Virtual @Overload Java_beans_VetoableChangeListener[] getVetoableChangeListeners(String p0);
	@Virtual @Overload boolean postProcessKeyEvent(Java_awt_event_KeyEvent p0);
	@Virtual @Overload void processKeyEvent(Java_awt_Component p0, Java_awt_event_KeyEvent p1);
	@Virtual @Overload void redispatchEvent(Java_awt_Component p0, Java_awt_AWTEvent p1);
	@Virtual @Overload void removeKeyEventDispatcher(Java_awt_KeyEventDispatcher p0);
	@Virtual @Overload void removeKeyEventPostProcessor(Java_awt_KeyEventPostProcessor p0);
	@Virtual @Overload void removePropertyChangeListener(Java_beans_PropertyChangeListener p0);
	@Virtual @Overload void removePropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload void removeVetoableChangeListener(Java_beans_VetoableChangeListener p0);
	@Virtual @Overload void removeVetoableChangeListener(String p0, Java_beans_VetoableChangeListener p1);
	@Virtual @Overload void setCurrentKeyboardFocusManager(Java_awt_KeyboardFocusManager p0);
	@Virtual @Overload void setDefaultFocusTraversalKeys(int p0, Java_util_Set p1);
	@Virtual @Overload void setDefaultFocusTraversalPolicy(Java_awt_FocusTraversalPolicy p0);
	@Virtual @Overload void setGlobalCurrentFocusCycleRoot(Java_awt_Container p0);
	@Virtual @Overload void upFocusCycle(Java_awt_Component p0);
	@Virtual @Overload void upFocusCycle();
}
Java_awt_KeyboardFocusManager Java_awt_KeyboardFocusManager.new();

/* class java.awt.Label */
class Java_awt_Label extends Java_awt_Component {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload int getAlignment();
	@Virtual @Overload String getText();
	@Virtual @Overload void setAlignment(int p0);
	@Virtual @Overload void setText(String p0);
}
@Overload Java_awt_Label Java_awt_Label.new();
@Overload Java_awt_Label Java_awt_Label.new(String p0);
@Overload Java_awt_Label Java_awt_Label.new(String p0, int p1);

/* interface java.awt.LayoutManager */
class Java_awt_LayoutManager {
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(String p0, Java_awt_Component p1);
	@Virtual @Overload void layoutContainer(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension minimumLayoutSize(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension preferredLayoutSize(Java_awt_Container p0);
	@Virtual @Overload void removeLayoutComponent(Java_awt_Component p0);
}

/* interface java.awt.LayoutManager2 */
class Java_awt_LayoutManager2 {
	// implements java.awt.LayoutManager
	/*-- Method --*/
	@Virtual @Overload void addLayoutComponent(Java_awt_Component p0, Object p1);
	@Virtual @Overload float getLayoutAlignmentX(Java_awt_Container p0);
	@Virtual @Overload float getLayoutAlignmentY(Java_awt_Container p0);
	@Virtual @Overload void invalidateLayout(Java_awt_Container p0);
	@Virtual @Overload Java_awt_Dimension maximumLayoutSize(Java_awt_Container p0);
}

/* class java.awt.LinearGradientPaint */
class Java_awt_LinearGradientPaint extends Java_awt_MultipleGradientPaint {
	/*-- Method --*/
	@Virtual @Overload Java_awt_geom_Point2D getEndPoint();
	@Virtual @Overload Java_awt_geom_Point2D getStartPoint();
}
@Overload Java_awt_LinearGradientPaint Java_awt_LinearGradientPaint.new(float p0, float p1, float p2, float p3, float[] p4, Java_awt_Color[] p5);
@Overload Java_awt_LinearGradientPaint Java_awt_LinearGradientPaint.new(float p0, float p1, float p2, float p3, float[] p4, Java_awt_Color[] p5, Java_awt_MultipleGradientPaint_CycleMethod p6);
@Overload Java_awt_LinearGradientPaint Java_awt_LinearGradientPaint.new(Java_awt_geom_Point2D p0, Java_awt_geom_Point2D p1, float[] p2, Java_awt_Color[] p3);
@Overload Java_awt_LinearGradientPaint Java_awt_LinearGradientPaint.new(Java_awt_geom_Point2D p0, Java_awt_geom_Point2D p1, float[] p2, Java_awt_Color[] p3, Java_awt_MultipleGradientPaint_CycleMethod p4);
@Overload Java_awt_LinearGradientPaint Java_awt_LinearGradientPaint.new(Java_awt_geom_Point2D p0, Java_awt_geom_Point2D p1, float[] p2, Java_awt_Color[] p3, Java_awt_MultipleGradientPaint_CycleMethod p4, Java_awt_MultipleGradientPaint_ColorSpaceType p5, Java_awt_geom_AffineTransform p6);

/* class java.awt.List */
class Java_awt_List extends Java_awt_Component {
	// implements java.awt.ItemSelectable, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void add(String p0);
	@Virtual @Overload void add(String p0, int p1);
	@Virtual @Overload void addActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void addItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload void deselect(int p0);
	@Virtual @Overload Java_awt_event_ActionListener[] getActionListeners();
	@Virtual @Overload String getItem(int p0);
	@Virtual @Overload int getItemCount();
	@Virtual @Overload Java_awt_event_ItemListener[] getItemListeners();
	@Virtual @Overload String[] getItems();
	@Virtual @Overload Java_awt_Dimension getMinimumSize(int p0);
	@Virtual @Overload Java_awt_Dimension getPreferredSize(int p0);
	@Virtual @Overload int getRows();
	@Virtual @Overload int getSelectedIndex();
	@Virtual @Overload int[] getSelectedIndexes();
	@Virtual @Overload String getSelectedItem();
	@Virtual @Overload String[] getSelectedItems();
	@Virtual @Overload Object[] getSelectedObjects();
	@Virtual @Overload int getVisibleIndex();
	@Virtual @Overload boolean isIndexSelected(int p0);
	@Virtual @Overload boolean isMultipleMode();
	@Virtual @Overload void makeVisible(int p0);
	@Virtual @Overload void remove(String p0);
	@Virtual @Overload void remove(int p0);
	@Virtual @Overload void removeActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void removeAll();
	@Virtual @Overload void removeItemListener(Java_awt_event_ItemListener p0);
	@Virtual @Overload void replaceItem(String p0, int p1);
	@Virtual @Overload void select(int p0);
	@Virtual @Overload void setMultipleMode(boolean p0);
}
@Overload Java_awt_List Java_awt_List.new();
@Overload Java_awt_List Java_awt_List.new(int p0);
@Overload Java_awt_List Java_awt_List.new(int p0, boolean p1);

/* class java.awt.MediaTracker */
class Java_awt_MediaTracker {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addImage(Java_awt_Image p0, int p1);
	@Virtual @Overload void addImage(Java_awt_Image p0, int p1, int p2, int p3);
	@Virtual @Overload boolean checkAll();
	@Virtual @Overload boolean checkAll(boolean p0);
	@Virtual @Overload boolean checkID(int p0);
	@Virtual @Overload boolean checkID(int p0, boolean p1);
	@Virtual @Overload Object[] getErrorsAny();
	@Virtual @Overload Object[] getErrorsID(int p0);
	@Virtual @Overload boolean isErrorAny();
	@Virtual @Overload boolean isErrorID(int p0);
	@Virtual @Overload void removeImage(Java_awt_Image p0);
	@Virtual @Overload void removeImage(Java_awt_Image p0, int p1);
	@Virtual @Overload void removeImage(Java_awt_Image p0, int p1, int p2, int p3);
	@Virtual @Overload int statusAll(boolean p0);
	@Virtual @Overload int statusID(int p0, boolean p1);
	@Virtual @Overload void waitForAll();
	@Virtual @Overload boolean waitForAll(long p0);
	@Virtual @Overload void waitForID(int p0);
	@Virtual @Overload boolean waitForID(int p0, long p1);
}
Java_awt_MediaTracker Java_awt_MediaTracker.new(Java_awt_Component p0);

/* class java.awt.Menu */
class Java_awt_Menu extends Java_awt_MenuItem {
	// implements java.awt.MenuContainer, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload Java_awt_MenuItem add(Java_awt_MenuItem p0);
	@Virtual @Overload void add(String p0);
	@Virtual @Overload void addSeparator();
	@Virtual @Overload Java_awt_MenuItem getItem(int p0);
	@Virtual @Overload int getItemCount();
	@Virtual @Overload void insert(Java_awt_MenuItem p0, int p1);
	@Virtual @Overload void insert(String p0, int p1);
	@Virtual @Overload void insertSeparator(int p0);
	@Virtual @Overload boolean isTearOff();
	@Virtual @Overload void remove(int p0);
	@Virtual @Overload void remove(Java_awt_MenuComponent p0);
	@Virtual @Overload void removeAll();
}
@Overload Java_awt_Menu Java_awt_Menu.new();
@Overload Java_awt_Menu Java_awt_Menu.new(String p0);
@Overload Java_awt_Menu Java_awt_Menu.new(String p0, boolean p1);

/* class java.awt.MenuBar */
class Java_awt_MenuBar extends Java_awt_MenuComponent {
	// implements java.awt.MenuContainer, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload Java_awt_Menu add(Java_awt_Menu p0);
	@Virtual @Overload void addNotify();
	@Virtual @Overload void deleteShortcut(Java_awt_MenuShortcut p0);
	@Virtual @Overload Java_awt_Menu getHelpMenu();
	@Virtual @Overload Java_awt_Menu getMenu(int p0);
	@Virtual @Overload int getMenuCount();
	@Virtual @Overload Java_awt_MenuItem getShortcutMenuItem(Java_awt_MenuShortcut p0);
	@Virtual @Overload void remove(int p0);
	@Virtual @Overload void remove(Java_awt_MenuComponent p0);
	@Virtual @Overload void setHelpMenu(Java_awt_Menu p0);
	@Virtual @Overload Java_util_Enumeration shortcuts();
}
Java_awt_MenuBar Java_awt_MenuBar.new();

/* class java.awt.MenuComponent */
class Java_awt_MenuComponent {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void dispatchEvent(Java_awt_AWTEvent p0);
	@Virtual @Overload javax.accessibility.AccessibleContext getAccessibleContext();
	@Virtual @Overload Java_awt_Font getFont();
	@Virtual @Overload String getName();
	@Virtual @Overload Java_awt_MenuContainer getParent();
	@Virtual @Overload void removeNotify();
	@Virtual @Overload void setFont(Java_awt_Font p0);
	@Virtual @Overload void setName(String p0);
	@Virtual @Overload String toString();
}
Java_awt_MenuComponent Java_awt_MenuComponent.new();

/* interface java.awt.MenuContainer */
class Java_awt_MenuContainer {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Font getFont();
	@Virtual @Overload void remove(Java_awt_MenuComponent p0);
}

/* class java.awt.MenuItem */
class Java_awt_MenuItem extends Java_awt_MenuComponent {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void addNotify();
	@Virtual @Overload void deleteShortcut();
	@Virtual @Overload String getActionCommand();
	@Virtual @Overload Java_awt_event_ActionListener[] getActionListeners();
	@Virtual @Overload String getLabel();
	@Virtual @Overload Java_util_EventListener[] getListeners(Class p0);
	@Virtual @Overload Java_awt_MenuShortcut getShortcut();
	@Virtual @Overload boolean isEnabled();
	@Virtual @Overload String paramString();
	@Virtual @Overload void removeActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void setActionCommand(String p0);
	@Virtual @Overload void setEnabled(boolean p0);
	@Virtual @Overload void setLabel(String p0);
	@Virtual @Overload void setShortcut(Java_awt_MenuShortcut p0);
}
@Overload Java_awt_MenuItem Java_awt_MenuItem.new();
@Overload Java_awt_MenuItem Java_awt_MenuItem.new(String p0);
@Overload Java_awt_MenuItem Java_awt_MenuItem.new(String p0, Java_awt_MenuShortcut p1);

/* class java.awt.MenuShortcut */
class Java_awt_MenuShortcut {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload boolean equals(Java_awt_MenuShortcut p0);
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int getKey();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
	@Virtual @Overload boolean usesShiftModifier();
}
@Overload Java_awt_MenuShortcut Java_awt_MenuShortcut.new(int p0);
@Overload Java_awt_MenuShortcut Java_awt_MenuShortcut.new(int p0, boolean p1);

/* class java.awt.MouseInfo */
class Java_awt_MouseInfo {
	/*-- Method --*/
	@Virtual @Overload int getNumberOfButtons();
	@Virtual @Overload Java_awt_PointerInfo getPointerInfo();
}

/* class java.awt.MultipleGradientPaint */
class Java_awt_MultipleGradientPaint {
	// implements java.awt.Paint
	/*-- Method --*/
	@Virtual @Overload Java_awt_MultipleGradientPaint_ColorSpaceType getColorSpace();
	@Virtual @Overload Java_awt_Color[] getColors();
	@Virtual @Overload Java_awt_MultipleGradientPaint_CycleMethod getCycleMethod();
	@Virtual @Overload float[] getFractions();
	@Virtual @Overload Java_awt_geom_AffineTransform getTransform();
	@Virtual @Overload int getTransparency();
}

/* class java.awt.PageAttributes */
class Java_awt_PageAttributes {
	// implements java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Java_awt_PageAttributes_ColorType getColor();
	@Virtual @Overload Java_awt_PageAttributes_MediaType getMedia();
	@Virtual @Overload Java_awt_PageAttributes_OrientationRequestedType getOrientationRequested();
	@Virtual @Overload Java_awt_PageAttributes_OriginType getOrigin();
	@Virtual @Overload Java_awt_PageAttributes_PrintQualityType getPrintQuality();
	@Virtual @Overload int[] getPrinterResolution();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload void set(Java_awt_PageAttributes p0);
	@Virtual @Overload void setColor(Java_awt_PageAttributes_ColorType p0);
	@Virtual @Overload void setMedia(Java_awt_PageAttributes_MediaType p0);
	@Virtual @Overload void setMediaToDefault();
	@Virtual @Overload void setOrientationRequested(Java_awt_PageAttributes_OrientationRequestedType p0);
	@Virtual @Overload void setOrientationRequested(int p0);
	@Virtual @Overload void setOrientationRequestedToDefault();
	@Virtual @Overload void setOrigin(Java_awt_PageAttributes_OriginType p0);
	@Virtual @Overload void setPrintQuality(Java_awt_PageAttributes_PrintQualityType p0);
	@Virtual @Overload void setPrintQuality(int p0);
	@Virtual @Overload void setPrintQualityToDefault();
	@Virtual @Overload void setPrinterResolution(int[] p0);
	@Virtual @Overload void setPrinterResolution(int p0);
	@Virtual @Overload void setPrinterResolutionToDefault();
	@Virtual @Overload String toString();
}
@Overload Java_awt_PageAttributes Java_awt_PageAttributes.new();
@Overload Java_awt_PageAttributes Java_awt_PageAttributes.new(Java_awt_PageAttributes p0);
@Overload Java_awt_PageAttributes Java_awt_PageAttributes.new(Java_awt_PageAttributes_ColorType p0, Java_awt_PageAttributes_MediaType p1, Java_awt_PageAttributes_OrientationRequestedType p2, Java_awt_PageAttributes_OriginType p3, Java_awt_PageAttributes_PrintQualityType p4, int[] p5);

/* interface java.awt.Paint */
class Java_awt_Paint {
	// implements java.awt.Transparency
	/*-- Method --*/
	@Virtual @Overload Java_awt_PaintContext createContext(Java_awt_image_ColorModel p0, Java_awt_Rectangle p1, Java_awt_geom_Rectangle2D p2, Java_awt_geom_AffineTransform p3, Java_awt_RenderingHints p4);
}

/* interface java.awt.PaintContext */
class Java_awt_PaintContext {
	/*-- Method --*/
	@Virtual @Overload void dispose();
	@Virtual @Overload Java_awt_image_ColorModel getColorModel();
	@Virtual @Overload Java_awt_image_Raster getRaster(int p0, int p1, int p2, int p3);
}

/* class java.awt.Panel */
class Java_awt_Panel extends Java_awt_Container {
	// implements javax.accessibility.Accessible
}
@Overload Java_awt_Panel Java_awt_Panel.new();
@Overload Java_awt_Panel Java_awt_Panel.new(Java_awt_LayoutManager p0);

/* class java.awt.Point */
class Java_awt_Point extends Java_awt_geom_Point2D {
	// implements java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload Java_awt_Point getLocation();
	@Virtual @Overload void move(int p0, int p1);
	@Virtual @Overload void setLocation(Java_awt_Point p0);
	@Virtual @Overload void setLocation(int p0, int p1);
	@Virtual @Overload void translate(int p0, int p1);
}
@Overload Java_awt_Point Java_awt_Point.new();
@Overload Java_awt_Point Java_awt_Point.new(Java_awt_Point p0);
@Overload Java_awt_Point Java_awt_Point.new(int p0, int p1);

/* class java.awt.PointerInfo */
class Java_awt_PointerInfo {
	/*-- Method --*/
	@Virtual @Overload Java_awt_GraphicsDevice getDevice();
	@Virtual @Overload Java_awt_Point getLocation();
}

/* class java.awt.Polygon */
class Java_awt_Polygon {
	// implements java.awt.Shape, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addPoint(int p0, int p1);
	@Virtual @Overload boolean contains(Java_awt_Point p0);
	@Virtual @Overload boolean contains(int p0, int p1);
	@Virtual @Overload boolean contains(double p0, double p1);
	@Virtual @Overload boolean contains(Java_awt_geom_Point2D p0);
	@Virtual @Overload boolean contains(double p0, double p1, double p2, double p3);
	@Virtual @Overload boolean contains(Java_awt_geom_Rectangle2D p0);
	@Virtual @Overload Java_awt_Rectangle getBounds();
	@Virtual @Overload Java_awt_geom_Rectangle2D getBounds2D();
	@Virtual @Overload Java_awt_geom_PathIterator getPathIterator(Java_awt_geom_AffineTransform p0);
	@Virtual @Overload Java_awt_geom_PathIterator getPathIterator(Java_awt_geom_AffineTransform p0, double p1);
	@Virtual @Overload boolean intersects(double p0, double p1, double p2, double p3);
	@Virtual @Overload boolean intersects(Java_awt_geom_Rectangle2D p0);
	@Virtual @Overload void invalidate();
	@Virtual @Overload void reset();
	@Virtual @Overload void translate(int p0, int p1);
}
@Overload Java_awt_Polygon Java_awt_Polygon.new();
@Overload Java_awt_Polygon Java_awt_Polygon.new(int[] p0, int[] p1, int p2);

/* class java.awt.PopupMenu */
class Java_awt_PopupMenu extends Java_awt_Menu {
	/*-- Method --*/
	@Virtual @Overload void show(Java_awt_Component p0, int p1, int p2);
}
@Overload Java_awt_PopupMenu Java_awt_PopupMenu.new();
@Overload Java_awt_PopupMenu Java_awt_PopupMenu.new(String p0);

/* interface java.awt.PrintGraphics */
class Java_awt_PrintGraphics {
	/*-- Method --*/
	@Virtual @Overload Java_awt_PrintJob getPrintJob();
}

/* class java.awt.PrintJob */
class Java_awt_PrintJob {
	/*-- Method --*/
	@Virtual @Overload void end();
	@Virtual @Overload void finalize();
	@Virtual @Overload Java_awt_Graphics getGraphics();
	@Virtual @Overload Java_awt_Dimension getPageDimension();
	@Virtual @Overload int getPageResolution();
	@Virtual @Overload boolean lastPageFirst();
}
Java_awt_PrintJob Java_awt_PrintJob.new();

/* class java.awt.RadialGradientPaint */
class Java_awt_RadialGradientPaint extends Java_awt_MultipleGradientPaint {
	/*-- Method --*/
	@Virtual @Overload Java_awt_geom_Point2D getCenterPoint();
	@Virtual @Overload Java_awt_geom_Point2D getFocusPoint();
	@Virtual @Overload float getRadius();
}
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(float p0, float p1, float p2, float[] p3, Java_awt_Color[] p4);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(Java_awt_geom_Point2D p0, float p1, float[] p2, Java_awt_Color[] p3);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(float p0, float p1, float p2, float[] p3, Java_awt_Color[] p4, Java_awt_MultipleGradientPaint_CycleMethod p5);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(Java_awt_geom_Point2D p0, float p1, float[] p2, Java_awt_Color[] p3, Java_awt_MultipleGradientPaint_CycleMethod p4);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(float p0, float p1, float p2, float p3, float p4, float[] p5, Java_awt_Color[] p6, Java_awt_MultipleGradientPaint_CycleMethod p7);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(Java_awt_geom_Point2D p0, float p1, Java_awt_geom_Point2D p2, float[] p3, Java_awt_Color[] p4, Java_awt_MultipleGradientPaint_CycleMethod p5);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(Java_awt_geom_Point2D p0, float p1, Java_awt_geom_Point2D p2, float[] p3, Java_awt_Color[] p4, Java_awt_MultipleGradientPaint_CycleMethod p5, Java_awt_MultipleGradientPaint_ColorSpaceType p6, Java_awt_geom_AffineTransform p7);
@Overload Java_awt_RadialGradientPaint Java_awt_RadialGradientPaint.new(Java_awt_geom_Rectangle2D p0, float[] p1, Java_awt_Color[] p2, Java_awt_MultipleGradientPaint_CycleMethod p3);

/* class java.awt.Rectangle */
class Java_awt_Rectangle extends Java_awt_geom_Rectangle2D {
	// implements java.awt.Shape, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void add(int p0, int p1);
	@Virtual @Overload void add(Java_awt_Point p0);
	@Virtual @Overload void add(Java_awt_Rectangle p0);
	@Virtual @Overload boolean contains(Java_awt_Point p0);
	@Virtual @Overload boolean contains(int p0, int p1);
	@Virtual @Overload boolean contains(Java_awt_Rectangle p0);
	@Virtual @Overload boolean contains(int p0, int p1, int p2, int p3);
	@Virtual @Overload Java_awt_Point getLocation();
	@Virtual @Overload Java_awt_Dimension getSize();
	@Virtual @Overload void grow(int p0, int p1);
	@Virtual @Overload Java_awt_Rectangle intersection(Java_awt_Rectangle p0);
	@Virtual @Overload boolean intersects(Java_awt_Rectangle p0);
	@Virtual @Overload void setBounds(Java_awt_Rectangle p0);
	@Virtual @Overload void setBounds(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setLocation(Java_awt_Point p0);
	@Virtual @Overload void setLocation(int p0, int p1);
	@Virtual @Overload void setSize(Java_awt_Dimension p0);
	@Virtual @Overload void setSize(int p0, int p1);
	@Virtual @Overload void translate(int p0, int p1);
	@Virtual @Overload Java_awt_Rectangle union(Java_awt_Rectangle p0);
}
@Overload Java_awt_Rectangle Java_awt_Rectangle.new();
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(Java_awt_Rectangle p0);
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(int p0, int p1, int p2, int p3);
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(int p0, int p1);
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(Java_awt_Point p0, Java_awt_Dimension p1);
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(Java_awt_Point p0);
@Overload Java_awt_Rectangle Java_awt_Rectangle.new(Java_awt_Dimension p0);

/* class java.awt.RenderingHints */
class Java_awt_RenderingHints {
	// implements java.util.Map, java.lang.Cloneable
	/*-- Method --*/
	@Virtual @Overload void add(Java_awt_RenderingHints p0);
	@Virtual @Overload void clear();
	@Virtual @Overload Object clone();
	@Virtual @Overload boolean containsKey(Object p0);
	@Virtual @Overload boolean containsValue(Object p0);
	@Virtual @Overload Java_util_Set entrySet();
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload Object get(Object p0);
	//@Virtual @Overload int hashCode();
	@Virtual @Overload boolean isEmpty();
	@Virtual @Overload Java_util_Set keySet();
	@Virtual @Overload Object put(Object p0, Object p1);
	@Virtual @Overload void putAll(Java_util_Map p0);
	@Virtual @Overload Object remove(Object p0);
	@Virtual @Overload int size();
	@Virtual @Overload String toString();
	@Virtual @Overload Java_util_Collection values();
}
@Overload Java_awt_RenderingHints Java_awt_RenderingHints.new(Java_util_Map p0);
@Overload Java_awt_RenderingHints Java_awt_RenderingHints.new(Java_awt_RenderingHints_Key p0, Object p1);

/* class java.awt.Robot */
class Java_awt_Robot {
	/*-- Method --*/
	@Virtual @Overload Java_awt_image_BufferedImage createScreenCapture(Java_awt_Rectangle p0);
	@Virtual @Overload void delay(int p0);
	@Virtual @Overload int getAutoDelay();
	@Virtual @Overload Java_awt_Color getPixelColor(int p0, int p1);
	@Virtual @Overload boolean isAutoWaitForIdle();
	@Virtual @Overload void keyPress(int p0);
	@Virtual @Overload void keyRelease(int p0);
	@Virtual @Overload void mouseMove(int p0, int p1);
	@Virtual @Overload void mousePress(int p0);
	@Virtual @Overload void mouseRelease(int p0);
	@Virtual @Overload void mouseWheel(int p0);
	@Virtual @Overload void setAutoDelay(int p0);
	@Virtual @Overload void setAutoWaitForIdle(boolean p0);
	@Virtual @Overload String toString();
	@Virtual @Overload void waitForIdle();
}
@Overload Java_awt_Robot Java_awt_Robot.new();
@Overload Java_awt_Robot Java_awt_Robot.new(Java_awt_GraphicsDevice p0);

/* class java.awt.ScrollPane */
class Java_awt_ScrollPane extends Java_awt_Container {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload Java_awt_Adjustable getHAdjustable();
	@Virtual @Overload int getHScrollbarHeight();
	@Virtual @Overload Java_awt_Point getScrollPosition();
	@Virtual @Overload int getScrollbarDisplayPolicy();
	@Virtual @Overload Java_awt_Adjustable getVAdjustable();
	@Virtual @Overload int getVScrollbarWidth();
	@Virtual @Overload Java_awt_Dimension getViewportSize();
	@Virtual @Overload boolean isWheelScrollingEnabled();
	@Virtual @Overload String paramString();
	@Virtual @Overload void setScrollPosition(int p0, int p1);
	@Virtual @Overload void setScrollPosition(Java_awt_Point p0);
	@Virtual @Overload void setWheelScrollingEnabled(boolean p0);
}
@Overload Java_awt_ScrollPane Java_awt_ScrollPane.new();
@Overload Java_awt_ScrollPane Java_awt_ScrollPane.new(int p0);

/* class java.awt.ScrollPaneAdjustable */
class Java_awt_ScrollPaneAdjustable {
	// implements java.awt.Adjustable, java.io.Serializable
	/*-- Method --*/
	@Virtual @Overload void addAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload Java_awt_event_AdjustmentListener[] getAdjustmentListeners();
	@Virtual @Overload int getBlockIncrement();
	@Virtual @Overload int getMaximum();
	@Virtual @Overload int getMinimum();
	@Virtual @Overload int getOrientation();
	@Virtual @Overload int getUnitIncrement();
	@Virtual @Overload int getValue();
	@Virtual @Overload boolean getValueIsAdjusting();
	@Virtual @Overload int getVisibleAmount();
	@Virtual @Overload String paramString();
	@Virtual @Overload void removeAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload void setBlockIncrement(int p0);
	@Virtual @Overload void setMaximum(int p0);
	@Virtual @Overload void setMinimum(int p0);
	@Virtual @Overload void setUnitIncrement(int p0);
	@Virtual @Overload void setValue(int p0);
	@Virtual @Overload void setValueIsAdjusting(boolean p0);
	@Virtual @Overload void setVisibleAmount(int p0);
	@Virtual @Overload String toString();
}

/* class java.awt.Scrollbar */
class Java_awt_Scrollbar extends Java_awt_Component {
	// implements java.awt.Adjustable, javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload Java_awt_event_AdjustmentListener[] getAdjustmentListeners();
	@Virtual @Overload int getBlockIncrement();
	@Virtual @Overload int getMaximum();
	@Virtual @Overload int getMinimum();
	@Virtual @Overload int getOrientation();
	@Virtual @Overload int getUnitIncrement();
	@Virtual @Overload int getValue();
	@Virtual @Overload boolean getValueIsAdjusting();
	@Virtual @Overload int getVisibleAmount();
	@Virtual @Overload void removeAdjustmentListener(Java_awt_event_AdjustmentListener p0);
	@Virtual @Overload void setBlockIncrement(int p0);
	@Virtual @Overload void setMaximum(int p0);
	@Virtual @Overload void setMinimum(int p0);
	@Virtual @Overload void setOrientation(int p0);
	@Virtual @Overload void setUnitIncrement(int p0);
	@Virtual @Overload void setValue(int p0);
	@Virtual @Overload void setValueIsAdjusting(boolean p0);
	@Virtual @Overload void setValues(int p0, int p1, int p2, int p3);
	@Virtual @Overload void setVisibleAmount(int p0);
}
@Overload Java_awt_Scrollbar Java_awt_Scrollbar.new();
@Overload Java_awt_Scrollbar Java_awt_Scrollbar.new(int p0);
@Overload Java_awt_Scrollbar Java_awt_Scrollbar.new(int p0, int p1, int p2, int p3, int p4);

/* interface java.awt.SecondaryLoop */
class Java_awt_SecondaryLoop {
	/*-- Method --*/
	@Virtual @Overload boolean enter();
	@Virtual @Overload boolean exit();
}

/* interface java.awt.Shape */
class Java_awt_Shape {
	/*-- Method --*/
	@Virtual @Overload boolean contains(double p0, double p1);
	@Virtual @Overload boolean contains(Java_awt_geom_Point2D p0);
	@Virtual @Overload boolean contains(double p0, double p1, double p2, double p3);
	@Virtual @Overload boolean contains(Java_awt_geom_Rectangle2D p0);
	@Virtual @Overload Java_awt_Rectangle getBounds();
	@Virtual @Overload Java_awt_geom_Rectangle2D getBounds2D();
	@Virtual @Overload Java_awt_geom_PathIterator getPathIterator(Java_awt_geom_AffineTransform p0);
	@Virtual @Overload Java_awt_geom_PathIterator getPathIterator(Java_awt_geom_AffineTransform p0, double p1);
	@Virtual @Overload boolean intersects(double p0, double p1, double p2, double p3);
	@Virtual @Overload boolean intersects(Java_awt_geom_Rectangle2D p0);
}

/* class java.awt.SplashScreen */
class Java_awt_SplashScreen {
	/*-- Method --*/
	@Virtual @Overload void close();
	@Virtual @Overload Java_awt_Graphics2D createGraphics();
	@Virtual @Overload Java_awt_Rectangle getBounds();
	@Virtual @Overload Java_net_URL getImageURL();
	@Virtual @Overload Java_awt_Dimension getSize();
	@Virtual @Overload Java_awt_SplashScreen getSplashScreen();
	@Virtual @Overload boolean isVisible();
	@Virtual @Overload void setImageURL(Java_net_URL p0);
	@Virtual @Overload void update();
}

/* interface java.awt.Stroke */
class Java_awt_Stroke {
	/*-- Method --*/
	@Virtual @Overload Java_awt_Shape createStrokedShape(Java_awt_Shape p0);
}

/* class java.awt.SystemColor */
class Java_awt_SystemColor extends Java_awt_Color {
	// implements java.io.Serializable
}

/* class java.awt.SystemTray */
class Java_awt_SystemTray {
	/*-- Method --*/
	@Virtual @Overload void add(Java_awt_TrayIcon p0);
	@Virtual @Overload void addPropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners(String p0);
	@Virtual @Overload Java_awt_SystemTray getSystemTray();
	@Virtual @Overload Java_awt_Dimension getTrayIconSize();
	@Virtual @Overload Java_awt_TrayIcon[] getTrayIcons();
	@Virtual @Overload boolean isSupported();
	@Virtual @Overload void remove(Java_awt_TrayIcon p0);
	@Virtual @Overload void removePropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
}

/* class java.awt.TextArea */
class Java_awt_TextArea extends Java_awt_TextComponent {
	/*-- Method --*/
	@Virtual @Overload void append(String p0);
	@Virtual @Overload int getColumns();
	@Virtual @Overload Java_awt_Dimension getMinimumSize(int p0, int p1);
	@Virtual @Overload Java_awt_Dimension getPreferredSize(int p0, int p1);
	@Virtual @Overload int getRows();
	@Virtual @Overload int getScrollbarVisibility();
	@Virtual @Overload void insert(String p0, int p1);
	@Virtual @Overload void replaceRange(String p0, int p1, int p2);
	@Virtual @Overload void setColumns(int p0);
	@Virtual @Overload void setRows(int p0);
}
@Overload Java_awt_TextArea Java_awt_TextArea.new();
@Overload Java_awt_TextArea Java_awt_TextArea.new(String p0);
@Overload Java_awt_TextArea Java_awt_TextArea.new(int p0, int p1);
@Overload Java_awt_TextArea Java_awt_TextArea.new(String p0, int p1, int p2);
@Overload Java_awt_TextArea Java_awt_TextArea.new(String p0, int p1, int p2, int p3);

/* class java.awt.TextComponent */
class Java_awt_TextComponent extends Java_awt_Component {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addTextListener(Java_awt_event_TextListener p0);
	@Virtual @Overload int getCaretPosition();
	@Virtual @Overload String getSelectedText();
	@Virtual @Overload int getSelectionEnd();
	@Virtual @Overload int getSelectionStart();
	@Virtual @Overload String getText();
	@Virtual @Overload Java_awt_event_TextListener[] getTextListeners();
	@Virtual @Overload boolean isEditable();
	@Virtual @Overload void removeTextListener(Java_awt_event_TextListener p0);
	@Virtual @Overload void select(int p0, int p1);
	@Virtual @Overload void selectAll();
	@Virtual @Overload void setCaretPosition(int p0);
	@Virtual @Overload void setEditable(boolean p0);
	@Virtual @Overload void setSelectionEnd(int p0);
	@Virtual @Overload void setSelectionStart(int p0);
	@Virtual @Overload void setText(String p0);
}

/* class java.awt.TextField */
class Java_awt_TextField extends Java_awt_TextComponent {
	/*-- Method --*/
	@Virtual @Overload void addActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload boolean echoCharIsSet();
	@Virtual @Overload Java_awt_event_ActionListener[] getActionListeners();
	@Virtual @Overload int getColumns();
	@Virtual @Overload int getEchoChar();
	@Virtual @Overload Java_awt_Dimension getMinimumSize(int p0);
	@Virtual @Overload Java_awt_Dimension getPreferredSize(int p0);
	@Virtual @Overload void removeActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void setColumns(int p0);
	@Virtual @Overload void setEchoChar(int p0);
}
@Overload Java_awt_TextField Java_awt_TextField.new();
@Overload Java_awt_TextField Java_awt_TextField.new(String p0);
@Overload Java_awt_TextField Java_awt_TextField.new(int p0);
@Overload Java_awt_TextField Java_awt_TextField.new(String p0, int p1);

/* class java.awt.TexturePaint */
class Java_awt_TexturePaint {
	// implements java.awt.Paint
	/*-- Method --*/
	@Virtual @Overload Java_awt_PaintContext createContext(Java_awt_image_ColorModel p0, Java_awt_Rectangle p1, Java_awt_geom_Rectangle2D p2, Java_awt_geom_AffineTransform p3, Java_awt_RenderingHints p4);
	@Virtual @Overload Java_awt_geom_Rectangle2D getAnchorRect();
	@Virtual @Overload Java_awt_image_BufferedImage getImage();
	@Virtual @Overload int getTransparency();
}
Java_awt_TexturePaint Java_awt_TexturePaint.new(Java_awt_image_BufferedImage p0, Java_awt_geom_Rectangle2D p1);

/* class java.awt.Toolkit */
class Java_awt_Toolkit {
	/*-- Method --*/
	@Virtual @Overload void addAWTEventListener(Java_awt_event_AWTEventListener p0, long p1);
	@Virtual @Overload void addPropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload boolean areExtraMouseButtonsEnabled();
	@Virtual @Overload void beep();
	@Virtual @Overload int checkImage(Java_awt_Image p0, int p1, int p2, Java_awt_image_ImageObserver p3);
	@Virtual @Overload Java_awt_Cursor createCustomCursor(Java_awt_Image p0, Java_awt_Point p1, String p2);
	@Virtual @Overload Java_awt_dnd_DragGestureRecognizer createDragGestureRecognizer(Class p0, Java_awt_dnd_DragSource p1, Java_awt_Component p2, int p3, Java_awt_dnd_DragGestureListener p4);
	@Virtual @Overload Java_awt_dnd_peer_DragSourceContextPeer createDragSourceContextPeer(Java_awt_dnd_DragGestureEvent p0);
	@Virtual @Overload Java_awt_Image createImage(String p0);
	@Virtual @Overload Java_awt_Image createImage(Java_net_URL p0);
	@Virtual @Overload Java_awt_Image createImage(Java_awt_image_ImageProducer p0);
	@Virtual @Overload Java_awt_Image createImage(int[] p0);
	@Virtual @Overload Java_awt_Image createImage(int[] p0, int p1, int p2);
	@Virtual @Overload Java_awt_event_AWTEventListener[] getAWTEventListeners();
	@Virtual @Overload Java_awt_event_AWTEventListener[] getAWTEventListeners(long p0);
	@Virtual @Overload Java_awt_Dimension getBestCursorSize(int p0, int p1);
	@Virtual @Overload Java_awt_image_ColorModel getColorModel();
	@Virtual @Overload Java_awt_Toolkit getDefaultToolkit();
	@Virtual @Overload Object getDesktopProperty(String p0);
	@Virtual @Overload Java_awt_Image getImage(String p0);
	@Virtual @Overload Java_awt_Image getImage(Java_net_URL p0);
	@Virtual @Overload boolean getLockingKeyState(int p0);
	@Virtual @Overload int getMaximumCursorColors();
	@Virtual @Overload int getMenuShortcutKeyMask();
	@Virtual @Overload Java_awt_PrintJob getPrintJob(Java_awt_Frame p0, String p1, Java_util_Properties p2);
	@Virtual @Overload Java_awt_PrintJob getPrintJob(Java_awt_Frame p0, String p1, Java_awt_JobAttributes p2, Java_awt_PageAttributes p3);
	@Virtual @Overload String getProperty(String p0, String p1);
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners();
	@Virtual @Overload Java_beans_PropertyChangeListener[] getPropertyChangeListeners(String p0);
	@Virtual @Overload Java_awt_Insets getScreenInsets(Java_awt_GraphicsConfiguration p0);
	@Virtual @Overload int getScreenResolution();
	@Virtual @Overload Java_awt_Dimension getScreenSize();
	@Virtual @Overload Java_awt_datatransfer_Clipboard getSystemClipboard();
	@Virtual @Overload Java_awt_EventQueue getSystemEventQueue();
	@Virtual @Overload Java_awt_datatransfer_Clipboard getSystemSelection();
	@Virtual @Overload boolean isAlwaysOnTopSupported();
	@Virtual @Overload boolean isDynamicLayoutActive();
	@Virtual @Overload boolean isFrameStateSupported(int p0);
	@Virtual @Overload boolean isModalExclusionTypeSupported(Java_awt_Dialog_ModalExclusionType p0);
	@Virtual @Overload boolean isModalityTypeSupported(Java_awt_Dialog_ModalityType p0);
	@Virtual @Overload Java_util_Map mapInputMethodHighlight(Java_awt_im_InputMethodHighlight p0);
	@Virtual @Overload boolean prepareImage(Java_awt_Image p0, int p1, int p2, Java_awt_image_ImageObserver p3);
	@Virtual @Overload void removeAWTEventListener(Java_awt_event_AWTEventListener p0);
	@Virtual @Overload void removePropertyChangeListener(String p0, Java_beans_PropertyChangeListener p1);
	@Virtual @Overload void setDynamicLayout(boolean p0);
	@Virtual @Overload void setLockingKeyState(int p0, boolean p1);
	@Virtual @Overload void sync();
}
Java_awt_Toolkit Java_awt_Toolkit.new();

/* interface java.awt.Transparency */
class Java_awt_Transparency {
	/*-- Method --*/
	@Virtual @Overload int getTransparency();
}

/* class java.awt.TrayIcon */
class Java_awt_TrayIcon {
	/*-- Method --*/
	@Virtual @Overload void addActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void addMouseListener(Java_awt_event_MouseListener p0);
	@Virtual @Overload void addMouseMotionListener(Java_awt_event_MouseMotionListener p0);
	@Virtual @Overload void displayMessage(String p0, String p1, Java_awt_TrayIcon_MessageType p2);
	@Virtual @Overload String getActionCommand();
	@Virtual @Overload Java_awt_event_ActionListener[] getActionListeners();
	@Virtual @Overload Java_awt_Image getImage();
	@Virtual @Overload Java_awt_event_MouseListener[] getMouseListeners();
	@Virtual @Overload Java_awt_event_MouseMotionListener[] getMouseMotionListeners();
	@Virtual @Overload Java_awt_PopupMenu getPopupMenu();
	@Virtual @Overload Java_awt_Dimension getSize();
	@Virtual @Overload String getToolTip();
	@Virtual @Overload boolean isImageAutoSize();
	@Virtual @Overload void removeActionListener(Java_awt_event_ActionListener p0);
	@Virtual @Overload void removeMouseListener(Java_awt_event_MouseListener p0);
	@Virtual @Overload void removeMouseMotionListener(Java_awt_event_MouseMotionListener p0);
	@Virtual @Overload void setActionCommand(String p0);
	@Virtual @Overload void setImage(Java_awt_Image p0);
	@Virtual @Overload void setImageAutoSize(boolean p0);
	@Virtual @Overload void setPopupMenu(Java_awt_PopupMenu p0);
	@Virtual @Overload void setToolTip(String p0);
}
@Overload Java_awt_TrayIcon Java_awt_TrayIcon.new(Java_awt_Image p0);
@Overload Java_awt_TrayIcon Java_awt_TrayIcon.new(Java_awt_Image p0, String p1);
@Overload Java_awt_TrayIcon Java_awt_TrayIcon.new(Java_awt_Image p0, String p1, Java_awt_PopupMenu p2);

/* class java.awt.Window */
class Java_awt_Window extends Java_awt_Container {
	// implements javax.accessibility.Accessible
	/*-- Method --*/
	@Virtual @Overload void addWindowFocusListener(Java_awt_event_WindowFocusListener p0);
	@Virtual @Overload void addWindowListener(Java_awt_event_WindowListener p0);
	@Virtual @Overload void addWindowStateListener(Java_awt_event_WindowStateListener p0);
	@Virtual @Overload void createBufferStrategy(int p0);
	@Virtual @Overload void createBufferStrategy(int p0, Java_awt_BufferCapabilities p1);
	@Virtual @Overload void dispose();
	@Virtual @Overload Java_awt_image_BufferStrategy getBufferStrategy();
	@Virtual @Overload Java_awt_Component getFocusOwner();
	@Virtual @Overload boolean getFocusableWindowState();
	@Virtual @Overload Java_util_List getIconImages();
	@Virtual @Overload Java_awt_Dialog_ModalExclusionType getModalExclusionType();
	@Virtual @Overload Java_awt_Component getMostRecentFocusOwner();
	@Virtual @Overload float getOpacity();
	@Virtual @Overload Java_awt_Window[] getOwnedWindows();
	@Virtual @Overload Java_awt_Window getOwner();
	@Virtual @Overload Java_awt_Window[] getOwnerlessWindows();
	@Virtual @Overload Java_awt_Shape getShape();
	@Virtual @Overload Java_awt_Window_Type getType();
	@Virtual @Overload String getWarningString();
	@Virtual @Overload Java_awt_event_WindowFocusListener[] getWindowFocusListeners();
	@Virtual @Overload Java_awt_event_WindowListener[] getWindowListeners();
	@Virtual @Overload Java_awt_event_WindowStateListener[] getWindowStateListeners();
	@Virtual @Overload Java_awt_Window[] getWindows();
	@Virtual @Overload boolean isActive();
	@Virtual @Overload boolean isAlwaysOnTop();
	@Virtual @Overload boolean isAlwaysOnTopSupported();
	@Virtual @Overload boolean isAutoRequestFocus();
	@Virtual @Overload boolean isFocusableWindow();
	@Virtual @Overload boolean isFocused();
	@Virtual @Overload boolean isLocationByPlatform();
	@Virtual @Overload void pack();
	@Virtual @Overload void removeWindowFocusListener(Java_awt_event_WindowFocusListener p0);
	@Virtual @Overload void removeWindowListener(Java_awt_event_WindowListener p0);
	@Virtual @Overload void removeWindowStateListener(Java_awt_event_WindowStateListener p0);
	@Virtual @Overload void setAlwaysOnTop(boolean p0);
	@Virtual @Overload void setAutoRequestFocus(boolean p0);
	@Virtual @Overload void setFocusableWindowState(boolean p0);
	@Virtual @Overload void setIconImage(Java_awt_Image p0);
	@Virtual @Overload void setIconImages(Java_util_List p0);
	@Virtual @Overload void setLocationByPlatform(boolean p0);
	@Virtual @Overload void setLocationRelativeTo(Java_awt_Component p0);
	@Virtual @Overload void setModalExclusionType(Java_awt_Dialog_ModalExclusionType p0);
	@Virtual @Overload void setOpacity(float p0);
	@Virtual @Overload void setShape(Java_awt_Shape p0);
	@Virtual @Overload void setType(Java_awt_Window_Type p0);
	@Virtual @Overload void toBack();
	@Virtual @Overload void toFront();
}
@Overload Java_awt_Window Java_awt_Window.new(Java_awt_Frame p0);
@Overload Java_awt_Window Java_awt_Window.new(Java_awt_Window p0);
@Overload Java_awt_Window Java_awt_Window.new(Java_awt_Window p0, Java_awt_GraphicsConfiguration p1);


/*------------------------------------------------------------*/
/* short names */
AWTError = Java_awt_AWTError
AWTEvent = Java_awt_AWTEvent
AWTEventMulticaster = Java_awt_AWTEventMulticaster
AWTException = Java_awt_AWTException
AWTKeyStroke = Java_awt_AWTKeyStroke
AWTPermission = Java_awt_AWTPermission
ActiveEvent = Java_awt_ActiveEvent
Adjustable = Java_awt_Adjustable
AlphaComposite = Java_awt_AlphaComposite
BasicStroke = Java_awt_BasicStroke
BorderLayout = Java_awt_BorderLayout
BufferCapabilities = Java_awt_BufferCapabilities
Button = Java_awt_Button
Canvas = Java_awt_Canvas
CardLayout = Java_awt_CardLayout
Checkbox = Java_awt_Checkbox
CheckboxGroup = Java_awt_CheckboxGroup
CheckboxMenuItem = Java_awt_CheckboxMenuItem
Choice = Java_awt_Choice
Color = Java_awt_Color
Component = Java_awt_Component
ComponentOrientation = Java_awt_ComponentOrientation
Composite = Java_awt_Composite
CompositeContext = Java_awt_CompositeContext
Container = Java_awt_Container
ContainerOrderFocusTraversalPolicy = Java_awt_ContainerOrderFocusTraversalPolicy
Cursor = Java_awt_Cursor
DefaultFocusTraversalPolicy = Java_awt_DefaultFocusTraversalPolicy
DefaultKeyboardFocusManager = Java_awt_DefaultKeyboardFocusManager
Desktop = Java_awt_Desktop
Dialog = Java_awt_Dialog
Dimension = Java_awt_Dimension
DisplayMode = Java_awt_DisplayMode
Event = Java_awt_Event
EventQueue = Java_awt_EventQueue
FileDialog = Java_awt_FileDialog
FlowLayout = Java_awt_FlowLayout
FocusTraversalPolicy = Java_awt_FocusTraversalPolicy
Font = Java_awt_Font
FontFormatException = Java_awt_FontFormatException
FontMetrics = Java_awt_FontMetrics
Frame = Java_awt_Frame
GradientPaint = Java_awt_GradientPaint
Graphics = Java_awt_Graphics
Graphics2D = Java_awt_Graphics2D
GraphicsConfigTemplate = Java_awt_GraphicsConfigTemplate
GraphicsConfiguration = Java_awt_GraphicsConfiguration
GraphicsDevice = Java_awt_GraphicsDevice
GraphicsEnvironment = Java_awt_GraphicsEnvironment
GridBagConstraints = Java_awt_GridBagConstraints
GridBagLayout = Java_awt_GridBagLayout
GridBagLayoutInfo = Java_awt_GridBagLayoutInfo
GridLayout = Java_awt_GridLayout
HeadlessException = Java_awt_HeadlessException
IllegalComponentStateException = Java_awt_IllegalComponentStateException
Image = Java_awt_Image
ImageCapabilities = Java_awt_ImageCapabilities
Insets = Java_awt_Insets
ItemSelectable = Java_awt_ItemSelectable
JobAttributes = Java_awt_JobAttributes
KeyEventDispatcher = Java_awt_KeyEventDispatcher
KeyEventPostProcessor = Java_awt_KeyEventPostProcessor
KeyboardFocusManager = Java_awt_KeyboardFocusManager
Label = Java_awt_Label
LayoutManager = Java_awt_LayoutManager
LayoutManager2 = Java_awt_LayoutManager2
LinearGradientPaint = Java_awt_LinearGradientPaint
List = Java_awt_List
MediaTracker = Java_awt_MediaTracker
Menu = Java_awt_Menu
MenuBar = Java_awt_MenuBar
MenuComponent = Java_awt_MenuComponent
MenuContainer = Java_awt_MenuContainer
MenuItem = Java_awt_MenuItem
MenuShortcut = Java_awt_MenuShortcut
MouseInfo = Java_awt_MouseInfo
MultipleGradientPaint = Java_awt_MultipleGradientPaint
PageAttributes = Java_awt_PageAttributes
Paint = Java_awt_Paint
PaintContext = Java_awt_PaintContext
Panel = Java_awt_Panel
Point = Java_awt_Point
PointerInfo = Java_awt_PointerInfo
Polygon = Java_awt_Polygon
PopupMenu = Java_awt_PopupMenu
PrintGraphics = Java_awt_PrintGraphics
PrintJob = Java_awt_PrintJob
RadialGradientPaint = Java_awt_RadialGradientPaint
Rectangle = Java_awt_Rectangle
RenderingHints = Java_awt_RenderingHints
Robot = Java_awt_Robot
ScrollPane = Java_awt_ScrollPane
ScrollPaneAdjustable = Java_awt_ScrollPaneAdjustable
Scrollbar = Java_awt_Scrollbar
SecondaryLoop = Java_awt_SecondaryLoop
Shape = Java_awt_Shape
SplashScreen = Java_awt_SplashScreen
Stroke = Java_awt_Stroke
SystemColor = Java_awt_SystemColor
SystemTray = Java_awt_SystemTray
TextArea = Java_awt_TextArea
TextComponent = Java_awt_TextComponent
TextField = Java_awt_TextField
TexturePaint = Java_awt_TexturePaint
Toolkit = Java_awt_Toolkit
Transparency = Java_awt_Transparency
TrayIcon = Java_awt_TrayIcon
Window = Java_awt_Window
