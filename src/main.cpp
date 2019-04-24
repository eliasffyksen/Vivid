#include <cstdlib> // for testing

// Include standard headers
#include <vivid/core.h>
#include <vivid/graphics/window.h>
#include <vivid/input/input.h>
#include <vivid/vivid.h>
#include <vivid/graphics/shader.h>
#include <vivid/scenegraph/sprite.h>
#include <vivid/graphics/batchrenderer2D.h>
#include <vivid/scenegraph/gameobject.h>
#include <vivid/graphics/texture.h>
#include <vivid/scenegraph/scene.h>
#include <vivid/util/maths.h>
#include <VividImage/image.h>

#include "vivid/events/windowEvent.h"
#include "vivid/graphics/font.h"

int main() {
	using namespace vivid;
	using namespace graphics;

	VividApplication app("Vivid", 600, 600);

	LOG("--------------------------------------------------------------------------");
	LOG("    Running Vivid Engine version " << VIVID_VERSION_MAJOR << "." << VIVID_VERSION_MINOR << (VIVID_DEBUG ? " (test build)" : ""));
	LOG("    OpenGL " << glGetString(GL_VERSION));
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
			sprites.push_back(new Sprite(x, y, affinity, affinity));

	for (int i = 0; i < sprites.size(); i++) {
		root.addChild(*sprites[i]);
	}

	Sprite goat(-0.5f, -0.5f, 1.0f, 1.0f);
	goat.getTransform().setScale(vdm::vec3(2, 2, 2));
	goat.getTransform().setScale(vdm::vec3(0.1f));

	unsigned int width = 128;
	unsigned int height = width;

	unsigned int pixels[width * height];
	for (int i = 0; i < width * height; i++)
		pixels[i] = 0xFF000000;

//	Font font("fonts/roboto-slab/RobotoSlab-Light.ttf");
	Font font("fonts/Aaargh/Aaargh.ttf");
	font.init();
//	font.renderBitmapOutline(pixels, width, height, '@');
//	font.renderBitmapOutline(pixels, width, height, 'C');
//	font.renderBitmap(pixels, width, height, 'C');
//	font.renderBitmap(pixels, width, height, '@');
//	font.renderBitmap(pixels, width, height, 'A');
//	font.renderBitmapOutline(pixels, width, height, 'A');
//	Image image(pixels, width, height, VIVID_IMAGE_FORMAT_RGBA);

	Texture& texture = font.getTexture(200);
//	Texture texture("images/cartoon_goat.png");

//	LOG(sprites.size() << " sprites");

	Scene scene;
	Layer *worldLayer = scene.createLayer(&batchgui, 1);
	//Layer *guiLayer = scene.createLayer(&batch, 10);

	worldLayer->addChild(goat);
//	guiLayer->addChild(root);

	root.getTransform().setScale(vdm::vec3(0.1, 0.1, 1));
	root.getTransform().setPosition(vdm::vec3(-0.9f, 0.9f, 0));

	float mx, my;
	float sx = 0.5, sy = 0.5;
	float x = 0, y = 0;
	float angle = 0.5;
	float omega = (VD_PI * 2.0f / 5.0f);
	bool toggled = false;

	float fpsTime = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();
	timer.elapsed();

	Input &input = app.getInput();
	input.registerKeyAlias("up", Input::UP);
	input.registerKeyAlias("down", Input::DOWN);
	input.registerKeyAlias("left", Input::LEFT);
	input.registerKeyAlias("right", Input::RIGHT);

	input.registerKeyAlias("rotate right", Input::E);
	input.registerKeyAlias("rotate left", Input::Q);

	input.registerKeyAlias("toggle", Input::SPACE);

	Window &window = app.getWindow();

	vdm::vec2 mouse;

	app.start();
	while (app.isRunning()) {
		window.clear();
		auto delta = (float) timer.elapsed();

		input.getCursorPosition(mouse);

		if (input.keyPressed("rotate left")) {
			angle += 0.25f;
			if (angle >= 1)
				angle = 1;
		}
		if (input.keyPressed("rotate right")) {
			angle -= 0.25f;
			if (angle < 0)
				angle = 0;
		}

		if (input.keyDown("up"))
			y += delta * sy;
		if (input.keyDown("down"))
			y -= delta * sy;
		if (input.keyDown("left"))
			x -= delta * sx;
		if (input.keyDown("right"))
			x += delta * sx;

		if (input.keyPressed("toggle")) {
			toggled = !toggled;
		}

		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::R)) {
			x = y = 0;
		}
		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::W)) {
			window.close();
		}

		simple.bind();
//		texture.bind(0);
		texture.bind(0);

		goat.getTransform().setPosition(vdm::vec3(x, y, 0));
		float omega = 10;

		vdm::vec2 dir = mouse - goat.getTransform().getPosition().xy();
		vdm::quat goal = vdm::quat((float) atan2(dir.y, dir.x), vdm::vec3(0, 0, 1));
		vdm::quat qOffset(-VD_PI_2, vdm::vec3(0, 0, 1));
		goal = qOffset * goal;
		vdm::quat cur = vdm::quat(goat.getTransform().getRotation().w, goat.getTransform().getRotation().x, goat.getTransform().getRotation().y, goat.getTransform().getRotation().z);
		vdm::quat q = vdm::slerp(cur, goal, vdm::clamp(omega * delta * vdm::angle(cur, goal), 0.005f, 1.0f));
		if (toggled)
			goat.getTransform().setRotation(q);

		if (toggled) {
			q = vdm::quat(VD_PI_4, vdm::vec3(0, 0, -1));
		} else {
			q = vdm::quat(0, vdm::vec3(0, 0, -1));
		}
		root.getTransform().setRotation(q);

		scene.render();

		texture.unbind();
//		texture.unbind();
		simple.unbind();

		input.clear();
		window.update();
		fpsTime += delta;
		fpsCount++;
		if (fpsTime >= 1) {
			fpsTime--;
//			LOG(fpsCount << " fps");
			fpsCount = 0;
		}
	}

	return 0;
}

