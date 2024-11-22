#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

// Constants
#define WINDOW_WIDTH    680
#define WINDOW_HEIGHT   560
#define SIZE            10.0

// Struct Definitions
typedef struct point3D {
    double x, y, z, w;
} point3D;

typedef struct matrix4x4 {
    double a11, a12, a13, a14,
           a21, a22, a23, a24,
           a31, a32, a33, a34,
           a41, a42, a43, a44;
} matrix4x4;

// Global Variables
extern int main_window;
extern float angle, angle1, aspect, aspect1, n, n1, f, f1;
extern float thetax, thetay, thetaz, dx, dy, dz, sx, sy, sz;
extern float thetax1, thetay1, thetaz1, dx1, dy1, dz1, sx1, sy1, sz1;
extern point3D t[8];

// GLUI Components
extern GLUI *glui;
extern GLUI_Panel *projection_panel, *transform_panel;
extern GLUI_EditText *aspct, *n_factor, *f_factor, *d_x, *d_y, *d_z, *s_x, *s_y, *s_z;
extern GLUI_Spinner *angl, *thx, *thy, *thz;

// Function Prototypes
void init_glui();
void myIdle();
void init_val();
void button_cb_reset(GLUI_Control *control);
void button_cb_set(GLUI_Control *control);
void set_identity_matrix(matrix4x4 &mat);
void mult(matrix4x4 mat, point3D &p);
void setup_triangle();
void translate(point3D *p);
void scale(point3D *p);
void rotateX(point3D *p);
void rotateY(point3D *p);
void rotateZ(point3D *p);
void perspective_projection(point3D *p);
void draw_triangle();
void draw_line(double xs, double ys, double xe, double ye);
void display();
void reshape(int w, int h);

#endif // TRANSFORMATIONS_H
