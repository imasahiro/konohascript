#include <cairo/cairo.h>
#include <konoha1.h>
#include "pkg_typerules.h"
#include "enum.h"

#ifdef __cplusplus
extern "C" {
#endif

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.cairo");
}
DEFAPI(void) defCairo(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Cairo";
}

static int CairoRegion_equal(kRawPtr *p1, kRawPtr *p2)
{
    cairo_region_t* a = PKGRawPtr_to_(cairo_region_t*, p1);
    cairo_region_t* b = PKGRawPtr_to_(cairo_region_t*, p2);
    return cairo_region_equal(a, b);
}

DEFAPI(void) defCairoRegion(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "CairoRegion";
	cdef->compareTo = CairoRegion_equal;
}

static int CairoFontOptions_equal(kRawPtr *p1, kRawPtr *p2)
{
    cairo_font_options_t* a = PKGRawPtr_to_(cairo_font_options_t*, p1);
    cairo_font_options_t* b = PKGRawPtr_to_(cairo_font_options_t*, p2);
    return cairo_font_options_equal(a, b);
}

DEFAPI(void) defCairoFontOptions(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "CairoFontOptions";
	cdef->compareTo = CairoFontOptions_equal;
}

DEFAPI(void) constCairo(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	knh_IntData_t _CairoConstInt[] = {
		{"VERSION", cairo_version()},
		{NULL, 0}
	};
	knh_StringData_t _CairoConstString[] = {
		{"VERSION_STRING", cairo_version_string()},
		{NULL, 0}
	};
	kapi->loadClassIntConst(ctx, cid, CairoConstInt);
	kapi->loadClassIntConst(ctx, cid, _CairoConstInt);
	kapi->loadStringClassConst(ctx, cid, _CairoConstString);
}

static void my_cairo_free(void *p)
{
    cairo_t *cr = (cairo_t *) p;
    cairo_destroy(cr);
}

static void my_free(void *p)
{
    KNH_TODO("");
}
static void my_cairo_pattern_free(void *p)
{
    cairo_pattern_t* pattern = (cairo_pattern_t*) p;
    cairo_pattern_destroy(pattern);
}
//## @Native Cairo Cairo.new(CairoSurface target);
KMETHOD Cairo_new(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* target = PKGRawPtr_to(cairo_surface_t*, 1);
    cairo_t* ret = cairo_create(target);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_free);
    RETURN_(p);
}

//## @Native void Cairo.destroy();
KMETHOD Cairo_destroy(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_destroy(cr);
    RETURNvoid_();
}

////## @Native cairo_t* Cairo.reference();
//KMETHOD Cairo_reference(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
//
//    cairo_t* ret = cairo_reference(cr);
//    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_free);
//    RETURN_(p);
//}
//
////## @Native int Cairo.get_reference_count();
//KMETHOD Cairo_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
//
//    int ret = cairo_get_reference_count(cr);
//    RETURNi_(ret);
//}

//## @Native CairoData Cairo.get_user_data(CairoUserDataKey key);
KMETHOD Cairo_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_get_user_data(cr, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native int Cairo.set_user_data(CairoUserDataKey key, CairoData user_data, cairo_destroy_func_t destroy);
KMETHOD Cairo_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);

    KNH_TODO("destroy");
    cairo_status_t ret = cairo_set_user_data(cr, key, user_data, destroy);
    RETURNi_(ret);
}

//## @Native void Cairo.save();
KMETHOD Cairo_save(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_save(cr);
    RETURNvoid_();
}

//## @Native void Cairo.restore();
KMETHOD Cairo_restore(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_restore(cr);
    RETURNvoid_();
}

//## @Native void Cairo.push_group();
KMETHOD Cairo_pushGroup(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_push_group(cr);
    RETURNvoid_();
}

//## @Native void Cairo.push_group_with_content(int content);
KMETHOD Cairo_pushGroupWithContent(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_content_t content = PKGInt_to(cairo_content_t, 1);

    cairo_push_group_with_content(cr, content);
    RETURNvoid_();
}

//## @Native CairoPattern Cairo.pop_group();
KMETHOD Cairo_popGroup(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_pattern_t* ret = cairo_pop_group(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native void Cairo.pop_group_to_source();
KMETHOD Cairo_popGroupToSource(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_pop_group_to_source(cr);
    RETURNvoid_();
}

//## @Native void Cairo.set_operator(int op);
KMETHOD Cairo_setOperator(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_operator_t op = PKGInt_to(cairo_operator_t, 1);

    cairo_set_operator(cr, op);
    RETURNvoid_();
}

//## @Native void Cairo.set_source(CairoPattern source);
KMETHOD Cairo_setSource(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_pattern_t* source = PKGRawPtr_to(cairo_pattern_t*, 1);

    cairo_set_source(cr, source);
    RETURNvoid_();
}

//## @Native void Cairo.set_source_rgb(double red, double green, double blue);
KMETHOD Cairo_setSourceRgb(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double red = PKGFloat_to(double, 1);
    double green = PKGFloat_to(double, 2);
    double blue = PKGFloat_to(double, 3);

    cairo_set_source_rgb(cr, red, green, blue);
    RETURNvoid_();
}

//## @Native void Cairo.set_source_rgba(double red, double green, double blue, double alpha);
KMETHOD Cairo_setSourceRgba(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double red = PKGFloat_to(double, 1);
    double green = PKGFloat_to(double, 2);
    double blue = PKGFloat_to(double, 3);
    double alpha = PKGFloat_to(double, 4);

    cairo_set_source_rgba(cr, red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void Cairo.set_source_surface(CairoSurface surface, double x, double y);
KMETHOD Cairo_setSourceSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 1);
    double x = PKGFloat_to(double, 2);
    double y = PKGFloat_to(double, 3);

    cairo_set_source_surface(cr, surface, x, y);
    RETURNvoid_();
}

//## @Native void Cairo.set_tolerance(double tolerance);
KMETHOD Cairo_setTolerance(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double tolerance = PKGFloat_to(double, 1);

    cairo_set_tolerance(cr, tolerance);
    RETURNvoid_();
}

//## @Native void Cairo.set_antialias(int antialias);
KMETHOD Cairo_setAntialias(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_antialias_t antialias = PKGInt_to(cairo_antialias_t, 1);

    cairo_set_antialias(cr, antialias);
    RETURNvoid_();
}

//## @Native void Cairo.set_fill_rule(int fill_rule);
KMETHOD Cairo_setFillRule(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_fill_rule_t fill_rule = PKGInt_to(cairo_fill_rule_t, 1);

    cairo_set_fill_rule(cr, fill_rule);
    RETURNvoid_();
}

//## @Native void Cairo.set_line_width(double width);
KMETHOD Cairo_setLineWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double width = PKGFloat_to(double, 1);

    cairo_set_line_width(cr, width);
    RETURNvoid_();
}

//## @Native void Cairo.set_line_cap(int line_cap);
KMETHOD Cairo_setLineCap(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_line_cap_t line_cap = PKGInt_to(cairo_line_cap_t, 1);

    cairo_set_line_cap(cr, line_cap);
    RETURNvoid_();
}

//## @Native void Cairo.set_line_join(int line_join);
KMETHOD Cairo_setLineJoin(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_line_join_t line_join = PKGInt_to(cairo_line_join_t, 1);

    cairo_set_line_join(cr, line_join);
    RETURNvoid_();
}

//## @Native void Cairo.set_dash(double[] dashes, int num_dashes, double offset);
KMETHOD Cairo_setDash(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* dashes = PKGFArray_to(double*, 1);
    int num_dashes = PKGInt_to(int, 2);
    double offset = PKGFloat_to(double, 3);

    cairo_set_dash(cr, dashes, num_dashes, offset);
    RETURNvoid_();
}

//## @Native void Cairo.set_miter_limit(double limit);
KMETHOD Cairo_setMiterLimit(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double limit = PKGFloat_to(double, 1);

    cairo_set_miter_limit(cr, limit);
    RETURNvoid_();
}

//## @Native void Cairo.translate(double tx, double ty);
KMETHOD Cairo_translate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double tx = PKGFloat_to(double, 1);
    double ty = PKGFloat_to(double, 2);

    cairo_translate(cr, tx, ty);
    RETURNvoid_();
}

//## @Native void Cairo.scale(double sx, double sy);
KMETHOD Cairo_scale(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double sx = PKGFloat_to(double, 1);
    double sy = PKGFloat_to(double, 2);

    cairo_scale(cr, sx, sy);
    RETURNvoid_();
}

//## @Native void Cairo.rotate(double angle);
KMETHOD Cairo_rotate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double angle = PKGFloat_to(double, 1);

    cairo_rotate(cr, angle);
    RETURNvoid_();
}

//## @Native void Cairo.transform(cairo_matrix_t* matrix);
KMETHOD Cairo_transform(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_transform(cr, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.set_matrix(cairo_matrix_t* matrix);
KMETHOD Cairo_setMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_set_matrix(cr, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.identity_matrix();
KMETHOD Cairo_identityMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_identity_matrix(cr);
    RETURNvoid_();
}

//## @Native void Cairo.user_to_device(double* x, double* y);
KMETHOD Cairo_userToDevice(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x = PKGFArray_to(double*, 1);
    double* y = PKGFArray_to(double*, 2);

    cairo_user_to_device(cr, x, y);
    RETURNvoid_();
}

//## @Native void Cairo.user_to_device_distance(double* dx, double* dy);
KMETHOD Cairo_userToDeviceDistance(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* dx = PKGFArray_to(double*, 1);
    double* dy = PKGFArray_to(double*, 2);

    cairo_user_to_device_distance(cr, dx, dy);
    RETURNvoid_();
}

//## @Native void Cairo.device_to_user(double* x, double* y);
KMETHOD Cairo_deviceToUser(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x = PKGFArray_to(double*, 1);
    double* y = PKGFArray_to(double*, 2);

    cairo_device_to_user(cr, x, y);
    RETURNvoid_();
}

//## @Native void Cairo.device_to_user_distance(double* dx, double* dy);
KMETHOD Cairo_deviceToUserDistance(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* dx = PKGFArray_to(double*, 1);
    double* dy = PKGFArray_to(double*, 2);

    cairo_device_to_user_distance(cr, dx, dy);
    RETURNvoid_();
}

//## @Native void Cairo.new_path();
KMETHOD Cairo_newPath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_new_path(cr);
    RETURNvoid_();
}

//## @Native void Cairo.move_to(double x, double y);
KMETHOD Cairo_moveTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);

    cairo_move_to(cr, x, y);
    RETURNvoid_();
}

//## @Native void Cairo.new_sub_path();
KMETHOD Cairo_newSubPath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_new_sub_path(cr);
    RETURNvoid_();
}

//## @Native void Cairo.line_to(double x, double y);
KMETHOD Cairo_lineTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);

    cairo_line_to(cr, x, y);
    RETURNvoid_();
}

//## @Native void Cairo.curve_to(double x1, double y1, double x2, double y2, double x3, double y3);
KMETHOD Cairo_curveTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x1 = PKGFloat_to(double, 1);
    double y1 = PKGFloat_to(double, 2);
    double x2 = PKGFloat_to(double, 3);
    double y2 = PKGFloat_to(double, 4);
    double x3 = PKGFloat_to(double, 5);
    double y3 = PKGFloat_to(double, 6);

    cairo_curve_to(cr, x1, y1, x2, y2, x3, y3);
    RETURNvoid_();
}

//## @Native void Cairo.arc(double xc, double yc, double radius, double angle1, double angle2);
KMETHOD Cairo_arc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double xc = PKGFloat_to(double, 1);
    double yc = PKGFloat_to(double, 2);
    double radius = PKGFloat_to(double, 3);
    double angle1 = PKGFloat_to(double, 4);
    double angle2 = PKGFloat_to(double, 5);

    cairo_arc(cr, xc, yc, radius, angle1, angle2);
    RETURNvoid_();
}

//## @Native void Cairo.arc_negative(double xc, double yc, double radius, double angle1, double angle2);
KMETHOD Cairo_arcNegative(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double xc = PKGFloat_to(double, 1);
    double yc = PKGFloat_to(double, 2);
    double radius = PKGFloat_to(double, 3);
    double angle1 = PKGFloat_to(double, 4);
    double angle2 = PKGFloat_to(double, 5);

    cairo_arc_negative(cr, xc, yc, radius, angle1, angle2);
    RETURNvoid_();
}

//## @Native void Cairo.rel_move_to(double dx, double dy);
KMETHOD Cairo_relMoveTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double dx = PKGFloat_to(double, 1);
    double dy = PKGFloat_to(double, 2);

    cairo_rel_move_to(cr, dx, dy);
    RETURNvoid_();
}

//## @Native void Cairo.rel_line_to(double dx, double dy);
KMETHOD Cairo_relLineTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double dx = PKGFloat_to(double, 1);
    double dy = PKGFloat_to(double, 2);

    cairo_rel_line_to(cr, dx, dy);
    RETURNvoid_();
}

//## @Native void Cairo.rel_curve_to(double dx1, double dy1, double dx2, double dy2, double dx3, double dy3);
KMETHOD Cairo_relCurveTo(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double dx1 = PKGFloat_to(double, 1);
    double dy1 = PKGFloat_to(double, 2);
    double dx2 = PKGFloat_to(double, 3);
    double dy2 = PKGFloat_to(double, 4);
    double dx3 = PKGFloat_to(double, 5);
    double dy3 = PKGFloat_to(double, 6);

    cairo_rel_curve_to(cr, dx1, dy1, dx2, dy2, dx3, dy3);
    RETURNvoid_();
}

//## @Native void Cairo.rectangle(double x, double y, double width, double height);
KMETHOD Cairo_rectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);
    double width = PKGFloat_to(double, 3);
    double height = PKGFloat_to(double, 4);

    cairo_rectangle(cr, x, y, width, height);
    RETURNvoid_();
}

//## @Native void Cairo.close_path();
KMETHOD Cairo_closePath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_close_path(cr);
    RETURNvoid_();
}

//## @Native void Cairo.path_extents(double* x1, double* y1, double* x2, double* y2);
KMETHOD Cairo_pathExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x1 = PKGFArray_to(double*, 1);
    double* y1 = PKGFArray_to(double*, 2);
    double* x2 = PKGFArray_to(double*, 3);
    double* y2 = PKGFArray_to(double*, 4);

    cairo_path_extents(cr, x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void Cairo.paint();
KMETHOD Cairo_paint(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_paint(cr);
    RETURNvoid_();
}

//## @Native void Cairo.paint_with_alpha(double alpha);
KMETHOD Cairo_paintWithAlpha(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double alpha = PKGFloat_to(double, 1);

    cairo_paint_with_alpha(cr, alpha);
    RETURNvoid_();
}

//## @Native void Cairo.mask(cairo_pattern_t* pattern);
KMETHOD Cairo_mask(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 1);

    cairo_mask(cr, pattern);
    RETURNvoid_();
}

//## @Native void Cairo.mask_surface(CairoSurface surface, double surface_x, double surface_y);
KMETHOD Cairo_maskSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 1);
    double surface_x = PKGFloat_to(double, 2);
    double surface_y = PKGFloat_to(double, 3);

    cairo_mask_surface(cr, surface, surface_x, surface_y);
    RETURNvoid_();
}

//## @Native void Cairo.stroke();
KMETHOD Cairo_stroke(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_stroke(cr);
    RETURNvoid_();
}

//## @Native void Cairo.stroke_preserve();
KMETHOD Cairo_strokePreserve(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_stroke_preserve(cr);
    RETURNvoid_();
}

//## @Native void Cairo.fill();
KMETHOD Cairo_fill(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_fill(cr);
    RETURNvoid_();
}

//## @Native void Cairo.fill_preserve();
KMETHOD Cairo_fillPreserve(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_fill_preserve(cr);
    RETURNvoid_();
}

//## @Native void Cairo.copy_page();
KMETHOD Cairo_copyPage(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_copy_page(cr);
    RETURNvoid_();
}

//## @Native void Cairo.show_page();
KMETHOD Cairo_showPage(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_show_page(cr);
    RETURNvoid_();
}

//## @Native cairo_bool_t Cairo.in_stroke(double x, double y);
KMETHOD Cairo_inStroke(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);

    cairo_bool_t ret = cairo_in_stroke(cr, x, y);
    RETURNb_(ret);
}

//## @Native cairo_bool_t Cairo.in_fill(double x, double y);
KMETHOD Cairo_inFill(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);

    cairo_bool_t ret = cairo_in_fill(cr, x, y);
    RETURNb_(ret);
}

//## @Native cairo_bool_t Cairo.in_clip(double x, double y);
KMETHOD Cairo_inClip(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);

    cairo_bool_t ret = cairo_in_clip(cr, x, y);
    RETURNb_(ret);
}

//## @Native void Cairo.stroke_extents(double* x1, double* y1, double* x2, double* y2);
KMETHOD Cairo_strokeExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x1 = PKGFArray_to(double*, 1);
    double* y1 = PKGFArray_to(double*, 2);
    double* x2 = PKGFArray_to(double*, 3);
    double* y2 = PKGFArray_to(double*, 4);

    cairo_stroke_extents(cr, x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void Cairo.fill_extents(double* x1, double* y1, double* x2, double* y2);
KMETHOD Cairo_fillExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x1 = PKGFArray_to(double*, 1);
    double* y1 = PKGFArray_to(double*, 2);
    double* x2 = PKGFArray_to(double*, 3);
    double* y2 = PKGFArray_to(double*, 4);

    cairo_fill_extents(cr, x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void Cairo.reset_clip();
KMETHOD Cairo_resetClip(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_reset_clip(cr);
    RETURNvoid_();
}

//## @Native void Cairo.clip();
KMETHOD Cairo_clip(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_clip(cr);
    RETURNvoid_();
}

//## @Native void Cairo.clip_preserve();
KMETHOD Cairo_clipPreserve(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_clip_preserve(cr);
    RETURNvoid_();
}

//## @Native void Cairo.clip_extents(double* x1, double* y1, double* x2, double* y2);
KMETHOD Cairo_clipExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x1 = PKGFArray_to(double*, 1);
    double* y1 = PKGFArray_to(double*, 2);
    double* x2 = PKGFArray_to(double*, 3);
    double* y2 = PKGFArray_to(double*, 4);

    cairo_clip_extents(cr, x1, y1, x2, y2);
    RETURNvoid_();
}

static void my_cairo_rectangle_list_free(void *p)
{
    cairo_rectangle_list_destroy((cairo_rectangle_list_t *)p);
}

//## @Native cairo_rectangle_list_t* Cairo.copy_clip_rectangle_list();
KMETHOD Cairo_copyClipRectangleList(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_rectangle_list_t* ret = cairo_copy_clip_rectangle_list(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_rectangle_list_free);
    RETURN_(p);
}

static void my_cairo_glyph_free(void *p)
{
    cairo_glyph_t *glyphs = (cairo_glyph_t*)p;
    cairo_glyph_free(glyphs);
}
//## @Native cairo_glyph_t* Cairo.glyph_allocate(int num_glyphs);
KMETHOD CairoGlyph_new(CTX ctx, ksfp_t *sfp _RIX)
{
    int num_glyphs = PKGInt_to(int, 1);

    cairo_glyph_t* ret = cairo_glyph_allocate(num_glyphs);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_glyph_free);
    RETURN_(p);
}

static void my_cairo_text_cluster_free(void *p)
{
    cairo_text_cluster_t* clusters = (cairo_text_cluster_t*)p;
    cairo_text_cluster_free(clusters);
}
//## @Native cairo_text_cluster_t* Cairo.text_cluster_allocate(int num_clusters);
KMETHOD CairoTextCluster_new(CTX ctx, ksfp_t *sfp _RIX)
{
    int num_clusters = PKGInt_to(int, 1);

    cairo_text_cluster_t* ret = cairo_text_cluster_allocate(num_clusters);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_text_cluster_free);
    RETURN_(p);
}

static void my_cairo_font_options_free(void *p)
{
    cairo_font_options_destroy((cairo_font_options_t *)p);
}
//## @Native cairo_font_options_t* Cairo.font_options_create();
KMETHOD CairoFontOptions_new(CTX ctx, ksfp_t *sfp _RIX)
{

    cairo_font_options_t* ret = cairo_font_options_create();
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_options_free);
    RETURN_(p);
}

//## @Native cairo_font_options_t* Cairo.font_options_copy(cairo_font_options_t* original);
KMETHOD CairoFontOptions_copy(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* original = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_font_options_t* ret = cairo_font_options_copy(original);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_options_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.font_options_status(cairo_font_options_t* options);
KMETHOD CairoFontOptions_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_status_t ret = cairo_font_options_status(options);
    RETURNi_(ret);
}

//## @Native void Cairo.font_options_merge(cairo_font_options_t* options, cairo_font_options_t* other);
KMETHOD CairoFontOptions_merge(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);
    cairo_font_options_t* other = PKGRawPtr_to(cairo_font_options_t*, 1);

    cairo_font_options_merge(options, other);
    RETURNvoid_();
}

//## @Native long Cairo.font_options_hash(cairo_font_options_t* options);
KMETHOD CairoFontOptions_hash(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    long ret = cairo_font_options_hash(options);
    RETURNi_(ret);
}

//## @Native void Cairo.font_options_set_antialias(cairo_font_options_t* options, cairo_antialias_t antialias);
KMETHOD CairoFontOptions_setAntialias(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);
    cairo_antialias_t antialias = PKGInt_to(cairo_antialias_t, 1);

    cairo_font_options_set_antialias(options, antialias);
    RETURNvoid_();
}

//## @Native cairo_antialias_t Cairo.font_options_get_antialias(cairo_font_options_t* options);
KMETHOD CairoFontOptions_getAntialias(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_antialias_t ret = cairo_font_options_get_antialias(options);
    RETURNi_(ret);
}

//## @Native void Cairo.font_options_set_subpixel_order(cairo_font_options_t* options, cairo_subpixel_order_t subpixel_order);
KMETHOD CairoFontOptions_setSubpixelOrder(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);
    cairo_subpixel_order_t subpixel_order = PKGInt_to(cairo_subpixel_order_t, 1);

    cairo_font_options_set_subpixel_order(options, subpixel_order);
    RETURNvoid_();
}

//## @Native cairo_subpixel_order_t Cairo.font_options_get_subpixel_order(cairo_font_options_t* options);
KMETHOD CairoFontOptions_getSubpixelOrder(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_subpixel_order_t ret = cairo_font_options_get_subpixel_order(options);
    RETURNi_(ret);
}

//## @Native void Cairo.font_options_set_hint_style(cairo_font_options_t* options, cairo_hint_style_t hint_style);
KMETHOD CairoFontOptions_setHintStyle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);
    cairo_hint_style_t hint_style = PKGInt_to(cairo_hint_style_t, 1);

    cairo_font_options_set_hint_style(options, hint_style);
    RETURNvoid_();
}

//## @Native cairo_hint_style_t Cairo.font_options_get_hint_style(cairo_font_options_t* options);
KMETHOD CairoFontOptions_getHintStyle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_hint_style_t ret = cairo_font_options_get_hint_style(options);
    RETURNi_(ret);
}

//## @Native void Cairo.font_options_set_hint_metrics(cairo_font_options_t* options, cairo_hint_metrics_t hint_metrics);
KMETHOD CairoFontOptions_setHintMetrics(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);
    cairo_hint_metrics_t hint_metrics = PKGInt_to(cairo_hint_metrics_t, 1);

    cairo_font_options_set_hint_metrics(options, hint_metrics);
    RETURNvoid_();
}

//## @Native cairo_hint_metrics_t Cairo.font_options_get_hint_metrics(cairo_font_options_t* options);
KMETHOD CairoFontOptions_getHintMetrics(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 0);

    cairo_hint_metrics_t ret = cairo_font_options_get_hint_metrics(options);
    RETURNi_(ret);
}

//## @Native void Cairo.select_font_face(String family, int slant, int weight);
KMETHOD Cairo_selectFontFace(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    char* family = PKGString_to(char*, 1);
    cairo_font_slant_t slant = PKGInt_to(cairo_font_slant_t, 2);
    cairo_font_weight_t weight = PKGInt_to(cairo_font_weight_t, 3);

    cairo_select_font_face(cr, family, slant, weight);
    RETURNvoid_();
}

//## @Native void Cairo.set_font_size(double size);
KMETHOD Cairo_setFontSize(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double size = PKGFloat_to(double, 1);

    cairo_set_font_size(cr, size);
    RETURNvoid_();
}

//## @Native void Cairo.set_font_matrix(cairo_matrix_t* matrix);
KMETHOD Cairo_setFontMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_set_font_matrix(cr, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.get_font_matrix(cairo_matrix_t* matrix);
KMETHOD Cairo_getFontMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);
    KNH_TODO("");

    cairo_get_font_matrix(cr, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.set_font_options(cairo_font_options_t* options);
KMETHOD Cairo_setFontOptions(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 1);

    cairo_set_font_options(cr, options);
    RETURNvoid_();
}

//## @Native void Cairo.get_font_options(cairo_font_options_t* options);
KMETHOD Cairo_getFontOptions(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 1);
    KNH_TODO("");

    cairo_get_font_options(cr, options);
    RETURNvoid_();
}

static void my_cairo_font_face_free(void *p)
{
    cairo_font_face_destroy((cairo_font_face_t*)p);
}
static void my_cairo_scaled_font(void *p)
{
    cairo_scaled_font_destroy((cairo_scaled_font_t*)p);
}


//## @Native void Cairo.set_font_face(cairo_font_face_t* font_face);
KMETHOD Cairo_setFontFace(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 1);

    cairo_set_font_face(cr, font_face);
    RETURNvoid_();
}

//## @Native cairo_font_face_t* Cairo.get_font_face();
KMETHOD Cairo_getFontFace(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_font_face_t* ret = cairo_get_font_face(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_face_free);
    RETURN_(p);
}

//## @Native void Cairo.set_scaled_font(cairo_scaled_font_t* scaled_font);
KMETHOD Cairo_setScaledFont(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 1);

    cairo_set_scaled_font(cr, scaled_font);
    RETURNvoid_();
}

//## @Native cairo_scaled_font_t* Cairo.get_scaled_font();
KMETHOD Cairo_getScaledFont(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_scaled_font_t* ret = cairo_get_scaled_font(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_scaled_font);
    RETURN_(p);
}

//## @Native void Cairo.show_text(char* utf8);
KMETHOD Cairo_showText(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    char* utf8 = PKGString_to(char*, 1);

    cairo_show_text(cr, utf8);
    RETURNvoid_();
}

//## @Native void Cairo.show_glyphs(cairo_glyph_t* glyphs, int num_glyphs);
KMETHOD Cairo_showGlyphs(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_glyph_t* glyphs = PKGRawPtr_to(cairo_glyph_t*, 1);
    int num_glyphs = PKGInt_to(int, 2);

    cairo_show_glyphs(cr, glyphs, num_glyphs);
    RETURNvoid_();
}

//## @Native void Cairo.show_text_glyphs(char* utf8, int utf8_len, cairo_glyph_t* glyphs, int num_glyphs, cairo_text_cluster_t* clusters, int num_clusters, cairo_text_cluster_flags_t cluster_flags);
KMETHOD Cairo_showTextGlyphs(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    char* utf8 = PKGString_to(char*, 1);
    int utf8_len = PKGInt_to(int, 2);
    cairo_glyph_t* glyphs = PKGRawPtr_to(cairo_glyph_t*, 3);
    int num_glyphs = PKGInt_to(int, 4);
    cairo_text_cluster_t* clusters = PKGRawPtr_to(cairo_text_cluster_t*, 5);
    int num_clusters = PKGInt_to(int, 6);
    cairo_text_cluster_flags_t cluster_flags = PKGInt_to(cairo_text_cluster_flags_t, 7);

    cairo_show_text_glyphs(cr, utf8, utf8_len, glyphs, num_glyphs, clusters, num_clusters, cluster_flags);
    RETURNvoid_();
}

//## @Native void Cairo.text_path(char* utf8);
KMETHOD Cairo_textPath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    char* utf8 = PKGString_to(char*, 1);

    cairo_text_path(cr, utf8);
    RETURNvoid_();
}

//## @Native void Cairo.glyph_path(cairo_glyph_t* glyphs, int num_glyphs);
KMETHOD CairoGlyph_path(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_glyph_t* glyphs = PKGRawPtr_to(cairo_glyph_t*, 1);
    int num_glyphs = PKGInt_to(int, 2);

    cairo_glyph_path(cr, glyphs, num_glyphs);
    RETURNvoid_();
}

//## @Native void Cairo.text_extents(char* utf8, cairo_text_extents_t* extents);
KMETHOD Cairo_textExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    char* utf8 = PKGString_to(char*, 1);
    cairo_text_extents_t* extents = PKGRawPtr_to(cairo_text_extents_t*, 2);

    cairo_text_extents(cr, utf8, extents);
    RETURNvoid_();
}

//## @Native void Cairo.glyph_extents(cairo_glyph_t* glyphs, int num_glyphs, cairo_text_extents_t* extents);
KMETHOD CairoGlyph_extents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_glyph_t* glyphs = PKGRawPtr_to(cairo_glyph_t*, 1);
    int num_glyphs = PKGInt_to(int, 2);
    cairo_text_extents_t* extents = PKGRawPtr_to(cairo_text_extents_t*, 3);

    cairo_glyph_extents(cr, glyphs, num_glyphs, extents);
    RETURNvoid_();
}

//## @Native void Cairo.font_extents(cairo_font_extents_t* extents);
KMETHOD Cairo_fontExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_font_extents_t* extents = PKGRawPtr_to(cairo_font_extents_t*, 1);

    cairo_font_extents(cr, extents);
    RETURNvoid_();
}

//## @Native cairo_font_face_t* Cairo.font_face_reference(cairo_font_face_t* font_face);
KMETHOD CairoFontFace_reference(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_font_face_t* ret = cairo_font_face_reference(font_face);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_face_free);
    RETURN_(p);
}


////## @Native int Cairo.font_face_get_reference_count(cairo_font_face_t* font_face);
//KMETHOD CairoFontFace_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
//
//    int ret = cairo_font_face_get_reference_count(font_face);
//    RETURNi_(ret);
//}

//## @Native cairo_status_t Cairo.font_face_status(cairo_font_face_t* font_face);
KMETHOD CairoFontFace_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_status_t ret = cairo_font_face_status(font_face);
    RETURNi_(ret);
}

//## @Native cairo_font_type_t Cairo.font_face_get_type(cairo_font_face_t* font_face);
KMETHOD CairoFontFace_getType(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_font_type_t ret = cairo_font_face_get_type(font_face);
    RETURNi_(ret);
}

//## @Native void* Cairo.font_face_get_user_data(cairo_font_face_t* font_face, cairo_user_data_key_t* key);
KMETHOD CairoFontFace_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_font_face_get_user_data(font_face, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.font_face_set_user_data(cairo_font_face_t* font_face, cairo_user_data_key_t* key, void* user_data, cairo_destroy_func_t destroy);
KMETHOD CairoFontFace_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);

    cairo_status_t ret = cairo_font_face_set_user_data(font_face, key, user_data, destroy);
    KNH_TODO("");
    RETURNi_(ret);
}

//## @Native cairo_scaled_font_t* Cairo.scaled_font_create(cairo_font_face_t* font_face, cairo_matrix_t* font_matrix, cairo_matrix_t* ctm, cairo_font_options_t* options);
KMETHOD CairoScaledFont_create(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_matrix_t* font_matrix = PKGRawPtr_to(cairo_matrix_t*, 1);
    cairo_matrix_t* ctm = PKGRawPtr_to(cairo_matrix_t*, 2);
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 3);

    cairo_scaled_font_t* ret = cairo_scaled_font_create(font_face, font_matrix, ctm, options);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_scaled_font);
    RETURN_(p);
}

//## @Native cairo_scaled_font_t* Cairo.scaled_font_reference(cairo_scaled_font_t* scaled_font);
KMETHOD CairoScaledFont_reference(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);

    cairo_scaled_font_t* ret = cairo_scaled_font_reference(scaled_font);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_scaled_font);
    RETURN_(p);
}

////## @Native int Cairo.scaled_font_get_reference_count(cairo_scaled_font_t* scaled_font);
//KMETHOD CairoScaledFont_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
//
//    int ret = cairo_scaled_font_get_reference_count(scaled_font);
//    RETURNi_(ret);
//}

//## @Native cairo_status_t Cairo.scaled_font_status(cairo_scaled_font_t* scaled_font);
KMETHOD CairoScaledFont_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);

    cairo_status_t ret = cairo_scaled_font_status(scaled_font);
    RETURNi_(ret);
}

//## @Native cairo_font_type_t Cairo.scaled_font_get_type(cairo_scaled_font_t* scaled_font);
KMETHOD CairoScaledFont_getType(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);

    cairo_font_type_t ret = cairo_scaled_font_get_type(scaled_font);
    RETURNi_(ret);
}

//## @Native void* Cairo.scaled_font_get_user_data(cairo_scaled_font_t* scaled_font, cairo_user_data_key_t* key);
KMETHOD CairoScaledFont_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_scaled_font_get_user_data(scaled_font, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.scaled_font_set_user_data(cairo_scaled_font_t* scaled_font, cairo_user_data_key_t* key, void* user_data, cairo_destroy_func_t destroy);
KMETHOD CairoScaledFont_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);

    cairo_status_t ret = cairo_scaled_font_set_user_data(scaled_font, key, user_data, destroy);
    RETURNi_(ret);
}

//## @Native void Cairo.scaled_font_extents(cairo_scaled_font_t* scaled_font, cairo_font_extents_t* extents);
KMETHOD CairoScaledFont_extents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_font_extents_t* extents = PKGRawPtr_to(cairo_font_extents_t*, 1);

    cairo_scaled_font_extents(scaled_font, extents);
    RETURNvoid_();
}

//## @Native void Cairo.scaled_font_text_extents(cairo_scaled_font_t* scaled_font, char* utf8, cairo_text_extents_t* extents);
KMETHOD CairoScaledFont_textExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    char* utf8 = PKGString_to(char*, 1);
    cairo_text_extents_t* extents = PKGRawPtr_to(cairo_text_extents_t*, 2);

    cairo_scaled_font_text_extents(scaled_font, utf8, extents);
    RETURNvoid_();
}

//## @Native void Cairo.scaled_font_glyph_extents(cairo_scaled_font_t* scaled_font, cairo_glyph_t* glyphs, int num_glyphs, cairo_text_extents_t* extents);
KMETHOD CairoScaledFont_glyphExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_glyph_t* glyphs = PKGRawPtr_to(cairo_glyph_t*, 1);
    int num_glyphs = PKGInt_to(int, 2);
    cairo_text_extents_t* extents = PKGRawPtr_to(cairo_text_extents_t*, 3);

    cairo_scaled_font_glyph_extents(scaled_font, glyphs, num_glyphs, extents);
    RETURNvoid_();
}

//## @Native cairo_status_t Cairo.scaled_font_text_to_glyphs(cairo_scaled_font_t* scaled_font, double x, double y, char* utf8, int utf8_len, cairo_glyph_t** glyphs, int* num_glyphs, cairo_text_cluster_t** clusters, int* num_clusters, cairo_text_cluster_flags_t* cluster_flags);
KMETHOD CairoScaledFont_textToGlyphs(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);
    char* utf8 = PKGString_to(char*, 3);
    int utf8_len = PKGInt_to(int, 4);
    cairo_glyph_t** glyphs = PKGRawPtr_to(cairo_glyph_t**, 5);
    int* num_glyphs = PKGIArray_to(int*, 6);
    cairo_text_cluster_t** clusters = PKGRawPtr_to(cairo_text_cluster_t**, 7);
    int* num_clusters = PKGRawPtr_to(int*, 8);
    cairo_text_cluster_flags_t* cluster_flags = PKGRawPtr_to(cairo_text_cluster_flags_t*, 9);

    KNH_TODO("");
    cairo_status_t ret = cairo_scaled_font_text_to_glyphs(scaled_font, x, y, utf8, utf8_len, glyphs, num_glyphs, clusters, num_clusters, cluster_flags);
    RETURNi_(ret);
}

//## @Native cairo_font_face_t* Cairo.scaled_font_get_font_face(cairo_scaled_font_t* scaled_font);
KMETHOD CairoScaledFont_getFontFace(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);

    cairo_font_face_t* ret = cairo_scaled_font_get_font_face(scaled_font);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_face_free);
    RETURN_(p);
}

//## @Native void Cairo.scaled_font_get_font_matrix(cairo_scaled_font_t* scaled_font, cairo_matrix_t* font_matrix);
KMETHOD CairoScaledFont_getFontMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_matrix_t* font_matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_scaled_font_get_font_matrix(scaled_font, font_matrix);
    RETURNvoid_();
}

//## @Native void Cairo.scaled_font_get_ctm(cairo_scaled_font_t* scaled_font, cairo_matrix_t* ctm);
KMETHOD CairoScaledFont_getCtm(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_matrix_t* ctm = PKGRawPtr_to(cairo_matrix_t*, 1);
    KNH_TODO("");

    cairo_scaled_font_get_ctm(scaled_font, ctm);
    RETURNvoid_();
}
/*DONE*/

//## @Native void Cairo.scaled_font_get_scale_matrix(cairo_scaled_font_t* scaled_font, cairo_matrix_t* scale_matrix);
KMETHOD CairoScaledFont_getScaleMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_matrix_t* scale_matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_scaled_font_get_scale_matrix(scaled_font, scale_matrix);
    RETURNvoid_();
}

//## @Native void Cairo.scaled_font_get_font_options(cairo_scaled_font_t* scaled_font, cairo_font_options_t* options);
KMETHOD CairoScaledFont_getFontOptions(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_scaled_font_t* scaled_font = PKGRawPtr_to(cairo_scaled_font_t*, 0);
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 1);

    cairo_scaled_font_get_font_options(scaled_font, options);
    RETURNvoid_();
}

//## @Native cairo_font_face_t* Cairo.toy_font_face_create(char* family, int slant, int weight);
KMETHOD Cairo_toyFontFaceCreate(CTX ctx, ksfp_t *sfp _RIX)
{
    char* family = PKGString_to(char*, 0);
    cairo_font_slant_t slant = PKGInt_to(cairo_font_slant_t, 1);
    cairo_font_weight_t weight = PKGInt_to(cairo_font_weight_t, 2);

    cairo_font_face_t* ret = cairo_toy_font_face_create(family, slant, weight);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_face_free);
    RETURN_(p);
}

//## @Native char* Cairo.toy_font_face_get_family(cairo_font_face_t* font_face);
KMETHOD Cairo_toyFontFaceGetFamily(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    const char* ret = cairo_toy_font_face_get_family(font_face);
    kString *s = new_String(ctx, ret);
    RETURN_(s);
}

//## @Native int Cairo.toy_font_face_get_slant(cairo_font_face_t* font_face);
KMETHOD Cairo_toyFontFaceGetSlant(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_font_slant_t ret = cairo_toy_font_face_get_slant(font_face);
    RETURNi_(ret);
}

//## @Native int Cairo.toy_font_face_get_weight(cairo_font_face_t* font_face);
KMETHOD Cairo_toyFontFaceGetWeight(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_font_weight_t ret = cairo_toy_font_face_get_weight(font_face);
    RETURNi_(ret);
}

//## @Native cairo_font_face_t* Cairo.user_font_face_create();
KMETHOD CairoUserFontFace_create(CTX ctx, ksfp_t *sfp _RIX)
{

    cairo_font_face_t* ret = cairo_user_font_face_create();
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_font_face_free);
    RETURN_(p);
}

//## @Native void Cairo.user_font_face_set_init_func(cairo_font_face_t* font_face, cairo_user_scaled_font_init_func_t init_func);
KMETHOD CairoUserFontFace_setInitFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_scaled_font_init_func_t init_func = PKGRawPtr_to(cairo_user_scaled_font_init_func_t, 1);
    KNH_TODO("");

    cairo_user_font_face_set_init_func(font_face, init_func);
    RETURNvoid_();
}

//## @Native void Cairo.user_font_face_set_render_glyph_func(cairo_font_face_t* font_face, cairo_user_scaled_font_render_glyph_func_t render_glyph_func);
KMETHOD CairoUserFontFace_setRenderGlyphFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_scaled_font_render_glyph_func_t render_glyph_func = PKGRawPtr_to(cairo_user_scaled_font_render_glyph_func_t, 1);

    KNH_TODO("");
    cairo_user_font_face_set_render_glyph_func(font_face, render_glyph_func);
    RETURNvoid_();
}

//## @Native void Cairo.user_font_face_set_text_to_glyphs_func(cairo_font_face_t* font_face, cairo_user_scaled_font_text_to_glyphs_func_t text_to_glyphs_func);
KMETHOD CairoUserFontFace_setTextToGlyphsFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_scaled_font_text_to_glyphs_func_t text_to_glyphs_func = PKGRawPtr_to(cairo_user_scaled_font_text_to_glyphs_func_t, 1);

    KNH_TODO("");
    cairo_user_font_face_set_text_to_glyphs_func(font_face, text_to_glyphs_func);
    RETURNvoid_();
}

//## @Native void Cairo.user_font_face_set_unicode_to_glyph_func(cairo_font_face_t* font_face, cairo_user_scaled_font_unicode_to_glyph_func_t unicode_to_glyph_func);
KMETHOD CairoUserFontFace_setUnicodeToGlyphFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);
    cairo_user_scaled_font_unicode_to_glyph_func_t unicode_to_glyph_func = PKGRawPtr_to(cairo_user_scaled_font_unicode_to_glyph_func_t, 1);

    KNH_TODO("");
    cairo_user_font_face_set_unicode_to_glyph_func(font_face, unicode_to_glyph_func);
    RETURNvoid_();
}

//## @Native cairo_user_scaled_font_init_func_t Cairo.user_font_face_get_init_func(cairo_font_face_t* font_face);
KMETHOD CairoUserFontFace_getInitFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_user_scaled_font_init_func_t ret = cairo_user_font_face_get_init_func(font_face);
    KNH_TODO("");
    RETURN_error(ret);
}

//## @Native cairo_user_scaled_font_render_glyph_func_t Cairo.user_font_face_get_render_glyph_func(cairo_font_face_t* font_face);
KMETHOD CairoUserFontFace_getRenderGlyphFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_user_scaled_font_render_glyph_func_t ret = cairo_user_font_face_get_render_glyph_func(font_face);
    KNH_TODO("");
    RETURN_error(ret);
}

//## @Native cairo_user_scaled_font_text_to_glyphs_func_t Cairo.user_font_face_get_text_to_glyphs_func(cairo_font_face_t* font_face);
KMETHOD CairoUserFontFace_getTextToGlyphsFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_user_scaled_font_text_to_glyphs_func_t ret = cairo_user_font_face_get_text_to_glyphs_func(font_face);
    KNH_TODO("");
    RETURN_error(ret);
}

//## @Native cairo_user_scaled_font_unicode_to_glyph_func_t Cairo.user_font_face_get_unicode_to_glyph_func(cairo_font_face_t* font_face);
KMETHOD CairoUserFontFace_getUnicodeToGlyphFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_font_face_t* font_face = PKGRawPtr_to(cairo_font_face_t*, 0);

    cairo_user_scaled_font_unicode_to_glyph_func_t ret = cairo_user_font_face_get_unicode_to_glyph_func(font_face);
    KNH_TODO("");
    RETURN_error(ret);
}

//## @Native int Cairo.get_operator();
KMETHOD Cairo_getOperator(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_operator_t ret = cairo_get_operator(cr);
    RETURNi_(ret);
}

//## @Native cairo_pattern_t* Cairo.get_source();
KMETHOD Cairo_getSource(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_pattern_t* ret = cairo_get_source(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native double Cairo.get_tolerance();
KMETHOD Cairo_getTolerance(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    double ret = cairo_get_tolerance(cr);
    RETURNf_(ret);
}

//## @Native cairo_antialias_t Cairo.get_antialias();
KMETHOD Cairo_getAntialias(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_antialias_t ret = cairo_get_antialias(cr);
    RETURNi_(ret);
}

//## @Native cairo_bool_t Cairo.has_current_point();
KMETHOD Cairo_hasCurrentPoint(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_bool_t ret = cairo_has_current_point(cr);
    RETURNb_(ret);
}

//## @Native void Cairo.get_current_point(double* x, double* y);
KMETHOD Cairo_getCurrentPoint(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* x = PKGFArray_to(double*, 1);
    double* y = PKGFArray_to(double*, 2);

    cairo_get_current_point(cr, x, y);
    RETURNvoid_();
}

//## @Native cairo_fill_rule_t Cairo.get_fill_rule();
KMETHOD Cairo_getFillRule(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_fill_rule_t ret = cairo_get_fill_rule(cr);
    RETURNi_(ret);
}

//## @Native double Cairo.get_line_width();
KMETHOD Cairo_getLineWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    double ret = cairo_get_line_width(cr);
    RETURNf_(ret);
}

//## @Native cairo_line_cap_t Cairo.get_line_cap();
KMETHOD Cairo_getLineCap(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_line_cap_t ret = cairo_get_line_cap(cr);
    RETURNi_(ret);
}

//## @Native int Cairo.get_line_join();
KMETHOD Cairo_getLineJoin(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_line_join_t ret = cairo_get_line_join(cr);
    RETURNi_(ret);
}

//## @Native double Cairo.get_miter_limit();
KMETHOD Cairo_getMiterLimit(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    double ret = cairo_get_miter_limit(cr);
    RETURNf_(ret);
}

//## @Native int Cairo.get_dash_count();
KMETHOD Cairo_getDashCount(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    int ret = cairo_get_dash_count(cr);
    RETURNi_(ret);
}

//## @Native void Cairo.get_dash(double* dashes, double* offset);
KMETHOD Cairo_getDash(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    double* dashes = PKGFArray_to(double*, 1);
    double* offset = PKGFArray_to(double*, 2);

    cairo_get_dash(cr, dashes, offset);
    RETURNvoid_();
}

//## @Native void Cairo.get_matrix(cairo_matrix_t* matrix);
KMETHOD Cairo_getMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_get_matrix(cr, matrix);
    RETURNvoid_();
}

static void my_cairo_surface_free(void *p)
{
    cairo_surface_destroy((cairo_surface_t*)p);
}

//## @Native CairoSurface Cairo.get_target();
KMETHOD Cairo_getTarget(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_surface_t* ret = cairo_get_target(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native CairoSurface Cairo.get_group_target();
KMETHOD Cairo_getGroupTarget(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_surface_t* ret = cairo_get_group_target(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

static void my_cairo_path_free(void *p)
{
    cairo_path_t* path = (cairo_path_t*) p;
    cairo_path_destroy(path);
}
//## @Native cairo_path_t* Cairo.copy_path();
KMETHOD Cairo_copyPath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_path_t* ret = cairo_copy_path(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_path_free);
    RETURN_(p);
}

//## @Native cairo_path_t* Cairo.copy_path_flat();
KMETHOD Cairo_copyPathFlat(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_path_t* ret = cairo_copy_path_flat(cr);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_path_free);
    RETURN_(p);
}

//## @Native void Cairo.append_path(cairo_path_t* path);
KMETHOD Cairo_appendPath(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);
    cairo_path_t* path = PKGRawPtr_to(cairo_path_t*, 1);

    cairo_append_path(cr, path);
    RETURNvoid_();
}

//## @Native cairo_status_t Cairo.status();
KMETHOD Cairo_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_t* cr = PKGRawPtr_to(cairo_t*, 0);

    cairo_status_t ret = cairo_status(cr);
    RETURNi_(ret);
}

//## @Native char* Cairo.status_to_string(cairo_status_t status);
KMETHOD Cairo_statusToString(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_status_t status = PKGInt_to(cairo_status_t, 0);

    const char* ret = cairo_status_to_string(status);
    kString *s = new_String(ctx, ret);
    RETURN_(s);
}

static void my_cairo_device_free(void *p)
{
    cairo_device_t* device = (cairo_device_t*) p;
    cairo_device_destroy(device);
}
////## @Native cairo_device_t* Cairo.device_reference(cairo_device_t* device);
//KMETHOD CairoDevice_reference(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);
//
//    cairo_device_t* ret = cairo_device_reference(device);
//    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_device_free);
//    RETURN_(p);
//}

//## @Native cairo_device_type_t Cairo.device_get_type(cairo_device_t* device);
KMETHOD CairoDevice_getType(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_device_type_t ret = cairo_device_get_type(device);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.device_status(cairo_device_t* device);
KMETHOD CairoDevice_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_status_t ret = cairo_device_status(device);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.device_acquire(cairo_device_t* device);
KMETHOD CairoDevice_acquire(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_status_t ret = cairo_device_acquire(device);
    RETURNi_(ret);
}

//## @Native void Cairo.device_release(cairo_device_t* device);
KMETHOD CairoDevice_release(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_device_release(device);
    RETURNvoid_();
}

//## @Native void Cairo.device_flush(cairo_device_t* device);
KMETHOD CairoDevice_flush(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_device_flush(device);
    RETURNvoid_();
}

//## @Native void Cairo.device_finish(cairo_device_t* device);
KMETHOD CairoDevice_finish(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);

    cairo_device_finish(device);
    RETURNvoid_();
}

////## @Native int Cairo.device_get_reference_count(cairo_device_t* device);
//KMETHOD CairoDevice_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);
//
//    int ret = cairo_device_get_reference_count(device);
//    RETURNi_(ret);
//}

//## @Native void* Cairo.device_get_user_data(cairo_device_t* device, cairo_user_data_key_t* key);
KMETHOD CairoDevice_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_device_get_user_data(device, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.device_set_user_data(cairo_device_t* device, cairo_user_data_key_t* key, void* user_data, cairo_destroy_func_t destroy);
KMETHOD CairoDevice_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_device_t* device = PKGRawPtr_to(cairo_device_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);

    KNH_TODO("");

    cairo_status_t ret = cairo_device_set_user_data(device, key, user_data, destroy);
    RETURNi_(ret);
}

//## @Native CairoSurFace Cairo.surface_create_similar(cairo_surface_t* other, int content, int width, int height);
KMETHOD CairoSurface_createSimilar(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* other = PKGRawPtr_to(cairo_surface_t*, 0);
    cairo_content_t content = PKGInt_to(cairo_content_t, 1);
    int width = PKGInt_to(int, 2);
    int height = PKGInt_to(int, 3);

    cairo_surface_t* ret = cairo_surface_create_similar(other, content, width, height);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native CairoSurFace Cairo.surface_create_for_rectangle(cairo_surface_t* target, double x, double y, double width, double height);
KMETHOD CairoSurface_createForRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* target = PKGRawPtr_to(cairo_surface_t*, 0);
    double x = PKGFloat_to(double, 1);
    double y = PKGFloat_to(double, 2);
    double width = PKGFloat_to(double, 3);
    double height = PKGFloat_to(double, 4);

    cairo_surface_t* ret = cairo_surface_create_for_rectangle(target, x, y, width, height);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native CairoSurFace Cairo.surface_reference(CairoSurface surface);
KMETHOD CairoSurface_reference(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_t* ret = cairo_surface_reference(surface);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native void Cairo.surface_finish(CairoSurface surface);
KMETHOD CairoSurface_finish(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_finish(surface);
    RETURNvoid_();
}

//## @Native cairo_device_t* Cairo.surface_get_device(CairoSurface surface);
KMETHOD CairoSurface_getDevice(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_device_t* ret = cairo_surface_get_device(surface);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_device_free);
    RETURN_(p);
}

////## @Native int Cairo.surface_get_reference_count(CairoSurface surface);
//KMETHOD CairoSurface_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
//
//    int ret = cairo_surface_get_reference_count(surface);
//    RETURNi_(ret);
//}

//## @Native cairo_status_t Cairo.surface_status(CairoSurface surface);
KMETHOD CairoSurface_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_status_t ret = cairo_surface_status(surface);
    RETURNi_(ret);
}

//## @Native cairo_surface_type_t Cairo.surface_get_type(CairoSurface surface);
KMETHOD CairoSurface_getType(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_type_t ret = cairo_surface_get_type(surface);
    RETURNi_(ret);
}

//## @Native int Cairo.surface_get_content(CairoSurface surface);
KMETHOD CairoSurface_getContent(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_content_t ret = cairo_surface_get_content(surface);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.surface_write_to_png(CairoSurface surface, char* filename);
KMETHOD CairoSurface_writeToPng(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    char* filename = PKGString_to(char*, 1);

    cairo_status_t ret = cairo_surface_write_to_png(surface, filename);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.surface_write_to_png_stream(CairoSurface surface, cairo_write_func_t write_func, void* closure);
KMETHOD CairoSurface_writeToPngStream(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    cairo_write_func_t write_func = PKGRawPtr_to(cairo_write_func_t, 1);
    void* closure = PKGRawPtr_to(void*, 2);

    KNH_TODO("");
    cairo_status_t ret = cairo_surface_write_to_png_stream(surface, write_func, closure);
    RETURNi_(ret);
}

//## @Native void* Cairo.surface_get_user_data(CairoSurface surface, cairo_user_data_key_t* key);
KMETHOD CairoSurface_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_surface_get_user_data(surface, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.surface_set_user_data(CairoSurface surface, cairo_user_data_key_t* key, void* user_data, cairo_destroy_func_t destroy);
KMETHOD CairoSurface_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);
    KNH_TODO("");

    cairo_status_t ret = cairo_surface_set_user_data(surface, key, user_data, destroy);
    RETURNi_(ret);
}

//## @Native void Cairo.surface_get_mime_data(CairoSurface surface, char* mime_type, char** data, long* length);
KMETHOD CairoSurface_getMimeData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    const char* mime_type = PKGString_to(const char*, 1);
    const unsigned char** data = PKGRawPtr_to(const unsigned char**, 2);
    unsigned long* length = PKGRawPtr_to(unsigned long*, 3);
    KNH_TODO("");

    cairo_surface_get_mime_data(surface, mime_type, data, length);
    RETURNvoid_();
}

//## @Native cairo_status_t Cairo.surface_set_mime_data(CairoSurface surface, char* mime_type, char* data, long length, cairo_destroy_func_t destroy, void* closure);
KMETHOD CairoSurface_setMimeData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    const char* mime_type = PKGString_to(char*, 1);
    const unsigned char* data = PKGString_to(const unsigned char*, 2);
    long length = PKGInt_to(long, 3);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 4);
    void* closure = PKGRawPtr_to(void*, 5);
    KNH_TODO("");

    cairo_status_t ret = cairo_surface_set_mime_data(surface, mime_type, data, length, destroy, closure);
    RETURNi_(ret);
}

//## @Native void Cairo.surface_get_font_options(CairoSurface surface, cairo_font_options_t* options);
KMETHOD CairoSurface_getFontOptions(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    cairo_font_options_t* options = PKGRawPtr_to(cairo_font_options_t*, 1);

    cairo_surface_get_font_options(surface, options);
    RETURNvoid_();
}

//## @Native void Cairo.surface_flush(CairoSurface surface);
KMETHOD CairoSurface_flush(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_flush(surface);
    RETURNvoid_();
}

//## @Native void Cairo.surface_mark_dirty(CairoSurface surface);
KMETHOD CairoSurface_markDirty(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_mark_dirty(surface);
    RETURNvoid_();
}

//## @Native void Cairo.surface_mark_dirty_rectangle(CairoSurface surface, int x, int y, int width, int height);
KMETHOD CairoSurface_markDirtyRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);
    int width = PKGInt_to(int, 3);
    int height = PKGInt_to(int, 4);

    cairo_surface_mark_dirty_rectangle(surface, x, y, width, height);
    RETURNvoid_();
}

//## @Native void Cairo.surface_set_device_offset(CairoSurface surface, double x_offset, double y_offset);
KMETHOD CairoSurface_setDeviceOffset(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    double x_offset = PKGFloat_to(double, 1);
    double y_offset = PKGFloat_to(double, 2);

    cairo_surface_set_device_offset(surface, x_offset, y_offset);
    RETURNvoid_();
}

//## @Native void Cairo.surface_get_device_offset(CairoSurface surface, double* x_offset, double* y_offset);
KMETHOD CairoSurface_getDeviceOffset(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    double* x_offset = PKGFArray_to(double*, 1);
    double* y_offset = PKGFArray_to(double*, 2);

    cairo_surface_get_device_offset(surface, x_offset, y_offset);
    RETURNvoid_();
}

//## @Native void Cairo.surface_set_fallback_resolution(CairoSurface surface, double x_pixels_per_inch, double y_pixels_per_inch);
KMETHOD CairoSurface_setFallbackResolution(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    double x_pixels_per_inch = PKGFloat_to(double, 1);
    double y_pixels_per_inch = PKGFloat_to(double, 2);

    cairo_surface_set_fallback_resolution(surface, x_pixels_per_inch, y_pixels_per_inch);
    RETURNvoid_();
}

//## @Native void Cairo.surface_get_fallback_resolution(CairoSurface surface, double* x_pixels_per_inch, double* y_pixels_per_inch);
KMETHOD CairoSurface_getFallbackResolution(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    double* x_pixels_per_inch = PKGFArray_to(double*, 1);
    double* y_pixels_per_inch = PKGFArray_to(double*, 2);

    cairo_surface_get_fallback_resolution(surface, x_pixels_per_inch, y_pixels_per_inch);
    RETURNvoid_();
}

//## @Native void Cairo.surface_copy_page(CairoSurface surface);
KMETHOD CairoSurface_copyPage(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_copy_page(surface);
    RETURNvoid_();
}

//## @Native void Cairo.surface_show_page(CairoSurface surface);
KMETHOD CairoSurface_showPage(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_surface_show_page(surface);
    RETURNvoid_();
}

//## @Native cairo_bool_t Cairo.surface_has_show_text_glyphs(CairoSurface surface);
KMETHOD CairoSurface_hasShowTextGlyphs(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_bool_t ret = cairo_surface_has_show_text_glyphs(surface);
    RETURNb_(ret);
}

//## @Native CairoSurFace Cairo.image_surface_create(cairo_format_t format, int width, int height);
KMETHOD CairoImageSurface_new(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_format_t format = PKGInt_to(cairo_format_t, 1);
    int width = PKGInt_to(int, 2);
    int height = PKGInt_to(int, 3);

    cairo_surface_t* ret = cairo_image_surface_create(format, width, height);

    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native int Cairo.format_stride_for_width(cairo_format_t format, int width);
KMETHOD Cairo_formatStrideForWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_format_t format = PKGInt_to(cairo_format_t, 0);
    int width = PKGInt_to(int, 1);

    int ret = cairo_format_stride_for_width(format, width);
    RETURNi_(ret);
}

//## @Native CairoSurFace Cairo.image_surface_create_for_data(char* data, cairo_format_t format, int width, int height, int stride);
KMETHOD CairoImageSurface_createForData(CTX ctx, ksfp_t *sfp _RIX)
{
    unsigned char* data = PKGString_to(unsigned char*, 0);
    cairo_format_t format = PKGInt_to(cairo_format_t, 1);
    int width = PKGInt_to(int, 2);
    int height = PKGInt_to(int, 3);
    int stride = PKGInt_to(int, 4);

    cairo_surface_t* ret = cairo_image_surface_create_for_data(data, format, width, height, stride);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native char* Cairo.image_surface_get_data(CairoSurface surface);
KMETHOD CairoImageSurface_getData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    unsigned char* ret = cairo_image_surface_get_data(surface);
    kString *s = new_String(ctx, (char*)ret);
    RETURN_(s);
}

//## @Native cairo_format_t Cairo.image_surface_get_format(CairoSurface surface);
KMETHOD CairoImageSurface_getFormat(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_format_t ret = cairo_image_surface_get_format(surface);
    RETURNi_(ret);
}

//## @Native int Cairo.image_surface_get_width(CairoSurface surface);
KMETHOD CairoImageSurface_getWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    int ret = cairo_image_surface_get_width(surface);
    RETURNi_(ret);
}

//## @Native int Cairo.image_surface_get_height(CairoSurface surface);
KMETHOD CairoImageSurface_getHeight(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    int ret = cairo_image_surface_get_height(surface);
    RETURNi_(ret);
}

//## @Native int Cairo.image_surface_get_stride(CairoSurface surface);
KMETHOD CairoImageSurface_getStride(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    int ret = cairo_image_surface_get_stride(surface);
    RETURNi_(ret);
}

//## @Native CairoSurFace Cairo.image_surface_create_from_png(char* filename);
KMETHOD CairoImageSurface_createFromPng(CTX ctx, ksfp_t *sfp _RIX)
{
    char* filename = PKGString_to(char*, 0);

    cairo_surface_t* ret = cairo_image_surface_create_from_png(filename);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native CairoSurFace Cairo.image_surface_create_from_png_stream(cairo_read_func_t read_func, void* closure);
KMETHOD CairoImageSurface_createFromPngStream(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_read_func_t read_func = PKGRawPtr_to(cairo_read_func_t, 0);
    void* closure = PKGRawPtr_to(void*, 1);
    KNH_TODO("");

    cairo_surface_t* ret = cairo_image_surface_create_from_png_stream(read_func, closure);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native CairoSurFace Cairo.recording_surface_create(int content, cairo_rectangle_t* extents);
KMETHOD Cairo_recordingSurfaceCreate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_content_t content = PKGInt_to(cairo_content_t, 0);
    cairo_rectangle_t* extents = PKGRawPtr_to(cairo_rectangle_t*, 1);

    cairo_surface_t* ret = cairo_recording_surface_create(content, extents);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_surface_free);
    RETURN_(p);
}

//## @Native void Cairo.recording_surface_ink_extents(CairoSurface surface, double* x0, double* y0, double* width, double* height);
KMETHOD Cairo_recordingSurfaceInkExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);
    double* x0 = PKGFArray_to(double*, 1);
    double* y0 = PKGFArray_to(double*, 2);
    double* width = PKGFArray_to(double*, 3);
    double* height = PKGFArray_to(double*, 4);

    cairo_recording_surface_ink_extents(surface, x0, y0, width, height);
    RETURNvoid_();
}

//## @Native cairo_pattern_t* Cairo.pattern_create_rgb(double red, double green, double blue);
KMETHOD CairoPattern_createRgb(CTX ctx, ksfp_t *sfp _RIX)
{
    double red = PKGFloat_to(double, 0);
    double green = PKGFloat_to(double, 1);
    double blue = PKGFloat_to(double, 2);

    cairo_pattern_t* ret = cairo_pattern_create_rgb(red, green, blue);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native cairo_pattern_t* Cairo.pattern_create_rgba(double red, double green, double blue, double alpha);
KMETHOD CairoPattern_createRgba(CTX ctx, ksfp_t *sfp _RIX)
{
    double red = PKGFloat_to(double, 0);
    double green = PKGFloat_to(double, 1);
    double blue = PKGFloat_to(double, 2);
    double alpha = PKGFloat_to(double, 3);

    cairo_pattern_t* ret = cairo_pattern_create_rgba(red, green, blue, alpha);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native cairo_pattern_t* Cairo.pattern_create_for_surface(CairoSurface surface);
KMETHOD CairoPattern_createForSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_surface_t* surface = PKGRawPtr_to(cairo_surface_t*, 0);

    cairo_pattern_t* ret = cairo_pattern_create_for_surface(surface);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native cairo_pattern_t* Cairo.pattern_create_linear(double x0, double y0, double x1, double y1);
KMETHOD CairoPattern_createLinear(CTX ctx, ksfp_t *sfp _RIX)
{
    double x0 = PKGFloat_to(double, 0);
    double y0 = PKGFloat_to(double, 1);
    double x1 = PKGFloat_to(double, 2);
    double y1 = PKGFloat_to(double, 3);

    cairo_pattern_t* ret = cairo_pattern_create_linear(x0, y0, x1, y1);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

//## @Native cairo_pattern_t* Cairo.pattern_create_radial(double cx0, double cy0, double radius0, double cx1, double cy1, double radius1);
KMETHOD CairoPattern_createRadial(CTX ctx, ksfp_t *sfp _RIX)
{
    double cx0 = PKGFloat_to(double, 0);
    double cy0 = PKGFloat_to(double, 1);
    double radius0 = PKGFloat_to(double, 2);
    double cx1 = PKGFloat_to(double, 3);
    double cy1 = PKGFloat_to(double, 4);
    double radius1 = PKGFloat_to(double, 5);

    cairo_pattern_t* ret = cairo_pattern_create_radial(cx0, cy0, radius0, cx1, cy1, radius1);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
    RETURN_(p);
}

////## @Native cairo_pattern_t* Cairo.pattern_reference(cairo_pattern_t* pattern);
//KMETHOD CairoPattern_reference(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
//
//    cairo_pattern_t* ret = cairo_pattern_reference(pattern);
//    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_pattern_free);
//    RETURN_(p);
//}
//
////## @Native int Cairo.pattern_get_reference_count(cairo_pattern_t* pattern);
//KMETHOD CairoPattern_getReferenceCount(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
//
//    int ret = cairo_pattern_get_reference_count(pattern);
//    RETURNi_(ret);
//}

//## @Native cairo_status_t Cairo.pattern_status(cairo_pattern_t* pattern);
KMETHOD CairoPattern_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);

    cairo_status_t ret = cairo_pattern_status(pattern);
    RETURNi_(ret);
}

//## @Native void* Cairo.pattern_get_user_data(cairo_pattern_t* pattern, cairo_user_data_key_t* key);
KMETHOD CairoPattern_getUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);

    void* ret = cairo_pattern_get_user_data(pattern, key);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_free);
    RETURN_(p);
}

//## @Native cairo_status_t Cairo.pattern_set_user_data(cairo_pattern_t* pattern, cairo_user_data_key_t* key, void* user_data, cairo_destroy_func_t destroy);
KMETHOD CairoPattern_setUserData(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_user_data_key_t* key = PKGRawPtr_to(cairo_user_data_key_t*, 1);
    void* user_data = PKGRawPtr_to(void*, 2);
    cairo_destroy_func_t destroy = PKGRawPtr_to(cairo_destroy_func_t, 3);
    KNH_TODO("");

    cairo_status_t ret = cairo_pattern_set_user_data(pattern, key, user_data, destroy);
    RETURNi_(ret);
}

//## @Native cairo_pattern_type_t Cairo.pattern_get_type(cairo_pattern_t* pattern);
KMETHOD CairoPattern_getType(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);

    cairo_pattern_type_t ret = cairo_pattern_get_type(pattern);
    RETURNi_(ret);
}

//## @Native void Cairo.pattern_add_color_stop_rgb(cairo_pattern_t* pattern, double offset, double red, double green, double blue);
KMETHOD CairoPattern_addColorStopRgb(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    double offset = PKGFloat_to(double, 1);
    double red = PKGFloat_to(double, 2);
    double green = PKGFloat_to(double, 3);
    double blue = PKGFloat_to(double, 4);

    cairo_pattern_add_color_stop_rgb(pattern, offset, red, green, blue);
    RETURNvoid_();
}

//## @Native void Cairo.pattern_add_color_stop_rgba(cairo_pattern_t* pattern, double offset, double red, double green, double blue, double alpha);
KMETHOD CairoPattern_addColorStopRgba(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    double offset = PKGFloat_to(double, 1);
    double red = PKGFloat_to(double, 2);
    double green = PKGFloat_to(double, 3);
    double blue = PKGFloat_to(double, 4);
    double alpha = PKGFloat_to(double, 5);

    cairo_pattern_add_color_stop_rgba(pattern, offset, red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void Cairo.pattern_set_matrix(cairo_pattern_t* pattern, cairo_matrix_t* matrix);
KMETHOD CairoPattern_setMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    cairo_pattern_set_matrix(pattern, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.pattern_get_matrix(cairo_pattern_t* pattern, cairo_matrix_t* matrix);
KMETHOD CairoPattern_getMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 1);

    KNH_TODO("");
    cairo_pattern_get_matrix(pattern, matrix);
    RETURNvoid_();
}

//## @Native void Cairo.pattern_set_extend(cairo_pattern_t* pattern, cairo_extend_t extend);
KMETHOD CairoPattern_setExtend(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_extend_t extend = PKGInt_to(cairo_extend_t, 1);

    cairo_pattern_set_extend(pattern, extend);
    RETURNvoid_();
}

//## @Native cairo_extend_t Cairo.pattern_get_extend(cairo_pattern_t* pattern);
KMETHOD CairoPattern_getExtend(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);

    cairo_extend_t ret = cairo_pattern_get_extend(pattern);
    RETURNi_(ret);
}

//## @Native void Cairo.pattern_set_filter(cairo_pattern_t* pattern, cairo_filter_t filter);
KMETHOD CairoPattern_setFilter(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_filter_t filter = PKGInt_to(cairo_filter_t, 1);

    cairo_pattern_set_filter(pattern, filter);
    RETURNvoid_();
}

//## @Native cairo_filter_t Cairo.pattern_get_filter(cairo_pattern_t* pattern);
KMETHOD CairoPattern_getFilter(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);

    cairo_filter_t ret = cairo_pattern_get_filter(pattern);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_rgba(cairo_pattern_t* pattern, double* red, double* green, double* blue, double* alpha);
KMETHOD CairoPattern_getRgba(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    double* red = PKGFArray_to(double*, 1);
    double* green = PKGFArray_to(double*, 2);
    double* blue = PKGFArray_to(double*, 3);
    double* alpha = PKGFArray_to(double*, 4);

    cairo_status_t ret = cairo_pattern_get_rgba(pattern, red, green, blue, alpha);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_surface(cairo_pattern_t* pattern, cairo_surface_t** surface);
KMETHOD CairoPattern_getSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    cairo_surface_t** surface = PKGRawPtr_to(cairo_surface_t**, 1);
    KNH_TODO("");

    cairo_status_t ret = cairo_pattern_get_surface(pattern, surface);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_color_stop_rgba(cairo_pattern_t* pattern, int index, double* offset, double* red, double* green, double* blue, double* alpha);
KMETHOD CairoPattern_getColorStopRgba(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    int index = PKGInt_to(int, 1);
    double* offset = PKGFArray_to(double*, 2);
    double* red = PKGFArray_to(double*, 3);
    double* green = PKGFArray_to(double*, 4);
    double* blue = PKGFArray_to(double*, 5);
    double* alpha = PKGFArray_to(double*, 6);

    cairo_status_t ret = cairo_pattern_get_color_stop_rgba(pattern, index, offset, red, green, blue, alpha);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_color_stop_count(cairo_pattern_t* pattern, int* count);
KMETHOD CairoPattern_getColorStopCount(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    int* count = PKGIArray_to(int*, 1);

    cairo_status_t ret = cairo_pattern_get_color_stop_count(pattern, count);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_linear_points(cairo_pattern_t* pattern, double* x0, double* y0, double* x1, double* y1);
KMETHOD CairoPattern_getLinearPoints(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    double* x0 = PKGFArray_to(double*, 1);
    double* y0 = PKGFArray_to(double*, 2);
    double* x1 = PKGFArray_to(double*, 3);
    double* y1 = PKGFArray_to(double*, 4);

    cairo_status_t ret = cairo_pattern_get_linear_points(pattern, x0, y0, x1, y1);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.pattern_get_radial_circles(cairo_pattern_t* pattern, double* x0, double* y0, double* r0, double* x1, double* y1, double* r1);
KMETHOD CairoPattern_getRadialCircles(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_pattern_t* pattern = PKGRawPtr_to(cairo_pattern_t*, 0);
    double* x0 = PKGFArray_to(double*, 1);
    double* y0 = PKGFArray_to(double*, 2);
    double* r0 = PKGFArray_to(double*, 3);
    double* x1 = PKGFArray_to(double*, 4);
    double* y1 = PKGFArray_to(double*, 5);
    double* r1 = PKGFArray_to(double*, 6);

    cairo_status_t ret = cairo_pattern_get_radial_circles(pattern, x0, y0, r0, x1, y1, r1);
    RETURNi_(ret);
}

//## @Native void Cairo.matrix_init(cairo_matrix_t* matrix, double xx, double yx, double xy, double yy, double x0, double y0);
KMETHOD CairoMatrix_init(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double xx = PKGFloat_to(double, 1);
    double yx = PKGFloat_to(double, 2);
    double xy = PKGFloat_to(double, 3);
    double yy = PKGFloat_to(double, 4);
    double x0 = PKGFloat_to(double, 5);
    double y0 = PKGFloat_to(double, 6);

    cairo_matrix_init(matrix, xx, yx, xy, yy, x0, y0);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_init_identity(cairo_matrix_t* matrix);
KMETHOD CairoMatrix_initIdentity(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);

    cairo_matrix_init_identity(matrix);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_init_translate(cairo_matrix_t* matrix, double tx, double ty);
KMETHOD CairoMatrix_initTranslate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double tx = PKGFloat_to(double, 1);
    double ty = PKGFloat_to(double, 2);

    cairo_matrix_init_translate(matrix, tx, ty);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_init_scale(cairo_matrix_t* matrix, double sx, double sy);
KMETHOD CairoMatrix_initScale(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double sx = PKGFloat_to(double, 1);
    double sy = PKGFloat_to(double, 2);

    cairo_matrix_init_scale(matrix, sx, sy);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_init_rotate(cairo_matrix_t* matrix, double radians);
KMETHOD CairoMatrix_initRotate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double radians = PKGFloat_to(double, 1);

    cairo_matrix_init_rotate(matrix, radians);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_translate(cairo_matrix_t* matrix, double tx, double ty);
KMETHOD CairoMatrix_translate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double tx = PKGFloat_to(double, 1);
    double ty = PKGFloat_to(double, 2);

    cairo_matrix_translate(matrix, tx, ty);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_scale(cairo_matrix_t* matrix, double sx, double sy);
KMETHOD CairoMatrix_scale(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double sx = PKGFloat_to(double, 1);
    double sy = PKGFloat_to(double, 2);

    cairo_matrix_scale(matrix, sx, sy);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_rotate(cairo_matrix_t* matrix, double radians);
KMETHOD CairoMatrix_rotate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double radians = PKGFloat_to(double, 1);

    cairo_matrix_rotate(matrix, radians);
    RETURNvoid_();
}

//## @Native cairo_status_t Cairo.matrix_invert(cairo_matrix_t* matrix);
KMETHOD CairoMatrix_invert(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);

    cairo_status_t ret = cairo_matrix_invert(matrix);
    RETURNi_(ret);
}

//## @Native void Cairo.matrix_multiply(cairo_matrix_t* result, cairo_matrix_t* a, cairo_matrix_t* b);
KMETHOD CairoMatrix_multiply(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* result = PKGRawPtr_to(cairo_matrix_t*, 0);
    cairo_matrix_t* a = PKGRawPtr_to(cairo_matrix_t*, 1);
    cairo_matrix_t* b = PKGRawPtr_to(cairo_matrix_t*, 2);

    cairo_matrix_multiply(result, a, b);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_transform_distance(cairo_matrix_t* matrix, double* dx, double* dy);
KMETHOD CairoMatrix_transformDistance(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double* dx = PKGFArray_to(double*, 1);
    double* dy = PKGFArray_to(double*, 2);

    cairo_matrix_transform_distance(matrix, dx, dy);
    RETURNvoid_();
}

//## @Native void Cairo.matrix_transform_point(cairo_matrix_t* matrix, double* x, double* y);
KMETHOD CairoMatrix_transformPoint(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_matrix_t* matrix = PKGRawPtr_to(cairo_matrix_t*, 0);
    double* x = PKGFArray_to(double*, 1);
    double* y = PKGFArray_to(double*, 2);

    cairo_matrix_transform_point(matrix, x, y);
    RETURNvoid_();
}

static void my_cairo_region_free(void *p)
{
    cairo_region_t* region = (cairo_region_t*) p;
    cairo_region_destroy(region);
}
//## @Native cairo_region_t* Cairo.region_create();
KMETHOD CairoRegion_new(CTX ctx, ksfp_t *sfp _RIX)
{

    cairo_region_t* ret = cairo_region_create();
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_region_free);
    RETURN_(p);
}

//## @Native cairo_region_t* Cairo.region_create_rectangle(cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_createRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 0);

    cairo_region_t* ret = cairo_region_create_rectangle(rectangle);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_region_free);
    RETURN_(p);
}

//## @Native cairo_region_t* Cairo.region_create_rectangles(cairo_rectangle_int_t* rects, int count);
KMETHOD CairoRegion_createRectangles(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_rectangle_int_t* rects = PKGRawPtr_to(cairo_rectangle_int_t*, 0);
    int count = PKGInt_to(int, 1);

    cairo_region_t* ret = cairo_region_create_rectangles(rects, count);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_region_free);
    RETURN_(p);
}

//## @Native cairo_region_t* Cairo.region_copy(cairo_region_t* original);
KMETHOD CairoRegion_copy(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* original = PKGRawPtr_to(cairo_region_t*, 1);

    cairo_region_t* ret = cairo_region_copy(original);
    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_region_free);
    RETURN_(p);
}

////## @Native cairo_region_t* Cairo.region_reference(cairo_region_t* region);
//KMETHOD CairoRegion_reference(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
//
//    cairo_region_t* ret = cairo_region_reference(region);
//    kRawPtr *p = new_ReturnCppObject(ctx, sfp, WRAP(ret), my_cairo_region_free);
//    RETURN_(p);
//}

//## @Native cairo_status_t Cairo.region_status(cairo_region_t* region);
KMETHOD CairoRegion_status(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);

    cairo_status_t ret = cairo_region_status(region);
    RETURNi_(ret);
}

//## @Native void Cairo.region_get_extents(cairo_region_t* region, cairo_rectangle_int_t* extents);
KMETHOD CairoRegion_getExtents(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* extents = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_region_get_extents(region, extents);
    RETURNvoid_();
}

//## @Native int Cairo.region_num_rectangles(cairo_region_t* region);
KMETHOD CairoRegion_numRectangles(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);

    int ret = cairo_region_num_rectangles(region);
    RETURNi_(ret);
}

//## @Native void Cairo.region_get_rectangle(cairo_region_t* region, int nth, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_getRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
    int nth = PKGInt_to(int, 1);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 2);

    cairo_region_get_rectangle(region, nth, rectangle);
    RETURNvoid_();
}

//## @Native cairo_bool_t Cairo.region_is_empty(cairo_region_t* region);
KMETHOD CairoRegion_isEmpty(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);

    cairo_bool_t ret = cairo_region_is_empty(region);
    RETURNb_(ret);
}

//## @Native cairo_region_overlap_t Cairo.region_contains_rectangle(cairo_region_t* region, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_containsRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_region_overlap_t ret = cairo_region_contains_rectangle(region, rectangle);
    RETURNi_(ret);
}

//## @Native cairo_bool_t Cairo.region_contains_point(cairo_region_t* region, int x, int y);
KMETHOD CairoRegion_containsPoint(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);

    cairo_bool_t ret = cairo_region_contains_point(region, x, y);
    RETURNb_(ret);
}

//## @Native void Cairo.region_translate(cairo_region_t* region, int dx, int dy);
KMETHOD CairoRegion_translate(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* region = PKGRawPtr_to(cairo_region_t*, 0);
    int dx = PKGInt_to(int, 1);
    int dy = PKGInt_to(int, 2);

    cairo_region_translate(region, dx, dy);
    RETURNvoid_();
}

//## @Native cairo_status_t Cairo.region_subtract(cairo_region_t* dst, cairo_region_t* other);
KMETHOD CairoRegion_subtract(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_region_t* other = PKGRawPtr_to(cairo_region_t*, 1);

    cairo_status_t ret = cairo_region_subtract(dst, other);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_subtract_rectangle(cairo_region_t* dst, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_subtractRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_status_t ret = cairo_region_subtract_rectangle(dst, rectangle);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_intersect(cairo_region_t* dst, cairo_region_t* other);
KMETHOD CairoRegion_intersect(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_region_t* other = PKGRawPtr_to(cairo_region_t*, 1);

    cairo_status_t ret = cairo_region_intersect(dst, other);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_intersect_rectangle(cairo_region_t* dst, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_intersectRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_status_t ret = cairo_region_intersect_rectangle(dst, rectangle);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_union(cairo_region_t* dst, cairo_region_t* other);
KMETHOD CairoRegion_union(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_region_t* other = PKGRawPtr_to(cairo_region_t*, 1);

    cairo_status_t ret = cairo_region_union(dst, other);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_union_rectangle(cairo_region_t* dst, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_unionRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_status_t ret = cairo_region_union_rectangle(dst, rectangle);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_xor(cairo_region_t* dst, cairo_region_t* other);
KMETHOD CairoRegion_xor(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_region_t* other = PKGRawPtr_to(cairo_region_t*, 1);

    cairo_status_t ret = cairo_region_xor(dst, other);
    RETURNi_(ret);
}

//## @Native cairo_status_t Cairo.region_xor_rectangle(cairo_region_t* dst, cairo_rectangle_int_t* rectangle);
KMETHOD CairoRegion_xorRectangle(CTX ctx, ksfp_t *sfp _RIX)
{
    cairo_region_t* dst = PKGRawPtr_to(cairo_region_t*, 0);
    cairo_rectangle_int_t* rectangle = PKGRawPtr_to(cairo_rectangle_int_t*, 1);

    cairo_status_t ret = cairo_region_xor_rectangle(dst, rectangle);
    RETURNi_(ret);
}

////## @Native void Cairo.debug_reset_static_data();
//KMETHOD Cairo_debug_reset_static_data(CTX ctx, ksfp_t *sfp _RIX)
//{
//    cairo_debug_reset_static_data();
//    RETURNvoid_();
//}

#ifdef __cplusplus
}
#endif

