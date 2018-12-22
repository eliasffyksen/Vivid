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

#if VIVID_DEBUG // random stuff that looks kinda cool
	LOG("--------------------------------------------------------------------------");
	LOG("  Running Vivid Engine version " << VIVID_VERSION_MAJOR << "." << VIVID_VERSION_MINOR
	                                      << (VIVID_DEBUG ? " (test build)" : ""));
	LOG("  Opengl " << glGetString(GL_VERSION));
	LOG("--------------------------------------------------------------------------");
	LOG("");
#endif

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // todo: actual alpha stufffffsss IT'S GONNA BE HELL ?

	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);

	Shader simple("shaders/simple");

	BatchRenderer2D batch;
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

	Sprite littlesprite(-0.5f, -0.5f, 1.0f, 1.0f, glm::vec4(1.0, 0, 1.0, 1));

	Texture texture("images/cartoon_goat.png");

	LOG(sprites.size() << " sprites");

	Scene scene;
//	Layer *guiLayer = scene.createLayer(100);
	Layer *worldLayer = scene.createLayer(0);

	worldLayer->setRenderer(&batch);
	worldLayer->addChild(littlesprite);
//	guiLayer->setRenderer(&batch);
//	guiLayer->addChild(littlesprite);

	double sx = 0.2, sy = 0;
	double x = 0, y = 0;
	float angle = 0;
	float omega = (float) (M_PI * 2.0f / 18.0f);

	float fpsTimer = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();

	while (!window.isClosed()) {
		window.clear();
		float delta = timer.elapsed();

		//input.getCursorPosition(x, y);

		x += delta * sx;
		y += delta * sy;
		angle += omega * delta;

		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::R)) {
			x = y = 0;
		}
		if ((input.keyDown(Input::LEFT_CONTROL) || input.keyDown(Input::RIGHT_CONTROL)) && input.keyPressed(Input::W)) {
			window.close();
		}


//		batch.pushMatrix(glm::translate(glm::vec3(2.0f * (x / window.getWidth() - 0.5f), 2.0f * (0.5f - y / window.getHeight()), 0.0f)));
//		batch.pushMatrix(glm::translate(glm::vec3(x, y, 0)));
		batch.pushMatrix(glm::rotate(angle, glm::vec3(0.0, 0.0, -1.0)));
//		batch.pushMatrix(glm::scale(glm::vec3(2.0, 2.0, 2.0)));

		simple.bind();
		texture.bind(0);

//		batch.begin();
//		for (auto sprite : sprites)
//			batch.submit(&(sprite->getRenderable()));
//		batch.submit(&littlesprite.getQuad());
//		batch.end();

//		batch.popMatrix();

//		batch.flush();

		//littlesprite.getTransform().setRotation(gtx::quaternion::angleAxis(0, glm::vec3(1, 0, 0)))
		scene.render();
//		batch.submit(&littlesprite.getQuad());
//		littlesprite.renderObject(&batch);

		texture.unbind();
		simple.unbind();

//		batch.popMatrix();
		batch.popMatrix();

		input.clear();
		window.update();
		fpsTimer += delta;
		fpsCount++;
		if (fpsTimer >= 1) {
			fpsTimer--;
			LOG(fpsCount << " fps");
			fpsCount = 0;
		}
	}

	return 0;
}

