#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		IDLE,
		UP,
		LEFT,
		RIGHT
	};

	void setCurrent(Action);
	Action getCurrent();

	void setIdle() { m_current = Action::IDLE; };
	void setUp() { m_current = Input::Action::UP; };
	void setLeft() { m_current = Input::Action::LEFT; };
	void setRight() { m_current = Input::Action::RIGHT; };

private:
	Action m_current;
};
#endif