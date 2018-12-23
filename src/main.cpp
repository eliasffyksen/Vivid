#include <cstdlib> // for testing

// Include standard headers
#include <vivid/vivid.h>
#include <vivid/graphics/window.h>
#include <glm/glm.hpp>
#include <vivid/input/input.h>
#include <vivid/graphics/shader.h>
#include <vivid/scenegraph/sprite.h>
#include <vivid/graphics/batchrenderer2D.h>
#include <vivid/scenegraph/gameobject.h>
#include <vivid/graphics/texture.h>
#include <vivid/scenegraph/scene.h>

#include <vivid/util/maths.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

int main() {
	using namespace vivid;
	using namespace graphics;

	Window window("Vivid", 600, 600); // THIS HAS TO BE THE FIRST THING!!
	Input input(window);

	LOG("--------------------------------------------------------------------------");
	LOG("    Running Vivid Engine version " << VIVID_VERSION_MAJOR << "." << VIVID_VERSION_MINOR
											<< (VIVID_DEBUG ? " (test build)" : ""));
	LOG("    Opengl " << glGetString(GL_VERSION));
	LOG("--------------------------------------------------------------------------");
	LOG("");

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // todo: actual alpha stufffffsss IT'S GONNA BE HELL ?

	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);

	Shader simple("shaders/simple");

	BatchRenderer2D batch;
	BatchRenderer2D batchgui;
	std::vector<Sprite *> sprites;
	GameObject root;
	srand((unsigned int) time(NULL));

	float size = 12.0f;
	float affinity = 2.0f / size;

	for (float y = -1.0f; y < 1.0f; y += affinity)
		for (float x = -1.0f; x < 1.0f; x += affinity)
			sprites.push_back(new Sprite(x, y, affinity, affinity,
										 glm::vec4((rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0,
												   (rand() % 1000) / 1000.0, 1)));

	for (int i = 0; i < sprites.size(); i++) {
		root.addChild(*sprites[i]);
	}

	Sprite goat(-0.5f, -0.5f, 1.0f, 1.0f, glm::vec4(1.0, 0, 1.0, 1));
//    Sprite goat2(-0.5f, -0.5f, 1.0f, 1.0f, glm::vec4(1.0, 0, 1.0, 1));

	Texture texture("images/cartoon_goat.png");

	LOG(sprites.size() << " sprites");

	Scene scene;
	Layer *worldLayer = scene.createLayer(&batchgui, 1);
	Layer *guiLayer = scene.createLayer(&batch, 10);

	worldLayer->addChild(goat);
	guiLayer->addChild(root);

	root.getTransform().setScale(glm::vec3(0.1, 0.1, 1));
	root.getTransform().setPosition(glm::vec3(-0.9f, 0.9f, 0));

	double sx = 0.5, sy = 0.5;
	double x = 0, y = 0;
	float angle = 0;
	float omega = (float) (M_PI * 2.0f / 18.0f);

	float fpsTime = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();
	timer.elapsed();

	input.registerKeyAlias("up", Input::UP);
	input.registerKeyAlias("down", Input::DOWN);
	input.registerKeyAlias("left", Input::LEFT);
	input.registerKeyAlias("right", Input::RIGHT);

//    window.close();

	while (!window.isClosed()) {
		window.clear();
		float delta = (float) timer.elapsed();

//		input.getCursorPosition(x, y);

//		x += delta * sx;
//		y += delta * sy;
		angle += omega * delta;

		if (input.keyDown("up")) {
			y += delta * sy;
		}
		if (input.keyDown("down")) {
			y -= delta * sy;
		}
		if (input.keyDown("left")) {
			x -= delta * sx;
		}
		if (input.keyDown("right")) {
			x += delta * sx;
		}

		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::R)) {
			x = y = 0;
		}
		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::W)) {
			window.close();
		}

		simple.bind();
		texture.bind(0);

//		maths::quat q(angle, maths::vec3(0, 0, 1));
		goat.getTransform().setPosition(glm::vec3(x, y, 0));
//		goat.getTransform().setRotation(glm::quat(-q.w, q.x, q.y, q.z));

//		guiLayer->render();
//		worldLayer->render();
		scene.render();

		texture.unbind();
		simple.unbind();

		input.clear();
		window.update();
		fpsTime += delta;
		fpsCount++;
		if (fpsTime >= 1) {
			fpsTime--;
			LOG(fpsCount << " fps");
			fpsCount = 0;
		}
	}

	return 0;
}

