#include <physics.hpp>

GLDebugDraw::GLDebugDraw() : mRatio(1.0f)
{
	startTimer(1000 / 40.0f);
}

GLDebugDraw::GLDebugDraw(float32 ratio) : mRatio(ratio)
{

}

void GLDebugDraw::show(void)
{
	startTimer(1000 / 40.0f);
	QGLWidget::show();
}

void GLDebugDraw::initializeGL(void)
{
	glClearColor(0x00, 0x00, 0x00, 0x00);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void GLDebugDraw::DrawPolygon(const b2Vec2* old_vertices, int32 vertexCount, const b2Color& color)
{
	b2Vec2 vertices[vertexCount];
	for (int i = 0; i < vertexCount; i++) {
		vertices[i] = old_vertices[i];
		vertices[i] *= mRatio;
		vertices[i].x /= 600;
		vertices[i].y /= 600;
	}
	glColor4f(color.r, color.g, color.b,1);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

void GLDebugDraw::DrawSolidPolygon(const b2Vec2* old_vertices, int32 vertexCount, const b2Color& color)
{
	b2Vec2 vertices[vertexCount];
	for (int i = 0; i < vertexCount; i++) {
		vertices[i] = old_vertices[i];
		vertices[i] *= mRatio;
		vertices[i].x /= 600;
		vertices[i].y /= 600;
	}
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glColor4f(color.r*0.5f, color.g*0.5f, color.b*0.5f,0.5f);
	glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
	glColor4f(color.r, color.g, color.b,1);
	glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

void GLDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	const float32 k_segments = 16.0f;
	int vertexCount=16;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	GLfloat glVertices[vertexCount*2];
	for (int32 i = 0; i < k_segments; ++i) {
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertices[i*2]=v.x * mRatio / 600;
		glVertices[i*2+1]=v.y * mRatio / 600;
		theta += k_increment;
	}
	glColor4f(color.r, color.g, color.b,1);
	glVertexPointer(2, GL_FLOAT, 0, glVertices);
	glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
}

void GLDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	const float32 k_segments = 16.0f;
	int vertexCount=16;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	GLfloat glVertices[vertexCount*2];
	for (int32 i = 0; i < k_segments; ++i) {
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertices[i*2]=v.x * mRatio / 600;
		glVertices[i*2+1]=v.y * mRatio / 600;
		theta += k_increment;
	}
	glColor4f(color.r *0.5f, color.g*0.5f, color.b*0.5f,0.5f);
	glVertexPointer(2, GL_FLOAT, 0, glVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
	glColor4f(color.r, color.g, color.b,1);
	glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
	// Draw the axis line
	DrawSegment(center,center+radius*axis,color);
}

void GLDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	//fprintf(stderr, "drawSegment\n");
	glColor4f(color.r, color.g, color.b,1);
	GLfloat glVertices[] = {
		p1.x * mRatio/600, p1.y * mRatio/600,
		p2.x * mRatio/600, p2.y * mRatio/600
	};
	glVertexPointer(2, GL_FLOAT, 0, glVertices);
	glDrawArrays(GL_LINES, 0, 2);
}

void GLDebugDraw::DrawTransform(const b2Transform& xf)
{
	//fprintf(stderr, "DrawTransform\n");
	b2Vec2 p1 = xf.position, p2;
	const float32 k_axisScale = 0.4f;
	p2 = p1 + k_axisScale * xf.R.col1;
	DrawSegment(p1,p2,b2Color(1,0,0));
	p2 = p1 + k_axisScale * xf.R.col2;
	DrawSegment(p1,p2,b2Color(0,1,0));
}

void GLDebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	//fprintf(stderr, "drawPoint\n");
	glColor4f(color.r, color.g, color.b,1);
	glPointSize(size);
	GLfloat glVertices[] = {
		p.x * mRatio / 600, p.y * mRatio / 600
	};
	glVertexPointer(2, GL_FLOAT, 0, glVertices);
	glDrawArrays(GL_POINTS, 0, 1);
	glPointSize(1.0f);
}

void GLDebugDraw::DrawString(int x, int y, const char *string, ...)
{
//	NSLog(@"DrawString: unsupported: %s", string);
	//printf(string);
	/* Unsupported as yet. Could replace with bitmap font renderer at a later date */
}

void GLDebugDraw::DrawAABB(b2AABB* aabb, const b2Color& c)
{
	//fprintf(stderr, "drawAABB\n");
	glColor4f(c.r, c.g, c.b,1);
	GLfloat glVertices[] = {
		aabb->lowerBound.x * mRatio, aabb->lowerBound.y * mRatio,
		aabb->upperBound.x * mRatio, aabb->lowerBound.y * mRatio,
		aabb->upperBound.x * mRatio, aabb->upperBound.y * mRatio,
		aabb->lowerBound.x * mRatio, aabb->upperBound.y * mRatio
	};
	glVertexPointer(2, GL_FLOAT, 0, glVertices);
	glDrawArrays(GL_LINE_LOOP, 0, 8);
}

void GLDebugDraw::timerEvent(QTimerEvent *event)
{
	glDraw();
}

void GLDebugDraw::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
}

void GLDebugDraw::paintGL(void)
{
	//fprintf(stderr, "GLDebugDraw:paintGL\n");
	// Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
	// Needed states:  GL_VERTEX_ARRAY,
	// Unneeded states: GL_TEXTURE_2D, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glScalef(1.0f, 1.0f, 1);
	world->DrawDebugData();
	// restore default GL states
	glDisableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
