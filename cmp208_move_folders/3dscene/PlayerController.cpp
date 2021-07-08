#include "PlayerController.h"
void PlayerController::Update(float dt)
{

	float speed = 3;
	gef::Vector4 direction = gef::Vector4(0, 0, 0, 0);
	edit_transform.SetIdentity();

	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_D)) {
		direction.set_x(direction.x() + 1);
	}
	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_A)) {
		direction.set_x(direction.x() - 1);
	}

	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_F)) {
		gef::Vector4 scale_amount = gef::Vector4(0.999 ,0.999 ,0.999 ,1);
		scale.Scale(scale_amount);
		edit_transform = edit_transform * scale;
	}
	if (input_manager->keyboard()->IsKeyDown(gef::Keyboard::KeyCode::KC_R)) {
		float rotation_amount = (2 * 3.14159 / 360) * 45 * dt;
		rotate.RotationZ(rotation_amount);
		edit_transform = edit_transform * rotate;
	}
	if (direction.LengthSqr() > 0) {
		direction.Normalise();
		direction *= dt;
		translate.SetTranslation(direction);
		edit_transform = edit_transform * translate;
	}
	*transform = edit_transform * *transform;
}