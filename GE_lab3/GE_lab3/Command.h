#pragma once
#include "Player.h"
#include "Input.h"
//command interface
class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command() {}

};

class Left : public Command {
public:
	Left(Input* input) : m_input(input){}
	virtual void execute() override
	{
		m_input->setLeft();
	}
private:
	Input* m_input;
};

class Right : public Command {
public:
	Right(Input* input) : m_input(input) {}
	virtual void execute() override
	{
		m_input->setRight();
	}
private:
	Input* m_input;
};

class Up : public Command {
public:
	Up(Input* input) : m_input(input) {}
	virtual void execute() override
	{
		m_input->setUp();
	}
private:
	Input* m_input;
};

class Down : public Command {
public:
	Down(Input* input) : m_input(input) {}
	virtual void execute() override
	{
		m_input->setIdle();
	}
private:
	Input* m_input;
};