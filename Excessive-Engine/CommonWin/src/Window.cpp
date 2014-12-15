#include "Window.h"
#include "SFML\Window\Event.hpp"

#include <cassert>

// TMP
#include <iostream>

Window::Window(const rWindow& d) 
:lastMouseX(0), lastMouseY(0), evt(*new (eventSpace) sf::Event) {
	std::cout << sizeof(sf::Event) << std::endl;
	std::cout.flush();
	w.create(sf::VideoMode(d.clientW, d.clientH), d.capText.c_str());
	w.setVerticalSyncEnabled(true);
}

bool Window::popEvent(rWindowEvent* evt_out) {
	bool b = w.pollEvent(evt);
	
	evt_out->msg = (eWindowMsg)(evt.type);

	// Key press release
	if (evt.type == sf::Event::EventType::KeyPressed || evt.type == sf::Event::EventType::KeyReleased) {
		evt_out->mouseBtn = eMouseBtn::INVALID;

		evt_out->key = (eKey)((int)evt.key.code);
		evt_out->mouseDeltaX = 0;
		evt_out->mouseDeltaY = 0;
		evt_out->mouseX = 0;
		evt_out->mouseY = 0;
	} else 
	if (evt.type == sf::Event::EventType::MouseMoved) {
		evt_out->key == eKey::INVALID;
		evt_out->mouseBtn = eMouseBtn::INVALID;

		evt_out->mouseDeltaX = evt.mouseMove.x - lastMouseX;
		evt_out->mouseDeltaY = evt.mouseMove.y - lastMouseY;
		evt_out->mouseX = evt.mouseMove.x;
		evt_out->mouseY = evt.mouseMove.y;

		lastMouseX = evt.mouseMove.x;
		lastMouseY = evt.mouseMove.y;
	} else
	if (evt.type == sf::Event::EventType::MouseEntered)
	{
		mm::ivec2 mousePos = Sys::getMousePos();

		sf::Vector2i windowPos = w.getPosition();

		lastMouseX = mousePos.x;
		lastMouseY = mousePos.y;
	}
	else
	if (evt.type == sf::Event::EventType::MouseButtonPressed || evt.type == sf::Event::EventType::MouseButtonReleased)
	{
		evt_out->key == eKey::INVALID;
		evt_out->mouseDeltaX = 0;
		evt_out->mouseDeltaY = 0;

		evt_out->mouseX = evt.mouseButton.x;
		evt_out->mouseY = evt.mouseButton.y;
		evt_out->mouseBtn = (eMouseBtn)((int)evt.mouseButton.button + 1); //  1 cuz our enum start with (out of sfml custom "INVALID" enum member)
	} else
	if (evt_out->msg == eWindowMsg::CLOSE)
		close();

	return b;
}

void Window::close() {
	w.close();
}

void Window::displayClientRect() {
	w.display();
}

bool Window::isOpen() const {
	return w.isOpen();
}

u16 Window::getClientW() const {
	return w.getSize().x;
}

u16 Window::getClientH() const {
	return w.getSize().y;
}

float Window::getClientAspectRatio() const {
	const sf::Vector2u size = w.getSize();
	return (float)size.x / size.y;
}

void Window::setText(const wchar_t* text) {
	w.setTitle(text);
}