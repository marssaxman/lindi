#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <ncurses.h>

class Controller
{
public:
	virtual ~Controller() = default;
	// A view has been created or has been cleared.
	// Fill it as necessary based on current model state.
	virtual void paint(WINDOW *view) = 0;
	// A keypress has occurred. Update model and view.
	// Return true if the process should continue, false if
	// the keypress represented a close action.
	virtual bool process(WINDOW *view, int ch) = 0;
	// Time has passed. Poll the inputs, if relevant.
	// Return true if the process should continue, false if
	// some input has occurred which signals process completion.
	virtual bool poll(WINDOW *view) = 0;
	// Human-readable string identifying the object.
	virtual std::string title() const = 0;
};

#endif // CONTROLLER_H