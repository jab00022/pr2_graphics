#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"

// Metodos constructores -----------------------------------

igvEscena3D::igvEscena3D () {ejes = true;}

igvEscena3D::~igvEscena3D() {}


// Metodos publicos ----------------------------------------

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
}

void tube() {
    static GLUquadric* quad = gluNewQuadric();

    GLfloat color_tube[] = { 0,0,0.5 };
    glMaterialfv(GL_FRONT, GL_EMISSION, color_tube);
    gluCylinder(quad, 0.25, 0.25, 1, 15, 15);
}


void igvEscena3D::visualizar(int scene) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window and the z-buffer

	// lights
  GLfloat light0[]={10,8,9,1}; // point light source
  glLightfv(GL_LIGHT0,GL_POSITION,light0);
  glEnable(GL_LIGHT0);

	glPushMatrix(); // store the model matrices

	  // se pintan los ejes
	  if (ejes) pintar_ejes();

	  // Scene selection based on menu option (int scene)
	  if (scene == SceneA) renderSceneA();
	  else if (scene == SceneB) renderSceneB();

	glPopMatrix (); // restore the modelview matrix
  glutSwapBuffers(); // it is used, instead of glFlush(), to avoid flickering
}

void igvEscena3D::renderSceneA() {
	GLfloat color_piece[] = { 0,0.25,0 };
	GLfloat color_black[] = { 0,0,0 };
	float dist = 1.65;

	// Practica 2a. Parte A.

	// Cube
	glMaterialfv(GL_FRONT, GL_EMISSION, color_piece);

	glutSolidCube(1);
	glPushMatrix();
	for (int k = 0; k < 3; ++k) {
		for (int j = 0; j < 3; ++j) {
			for (int i = 0; i < 2; ++i) {
				if (i == 0 && j == 0 && k != 0) {
					glPopMatrix();
					glTranslatef(0, dist, 0);
					glutSolidCube(1);
					glPushMatrix();
				}
				if (j == 1) {
					glTranslatef(-dist, 0, 0);
					glutSolidCube(1);
				}
				else {
					glTranslatef(dist, 0, 0);
					glutSolidCube(1);
				}
			}
			if (j != 2) {
				glTranslatef(0, 0, dist);
				glutSolidCube(1);
			}
		}
	}

	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, color_black);
}

void igvEscena3D::renderSceneB() {
	float dist = 1.65;
	GLfloat color_black[] = { 0,0.25,0 };

	// Practica 2a. Parte B.
	glMaterialfv(GL_FRONT, GL_EMISSION, color_black);

	glutSolidCube(1);
	glPushMatrix();
	for (int k = 0; k < 3; ++k) {
		for (int j = 0; j < 3; ++j) {
			for (int i = 0; i < 2; ++i) {
				if (i == 0 && j == 0 && k != 0) {
					glPopMatrix();
					glTranslatef(0, dist, 0);
					glutSolidCube(1);
					glPushMatrix();
				}
				if (j == 1) {
					glTranslatef(-dist, 0, 0);
					glutSolidCube(1);
				}
				else {
					glTranslatef(dist, 0, 0);
					glutSolidCube(1);
					if (k == 2 && i == 1) {
						glPushMatrix(); //Para poner luego los tubos
					}
				}
			}
			if (j != 2) {
				glTranslatef(0, 0, dist);
				glutSolidCube(1);
			}
		}
	}
	glPopMatrix();
	glRotatef(270, 1, 0, 0);		//Para orientarlos hacia arriba
	glRotatef(rotar, 0, 1, 0);		//Para que haga la rotación
	glScalef(0.8, 0.8, 0.8 + escalar);
	tube();

	glPopMatrix();
	glRotatef(270, 1, 0, 0);
	glRotatef(rotar, 0, 1, 0);
	glScalef(0.8, 0.8, 0.8 + escalar);
	tube();

	glPopMatrix();
}

void igvEscena3D::set_rotar() {
	rotar += 90;
}
void igvEscena3D::set_escal() {
	escalar += 0.8;
}



