#include "MovingCamera.h"
void MovingCamera::Update(float frame_time)
{
	gef::Vector4 direction = gef::Vector4(0, 0, 0, 0);
	float speed = 3;
	if (keyboard) {

		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_W)) {
			direction.set_z(direction.z() - 1);
		}
		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_S)) {
			direction.set_z(direction.z() + 1);
		}
		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_D)) {
			direction.set_x(direction.x() + 1);
		}
		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_A)) {
			direction.set_x(direction.x() - 1);
		}
		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_Q)) {
			direction.set_y(direction.y() + 1);
		}
		if (keyboard->IsKeyDown(gef::Keyboard::KeyCode::KC_E)) {
			direction.set_y(direction.y() - 1);
		}

		if (direction.x() != 0 || direction.y() != 0 || direction.z() != 0) {
			direction.Normalise();
			direction *= (speed * frame_time);

			//position += direction;
			//looking_at = position + gef::Vector4(0, 0, -1);
		}
	}
	gef::Matrix44 rotate, translate;

	//rotate.SetIdentity();
	//rotate.RotationZ(frame_time * (((2*3.14159) / 360) * 20) );
	//translate.SetIdentity();
	//translate.SetTranslation(-direction);
	//transform = transform;// * rotate * translate;

	//transform.LookAt(position, looking_at, up);


}