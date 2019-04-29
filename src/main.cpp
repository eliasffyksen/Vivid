// Include standard headers
#include <vivid/core.h>
#include <vivid/graphics/window.h>
#include <vivid/input/input.h>
#include <vivid/vivid.h>
#include <vivid/events/windowEvent.h>

#include <vivid/graphics/shader.h>
#include <vivid/scenegraph/sprite.h>
#include <vivid/graphics/batchrenderer2D.h>
#include <vivid/scenegraph/gameobject.h>
#include <vivid/graphics/texture.h>
#include <vivid/scenegraph/scene.h>
#include <vivid/util/maths.h>
#include <VividImage/image.h>
#include <vivid/scenegraph/textureatlas.h>
#include <vivid/scenegraph/Text.h>
#include <vivid/graphics/font.h>


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

	TextureAtlas atlas(1);
	Image atlas1("images/atlas1.png");
	Image atlas4("images/atlas4.png");
	Image atlasgoat("images/cartoon_goat.png");
	auto arrowHandle = atlas.registerTexture(atlas1);
	auto goathandle = atlas.registerTexture(atlasgoat);

//	Font font("fonts/Aaargh/Aaargh.ttf", atlas);
	Font font("fonts/roboto-slab/RobotoSlab-Light.ttf", atlas);
	font.init(12);

	GameObject goat;
//	goat.getTransform().setScale(0.5f);
	Sprite atlasSprite(-0.5f, -0.5f, 1.0f, 1.0f, nullptr);
	atlasSprite.getTransform().setScale(vdm::vec3(2.0f));
	Sprite goatSprite(-0.5f, -0.5f, 1.0f, 1.0f, goathandle);
//	Sprite goat(-0.5f, -0.5f, 1.0f, 1.0f, &font.getTexture('X'));
//	goat.getTransform().setScale(vdm::vec3(2.0f));
//	goat.getTransform().setScale(vdm::vec3(1.0f));
//	goat.getTransform().setScale(vdm::vec3(0.1f));
	Sprite arrow(-0.5f, -0.5f, 1.0f, 1.0f, arrowHandle);
	arrow.getTransform().setScale(0.5);

	Sprite spriteX(0.025, -0.0f, 0.304348f, 0.423913f, &font.getTexture('X'));
	Sprite spriteA(0.36413, -0.0f, 0.336957f, 0.423913f, &font.getTexture('A'));
	Sprite spriteh(0.36413 + 0.359783 + 0.0516304, -0.0f, 0.271739f, 0.5f, &font.getTexture('h'));
	Sprite spritex(0.36413 + 0.359783 + 0.360326 + 0.0163043, -0.0f, 0.271739f, 0.304348f, &font.getTexture('x'));
//	spriteX.getTransform().setScale(0.2);
//	spriteA.getTransform().setScale(0.2);
//	spriteh.getTransform().setScale(0.2);
//	spritex.getTransform().setScale(0.2);

//	LOG(sprites.size() << " sprites");

	Text text(font, "A");
//	text.getTransform().getPosition().x = -1.0f;
	text.getTransform().getPosition().x = -0.5f;
	text.getTransform().setScale(vdm::vec3(0.68f));

	Scene scene;
	Layer *worldLayer = scene.createLayer(&batchgui, 1);
	//Layer *guiLayer = scene.createLayer(&batch, 10);

	goat.addChild(goatSprite);
//	goat.addChild(atlasSprite);
//	goat.addChild(spriteX);
//	goat.addChild(spriteA);
//	goat.addChild(spriteh);
//	goat.addChild(spritex);
	worldLayer->addChild(text);
//	worldLayer->addChild(goat);
//	worldLayer->addChild(arrow);

	float sx = 0.5, sy = 0.5;
	float x = 0.0f, y = 0;
	float angle = 0;
	float omega = (VD_PI * 2.0f / 5.0f);
	float omegaArrow = VD_PI * 2.0f / 2.0f;
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

	float bigTimer = 0.0f;
	bool isBig = false;

	app.start();
	while (app.isRunning()) {
		window.clear();
		auto delta = (float) timer.elapsed();

		input.getCursorPosition(mouse);

		if (toggled) {
			if (isBig) {
				bigTimer -= delta;
				if (bigTimer <= 0) {
					isBig = false;
					arrow.getTransform().setScale(0.5f);
				}
			}

			if (!isBig && input.mouseButtonPressed(Input::LEFT_MOUSE)) {
				isBig = true;
				bigTimer = 0.15f;
				arrow.getTransform().setScale(vdm::vec3(0.5, 0.75f, 1.0f));
			}
		}

		if (input.keyDown("rotate left")) {
			angle += omega * delta;
		}
		if (input.keyDown("rotate right")) {
			angle -= omega * delta;
		}

		if (input.keyDown("up") || input.keyDown(Input::W))
			y += delta * sy;
		if (input.keyDown("down") || input.keyDown(Input::S))
			y -= delta * sy;
		if (input.keyDown("left") || input.keyDown(Input::A))
			x -= delta * sx;
		if (input.keyDown("right") || input.keyDown(Input::D))
			x += delta * sx;

		if (input.keyPressed("toggle")) {
			toggled = !toggled;
		}

		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::R)) {
			x = y = 0;
			angle = 0;
		}
		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::W)) {
			window.close();
		}
		goat.getTransform().setRotation(vdm::quat(angle, vdm::vec3(0, 0, 1)));
		goat.getTransform().setPosition(vdm::vec3(x, y, 0));

		simple.bind();
		atlas.update();
		atlas.bind(Texture::TEXTURE_MAP);

		if (toggled) {
			vdm::vec2 dir = mouse - arrow.getTransform().getPosition().xy();
			vdm::quat goal = vdm::quat(atan2f(dir.y, dir.x), vdm::vec3(0, 0, 1));
			vdm::quat qOffset(-VD_PI_2, vdm::vec3(0, 0, 1));
			goal = qOffset * goal;
			vdm::quat cur = vdm::quat(arrow.getTransform().getRotation().w, arrow.getTransform().getRotation().x, arrow.getTransform().getRotation().y, arrow.getTransform().getRotation().z);
			vdm::quat q = vdm::slerpTowards(cur, goal, omegaArrow * delta);
			arrow.getTransform().setRotation(q);
		}

		scene.render();

		atlas.unbind();
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

