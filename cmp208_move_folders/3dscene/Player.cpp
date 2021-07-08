#include "Player.h"

Player::Player()
{
	input_manager = nullptr;
	transform = &transform_;
	rotate.SetIdentity();
	rotate.RotationZ((float)(((3.14159 * 2) / 360) * 45));
	translate.SetIdentity();
	translate.SetTranslation(gef::Vector4(0,0,0,0));
	scale.SetIdentity();
	scale.Scale(gef::Vector4(1, 1, 1, 1));
	edit_transform.SetIdentity();
	//transform_ = transform_ * scale * transform;//scale * translate;
}

Player::~Player()
{
}

void Player::init(PrimitiveBuilder& primitive_builder, InputManager* new_input_manager)
{
	mesh_ = primitive_builder.GetDefaultCubeMesh();
	input_manager = new_input_manager;
}

void Player::Update(float dt)
{

	/*
	float speed = 3;
	gef::Vector4 direction = gef::Vector4(0,0,0,0);
	//rotate.RotationZ((float)(((3.14159 * 2)/360)*45));

	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_D)) {
		direction.set_x(direction.x() + 1);
	}
	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_A)) {
		direction.set_x(direction.x() - 1);
	}

	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_R)) {
		float rotation_amount = (2 * 3.14159 / 360) * 45 * dt;
		rotate.RotationZ(rotation_amount);
		transform_ = transform_ * rotate;
	}
	if (direction.LengthSqr() > 0) {
		direction.Normalise();
		direction *= dt;
		translate.SetTranslation(direction);
		transform_ = transform_ * translate;
	}
	*/

}

void Player::Render(Renderer3D& renderer) {
	renderer.DrawMesh(*this);
}
