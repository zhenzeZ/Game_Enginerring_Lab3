#include "Game.h"

Game::Game()
{
	m_window = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 600, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}
	else
	{
		m_idleTexture = IMG_LoadTexture(m_renderer, "ASSETS\\Idle.png");
		m_leftTexture = IMG_LoadTexture(m_renderer, "ASSETS\\Left.png");
		m_rightTexture = IMG_LoadTexture(m_renderer, "ASSETS\\Right.png");
		m_upTexture = IMG_LoadTexture(m_renderer, "ASSETS\\Up.png");
	}

	m_idle = new AnimatedSprite(m_idleTexture);
	m_up = new AnimatedSprite(m_upTexture);
	m_left = new AnimatedSprite(m_leftTexture);
	m_right = new AnimatedSprite(m_rightTexture);

	for (int i = 0; i < 3; i++ )
	{
		rect = SDL_Rect({ i * 32, 0, 32, 32 });
		m_idle->addFrame(rect);
		m_up->addFrame(rect);
		m_left->addFrame(rect);
		m_right->addFrame(rect);
	}

	m_Sprites.push_back(m_idle);
	m_Sprites.push_back(m_up);
	m_Sprites.push_back(m_left);
	m_Sprites.push_back(m_right);

	m_input = new Input();
	m_player = new Player(m_Sprites);
	m_handler = new InputHandler(m_input);

}

Game::~Game()
{
}

void Game::run()
{
	const Uint32 fps = 60;
	const Uint32 minimumFrameTime = 1000 / fps;

	Uint32 frameTime;
	Uint32 lastFrameTime = 0;
	Uint32 deltaTime = 0;

	while (!m_exitGame) {

		processEvents();
		frameTime = SDL_GetTicks();

		deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
			SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_exitGame = true;
			break;
		case SDL_KEYDOWN:
			m_handler->handleInput(event.key.keysym.sym);
			if (event.key.keysym.sym == SDLK_ESCAPE)
				m_exitGame = true;
			break;
		}
	}
}

void Game::update()
{
	m_player->update();
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderClear(m_renderer);

	int curF = m_player->getAnimatedSprite(m_input)->getCurrentFrame();
	SDL_RenderCopy(m_renderer, m_player->getAnimatedSprite(m_input)->m_spriteTexture, &m_player->getAnimatedSprite(m_input)->getFrame(curF), &bounds);

	SDL_RenderPresent(m_renderer);

}