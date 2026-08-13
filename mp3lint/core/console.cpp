#include "console.h"

void Console::SetOutputCallback(OutputCallback callback) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_outputCallback = std::move(callback);
}

void Console::SetErrorCallback(OutputCallback callback) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_errorCallback = std::move(callback);
}

void Console::SetInputCallback(InputCallback callback) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_inputCallback = std::move(callback);
}

void Console::Write(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	// Always write to native console
	std::cout << message;

	// Route to callback if set
	if (m_outputCallback) {
		m_outputCallback(message);
	}
}

void Console::WriteLine(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::cout << message << std::endl;

	if (m_outputCallback) {
		std::string msgWithNewline = std::string(message) + "\n";
		m_outputCallback(msgWithNewline);
	}
}

void Console::WriteError(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::cerr << message << std::endl;

	if (m_errorCallback) {
		std::string msgWithNewline = std::string(message) + "\n";
		m_errorCallback(msgWithNewline);
	}
}

std::string Console::ReadLine() {
	std::lock_guard<std::mutex> lock(m_mutex);

	// If there's an input callback for the GUI or custom widget, use it
	if (m_inputCallback) {
		return m_inputCallback();
	}

	// Otherwise fallback to std::cin
	std::string input;
	std::getline(std::cin, input);
	return input;
}
