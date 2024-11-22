#include <GL/glut.h>
#include <GL/glui.h>
#include <math.h>

void init_glui()
{
	glui = GLUI_Master.create_glui( "GUI" );
	glui->set_main_gfx_window(main_window);
	
	//Panels
	projection_panel = glui->add_panel("Projection");
	transform_panel = glui->add_panel("Transformations");
	
	//Spinners
	angl = glui->add_spinner_to_panel(projection_panel,"Projection Angle", GLUI_SPINNER_FLOAT, &angle1);
	angl->set_float_limits(0, 180);
    angl->set_float_val(angle);
	
	thx = glui->add_spinner_to_panel(transform_panel, "X Transformation Angle", GLUI_SPINNER_FLOAT,&thetax1);
	thx->set_float_limits(0,360);
	thx->set_float_val(thetax);

	thy = glui->add_spinner_to_panel(transform_panel, "Y Transformation Angle", GLUI_SPINNER_FLOAT,&thetay1);
	thy->set_float_limits(0,360);
	thy->set_float_val(thetay);

	thz = glui->add_spinner_to_panel(transform_panel, "Z Transformation Angle", GLUI_SPINNER_FLOAT,&thetaz1);
	thz->set_float_limits(0,360);
	thz->set_float_val(thetaz);

	//Textboxes
	aspct = glui->add_edittext_to_panel(projection_panel,"Aspect", GLUI_EDITTEXT_FLOAT, &aspect1);
	aspct->set_float_limits(0, INFINITY);
	
	n_factor = glui->add_edittext_to_panel(projection_panel,"Near Plane", GLUI_EDITTEXT_FLOAT, &n1);
    n_factor->set_float_val(n);

	f_factor = glui->add_edittext_to_panel(projection_panel,"Far Plane", GLUI_EDITTEXT_FLOAT, &f1);
	f_factor->set_float_limits(n1,INFINITY);
    f_factor->set_float_val(f);
	
	d_x = glui->add_edittext_to_panel(transform_panel, "X translation", GLUI_EDITTEXT_FLOAT, &dx1);
	d_x->set_float_limits(-WINDOW_WIDTH/2,WINDOW_WIDTH/2);
	
	d_y = glui->add_edittext_to_panel(transform_panel, "Y translation", GLUI_EDITTEXT_FLOAT, &dy1);
	d_y->set_float_limits(-WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
	
	d_z = glui->add_edittext_to_panel(transform_panel, "Z translation", GLUI_EDITTEXT_FLOAT, &dz1);
	
	s_x = glui->add_edittext_to_panel(transform_panel, "X Scale", GLUI_EDITTEXT_FLOAT, &sx1);
	s_x->set_float_limits(0,INFINITY);
	s_x->set_float_val(sx);
	
	s_y = glui->add_edittext_to_panel(transform_panel, "Y Scale", GLUI_EDITTEXT_FLOAT, &sy1);
	s_y->set_float_limits(0,INFINITY);
	s_y->set_float_val(sy);
	
	s_z = glui->add_edittext_to_panel(transform_panel, "Z Scale", GLUI_EDITTEXT_FLOAT, &sz1);
	s_z->set_float_limits(0,INFINITY);
	s_z->set_float_val(sz);

	//Buttons
	glui->add_button("Set", 0, button_cb_set);

	glui->add_button("Reset", 0, button_cb_reset);
	
	glui->add_button("Exit", 0, (GLUI_Update_CB)exit);
}


void init_val()
{
	aspect = (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT;
    angle = 45.0;
    n = -SIZE;
    f = SIZE;
    dx = dy = dz = 0.0;
    sx = sy = sz = 1.0;
    thetax = thetay = 60.0;
    thetaz = 0.0;
}

// redispaly function
void myIdle()
{
	
	if ( glutGetWindow() != main_window ) 
	{
	 glutSetWindow(main_window);  
	 glutPostRedisplay();
    }
}


void button_cb_reset( GLUI_Control *control)
{
		//Reset Projection
		angle = 45.0;
		aspect = (float) WINDOW_WIDTH/(float) WINDOW_HEIGHT;
		n = SIZE;
    	f = -SIZE;
		n_factor->set_float_val(n);
		f_factor->set_float_val(f);
		angl->set_float_val(angle);
		aspct->set_float_val(aspect);
		
		//Reset Transformations
		dx = dy = dz = 0.0;
    	sx = sy = sz = 1.0;
    	thetax = thetay = 60.0;
    	thetaz = 0.0;
    	d_x->set_float_val(dx);
		d_y->set_float_val(dy);
		d_z->set_float_val(dz);
		s_x->set_float_val(sx);
		s_y->set_float_val(sy);
		s_z->set_float_val(sz);
		thx->set_float_val(thetax);
		thy->set_float_val(thetay);
		thz->set_float_val(thetaz);		

        //redisplay the circle again
        glutIdleFunc(myIdle);

	}

void button_cb_set( GLUI_Control *control)
{
		n = n1;
		f = f1;
		angle = angle1;
		aspect = aspect1;
		thetax = thetax1;
		thetay = thetay1;
		thetaz = thetaz1;
		dx = dx1;
		dy = dy1;
		dz = dz1;
		sx = sx1;
		sy = sy1;
		sz = sz1;

       //redisplay the circle again
       glutIdleFunc(myIdle);		
}

void set_identity_matrix(matrix4x4 &mat)
{
    mat.a11 = 1; mat.a12 = 0; mat.a13 = 0; mat.a14 = 0;
    mat.a21 = 0; mat.a22 = 1; mat.a23 = 0; mat.a24 = 0;
    mat.a31 = 0; mat.a32 = 0; mat.a33 = 1; mat.a34 = 0;
    mat.a41 = 0; mat.a42 = 0; mat.a43 = 0; mat.a44 = 1;
}

void mult(matrix4x4 mat, point3D &p)
{
    point3D temp;
    temp.x = mat.a11 * p.x + mat.a12 * p.y + mat.a13 * p.z + mat.a14 * p.w;
    temp.y = mat.a21 * p.x + mat.a22 * p.y + mat.a23 * p.z + mat.a24 * p.w;
    temp.z = mat.a31 * p.x + mat.a32 * p.y + mat.a33 * p.z + mat.a34 * p.w;
    temp.w = mat.a41 * p.x + mat.a42 * p.y + mat.a43 * p.z + mat.a44 * p.w;
    p = temp;
}

void setup_triangle()
{
	t[0].x = -SIZE; t[0].y = -SIZE; t[0].z = -SIZE; t[0].w = 1;
    t[1].x =  SIZE; t[1].y = -SIZE; t[1].z = -SIZE; t[1].w = 1;
    t[2].x =  SIZE; t[2].y =  SIZE; t[2].z = -SIZE; t[2].w = 1;
    t[3].x = -SIZE; t[3].y =  SIZE; t[3].z = -SIZE; t[3].w = 1;
    t[4].x = -SIZE; t[4].y = -SIZE; t[4].z =  SIZE; t[4].w = 1;
    t[5].x =  SIZE; t[5].y = -SIZE; t[5].z =  SIZE; t[5].w = 1;
    t[6].x =  SIZE; t[6].y =  SIZE; t[6].z =  SIZE; t[6].w = 1;
    t[7].x = -SIZE; t[7].y =  SIZE; t[7].z =  SIZE; t[7].w = 1;
  
}

void translate(point3D *p)
{
    matrix4x4 temp;
    set_identity_matrix(temp);
    temp.a14 = dx;
    temp.a24 = dy;
    temp.a34 = dz;
    mult(temp, *p);
}

void scale(point3D *p)
{
    matrix4x4 temp;
    set_identity_matrix(temp);
    temp.a11 *= sx;
    temp.a22 *= sy;
    temp.a33 *= sz;
    mult(temp, *p);
}

void rotateX(point3D *p)
{
    matrix4x4 temp;
    set_identity_matrix(temp);
    double sinTheta = sin(thetax * M_PI / 180);
    double cosTheta = cos(thetay * M_PI / 180);
    temp.a22 = cosTheta;
    temp.a23 = -sinTheta;
    temp.a32 = sinTheta;
    temp.a33 = cosTheta;
    mult(temp, *p);
}

void rotateY(point3D *p)
{
    matrix4x4 temp;
    set_identity_matrix(temp);
    double sinTheta = sin(thetay * M_PI / 180);
    double cosTheta = cos(thetay * M_PI / 180);
    temp.a11 = cosTheta;
    temp.a13 = sinTheta;
    temp.a31 = -sinTheta;
    temp.a33 = cosTheta;
    mult(temp, *p);
}

void rotateZ(point3D *p)
{
    matrix4x4 temp;
    set_identity_matrix(temp);
    double sinTheta = sin(thetaz * M_PI / 180);
    double cosTheta = cos(thetaz * M_PI / 180);
    temp.a11 = cosTheta;
    temp.a12 = -sinTheta;
    temp.a21 = sinTheta;
    temp.a22 = cosTheta;
    mult(temp, *p);
}

// perspective_projection based on matrix in page 375 eclass notes.
void perspective_projection(point3D *p)
{   
    int t = abs(n) * tan(angle/2.0);
    int b = -t;
    int r = t * aspect;
	int l = -r;
    
	matrix4x4 tmp;
	set_identity_matrix(tmp);
	tmp.a11 = (2.0*n)/(r-l);
	tmp.a22 = (2.0*n)/(t-b);
	tmp.a33 = (n+f)/(f-n);
	tmp.a34 = (-2.0*n*f)/(f-n);
	tmp.a43 = 1.0;
	tmp.a44 = 0.0;
	mult(tmp, *p);
}

void draw_triangle()
{
	int i;

    for(i = 0; i < 4; i++)
    {
	    draw_line(t[i].x, t[i].y, t[(i + 1) % 4].x, t[(i + 1) % 4].y);
	    draw_line(t[i + 4].x, t[i + 4].y, t[(i + 1) % 4 + 4].x, t[(i + 1) % 4 + 4].y);
	    draw_line(t[i].x, t[i].y, t[i + 4].x, t[i + 4].y); 
    }
}

void draw_line(double xs, double ys, double xe, double ye)
{
	glBegin(GL_LINES);
    glVertex2d(xs, ys);
    glVertex2d(xe, ye);
    glEnd();
}

void display()
{
	int i;

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);



    setup_triangle();

    for(i = 0; i < 8; i++)
        scale(&t[i]);

    for(i = 0; i < 8; i++)
        rotateZ(&t[i]);

    for(i = 0; i < 8; i++)
        rotateY(&t[i]);

	for(i = 0; i < 8; i++)
		rotateX(&t[i]);

    for(i = 0; i < 8; i++)
        translate(&t[i]);

    for(i = 0; i < 8; i++)
    {
		perspective_projection(&t[i]);
	
	}
    draw_triangle();

    glFlush();
}

void reshape(int w, int h)
{
    if(h == 0) h = 1;
    aspect = (double)w/(double)h;
    aspct->set_float_val(aspect);    
}