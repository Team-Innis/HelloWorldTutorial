#include "../include/MenuScene.hpp"

#include <UtH/Engine/UtHEngine.h>
#include <UtH/Platform/Debug.hpp> //WriteLog(...), works like printf.
#include <UtH/Engine/Text.hpp>
#include <UtH/Engine/AnimatedSprite.hpp>
#include <UtH/Platform/Input.hpp>

using namespace uth;

// Main initialisation.
// Automatically called inside SceneManager.
bool MenuScene::Init()
{
	// Some shader must be loaded and set window to use it
	m_shader.LoadShader("Shaders/Default.vert", "Shaders/Default.frag");
	m_shader.Use();
	uthEngine.GetWindow().SetShader(&m_shader);

	uthEngine.GetWindow().GetCamera()
		.SetPosition(uthEngine.GetWindow().GetSize()/2);

	helloGO = new GameObject();
	helloGO->AddComponent(new Text("kenpixel.ttf", 24.f));

	helloGO->GetComponent<Text>("Text")->AddText("Hello World!");
	helloGO->transform.SetPosition(uthEngine.GetWindow().GetSize().x / 2, 256.f);

	animGO = new GameObject();
	animGO->AddComponent(new uth::AnimatedSprite(
		new Texture("planetsheet.tga"), 25, 5, 5, 10));

	return true;
}

// Main deinitialisation.
// Automatically called inside SceneManager.
bool MenuScene::DeInit()
{
	delete helloGO;
	delete animGO;
	return true;
}

// Update loop. Gone trought once per frame.
bool MenuScene::Update(float dt)
{
	animGO->transform.SetPosition(uthInput.Mouse.Position());

	animGO->Update(dt);
	return true; // Update succeeded.
}

// Draw loop. All graphics are drawn during this loop.
bool MenuScene::Draw()
{
	animGO->Draw(uthEngine.GetWindow());
	helloGO->Draw(uthEngine.GetWindow());

	return true; // Drawing succeeded.
}

//Default constructor for initialising constant variables.
MenuScene::MenuScene()
{

}
//Default deconstrutor.
MenuScene::~MenuScene()
{

}