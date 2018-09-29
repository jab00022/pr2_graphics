#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <glut.h>
#endif

class igvEscena3D {
    public:
        const int SceneA = 1;
		const int SceneB = 2;

		const char *SceneA_Name = "Scene A";
		const char *SceneB_Name = "Scene B";

	protected:
		// Atributos
		bool ejes;
		int rotar = 0;
		float escalar = 0.5;
        // Declarar variables para manejar las transformaciones para la escena B


	public:
		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos estáticos

		// Métodos
		// método con las llamadas OpenGL para visualizar la escena
        void visualizar(int scene);

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};

		void set_escal();
		void set_rotar();

		// Definir las funciones get y set para las nuevas variables de la escena B

    protected:
        void renderSceneA();
        void renderSceneB();

};

#endif
