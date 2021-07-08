#pragma once
#include <graphics/mesh_instance.h>
#include "primitive_builder.h"
#include <graphics/renderer_3d.h>
#include <input/input_manager.h>
#include <input/keyboard.h>
using namespace gef;

class Player : gef::MeshInstance
{
public:
	Player();
	~Player();
	void init(PrimitiveBuilder& primitive_builder, InputManager* new_input_manager);
	void Update(float dt);
	void Render(Renderer3D& renderer);

//protected:
	gef::Matrix44 rotate, translate, scale, edit_transform;
	gef::Matrix44* transform;
	gef::InputManager* input_manager;
};

