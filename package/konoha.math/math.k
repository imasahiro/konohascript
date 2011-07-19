/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with KONOHA_UNDER_LGPL3)
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

include "lib:gluelink";

@Singleton @Native class Math;

@Native int Math.abs(int x);
@Native float Math.fabs(float x);
@Native float Math.pow(float x,float y);
@Native float Math.ldexp(float x,int e);
@Native float Math.modf(float x,double y);
@Native float Math.frexp(float x,int y);
@Native float Math.fmod(float x,float d);
@Native float Math.ceil(float x);
//@Native float Math.round(float x);
//@Native float Math.nearbyint(float x);
@Native float Math.floor(float x);
@Native float Math.sqrt(float x);
@Native float Math.exp(float x);
@Native float Math.log10(float x);
@Native float Math.log(float x);
@Native float Math.sin(float x);
@Native float Math.cos(float x);
@Native float Math.tan(float x);
@Native float Math.asin(float x);
@Native float Math.acos(float x);
@Native float Math.atan(float x);
@Native float Math.atan2(float x,float y);
@Native float Math.sinh(float x);
@Native float Math.cosh(float x);
@Native float Math.tanh(float x);
//@Native float Math.asinh(float x);
//@Native float Math.acosh(float x);

