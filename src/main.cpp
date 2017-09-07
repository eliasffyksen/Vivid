// Include standard headers
#include <iostream>
#include <unistd.h>

#include "vivid/vivid.h"
#include "vivid/graphics/sprite.h"
#include "vivid/graphics/buffers/buffer.h"
#include "vivid/graphics/buffers/indexbuffer.h"
#include "vivid/graphics/buffers/vertexarray.h"
#include "vivid/graphics/batchrenderer2D.h"

#include "time.h"

int main() {
	using namespace vivid;
	using namespace graphics;
	
	Window window("Window!!", 800, 600);
	Input input(window.window);
	
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	Shader simple("shaders/simple");
	
	BatchRenderer2D batch;
	std::vector<Renderable2D*> sprites;
	srand(time(NULL));
	
	float size = 100.0f;
	float affinity = 2.0f/size;
	
	for (float y = -1.0f; y < 1.0f; y += affinity) {
		for (float x = -1.0f; x < 1.0f; x += affinity) {
			 sprites.push_back(new Sprite(x, y, affinity, affinity, glm::vec4((rand() % 1000) / 1000.0, 0, 0, 1)));
		}
	}
	
	Sprite sprite(-0.5f, -0.5f, 1.0f, 1.0f, glm::vec4(0.6, 0, 0.6, 1));
	
	LOG(sprites.size() << " sprites");
	
	input.registerKeyAlias("Let's go", Input::UP);
	
	float fpsTimer = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();
	while (!window.isClosed()) {
		if (input.keyPressed(GLFW_KEY_SPACE))
			LOG("DOWN");
		if (input.keyReleased(GLFW_KEY_SPACE))
			LOG("UP");
		
		float delta = timer.elapsed();
		
		if (input.keyPressed("Let's go"))
			LOG("IT'S GOING DOW... up?!");
		
		window.clear();
		simple.bind();
		
		batch.begin();
		for(auto renderable : sprites)
			batch.submit(renderable);
		batch.end();
		batch.flush();
		
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

