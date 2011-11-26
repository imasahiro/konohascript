/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
 *
 * All rights reserved.
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <konoha1.h>
#include "pkg_typerules.h"

#ifdef __cplusplus
extern "C" {
#endif

//## @Native void GL.glActiveTextureARB(GLenum texture);
KMETHOD GL_glActiveTextureARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum texture = PKGInt_to(GLenum, 1);

    glActiveTextureARB(texture);
    RETURNvoid_();
}

//## @Native void GL.glClientActiveTextureARB(GLenum texture);
KMETHOD GL_glClientActiveTextureARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum texture = PKGInt_to(GLenum, 1);

    glClientActiveTextureARB(texture);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1dARB(GLenum target, GLdouble s);
KMETHOD GL_glMultiTexCoord1dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);

    glMultiTexCoord1dARB(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1dvARB(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord1dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord1dvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1fARB(GLenum target, GLfloat s);
KMETHOD GL_glMultiTexCoord1fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);

    glMultiTexCoord1fARB(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1fvARB(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord1fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord1fvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1iARB(GLenum target, GLint s);
KMETHOD GL_glMultiTexCoord1iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);

    glMultiTexCoord1iARB(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1ivARB(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord1ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord1ivARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1sARB(GLenum target, GLshort s);
KMETHOD GL_glMultiTexCoord1sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);

    glMultiTexCoord1sARB(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1svARB(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord1svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord1svARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
KMETHOD GL_glMultiTexCoord2dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);

    glMultiTexCoord2dARB(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2dvARB(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord2dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord2dvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
KMETHOD GL_glMultiTexCoord2fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);

    glMultiTexCoord2fARB(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2fvARB(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord2fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord2fvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
KMETHOD GL_glMultiTexCoord2iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);

    glMultiTexCoord2iARB(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2ivARB(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord2ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord2ivARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
KMETHOD GL_glMultiTexCoord2sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);

    glMultiTexCoord2sARB(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2svARB(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord2svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord2svARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
KMETHOD GL_glMultiTexCoord3dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);
    GLdouble r = PKGFloat_to(GLdouble, 4);

    glMultiTexCoord3dARB(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3dvARB(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord3dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord3dvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
KMETHOD GL_glMultiTexCoord3fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);
    GLfloat r = PKGFloat_to(GLfloat, 4);

    glMultiTexCoord3fARB(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3fvARB(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord3fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord3fvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
KMETHOD GL_glMultiTexCoord3iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);
    GLint r = PKGInt_to(GLint, 4);

    glMultiTexCoord3iARB(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3ivARB(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord3ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord3ivARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
KMETHOD GL_glMultiTexCoord3sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);
    GLshort r = PKGInt_to(GLshort, 4);

    glMultiTexCoord3sARB(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3svARB(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord3svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord3svARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
KMETHOD GL_glMultiTexCoord4dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);
    GLdouble r = PKGFloat_to(GLdouble, 4);
    GLdouble q = PKGFloat_to(GLdouble, 5);

    glMultiTexCoord4dARB(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4dvARB(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord4dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord4dvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
KMETHOD GL_glMultiTexCoord4fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);
    GLfloat r = PKGFloat_to(GLfloat, 4);
    GLfloat q = PKGFloat_to(GLfloat, 5);

    glMultiTexCoord4fARB(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4fvARB(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord4fvARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
KMETHOD GL_glMultiTexCoord4iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);
    GLint r = PKGInt_to(GLint, 4);
    GLint q = PKGInt_to(GLint, 5);

    glMultiTexCoord4iARB(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4ivARB(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord4ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord4ivARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
KMETHOD GL_glMultiTexCoord4sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);
    GLshort r = PKGInt_to(GLshort, 4);
    GLshort q = PKGInt_to(GLshort, 5);

    glMultiTexCoord4sARB(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4svARB(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord4svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord4svARB(target, v);
    RETURNvoid_();
}

//## @Native void GL.glLoadTransposeMatrixfARB(GLfloat* m);
KMETHOD GL_glLoadTransposeMatrixfARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glLoadTransposeMatrixfARB(m);
    RETURNvoid_();
}

//## @Native void GL.glLoadTransposeMatrixdARB(GLdouble* m);
KMETHOD GL_glLoadTransposeMatrixdARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glLoadTransposeMatrixdARB(m);
    RETURNvoid_();
}

//## @Native void GL.glMultTransposeMatrixfARB(GLfloat* m);
KMETHOD GL_glMultTransposeMatrixfARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glMultTransposeMatrixfARB(m);
    RETURNvoid_();
}

//## @Native void GL.glMultTransposeMatrixdARB(GLdouble* m);
KMETHOD GL_glMultTransposeMatrixdARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glMultTransposeMatrixdARB(m);
    RETURNvoid_();
}

//## @Native void GL.glSampleCoverageARB(GLclampf value, GLboolean invert);
KMETHOD GL_glSampleCoverageARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampf value = PKGFloat_to(GLclampf, 1);
    GLboolean invert = PKGInt_to(GLboolean, 2);

    glSampleCoverageARB(value, invert);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage3DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLsizei depth = PKGInt_to(GLsizei, 6);
    GLint border = PKGInt_to(GLint, 7);
    GLsizei imageSize = PKGInt_to(GLsizei, 8);
    GLvoid* data = PKG_Error_to(GLvoid*, 9);

    glCompressedTexImage3DARB(target, level, internalformat, width, height, depth, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage2DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLint border = PKGInt_to(GLint, 6);
    GLsizei imageSize = PKGInt_to(GLsizei, 7);
    GLvoid* data = PKG_Error_to(GLvoid*, 8);

    glCompressedTexImage2DARB(target, level, internalformat, width, height, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage1DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLint border = PKGInt_to(GLint, 5);
    GLsizei imageSize = PKGInt_to(GLsizei, 6);
    GLvoid* data = PKG_Error_to(GLvoid*, 7);

    glCompressedTexImage1DARB(target, level, internalformat, width, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage3DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLint zoffset = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);
    GLsizei height = PKGInt_to(GLsizei, 7);
    GLsizei depth = PKGInt_to(GLsizei, 8);
    GLenum format = PKGInt_to(GLenum, 9);
    GLsizei imageSize = PKGInt_to(GLsizei, 10);
    GLvoid* data = PKG_Error_to(GLvoid*, 11);

    glCompressedTexSubImage3DARB(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage2DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);
    GLsizei height = PKGInt_to(GLsizei, 6);
    GLenum format = PKGInt_to(GLenum, 7);
    GLsizei imageSize = PKGInt_to(GLsizei, 8);
    GLvoid* data = PKG_Error_to(GLvoid*, 9);

    glCompressedTexSubImage2DARB(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage1DARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLsizei imageSize = PKGInt_to(GLsizei, 6);
    GLvoid* data = PKG_Error_to(GLvoid*, 7);

    glCompressedTexSubImage1DARB(target, level, xoffset, width, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid* data);
KMETHOD GL_glGetCompressedTexImageARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLvoid* data = PKG_Error_to(GLvoid*, 3);

    glGetCompressedTexImageARB(target, level, data);
    RETURNvoid_();
}

//## @Native void GL.glWeightbvARB(GLint size, GLbyte* weights);
KMETHOD GL_glWeightbvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLbyte* weights = PKG_Error_to(GLbyte*, 2);

    glWeightbvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightsvARB(GLint size, GLshort* weights);
KMETHOD GL_glWeightsvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLshort* weights = PKG_Error_to(GLshort*, 2);

    glWeightsvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightivARB(GLint size, GLint* weights);
KMETHOD GL_glWeightivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLint* weights = PKG_Error_to(GLint*, 2);

    glWeightivARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightfvARB(GLint size, GLfloat* weights);
KMETHOD GL_glWeightfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLfloat* weights = PKG_Error_to(GLfloat*, 2);

    glWeightfvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightdvARB(GLint size, GLdouble* weights);
KMETHOD GL_glWeightdvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLdouble* weights = PKG_Error_to(GLdouble*, 2);

    glWeightdvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightubvARB(GLint size, GLubyte* weights);
KMETHOD GL_glWeightubvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLubyte* weights = PKG_Error_to(GLubyte*, 2);

    glWeightubvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightusvARB(GLint size, GLushort* weights);
KMETHOD GL_glWeightusvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLushort* weights = PKG_Error_to(GLushort*, 2);

    glWeightusvARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightuivARB(GLint size, GLuint* weights);
KMETHOD GL_glWeightuivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLuint* weights = PKG_Error_to(GLuint*, 2);

    glWeightuivARB(size, weights);
    RETURNvoid_();
}

//## @Native void GL.glWeightPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glWeightPointerARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glWeightPointerARB(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glVertexBlendARB(GLint count);
KMETHOD GL_glVertexBlendARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint count = PKGInt_to(GLint, 1);

    glVertexBlendARB(count);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2dARB(GLdouble x, GLdouble y);
KMETHOD GL_glWindowPos2dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);

    glWindowPos2dARB(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2dvARB(GLdouble* p);
KMETHOD GL_glWindowPos2dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* p = PKG_Error_to(GLdouble*, 1);

    glWindowPos2dvARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2fARB(GLfloat x, GLfloat y);
KMETHOD GL_glWindowPos2fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);

    glWindowPos2fARB(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2fvARB(GLfloat* p);
KMETHOD GL_glWindowPos2fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* p = PKG_Error_to(GLfloat*, 1);

    glWindowPos2fvARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2iARB(GLint x, GLint y);
KMETHOD GL_glWindowPos2iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);

    glWindowPos2iARB(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2ivARB(GLint* p);
KMETHOD GL_glWindowPos2ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* p = PKG_Error_to(GLint*, 1);

    glWindowPos2ivARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2sARB(GLshort x, GLshort y);
KMETHOD GL_glWindowPos2sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);

    glWindowPos2sARB(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2svARB(GLshort* p);
KMETHOD GL_glWindowPos2svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* p = PKG_Error_to(GLshort*, 1);

    glWindowPos2svARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glWindowPos3dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glWindowPos3dARB(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3dvARB(GLdouble* p);
KMETHOD GL_glWindowPos3dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* p = PKG_Error_to(GLdouble*, 1);

    glWindowPos3dvARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glWindowPos3fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glWindowPos3fARB(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3fvARB(GLfloat* p);
KMETHOD GL_glWindowPos3fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* p = PKG_Error_to(GLfloat*, 1);

    glWindowPos3fvARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3iARB(GLint x, GLint y, GLint z);
KMETHOD GL_glWindowPos3iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);

    glWindowPos3iARB(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3ivARB(GLint* p);
KMETHOD GL_glWindowPos3ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* p = PKG_Error_to(GLint*, 1);

    glWindowPos3ivARB(p);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
KMETHOD GL_glWindowPos3sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);

    glWindowPos3sARB(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3svARB(GLshort* p);
KMETHOD GL_glWindowPos3svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* p = PKG_Error_to(GLshort*, 1);

    glWindowPos3svARB(p);
    RETURNvoid_();
}

//## @Native void GL.glGenQueriesARB(GLsizei n, GLuint* ids);
KMETHOD GL_glGenQueriesARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glGenQueriesARB(n, ids);
    RETURNvoid_();
}

//## @Native void GL.glDeleteQueriesARB(GLsizei n, GLuint* ids);
KMETHOD GL_glDeleteQueriesARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glDeleteQueriesARB(n, ids);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsQueryARB(GLuint id);
KMETHOD GL_glIsQueryARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsQueryARB(id);
    RETURNi_(ret);
}

//## @Native void GL.glBeginQueryARB(GLenum target, GLuint id);
KMETHOD GL_glBeginQueryARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint id = PKGInt_to(GLuint, 2);

    glBeginQueryARB(target, id);
    RETURNvoid_();
}

//## @Native void GL.glEndQueryARB(GLenum target);
KMETHOD GL_glEndQueryARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glEndQueryARB(target);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryivARB(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetQueryivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetQueryivARB(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjectivARB(GLuint id, GLenum pname, GLint* params);
KMETHOD GL_glGetQueryObjectivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetQueryObjectivARB(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint* params);
KMETHOD GL_glGetQueryObjectuivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glGetQueryObjectuivARB(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glPointParameterfARB(GLenum pname, GLfloat param);
KMETHOD GL_glPointParameterfARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPointParameterfARB(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPointParameterfvARB(GLenum pname, GLfloat* params);
KMETHOD GL_glPointParameterfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat* params = PKG_Error_to(GLfloat*, 2);

    glPointParameterfvARB(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glBindProgramARB(GLenum target, GLuint program);
KMETHOD GL_glBindProgramARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint program = PKGInt_to(GLuint, 2);

    glBindProgramARB(target, program);
    RETURNvoid_();
}

//## @Native void GL.glDeleteProgramsARB(GLsizei n, GLuint* programs);
KMETHOD GL_glDeleteProgramsARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* programs = PKG_Error_to(GLuint*, 2);

    glDeleteProgramsARB(n, programs);
    RETURNvoid_();
}

//## @Native void GL.glGenProgramsARB(GLsizei n, GLuint* programs);
KMETHOD GL_glGenProgramsARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* programs = PKG_Error_to(GLuint*, 2);

    glGenProgramsARB(n, programs);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsProgramARB(GLuint program);
KMETHOD GL_glIsProgramARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsProgramARB(program);
    RETURNi_(ret);
}

//## @Native void GL.glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glProgramEnvParameter4dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble x = PKGFloat_to(GLdouble, 3);
    GLdouble y = PKGFloat_to(GLdouble, 4);
    GLdouble z = PKGFloat_to(GLdouble, 5);
    GLdouble w = PKGFloat_to(GLdouble, 6);

    glProgramEnvParameter4dARB(target, index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble* params);
KMETHOD GL_glProgramEnvParameter4dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glProgramEnvParameter4dvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glProgramEnvParameter4fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat x = PKGFloat_to(GLfloat, 3);
    GLfloat y = PKGFloat_to(GLfloat, 4);
    GLfloat z = PKGFloat_to(GLfloat, 5);
    GLfloat w = PKGFloat_to(GLfloat, 6);

    glProgramEnvParameter4fARB(target, index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat* params);
KMETHOD GL_glProgramEnvParameter4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glProgramEnvParameter4fvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glProgramLocalParameter4dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble x = PKGFloat_to(GLdouble, 3);
    GLdouble y = PKGFloat_to(GLdouble, 4);
    GLdouble z = PKGFloat_to(GLdouble, 5);
    GLdouble w = PKGFloat_to(GLdouble, 6);

    glProgramLocalParameter4dARB(target, index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble* params);
KMETHOD GL_glProgramLocalParameter4dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glProgramLocalParameter4dvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glProgramLocalParameter4fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat x = PKGFloat_to(GLfloat, 3);
    GLfloat y = PKGFloat_to(GLfloat, 4);
    GLfloat z = PKGFloat_to(GLfloat, 5);
    GLfloat w = PKGFloat_to(GLfloat, 6);

    glProgramLocalParameter4fARB(target, index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat* params);
KMETHOD GL_glProgramLocalParameter4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glProgramLocalParameter4fvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* params);
KMETHOD GL_glGetProgramEnvParameterdvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glGetProgramEnvParameterdvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* params);
KMETHOD GL_glGetProgramEnvParameterfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetProgramEnvParameterfvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat* params);
KMETHOD GL_glProgramEnvParameters4fvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);
    GLfloat* params = PKG_Error_to(GLfloat*, 4);

    glProgramEnvParameters4fvEXT(target, index, count, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat* params);
KMETHOD GL_glProgramLocalParameters4fvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);
    GLfloat* params = PKG_Error_to(GLfloat*, 4);

    glProgramLocalParameters4fvEXT(target, index, count, params);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* params);
KMETHOD GL_glGetProgramLocalParameterdvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glGetProgramLocalParameterdvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* params);
KMETHOD GL_glGetProgramLocalParameterfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetProgramLocalParameterfvARB(target, index, params);
    RETURNvoid_();
}

//## @Native void GL.glProgramStringARB(GLenum target, GLenum format, GLsizei len, GLvoid* string);
KMETHOD GL_glProgramStringARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum format = PKGInt_to(GLenum, 2);
    GLsizei len = PKGInt_to(GLsizei, 3);
    GLvoid* string = PKG_Error_to(GLvoid*, 4);

    glProgramStringARB(target, format, len, string);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramStringARB(GLenum target, GLenum pname, GLvoid* string);
KMETHOD GL_glGetProgramStringARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid* string = PKG_Error_to(GLvoid*, 3);

    glGetProgramStringARB(target, pname, string);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramivARB(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetProgramivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetProgramivARB(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1dARB(GLuint index, GLdouble x);
KMETHOD GL_glVertexAttrib1dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);

    glVertexAttrib1dARB(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1dvARB(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib1dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib1dvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1fARB(GLuint index, GLfloat x);
KMETHOD GL_glVertexAttrib1fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);

    glVertexAttrib1fARB(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1fvARB(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib1fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib1fvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1sARB(GLuint index, GLshort x);
KMETHOD GL_glVertexAttrib1sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);

    glVertexAttrib1sARB(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1svARB(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib1svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib1svARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
KMETHOD GL_glVertexAttrib2dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);

    glVertexAttrib2dARB(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2dvARB(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib2dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib2dvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
KMETHOD GL_glVertexAttrib2fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);

    glVertexAttrib2fARB(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2fvARB(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib2fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib2fvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
KMETHOD GL_glVertexAttrib2sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);

    glVertexAttrib2sARB(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2svARB(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib2svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib2svARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glVertexAttrib3dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);
    GLdouble z = PKGFloat_to(GLdouble, 4);

    glVertexAttrib3dARB(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3dvARB(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib3dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib3dvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glVertexAttrib3fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);
    GLfloat z = PKGFloat_to(GLfloat, 4);

    glVertexAttrib3fARB(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3fvARB(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib3fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib3fvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
KMETHOD GL_glVertexAttrib3sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);
    GLshort z = PKGInt_to(GLshort, 4);

    glVertexAttrib3sARB(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3svARB(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib3svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib3svARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NbvARB(GLuint index, GLbyte* v);
KMETHOD GL_glVertexAttrib4NbvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLbyte* v = PKG_Error_to(GLbyte*, 2);

    glVertexAttrib4NbvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NivARB(GLuint index, GLint* v);
KMETHOD GL_glVertexAttrib4NivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttrib4NivARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NsvARB(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib4NsvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib4NsvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
KMETHOD GL_glVertexAttrib4NubARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte x = PKGInt_to(GLubyte, 2);
    GLubyte y = PKGInt_to(GLubyte, 3);
    GLubyte z = PKGInt_to(GLubyte, 4);
    GLubyte w = PKGInt_to(GLubyte, 5);

    glVertexAttrib4NubARB(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NubvARB(GLuint index, GLubyte* v);
KMETHOD GL_glVertexAttrib4NubvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte* v = PKG_Error_to(GLubyte*, 2);

    glVertexAttrib4NubvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NuivARB(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttrib4NuivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttrib4NuivARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4NusvARB(GLuint index, GLushort* v);
KMETHOD GL_glVertexAttrib4NusvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLushort* v = PKG_Error_to(GLushort*, 2);

    glVertexAttrib4NusvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4bvARB(GLuint index, GLbyte* v);
KMETHOD GL_glVertexAttrib4bvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLbyte* v = PKG_Error_to(GLbyte*, 2);

    glVertexAttrib4bvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glVertexAttrib4dARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);
    GLdouble z = PKGFloat_to(GLdouble, 4);
    GLdouble w = PKGFloat_to(GLdouble, 5);

    glVertexAttrib4dARB(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4dvARB(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib4dvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib4dvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glVertexAttrib4fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);
    GLfloat z = PKGFloat_to(GLfloat, 4);
    GLfloat w = PKGFloat_to(GLfloat, 5);

    glVertexAttrib4fARB(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4fvARB(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib4fvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4ivARB(GLuint index, GLint* v);
KMETHOD GL_glVertexAttrib4ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttrib4ivARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
KMETHOD GL_glVertexAttrib4sARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);
    GLshort z = PKGInt_to(GLshort, 4);
    GLshort w = PKGInt_to(GLshort, 5);

    glVertexAttrib4sARB(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4svARB(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib4svARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib4svARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4ubvARB(GLuint index, GLubyte* v);
KMETHOD GL_glVertexAttrib4ubvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte* v = PKG_Error_to(GLubyte*, 2);

    glVertexAttrib4ubvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4uivARB(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttrib4uivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttrib4uivARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4usvARB(GLuint index, GLushort* v);
KMETHOD GL_glVertexAttrib4usvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLushort* v = PKG_Error_to(GLushort*, 2);

    glVertexAttrib4usvARB(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glVertexAttribPointerARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint size = PKGInt_to(GLint, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLboolean normalized = PKGInt_to(GLboolean, 4);
    GLsizei stride = PKGInt_to(GLsizei, 5);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 6);

    glVertexAttribPointerARB(index, size, type, normalized, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glDisableVertexAttribArrayARB(GLuint index);
KMETHOD GL_glDisableVertexAttribArrayARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);

    glDisableVertexAttribArrayARB(index);
    RETURNvoid_();
}

//## @Native void GL.glEnableVertexAttribArrayARB(GLuint index);
KMETHOD GL_glEnableVertexAttribArrayARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);

    glEnableVertexAttribArrayARB(index);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid** pointer);
KMETHOD GL_glGetVertexAttribPointervARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid** pointer = PKG_Error_to(GLvoid**, 3);

    glGetVertexAttribPointervARB(index, pname, pointer);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble* params);
KMETHOD GL_glGetVertexAttribdvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glGetVertexAttribdvARB(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat* params);
KMETHOD GL_glGetVertexAttribfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetVertexAttribfvARB(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribivARB(GLuint index, GLenum pname, GLint* params);
KMETHOD GL_glGetVertexAttribivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetVertexAttribivARB(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glDeleteObjectARB(GLhandleARB obj);
KMETHOD GL_glDeleteObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 1);

    glDeleteObjectARB(obj);
    RETURNvoid_();
}

//## @Native GLhandleARB GL.glGetHandleARB(GLenum pname);
KMETHOD GL_glGetHandleARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);

    GLhandleARB ret = glGetHandleARB(pname);
    RETURN_error(ret);
}

//## @Native void GL.glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
KMETHOD GL_glDetachObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB containerObj = PKG_Error_to(GLhandleARB, 1);
    GLhandleARB attachedObj = PKG_Error_to(GLhandleARB, 2);

    glDetachObjectARB(containerObj, attachedObj);
    RETURNvoid_();
}

//## @Native GLhandleARB GL.glCreateShaderObjectARB(GLenum shaderType);
KMETHOD GL_glCreateShaderObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum shaderType = PKGInt_to(GLenum, 1);

    GLhandleARB ret = glCreateShaderObjectARB(shaderType);
    RETURN_error(ret);
}

//## @Native void GL.glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB** string, GLint* length);
KMETHOD GL_glShaderSourceARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB shaderObj = PKG_Error_to(GLhandleARB, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    const GLcharARB** string = PKG_Error_to(const GLcharARB**, 3);
    GLint* length = PKG_Error_to(GLint*, 4);

    glShaderSourceARB(shaderObj, count, string, length);
    RETURNvoid_();
}

//## @Native void GL.glCompileShaderARB(GLhandleARB shaderObj);
KMETHOD GL_glCompileShaderARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB shaderObj = PKG_Error_to(GLhandleARB, 1);

    glCompileShaderARB(shaderObj);
    RETURNvoid_();
}

//## @Native GLhandleARB GL.glCreateProgramObjectARB();
KMETHOD GL_glCreateProgramObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{

    GLhandleARB ret = glCreateProgramObjectARB();
    RETURN_error(ret);
}

//## @Native void GL.glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
KMETHOD GL_glAttachObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB containerObj = PKG_Error_to(GLhandleARB, 1);
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 2);

    glAttachObjectARB(containerObj, obj);
    RETURNvoid_();
}

//## @Native void GL.glLinkProgramARB(GLhandleARB programObj);
KMETHOD GL_glLinkProgramARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);

    glLinkProgramARB(programObj);
    RETURNvoid_();
}

//## @Native void GL.glUseProgramObjectARB(GLhandleARB programObj);
KMETHOD GL_glUseProgramObjectARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);

    glUseProgramObjectARB(programObj);
    RETURNvoid_();
}

//## @Native void GL.glValidateProgramARB(GLhandleARB programObj);
KMETHOD GL_glValidateProgramARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);

    glValidateProgramARB(programObj);
    RETURNvoid_();
}

//## @Native void GL.glUniform1fARB(GLint location, GLfloat v0);
KMETHOD GL_glUniform1fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);

    glUniform1fARB(location, v0);
    RETURNvoid_();
}

//## @Native void GL.glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
KMETHOD GL_glUniform2fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);

    glUniform2fARB(location, v0, v1);
    RETURNvoid_();
}

//## @Native void GL.glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
KMETHOD GL_glUniform3fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);
    GLfloat v2 = PKGFloat_to(GLfloat, 4);

    glUniform3fARB(location, v0, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
KMETHOD GL_glUniform4fARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);
    GLfloat v2 = PKGFloat_to(GLfloat, 4);
    GLfloat v3 = PKGFloat_to(GLfloat, 5);

    glUniform4fARB(location, v0, v1, v2, v3);
    RETURNvoid_();
}

//## @Native void GL.glUniform1iARB(GLint location, GLint v0);
KMETHOD GL_glUniform1iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);

    glUniform1iARB(location, v0);
    RETURNvoid_();
}

//## @Native void GL.glUniform2iARB(GLint location, GLint v0, GLint v1);
KMETHOD GL_glUniform2iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);

    glUniform2iARB(location, v0, v1);
    RETURNvoid_();
}

//## @Native void GL.glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
KMETHOD GL_glUniform3iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);
    GLint v2 = PKGInt_to(GLint, 4);

    glUniform3iARB(location, v0, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
KMETHOD GL_glUniform4iARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);
    GLint v2 = PKGInt_to(GLint, 4);
    GLint v3 = PKGInt_to(GLint, 5);

    glUniform4iARB(location, v0, v1, v2, v3);
    RETURNvoid_();
}

//## @Native void GL.glUniform1fvARB(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform1fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform1fvARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform2fvARB(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform2fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform2fvARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform3fvARB(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform3fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform3fvARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform4fvARB(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform4fvARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform1ivARB(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform1ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform1ivARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform2ivARB(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform2ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform2ivARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform3ivARB(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform3ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform3ivARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform4ivARB(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform4ivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform4ivARB(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix2fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix2fvARB(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix3fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix3fvARB(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix4fvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix4fvARB(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat* params);
KMETHOD GL_glGetObjectParameterfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetObjectParameterfvARB(obj, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint* params);
KMETHOD GL_glGetObjectParameterivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetObjectParameterivARB(obj, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog);
KMETHOD GL_glGetInfoLogARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 1);
    GLsizei maxLength = PKGInt_to(GLsizei, 2);
    GLsizei* length = PKG_Error_to(GLsizei*, 3);
    GLcharARB* infoLog = PKG_Error_to(GLcharARB*, 4);

    glGetInfoLogARB(obj, maxLength, length, infoLog);
    RETURNvoid_();
}

//## @Native void GL.glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj);
KMETHOD GL_glGetAttachedObjectsARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB containerObj = PKG_Error_to(GLhandleARB, 1);
    GLsizei maxCount = PKGInt_to(GLsizei, 2);
    GLsizei* count = PKG_Error_to(GLsizei*, 3);
    GLhandleARB* obj = PKG_Error_to(GLhandleARB*, 4);

    glGetAttachedObjectsARB(containerObj, maxCount, count, obj);
    RETURNvoid_();
}

//## @Native GLint GL.glGetUniformLocationARB(GLhandleARB programObj, GLcharARB* name);
KMETHOD GL_glGetUniformLocationARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLcharARB* name = PKG_Error_to(GLcharARB*, 2);

    GLint ret = glGetUniformLocationARB(programObj, name);
    RETURNi_(ret);
}

//## @Native void GL.glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name);
KMETHOD GL_glGetActiveUniformARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei maxLength = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLint* size = PKG_Error_to(GLint*, 5);
    GLenum* type = PKG_Error_to(GLenum*, 6);
    GLcharARB* name = PKG_Error_to(GLcharARB*, 7);

    glGetActiveUniformARB(programObj, index, maxLength, length, size, type, name);
    RETURNvoid_();
}

//## @Native void GL.glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat* params);
KMETHOD GL_glGetUniformfvARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetUniformfvARB(programObj, location, params);
    RETURNvoid_();
}

//## @Native void GL.glGetUniformivARB(GLhandleARB programObj, GLint location, GLint* params);
KMETHOD GL_glGetUniformivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetUniformivARB(programObj, location, params);
    RETURNvoid_();
}

//## @Native void GL.glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source);
KMETHOD GL_glGetShaderSourceARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB obj = PKG_Error_to(GLhandleARB, 1);
    GLsizei maxLength = PKGInt_to(GLsizei, 2);
    GLsizei* length = PKG_Error_to(GLsizei*, 3);
    GLcharARB* source = PKG_Error_to(GLcharARB*, 4);

    glGetShaderSourceARB(obj, maxLength, length, source);
    RETURNvoid_();
}

//## @Native void GL.glBindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB* name);
KMETHOD GL_glBindAttribLocationARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLcharARB* name = PKG_Error_to(GLcharARB*, 3);

    glBindAttribLocationARB(programObj, index, name);
    RETURNvoid_();
}

//## @Native void GL.glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name);
KMETHOD GL_glGetActiveAttribARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei maxLength = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLint* size = PKG_Error_to(GLint*, 5);
    GLenum* type = PKG_Error_to(GLenum*, 6);
    GLcharARB* name = PKG_Error_to(GLcharARB*, 7);

    glGetActiveAttribARB(programObj, index, maxLength, length, size, type, name);
    RETURNvoid_();
}

//## @Native GLint GL.glGetAttribLocationARB(GLhandleARB programObj, GLcharARB* name);
KMETHOD GL_glGetAttribLocationARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLhandleARB programObj = PKG_Error_to(GLhandleARB, 1);
    GLcharARB* name = PKG_Error_to(GLcharARB*, 2);

    GLint ret = glGetAttribLocationARB(programObj, name);
    RETURNi_(ret);
}

//## @Native void GL.glBindBufferARB(GLenum target, GLuint buffer);
KMETHOD GL_glBindBufferARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint buffer = PKGInt_to(GLuint, 2);

    glBindBufferARB(target, buffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteBuffersARB(GLsizei n, GLuint* buffers);
KMETHOD GL_glDeleteBuffersARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* buffers = PKG_Error_to(GLuint*, 2);

    glDeleteBuffersARB(n, buffers);
    RETURNvoid_();
}

//## @Native void GL.glGenBuffersARB(GLsizei n, GLuint* buffers);
KMETHOD GL_glGenBuffersARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* buffers = PKG_Error_to(GLuint*, 2);

    glGenBuffersARB(n, buffers);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsBufferARB(GLuint buffer);
KMETHOD GL_glIsBufferARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint buffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsBufferARB(buffer);
    RETURNi_(ret);
}

//## @Native void GL.glBufferDataARB(GLenum target, GLsizeiptrARB size, GLvoid* data, GLenum usage);
KMETHOD GL_glBufferDataARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizeiptrARB size = PKGInt_to(GLsizeiptrARB, 2);
    GLvoid* data = PKG_Error_to(GLvoid*, 3);
    GLenum usage = PKGInt_to(GLenum, 4);

    glBufferDataARB(target, size, data, usage);
    RETURNvoid_();
}

//## @Native void GL.glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
KMETHOD GL_glBufferSubDataARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLintptrARB offset = PKGInt_to(GLintptrARB, 2);
    GLsizeiptrARB size = PKGInt_to(GLsizeiptrARB, 3);
    GLvoid* data = PKG_Error_to(GLvoid*, 4);

    glBufferSubDataARB(target, offset, size, data);
    RETURNvoid_();
}

//## @Native void GL.glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
KMETHOD GL_glGetBufferSubDataARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLintptrARB offset = PKGInt_to(GLintptrARB, 2);
    GLsizeiptrARB size = PKGInt_to(GLsizeiptrARB, 3);
    GLvoid* data = PKG_Error_to(GLvoid*, 4);

    glGetBufferSubDataARB(target, offset, size, data);
    RETURNvoid_();
}

//## @Native GLvoid* GL.glMapBufferARB(GLenum target, GLenum access);
KMETHOD GL_glMapBufferARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum access = PKGInt_to(GLenum, 2);

    GLvoid* ret = glMapBufferARB(target, access);
    RETURN_error(ret);
}

//## @Native GLboolean GL.glUnmapBufferARB(GLenum target);
KMETHOD GL_glUnmapBufferARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    GLboolean ret = glUnmapBufferARB(target);
    RETURNi_(ret);
}

//## @Native void GL.glGetBufferParameterivARB(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetBufferParameterivARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetBufferParameterivARB(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid** params);
KMETHOD GL_glGetBufferPointervARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid** params = PKG_Error_to(GLvoid**, 3);

    glGetBufferPointervARB(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glDrawBuffersARB(GLsizei n, GLenum* bufs);
KMETHOD GL_glDrawBuffersARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLenum* bufs = PKG_Error_to(GLenum*, 2);

    glDrawBuffersARB(n, bufs);
    RETURNvoid_();
}

//## @Native void GL.glClampColorARB(GLenum target, GLenum clamp);
KMETHOD GL_glClampColorARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum clamp = PKGInt_to(GLenum, 2);

    glClampColorARB(target, clamp);
    RETURNvoid_();
}

//## @Native void GL.glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
KMETHOD GL_glDrawArraysInstancedARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint first = PKGInt_to(GLint, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);
    GLsizei primcount = PKGInt_to(GLsizei, 4);

    glDrawArraysInstancedARB(mode, first, count, primcount);
    RETURNvoid_();
}

//## @Native void GL.glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount);
KMETHOD GL_glDrawElementsInstancedARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* indices = PKG_Error_to(GLvoid*, 4);
    GLsizei primcount = PKGInt_to(GLsizei, 5);

    glDrawElementsInstancedARB(mode, count, type, indices, primcount);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribDivisorARB(GLuint index, GLuint divisor);
KMETHOD GL_glVertexAttribDivisorARB(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint divisor = PKGInt_to(GLuint, 2);

    glVertexAttribDivisorARB(index, divisor);
    RETURNvoid_();
}

//## @Native void GL.glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLint base_vertex);
KMETHOD GL_glDrawElementsBaseVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* indices = PKG_Error_to(GLvoid*, 4);
    GLint base_vertex = PKGInt_to(GLint, 5);

    glDrawElementsBaseVertex(mode, count, type, indices, base_vertex);
    RETURNvoid_();
}

//## @Native void GL.glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices, GLint base_vertex);
KMETHOD GL_glDrawRangeElementsBaseVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLuint start = PKGInt_to(GLuint, 2);
    GLuint end = PKGInt_to(GLuint, 3);
    GLsizei count = PKGInt_to(GLsizei, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* indices = PKG_Error_to(GLvoid*, 6);
    GLint base_vertex = PKGInt_to(GLint, 7);

    glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, base_vertex);
    RETURNvoid_();
}

//## @Native void GL.glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint base_vertex);
KMETHOD GL_glDrawElementsInstancedBaseVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* indices = PKG_Error_to(GLvoid*, 4);
    GLsizei primcount = PKGInt_to(GLsizei, 5);
    GLint base_vertex = PKGInt_to(GLint, 6);

    glDrawElementsInstancedBaseVertex(mode, count, type, indices, primcount, base_vertex);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawElementsBaseVertex(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount, GLint* base_vertex);
KMETHOD GL_glMultiDrawElementsBaseVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei* count = PKG_Error_to(GLsizei*, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    const GLvoid** indices = PKG_Error_to(const GLvoid**, 4);
    GLsizei primcount = PKGInt_to(GLsizei, 5);
    GLint* base_vertex = PKG_Error_to(GLint*, 6);

    glMultiDrawElementsBaseVertex(mode, count, type, indices, primcount, base_vertex);
    RETURNvoid_();
}

//## @Native GLsync GL.glFenceSync(GLenum condition, GLbitfield flags);
KMETHOD GL_glFenceSync(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum condition = PKGInt_to(GLenum, 1);
    GLbitfield flags = PKGInt_to(GLbitfield, 2);

    GLsync ret = glFenceSync(condition, flags);
    RETURN_error(ret);
}

//## @Native GLboolean GL.glIsSync(GLsync sync);
KMETHOD GL_glIsSync(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsync sync = PKG_Error_to(GLsync, 1);

    GLboolean ret = glIsSync(sync);
    RETURNi_(ret);
}

//## @Native void GL.glDeleteSync(GLsync sync);
KMETHOD GL_glDeleteSync(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsync sync = PKG_Error_to(GLsync, 1);

    glDeleteSync(sync);
    RETURNvoid_();
}

//## @Native GLenum GL.glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
KMETHOD GL_glClientWaitSync(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsync sync = PKG_Error_to(GLsync, 1);
    GLbitfield flags = PKGInt_to(GLbitfield, 2);
    GLuint64 timeout = PKG_Error_to(GLuint64, 3);

    GLenum ret = glClientWaitSync(sync, flags, timeout);
    RETURNi_(ret);
}

//## @Native void GL.glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
KMETHOD GL_glWaitSync(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsync sync = PKG_Error_to(GLsync, 1);
    GLbitfield flags = PKGInt_to(GLbitfield, 2);
    GLuint64 timeout = PKG_Error_to(GLuint64, 3);

    glWaitSync(sync, flags, timeout);
    RETURNvoid_();
}

//## @Native void GL.glGetInteger64v(GLenum pname, GLint64* params);
KMETHOD GL_glGetInteger64v(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint64* params = PKG_Error_to(GLint64*, 2);

    glGetInteger64v(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
KMETHOD GL_glGetSynciv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsync sync = PKG_Error_to(GLsync, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLsizei bufSize = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLint* values = PKG_Error_to(GLint*, 5);

    glGetSynciv(sync, pname, bufSize, length, values);
    RETURNvoid_();
}

//## @Native void GL.glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
KMETHOD GL_glBlendColorEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampf red = PKGFloat_to(GLclampf, 1);
    GLclampf green = PKGFloat_to(GLclampf, 2);
    GLclampf blue = PKGFloat_to(GLclampf, 3);
    GLclampf alpha = PKGFloat_to(GLclampf, 4);

    glBlendColorEXT(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glBlendEquationEXT(GLenum mode);
KMETHOD GL_glBlendEquationEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glBlendEquationEXT(mode);
    RETURNvoid_();
}

//## @Native void GL.glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices);
KMETHOD GL_glDrawRangeElementsEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLuint start = PKGInt_to(GLuint, 2);
    GLuint end = PKGInt_to(GLuint, 3);
    GLsizei count = PKGInt_to(GLsizei, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* indices = PKG_Error_to(GLvoid*, 6);

    glDrawRangeElementsEXT(mode, start, end, count, type, indices);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
KMETHOD GL_glSecondaryColor3bEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte red = PKGInt_to(GLbyte, 1);
    GLbyte green = PKGInt_to(GLbyte, 2);
    GLbyte blue = PKGInt_to(GLbyte, 3);

    glSecondaryColor3bEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3bvEXT(GLbyte* v);
KMETHOD GL_glSecondaryColor3bvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte* v = PKG_Error_to(GLbyte*, 1);

    glSecondaryColor3bvEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
KMETHOD GL_glSecondaryColor3dEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble red = PKGFloat_to(GLdouble, 1);
    GLdouble green = PKGFloat_to(GLdouble, 2);
    GLdouble blue = PKGFloat_to(GLdouble, 3);

    glSecondaryColor3dEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3dvEXT(GLdouble* v);
KMETHOD GL_glSecondaryColor3dvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glSecondaryColor3dvEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
KMETHOD GL_glSecondaryColor3fEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat red = PKGFloat_to(GLfloat, 1);
    GLfloat green = PKGFloat_to(GLfloat, 2);
    GLfloat blue = PKGFloat_to(GLfloat, 3);

    glSecondaryColor3fEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3fvEXT(GLfloat* v);
KMETHOD GL_glSecondaryColor3fvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glSecondaryColor3fvEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
KMETHOD GL_glSecondaryColor3iEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint red = PKGInt_to(GLint, 1);
    GLint green = PKGInt_to(GLint, 2);
    GLint blue = PKGInt_to(GLint, 3);

    glSecondaryColor3iEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ivEXT(GLint* v);
KMETHOD GL_glSecondaryColor3ivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glSecondaryColor3ivEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
KMETHOD GL_glSecondaryColor3sEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort red = PKGInt_to(GLshort, 1);
    GLshort green = PKGInt_to(GLshort, 2);
    GLshort blue = PKGInt_to(GLshort, 3);

    glSecondaryColor3sEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3svEXT(GLshort* v);
KMETHOD GL_glSecondaryColor3svEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glSecondaryColor3svEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
KMETHOD GL_glSecondaryColor3ubEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte red = PKGInt_to(GLubyte, 1);
    GLubyte green = PKGInt_to(GLubyte, 2);
    GLubyte blue = PKGInt_to(GLubyte, 3);

    glSecondaryColor3ubEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ubvEXT(GLubyte* v);
KMETHOD GL_glSecondaryColor3ubvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* v = PKG_Error_to(GLubyte*, 1);

    glSecondaryColor3ubvEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
KMETHOD GL_glSecondaryColor3uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint red = PKGInt_to(GLuint, 1);
    GLuint green = PKGInt_to(GLuint, 2);
    GLuint blue = PKGInt_to(GLuint, 3);

    glSecondaryColor3uiEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3uivEXT(GLuint* v);
KMETHOD GL_glSecondaryColor3uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint* v = PKG_Error_to(GLuint*, 1);

    glSecondaryColor3uivEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
KMETHOD GL_glSecondaryColor3usEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort red = PKGInt_to(GLushort, 1);
    GLushort green = PKGInt_to(GLushort, 2);
    GLushort blue = PKGInt_to(GLushort, 3);

    glSecondaryColor3usEXT(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3usvEXT(GLushort* v);
KMETHOD GL_glSecondaryColor3usvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort* v = PKG_Error_to(GLushort*, 1);

    glSecondaryColor3usvEXT(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glSecondaryColorPointerEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glSecondaryColorPointerEXT(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawArraysEXT(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
KMETHOD GL_glMultiDrawArraysEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint* first = PKG_Error_to(GLint*, 2);
    GLsizei* count = PKG_Error_to(GLsizei*, 3);
    GLsizei primcount = PKGInt_to(GLsizei, 4);

    glMultiDrawArraysEXT(mode, first, count, primcount);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawElementsEXT(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount);
KMETHOD GL_glMultiDrawElementsEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei* count = PKG_Error_to(GLsizei*, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    const GLvoid** indices = PKG_Error_to(const GLvoid**, 4);
    GLsizei primcount = PKGInt_to(GLsizei, 5);

    glMultiDrawElementsEXT(mode, count, type, indices, primcount);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordfEXT(GLfloat coord);
KMETHOD GL_glFogCoordfEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat coord = PKGFloat_to(GLfloat, 1);

    glFogCoordfEXT(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordfvEXT(GLfloat* coord);
KMETHOD GL_glFogCoordfvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* coord = PKG_Error_to(GLfloat*, 1);

    glFogCoordfvEXT(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoorddEXT(GLdouble coord);
KMETHOD GL_glFogCoorddEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble coord = PKGFloat_to(GLdouble, 1);

    glFogCoorddEXT(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoorddvEXT(GLdouble* coord);
KMETHOD GL_glFogCoorddvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* coord = PKG_Error_to(GLdouble*, 1);

    glFogCoorddvEXT(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordPointerEXT(GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glFogCoordPointerEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glFogCoordPointerEXT(type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
KMETHOD GL_glBlendFuncSeparateEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum sfactorRGB = PKGInt_to(GLenum, 1);
    GLenum dfactorRGB = PKGInt_to(GLenum, 2);
    GLenum sfactorAlpha = PKGInt_to(GLenum, 3);
    GLenum dfactorAlpha = PKGInt_to(GLenum, 4);

    glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    RETURNvoid_();
}

//## @Native void GL.glActiveStencilFaceEXT(GLenum face);
KMETHOD GL_glActiveStencilFaceEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);

    glActiveStencilFaceEXT(face);
    RETURNvoid_();
}

//## @Native void GL.glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
KMETHOD GL_glDepthBoundsEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampd zmin = PKGFloat_to(GLclampd, 1);
    GLclampd zmax = PKGFloat_to(GLclampd, 2);

    glDepthBoundsEXT(zmin, zmax);
    RETURNvoid_();
}

//## @Native void GL.glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
KMETHOD GL_glBlendEquationSeparateEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum modeRGB = PKGInt_to(GLenum, 1);
    GLenum modeAlpha = PKGInt_to(GLenum, 2);

    glBlendEquationSeparateEXT(modeRGB, modeAlpha);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsRenderbufferEXT(GLuint renderbuffer);
KMETHOD GL_glIsRenderbufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint renderbuffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsRenderbufferEXT(renderbuffer);
    RETURNi_(ret);
}

//## @Native void GL.glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
KMETHOD GL_glBindRenderbufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint renderbuffer = PKGInt_to(GLuint, 2);

    glBindRenderbufferEXT(target, renderbuffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteRenderbuffersEXT(GLsizei n, GLuint* renderbuffers);
KMETHOD GL_glDeleteRenderbuffersEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* renderbuffers = PKG_Error_to(GLuint*, 2);

    glDeleteRenderbuffersEXT(n, renderbuffers);
    RETURNvoid_();
}

//## @Native void GL.glGenRenderbuffersEXT(GLsizei n, GLuint* renderbuffers);
KMETHOD GL_glGenRenderbuffersEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* renderbuffers = PKG_Error_to(GLuint*, 2);

    glGenRenderbuffersEXT(n, renderbuffers);
    RETURNvoid_();
}

//## @Native void GL.glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
KMETHOD GL_glRenderbufferStorageEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);

    glRenderbufferStorageEXT(target, internalformat, width, height);
    RETURNvoid_();
}

//## @Native void GL.glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetRenderbufferParameterivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetRenderbufferParameterivEXT(target, pname, params);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsFramebufferEXT(GLuint framebuffer);
KMETHOD GL_glIsFramebufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint framebuffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsFramebufferEXT(framebuffer);
    RETURNi_(ret);
}

//## @Native void GL.glBindFramebufferEXT(GLenum target, GLuint framebuffer);
KMETHOD GL_glBindFramebufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint framebuffer = PKGInt_to(GLuint, 2);

    glBindFramebufferEXT(target, framebuffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteFramebuffersEXT(GLsizei n, GLuint* framebuffers);
KMETHOD GL_glDeleteFramebuffersEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* framebuffers = PKG_Error_to(GLuint*, 2);

    glDeleteFramebuffersEXT(n, framebuffers);
    RETURNvoid_();
}

//## @Native void GL.glGenFramebuffersEXT(GLsizei n, GLuint* framebuffers);
KMETHOD GL_glGenFramebuffersEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* framebuffers = PKG_Error_to(GLuint*, 2);

    glGenFramebuffersEXT(n, framebuffers);
    RETURNvoid_();
}

//## @Native GLenum GL.glCheckFramebufferStatusEXT(GLenum target);
KMETHOD GL_glCheckFramebufferStatusEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    GLenum ret = glCheckFramebufferStatusEXT(target);
    RETURNi_(ret);
}

//## @Native void GL.glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
KMETHOD GL_glFramebufferTexture1DEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);

    glFramebufferTexture1DEXT(target, attachment, textarget, texture, level);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
KMETHOD GL_glFramebufferTexture2DEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);

    glFramebufferTexture2DEXT(target, attachment, textarget, texture, level);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
KMETHOD GL_glFramebufferTexture3DEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);
    GLint zoffset = PKGInt_to(GLint, 6);

    glFramebufferTexture3DEXT(target, attachment, textarget, texture, level, zoffset);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
KMETHOD GL_glFramebufferRenderbufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum renderbuffertarget = PKGInt_to(GLenum, 3);
    GLuint renderbuffer = PKGInt_to(GLuint, 4);

    glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);
    RETURNvoid_();
}

//## @Native void GL.glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint* params);
KMETHOD GL_glGetFramebufferAttachmentParameterivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum pname = PKGInt_to(GLenum, 3);
    GLint* params = PKG_Error_to(GLint*, 4);

    glGetFramebufferAttachmentParameterivEXT(target, attachment, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGenerateMipmapEXT(GLenum target);
KMETHOD GL_glGenerateMipmapEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glGenerateMipmapEXT(target);
    RETURNvoid_();
}

//## @Native void GL.glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
KMETHOD GL_glBlitFramebufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint srcX0 = PKGInt_to(GLint, 1);
    GLint srcY0 = PKGInt_to(GLint, 2);
    GLint srcX1 = PKGInt_to(GLint, 3);
    GLint srcY1 = PKGInt_to(GLint, 4);
    GLint dstX0 = PKGInt_to(GLint, 5);
    GLint dstY0 = PKGInt_to(GLint, 6);
    GLint dstX1 = PKGInt_to(GLint, 7);
    GLint dstY1 = PKGInt_to(GLint, 8);
    GLbitfield mask = PKGInt_to(GLbitfield, 9);
    GLenum filter = PKGInt_to(GLenum, 10);

    glBlitFramebufferEXT(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    RETURNvoid_();
}

//## @Native void GL.glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
KMETHOD GL_glRenderbufferStorageMultisampleEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei samples = PKGInt_to(GLsizei, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);

    glRenderbufferStorageMultisampleEXT(target, samples, internalformat, width, height);
    RETURNvoid_();
}

//## @Native void GL.glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
KMETHOD GL_glProgramParameteriEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint value = PKGInt_to(GLint, 3);

    glProgramParameteriEXT(program, pname, value);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
KMETHOD GL_glFramebufferTextureEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLuint texture = PKGInt_to(GLuint, 3);
    GLint level = PKGInt_to(GLint, 4);

    glFramebufferTextureEXT(target, attachment, texture, level);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
KMETHOD GL_glFramebufferTextureFaceEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLuint texture = PKGInt_to(GLuint, 3);
    GLint level = PKGInt_to(GLint, 4);
    GLenum face = PKGInt_to(GLenum, 5);

    glFramebufferTextureFaceEXT(target, attachment, texture, level, face);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
KMETHOD GL_glFramebufferTextureLayerEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLuint texture = PKGInt_to(GLuint, 3);
    GLint level = PKGInt_to(GLint, 4);
    GLint layer = PKGInt_to(GLint, 5);

    glFramebufferTextureLayerEXT(target, attachment, texture, level, layer);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsRenderbuffer(GLuint renderbuffer);
KMETHOD GL_glIsRenderbuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint renderbuffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsRenderbuffer(renderbuffer);
    RETURNi_(ret);
}

//## @Native void GL.glBindRenderbuffer(GLenum target, GLuint renderbuffer);
KMETHOD GL_glBindRenderbuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint renderbuffer = PKGInt_to(GLuint, 2);

    glBindRenderbuffer(target, renderbuffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteRenderbuffers(GLsizei n, GLuint* renderbuffers);
KMETHOD GL_glDeleteRenderbuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* renderbuffers = PKG_Error_to(GLuint*, 2);

    glDeleteRenderbuffers(n, renderbuffers);
    RETURNvoid_();
}

//## @Native void GL.glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
KMETHOD GL_glGenRenderbuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* renderbuffers = PKG_Error_to(GLuint*, 2);

    glGenRenderbuffers(n, renderbuffers);
    RETURNvoid_();
}

//## @Native void GL.glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
KMETHOD GL_glRenderbufferStorage(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);

    glRenderbufferStorage(target, internalformat, width, height);
    RETURNvoid_();
}

//## @Native void GL.glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetRenderbufferParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetRenderbufferParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsFramebuffer(GLuint framebuffer);
KMETHOD GL_glIsFramebuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint framebuffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsFramebuffer(framebuffer);
    RETURNi_(ret);
}

//## @Native void GL.glBindFramebuffer(GLenum target, GLuint framebuffer);
KMETHOD GL_glBindFramebuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint framebuffer = PKGInt_to(GLuint, 2);

    glBindFramebuffer(target, framebuffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteFramebuffers(GLsizei n, GLuint* framebuffers);
KMETHOD GL_glDeleteFramebuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* framebuffers = PKG_Error_to(GLuint*, 2);

    glDeleteFramebuffers(n, framebuffers);
    RETURNvoid_();
}

//## @Native void GL.glGenFramebuffers(GLsizei n, GLuint* framebuffers);
KMETHOD GL_glGenFramebuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* framebuffers = PKG_Error_to(GLuint*, 2);

    glGenFramebuffers(n, framebuffers);
    RETURNvoid_();
}

//## @Native GLenum GL.glCheckFramebufferStatus(GLenum target);
KMETHOD GL_glCheckFramebufferStatus(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    GLenum ret = glCheckFramebufferStatus(target);
    RETURNi_(ret);
}

//## @Native void GL.glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
KMETHOD GL_glFramebufferTexture1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);

    glFramebufferTexture1D(target, attachment, textarget, texture, level);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
KMETHOD GL_glFramebufferTexture2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);

    glFramebufferTexture2D(target, attachment, textarget, texture, level);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
KMETHOD GL_glFramebufferTexture3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum textarget = PKGInt_to(GLenum, 3);
    GLuint texture = PKGInt_to(GLuint, 4);
    GLint level = PKGInt_to(GLint, 5);
    GLint zoffset = PKGInt_to(GLint, 6);

    glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
KMETHOD GL_glFramebufferRenderbuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum renderbuffertarget = PKGInt_to(GLenum, 3);
    GLuint renderbuffer = PKGInt_to(GLuint, 4);

    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    RETURNvoid_();
}

//## @Native void GL.glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
KMETHOD GL_glGetFramebufferAttachmentParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLenum pname = PKGInt_to(GLenum, 3);
    GLint* params = PKG_Error_to(GLint*, 4);

    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGenerateMipmap(GLenum target);
KMETHOD GL_glGenerateMipmap(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glGenerateMipmap(target);
    RETURNvoid_();
}

//## @Native void GL.glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
KMETHOD GL_glBlitFramebuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint srcX0 = PKGInt_to(GLint, 1);
    GLint srcY0 = PKGInt_to(GLint, 2);
    GLint srcX1 = PKGInt_to(GLint, 3);
    GLint srcY1 = PKGInt_to(GLint, 4);
    GLint dstX0 = PKGInt_to(GLint, 5);
    GLint dstY0 = PKGInt_to(GLint, 6);
    GLint dstX1 = PKGInt_to(GLint, 7);
    GLint dstY1 = PKGInt_to(GLint, 8);
    GLbitfield mask = PKGInt_to(GLbitfield, 9);
    GLenum filter = PKGInt_to(GLenum, 10);

    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    RETURNvoid_();
}

//## @Native void GL.glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
KMETHOD GL_glRenderbufferStorageMultisample(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei samples = PKGInt_to(GLsizei, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);

    glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
    RETURNvoid_();
}

//## @Native void GL.glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
KMETHOD GL_glFramebufferTextureLayer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum attachment = PKGInt_to(GLenum, 2);
    GLuint texture = PKGInt_to(GLuint, 3);
    GLint level = PKGInt_to(GLint, 4);
    GLint layer = PKGInt_to(GLint, 5);

    glFramebufferTextureLayer(target, attachment, texture, level, layer);
    RETURNvoid_();
}

//## @Native void GL.glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
KMETHOD GL_glBindBufferRangeEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLuint buffer = PKGInt_to(GLuint, 3);
    GLintptr offset = PKGInt_to(GLintptr, 4);
    GLsizeiptr size = PKGInt_to(GLsizeiptr, 5);

    glBindBufferRangeEXT(target, index, buffer, offset, size);
    RETURNvoid_();
}

//## @Native void GL.glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
KMETHOD GL_glBindBufferOffsetEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLuint buffer = PKGInt_to(GLuint, 3);
    GLintptr offset = PKGInt_to(GLintptr, 4);

    glBindBufferOffsetEXT(target, index, buffer, offset);
    RETURNvoid_();
}

//## @Native void GL.glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
KMETHOD GL_glBindBufferBaseEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLuint buffer = PKGInt_to(GLuint, 3);

    glBindBufferBaseEXT(target, index, buffer);
    RETURNvoid_();
}

//## @Native void GL.glBeginTransformFeedbackEXT(GLenum primitiveMode);
KMETHOD GL_glBeginTransformFeedbackEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum primitiveMode = PKGInt_to(GLenum, 1);

    glBeginTransformFeedbackEXT(primitiveMode);
    RETURNvoid_();
}

//## @Native void GL.glEndTransformFeedbackEXT();
KMETHOD GL_glEndTransformFeedbackEXT(CTX ctx, ksfp_t *sfp _RIX)
{

    glEndTransformFeedbackEXT();
    RETURNvoid_();
}

//## @Native void GL.glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar** varyings, GLenum bufferMode);
KMETHOD GL_glTransformFeedbackVaryingsEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    const GLchar** varyings = PKG_Error_to(const GLchar**, 3);
    GLenum bufferMode = PKGInt_to(GLenum, 4);

    glTransformFeedbackVaryingsEXT(program, count, varyings, bufferMode);
    RETURNvoid_();
}

//## @Native void GL.glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
KMETHOD GL_glGetTransformFeedbackVaryingEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei bufSize = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLsizei* size = PKG_Error_to(GLsizei*, 5);
    GLenum* type = PKG_Error_to(GLenum*, 6);
    GLchar* name = PKG_Error_to(GLchar*, 7);

    glGetTransformFeedbackVaryingEXT(program, index, bufSize, length, size, type, name);
    RETURNvoid_();
}

//## @Native void GL.glGetIntegerIndexedvEXT(GLenum param, GLuint index, GLint* values);
KMETHOD GL_glGetIntegerIndexedvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum param = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLint* values = PKG_Error_to(GLint*, 3);

    glGetIntegerIndexedvEXT(param, index, values);
    RETURNvoid_();
}

//## @Native void GL.glGetBooleanIndexedvEXT(GLenum param, GLuint index, GLboolean* values);
KMETHOD GL_glGetBooleanIndexedvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum param = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLboolean* values = PKG_Error_to(GLboolean*, 3);

    glGetBooleanIndexedvEXT(param, index, values);
    RETURNvoid_();
}

//## @Native void GL.glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
KMETHOD GL_glUniformBufferEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLuint buffer = PKGInt_to(GLuint, 3);

    glUniformBufferEXT(program, location, buffer);
    RETURNvoid_();
}

//## @Native GLint GL.glGetUniformBufferSizeEXT(GLuint program, GLint location);
KMETHOD GL_glGetUniformBufferSizeEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);

    GLint ret = glGetUniformBufferSizeEXT(program, location);
    RETURNi_(ret);
}

//## @Native GLintptr GL.glGetUniformOffsetEXT(GLuint program, GLint location);
KMETHOD GL_glGetUniformOffsetEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);

    GLintptr ret = glGetUniformOffsetEXT(program, location);
    RETURNi_(ret);
}

//## @Native void GL.glClearColorIiEXT(GLint r, GLint g, GLint b, GLint a );
KMETHOD GL_glClearColorIiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint r = PKGInt_to(GLint, 1);
    GLint g = PKGInt_to(GLint, 2);
    GLint b = PKGInt_to(GLint, 3);
    GLint a = PKGInt_to(GLint, 4);

    glClearColorIiEXT(r, g, b, a);
    RETURNvoid_();
}

//## @Native void GL.glClearColorIuiEXT(GLuint r, GLuint g, GLuint b, GLuint a );
KMETHOD GL_glClearColorIuiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint r = PKGInt_to(GLuint, 1);
    GLuint g = PKGInt_to(GLuint, 2);
    GLuint b = PKGInt_to(GLuint, 3);
    GLuint a = PKGInt_to(GLuint, 4);

    glClearColorIuiEXT(r, g, b, a);
    RETURNvoid_();
}

//## @Native void GL.glTexParameterIivEXT(GLenum target, GLenum pname, GLint* params );
KMETHOD GL_glTexParameterIivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glTexParameterIivEXT(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint* params );
KMETHOD GL_glTexParameterIuivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glTexParameterIuivEXT(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetTexParameterIivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetTexParameterIivEXT(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint* params);
KMETHOD GL_glGetTexParameterIuivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glGetTexParameterIuivEXT(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI1iEXT(GLuint index, GLint x);
KMETHOD GL_glVertexAttribI1iEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint x = PKGInt_to(GLint, 2);

    glVertexAttribI1iEXT(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI2iEXT(GLuint index, GLint x, GLint y);
KMETHOD GL_glVertexAttribI2iEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint x = PKGInt_to(GLint, 2);
    GLint y = PKGInt_to(GLint, 3);

    glVertexAttribI2iEXT(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
KMETHOD GL_glVertexAttribI3iEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint x = PKGInt_to(GLint, 2);
    GLint y = PKGInt_to(GLint, 3);
    GLint z = PKGInt_to(GLint, 4);

    glVertexAttribI3iEXT(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
KMETHOD GL_glVertexAttribI4iEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint x = PKGInt_to(GLint, 2);
    GLint y = PKGInt_to(GLint, 3);
    GLint z = PKGInt_to(GLint, 4);
    GLint w = PKGInt_to(GLint, 5);

    glVertexAttribI4iEXT(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI1uiEXT(GLuint index, GLuint x);
KMETHOD GL_glVertexAttribI1uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint x = PKGInt_to(GLuint, 2);

    glVertexAttribI1uiEXT(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
KMETHOD GL_glVertexAttribI2uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint x = PKGInt_to(GLuint, 2);
    GLuint y = PKGInt_to(GLuint, 3);

    glVertexAttribI2uiEXT(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
KMETHOD GL_glVertexAttribI3uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint x = PKGInt_to(GLuint, 2);
    GLuint y = PKGInt_to(GLuint, 3);
    GLuint z = PKGInt_to(GLuint, 4);

    glVertexAttribI3uiEXT(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
KMETHOD GL_glVertexAttribI4uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint x = PKGInt_to(GLuint, 2);
    GLuint y = PKGInt_to(GLuint, 3);
    GLuint z = PKGInt_to(GLuint, 4);
    GLuint w = PKGInt_to(GLuint, 5);

    glVertexAttribI4uiEXT(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI1ivEXT(GLuint index, GLint* v);
KMETHOD GL_glVertexAttribI1ivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttribI1ivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI2ivEXT(GLuint index, GLint* v);
KMETHOD GL_glVertexAttribI2ivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttribI2ivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI3ivEXT(GLuint index, GLint* v);
KMETHOD GL_glVertexAttribI3ivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttribI3ivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4ivEXT(GLuint index, GLint* v);
KMETHOD GL_glVertexAttribI4ivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttribI4ivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI1uivEXT(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttribI1uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttribI1uivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI2uivEXT(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttribI2uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttribI2uivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI3uivEXT(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttribI3uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttribI3uivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4uivEXT(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttribI4uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttribI4uivEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4bvEXT(GLuint index, GLbyte* v);
KMETHOD GL_glVertexAttribI4bvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLbyte* v = PKG_Error_to(GLbyte*, 2);

    glVertexAttribI4bvEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4svEXT(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttribI4svEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttribI4svEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4ubvEXT(GLuint index, GLubyte* v);
KMETHOD GL_glVertexAttribI4ubvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte* v = PKG_Error_to(GLubyte*, 2);

    glVertexAttribI4ubvEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribI4usvEXT(GLuint index, GLushort* v);
KMETHOD GL_glVertexAttribI4usvEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLushort* v = PKG_Error_to(GLushort*, 2);

    glVertexAttribI4usvEXT(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glVertexAttribIPointerEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint size = PKGInt_to(GLint, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLsizei stride = PKGInt_to(GLsizei, 4);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 5);

    glVertexAttribIPointerEXT(index, size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint* params);
KMETHOD GL_glGetVertexAttribIivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetVertexAttribIivEXT(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint* params);
KMETHOD GL_glGetVertexAttribIuivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glGetVertexAttribIuivEXT(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glUniform1uiEXT(GLint location, GLuint v0);
KMETHOD GL_glUniform1uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLuint v0 = PKGInt_to(GLuint, 2);

    glUniform1uiEXT(location, v0);
    RETURNvoid_();
}

//## @Native void GL.glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
KMETHOD GL_glUniform2uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLuint v0 = PKGInt_to(GLuint, 2);
    GLuint v1 = PKGInt_to(GLuint, 3);

    glUniform2uiEXT(location, v0, v1);
    RETURNvoid_();
}

//## @Native void GL.glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
KMETHOD GL_glUniform3uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLuint v0 = PKGInt_to(GLuint, 2);
    GLuint v1 = PKGInt_to(GLuint, 3);
    GLuint v2 = PKGInt_to(GLuint, 4);

    glUniform3uiEXT(location, v0, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
KMETHOD GL_glUniform4uiEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLuint v0 = PKGInt_to(GLuint, 2);
    GLuint v1 = PKGInt_to(GLuint, 3);
    GLuint v2 = PKGInt_to(GLuint, 4);
    GLuint v3 = PKGInt_to(GLuint, 5);

    glUniform4uiEXT(location, v0, v1, v2, v3);
    RETURNvoid_();
}

//## @Native void GL.glUniform1uivEXT(GLint location, GLsizei count, GLuint* value);
KMETHOD GL_glUniform1uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLuint* value = PKG_Error_to(GLuint*, 3);

    glUniform1uivEXT(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform2uivEXT(GLint location, GLsizei count, GLuint* value);
KMETHOD GL_glUniform2uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLuint* value = PKG_Error_to(GLuint*, 3);

    glUniform2uivEXT(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform3uivEXT(GLint location, GLsizei count, GLuint* value);
KMETHOD GL_glUniform3uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLuint* value = PKG_Error_to(GLuint*, 3);

    glUniform3uivEXT(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform4uivEXT(GLint location, GLsizei count, GLuint* value);
KMETHOD GL_glUniform4uivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLuint* value = PKG_Error_to(GLuint*, 3);

    glUniform4uivEXT(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glGetUniformuivEXT(GLuint program, GLint location, GLuint* params);
KMETHOD GL_glGetUniformuivEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glGetUniformuivEXT(program, location, params);
    RETURNvoid_();
}

//## @Native void GL.glBindFragDataLocationEXT(GLuint program, GLuint colorNumber, GLchar* name);
KMETHOD GL_glBindFragDataLocationEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint colorNumber = PKGInt_to(GLuint, 2);
    GLchar* name = PKG_Error_to(GLchar*, 3);

    glBindFragDataLocationEXT(program, colorNumber, name);
    RETURNvoid_();
}

//## @Native GLint GL.glGetFragDataLocationEXT(GLuint program, GLchar* name);
KMETHOD GL_glGetFragDataLocationEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLchar* name = PKG_Error_to(GLchar*, 2);

    GLint ret = glGetFragDataLocationEXT(program, name);
    RETURNi_(ret);
}

//## @Native void GL.glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
KMETHOD GL_glColorMaskIndexedEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLboolean r = PKGInt_to(GLboolean, 2);
    GLboolean g = PKGInt_to(GLboolean, 3);
    GLboolean b = PKGInt_to(GLboolean, 4);
    GLboolean a = PKGInt_to(GLboolean, 5);

    glColorMaskIndexedEXT(index, r, g, b, a);
    RETURNvoid_();
}

//## @Native void GL.glEnableIndexedEXT(GLenum target, GLuint index);
KMETHOD GL_glEnableIndexedEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);

    glEnableIndexedEXT(target, index);
    RETURNvoid_();
}

//## @Native void GL.glDisableIndexedEXT(GLenum target, GLuint index);
KMETHOD GL_glDisableIndexedEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);

    glDisableIndexedEXT(target, index);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsEnabledIndexedEXT(GLenum target, GLuint index);
KMETHOD GL_glIsEnabledIndexedEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint index = PKGInt_to(GLuint, 2);

    GLboolean ret = glIsEnabledIndexedEXT(target, index);
    RETURNi_(ret);
}

//## @Native void GL.glProvokingVertexEXT(GLenum mode);
KMETHOD GL_glProvokingVertexEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glProvokingVertexEXT(mode);
    RETURNvoid_();
}

//## @Native void GL.glProvokingVertex(GLenum mode);
KMETHOD GL_glProvokingVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glProvokingVertex(mode);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT* params);
KMETHOD GL_glGetQueryObjecti64vEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint64EXT* params = PKG_Error_to(GLint64EXT*, 3);

    glGetQueryObjecti64vEXT(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT* params);
KMETHOD GL_glGetQueryObjectui64vEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint64EXT* params = PKG_Error_to(GLuint64EXT*, 3);

    glGetQueryObjectui64vEXT(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTextureRangeAPPLE(GLenum target, GLsizei length, GLvoid* pointer);
KMETHOD GL_glTextureRangeAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei length = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glTextureRangeAPPLE(target, length, pointer);
    RETURNvoid_();
}

//## @Native void GL.glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid** params);
KMETHOD GL_glGetTexParameterPointervAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid** params = PKG_Error_to(GLvoid**, 3);

    glGetTexParameterPointervAPPLE(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glVertexArrayRangeAPPLE(GLsizei length, GLvoid* pointer);
KMETHOD GL_glVertexArrayRangeAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei length = PKGInt_to(GLsizei, 1);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 2);

    glVertexArrayRangeAPPLE(length, pointer);
    RETURNvoid_();
}

//## @Native void GL.glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid* pointer);
KMETHOD GL_glFlushVertexArrayRangeAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei length = PKGInt_to(GLsizei, 1);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 2);

    glFlushVertexArrayRangeAPPLE(length, pointer);
    RETURNvoid_();
}

//## @Native void GL.glVertexArrayParameteriAPPLE(GLenum pname, GLint param);
KMETHOD GL_glVertexArrayParameteriAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glVertexArrayParameteriAPPLE(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glBindVertexArrayAPPLE(GLuint id);
KMETHOD GL_glBindVertexArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);

    glBindVertexArrayAPPLE(id);
    RETURNvoid_();
}

//## @Native void GL.glDeleteVertexArraysAPPLE(GLsizei n, GLuint* ids);
KMETHOD GL_glDeleteVertexArraysAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glDeleteVertexArraysAPPLE(n, ids);
    RETURNvoid_();
}

//## @Native void GL.glGenVertexArraysAPPLE(GLsizei n, GLuint* ids);
KMETHOD GL_glGenVertexArraysAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glGenVertexArraysAPPLE(n, ids);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsVertexArrayAPPLE(GLuint id);
KMETHOD GL_glIsVertexArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsVertexArrayAPPLE(id);
    RETURNi_(ret);
}

//## @Native void GL.glGenFencesAPPLE(GLsizei n, GLuint* fences);
KMETHOD GL_glGenFencesAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* fences = PKG_Error_to(GLuint*, 2);

    glGenFencesAPPLE(n, fences);
    RETURNvoid_();
}

//## @Native void GL.glDeleteFencesAPPLE(GLsizei n, GLuint* fences);
KMETHOD GL_glDeleteFencesAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* fences = PKG_Error_to(GLuint*, 2);

    glDeleteFencesAPPLE(n, fences);
    RETURNvoid_();
}

//## @Native void GL.glSetFenceAPPLE(GLuint fence);
KMETHOD GL_glSetFenceAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint fence = PKGInt_to(GLuint, 1);

    glSetFenceAPPLE(fence);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsFenceAPPLE(GLuint fence);
KMETHOD GL_glIsFenceAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint fence = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsFenceAPPLE(fence);
    RETURNi_(ret);
}

//## @Native GLboolean GL.glTestFenceAPPLE(GLuint fence);
KMETHOD GL_glTestFenceAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint fence = PKGInt_to(GLuint, 1);

    GLboolean ret = glTestFenceAPPLE(fence);
    RETURNi_(ret);
}

//## @Native void GL.glFinishFenceAPPLE(GLuint fence);
KMETHOD GL_glFinishFenceAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint fence = PKGInt_to(GLuint, 1);

    glFinishFenceAPPLE(fence);
    RETURNvoid_();
}

//## @Native GLboolean GL.glTestObjectAPPLE(GLenum object, GLuint name);
KMETHOD GL_glTestObjectAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum object = PKGInt_to(GLenum, 1);
    GLuint name = PKGInt_to(GLuint, 2);

    GLboolean ret = glTestObjectAPPLE(object, name);
    RETURNi_(ret);
}

//## @Native void GL.glFinishObjectAPPLE(GLenum object, GLuint name);
KMETHOD GL_glFinishObjectAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum object = PKGInt_to(GLenum, 1);
    GLuint name = PKGInt_to(GLuint, 2);

    glFinishObjectAPPLE(object, name);
    RETURNvoid_();
}

//## @Native void GL.glElementPointerAPPLE(GLenum type, GLvoid* pointer);
KMETHOD GL_glElementPointerAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 2);

    glElementPointerAPPLE(type, pointer);
    RETURNvoid_();
}

//## @Native void GL.glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count);
KMETHOD GL_glDrawElementArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint first = PKGInt_to(GLint, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);

    glDrawElementArrayAPPLE(mode, first, count);
    RETURNvoid_();
}

//## @Native void GL.glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
KMETHOD GL_glDrawRangeElementArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLuint start = PKGInt_to(GLuint, 2);
    GLuint end = PKGInt_to(GLuint, 3);
    GLint first = PKGInt_to(GLint, 4);
    GLsizei count = PKGInt_to(GLsizei, 5);

    glDrawRangeElementArrayAPPLE(mode, start, end, first, count);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawElementArrayAPPLE(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
KMETHOD GL_glMultiDrawElementArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint* first = PKG_Error_to(GLint*, 2);
    GLsizei* count = PKG_Error_to(GLsizei*, 3);
    GLsizei primcount = PKGInt_to(GLsizei, 4);

    glMultiDrawElementArrayAPPLE(mode, first, count, primcount);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint* first, GLsizei* count, GLsizei primcount);
KMETHOD GL_glMultiDrawRangeElementArrayAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLuint start = PKGInt_to(GLuint, 2);
    GLuint end = PKGInt_to(GLuint, 3);
    GLint* first = PKG_Error_to(GLint*, 4);
    GLsizei* count = PKG_Error_to(GLsizei*, 5);
    GLsizei primcount = PKGInt_to(GLsizei, 6);

    glMultiDrawRangeElementArrayAPPLE(mode, start, end, first, count, primcount);
    RETURNvoid_();
}

//## @Native void GL.glFlushRenderAPPLE();
KMETHOD GL_glFlushRenderAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{

    glFlushRenderAPPLE();
    RETURNvoid_();
}

//## @Native void GL.glFinishRenderAPPLE();
KMETHOD GL_glFinishRenderAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{

    glFinishRenderAPPLE();
    RETURNvoid_();
}

//## @Native void GL.glSwapAPPLE();
KMETHOD GL_glSwapAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{

    glSwapAPPLE();
    RETURNvoid_();
}

//## @Native void GL.glEnableVertexAttribAPPLE(GLuint index, GLenum pname);
KMETHOD GL_glEnableVertexAttribAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);

    glEnableVertexAttribAPPLE(index, pname);
    RETURNvoid_();
}

//## @Native void GL.glDisableVertexAttribAPPLE(GLuint index, GLenum pname);
KMETHOD GL_glDisableVertexAttribAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);

    glDisableVertexAttribAPPLE(index, pname);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname);
KMETHOD GL_glIsVertexAttribEnabledAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);

    GLboolean ret = glIsVertexAttribEnabledAPPLE(index, pname);
    RETURNi_(ret);
}

//## @Native void GL.glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble* points);
KMETHOD GL_glMapVertexAttrib1dAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint size = PKGInt_to(GLuint, 2);
    GLdouble u1 = PKGFloat_to(GLdouble, 3);
    GLdouble u2 = PKGFloat_to(GLdouble, 4);
    GLint stride = PKGInt_to(GLint, 5);
    GLint order = PKGInt_to(GLint, 6);
    GLdouble* points = PKG_Error_to(GLdouble*, 7);

    glMapVertexAttrib1dAPPLE(index, size, u1, u2, stride, order, points);
    RETURNvoid_();
}

//## @Native void GL.glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat* points);
KMETHOD GL_glMapVertexAttrib1fAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint size = PKGInt_to(GLuint, 2);
    GLfloat u1 = PKGFloat_to(GLfloat, 3);
    GLfloat u2 = PKGFloat_to(GLfloat, 4);
    GLint stride = PKGInt_to(GLint, 5);
    GLint order = PKGInt_to(GLint, 6);
    GLfloat* points = PKG_Error_to(GLfloat*, 7);

    glMapVertexAttrib1fAPPLE(index, size, u1, u2, stride, order, points);
    RETURNvoid_();
}

//## @Native void GL.glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble* points);
KMETHOD GL_glMapVertexAttrib2dAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint size = PKGInt_to(GLuint, 2);
    GLdouble u1 = PKGFloat_to(GLdouble, 3);
    GLdouble u2 = PKGFloat_to(GLdouble, 4);
    GLint ustride = PKGInt_to(GLint, 5);
    GLint uorder = PKGInt_to(GLint, 6);
    GLdouble v1 = PKGFloat_to(GLdouble, 7);
    GLdouble v2 = PKGFloat_to(GLdouble, 8);
    GLint vstride = PKGInt_to(GLint, 9);
    GLint vorder = PKGInt_to(GLint, 10);
    GLdouble* points = PKG_Error_to(GLdouble*, 11);

    glMapVertexAttrib2dAPPLE(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    RETURNvoid_();
}

//## @Native void GL.glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat* points);
KMETHOD GL_glMapVertexAttrib2fAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint size = PKGInt_to(GLuint, 2);
    GLfloat u1 = PKGFloat_to(GLfloat, 3);
    GLfloat u2 = PKGFloat_to(GLfloat, 4);
    GLint ustride = PKGInt_to(GLint, 5);
    GLint uorder = PKGInt_to(GLint, 6);
    GLfloat v1 = PKGFloat_to(GLfloat, 7);
    GLfloat v2 = PKGFloat_to(GLfloat, 8);
    GLint vstride = PKGInt_to(GLint, 9);
    GLint vorder = PKGInt_to(GLint, 10);
    GLfloat* points = PKG_Error_to(GLfloat*, 11);

    glMapVertexAttrib2fAPPLE(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    RETURNvoid_();
}

//## @Native void GL.glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param);
KMETHOD GL_glBufferParameteriAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glBufferParameteriAPPLE(target, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size);
KMETHOD GL_glFlushMappedBufferRangeAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLintptr offset = PKGInt_to(GLintptr, 2);
    GLsizeiptr size = PKGInt_to(GLsizeiptr, 3);

    glFlushMappedBufferRangeAPPLE(target, offset, size);
    RETURNvoid_();
}

//## @Native GLenum GL.glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
KMETHOD GL_glObjectPurgeableAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum objectType = PKGInt_to(GLenum, 1);
    GLuint name = PKGInt_to(GLuint, 2);
    GLenum option = PKGInt_to(GLenum, 3);

    GLenum ret = glObjectPurgeableAPPLE(objectType, name, option);
    RETURNi_(ret);
}

//## @Native GLenum GL.glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
KMETHOD GL_glObjectUnpurgeableAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum objectType = PKGInt_to(GLenum, 1);
    GLuint name = PKGInt_to(GLuint, 2);
    GLenum option = PKGInt_to(GLenum, 3);

    GLenum ret = glObjectUnpurgeableAPPLE(objectType, name, option);
    RETURNi_(ret);
}

//## @Native void GL.glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint* params);
KMETHOD GL_glGetObjectParameterivAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum objectType = PKGInt_to(GLenum, 1);
    GLuint name = PKGInt_to(GLuint, 2);
    GLenum pname = PKGInt_to(GLenum, 3);
    GLint* params = PKG_Error_to(GLint*, 4);

    glGetObjectParameterivAPPLE(objectType, name, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glPointSizePointerAPPLE(GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glPointSizePointerAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glPointSizePointerAPPLE(type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glVertexPointSizefAPPLE(GLfloat size);
KMETHOD GL_glVertexPointSizefAPPLE(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat size = PKGFloat_to(GLfloat, 1);

    glVertexPointSizefAPPLE(size);
    RETURNvoid_();
}

//## @Native void GL.glPNTrianglesiATI(GLenum pname, GLint param);
KMETHOD GL_glPNTrianglesiATI(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPNTrianglesiATI(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPNTrianglesfATI(GLenum pname, GLfloat param);
KMETHOD GL_glPNTrianglesfATI(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPNTrianglesfATI(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glBlendEquationSeparateATI(GLenum equationRGB, GLenum equationAlpha);
KMETHOD GL_glBlendEquationSeparateATI(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum equationRGB = PKGInt_to(GLenum, 1);
    GLenum equationAlpha = PKGInt_to(GLenum, 2);

    glBlendEquationSeparateATI(equationRGB, equationAlpha);
    RETURNvoid_();
}

//## @Native void GL.glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
KMETHOD GL_glStencilOpSeparateATI(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum sfail = PKGInt_to(GLenum, 2);
    GLenum dpfail = PKGInt_to(GLenum, 3);
    GLenum dppass = PKGInt_to(GLenum, 4);

    glStencilOpSeparateATI(face, sfail, dpfail, dppass);
    RETURNvoid_();
}

//## @Native void GL.glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
KMETHOD GL_glStencilFuncSeparateATI(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum frontfunc = PKGInt_to(GLenum, 1);
    GLenum backfunc = PKGInt_to(GLenum, 2);
    GLint ref = PKGInt_to(GLint, 3);
    GLuint mask = PKGInt_to(GLuint, 4);

    glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
    RETURNvoid_();
}

//## @Native void GL.glPNTrianglesiATIX(GLenum pname, GLint param);
KMETHOD GL_glPNTrianglesiATIX(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPNTrianglesiATIX(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPNTrianglesfATIX(GLenum pname, GLfloat param);
KMETHOD GL_glPNTrianglesfATIX(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPNTrianglesfATIX(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPointParameteriNV(GLenum pname, GLint param);
KMETHOD GL_glPointParameteriNV(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPointParameteriNV(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPointParameterivNV(GLenum pname, GLint* params);
KMETHOD GL_glPointParameterivNV(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint* params = PKG_Error_to(GLint*, 2);

    glPointParameterivNV(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glBeginConditionalRenderNV(GLuint id, GLenum mode);
KMETHOD GL_glBeginConditionalRenderNV(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum mode = PKGInt_to(GLenum, 2);

    glBeginConditionalRenderNV(id, mode);
    RETURNvoid_();
}

//## @Native void GL.glEndConditionalRenderNV();
KMETHOD GL_glEndConditionalRenderNV(CTX ctx, ksfp_t *sfp _RIX)
{

    glEndConditionalRenderNV();
    RETURNvoid_();
}

//## @Native void GL.glAccum(GLenum op, GLfloat value);
KMETHOD GL_glAccum(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum op = PKGInt_to(GLenum, 1);
    GLfloat value = PKGFloat_to(GLfloat, 2);

    glAccum(op, value);
    RETURNvoid_();
}

//## @Native void GL.glAlphaFunc(GLenum func, GLclampf ref);
KMETHOD GL_glAlphaFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum func = PKGInt_to(GLenum, 1);
    GLclampf ref = PKGFloat_to(GLclampf, 2);

    glAlphaFunc(func, ref);
    RETURNvoid_();
}

//## @Native GLboolean GL.glAreTexturesResident(GLsizei n, GLuint* textures, GLboolean* residences);
KMETHOD GL_glAreTexturesResident(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* textures = PKG_Error_to(GLuint*, 2);
    GLboolean* residences = PKG_Error_to(GLboolean*, 3);

    GLboolean ret = glAreTexturesResident(n, textures, residences);
    RETURNi_(ret);
}

//## @Native void GL.glArrayElement(GLint i);
KMETHOD GL_glArrayElement(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint i = PKGInt_to(GLint, 1);

    glArrayElement(i);
    RETURNvoid_();
}

//## @Native void GL.glBegin(GLenum mode);
KMETHOD GL_glBegin(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glBegin(mode);
    RETURNvoid_();
}

//## @Native void GL.glBindTexture(GLenum target, GLuint texture);
KMETHOD GL_glBindTexture(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint texture = PKGInt_to(GLuint, 2);

    glBindTexture(target, texture);
    RETURNvoid_();
}

//## @Native void GL.glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte* bitmap);
KMETHOD GL_glBitmap(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei width = PKGInt_to(GLsizei, 1);
    GLsizei height = PKGInt_to(GLsizei, 2);
    GLfloat xorig = PKGFloat_to(GLfloat, 3);
    GLfloat yorig = PKGFloat_to(GLfloat, 4);
    GLfloat xmove = PKGFloat_to(GLfloat, 5);
    GLfloat ymove = PKGFloat_to(GLfloat, 6);
    GLubyte* bitmap = PKG_Error_to(GLubyte*, 7);

    glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
    RETURNvoid_();
}

//## @Native void GL.glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
KMETHOD GL_glBlendColor(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampf red = PKGFloat_to(GLclampf, 1);
    GLclampf green = PKGFloat_to(GLclampf, 2);
    GLclampf blue = PKGFloat_to(GLclampf, 3);
    GLclampf alpha = PKGFloat_to(GLclampf, 4);

    glBlendColor(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glBlendEquation(GLenum mode);
KMETHOD GL_glBlendEquation(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glBlendEquation(mode);
    RETURNvoid_();
}

//## @Native void GL.glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
KMETHOD GL_glBlendEquationSeparate(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum modeRGB = PKGInt_to(GLenum, 1);
    GLenum modeAlpha = PKGInt_to(GLenum, 2);

    glBlendEquationSeparate(modeRGB, modeAlpha);
    RETURNvoid_();
}

//## @Native void GL.glBlendFunc(GLenum sfactor, GLenum dfactor);
KMETHOD GL_glBlendFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum sfactor = PKGInt_to(GLenum, 1);
    GLenum dfactor = PKGInt_to(GLenum, 2);

    glBlendFunc(sfactor, dfactor);
    RETURNvoid_();
}

//## @Native void GL.glCallList(GLuint list);
KMETHOD GL_glCallList(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint list = PKGInt_to(GLuint, 1);

    glCallList(list);
    RETURNvoid_();
}

//## @Native void GL.glCallLists(GLsizei n, GLenum type, GLvoid* lists);
KMETHOD GL_glCallLists(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLvoid* lists = PKG_Error_to(GLvoid*, 3);

    glCallLists(n, type, lists);
    RETURNvoid_();
}

//## @Native void GL.glClear(GLbitfield mask);
KMETHOD GL_glClear(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbitfield mask = PKGInt_to(GLbitfield, 1);

    glClear(mask);
    RETURNvoid_();
}

//## @Native void GL.glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
KMETHOD GL_glClearAccum(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat red = PKGFloat_to(GLfloat, 1);
    GLfloat green = PKGFloat_to(GLfloat, 2);
    GLfloat blue = PKGFloat_to(GLfloat, 3);
    GLfloat alpha = PKGFloat_to(GLfloat, 4);

    glClearAccum(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
KMETHOD GL_glClearColor(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampf red = PKGFloat_to(GLclampf, 1);
    GLclampf green = PKGFloat_to(GLclampf, 2);
    GLclampf blue = PKGFloat_to(GLclampf, 3);
    GLclampf alpha = PKGFloat_to(GLclampf, 4);

    glClearColor(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glClearDepth(GLclampd depth);
KMETHOD GL_glClearDepth(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampd depth = PKGFloat_to(GLclampd, 1);

    glClearDepth(depth);
    RETURNvoid_();
}

//## @Native void GL.glClearIndex(GLfloat c);
KMETHOD GL_glClearIndex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat c = PKGFloat_to(GLfloat, 1);

    glClearIndex(c);
    RETURNvoid_();
}

//## @Native void GL.glClearStencil(GLint s);
KMETHOD GL_glClearStencil(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint s = PKGInt_to(GLint, 1);

    glClearStencil(s);
    RETURNvoid_();
}

//## @Native void GL.glClipPlane(GLenum plane, GLdouble* equation);
KMETHOD GL_glClipPlane(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum plane = PKGInt_to(GLenum, 1);
    GLdouble* equation = PKG_Error_to(GLdouble*, 2);

    glClipPlane(plane, equation);
    RETURNvoid_();
}

//## @Native void GL.glColor3b(GLbyte red, GLbyte green, GLbyte blue);
KMETHOD GL_glColor3b(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte red = PKGInt_to(GLbyte, 1);
    GLbyte green = PKGInt_to(GLbyte, 2);
    GLbyte blue = PKGInt_to(GLbyte, 3);

    glColor3b(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3bv(GLbyte* v);
KMETHOD GL_glColor3bv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte* v = PKG_Error_to(GLbyte*, 1);

    glColor3bv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3d(GLdouble red, GLdouble green, GLdouble blue);
KMETHOD GL_glColor3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble red = PKGFloat_to(GLdouble, 1);
    GLdouble green = PKGFloat_to(GLdouble, 2);
    GLdouble blue = PKGFloat_to(GLdouble, 3);

    glColor3d(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3dv(GLdouble* v);
KMETHOD GL_glColor3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glColor3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3f(GLfloat red, GLfloat green, GLfloat blue);
KMETHOD GL_glColor3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat red = PKGFloat_to(GLfloat, 1);
    GLfloat green = PKGFloat_to(GLfloat, 2);
    GLfloat blue = PKGFloat_to(GLfloat, 3);

    glColor3f(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3fv(GLfloat* v);
KMETHOD GL_glColor3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glColor3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3i(GLint red, GLint green, GLint blue);
KMETHOD GL_glColor3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint red = PKGInt_to(GLint, 1);
    GLint green = PKGInt_to(GLint, 2);
    GLint blue = PKGInt_to(GLint, 3);

    glColor3i(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3iv(GLint* v);
KMETHOD GL_glColor3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glColor3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3s(GLshort red, GLshort green, GLshort blue);
KMETHOD GL_glColor3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort red = PKGInt_to(GLshort, 1);
    GLshort green = PKGInt_to(GLshort, 2);
    GLshort blue = PKGInt_to(GLshort, 3);

    glColor3s(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3sv(GLshort* v);
KMETHOD GL_glColor3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glColor3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
KMETHOD GL_glColor3ub(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte red = PKGInt_to(GLubyte, 1);
    GLubyte green = PKGInt_to(GLubyte, 2);
    GLubyte blue = PKGInt_to(GLubyte, 3);

    glColor3ub(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3ubv(GLubyte* v);
KMETHOD GL_glColor3ubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* v = PKG_Error_to(GLubyte*, 1);

    glColor3ubv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3ui(GLuint red, GLuint green, GLuint blue);
KMETHOD GL_glColor3ui(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint red = PKGInt_to(GLuint, 1);
    GLuint green = PKGInt_to(GLuint, 2);
    GLuint blue = PKGInt_to(GLuint, 3);

    glColor3ui(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3uiv(GLuint* v);
KMETHOD GL_glColor3uiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint* v = PKG_Error_to(GLuint*, 1);

    glColor3uiv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor3us(GLushort red, GLushort green, GLushort blue);
KMETHOD GL_glColor3us(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort red = PKGInt_to(GLushort, 1);
    GLushort green = PKGInt_to(GLushort, 2);
    GLushort blue = PKGInt_to(GLushort, 3);

    glColor3us(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glColor3usv(GLushort* v);
KMETHOD GL_glColor3usv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort* v = PKG_Error_to(GLushort*, 1);

    glColor3usv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
KMETHOD GL_glColor4b(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte red = PKGInt_to(GLbyte, 1);
    GLbyte green = PKGInt_to(GLbyte, 2);
    GLbyte blue = PKGInt_to(GLbyte, 3);
    GLbyte alpha = PKGInt_to(GLbyte, 4);

    glColor4b(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4bv(GLbyte* v);
KMETHOD GL_glColor4bv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte* v = PKG_Error_to(GLbyte*, 1);

    glColor4bv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
KMETHOD GL_glColor4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble red = PKGFloat_to(GLdouble, 1);
    GLdouble green = PKGFloat_to(GLdouble, 2);
    GLdouble blue = PKGFloat_to(GLdouble, 3);
    GLdouble alpha = PKGFloat_to(GLdouble, 4);

    glColor4d(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4dv(GLdouble* v);
KMETHOD GL_glColor4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glColor4dv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
KMETHOD GL_glColor4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat red = PKGFloat_to(GLfloat, 1);
    GLfloat green = PKGFloat_to(GLfloat, 2);
    GLfloat blue = PKGFloat_to(GLfloat, 3);
    GLfloat alpha = PKGFloat_to(GLfloat, 4);

    glColor4f(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4fv(GLfloat* v);
KMETHOD GL_glColor4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glColor4fv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
KMETHOD GL_glColor4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint red = PKGInt_to(GLint, 1);
    GLint green = PKGInt_to(GLint, 2);
    GLint blue = PKGInt_to(GLint, 3);
    GLint alpha = PKGInt_to(GLint, 4);

    glColor4i(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4iv(GLint* v);
KMETHOD GL_glColor4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glColor4iv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
KMETHOD GL_glColor4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort red = PKGInt_to(GLshort, 1);
    GLshort green = PKGInt_to(GLshort, 2);
    GLshort blue = PKGInt_to(GLshort, 3);
    GLshort alpha = PKGInt_to(GLshort, 4);

    glColor4s(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4sv(GLshort* v);
KMETHOD GL_glColor4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glColor4sv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
KMETHOD GL_glColor4ub(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte red = PKGInt_to(GLubyte, 1);
    GLubyte green = PKGInt_to(GLubyte, 2);
    GLubyte blue = PKGInt_to(GLubyte, 3);
    GLubyte alpha = PKGInt_to(GLubyte, 4);

    glColor4ub(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4ubv(GLubyte* v);
KMETHOD GL_glColor4ubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* v = PKG_Error_to(GLubyte*, 1);

    glColor4ubv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
KMETHOD GL_glColor4ui(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint red = PKGInt_to(GLuint, 1);
    GLuint green = PKGInt_to(GLuint, 2);
    GLuint blue = PKGInt_to(GLuint, 3);
    GLuint alpha = PKGInt_to(GLuint, 4);

    glColor4ui(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4uiv(GLuint* v);
KMETHOD GL_glColor4uiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint* v = PKG_Error_to(GLuint*, 1);

    glColor4uiv(v);
    RETURNvoid_();
}

//## @Native void GL.glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
KMETHOD GL_glColor4us(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort red = PKGInt_to(GLushort, 1);
    GLushort green = PKGInt_to(GLushort, 2);
    GLushort blue = PKGInt_to(GLushort, 3);
    GLushort alpha = PKGInt_to(GLushort, 4);

    glColor4us(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColor4usv(GLushort* v);
KMETHOD GL_glColor4usv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort* v = PKG_Error_to(GLushort*, 1);

    glColor4usv(v);
    RETURNvoid_();
}

//## @Native void GL.glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
KMETHOD GL_glColorMask(CTX ctx, ksfp_t *sfp _RIX)
{
    GLboolean red = PKGInt_to(GLboolean, 1);
    GLboolean green = PKGInt_to(GLboolean, 2);
    GLboolean blue = PKGInt_to(GLboolean, 3);
    GLboolean alpha = PKGInt_to(GLboolean, 4);

    glColorMask(red, green, blue, alpha);
    RETURNvoid_();
}

//## @Native void GL.glColorMaterial(GLenum face, GLenum mode);
KMETHOD GL_glColorMaterial(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum mode = PKGInt_to(GLenum, 2);

    glColorMaterial(face, mode);
    RETURNvoid_();
}

//## @Native void GL.glColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glColorPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glColorPointer(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid* data);
KMETHOD GL_glColorSubTable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei start = PKGInt_to(GLsizei, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);
    GLenum format = PKGInt_to(GLenum, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* data = PKG_Error_to(GLvoid*, 6);

    glColorSubTable(target, start, count, format, type, data);
    RETURNvoid_();
}

//## @Native void GL.glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid* table);
KMETHOD GL_glColorTable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLenum format = PKGInt_to(GLenum, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* table = PKG_Error_to(GLvoid*, 6);

    glColorTable(target, internalformat, width, format, type, table);
    RETURNvoid_();
}

//## @Native void GL.glColorTableParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glColorTableParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glColorTableParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glColorTableParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glColorTableParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glColorTableParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid* image);
KMETHOD GL_glConvolutionFilter1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLenum format = PKGInt_to(GLenum, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* image = PKG_Error_to(GLvoid*, 6);

    glConvolutionFilter1D(target, internalformat, width, format, type, image);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* image);
KMETHOD GL_glConvolutionFilter2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    GLvoid* image = PKG_Error_to(GLvoid*, 7);

    glConvolutionFilter2D(target, internalformat, width, height, format, type, image);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
KMETHOD GL_glConvolutionParameterf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat params = PKGFloat_to(GLfloat, 3);

    glConvolutionParameterf(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glConvolutionParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glConvolutionParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
KMETHOD GL_glConvolutionParameteri(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint params = PKGInt_to(GLint, 3);

    glConvolutionParameteri(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glConvolutionParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glConvolutionParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glConvolutionParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
KMETHOD GL_glCopyColorSubTable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei start = PKGInt_to(GLsizei, 2);
    GLint x = PKGInt_to(GLint, 3);
    GLint y = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);

    glCopyColorSubTable(target, start, x, y, width);
    RETURNvoid_();
}

//## @Native void GL.glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
KMETHOD GL_glCopyColorTable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLint x = PKGInt_to(GLint, 3);
    GLint y = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);

    glCopyColorTable(target, internalformat, x, y, width);
    RETURNvoid_();
}

//## @Native void GL.glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
KMETHOD GL_glCopyConvolutionFilter1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLint x = PKGInt_to(GLint, 3);
    GLint y = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);

    glCopyConvolutionFilter1D(target, internalformat, x, y, width);
    RETURNvoid_();
}

//## @Native void GL.glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
KMETHOD GL_glCopyConvolutionFilter2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLint x = PKGInt_to(GLint, 3);
    GLint y = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);
    GLsizei height = PKGInt_to(GLsizei, 6);

    glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
KMETHOD GL_glCopyPixels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum type = PKGInt_to(GLenum, 5);

    glCopyPixels(x, y, width, height, type);
    RETURNvoid_();
}

//## @Native void GL.glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
KMETHOD GL_glCopyTexImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLint x = PKGInt_to(GLint, 4);
    GLint y = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);
    GLint border = PKGInt_to(GLint, 7);

    glCopyTexImage1D(target, level, internalformat, x, y, width, border);
    RETURNvoid_();
}

//## @Native void GL.glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
KMETHOD GL_glCopyTexImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLint x = PKGInt_to(GLint, 4);
    GLint y = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);
    GLsizei height = PKGInt_to(GLsizei, 7);
    GLint border = PKGInt_to(GLint, 8);

    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    RETURNvoid_();
}

//## @Native void GL.glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
KMETHOD GL_glCopyTexSubImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint x = PKGInt_to(GLint, 4);
    GLint y = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);

    glCopyTexSubImage1D(target, level, xoffset, x, y, width);
    RETURNvoid_();
}

//## @Native void GL.glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
KMETHOD GL_glCopyTexSubImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLint x = PKGInt_to(GLint, 5);
    GLint y = PKGInt_to(GLint, 6);
    GLsizei width = PKGInt_to(GLsizei, 7);
    GLsizei height = PKGInt_to(GLsizei, 8);

    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
KMETHOD GL_glCopyTexSubImage3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLint zoffset = PKGInt_to(GLint, 5);
    GLint x = PKGInt_to(GLint, 6);
    GLint y = PKGInt_to(GLint, 7);
    GLsizei width = PKGInt_to(GLsizei, 8);
    GLsizei height = PKGInt_to(GLsizei, 9);

    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glCullFace(GLenum mode);
KMETHOD GL_glCullFace(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glCullFace(mode);
    RETURNvoid_();
}

//## @Native void GL.glDeleteLists(GLuint list, GLsizei range);
KMETHOD GL_glDeleteLists(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint list = PKGInt_to(GLuint, 1);
    GLsizei range = PKGInt_to(GLsizei, 2);

    glDeleteLists(list, range);
    RETURNvoid_();
}

//## @Native void GL.glDeleteTextures(GLsizei n, GLuint* textures);
KMETHOD GL_glDeleteTextures(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* textures = PKG_Error_to(GLuint*, 2);

    glDeleteTextures(n, textures);
    RETURNvoid_();
}

//## @Native void GL.glDepthFunc(GLenum func);
KMETHOD GL_glDepthFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum func = PKGInt_to(GLenum, 1);

    glDepthFunc(func);
    RETURNvoid_();
}

//## @Native void GL.glDepthMask(GLboolean flag);
KMETHOD GL_glDepthMask(CTX ctx, ksfp_t *sfp _RIX)
{
    GLboolean flag = PKGInt_to(GLboolean, 1);

    glDepthMask(flag);
    RETURNvoid_();
}

//## @Native void GL.glDepthRange(GLclampd zNear, GLclampd zFar);
KMETHOD GL_glDepthRange(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampd zNear = PKGFloat_to(GLclampd, 1);
    GLclampd zFar = PKGFloat_to(GLclampd, 2);

    glDepthRange(zNear, zFar);
    RETURNvoid_();
}

//## @Native void GL.glDisable(GLenum cap);
KMETHOD GL_glDisable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum cap = PKGInt_to(GLenum, 1);

    glDisable(cap);
    RETURNvoid_();
}

//## @Native void GL.glDisableClientState(GLenum array);
KMETHOD GL_glDisableClientState(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum array = PKGInt_to(GLenum, 1);

    glDisableClientState(array);
    RETURNvoid_();
}

//## @Native void GL.glDrawArrays(GLenum mode, GLint first, GLsizei count);
KMETHOD GL_glDrawArrays(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint first = PKGInt_to(GLint, 2);
    GLsizei count = PKGInt_to(GLsizei, 3);

    glDrawArrays(mode, first, count);
    RETURNvoid_();
}

//## @Native void GL.glDrawBuffer(GLenum mode);
KMETHOD GL_glDrawBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glDrawBuffer(mode);
    RETURNvoid_();
}

//## @Native void GL.glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid* indices);
KMETHOD GL_glDrawElements(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* indices = PKG_Error_to(GLvoid*, 4);

    glDrawElements(mode, count, type, indices);
    RETURNvoid_();
}

//## @Native void GL.glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glDrawPixels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei width = PKGInt_to(GLsizei, 1);
    GLsizei height = PKGInt_to(GLsizei, 2);
    GLenum format = PKGInt_to(GLenum, 3);
    GLenum type = PKGInt_to(GLenum, 4);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 5);

    glDrawPixels(width, height, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices);
KMETHOD GL_glDrawRangeElements(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLuint start = PKGInt_to(GLuint, 2);
    GLuint end = PKGInt_to(GLuint, 3);
    GLsizei count = PKGInt_to(GLsizei, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLvoid* indices = PKG_Error_to(GLvoid*, 6);

    glDrawRangeElements(mode, start, end, count, type, indices);
    RETURNvoid_();
}

//## @Native void GL.glEdgeFlag(GLboolean flag);
KMETHOD GL_glEdgeFlag(CTX ctx, ksfp_t *sfp _RIX)
{
    GLboolean flag = PKGInt_to(GLboolean, 1);

    glEdgeFlag(flag);
    RETURNvoid_();
}

//## @Native void GL.glEdgeFlagPointer(GLsizei stride, GLvoid* pointer);
KMETHOD GL_glEdgeFlagPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei stride = PKGInt_to(GLsizei, 1);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 2);

    glEdgeFlagPointer(stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glEdgeFlagv(GLboolean* flag);
KMETHOD GL_glEdgeFlagv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLboolean* flag = PKG_Error_to(GLboolean*, 1);

    glEdgeFlagv(flag);
    RETURNvoid_();
}

//## @Native void GL.glEnable(GLenum cap);
KMETHOD GL_glEnable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum cap = PKGInt_to(GLenum, 1);

    glEnable(cap);
    RETURNvoid_();
}

//## @Native void GL.glEnableClientState(GLenum array);
KMETHOD GL_glEnableClientState(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum array = PKGInt_to(GLenum, 1);

    glEnableClientState(array);
    RETURNvoid_();
}

//## @Native void GL.glEnd();
KMETHOD GL_glEnd(CTX ctx, ksfp_t *sfp _RIX)
{

    glEnd();
    RETURNvoid_();
}

//## @Native void GL.glEndList();
KMETHOD GL_glEndList(CTX ctx, ksfp_t *sfp _RIX)
{

    glEndList();
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord1d(GLdouble u);
KMETHOD GL_glEvalCoord1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble u = PKGFloat_to(GLdouble, 1);

    glEvalCoord1d(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord1dv(GLdouble* u);
KMETHOD GL_glEvalCoord1dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* u = PKG_Error_to(GLdouble*, 1);

    glEvalCoord1dv(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord1f(GLfloat u);
KMETHOD GL_glEvalCoord1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat u = PKGFloat_to(GLfloat, 1);

    glEvalCoord1f(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord1fv(GLfloat* u);
KMETHOD GL_glEvalCoord1fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* u = PKG_Error_to(GLfloat*, 1);

    glEvalCoord1fv(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord2d(GLdouble u, GLdouble v);
KMETHOD GL_glEvalCoord2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble u = PKGFloat_to(GLdouble, 1);
    GLdouble v = PKGFloat_to(GLdouble, 2);

    glEvalCoord2d(u, v);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord2dv(GLdouble* u);
KMETHOD GL_glEvalCoord2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* u = PKG_Error_to(GLdouble*, 1);

    glEvalCoord2dv(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord2f(GLfloat u, GLfloat v);
KMETHOD GL_glEvalCoord2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat u = PKGFloat_to(GLfloat, 1);
    GLfloat v = PKGFloat_to(GLfloat, 2);

    glEvalCoord2f(u, v);
    RETURNvoid_();
}

//## @Native void GL.glEvalCoord2fv(GLfloat* u);
KMETHOD GL_glEvalCoord2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* u = PKG_Error_to(GLfloat*, 1);

    glEvalCoord2fv(u);
    RETURNvoid_();
}

//## @Native void GL.glEvalMesh1(GLenum mode, GLint i1, GLint i2);
KMETHOD GL_glEvalMesh1(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint i1 = PKGInt_to(GLint, 2);
    GLint i2 = PKGInt_to(GLint, 3);

    glEvalMesh1(mode, i1, i2);
    RETURNvoid_();
}

//## @Native void GL.glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
KMETHOD GL_glEvalMesh2(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint i1 = PKGInt_to(GLint, 2);
    GLint i2 = PKGInt_to(GLint, 3);
    GLint j1 = PKGInt_to(GLint, 4);
    GLint j2 = PKGInt_to(GLint, 5);

    glEvalMesh2(mode, i1, i2, j1, j2);
    RETURNvoid_();
}

//## @Native void GL.glEvalPoint1(GLint i);
KMETHOD GL_glEvalPoint1(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint i = PKGInt_to(GLint, 1);

    glEvalPoint1(i);
    RETURNvoid_();
}

//## @Native void GL.glEvalPoint2(GLint i, GLint j);
KMETHOD GL_glEvalPoint2(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint i = PKGInt_to(GLint, 1);
    GLint j = PKGInt_to(GLint, 2);

    glEvalPoint2(i, j);
    RETURNvoid_();
}

//## @Native void GL.glFeedbackBuffer(GLsizei size, GLenum type, GLfloat* buffer);
KMETHOD GL_glFeedbackBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei size = PKGInt_to(GLsizei, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLfloat* buffer = PKG_Error_to(GLfloat*, 3);

    glFeedbackBuffer(size, type, buffer);
    RETURNvoid_();
}

//## @Native void GL.glFinish();
KMETHOD GL_glFinish(CTX ctx, ksfp_t *sfp _RIX)
{

    glFinish();
    RETURNvoid_();
}

//## @Native void GL.glFlush();
KMETHOD GL_glFlush(CTX ctx, ksfp_t *sfp _RIX)
{

    glFlush();
    RETURNvoid_();
}

//## @Native void GL.glFogf(GLenum pname, GLfloat param);
KMETHOD GL_glFogf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glFogf(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glFogfv(GLenum pname, GLfloat* params);
KMETHOD GL_glFogfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat* params = PKG_Error_to(GLfloat*, 2);

    glFogfv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glFogi(GLenum pname, GLint param);
KMETHOD GL_glFogi(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glFogi(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glFogiv(GLenum pname, GLint* params);
KMETHOD GL_glFogiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint* params = PKG_Error_to(GLint*, 2);

    glFogiv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glFrontFace(GLenum mode);
KMETHOD GL_glFrontFace(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glFrontFace(mode);
    RETURNvoid_();
}

//## @Native void GL.glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
KMETHOD GL_glFrustum(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble left = PKGFloat_to(GLdouble, 1);
    GLdouble right = PKGFloat_to(GLdouble, 2);
    GLdouble bottom = PKGFloat_to(GLdouble, 3);
    GLdouble top = PKGFloat_to(GLdouble, 4);
    GLdouble zNear = PKGFloat_to(GLdouble, 5);
    GLdouble zFar = PKGFloat_to(GLdouble, 6);

    glFrustum(left, right, bottom, top, zNear, zFar);
    RETURNvoid_();
}

//## @Native GLuint GL.glGenLists(GLsizei range);
KMETHOD GL_glGenLists(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei range = PKGInt_to(GLsizei, 1);

    GLuint ret = glGenLists(range);
    RETURNi_(ret);
}

//## @Native void GL.glGenTextures(GLsizei n, GLuint* textures);
KMETHOD GL_glGenTextures(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* textures = PKG_Error_to(GLuint*, 2);

    glGenTextures(n, textures);
    RETURNvoid_();
}

//## @Native void GL.glGetBooleanv(GLenum pname, GLboolean* params);
KMETHOD GL_glGetBooleanv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLboolean* params = PKG_Error_to(GLboolean*, 2);

    glGetBooleanv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetClipPlane(GLenum plane, GLdouble* equation);
KMETHOD GL_glGetClipPlane(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum plane = PKGInt_to(GLenum, 1);
    GLdouble* equation = PKG_Error_to(GLdouble*, 2);

    glGetClipPlane(plane, equation);
    RETURNvoid_();
}

//## @Native void GL.glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid* table);
KMETHOD GL_glGetColorTable(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum format = PKGInt_to(GLenum, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* table = PKG_Error_to(GLvoid*, 4);

    glGetColorTable(target, format, type, table);
    RETURNvoid_();
}

//## @Native void GL.glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetColorTableParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetColorTableParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetColorTableParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetColorTableParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetColorTableParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid* image);
KMETHOD GL_glGetConvolutionFilter(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum format = PKGInt_to(GLenum, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* image = PKG_Error_to(GLvoid*, 4);

    glGetConvolutionFilter(target, format, type, image);
    RETURNvoid_();
}

//## @Native void GL.glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetConvolutionParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetConvolutionParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetConvolutionParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetConvolutionParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetDoublev(GLenum pname, GLdouble* params);
KMETHOD GL_glGetDoublev(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLdouble* params = PKG_Error_to(GLdouble*, 2);

    glGetDoublev(pname, params);
    RETURNvoid_();
}

//## @Native GLenum GL.glGetError();
KMETHOD GL_glGetError(CTX ctx, ksfp_t *sfp _RIX)
{

    GLenum ret = glGetError();
    RETURNi_(ret);
}

//## @Native void GL.glGetFloatv(GLenum pname, GLfloat* params);
KMETHOD GL_glGetFloatv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat* params = PKG_Error_to(GLfloat*, 2);

    glGetFloatv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
KMETHOD GL_glGetHistogram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLboolean reset = PKGInt_to(GLboolean, 2);
    GLenum format = PKGInt_to(GLenum, 3);
    GLenum type = PKGInt_to(GLenum, 4);
    GLvoid* values = PKG_Error_to(GLvoid*, 5);

    glGetHistogram(target, reset, format, type, values);
    RETURNvoid_();
}

//## @Native void GL.glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetHistogramParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetHistogramParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetHistogramParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetHistogramParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetHistogramParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetIntegerv(GLenum pname, GLint* params);
KMETHOD GL_glGetIntegerv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint* params = PKG_Error_to(GLint*, 2);

    glGetIntegerv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetLightfv(GLenum light, GLenum pname, GLfloat* params);
KMETHOD GL_glGetLightfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetLightfv(light, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetLightiv(GLenum light, GLenum pname, GLint* params);
KMETHOD GL_glGetLightiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetLightiv(light, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetMapdv(GLenum target, GLenum query, GLdouble* v);
KMETHOD GL_glGetMapdv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum query = PKGInt_to(GLenum, 2);
    GLdouble* v = PKG_Error_to(GLdouble*, 3);

    glGetMapdv(target, query, v);
    RETURNvoid_();
}

//## @Native void GL.glGetMapfv(GLenum target, GLenum query, GLfloat* v);
KMETHOD GL_glGetMapfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum query = PKGInt_to(GLenum, 2);
    GLfloat* v = PKG_Error_to(GLfloat*, 3);

    glGetMapfv(target, query, v);
    RETURNvoid_();
}

//## @Native void GL.glGetMapiv(GLenum target, GLenum query, GLint* v);
KMETHOD GL_glGetMapiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum query = PKGInt_to(GLenum, 2);
    GLint* v = PKG_Error_to(GLint*, 3);

    glGetMapiv(target, query, v);
    RETURNvoid_();
}

//## @Native void GL.glGetMaterialfv(GLenum face, GLenum pname, GLfloat* params);
KMETHOD GL_glGetMaterialfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetMaterialfv(face, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetMaterialiv(GLenum face, GLenum pname, GLint* params);
KMETHOD GL_glGetMaterialiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetMaterialiv(face, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
KMETHOD GL_glGetMinmax(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLboolean reset = PKGInt_to(GLboolean, 2);
    GLenum format = PKGInt_to(GLenum, 3);
    GLenum type = PKGInt_to(GLenum, 4);
    GLvoid* values = PKG_Error_to(GLvoid*, 5);

    glGetMinmax(target, reset, format, type, values);
    RETURNvoid_();
}

//## @Native void GL.glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetMinmaxParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetMinmaxParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetMinmaxParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetMinmaxParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetPixelMapfv(GLenum map, GLfloat* values);
KMETHOD GL_glGetPixelMapfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLfloat* values = PKG_Error_to(GLfloat*, 2);

    glGetPixelMapfv(map, values);
    RETURNvoid_();
}

//## @Native void GL.glGetPixelMapuiv(GLenum map, GLuint* values);
KMETHOD GL_glGetPixelMapuiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLuint* values = PKG_Error_to(GLuint*, 2);

    glGetPixelMapuiv(map, values);
    RETURNvoid_();
}

//## @Native void GL.glGetPixelMapusv(GLenum map, GLushort* values);
KMETHOD GL_glGetPixelMapusv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLushort* values = PKG_Error_to(GLushort*, 2);

    glGetPixelMapusv(map, values);
    RETURNvoid_();
}

//## @Native void GL.glGetPointerv(GLenum pname, GLvoid** params);
KMETHOD GL_glGetPointerv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLvoid** params = PKG_Error_to(GLvoid**, 2);

    glGetPointerv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetPolygonStipple(GLubyte* mask);
KMETHOD GL_glGetPolygonStipple(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* mask = PKG_Error_to(GLubyte*, 1);

    glGetPolygonStipple(mask);
    RETURNvoid_();
}

//## @Native void GL.glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
KMETHOD GL_glGetSeparableFilter(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum format = PKGInt_to(GLenum, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLvoid* row = PKG_Error_to(GLvoid*, 4);
    GLvoid* column = PKG_Error_to(GLvoid*, 5);
    GLvoid* span = PKG_Error_to(GLvoid*, 6);

    glGetSeparableFilter(target, format, type, row, column, span);
    RETURNvoid_();
}

//## @Native GLubyte* GL.glGetString(GLenum name);
KMETHOD GL_glGetString(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum name = PKGInt_to(GLenum, 1);

    const GLubyte* ret = glGetString(name);
    RETURN_error(ret);
}

//## @Native void GL.glGetTexEnvfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetTexEnvfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetTexEnvfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexEnviv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetTexEnviv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetTexEnviv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexGendv(GLenum coord, GLenum pname, GLdouble* params);
KMETHOD GL_glGetTexGendv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glGetTexGendv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexGenfv(GLenum coord, GLenum pname, GLfloat* params);
KMETHOD GL_glGetTexGenfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetTexGenfv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexGeniv(GLenum coord, GLenum pname, GLint* params);
KMETHOD GL_glGetTexGeniv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetTexGeniv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glGetTexImage(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum format = PKGInt_to(GLenum, 3);
    GLenum type = PKGInt_to(GLenum, 4);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 5);

    glGetTexImage(target, level, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
KMETHOD GL_glGetTexLevelParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum pname = PKGInt_to(GLenum, 3);
    GLfloat* params = PKG_Error_to(GLfloat*, 4);

    glGetTexLevelParameterfv(target, level, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
KMETHOD GL_glGetTexLevelParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum pname = PKGInt_to(GLenum, 3);
    GLint* params = PKG_Error_to(GLint*, 4);

    glGetTexLevelParameteriv(target, level, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glGetTexParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetTexParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetTexParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetTexParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glHint(GLenum target, GLenum mode);
KMETHOD GL_glHint(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum mode = PKGInt_to(GLenum, 2);

    glHint(target, mode);
    RETURNvoid_();
}

//## @Native void GL.glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
KMETHOD GL_glHistogram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizei width = PKGInt_to(GLsizei, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLboolean sink = PKGInt_to(GLboolean, 4);

    glHistogram(target, width, internalformat, sink);
    RETURNvoid_();
}

//## @Native void GL.glIndexMask(GLuint mask);
KMETHOD GL_glIndexMask(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint mask = PKGInt_to(GLuint, 1);

    glIndexMask(mask);
    RETURNvoid_();
}

//## @Native void GL.glIndexPointer(GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glIndexPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glIndexPointer(type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glIndexd(GLdouble c);
KMETHOD GL_glIndexd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble c = PKGFloat_to(GLdouble, 1);

    glIndexd(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexdv(GLdouble* c);
KMETHOD GL_glIndexdv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* c = PKG_Error_to(GLdouble*, 1);

    glIndexdv(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexf(GLfloat c);
KMETHOD GL_glIndexf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat c = PKGFloat_to(GLfloat, 1);

    glIndexf(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexfv(GLfloat* c);
KMETHOD GL_glIndexfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* c = PKG_Error_to(GLfloat*, 1);

    glIndexfv(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexi(GLint c);
KMETHOD GL_glIndexi(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint c = PKGInt_to(GLint, 1);

    glIndexi(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexiv(GLint* c);
KMETHOD GL_glIndexiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* c = PKG_Error_to(GLint*, 1);

    glIndexiv(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexs(GLshort c);
KMETHOD GL_glIndexs(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort c = PKGInt_to(GLshort, 1);

    glIndexs(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexsv(GLshort* c);
KMETHOD GL_glIndexsv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* c = PKG_Error_to(GLshort*, 1);

    glIndexsv(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexub(GLubyte c);
KMETHOD GL_glIndexub(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte c = PKGInt_to(GLubyte, 1);

    glIndexub(c);
    RETURNvoid_();
}

//## @Native void GL.glIndexubv(GLubyte* c);
KMETHOD GL_glIndexubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* c = PKG_Error_to(GLubyte*, 1);

    glIndexubv(c);
    RETURNvoid_();
}

//## @Native void GL.glInitNames();
KMETHOD GL_glInitNames(CTX ctx, ksfp_t *sfp _RIX)
{

    glInitNames();
    RETURNvoid_();
}

//## @Native void GL.glInterleavedArrays(GLenum format, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glInterleavedArrays(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum format = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glInterleavedArrays(format, stride, pointer);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsEnabled(GLenum cap);
KMETHOD GL_glIsEnabled(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum cap = PKGInt_to(GLenum, 1);

    GLboolean ret = glIsEnabled(cap);
    RETURNi_(ret);
}

//## @Native GLboolean GL.glIsList(GLuint list);
KMETHOD GL_glIsList(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint list = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsList(list);
    RETURNi_(ret);
}

//## @Native GLboolean GL.glIsTexture(GLuint texture);
KMETHOD GL_glIsTexture(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint texture = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsTexture(texture);
    RETURNi_(ret);
}

//## @Native void GL.glLightModelf(GLenum pname, GLfloat param);
KMETHOD GL_glLightModelf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glLightModelf(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glLightModelfv(GLenum pname, GLfloat* params);
KMETHOD GL_glLightModelfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat* params = PKG_Error_to(GLfloat*, 2);

    glLightModelfv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glLightModeli(GLenum pname, GLint param);
KMETHOD GL_glLightModeli(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glLightModeli(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glLightModeliv(GLenum pname, GLint* params);
KMETHOD GL_glLightModeliv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint* params = PKG_Error_to(GLint*, 2);

    glLightModeliv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glLightf(GLenum light, GLenum pname, GLfloat param);
KMETHOD GL_glLightf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat param = PKGFloat_to(GLfloat, 3);

    glLightf(light, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glLightfv(GLenum light, GLenum pname, GLfloat* params);
KMETHOD GL_glLightfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glLightfv(light, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glLighti(GLenum light, GLenum pname, GLint param);
KMETHOD GL_glLighti(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glLighti(light, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glLightiv(GLenum light, GLenum pname, GLint* params);
KMETHOD GL_glLightiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum light = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glLightiv(light, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glLineStipple(GLint factor, GLushort pattern);
KMETHOD GL_glLineStipple(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint factor = PKGInt_to(GLint, 1);
    GLushort pattern = PKGInt_to(GLushort, 2);

    glLineStipple(factor, pattern);
    RETURNvoid_();
}

//## @Native void GL.glLineWidth(GLfloat width);
KMETHOD GL_glLineWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat width = PKGFloat_to(GLfloat, 1);

    glLineWidth(width);
    RETURNvoid_();
}

//## @Native void GL.glListBase(GLuint base);
KMETHOD GL_glListBase(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint base = PKGInt_to(GLuint, 1);

    glListBase(base);
    RETURNvoid_();
}

//## @Native void GL.glLoadIdentity();
KMETHOD GL_glLoadIdentity(CTX ctx, ksfp_t *sfp _RIX)
{

    glLoadIdentity();
    RETURNvoid_();
}

//## @Native void GL.glLoadMatrixd(GLdouble* m);
KMETHOD GL_glLoadMatrixd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glLoadMatrixd(m);
    RETURNvoid_();
}

//## @Native void GL.glLoadMatrixf(GLfloat* m);
KMETHOD GL_glLoadMatrixf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glLoadMatrixf(m);
    RETURNvoid_();
}

//## @Native void GL.glLoadName(GLuint name);
KMETHOD GL_glLoadName(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint name = PKGInt_to(GLuint, 1);

    glLoadName(name);
    RETURNvoid_();
}

//## @Native void GL.glLogicOp(GLenum opcode);
KMETHOD GL_glLogicOp(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum opcode = PKGInt_to(GLenum, 1);

    glLogicOp(opcode);
    RETURNvoid_();
}

//## @Native void GL.glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble* points);
KMETHOD GL_glMap1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble u1 = PKGFloat_to(GLdouble, 2);
    GLdouble u2 = PKGFloat_to(GLdouble, 3);
    GLint stride = PKGInt_to(GLint, 4);
    GLint order = PKGInt_to(GLint, 5);
    GLdouble* points = PKG_Error_to(GLdouble*, 6);

    glMap1d(target, u1, u2, stride, order, points);
    RETURNvoid_();
}

//## @Native void GL.glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat* points);
KMETHOD GL_glMap1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat u1 = PKGFloat_to(GLfloat, 2);
    GLfloat u2 = PKGFloat_to(GLfloat, 3);
    GLint stride = PKGInt_to(GLint, 4);
    GLint order = PKGInt_to(GLint, 5);
    GLfloat* points = PKG_Error_to(GLfloat*, 6);

    glMap1f(target, u1, u2, stride, order, points);
    RETURNvoid_();
}

//## @Native void GL.glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble* points);
KMETHOD GL_glMap2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble u1 = PKGFloat_to(GLdouble, 2);
    GLdouble u2 = PKGFloat_to(GLdouble, 3);
    GLint ustride = PKGInt_to(GLint, 4);
    GLint uorder = PKGInt_to(GLint, 5);
    GLdouble v1 = PKGFloat_to(GLdouble, 6);
    GLdouble v2 = PKGFloat_to(GLdouble, 7);
    GLint vstride = PKGInt_to(GLint, 8);
    GLint vorder = PKGInt_to(GLint, 9);
    GLdouble* points = PKG_Error_to(GLdouble*, 10);

    glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    RETURNvoid_();
}

//## @Native void GL.glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat* points);
KMETHOD GL_glMap2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat u1 = PKGFloat_to(GLfloat, 2);
    GLfloat u2 = PKGFloat_to(GLfloat, 3);
    GLint ustride = PKGInt_to(GLint, 4);
    GLint uorder = PKGInt_to(GLint, 5);
    GLfloat v1 = PKGFloat_to(GLfloat, 6);
    GLfloat v2 = PKGFloat_to(GLfloat, 7);
    GLint vstride = PKGInt_to(GLint, 8);
    GLint vorder = PKGInt_to(GLint, 9);
    GLfloat* points = PKG_Error_to(GLfloat*, 10);

    glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
    RETURNvoid_();
}

//## @Native void GL.glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
KMETHOD GL_glMapGrid1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint un = PKGInt_to(GLint, 1);
    GLdouble u1 = PKGFloat_to(GLdouble, 2);
    GLdouble u2 = PKGFloat_to(GLdouble, 3);

    glMapGrid1d(un, u1, u2);
    RETURNvoid_();
}

//## @Native void GL.glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
KMETHOD GL_glMapGrid1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint un = PKGInt_to(GLint, 1);
    GLfloat u1 = PKGFloat_to(GLfloat, 2);
    GLfloat u2 = PKGFloat_to(GLfloat, 3);

    glMapGrid1f(un, u1, u2);
    RETURNvoid_();
}

//## @Native void GL.glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
KMETHOD GL_glMapGrid2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint un = PKGInt_to(GLint, 1);
    GLdouble u1 = PKGFloat_to(GLdouble, 2);
    GLdouble u2 = PKGFloat_to(GLdouble, 3);
    GLint vn = PKGInt_to(GLint, 4);
    GLdouble v1 = PKGFloat_to(GLdouble, 5);
    GLdouble v2 = PKGFloat_to(GLdouble, 6);

    glMapGrid2d(un, u1, u2, vn, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
KMETHOD GL_glMapGrid2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint un = PKGInt_to(GLint, 1);
    GLfloat u1 = PKGFloat_to(GLfloat, 2);
    GLfloat u2 = PKGFloat_to(GLfloat, 3);
    GLint vn = PKGInt_to(GLint, 4);
    GLfloat v1 = PKGFloat_to(GLfloat, 5);
    GLfloat v2 = PKGFloat_to(GLfloat, 6);

    glMapGrid2f(un, u1, u2, vn, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glMaterialf(GLenum face, GLenum pname, GLfloat param);
KMETHOD GL_glMaterialf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat param = PKGFloat_to(GLfloat, 3);

    glMaterialf(face, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glMaterialfv(GLenum face, GLenum pname, GLfloat* params);
KMETHOD GL_glMaterialfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glMaterialfv(face, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glMateriali(GLenum face, GLenum pname, GLint param);
KMETHOD GL_glMateriali(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glMateriali(face, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glMaterialiv(GLenum face, GLenum pname, GLint* params);
KMETHOD GL_glMaterialiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glMaterialiv(face, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glMatrixMode(GLenum mode);
KMETHOD GL_glMatrixMode(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glMatrixMode(mode);
    RETURNvoid_();
}

//## @Native void GL.glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
KMETHOD GL_glMinmax(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLboolean sink = PKGInt_to(GLboolean, 3);

    glMinmax(target, internalformat, sink);
    RETURNvoid_();
}

//## @Native void GL.glMultMatrixd(GLdouble* m);
KMETHOD GL_glMultMatrixd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glMultMatrixd(m);
    RETURNvoid_();
}

//## @Native void GL.glMultMatrixf(GLfloat* m);
KMETHOD GL_glMultMatrixf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glMultMatrixf(m);
    RETURNvoid_();
}

//## @Native void GL.glNewList(GLuint list, GLenum mode);
KMETHOD GL_glNewList(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint list = PKGInt_to(GLuint, 1);
    GLenum mode = PKGInt_to(GLenum, 2);

    glNewList(list, mode);
    RETURNvoid_();
}

//## @Native void GL.glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
KMETHOD GL_glNormal3b(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte nx = PKGInt_to(GLbyte, 1);
    GLbyte ny = PKGInt_to(GLbyte, 2);
    GLbyte nz = PKGInt_to(GLbyte, 3);

    glNormal3b(nx, ny, nz);
    RETURNvoid_();
}

//## @Native void GL.glNormal3bv(GLbyte* v);
KMETHOD GL_glNormal3bv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte* v = PKG_Error_to(GLbyte*, 1);

    glNormal3bv(v);
    RETURNvoid_();
}

//## @Native void GL.glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
KMETHOD GL_glNormal3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble nx = PKGFloat_to(GLdouble, 1);
    GLdouble ny = PKGFloat_to(GLdouble, 2);
    GLdouble nz = PKGFloat_to(GLdouble, 3);

    glNormal3d(nx, ny, nz);
    RETURNvoid_();
}

//## @Native void GL.glNormal3dv(GLdouble* v);
KMETHOD GL_glNormal3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glNormal3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
KMETHOD GL_glNormal3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat nx = PKGFloat_to(GLfloat, 1);
    GLfloat ny = PKGFloat_to(GLfloat, 2);
    GLfloat nz = PKGFloat_to(GLfloat, 3);

    glNormal3f(nx, ny, nz);
    RETURNvoid_();
}

//## @Native void GL.glNormal3fv(GLfloat* v);
KMETHOD GL_glNormal3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glNormal3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glNormal3i(GLint nx, GLint ny, GLint nz);
KMETHOD GL_glNormal3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint nx = PKGInt_to(GLint, 1);
    GLint ny = PKGInt_to(GLint, 2);
    GLint nz = PKGInt_to(GLint, 3);

    glNormal3i(nx, ny, nz);
    RETURNvoid_();
}

//## @Native void GL.glNormal3iv(GLint* v);
KMETHOD GL_glNormal3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glNormal3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glNormal3s(GLshort nx, GLshort ny, GLshort nz);
KMETHOD GL_glNormal3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort nx = PKGInt_to(GLshort, 1);
    GLshort ny = PKGInt_to(GLshort, 2);
    GLshort nz = PKGInt_to(GLshort, 3);

    glNormal3s(nx, ny, nz);
    RETURNvoid_();
}

//## @Native void GL.glNormal3sv(GLshort* v);
KMETHOD GL_glNormal3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glNormal3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glNormalPointer(GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glNormalPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glNormalPointer(type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
KMETHOD GL_glOrtho(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble left = PKGFloat_to(GLdouble, 1);
    GLdouble right = PKGFloat_to(GLdouble, 2);
    GLdouble bottom = PKGFloat_to(GLdouble, 3);
    GLdouble top = PKGFloat_to(GLdouble, 4);
    GLdouble zNear = PKGFloat_to(GLdouble, 5);
    GLdouble zFar = PKGFloat_to(GLdouble, 6);

    glOrtho(left, right, bottom, top, zNear, zFar);
    RETURNvoid_();
}

//## @Native void GL.glPassThrough(GLfloat token);
KMETHOD GL_glPassThrough(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat token = PKGFloat_to(GLfloat, 1);

    glPassThrough(token);
    RETURNvoid_();
}

//## @Native void GL.glPixelMapfv(GLenum map, GLint mapsize, GLfloat* values);
KMETHOD GL_glPixelMapfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLint mapsize = PKGInt_to(GLint, 2);
    GLfloat* values = PKG_Error_to(GLfloat*, 3);

    glPixelMapfv(map, mapsize, values);
    RETURNvoid_();
}

//## @Native void GL.glPixelMapuiv(GLenum map, GLint mapsize, GLuint* values);
KMETHOD GL_glPixelMapuiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLint mapsize = PKGInt_to(GLint, 2);
    GLuint* values = PKG_Error_to(GLuint*, 3);

    glPixelMapuiv(map, mapsize, values);
    RETURNvoid_();
}

//## @Native void GL.glPixelMapusv(GLenum map, GLint mapsize, GLushort* values);
KMETHOD GL_glPixelMapusv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum map = PKGInt_to(GLenum, 1);
    GLint mapsize = PKGInt_to(GLint, 2);
    GLushort* values = PKG_Error_to(GLushort*, 3);

    glPixelMapusv(map, mapsize, values);
    RETURNvoid_();
}

//## @Native void GL.glPixelStoref(GLenum pname, GLfloat param);
KMETHOD GL_glPixelStoref(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPixelStoref(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPixelStorei(GLenum pname, GLint param);
KMETHOD GL_glPixelStorei(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPixelStorei(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPixelTransferf(GLenum pname, GLfloat param);
KMETHOD GL_glPixelTransferf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPixelTransferf(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPixelTransferi(GLenum pname, GLint param);
KMETHOD GL_glPixelTransferi(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPixelTransferi(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPixelZoom(GLfloat xfactor, GLfloat yfactor);
KMETHOD GL_glPixelZoom(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat xfactor = PKGFloat_to(GLfloat, 1);
    GLfloat yfactor = PKGFloat_to(GLfloat, 2);

    glPixelZoom(xfactor, yfactor);
    RETURNvoid_();
}

//## @Native void GL.glPointSize(GLfloat size);
KMETHOD GL_glPointSize(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat size = PKGFloat_to(GLfloat, 1);

    glPointSize(size);
    RETURNvoid_();
}

//## @Native void GL.glPolygonMode(GLenum face, GLenum mode);
KMETHOD GL_glPolygonMode(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum mode = PKGInt_to(GLenum, 2);

    glPolygonMode(face, mode);
    RETURNvoid_();
}

//## @Native void GL.glPolygonOffset(GLfloat factor, GLfloat units);
KMETHOD GL_glPolygonOffset(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat factor = PKGFloat_to(GLfloat, 1);
    GLfloat units = PKGFloat_to(GLfloat, 2);

    glPolygonOffset(factor, units);
    RETURNvoid_();
}

//## @Native void GL.glPolygonStipple(GLubyte* mask);
KMETHOD GL_glPolygonStipple(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* mask = PKG_Error_to(GLubyte*, 1);

    glPolygonStipple(mask);
    RETURNvoid_();
}

//## @Native void GL.glPopAttrib();
KMETHOD GL_glPopAttrib(CTX ctx, ksfp_t *sfp _RIX)
{

    glPopAttrib();
    RETURNvoid_();
}

//## @Native void GL.glPopClientAttrib();
KMETHOD GL_glPopClientAttrib(CTX ctx, ksfp_t *sfp _RIX)
{

    glPopClientAttrib();
    RETURNvoid_();
}

//## @Native void GL.glPopMatrix();
KMETHOD GL_glPopMatrix(CTX ctx, ksfp_t *sfp _RIX)
{

    glPopMatrix();
    RETURNvoid_();
}

//## @Native void GL.glPopName();
KMETHOD GL_glPopName(CTX ctx, ksfp_t *sfp _RIX)
{

    glPopName();
    RETURNvoid_();
}

//## @Native void GL.glPrioritizeTextures(GLsizei n, GLuint* textures, GLclampf* priorities);
KMETHOD GL_glPrioritizeTextures(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* textures = PKG_Error_to(GLuint*, 2);
    GLclampf* priorities = PKG_Error_to(GLclampf*, 3);

    glPrioritizeTextures(n, textures, priorities);
    RETURNvoid_();
}

//## @Native void GL.glPushAttrib(GLbitfield mask);
KMETHOD GL_glPushAttrib(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbitfield mask = PKGInt_to(GLbitfield, 1);

    glPushAttrib(mask);
    RETURNvoid_();
}

//## @Native void GL.glPushClientAttrib(GLbitfield mask);
KMETHOD GL_glPushClientAttrib(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbitfield mask = PKGInt_to(GLbitfield, 1);

    glPushClientAttrib(mask);
    RETURNvoid_();
}

//## @Native void GL.glPushMatrix();
KMETHOD GL_glPushMatrix(CTX ctx, ksfp_t *sfp _RIX)
{

    glPushMatrix();
    RETURNvoid_();
}

//## @Native void GL.glPushName(GLuint name);
KMETHOD GL_glPushName(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint name = PKGInt_to(GLuint, 1);

    glPushName(name);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2d(GLdouble x, GLdouble y);
KMETHOD GL_glRasterPos2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);

    glRasterPos2d(x, y);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2dv(GLdouble* v);
KMETHOD GL_glRasterPos2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glRasterPos2dv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2f(GLfloat x, GLfloat y);
KMETHOD GL_glRasterPos2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);

    glRasterPos2f(x, y);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2fv(GLfloat* v);
KMETHOD GL_glRasterPos2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glRasterPos2fv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2i(GLint x, GLint y);
KMETHOD GL_glRasterPos2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);

    glRasterPos2i(x, y);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2iv(GLint* v);
KMETHOD GL_glRasterPos2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glRasterPos2iv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2s(GLshort x, GLshort y);
KMETHOD GL_glRasterPos2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);

    glRasterPos2s(x, y);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos2sv(GLshort* v);
KMETHOD GL_glRasterPos2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glRasterPos2sv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glRasterPos3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glRasterPos3d(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3dv(GLdouble* v);
KMETHOD GL_glRasterPos3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glRasterPos3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glRasterPos3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glRasterPos3f(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3fv(GLfloat* v);
KMETHOD GL_glRasterPos3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glRasterPos3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3i(GLint x, GLint y, GLint z);
KMETHOD GL_glRasterPos3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);

    glRasterPos3i(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3iv(GLint* v);
KMETHOD GL_glRasterPos3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glRasterPos3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3s(GLshort x, GLshort y, GLshort z);
KMETHOD GL_glRasterPos3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);

    glRasterPos3s(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos3sv(GLshort* v);
KMETHOD GL_glRasterPos3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glRasterPos3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glRasterPos4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);
    GLdouble w = PKGFloat_to(GLdouble, 4);

    glRasterPos4d(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4dv(GLdouble* v);
KMETHOD GL_glRasterPos4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glRasterPos4dv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glRasterPos4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);
    GLfloat w = PKGFloat_to(GLfloat, 4);

    glRasterPos4f(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4fv(GLfloat* v);
KMETHOD GL_glRasterPos4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glRasterPos4fv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
KMETHOD GL_glRasterPos4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);
    GLint w = PKGInt_to(GLint, 4);

    glRasterPos4i(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4iv(GLint* v);
KMETHOD GL_glRasterPos4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glRasterPos4iv(v);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
KMETHOD GL_glRasterPos4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);
    GLshort w = PKGInt_to(GLshort, 4);

    glRasterPos4s(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glRasterPos4sv(GLshort* v);
KMETHOD GL_glRasterPos4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glRasterPos4sv(v);
    RETURNvoid_();
}

//## @Native void GL.glReadBuffer(GLenum mode);
KMETHOD GL_glReadBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glReadBuffer(mode);
    RETURNvoid_();
}

//## @Native void GL.glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glReadPixels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 7);

    glReadPixels(x, y, width, height, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
KMETHOD GL_glRectd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x1 = PKGFloat_to(GLdouble, 1);
    GLdouble y1 = PKGFloat_to(GLdouble, 2);
    GLdouble x2 = PKGFloat_to(GLdouble, 3);
    GLdouble y2 = PKGFloat_to(GLdouble, 4);

    glRectd(x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void GL.glRectdv(GLdouble* v1, GLdouble* v2);
KMETHOD GL_glRectdv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v1 = PKG_Error_to(GLdouble*, 1);
    GLdouble* v2 = PKG_Error_to(GLdouble*, 2);

    glRectdv(v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
KMETHOD GL_glRectf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x1 = PKGFloat_to(GLfloat, 1);
    GLfloat y1 = PKGFloat_to(GLfloat, 2);
    GLfloat x2 = PKGFloat_to(GLfloat, 3);
    GLfloat y2 = PKGFloat_to(GLfloat, 4);

    glRectf(x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void GL.glRectfv(GLfloat* v1, GLfloat* v2);
KMETHOD GL_glRectfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v1 = PKG_Error_to(GLfloat*, 1);
    GLfloat* v2 = PKG_Error_to(GLfloat*, 2);

    glRectfv(v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
KMETHOD GL_glRecti(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x1 = PKGInt_to(GLint, 1);
    GLint y1 = PKGInt_to(GLint, 2);
    GLint x2 = PKGInt_to(GLint, 3);
    GLint y2 = PKGInt_to(GLint, 4);

    glRecti(x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void GL.glRectiv(GLint* v1, GLint* v2);
KMETHOD GL_glRectiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v1 = PKG_Error_to(GLint*, 1);
    GLint* v2 = PKG_Error_to(GLint*, 2);

    glRectiv(v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
KMETHOD GL_glRects(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x1 = PKGInt_to(GLshort, 1);
    GLshort y1 = PKGInt_to(GLshort, 2);
    GLshort x2 = PKGInt_to(GLshort, 3);
    GLshort y2 = PKGInt_to(GLshort, 4);

    glRects(x1, y1, x2, y2);
    RETURNvoid_();
}

//## @Native void GL.glRectsv(GLshort* v1, GLshort* v2);
KMETHOD GL_glRectsv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v1 = PKG_Error_to(GLshort*, 1);
    GLshort* v2 = PKG_Error_to(GLshort*, 2);

    glRectsv(v1, v2);
    RETURNvoid_();
}

//## @Native GLint GL.glRenderMode(GLenum mode);
KMETHOD GL_glRenderMode(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    GLint ret = glRenderMode(mode);
    RETURNi_(ret);
}

//## @Native void GL.glResetHistogram(GLenum target);
KMETHOD GL_glResetHistogram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glResetHistogram(target);
    RETURNvoid_();
}

//## @Native void GL.glResetMinmax(GLenum target);
KMETHOD GL_glResetMinmax(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glResetMinmax(target);
    RETURNvoid_();
}

//## @Native void GL.glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glRotated(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble angle = PKGFloat_to(GLdouble, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);
    GLdouble z = PKGFloat_to(GLdouble, 4);

    glRotated(angle, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glRotatef(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat angle = PKGFloat_to(GLfloat, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);
    GLfloat z = PKGFloat_to(GLfloat, 4);

    glRotatef(angle, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glScaled(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glScaled(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glScaled(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glScalef(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glScalef(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glScalef(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
KMETHOD GL_glScissor(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);

    glScissor(x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glSelectBuffer(GLsizei size, GLuint* buffer);
KMETHOD GL_glSelectBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei size = PKGInt_to(GLsizei, 1);
    GLuint* buffer = PKG_Error_to(GLuint*, 2);

    glSelectBuffer(size, buffer);
    RETURNvoid_();
}

//## @Native void GL.glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* row, GLvoid* column);
KMETHOD GL_glSeparableFilter2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum internalformat = PKGInt_to(GLenum, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    GLvoid* row = PKG_Error_to(GLvoid*, 7);
    GLvoid* column = PKG_Error_to(GLvoid*, 8);

    glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);
    RETURNvoid_();
}

//## @Native void GL.glShadeModel(GLenum mode);
KMETHOD GL_glShadeModel(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    glShadeModel(mode);
    RETURNvoid_();
}

//## @Native void GL.glStencilFunc(GLenum func, GLint ref, GLuint mask);
KMETHOD GL_glStencilFunc(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum func = PKGInt_to(GLenum, 1);
    GLint ref = PKGInt_to(GLint, 2);
    GLuint mask = PKGInt_to(GLuint, 3);

    glStencilFunc(func, ref, mask);
    RETURNvoid_();
}

//## @Native void GL.glStencilMask(GLuint mask);
KMETHOD GL_glStencilMask(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint mask = PKGInt_to(GLuint, 1);

    glStencilMask(mask);
    RETURNvoid_();
}

//## @Native void GL.glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
KMETHOD GL_glStencilOp(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum fail = PKGInt_to(GLenum, 1);
    GLenum zfail = PKGInt_to(GLenum, 2);
    GLenum zpass = PKGInt_to(GLenum, 3);

    glStencilOp(fail, zfail, zpass);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1d(GLdouble s);
KMETHOD GL_glTexCoord1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble s = PKGFloat_to(GLdouble, 1);

    glTexCoord1d(s);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1dv(GLdouble* v);
KMETHOD GL_glTexCoord1dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glTexCoord1dv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1f(GLfloat s);
KMETHOD GL_glTexCoord1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat s = PKGFloat_to(GLfloat, 1);

    glTexCoord1f(s);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1fv(GLfloat* v);
KMETHOD GL_glTexCoord1fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glTexCoord1fv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1i(GLint s);
KMETHOD GL_glTexCoord1i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint s = PKGInt_to(GLint, 1);

    glTexCoord1i(s);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1iv(GLint* v);
KMETHOD GL_glTexCoord1iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glTexCoord1iv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1s(GLshort s);
KMETHOD GL_glTexCoord1s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort s = PKGInt_to(GLshort, 1);

    glTexCoord1s(s);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord1sv(GLshort* v);
KMETHOD GL_glTexCoord1sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glTexCoord1sv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2d(GLdouble s, GLdouble t);
KMETHOD GL_glTexCoord2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble s = PKGFloat_to(GLdouble, 1);
    GLdouble t = PKGFloat_to(GLdouble, 2);

    glTexCoord2d(s, t);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2dv(GLdouble* v);
KMETHOD GL_glTexCoord2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glTexCoord2dv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2f(GLfloat s, GLfloat t);
KMETHOD GL_glTexCoord2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat s = PKGFloat_to(GLfloat, 1);
    GLfloat t = PKGFloat_to(GLfloat, 2);

    glTexCoord2f(s, t);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2fv(GLfloat* v);
KMETHOD GL_glTexCoord2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glTexCoord2fv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2i(GLint s, GLint t);
KMETHOD GL_glTexCoord2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint s = PKGInt_to(GLint, 1);
    GLint t = PKGInt_to(GLint, 2);

    glTexCoord2i(s, t);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2iv(GLint* v);
KMETHOD GL_glTexCoord2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glTexCoord2iv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2s(GLshort s, GLshort t);
KMETHOD GL_glTexCoord2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort s = PKGInt_to(GLshort, 1);
    GLshort t = PKGInt_to(GLshort, 2);

    glTexCoord2s(s, t);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord2sv(GLshort* v);
KMETHOD GL_glTexCoord2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glTexCoord2sv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
KMETHOD GL_glTexCoord3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble s = PKGFloat_to(GLdouble, 1);
    GLdouble t = PKGFloat_to(GLdouble, 2);
    GLdouble r = PKGFloat_to(GLdouble, 3);

    glTexCoord3d(s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3dv(GLdouble* v);
KMETHOD GL_glTexCoord3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glTexCoord3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
KMETHOD GL_glTexCoord3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat s = PKGFloat_to(GLfloat, 1);
    GLfloat t = PKGFloat_to(GLfloat, 2);
    GLfloat r = PKGFloat_to(GLfloat, 3);

    glTexCoord3f(s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3fv(GLfloat* v);
KMETHOD GL_glTexCoord3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glTexCoord3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3i(GLint s, GLint t, GLint r);
KMETHOD GL_glTexCoord3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint s = PKGInt_to(GLint, 1);
    GLint t = PKGInt_to(GLint, 2);
    GLint r = PKGInt_to(GLint, 3);

    glTexCoord3i(s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3iv(GLint* v);
KMETHOD GL_glTexCoord3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glTexCoord3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3s(GLshort s, GLshort t, GLshort r);
KMETHOD GL_glTexCoord3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort s = PKGInt_to(GLshort, 1);
    GLshort t = PKGInt_to(GLshort, 2);
    GLshort r = PKGInt_to(GLshort, 3);

    glTexCoord3s(s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord3sv(GLshort* v);
KMETHOD GL_glTexCoord3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glTexCoord3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
KMETHOD GL_glTexCoord4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble s = PKGFloat_to(GLdouble, 1);
    GLdouble t = PKGFloat_to(GLdouble, 2);
    GLdouble r = PKGFloat_to(GLdouble, 3);
    GLdouble q = PKGFloat_to(GLdouble, 4);

    glTexCoord4d(s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4dv(GLdouble* v);
KMETHOD GL_glTexCoord4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glTexCoord4dv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
KMETHOD GL_glTexCoord4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat s = PKGFloat_to(GLfloat, 1);
    GLfloat t = PKGFloat_to(GLfloat, 2);
    GLfloat r = PKGFloat_to(GLfloat, 3);
    GLfloat q = PKGFloat_to(GLfloat, 4);

    glTexCoord4f(s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4fv(GLfloat* v);
KMETHOD GL_glTexCoord4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glTexCoord4fv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
KMETHOD GL_glTexCoord4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint s = PKGInt_to(GLint, 1);
    GLint t = PKGInt_to(GLint, 2);
    GLint r = PKGInt_to(GLint, 3);
    GLint q = PKGInt_to(GLint, 4);

    glTexCoord4i(s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4iv(GLint* v);
KMETHOD GL_glTexCoord4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glTexCoord4iv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
KMETHOD GL_glTexCoord4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort s = PKGInt_to(GLshort, 1);
    GLshort t = PKGInt_to(GLshort, 2);
    GLshort r = PKGInt_to(GLshort, 3);
    GLshort q = PKGInt_to(GLshort, 4);

    glTexCoord4s(s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glTexCoord4sv(GLshort* v);
KMETHOD GL_glTexCoord4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glTexCoord4sv(v);
    RETURNvoid_();
}

//## @Native void GL.glTexCoordPointer(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glTexCoordPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glTexCoordPointer(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glTexEnvf(GLenum target, GLenum pname, GLfloat param);
KMETHOD GL_glTexEnvf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat param = PKGFloat_to(GLfloat, 3);

    glTexEnvf(target, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexEnvfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glTexEnvfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glTexEnvfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexEnvi(GLenum target, GLenum pname, GLint param);
KMETHOD GL_glTexEnvi(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glTexEnvi(target, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexEnviv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glTexEnviv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glTexEnviv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexGend(GLenum coord, GLenum pname, GLdouble param);
KMETHOD GL_glTexGend(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLdouble param = PKGFloat_to(GLdouble, 3);

    glTexGend(coord, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexGendv(GLenum coord, GLenum pname, GLdouble* params);
KMETHOD GL_glTexGendv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glTexGendv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexGenf(GLenum coord, GLenum pname, GLfloat param);
KMETHOD GL_glTexGenf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat param = PKGFloat_to(GLfloat, 3);

    glTexGenf(coord, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexGenfv(GLenum coord, GLenum pname, GLfloat* params);
KMETHOD GL_glTexGenfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glTexGenfv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexGeni(GLenum coord, GLenum pname, GLint param);
KMETHOD GL_glTexGeni(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glTexGeni(coord, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexGeniv(GLenum coord, GLenum pname, GLint* params);
KMETHOD GL_glTexGeniv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum coord = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glTexGeniv(coord, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint internalformat = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLint border = PKGInt_to(GLint, 5);
    GLenum format = PKGInt_to(GLenum, 6);
    GLenum type = PKGInt_to(GLenum, 7);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 8);

    glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint internalformat = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLint border = PKGInt_to(GLint, 6);
    GLenum format = PKGInt_to(GLenum, 7);
    GLenum type = PKGInt_to(GLenum, 8);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 9);

    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexImage3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint internalformat = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLsizei depth = PKGInt_to(GLsizei, 6);
    GLint border = PKGInt_to(GLint, 7);
    GLenum format = PKGInt_to(GLenum, 8);
    GLenum type = PKGInt_to(GLenum, 9);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 10);

    glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTexParameterf(GLenum target, GLenum pname, GLfloat param);
KMETHOD GL_glTexParameterf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat param = PKGFloat_to(GLfloat, 3);

    glTexParameterf(target, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
KMETHOD GL_glTexParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glTexParameterfv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexParameteri(GLenum target, GLenum pname, GLint param);
KMETHOD GL_glTexParameteri(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint param = PKGInt_to(GLint, 3);

    glTexParameteri(target, pname, param);
    RETURNvoid_();
}

//## @Native void GL.glTexParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glTexParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glTexParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexSubImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 7);

    glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexSubImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);
    GLsizei height = PKGInt_to(GLsizei, 6);
    GLenum format = PKGInt_to(GLenum, 7);
    GLenum type = PKGInt_to(GLenum, 8);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 9);

    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid* pixels);
KMETHOD GL_glTexSubImage3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLint zoffset = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);
    GLsizei height = PKGInt_to(GLsizei, 7);
    GLsizei depth = PKGInt_to(GLsizei, 8);
    GLenum format = PKGInt_to(GLenum, 9);
    GLenum type = PKGInt_to(GLenum, 10);
    GLvoid* pixels = PKG_Error_to(GLvoid*, 11);

    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    RETURNvoid_();
}

//## @Native void GL.glTranslated(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glTranslated(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glTranslated(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glTranslatef(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glTranslatef(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glTranslatef(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertex2d(GLdouble x, GLdouble y);
KMETHOD GL_glVertex2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);

    glVertex2d(x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertex2dv(GLdouble* v);
KMETHOD GL_glVertex2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glVertex2dv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex2f(GLfloat x, GLfloat y);
KMETHOD GL_glVertex2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);

    glVertex2f(x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertex2fv(GLfloat* v);
KMETHOD GL_glVertex2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glVertex2fv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex2i(GLint x, GLint y);
KMETHOD GL_glVertex2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);

    glVertex2i(x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertex2iv(GLint* v);
KMETHOD GL_glVertex2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glVertex2iv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex2s(GLshort x, GLshort y);
KMETHOD GL_glVertex2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);

    glVertex2s(x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertex2sv(GLshort* v);
KMETHOD GL_glVertex2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glVertex2sv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex3d(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glVertex3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glVertex3d(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertex3dv(GLdouble* v);
KMETHOD GL_glVertex3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glVertex3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex3f(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glVertex3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glVertex3f(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertex3fv(GLfloat* v);
KMETHOD GL_glVertex3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glVertex3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex3i(GLint x, GLint y, GLint z);
KMETHOD GL_glVertex3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);

    glVertex3i(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertex3iv(GLint* v);
KMETHOD GL_glVertex3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glVertex3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex3s(GLshort x, GLshort y, GLshort z);
KMETHOD GL_glVertex3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);

    glVertex3s(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertex3sv(GLshort* v);
KMETHOD GL_glVertex3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glVertex3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glVertex4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);
    GLdouble w = PKGFloat_to(GLdouble, 4);

    glVertex4d(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertex4dv(GLdouble* v);
KMETHOD GL_glVertex4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glVertex4dv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glVertex4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);
    GLfloat w = PKGFloat_to(GLfloat, 4);

    glVertex4f(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertex4fv(GLfloat* v);
KMETHOD GL_glVertex4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glVertex4fv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex4i(GLint x, GLint y, GLint z, GLint w);
KMETHOD GL_glVertex4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);
    GLint w = PKGInt_to(GLint, 4);

    glVertex4i(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertex4iv(GLint* v);
KMETHOD GL_glVertex4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glVertex4iv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
KMETHOD GL_glVertex4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);
    GLshort w = PKGInt_to(GLshort, 4);

    glVertex4s(x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertex4sv(GLshort* v);
KMETHOD GL_glVertex4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glVertex4sv(v);
    RETURNvoid_();
}

//## @Native void GL.glVertexPointer(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glVertexPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glVertexPointer(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
KMETHOD GL_glViewport(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);

    glViewport(x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glSampleCoverage(GLclampf value, GLboolean invert);
KMETHOD GL_glSampleCoverage(CTX ctx, ksfp_t *sfp _RIX)
{
    GLclampf value = PKGFloat_to(GLclampf, 1);
    GLboolean invert = PKGInt_to(GLboolean, 2);

    glSampleCoverage(value, invert);
    RETURNvoid_();
}

//## @Native void GL.glLoadTransposeMatrixf(GLfloat* m);
KMETHOD GL_glLoadTransposeMatrixf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glLoadTransposeMatrixf(m);
    RETURNvoid_();
}

//## @Native void GL.glLoadTransposeMatrixd(GLdouble* m);
KMETHOD GL_glLoadTransposeMatrixd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glLoadTransposeMatrixd(m);
    RETURNvoid_();
}

//## @Native void GL.glMultTransposeMatrixf(GLfloat* m);
KMETHOD GL_glMultTransposeMatrixf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* m = PKG_Error_to(GLfloat*, 1);

    glMultTransposeMatrixf(m);
    RETURNvoid_();
}

//## @Native void GL.glMultTransposeMatrixd(GLdouble* m);
KMETHOD GL_glMultTransposeMatrixd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* m = PKG_Error_to(GLdouble*, 1);

    glMultTransposeMatrixd(m);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLsizei depth = PKGInt_to(GLsizei, 6);
    GLint border = PKGInt_to(GLint, 7);
    GLsizei imageSize = PKGInt_to(GLsizei, 8);
    GLvoid* data = PKG_Error_to(GLvoid*, 9);

    glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLsizei height = PKGInt_to(GLsizei, 5);
    GLint border = PKGInt_to(GLint, 6);
    GLsizei imageSize = PKGInt_to(GLsizei, 7);
    GLvoid* data = PKG_Error_to(GLvoid*, 8);

    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLenum internalformat = PKGInt_to(GLenum, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLint border = PKGInt_to(GLint, 5);
    GLsizei imageSize = PKGInt_to(GLsizei, 6);
    GLvoid* data = PKG_Error_to(GLvoid*, 7);

    glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage3D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLint zoffset = PKGInt_to(GLint, 5);
    GLsizei width = PKGInt_to(GLsizei, 6);
    GLsizei height = PKGInt_to(GLsizei, 7);
    GLsizei depth = PKGInt_to(GLsizei, 8);
    GLenum format = PKGInt_to(GLenum, 9);
    GLsizei imageSize = PKGInt_to(GLsizei, 10);
    GLvoid* data = PKG_Error_to(GLvoid*, 11);

    glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLint yoffset = PKGInt_to(GLint, 4);
    GLsizei width = PKGInt_to(GLsizei, 5);
    GLsizei height = PKGInt_to(GLsizei, 6);
    GLenum format = PKGInt_to(GLenum, 7);
    GLsizei imageSize = PKGInt_to(GLsizei, 8);
    GLvoid* data = PKG_Error_to(GLvoid*, 9);

    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid* data);
KMETHOD GL_glCompressedTexSubImage1D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint level = PKGInt_to(GLint, 2);
    GLint xoffset = PKGInt_to(GLint, 3);
    GLsizei width = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLsizei imageSize = PKGInt_to(GLsizei, 6);
    GLvoid* data = PKG_Error_to(GLvoid*, 7);

    glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
    RETURNvoid_();
}

//## @Native void GL.glGetCompressedTexImage(GLenum target, GLint lod, GLvoid* img);
KMETHOD GL_glGetCompressedTexImage(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint lod = PKGInt_to(GLint, 2);
    GLvoid* img = PKG_Error_to(GLvoid*, 3);

    glGetCompressedTexImage(target, lod, img);
    RETURNvoid_();
}

//## @Native void GL.glActiveTexture(GLenum texture);
KMETHOD GL_glActiveTexture(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum texture = PKGInt_to(GLenum, 1);

    glActiveTexture(texture);
    RETURNvoid_();
}

//## @Native void GL.glClientActiveTexture(GLenum texture);
KMETHOD GL_glClientActiveTexture(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum texture = PKGInt_to(GLenum, 1);

    glClientActiveTexture(texture);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1d(GLenum target, GLdouble s);
KMETHOD GL_glMultiTexCoord1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);

    glMultiTexCoord1d(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1dv(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord1dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord1dv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1f(GLenum target, GLfloat s);
KMETHOD GL_glMultiTexCoord1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);

    glMultiTexCoord1f(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1fv(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord1fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord1fv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1i(GLenum target, GLint s);
KMETHOD GL_glMultiTexCoord1i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);

    glMultiTexCoord1i(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1iv(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord1iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord1iv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1s(GLenum target, GLshort s);
KMETHOD GL_glMultiTexCoord1s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);

    glMultiTexCoord1s(target, s);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord1sv(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord1sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord1sv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
KMETHOD GL_glMultiTexCoord2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);

    glMultiTexCoord2d(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2dv(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord2dv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
KMETHOD GL_glMultiTexCoord2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);

    glMultiTexCoord2f(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2fv(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord2fv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2i(GLenum target, GLint s, GLint t);
KMETHOD GL_glMultiTexCoord2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);

    glMultiTexCoord2i(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2iv(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord2iv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
KMETHOD GL_glMultiTexCoord2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);

    glMultiTexCoord2s(target, s, t);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord2sv(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord2sv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
KMETHOD GL_glMultiTexCoord3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);
    GLdouble r = PKGFloat_to(GLdouble, 4);

    glMultiTexCoord3d(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3dv(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord3dv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
KMETHOD GL_glMultiTexCoord3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);
    GLfloat r = PKGFloat_to(GLfloat, 4);

    glMultiTexCoord3f(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3fv(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord3fv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
KMETHOD GL_glMultiTexCoord3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);
    GLint r = PKGInt_to(GLint, 4);

    glMultiTexCoord3i(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3iv(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord3iv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
KMETHOD GL_glMultiTexCoord3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);
    GLshort r = PKGInt_to(GLshort, 4);

    glMultiTexCoord3s(target, s, t, r);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord3sv(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord3sv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
KMETHOD GL_glMultiTexCoord4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble s = PKGFloat_to(GLdouble, 2);
    GLdouble t = PKGFloat_to(GLdouble, 3);
    GLdouble r = PKGFloat_to(GLdouble, 4);
    GLdouble q = PKGFloat_to(GLdouble, 5);

    glMultiTexCoord4d(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4dv(GLenum target, GLdouble* v);
KMETHOD GL_glMultiTexCoord4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glMultiTexCoord4dv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
KMETHOD GL_glMultiTexCoord4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat s = PKGFloat_to(GLfloat, 2);
    GLfloat t = PKGFloat_to(GLfloat, 3);
    GLfloat r = PKGFloat_to(GLfloat, 4);
    GLfloat q = PKGFloat_to(GLfloat, 5);

    glMultiTexCoord4f(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4fv(GLenum target, GLfloat* v);
KMETHOD GL_glMultiTexCoord4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glMultiTexCoord4fv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
KMETHOD GL_glMultiTexCoord4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint s = PKGInt_to(GLint, 2);
    GLint t = PKGInt_to(GLint, 3);
    GLint r = PKGInt_to(GLint, 4);
    GLint q = PKGInt_to(GLint, 5);

    glMultiTexCoord4i(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4iv(GLenum target, GLint* v);
KMETHOD GL_glMultiTexCoord4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glMultiTexCoord4iv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
KMETHOD GL_glMultiTexCoord4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort s = PKGInt_to(GLshort, 2);
    GLshort t = PKGInt_to(GLshort, 3);
    GLshort r = PKGInt_to(GLshort, 4);
    GLshort q = PKGInt_to(GLshort, 5);

    glMultiTexCoord4s(target, s, t, r, q);
    RETURNvoid_();
}

//## @Native void GL.glMultiTexCoord4sv(GLenum target, GLshort* v);
KMETHOD GL_glMultiTexCoord4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glMultiTexCoord4sv(target, v);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordf(GLfloat coord);
KMETHOD GL_glFogCoordf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat coord = PKGFloat_to(GLfloat, 1);

    glFogCoordf(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordfv(GLfloat* coord);
KMETHOD GL_glFogCoordfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* coord = PKG_Error_to(GLfloat*, 1);

    glFogCoordfv(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordd(GLdouble coord);
KMETHOD GL_glFogCoordd(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble coord = PKGFloat_to(GLdouble, 1);

    glFogCoordd(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoorddv(GLdouble* coord);
KMETHOD GL_glFogCoorddv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* coord = PKG_Error_to(GLdouble*, 1);

    glFogCoorddv(coord);
    RETURNvoid_();
}

//## @Native void GL.glFogCoordPointer(GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glFogCoordPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);
    GLsizei stride = PKGInt_to(GLsizei, 2);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 3);

    glFogCoordPointer(type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
KMETHOD GL_glSecondaryColor3b(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte red = PKGInt_to(GLbyte, 1);
    GLbyte green = PKGInt_to(GLbyte, 2);
    GLbyte blue = PKGInt_to(GLbyte, 3);

    glSecondaryColor3b(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3bv(GLbyte* v);
KMETHOD GL_glSecondaryColor3bv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLbyte* v = PKG_Error_to(GLbyte*, 1);

    glSecondaryColor3bv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
KMETHOD GL_glSecondaryColor3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble red = PKGFloat_to(GLdouble, 1);
    GLdouble green = PKGFloat_to(GLdouble, 2);
    GLdouble blue = PKGFloat_to(GLdouble, 3);

    glSecondaryColor3d(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3dv(GLdouble* v);
KMETHOD GL_glSecondaryColor3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glSecondaryColor3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
KMETHOD GL_glSecondaryColor3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat red = PKGFloat_to(GLfloat, 1);
    GLfloat green = PKGFloat_to(GLfloat, 2);
    GLfloat blue = PKGFloat_to(GLfloat, 3);

    glSecondaryColor3f(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3fv(GLfloat* v);
KMETHOD GL_glSecondaryColor3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glSecondaryColor3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3i(GLint red, GLint green, GLint blue);
KMETHOD GL_glSecondaryColor3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint red = PKGInt_to(GLint, 1);
    GLint green = PKGInt_to(GLint, 2);
    GLint blue = PKGInt_to(GLint, 3);

    glSecondaryColor3i(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3iv(GLint* v);
KMETHOD GL_glSecondaryColor3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glSecondaryColor3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
KMETHOD GL_glSecondaryColor3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort red = PKGInt_to(GLshort, 1);
    GLshort green = PKGInt_to(GLshort, 2);
    GLshort blue = PKGInt_to(GLshort, 3);

    glSecondaryColor3s(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3sv(GLshort* v);
KMETHOD GL_glSecondaryColor3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glSecondaryColor3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
KMETHOD GL_glSecondaryColor3ub(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte red = PKGInt_to(GLubyte, 1);
    GLubyte green = PKGInt_to(GLubyte, 2);
    GLubyte blue = PKGInt_to(GLubyte, 3);

    glSecondaryColor3ub(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ubv(GLubyte* v);
KMETHOD GL_glSecondaryColor3ubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* v = PKG_Error_to(GLubyte*, 1);

    glSecondaryColor3ubv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
KMETHOD GL_glSecondaryColor3ui(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint red = PKGInt_to(GLuint, 1);
    GLuint green = PKGInt_to(GLuint, 2);
    GLuint blue = PKGInt_to(GLuint, 3);

    glSecondaryColor3ui(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3uiv(GLuint* v);
KMETHOD GL_glSecondaryColor3uiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint* v = PKG_Error_to(GLuint*, 1);

    glSecondaryColor3uiv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
KMETHOD GL_glSecondaryColor3us(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort red = PKGInt_to(GLushort, 1);
    GLushort green = PKGInt_to(GLushort, 2);
    GLushort blue = PKGInt_to(GLushort, 3);

    glSecondaryColor3us(red, green, blue);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColor3usv(GLushort* v);
KMETHOD GL_glSecondaryColor3usv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLushort* v = PKG_Error_to(GLushort*, 1);

    glSecondaryColor3usv(v);
    RETURNvoid_();
}

//## @Native void GL.glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glSecondaryColorPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint size = PKGInt_to(GLint, 1);
    GLenum type = PKGInt_to(GLenum, 2);
    GLsizei stride = PKGInt_to(GLsizei, 3);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 4);

    glSecondaryColorPointer(size, type, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glPointParameterf(GLenum pname, GLfloat param);
KMETHOD GL_glPointParameterf(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat param = PKGFloat_to(GLfloat, 2);

    glPointParameterf(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPointParameterfv(GLenum pname, GLfloat* params);
KMETHOD GL_glPointParameterfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLfloat* params = PKG_Error_to(GLfloat*, 2);

    glPointParameterfv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glPointParameteri(GLenum pname, GLint param);
KMETHOD GL_glPointParameteri(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint param = PKGInt_to(GLint, 2);

    glPointParameteri(pname, param);
    RETURNvoid_();
}

//## @Native void GL.glPointParameteriv(GLenum pname, GLint* params);
KMETHOD GL_glPointParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum pname = PKGInt_to(GLenum, 1);
    GLint* params = PKG_Error_to(GLint*, 2);

    glPointParameteriv(pname, params);
    RETURNvoid_();
}

//## @Native void GL.glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
KMETHOD GL_glBlendFuncSeparate(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum srcRGB = PKGInt_to(GLenum, 1);
    GLenum dstRGB = PKGInt_to(GLenum, 2);
    GLenum srcAlpha = PKGInt_to(GLenum, 3);
    GLenum dstAlpha = PKGInt_to(GLenum, 4);

    glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
KMETHOD GL_glMultiDrawArrays(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLint* first = PKG_Error_to(GLint*, 2);
    GLsizei* count = PKG_Error_to(GLsizei*, 3);
    GLsizei primcount = PKGInt_to(GLsizei, 4);

    glMultiDrawArrays(mode, first, count, primcount);
    RETURNvoid_();
}

//## @Native void GL.glMultiDrawElements(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount);
KMETHOD GL_glMultiDrawElements(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);
    GLsizei* count = PKG_Error_to(GLsizei*, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    const GLvoid** indices = PKG_Error_to(const GLvoid**, 4);
    GLsizei primcount = PKGInt_to(GLsizei, 5);

    glMultiDrawElements(mode, count, type, indices, primcount);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2d(GLdouble x, GLdouble y);
KMETHOD GL_glWindowPos2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);

    glWindowPos2d(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2dv(GLdouble* v);
KMETHOD GL_glWindowPos2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glWindowPos2dv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2f(GLfloat x, GLfloat y);
KMETHOD GL_glWindowPos2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);

    glWindowPos2f(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2fv(GLfloat* v);
KMETHOD GL_glWindowPos2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glWindowPos2fv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2i(GLint x, GLint y);
KMETHOD GL_glWindowPos2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);

    glWindowPos2i(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2iv(GLint* v);
KMETHOD GL_glWindowPos2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glWindowPos2iv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2s(GLshort x, GLshort y);
KMETHOD GL_glWindowPos2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);

    glWindowPos2s(x, y);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos2sv(GLshort* v);
KMETHOD GL_glWindowPos2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glWindowPos2sv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glWindowPos3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble z = PKGFloat_to(GLdouble, 3);

    glWindowPos3d(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3dv(GLdouble* v);
KMETHOD GL_glWindowPos3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble* v = PKG_Error_to(GLdouble*, 1);

    glWindowPos3dv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glWindowPos3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat x = PKGFloat_to(GLfloat, 1);
    GLfloat y = PKGFloat_to(GLfloat, 2);
    GLfloat z = PKGFloat_to(GLfloat, 3);

    glWindowPos3f(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3fv(GLfloat* v);
KMETHOD GL_glWindowPos3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLfloat* v = PKG_Error_to(GLfloat*, 1);

    glWindowPos3fv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3i(GLint x, GLint y, GLint z);
KMETHOD GL_glWindowPos3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint x = PKGInt_to(GLint, 1);
    GLint y = PKGInt_to(GLint, 2);
    GLint z = PKGInt_to(GLint, 3);

    glWindowPos3i(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3iv(GLint* v);
KMETHOD GL_glWindowPos3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint* v = PKG_Error_to(GLint*, 1);

    glWindowPos3iv(v);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3s(GLshort x, GLshort y, GLshort z);
KMETHOD GL_glWindowPos3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort x = PKGInt_to(GLshort, 1);
    GLshort y = PKGInt_to(GLshort, 2);
    GLshort z = PKGInt_to(GLshort, 3);

    glWindowPos3s(x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glWindowPos3sv(GLshort* v);
KMETHOD GL_glWindowPos3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLshort* v = PKG_Error_to(GLshort*, 1);

    glWindowPos3sv(v);
    RETURNvoid_();
}

//## @Native void GL.glGenQueries(GLsizei n, GLuint* ids);
KMETHOD GL_glGenQueries(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glGenQueries(n, ids);
    RETURNvoid_();
}

//## @Native void GL.glDeleteQueries(GLsizei n, GLuint* ids);
KMETHOD GL_glDeleteQueries(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* ids = PKG_Error_to(GLuint*, 2);

    glDeleteQueries(n, ids);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsQuery(GLuint id);
KMETHOD GL_glIsQuery(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsQuery(id);
    RETURNi_(ret);
}

//## @Native void GL.glBeginQuery(GLenum target, GLuint id);
KMETHOD GL_glBeginQuery(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint id = PKGInt_to(GLuint, 2);

    glBeginQuery(target, id);
    RETURNvoid_();
}

//## @Native void GL.glEndQuery(GLenum target);
KMETHOD GL_glEndQuery(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    glEndQuery(target);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryiv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetQueryiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetQueryiv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
KMETHOD GL_glGetQueryObjectiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetQueryObjectiv(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
KMETHOD GL_glGetQueryObjectuiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint id = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLuint* params = PKG_Error_to(GLuint*, 3);

    glGetQueryObjectuiv(id, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glBindBuffer(GLenum target, GLuint buffer);
KMETHOD GL_glBindBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLuint buffer = PKGInt_to(GLuint, 2);

    glBindBuffer(target, buffer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteBuffers(GLsizei n, GLuint* buffers);
KMETHOD GL_glDeleteBuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* buffers = PKG_Error_to(GLuint*, 2);

    glDeleteBuffers(n, buffers);
    RETURNvoid_();
}

//## @Native void GL.glGenBuffers(GLsizei n, GLuint* buffers);
KMETHOD GL_glGenBuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLuint* buffers = PKG_Error_to(GLuint*, 2);

    glGenBuffers(n, buffers);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsBuffer(GLuint buffer);
KMETHOD GL_glIsBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint buffer = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsBuffer(buffer);
    RETURNi_(ret);
}

//## @Native void GL.glBufferData(GLenum target, GLsizeiptr size, GLvoid* data, GLenum usage);
KMETHOD GL_glBufferData(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLsizeiptr size = PKGInt_to(GLsizeiptr, 2);
    GLvoid* data = PKG_Error_to(GLvoid*, 3);
    GLenum usage = PKGInt_to(GLenum, 4);

    glBufferData(target, size, data, usage);
    RETURNvoid_();
}

//## @Native void GL.glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
KMETHOD GL_glBufferSubData(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLintptr offset = PKGInt_to(GLintptr, 2);
    GLsizeiptr size = PKGInt_to(GLsizeiptr, 3);
    GLvoid* data = PKG_Error_to(GLvoid*, 4);

    glBufferSubData(target, offset, size, data);
    RETURNvoid_();
}

//## @Native void GL.glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
KMETHOD GL_glGetBufferSubData(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLintptr offset = PKGInt_to(GLintptr, 2);
    GLsizeiptr size = PKGInt_to(GLsizeiptr, 3);
    GLvoid* data = PKG_Error_to(GLvoid*, 4);

    glGetBufferSubData(target, offset, size, data);
    RETURNvoid_();
}

//## @Native GLvoid* GL.glMapBuffer(GLenum target, GLenum access);
KMETHOD GL_glMapBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum access = PKGInt_to(GLenum, 2);

    GLvoid* ret = glMapBuffer(target, access);
    RETURN_error(ret);
}

//## @Native GLboolean GL.glUnmapBuffer(GLenum target);
KMETHOD GL_glUnmapBuffer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);

    GLboolean ret = glUnmapBuffer(target);
    RETURNi_(ret);
}

//## @Native void GL.glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
KMETHOD GL_glGetBufferParameteriv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetBufferParameteriv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetBufferPointerv(GLenum target, GLenum pname, GLvoid** params);
KMETHOD GL_glGetBufferPointerv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid** params = PKG_Error_to(GLvoid**, 3);

    glGetBufferPointerv(target, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glDrawBuffers(GLsizei n, GLenum* bufs);
KMETHOD GL_glDrawBuffers(CTX ctx, ksfp_t *sfp _RIX)
{
    GLsizei n = PKGInt_to(GLsizei, 1);
    GLenum* bufs = PKG_Error_to(GLenum*, 2);

    glDrawBuffers(n, bufs);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1d(GLuint index, GLdouble x);
KMETHOD GL_glVertexAttrib1d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);

    glVertexAttrib1d(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1dv(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib1dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib1dv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1f(GLuint index, GLfloat x);
KMETHOD GL_glVertexAttrib1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);

    glVertexAttrib1f(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1fv(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib1fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib1fv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1s(GLuint index, GLshort x);
KMETHOD GL_glVertexAttrib1s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);

    glVertexAttrib1s(index, x);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib1sv(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib1sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib1sv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
KMETHOD GL_glVertexAttrib2d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);

    glVertexAttrib2d(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2dv(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib2dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib2dv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
KMETHOD GL_glVertexAttrib2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);

    glVertexAttrib2f(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2fv(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib2fv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
KMETHOD GL_glVertexAttrib2s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);

    glVertexAttrib2s(index, x, y);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib2sv(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib2sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib2sv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
KMETHOD GL_glVertexAttrib3d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);
    GLdouble z = PKGFloat_to(GLdouble, 4);

    glVertexAttrib3d(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3dv(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib3dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib3dv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
KMETHOD GL_glVertexAttrib3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);
    GLfloat z = PKGFloat_to(GLfloat, 4);

    glVertexAttrib3f(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3fv(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib3fv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
KMETHOD GL_glVertexAttrib3s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);
    GLshort z = PKGInt_to(GLshort, 4);

    glVertexAttrib3s(index, x, y, z);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib3sv(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib3sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib3sv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nbv(GLuint index, GLbyte* v);
KMETHOD GL_glVertexAttrib4Nbv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLbyte* v = PKG_Error_to(GLbyte*, 2);

    glVertexAttrib4Nbv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Niv(GLuint index, GLint* v);
KMETHOD GL_glVertexAttrib4Niv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttrib4Niv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nsv(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib4Nsv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib4Nsv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
KMETHOD GL_glVertexAttrib4Nub(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte x = PKGInt_to(GLubyte, 2);
    GLubyte y = PKGInt_to(GLubyte, 3);
    GLubyte z = PKGInt_to(GLubyte, 4);
    GLubyte w = PKGInt_to(GLubyte, 5);

    glVertexAttrib4Nub(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nubv(GLuint index, GLubyte* v);
KMETHOD GL_glVertexAttrib4Nubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte* v = PKG_Error_to(GLubyte*, 2);

    glVertexAttrib4Nubv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nuiv(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttrib4Nuiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttrib4Nuiv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4Nusv(GLuint index, GLushort* v);
KMETHOD GL_glVertexAttrib4Nusv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLushort* v = PKG_Error_to(GLushort*, 2);

    glVertexAttrib4Nusv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4bv(GLuint index, GLbyte* v);
KMETHOD GL_glVertexAttrib4bv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLbyte* v = PKG_Error_to(GLbyte*, 2);

    glVertexAttrib4bv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
KMETHOD GL_glVertexAttrib4d(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble x = PKGFloat_to(GLdouble, 2);
    GLdouble y = PKGFloat_to(GLdouble, 3);
    GLdouble z = PKGFloat_to(GLdouble, 4);
    GLdouble w = PKGFloat_to(GLdouble, 5);

    glVertexAttrib4d(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4dv(GLuint index, GLdouble* v);
KMETHOD GL_glVertexAttrib4dv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLdouble* v = PKG_Error_to(GLdouble*, 2);

    glVertexAttrib4dv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD GL_glVertexAttrib4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat x = PKGFloat_to(GLfloat, 2);
    GLfloat y = PKGFloat_to(GLfloat, 3);
    GLfloat z = PKGFloat_to(GLfloat, 4);
    GLfloat w = PKGFloat_to(GLfloat, 5);

    glVertexAttrib4f(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4fv(GLuint index, GLfloat* v);
KMETHOD GL_glVertexAttrib4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLfloat* v = PKG_Error_to(GLfloat*, 2);

    glVertexAttrib4fv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4iv(GLuint index, GLint* v);
KMETHOD GL_glVertexAttrib4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint* v = PKG_Error_to(GLint*, 2);

    glVertexAttrib4iv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
KMETHOD GL_glVertexAttrib4s(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort x = PKGInt_to(GLshort, 2);
    GLshort y = PKGInt_to(GLshort, 3);
    GLshort z = PKGInt_to(GLshort, 4);
    GLshort w = PKGInt_to(GLshort, 5);

    glVertexAttrib4s(index, x, y, z, w);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4sv(GLuint index, GLshort* v);
KMETHOD GL_glVertexAttrib4sv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLshort* v = PKG_Error_to(GLshort*, 2);

    glVertexAttrib4sv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4ubv(GLuint index, GLubyte* v);
KMETHOD GL_glVertexAttrib4ubv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLubyte* v = PKG_Error_to(GLubyte*, 2);

    glVertexAttrib4ubv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4uiv(GLuint index, GLuint* v);
KMETHOD GL_glVertexAttrib4uiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLuint* v = PKG_Error_to(GLuint*, 2);

    glVertexAttrib4uiv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttrib4usv(GLuint index, GLushort* v);
KMETHOD GL_glVertexAttrib4usv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLushort* v = PKG_Error_to(GLushort*, 2);

    glVertexAttrib4usv(index, v);
    RETURNvoid_();
}

//## @Native void GL.glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
KMETHOD GL_glVertexAttribPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLint size = PKGInt_to(GLint, 2);
    GLenum type = PKGInt_to(GLenum, 3);
    GLboolean normalized = PKGInt_to(GLboolean, 4);
    GLsizei stride = PKGInt_to(GLsizei, 5);
    GLvoid* pointer = PKG_Error_to(GLvoid*, 6);

    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    RETURNvoid_();
}

//## @Native void GL.glEnableVertexAttribArray(GLuint index);
KMETHOD GL_glEnableVertexAttribArray(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);

    glEnableVertexAttribArray(index);
    RETURNvoid_();
}

//## @Native void GL.glDisableVertexAttribArray(GLuint index);
KMETHOD GL_glDisableVertexAttribArray(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);

    glDisableVertexAttribArray(index);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
KMETHOD GL_glGetVertexAttribdv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLdouble* params = PKG_Error_to(GLdouble*, 3);

    glGetVertexAttribdv(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
KMETHOD GL_glGetVertexAttribfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetVertexAttribfv(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
KMETHOD GL_glGetVertexAttribiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetVertexAttribiv(index, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid** pointer);
KMETHOD GL_glGetVertexAttribPointerv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint index = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLvoid** pointer = PKG_Error_to(GLvoid**, 3);

    glGetVertexAttribPointerv(index, pname, pointer);
    RETURNvoid_();
}

//## @Native void GL.glDeleteShader(GLuint shader);
KMETHOD GL_glDeleteShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);

    glDeleteShader(shader);
    RETURNvoid_();
}

//## @Native void GL.glDetachShader(GLuint program, GLuint shader);
KMETHOD GL_glDetachShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint shader = PKGInt_to(GLuint, 2);

    glDetachShader(program, shader);
    RETURNvoid_();
}

//## @Native GLuint GL.glCreateShader(GLenum type);
KMETHOD GL_glCreateShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);

    GLuint ret = glCreateShader(type);
    RETURNi_(ret);
}

//## @Native void GL.glShaderSource(GLuint shader, GLsizei count, GLchar** string, GLint* length);
KMETHOD GL_glShaderSource(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    const GLchar** string = PKG_Error_to(const GLchar**, 3);
    GLint* length = PKG_Error_to(GLint*, 4);

    glShaderSource(shader, count, string, length);
    RETURNvoid_();
}

//## @Native void GL.glCompileShader(GLuint shader);
KMETHOD GL_glCompileShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);

    glCompileShader(shader);
    RETURNvoid_();
}

//## @Native GLuint GL.glCreateProgram();
KMETHOD GL_glCreateProgram(CTX ctx, ksfp_t *sfp _RIX)
{

    GLuint ret = glCreateProgram();
    RETURNi_(ret);
}

//## @Native void GL.glAttachShader(GLuint program, GLuint shader);
KMETHOD GL_glAttachShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint shader = PKGInt_to(GLuint, 2);

    glAttachShader(program, shader);
    RETURNvoid_();
}

//## @Native void GL.glLinkProgram(GLuint program);
KMETHOD GL_glLinkProgram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    glLinkProgram(program);
    RETURNvoid_();
}

//## @Native void GL.glUseProgram(GLuint program);
KMETHOD GL_glUseProgram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    glUseProgram(program);
    RETURNvoid_();
}

//## @Native void GL.glDeleteProgram(GLuint program);
KMETHOD GL_glDeleteProgram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    glDeleteProgram(program);
    RETURNvoid_();
}

//## @Native void GL.glValidateProgram(GLuint program);
KMETHOD GL_glValidateProgram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    glValidateProgram(program);
    RETURNvoid_();
}

//## @Native void GL.glUniform1f(GLint location, GLfloat v0);
KMETHOD GL_glUniform1f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);

    glUniform1f(location, v0);
    RETURNvoid_();
}

//## @Native void GL.glUniform2f(GLint location, GLfloat v0, GLfloat v1);
KMETHOD GL_glUniform2f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);

    glUniform2f(location, v0, v1);
    RETURNvoid_();
}

//## @Native void GL.glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
KMETHOD GL_glUniform3f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);
    GLfloat v2 = PKGFloat_to(GLfloat, 4);

    glUniform3f(location, v0, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
KMETHOD GL_glUniform4f(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLfloat v0 = PKGFloat_to(GLfloat, 2);
    GLfloat v1 = PKGFloat_to(GLfloat, 3);
    GLfloat v2 = PKGFloat_to(GLfloat, 4);
    GLfloat v3 = PKGFloat_to(GLfloat, 5);

    glUniform4f(location, v0, v1, v2, v3);
    RETURNvoid_();
}

//## @Native void GL.glUniform1i(GLint location, GLint v0);
KMETHOD GL_glUniform1i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);

    glUniform1i(location, v0);
    RETURNvoid_();
}

//## @Native void GL.glUniform2i(GLint location, GLint v0, GLint v1);
KMETHOD GL_glUniform2i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);

    glUniform2i(location, v0, v1);
    RETURNvoid_();
}

//## @Native void GL.glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
KMETHOD GL_glUniform3i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);
    GLint v2 = PKGInt_to(GLint, 4);

    glUniform3i(location, v0, v1, v2);
    RETURNvoid_();
}

//## @Native void GL.glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
KMETHOD GL_glUniform4i(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLint v0 = PKGInt_to(GLint, 2);
    GLint v1 = PKGInt_to(GLint, 3);
    GLint v2 = PKGInt_to(GLint, 4);
    GLint v3 = PKGInt_to(GLint, 5);

    glUniform4i(location, v0, v1, v2, v3);
    RETURNvoid_();
}

//## @Native void GL.glUniform1fv(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform1fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform1fv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform2fv(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform2fv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform3fv(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform3fv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform4fv(GLint location, GLsizei count, GLfloat* value);
KMETHOD GL_glUniform4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLfloat* value = PKG_Error_to(GLfloat*, 3);

    glUniform4fv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform1iv(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform1iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform1iv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform2iv(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform2iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform2iv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform3iv(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform3iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform3iv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniform4iv(GLint location, GLsizei count, GLint* value);
KMETHOD GL_glUniform4iv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLint* value = PKG_Error_to(GLint*, 3);

    glUniform4iv(location, count, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix2fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix3fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix4fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native GLboolean GL.glIsShader(GLuint shader);
KMETHOD GL_glIsShader(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsShader(shader);
    RETURNi_(ret);
}

//## @Native GLboolean GL.glIsProgram(GLuint program);
KMETHOD GL_glIsProgram(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);

    GLboolean ret = glIsProgram(program);
    RETURNi_(ret);
}

//## @Native void GL.glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
KMETHOD GL_glGetShaderiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetShaderiv(shader, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramiv(GLuint program, GLenum pname, GLint* params);
KMETHOD GL_glGetProgramiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLenum pname = PKGInt_to(GLenum, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetProgramiv(program, pname, params);
    RETURNvoid_();
}

//## @Native void GL.glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
KMETHOD GL_glGetAttachedShaders(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLsizei maxCount = PKGInt_to(GLsizei, 2);
    GLsizei* count = PKG_Error_to(GLsizei*, 3);
    GLuint* shaders = PKG_Error_to(GLuint*, 4);

    glGetAttachedShaders(program, maxCount, count, shaders);
    RETURNvoid_();
}

//## @Native void GL.glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
KMETHOD GL_glGetShaderInfoLog(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);
    GLsizei bufSize = PKGInt_to(GLsizei, 2);
    GLsizei* length = PKG_Error_to(GLsizei*, 3);
    GLchar* infoLog = PKG_Error_to(GLchar*, 4);

    glGetShaderInfoLog(shader, bufSize, length, infoLog);
    RETURNvoid_();
}

//## @Native void GL.glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
KMETHOD GL_glGetProgramInfoLog(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLsizei bufSize = PKGInt_to(GLsizei, 2);
    GLsizei* length = PKG_Error_to(GLsizei*, 3);
    GLchar* infoLog = PKG_Error_to(GLchar*, 4);

    glGetProgramInfoLog(program, bufSize, length, infoLog);
    RETURNvoid_();
}

//## @Native GLint GL.glGetUniformLocation(GLuint program, GLchar* name);
KMETHOD GL_glGetUniformLocation(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLchar* name = PKG_Error_to(GLchar*, 2);

    GLint ret = glGetUniformLocation(program, name);
    RETURNi_(ret);
}

//## @Native void GL.glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
KMETHOD GL_glGetActiveUniform(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei bufSize = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLint* size = PKG_Error_to(GLint*, 5);
    GLenum* type = PKG_Error_to(GLenum*, 6);
    GLchar* name = PKG_Error_to(GLchar*, 7);

    glGetActiveUniform(program, index, bufSize, length, size, type, name);
    RETURNvoid_();
}

//## @Native void GL.glGetUniformfv(GLuint program, GLint location, GLfloat* params);
KMETHOD GL_glGetUniformfv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLfloat* params = PKG_Error_to(GLfloat*, 3);

    glGetUniformfv(program, location, params);
    RETURNvoid_();
}

//## @Native void GL.glGetUniformiv(GLuint program, GLint location, GLint* params);
KMETHOD GL_glGetUniformiv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLint location = PKGInt_to(GLint, 2);
    GLint* params = PKG_Error_to(GLint*, 3);

    glGetUniformiv(program, location, params);
    RETURNvoid_();
}

//## @Native void GL.glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
KMETHOD GL_glGetShaderSource(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint shader = PKGInt_to(GLuint, 1);
    GLsizei bufSize = PKGInt_to(GLsizei, 2);
    GLsizei* length = PKG_Error_to(GLsizei*, 3);
    GLchar* source = PKG_Error_to(GLchar*, 4);

    glGetShaderSource(shader, bufSize, length, source);
    RETURNvoid_();
}

//## @Native void GL.glBindAttribLocation(GLuint program, GLuint index, GLchar* name);
KMETHOD GL_glBindAttribLocation(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLchar* name = PKG_Error_to(GLchar*, 3);

    glBindAttribLocation(program, index, name);
    RETURNvoid_();
}

//## @Native void GL.glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
KMETHOD GL_glGetActiveAttrib(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLuint index = PKGInt_to(GLuint, 2);
    GLsizei bufSize = PKGInt_to(GLsizei, 3);
    GLsizei* length = PKG_Error_to(GLsizei*, 4);
    GLint* size = PKG_Error_to(GLint*, 5);
    GLenum* type = PKG_Error_to(GLenum*, 6);
    GLchar* name = PKG_Error_to(GLchar*, 7);

    glGetActiveAttrib(program, index, bufSize, length, size, type, name);
    RETURNvoid_();
}

//## @Native GLint GL.glGetAttribLocation(GLuint program, GLchar* name);
KMETHOD GL_glGetAttribLocation(CTX ctx, ksfp_t *sfp _RIX)
{
    GLuint program = PKGInt_to(GLuint, 1);
    GLchar* name = PKG_Error_to(GLchar*, 2);

    GLint ret = glGetAttribLocation(program, name);
    RETURNi_(ret);
}

//## @Native void GL.glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
KMETHOD GL_glStencilFuncSeparate(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum func = PKGInt_to(GLenum, 2);
    GLint ref = PKGInt_to(GLint, 3);
    GLuint mask = PKGInt_to(GLuint, 4);

    glStencilFuncSeparate(face, func, ref, mask);
    RETURNvoid_();
}

//## @Native void GL.glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
KMETHOD GL_glStencilOpSeparate(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLenum fail = PKGInt_to(GLenum, 2);
    GLenum zfail = PKGInt_to(GLenum, 3);
    GLenum zpass = PKGInt_to(GLenum, 4);

    glStencilOpSeparate(face, fail, zfail, zpass);
    RETURNvoid_();
}

//## @Native void GL.glStencilMaskSeparate(GLenum face, GLuint mask);
KMETHOD GL_glStencilMaskSeparate(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum face = PKGInt_to(GLenum, 1);
    GLuint mask = PKGInt_to(GLuint, 2);

    glStencilMaskSeparate(face, mask);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix2x3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix2x3fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix3x2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix3x2fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix2x4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix2x4fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix4x2fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix4x2fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix3x4fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix3x4fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
KMETHOD GL_glUniformMatrix4x3fv(CTX ctx, ksfp_t *sfp _RIX)
{
    GLint location = PKGInt_to(GLint, 1);
    GLsizei count = PKGInt_to(GLsizei, 2);
    GLboolean transpose = PKGInt_to(GLboolean, 3);
    GLfloat* value = PKG_Error_to(GLfloat*, 4);

    glUniformMatrix4x3fv(location, count, transpose, value);
    RETURNvoid_();
}

//## @Native void GL.gluBeginCurve(GLUnurbs* nurb);
KMETHOD GL_gluBeginCurve(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluBeginCurve(nurb);
    RETURNvoid_();
}

//## @Native void GL.gluBeginPolygon(GLUtesselator* tess);
KMETHOD GL_gluBeginPolygon(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluBeginPolygon(tess);
    RETURNvoid_();
}

//## @Native void GL.gluBeginSurface(GLUnurbs* nurb);
KMETHOD GL_gluBeginSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluBeginSurface(nurb);
    RETURNvoid_();
}

//## @Native void GL.gluBeginTrim(GLUnurbs* nurb);
KMETHOD GL_gluBeginTrim(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluBeginTrim(nurb);
    RETURNvoid_();
}

//## @Native GLint GL.gluBuild1DMipmapLevels(GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, void* data);
KMETHOD GL_gluBuild1DMipmapLevels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLenum format = PKGInt_to(GLenum, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    GLint level = PKGInt_to(GLint, 6);
    GLint base = PKGInt_to(GLint, 7);
    GLint max = PKGInt_to(GLint, 8);
    void* data = PKG_Error_to(void*, 9);

    GLint ret = gluBuild1DMipmapLevels(target, internalFormat, width, format, type, level, base, max, data);
    RETURNi_(ret);
}

//## @Native GLint GL.gluBuild1DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, void* data);
KMETHOD GL_gluBuild1DMipmaps(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLenum format = PKGInt_to(GLenum, 4);
    GLenum type = PKGInt_to(GLenum, 5);
    void* data = PKG_Error_to(void*, 6);

    GLint ret = gluBuild1DMipmaps(target, internalFormat, width, format, type, data);
    RETURNi_(ret);
}

//## @Native GLint GL.gluBuild2DMipmapLevels(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, void* data);
KMETHOD GL_gluBuild2DMipmapLevels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    GLint level = PKGInt_to(GLint, 7);
    GLint base = PKGInt_to(GLint, 8);
    GLint max = PKGInt_to(GLint, 9);
    void* data = PKG_Error_to(void*, 10);

    GLint ret = gluBuild2DMipmapLevels(target, internalFormat, width, height, format, type, level, base, max, data);
    RETURNi_(ret);
}

//## @Native GLint GL.gluBuild2DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, void* data);
KMETHOD GL_gluBuild2DMipmaps(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLenum format = PKGInt_to(GLenum, 5);
    GLenum type = PKGInt_to(GLenum, 6);
    void* data = PKG_Error_to(void*, 7);

    GLint ret = gluBuild2DMipmaps(target, internalFormat, width, height, format, type, data);
    RETURNi_(ret);
}

//## @Native GLint GL.gluBuild3DMipmapLevels(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, void* data);
KMETHOD GL_gluBuild3DMipmapLevels(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLsizei depth = PKGInt_to(GLsizei, 5);
    GLenum format = PKGInt_to(GLenum, 6);
    GLenum type = PKGInt_to(GLenum, 7);
    GLint level = PKGInt_to(GLint, 8);
    GLint base = PKGInt_to(GLint, 9);
    GLint max = PKGInt_to(GLint, 10);
    void* data = PKG_Error_to(void*, 11);

    GLint ret = gluBuild3DMipmapLevels(target, internalFormat, width, height, depth, format, type, level, base, max, data);
    RETURNi_(ret);
}

//## @Native GLint GL.gluBuild3DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, void* data);
KMETHOD GL_gluBuild3DMipmaps(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum target = PKGInt_to(GLenum, 1);
    GLint internalFormat = PKGInt_to(GLint, 2);
    GLsizei width = PKGInt_to(GLsizei, 3);
    GLsizei height = PKGInt_to(GLsizei, 4);
    GLsizei depth = PKGInt_to(GLsizei, 5);
    GLenum format = PKGInt_to(GLenum, 6);
    GLenum type = PKGInt_to(GLenum, 7);
    void* data = PKG_Error_to(void*, 8);

    GLint ret = gluBuild3DMipmaps(target, internalFormat, width, height, depth, format, type, data);
    RETURNi_(ret);
}

//## @Native GLboolean GL.gluCheckExtension(GLubyte* extName, GLubyte* extString);
KMETHOD GL_gluCheckExtension(CTX ctx, ksfp_t *sfp _RIX)
{
    GLubyte* extName = PKG_Error_to(GLubyte*, 1);
    GLubyte* extString = PKG_Error_to(GLubyte*, 2);

    GLboolean ret = gluCheckExtension(extName, extString);
    RETURNi_(ret);
}

//## @Native void GL.gluCylinder(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
KMETHOD GL_gluCylinder(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLdouble base = PKGFloat_to(GLdouble, 2);
    GLdouble top = PKGFloat_to(GLdouble, 3);
    GLdouble height = PKGFloat_to(GLdouble, 4);
    GLint slices = PKGInt_to(GLint, 5);
    GLint stacks = PKGInt_to(GLint, 6);

    gluCylinder(quad, base, top, height, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.gluDeleteNurbsRenderer(GLUnurbs* nurb);
KMETHOD GL_gluDeleteNurbsRenderer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluDeleteNurbsRenderer(nurb);
    RETURNvoid_();
}

//## @Native void GL.gluDeleteQuadric(GLUquadric* quad);
KMETHOD GL_gluDeleteQuadric(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);

    gluDeleteQuadric(quad);
    RETURNvoid_();
}

//## @Native void GL.gluDeleteTess(GLUtesselator* tess);
KMETHOD GL_gluDeleteTess(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluDeleteTess(tess);
    RETURNvoid_();
}

//## @Native void GL.gluDisk(GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops);
KMETHOD GL_gluDisk(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLdouble inner = PKGFloat_to(GLdouble, 2);
    GLdouble outer = PKGFloat_to(GLdouble, 3);
    GLint slices = PKGInt_to(GLint, 4);
    GLint loops = PKGInt_to(GLint, 5);

    gluDisk(quad, inner, outer, slices, loops);
    RETURNvoid_();
}

//## @Native void GL.gluEndCurve(GLUnurbs* nurb);
KMETHOD GL_gluEndCurve(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluEndCurve(nurb);
    RETURNvoid_();
}

//## @Native void GL.gluEndPolygon(GLUtesselator* tess);
KMETHOD GL_gluEndPolygon(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluEndPolygon(tess);
    RETURNvoid_();
}

//## @Native void GL.gluEndSurface(GLUnurbs* nurb);
KMETHOD GL_gluEndSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluEndSurface(nurb);
    RETURNvoid_();
}

//## @Native void GL.gluEndTrim(GLUnurbs* nurb);
KMETHOD GL_gluEndTrim(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);

    gluEndTrim(nurb);
    RETURNvoid_();
}

//## @Native GLubyte* GL.gluErrorString(GLenum error);
KMETHOD GL_gluErrorString(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum error = PKGInt_to(GLenum, 1);

    const GLubyte* ret = gluErrorString(error);
    RETURN_error(ret);
}

//## @Native void GL.gluGetNurbsProperty(GLUnurbs* nurb, GLenum property, GLfloat* data);
KMETHOD GL_gluGetNurbsProperty(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLenum property = PKGInt_to(GLenum, 2);
    GLfloat* data = PKG_Error_to(GLfloat*, 3);

    gluGetNurbsProperty(nurb, property, data);
    RETURNvoid_();
}

//## @Native GLubyte* GL.gluGetString(GLenum name);
KMETHOD GL_gluGetString(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum name = PKGInt_to(GLenum, 1);

    const GLubyte* ret = gluGetString(name);
    RETURN_error(ret);
}

//## @Native void GL.gluGetTessProperty(GLUtesselator* tess, GLenum which, GLdouble* data);
KMETHOD GL_gluGetTessProperty(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLenum which = PKGInt_to(GLenum, 2);
    GLdouble* data = PKG_Error_to(GLdouble*, 3);

    gluGetTessProperty(tess, which, data);
    RETURNvoid_();
}

//## @Native void GL.gluLoadSamplingMatrices(GLUnurbs* nurb, GLfloat* model, GLfloat* perspective, GLint* view);
KMETHOD GL_gluLoadSamplingMatrices(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLfloat* model = PKG_Error_to(GLfloat*, 2);
    GLfloat* perspective = PKG_Error_to(GLfloat*, 3);
    GLint* view = PKG_Error_to(GLint*, 4);

    gluLoadSamplingMatrices(nurb, model, perspective, view);
    RETURNvoid_();
}

//## @Native void GL.gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX, GLdouble centerY, GLdouble centerZ, GLdouble upX, GLdouble upY, GLdouble upZ);
KMETHOD GL_gluLookAt(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble eyeX = PKGFloat_to(GLdouble, 1);
    GLdouble eyeY = PKGFloat_to(GLdouble, 2);
    GLdouble eyeZ = PKGFloat_to(GLdouble, 3);
    GLdouble centerX = PKGFloat_to(GLdouble, 4);
    GLdouble centerY = PKGFloat_to(GLdouble, 5);
    GLdouble centerZ = PKGFloat_to(GLdouble, 6);
    GLdouble upX = PKGFloat_to(GLdouble, 7);
    GLdouble upY = PKGFloat_to(GLdouble, 8);
    GLdouble upZ = PKGFloat_to(GLdouble, 9);

    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    RETURNvoid_();
}

//## @Native GLUnurbs* GL.gluNewNurbsRenderer();
KMETHOD GL_gluNewNurbsRenderer(CTX ctx, ksfp_t *sfp _RIX)
{

    GLUnurbs* ret = gluNewNurbsRenderer();
    RETURN_error(ret);
}

//## @Native GLUquadric* GL.gluNewQuadric();
KMETHOD GL_gluNewQuadric(CTX ctx, ksfp_t *sfp _RIX)
{

    GLUquadric* ret = gluNewQuadric();
    RETURN_error(ret);
}

//## @Native GLUtesselator* GL.gluNewTess();
KMETHOD GL_gluNewTess(CTX ctx, ksfp_t *sfp _RIX)
{

    GLUtesselator* ret = gluNewTess();
    RETURN_error(ret);
}

//## @Native void GL.gluNextContour(GLUtesselator* tess, GLenum type);
KMETHOD GL_gluNextContour(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLenum type = PKGInt_to(GLenum, 2);

    gluNextContour(tess, type);
    RETURNvoid_();
}

//## @Native void GL.gluNurbsCallbackData(GLUnurbs* nurb, GLvoid* userData);
KMETHOD GL_gluNurbsCallbackData(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLvoid* userData = PKG_Error_to(GLvoid*, 2);

    gluNurbsCallbackData(nurb, userData);
    RETURNvoid_();
}

//## @Native void GL.gluNurbsCallbackDataEXT(GLUnurbs* nurb, GLvoid* userData);
KMETHOD GL_gluNurbsCallbackDataEXT(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLvoid* userData = PKG_Error_to(GLvoid*, 2);

    gluNurbsCallbackDataEXT(nurb, userData);
    RETURNvoid_();
}

//## @Native void GL.gluNurbsCurve(GLUnurbs* nurb, GLint knotCount, GLfloat* knots, GLint stride, GLfloat* control, GLint order, GLenum type);
KMETHOD GL_gluNurbsCurve(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLint knotCount = PKGInt_to(GLint, 2);
    GLfloat* knots = PKG_Error_to(GLfloat*, 3);
    GLint stride = PKGInt_to(GLint, 4);
    GLfloat* control = PKG_Error_to(GLfloat*, 5);
    GLint order = PKGInt_to(GLint, 6);
    GLenum type = PKGInt_to(GLenum, 7);

    gluNurbsCurve(nurb, knotCount, knots, stride, control, order, type);
    RETURNvoid_();
}

//## @Native void GL.gluNurbsProperty(GLUnurbs* nurb, GLenum property, GLfloat value);
KMETHOD GL_gluNurbsProperty(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLenum property = PKGInt_to(GLenum, 2);
    GLfloat value = PKGFloat_to(GLfloat, 3);

    gluNurbsProperty(nurb, property, value);
    RETURNvoid_();
}

//## @Native void GL.gluNurbsSurface(GLUnurbs* nurb, GLint sKnotCount, GLfloat* sKnots, GLint tKnotCount, GLfloat* tKnots, GLint sStride, GLint tStride, GLfloat* control, GLint sOrder, GLint tOrder, GLenum type);
KMETHOD GL_gluNurbsSurface(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLint sKnotCount = PKGInt_to(GLint, 2);
    GLfloat* sKnots = PKG_Error_to(GLfloat*, 3);
    GLint tKnotCount = PKGInt_to(GLint, 4);
    GLfloat* tKnots = PKG_Error_to(GLfloat*, 5);
    GLint sStride = PKGInt_to(GLint, 6);
    GLint tStride = PKGInt_to(GLint, 7);
    GLfloat* control = PKG_Error_to(GLfloat*, 8);
    GLint sOrder = PKGInt_to(GLint, 9);
    GLint tOrder = PKGInt_to(GLint, 10);
    GLenum type = PKGInt_to(GLenum, 11);

    gluNurbsSurface(nurb, sKnotCount, sKnots, tKnotCount, tKnots, sStride, tStride, control, sOrder, tOrder, type);
    RETURNvoid_();
}

//## @Native void GL.gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
KMETHOD GL_gluOrtho2D(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble left = PKGFloat_to(GLdouble, 1);
    GLdouble right = PKGFloat_to(GLdouble, 2);
    GLdouble bottom = PKGFloat_to(GLdouble, 3);
    GLdouble top = PKGFloat_to(GLdouble, 4);

    gluOrtho2D(left, right, bottom, top);
    RETURNvoid_();
}

//## @Native void GL.gluPartialDisk(GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops, GLdouble start, GLdouble sweep);
KMETHOD GL_gluPartialDisk(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLdouble inner = PKGFloat_to(GLdouble, 2);
    GLdouble outer = PKGFloat_to(GLdouble, 3);
    GLint slices = PKGInt_to(GLint, 4);
    GLint loops = PKGInt_to(GLint, 5);
    GLdouble start = PKGFloat_to(GLdouble, 6);
    GLdouble sweep = PKGFloat_to(GLdouble, 7);

    gluPartialDisk(quad, inner, outer, slices, loops, start, sweep);
    RETURNvoid_();
}

//## @Native void GL.gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
KMETHOD GL_gluPerspective(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble fovy = PKGFloat_to(GLdouble, 1);
    GLdouble aspect = PKGFloat_to(GLdouble, 2);
    GLdouble zNear = PKGFloat_to(GLdouble, 3);
    GLdouble zFar = PKGFloat_to(GLdouble, 4);

    gluPerspective(fovy, aspect, zNear, zFar);
    RETURNvoid_();
}

//## @Native void GL.gluPickMatrix(GLdouble x, GLdouble y, GLdouble delX, GLdouble delY, GLint* viewport);
KMETHOD GL_gluPickMatrix(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble x = PKGFloat_to(GLdouble, 1);
    GLdouble y = PKGFloat_to(GLdouble, 2);
    GLdouble delX = PKGFloat_to(GLdouble, 3);
    GLdouble delY = PKGFloat_to(GLdouble, 4);
    GLint* viewport = PKG_Error_to(GLint*, 5);

    gluPickMatrix(x, y, delX, delY, viewport);
    RETURNvoid_();
}

//## @Native GLint GL.gluProject(GLdouble objX, GLdouble objY, GLdouble objZ, GLdouble* model, GLdouble* proj, GLint* view, GLdouble* winX, GLdouble* winY, GLdouble* winZ);
KMETHOD GL_gluProject(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble objX = PKGFloat_to(GLdouble, 1);
    GLdouble objY = PKGFloat_to(GLdouble, 2);
    GLdouble objZ = PKGFloat_to(GLdouble, 3);
    GLdouble* model = PKG_Error_to(GLdouble*, 4);
    GLdouble* proj = PKG_Error_to(GLdouble*, 5);
    GLint* view = PKG_Error_to(GLint*, 6);
    GLdouble* winX = PKG_Error_to(GLdouble*, 7);
    GLdouble* winY = PKG_Error_to(GLdouble*, 8);
    GLdouble* winZ = PKG_Error_to(GLdouble*, 9);

    GLint ret = gluProject(objX, objY, objZ, model, proj, view, winX, winY, winZ);
    RETURNi_(ret);
}

//## @Native void GL.gluPwlCurve(GLUnurbs* nurb, GLint count, GLfloat* data, GLint stride, GLenum type);
KMETHOD GL_gluPwlCurve(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUnurbs* nurb = PKG_Error_to(GLUnurbs*, 1);
    GLint count = PKGInt_to(GLint, 2);
    GLfloat* data = PKG_Error_to(GLfloat*, 3);
    GLint stride = PKGInt_to(GLint, 4);
    GLenum type = PKGInt_to(GLenum, 5);

    gluPwlCurve(nurb, count, data, stride, type);
    RETURNvoid_();
}

//## @Native void GL.gluQuadricDrawStyle(GLUquadric* quad, GLenum draw);
KMETHOD GL_gluQuadricDrawStyle(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLenum draw = PKGInt_to(GLenum, 2);

    gluQuadricDrawStyle(quad, draw);
    RETURNvoid_();
}

//## @Native void GL.gluQuadricNormals(GLUquadric* quad, GLenum normal);
KMETHOD GL_gluQuadricNormals(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLenum normal = PKGInt_to(GLenum, 2);

    gluQuadricNormals(quad, normal);
    RETURNvoid_();
}

//## @Native void GL.gluQuadricOrientation(GLUquadric* quad, GLenum orientation);
KMETHOD GL_gluQuadricOrientation(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLenum orientation = PKGInt_to(GLenum, 2);

    gluQuadricOrientation(quad, orientation);
    RETURNvoid_();
}

//## @Native void GL.gluQuadricTexture(GLUquadric* quad, GLboolean texture);
KMETHOD GL_gluQuadricTexture(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLboolean texture = PKGInt_to(GLboolean, 2);

    gluQuadricTexture(quad, texture);
    RETURNvoid_();
}

//## @Native GLint GL.gluScaleImage(GLenum format, GLsizei wIn, GLsizei hIn, GLenum typeIn, void* dataIn, GLsizei wOut, GLsizei hOut, GLenum typeOut, GLvoid* dataOut);
KMETHOD GL_gluScaleImage(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum format = PKGInt_to(GLenum, 1);
    GLsizei wIn = PKGInt_to(GLsizei, 2);
    GLsizei hIn = PKGInt_to(GLsizei, 3);
    GLenum typeIn = PKGInt_to(GLenum, 4);
    void* dataIn = PKG_Error_to(void*, 5);
    GLsizei wOut = PKGInt_to(GLsizei, 6);
    GLsizei hOut = PKGInt_to(GLsizei, 7);
    GLenum typeOut = PKGInt_to(GLenum, 8);
    GLvoid* dataOut = PKG_Error_to(GLvoid*, 9);

    GLint ret = gluScaleImage(format, wIn, hIn, typeIn, dataIn, wOut, hOut, typeOut, dataOut);
    RETURNi_(ret);
}

//## @Native void GL.gluSphere(GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks);
KMETHOD GL_gluSphere(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUquadric* quad = PKG_Error_to(GLUquadric*, 1);
    GLdouble radius = PKGFloat_to(GLdouble, 2);
    GLint slices = PKGInt_to(GLint, 3);
    GLint stacks = PKGInt_to(GLint, 4);

    gluSphere(quad, radius, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.gluTessBeginContour(GLUtesselator* tess);
KMETHOD GL_gluTessBeginContour(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluTessBeginContour(tess);
    RETURNvoid_();
}

//## @Native void GL.gluTessBeginPolygon(GLUtesselator* tess, GLvoid* data);
KMETHOD GL_gluTessBeginPolygon(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLvoid* data = PKG_Error_to(GLvoid*, 2);

    gluTessBeginPolygon(tess, data);
    RETURNvoid_();
}

//## @Native void GL.gluTessEndContour(GLUtesselator* tess);
KMETHOD GL_gluTessEndContour(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluTessEndContour(tess);
    RETURNvoid_();
}

//## @Native void GL.gluTessEndPolygon(GLUtesselator* tess);
KMETHOD GL_gluTessEndPolygon(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);

    gluTessEndPolygon(tess);
    RETURNvoid_();
}

//## @Native void GL.gluTessNormal(GLUtesselator* tess, GLdouble valueX, GLdouble valueY, GLdouble valueZ);
KMETHOD GL_gluTessNormal(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLdouble valueX = PKGFloat_to(GLdouble, 2);
    GLdouble valueY = PKGFloat_to(GLdouble, 3);
    GLdouble valueZ = PKGFloat_to(GLdouble, 4);

    gluTessNormal(tess, valueX, valueY, valueZ);
    RETURNvoid_();
}

//## @Native void GL.gluTessProperty(GLUtesselator* tess, GLenum which, GLdouble data);
KMETHOD GL_gluTessProperty(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLenum which = PKGInt_to(GLenum, 2);
    GLdouble data = PKGFloat_to(GLdouble, 3);

    gluTessProperty(tess, which, data);
    RETURNvoid_();
}

//## @Native void GL.gluTessVertex(GLUtesselator* tess, GLdouble* location, GLvoid* data);
KMETHOD GL_gluTessVertex(CTX ctx, ksfp_t *sfp _RIX)
{
    GLUtesselator* tess = PKG_Error_to(GLUtesselator*, 1);
    GLdouble* location = PKG_Error_to(GLdouble*, 2);
    GLvoid* data = PKG_Error_to(GLvoid*, 3);

    gluTessVertex(tess, location, data);
    RETURNvoid_();
}

//## @Native GLint GL.gluUnProject(GLdouble winX, GLdouble winY, GLdouble winZ, GLdouble* model, GLdouble* proj, GLint* view, GLdouble* objX, GLdouble* objY, GLdouble* objZ);
KMETHOD GL_gluUnProject(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble winX = PKGFloat_to(GLdouble, 1);
    GLdouble winY = PKGFloat_to(GLdouble, 2);
    GLdouble winZ = PKGFloat_to(GLdouble, 3);
    GLdouble* model = PKG_Error_to(GLdouble*, 4);
    GLdouble* proj = PKG_Error_to(GLdouble*, 5);
    GLint* view = PKG_Error_to(GLint*, 6);
    GLdouble* objX = PKG_Error_to(GLdouble*, 7);
    GLdouble* objY = PKG_Error_to(GLdouble*, 8);
    GLdouble* objZ = PKG_Error_to(GLdouble*, 9);

    GLint ret = gluUnProject(winX, winY, winZ, model, proj, view, objX, objY, objZ);
    RETURNi_(ret);
}

//## @Native GLint GL.gluUnProject4(GLdouble winX, GLdouble winY, GLdouble winZ, GLdouble clipW, GLdouble* model, GLdouble* proj, GLint* view, GLdouble nearPlane, GLdouble farPlane, GLdouble* objX, GLdouble* objY, GLdouble* objZ, GLdouble* objW);
KMETHOD GL_gluUnProject4(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble winX = PKGFloat_to(GLdouble, 1);
    GLdouble winY = PKGFloat_to(GLdouble, 2);
    GLdouble winZ = PKGFloat_to(GLdouble, 3);
    GLdouble clipW = PKGFloat_to(GLdouble, 4);
    GLdouble* model = PKG_Error_to(GLdouble*, 5);
    GLdouble* proj = PKG_Error_to(GLdouble*, 6);
    GLint* view = PKG_Error_to(GLint*, 7);
    GLdouble nearPlane = PKGFloat_to(GLdouble, 8);
    GLdouble farPlane = PKGFloat_to(GLdouble, 9);
    GLdouble* objX = PKG_Error_to(GLdouble*, 10);
    GLdouble* objY = PKG_Error_to(GLdouble*, 11);
    GLdouble* objZ = PKG_Error_to(GLdouble*, 12);
    GLdouble* objW = PKG_Error_to(GLdouble*, 13);

    GLint ret = gluUnProject4(winX, winY, winZ, clipW, model, proj, view, nearPlane, farPlane, objX, objY, objZ, objW);
    RETURNi_(ret);
}

//## @Native void GL.glutInit(String[] argv);
KMETHOD GL_glutInit(CTX ctx, ksfp_t *sfp _RIX)
{
    /* FIXED */
    kArray *a = sfp[1].a;
    int i, argc = knh_Array_size(a);
    char** argv = (char **) alloca(sizeof(char**) * argc);
    for (i = 0; i < argc; ++i) {
        kString *s = (kString *) knh_Array_n(a, i);
        argv[i] = (char *) S_totext(s);
    }
    glutInit(&argc, argv);
    RETURNvoid_();
}

//## @Native void GL.glutInitDisplayMode(unsigned int mode);
KMETHOD GL_glutInitDisplayMode(CTX ctx, ksfp_t *sfp _RIX)
{
    unsigned int v= PKG_Error_to(unsigned int, 1);

    glutInitDisplayMode(v);
    RETURNvoid_();
}

//## @Native void GL.glutInitDisplayString(char* string);
KMETHOD GL_glutInitDisplayString(CTX ctx, ksfp_t *sfp _RIX)
{
    char* string = PKGString_to(char*, 1);

    glutInitDisplayString(string);
    RETURNvoid_();
}

//## @Native void GL.glutInitWindowPosition(int x, int y);
KMETHOD GL_glutInitWindowPosition(CTX ctx, ksfp_t *sfp _RIX)
{
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);

    glutInitWindowPosition(x, y);
    RETURNvoid_();
}

//## @Native void GL.glutInitWindowSize(int width, int height);
KMETHOD GL_glutInitWindowSize(CTX ctx, ksfp_t *sfp _RIX)
{
    int width = PKGInt_to(int, 1);
    int height = PKGInt_to(int, 2);

    glutInitWindowSize(width, height);
    RETURNvoid_();
}

//## @Native void GL.glutMainLoop();
KMETHOD GL_glutMainLoop(CTX ctx, ksfp_t *sfp _RIX)
{

    glutMainLoop();
    RETURNvoid_();
}

//## @Native int GL.glutCreateWindow(char* title);
KMETHOD GL_glutCreateWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    char* title = PKGString_to(char*, 1);

    int ret = glutCreateWindow(title);
    RETURNi_(ret);
}

//## @Native int GL.glutCreateSubWindow(int win, int x, int y, int width, int height);
KMETHOD GL_glutCreateSubWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);
    int x = PKGInt_to(int, 2);
    int y = PKGInt_to(int, 3);
    int width = PKGInt_to(int, 4);
    int height = PKGInt_to(int, 5);

    int ret = glutCreateSubWindow(win, x, y, width, height);
    RETURNi_(ret);
}

//## @Native void GL.glutDestroyWindow(int win);
KMETHOD GL_glutDestroyWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);

    glutDestroyWindow(win);
    RETURNvoid_();
}

//## @Native void GL.glutPostRedisplay();
KMETHOD GL_glutPostRedisplay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutPostRedisplay();
    RETURNvoid_();
}

//## @Native void GL.glutPostWindowRedisplay(int win);
KMETHOD GL_glutPostWindowRedisplay(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);

    glutPostWindowRedisplay(win);
    RETURNvoid_();
}

//## @Native void GL.glutSwapBuffers();
KMETHOD GL_glutSwapBuffers(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSwapBuffers();
    RETURNvoid_();
}

//## @Native int GL.glutGetWindow();
KMETHOD GL_glutGetWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    int ret = glutGetWindow();
    RETURNi_(ret);
}

//## @Native void GL.glutSetWindow(int win);
KMETHOD GL_glutSetWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);

    glutSetWindow(win);
    RETURNvoid_();
}

//## @Native void GL.glutSetWindowTitle(char* title);
KMETHOD GL_glutSetWindowTitle(CTX ctx, ksfp_t *sfp _RIX)
{
    char* title = PKGString_to(char*, 1);

    glutSetWindowTitle(title);
    RETURNvoid_();
}

//## @Native void GL.glutSetIconTitle(char* title);
KMETHOD GL_glutSetIconTitle(CTX ctx, ksfp_t *sfp _RIX)
{
    char* title = PKGString_to(char*, 1);

    glutSetIconTitle(title);
    RETURNvoid_();
}

//## @Native void GL.glutPositionWindow(int x, int y);
KMETHOD GL_glutPositionWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);

    glutPositionWindow(x, y);
    RETURNvoid_();
}

//## @Native void GL.glutReshapeWindow(int width, int height);
KMETHOD GL_glutReshapeWindow(CTX ctx, ksfp_t *sfp _RIX)
{
    int width = PKGInt_to(int, 1);
    int height = PKGInt_to(int, 2);

    glutReshapeWindow(width, height);
    RETURNvoid_();
}

//## @Native void GL.glutPopWindow();
KMETHOD GL_glutPopWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    glutPopWindow();
    RETURNvoid_();
}

//## @Native void GL.glutPushWindow();
KMETHOD GL_glutPushWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    glutPushWindow();
    RETURNvoid_();
}

//## @Native void GL.glutIconifyWindow();
KMETHOD GL_glutIconifyWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    glutIconifyWindow();
    RETURNvoid_();
}

//## @Native void GL.glutShowWindow();
KMETHOD GL_glutShowWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    glutShowWindow();
    RETURNvoid_();
}

//## @Native void GL.glutHideWindow();
KMETHOD GL_glutHideWindow(CTX ctx, ksfp_t *sfp _RIX)
{

    glutHideWindow();
    RETURNvoid_();
}

//## @Native void GL.glutFullScreen();
KMETHOD GL_glutFullScreen(CTX ctx, ksfp_t *sfp _RIX)
{

    glutFullScreen();
    RETURNvoid_();
}

//## @Native void GL.glutSetCursor(int cursor);
KMETHOD GL_glutSetCursor(CTX ctx, ksfp_t *sfp _RIX)
{
    int cursor = PKGInt_to(int, 1);

    glutSetCursor(cursor);
    RETURNvoid_();
}

//## @Native void GL.glutWarpPointer(int x, int y);
KMETHOD GL_glutWarpPointer(CTX ctx, ksfp_t *sfp _RIX)
{
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);

    glutWarpPointer(x, y);
    RETURNvoid_();
}

//## @Native void GL.glutCheckLoop();
KMETHOD GL_glutCheckLoop(CTX ctx, ksfp_t *sfp _RIX)
{

    glutCheckLoop();
    RETURNvoid_();
}

//## @Native void GL.glutEstablishOverlay();
KMETHOD GL_glutEstablishOverlay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutEstablishOverlay();
    RETURNvoid_();
}

//## @Native void GL.glutRemoveOverlay();
KMETHOD GL_glutRemoveOverlay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutRemoveOverlay();
    RETURNvoid_();
}

//## @Native void GL.glutUseLayer(GLenum layer);
KMETHOD GL_glutUseLayer(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum layer = PKGInt_to(GLenum, 1);

    glutUseLayer(layer);
    RETURNvoid_();
}

//## @Native void GL.glutPostOverlayRedisplay();
KMETHOD GL_glutPostOverlayRedisplay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutPostOverlayRedisplay();
    RETURNvoid_();
}

//## @Native void GL.glutPostWindowOverlayRedisplay(int win);
KMETHOD GL_glutPostWindowOverlayRedisplay(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);

    glutPostWindowOverlayRedisplay(win);
    RETURNvoid_();
}

//## @Native void GL.glutShowOverlay();
KMETHOD GL_glutShowOverlay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutShowOverlay();
    RETURNvoid_();
}

//## @Native void GL.glutHideOverlay();
KMETHOD GL_glutHideOverlay(CTX ctx, ksfp_t *sfp _RIX)
{

    glutHideOverlay();
    RETURNvoid_();
}

//## @Native void GL.glutDestroyMenu(int menu);
KMETHOD GL_glutDestroyMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    int menu = PKGInt_to(int, 1);

    glutDestroyMenu(menu);
    RETURNvoid_();
}

//## @Native int GL.glutGetMenu();
KMETHOD GL_glutGetMenu(CTX ctx, ksfp_t *sfp _RIX)
{

    int ret = glutGetMenu();
    RETURNi_(ret);
}

//## @Native void GL.glutSetMenu(int menu);
KMETHOD GL_glutSetMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    int menu = PKGInt_to(int, 1);

    glutSetMenu(menu);
    RETURNvoid_();
}

//## @Native void GL.glutAddMenuEntry(char* label, int value);
KMETHOD GL_glutAddMenuEntry(CTX ctx, ksfp_t *sfp _RIX)
{
    char* label = PKGString_to(char*, 1);
    int value = PKGInt_to(int, 2);

    glutAddMenuEntry(label, value);
    RETURNvoid_();
}

//## @Native void GL.glutAddSubMenu(char* label, int submenu);
KMETHOD GL_glutAddSubMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    char* label = PKGString_to(char*, 1);
    int submenu = PKGInt_to(int, 2);

    glutAddSubMenu(label, submenu);
    RETURNvoid_();
}

//## @Native void GL.glutChangeToMenuEntry(int item, char* label, int value);
KMETHOD GL_glutChangeToMenuEntry(CTX ctx, ksfp_t *sfp _RIX)
{
    int item = PKGInt_to(int, 1);
    char* label = PKGString_to(char*, 2);
    int value = PKGInt_to(int, 3);

    glutChangeToMenuEntry(item, label, value);
    RETURNvoid_();
}

//## @Native void GL.glutChangeToSubMenu(int item, char* label, int submenu);
KMETHOD GL_glutChangeToSubMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    int item = PKGInt_to(int, 1);
    char* label = PKGString_to(char*, 2);
    int submenu = PKGInt_to(int, 3);

    glutChangeToSubMenu(item, label, submenu);
    RETURNvoid_();
}

//## @Native void GL.glutRemoveMenuItem(int item);
KMETHOD GL_glutRemoveMenuItem(CTX ctx, ksfp_t *sfp _RIX)
{
    int item = PKGInt_to(int, 1);

    glutRemoveMenuItem(item);
    RETURNvoid_();
}

//## @Native void GL.glutAttachMenu(int button);
KMETHOD GL_glutAttachMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    int button = PKGInt_to(int, 1);

    glutAttachMenu(button);
    RETURNvoid_();
}

//## @Native void GL.glutDetachMenu(int button);
KMETHOD GL_glutDetachMenu(CTX ctx, ksfp_t *sfp _RIX)
{
    int button = PKGInt_to(int, 1);

    glutDetachMenu(button);
    RETURNvoid_();
}

//## @Native void GL.glutSetColor(int, GLfloat red, GLfloat green, GLfloat blue);
KMETHOD GL_glutSetColor(CTX ctx, ksfp_t *sfp _RIX)
{
    int arg0 = PKGInt_to(int, 1);
    GLfloat red = PKGFloat_to(GLfloat, 2);
    GLfloat green = PKGFloat_to(GLfloat, 3);
    GLfloat blue = PKGFloat_to(GLfloat, 4);

    glutSetColor(arg0, red, green, blue);
    RETURNvoid_();
}

//## @Native GLfloat GL.glutGetColor(int ndx, int component);
KMETHOD GL_glutGetColor(CTX ctx, ksfp_t *sfp _RIX)
{
    int ndx = PKGInt_to(int, 1);
    int component = PKGInt_to(int, 2);

    GLfloat ret = glutGetColor(ndx, component);
    RETURNf_(ret);
}

//## @Native void GL.glutCopyColormap(int win);
KMETHOD GL_glutCopyColormap(CTX ctx, ksfp_t *sfp _RIX)
{
    int win = PKGInt_to(int, 1);

    glutCopyColormap(win);
    RETURNvoid_();
}

//## @Native int GL.glutGet(GLenum type);
KMETHOD GL_glutGet(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);

    int ret = glutGet(type);
    RETURNi_(ret);
}

//## @Native int GL.glutDeviceGet(GLenum type);
KMETHOD GL_glutDeviceGet(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);

    int ret = glutDeviceGet(type);
    RETURNi_(ret);
}

//## @Native int GL.glutExtensionSupported(char* name);
KMETHOD GL_glutExtensionSupported(CTX ctx, ksfp_t *sfp _RIX)
{
    char* name = PKGString_to(char*, 1);

    int ret = glutExtensionSupported(name);
    RETURNi_(ret);
}

//## @Native int GL.glutGetModifiers();
KMETHOD GL_glutGetModifiers(CTX ctx, ksfp_t *sfp _RIX)
{

    int ret = glutGetModifiers();
    RETURNi_(ret);
}

//## @Native int GL.glutLayerGet(GLenum type);
KMETHOD GL_glutLayerGet(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum type = PKGInt_to(GLenum, 1);

    int ret = glutLayerGet(type);
    RETURNi_(ret);
}

//## @Native void* GL.glutGetProcAddress(char* procName);
KMETHOD GL_glutGetProcAddress(CTX ctx, ksfp_t *sfp _RIX)
{
    char* procName = PKGString_to(char*, 1);

    void* ret = glutGetProcAddress(procName);
    RETURN_error(ret);
}

//## @Native void GL.glutBitmapCharacter(void* font, int character);
KMETHOD GL_glutBitmapCharacter(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    int character = PKGInt_to(int, 2);

    glutBitmapCharacter(font, character);
    RETURNvoid_();
}

//## @Native int GL.glutBitmapWidth(void* font, int character);
KMETHOD GL_glutBitmapWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    int character = PKGInt_to(int, 2);

    int ret = glutBitmapWidth(font, character);
    RETURNi_(ret);
}

//## @Native void GL.glutStrokeCharacter(void* font, int character);
KMETHOD GL_glutStrokeCharacter(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    int character = PKGInt_to(int, 2);

    glutStrokeCharacter(font, character);
    RETURNvoid_();
}

//## @Native int GL.glutStrokeWidth(void* font, int character);
KMETHOD GL_glutStrokeWidth(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    int character = PKGInt_to(int, 2);

    int ret = glutStrokeWidth(font, character);
    RETURNi_(ret);
}

//## @Native int GL.glutBitmapLength(void* font, unsigned char* string);
KMETHOD GL_glutBitmapLength(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    unsigned char* s = PKG_Error_to(unsigned char *, 2);

    int ret = glutBitmapLength(font, s);
    RETURNi_(ret);
}

//## @Native int GL.glutStrokeLength(void* font, unsigned char* string);
KMETHOD GL_glutStrokeLength(CTX ctx, ksfp_t *sfp _RIX)
{
    void* font = PKG_Error_to(void*, 1);
    unsigned char* s = PKG_Error_to(unsigned char *, 2);

    int ret = glutStrokeLength(font, s);
    RETURNi_(ret);
}

//## @Native void GL.glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
KMETHOD GL_glutWireSphere(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble radius = PKGFloat_to(GLdouble, 1);
    GLint slices = PKGInt_to(GLint, 2);
    GLint stacks = PKGInt_to(GLint, 3);

    glutWireSphere(radius, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
KMETHOD GL_glutSolidSphere(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble radius = PKGFloat_to(GLdouble, 1);
    GLint slices = PKGInt_to(GLint, 2);
    GLint stacks = PKGInt_to(GLint, 3);

    glutSolidSphere(radius, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
KMETHOD GL_glutWireCone(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble base = PKGFloat_to(GLdouble, 1);
    GLdouble height = PKGFloat_to(GLdouble, 2);
    GLint slices = PKGInt_to(GLint, 3);
    GLint stacks = PKGInt_to(GLint, 4);

    glutWireCone(base, height, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
KMETHOD GL_glutSolidCone(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble base = PKGFloat_to(GLdouble, 1);
    GLdouble height = PKGFloat_to(GLdouble, 2);
    GLint slices = PKGInt_to(GLint, 3);
    GLint stacks = PKGInt_to(GLint, 4);

    glutSolidCone(base, height, slices, stacks);
    RETURNvoid_();
}

//## @Native void GL.glutWireCube(GLdouble size);
KMETHOD GL_glutWireCube(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble size = PKGFloat_to(GLdouble, 1);

    glutWireCube(size);
    RETURNvoid_();
}

//## @Native void GL.glutSolidCube(GLdouble size);
KMETHOD GL_glutSolidCube(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble size = PKGFloat_to(GLdouble, 1);

    glutSolidCube(size);
    RETURNvoid_();
}

//## @Native void GL.glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
KMETHOD GL_glutWireTorus(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble innerRadius = PKGFloat_to(GLdouble, 1);
    GLdouble outerRadius = PKGFloat_to(GLdouble, 2);
    GLint sides = PKGInt_to(GLint, 3);
    GLint rings = PKGInt_to(GLint, 4);

    glutWireTorus(innerRadius, outerRadius, sides, rings);
    RETURNvoid_();
}

//## @Native void GL.glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
KMETHOD GL_glutSolidTorus(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble innerRadius = PKGFloat_to(GLdouble, 1);
    GLdouble outerRadius = PKGFloat_to(GLdouble, 2);
    GLint sides = PKGInt_to(GLint, 3);
    GLint rings = PKGInt_to(GLint, 4);

    glutSolidTorus(innerRadius, outerRadius, sides, rings);
    RETURNvoid_();
}

//## @Native void GL.glutWireDodecahedron();
KMETHOD GL_glutWireDodecahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutWireDodecahedron();
    RETURNvoid_();
}

//## @Native void GL.glutSolidDodecahedron();
KMETHOD GL_glutSolidDodecahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSolidDodecahedron();
    RETURNvoid_();
}

//## @Native void GL.glutWireTeapot(GLdouble size);
KMETHOD GL_glutWireTeapot(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble size = PKGFloat_to(GLdouble, 1);

    glutWireTeapot(size);
    RETURNvoid_();
}

//## @Native void GL.glutSolidTeapot(GLdouble size);
KMETHOD GL_glutSolidTeapot(CTX ctx, ksfp_t *sfp _RIX)
{
    GLdouble size = PKGFloat_to(GLdouble, 1);

    glutSolidTeapot(size);
    RETURNvoid_();
}

//## @Native void GL.glutWireOctahedron();
KMETHOD GL_glutWireOctahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutWireOctahedron();
    RETURNvoid_();
}

//## @Native void GL.glutSolidOctahedron();
KMETHOD GL_glutSolidOctahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSolidOctahedron();
    RETURNvoid_();
}

//## @Native void GL.glutWireTetrahedron();
KMETHOD GL_glutWireTetrahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutWireTetrahedron();
    RETURNvoid_();
}

//## @Native void GL.glutSolidTetrahedron();
KMETHOD GL_glutSolidTetrahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSolidTetrahedron();
    RETURNvoid_();
}

//## @Native void GL.glutWireIcosahedron();
KMETHOD GL_glutWireIcosahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutWireIcosahedron();
    RETURNvoid_();
}

//## @Native void GL.glutSolidIcosahedron();
KMETHOD GL_glutSolidIcosahedron(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSolidIcosahedron();
    RETURNvoid_();
}

//## @Native int GL.glutVideoResizeGet(GLenum param);
KMETHOD GL_glutVideoResizeGet(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum param = PKGInt_to(GLenum, 1);

    int ret = glutVideoResizeGet(param);
    RETURNi_(ret);
}

//## @Native void GL.glutSetupVideoResizing();
KMETHOD GL_glutSetupVideoResizing(CTX ctx, ksfp_t *sfp _RIX)
{

    glutSetupVideoResizing();
    RETURNvoid_();
}

//## @Native void GL.glutStopVideoResizing();
KMETHOD GL_glutStopVideoResizing(CTX ctx, ksfp_t *sfp _RIX)
{

    glutStopVideoResizing();
    RETURNvoid_();
}

//## @Native void GL.glutVideoResize(int x, int y, int width, int height);
KMETHOD GL_glutVideoResize(CTX ctx, ksfp_t *sfp _RIX)
{
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);
    int width = PKGInt_to(int, 3);
    int height = PKGInt_to(int, 4);

    glutVideoResize(x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glutVideoPan(int x, int y, int width, int height);
KMETHOD GL_glutVideoPan(CTX ctx, ksfp_t *sfp _RIX)
{
    int x = PKGInt_to(int, 1);
    int y = PKGInt_to(int, 2);
    int width = PKGInt_to(int, 3);
    int height = PKGInt_to(int, 4);

    glutVideoPan(x, y, width, height);
    RETURNvoid_();
}

//## @Native void GL.glutReportErrors();
KMETHOD GL_glutReportErrors(CTX ctx, ksfp_t *sfp _RIX)
{

    glutReportErrors();
    RETURNvoid_();
}

//## @Native void GL.glutIgnoreKeyRepeat(int ignore);
KMETHOD GL_glutIgnoreKeyRepeat(CTX ctx, ksfp_t *sfp _RIX)
{
    int ignore = PKGInt_to(int, 1);

    glutIgnoreKeyRepeat(ignore);
    RETURNvoid_();
}

//## @Native void GL.glutSetKeyRepeat(int repeatMode);
KMETHOD GL_glutSetKeyRepeat(CTX ctx, ksfp_t *sfp _RIX)
{
    int repeatMode = PKGInt_to(int, 1);

    glutSetKeyRepeat(repeatMode);
    RETURNvoid_();
}

//## @Native void GL.glutForceJoystickFunc();
KMETHOD GL_glutForceJoystickFunc(CTX ctx, ksfp_t *sfp _RIX)
{

    glutForceJoystickFunc();
    RETURNvoid_();
}

//## @Native void GL.glutGameModeString(char* string);
KMETHOD GL_glutGameModeString(CTX ctx, ksfp_t *sfp _RIX)
{
    char* string = PKGString_to(char*, 1);

    glutGameModeString(string);
    RETURNvoid_();
}

//## @Native int GL.glutEnterGameMode();
KMETHOD GL_glutEnterGameMode(CTX ctx, ksfp_t *sfp _RIX)
{

    int ret = glutEnterGameMode();
    RETURNi_(ret);
}

//## @Native void GL.glutLeaveGameMode();
KMETHOD GL_glutLeaveGameMode(CTX ctx, ksfp_t *sfp _RIX)
{

    glutLeaveGameMode();
    RETURNvoid_();
}

//## @Native int GL.glutGameModeGet(GLenum mode);
KMETHOD GL_glutGameModeGet(CTX ctx, ksfp_t *sfp _RIX)
{
    GLenum mode = PKGInt_to(GLenum, 1);

    int ret = glutGameModeGet(mode);
    RETURNi_(ret);
}

#ifdef __cplusplus
}
#endif

