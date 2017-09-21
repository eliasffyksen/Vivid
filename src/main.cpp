// Include standard headers
#include <iostream>

#include "vivid/vivid.h"
#include "vivid/graphics/sprite.h"
#include "vivid/graphics/batchrenderer2D.h"
#include "vivid/scenegraph/gameobject.h"

#include "time.h"

int main() {
	using namespace vivid;
	using namespace graphics;
	
	GameObject ob;
	
	Window window("Window!!", 600, 600);
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
			 sprites.push_back(new Sprite(x, y, affinity, affinity, glm::vec4((rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0, (rand() % 1000) / 1000.0, 1)));
		}
	}
	
	Sprite sprite(-0.5f, -0.5f, 1.0f, 1.0f, glm::vec4(0.6, 0, 0.6, 1));
	
	LOG(sprites.size() << " sprites");
	
	double ox=-1, oy=-1;
	double x, y;
	
	float fpsTimer = 0.0f;
	int fpsCount = 0;
	Timer timer;
	timer.reset();
	while (!window.isClosed()) {
		float delta = timer.elapsed();
		
		input.getCursorPosition(x, y);
		if(x != ox || y != oy) {
			ox = x;
			oy = y;
			
			batch.popMatrix();
			batch.pushMatrix(glm::translate(glm::vec3(2.0f * (x / window.getWidth() - 0.5f), 2.0f * (0.5f - y / window.getHeight()), 0.0f)));
		}
		
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

