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

/*
 * qt4commons.hpp
 *
 *  Created on: Aug 3, 2011
 *      Author: kimio
 */

#ifndef QT4COMMONS_HPP_
#define QT4COMMONS_HPP_

#include <QtGui>
#include <iostream>
#include <konoha1.h>

#define QCAST(T, p)     (T)p
#define QPtr_to(T, a)   (T)((a).p->rawptr)

using namespace std;

class Connector : public QObject {
	Q_OBJECT;

public:
	knh_context_t *ctx;
	knh_Func_t *fo;
	Connector(CTX, knh_Func_t *fo);
	bool connectValueChanged(CTX, QObject *);
	bool connectClicked(CTX, QObject *);

public slots:
	void slotValueChanged(qreal);
	// QAbstractButton
	void slotClicked(bool);
};


class KonohaEvalEvent : public QEvent {
//	Q_OBJECT;

public:
	char *script;
	KonohaEvalEvent(char *);
	~KonohaEvalEvent();

};

class KonohaEval : public QObject {
	Q_OBJECT;

public:
	knh_context_t *ctx;
	KonohaEval(CTX);
	bool event(QEvent *e);

};


#endif /* QT4COMMONS_HPP_ */
