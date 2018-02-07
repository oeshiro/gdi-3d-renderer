#pragma once

#include "SceneObject.h"
#include "Camera.h"

#include <vector>

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	// The Scene class represents a 3D scene that consists of SceneObjects.
	class Scene
	{
	public:
		Scene();
		//void renderScene(Renderer ^renderer);
		void addObject(SceneObject obj);

		// methods to manipulate objects;

		void setObjectPosition(int x_coord, int y_coord, int z_coord);
		void setObjectRotation(float x_angle, float y_angle, float z_angle);
		void setObjectReflection(bool xy, bool xz, bool yz);
		void setObjectScale(int x_scale, int y_scale, int z_scale);

		void resetObject();
		void deleteObject();
		void selectNextObject();
		void selectPreviousObject();

		// methods to manipulate camera:

		void setCameraPosition(int x_coord, int y_coord, int z_coord);
		void setCameraRotation(float pitch, float yawn, float roll);
		void resetCamera();

		// Sets projection mode: perspective if the parameter is true, orthographics otherwise.
		void setProjectionMode(bool perspective);
		// Sets drawing mode flags: wireframe and/or solid.
		void setDrawingMode(bool wireframe, bool solid);
		// Returns true is the scene contains no objects.
		bool isEmpty();

		// test
		void addCube();

		std::vector<SceneObject> sceneObjects;
		int selectedObject;
		bool isPerspective;
		bool drawWireframe;
		bool drawSolid;
		Camera camera;
	};
}