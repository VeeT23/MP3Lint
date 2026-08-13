#pragma once

#include <string>
#include <functional>
#include <iostream>
#include <sstream>
#include <mutex>
#include <string_view>

class Console {
public:
	static Console& GetInstance() {
		static Console instance;
		return instance;
	}

	// Callbacks for routing output to the GUI widget
	using OutputCallback = std::function<void(std::string_view)>;
	using InputCallback = std::function<std::string()>;

	void SetOutputCallback(OutputCallback callback);
	void SetErrorCallback(OutputCallback callback);
	void SetInputCallback(InputCallback callback);

	void Write(std::string_view message);
	void WriteLine(std::string_view message);
	void WriteError(std::string_view message);

	std::string ReadLine();

	// Stream-like interface
	template <typename T>
	Console& operator<<(const T& value) {
		std::ostringstream oss;
		oss << value;
		Write(oss.str());
		return *this;
	}

	// Support std::endl and other manipulators
	Console& operator<<(std::ostream& (*manip)(std::ostream&)) {
		std::ostringstream oss;
		oss << manip;
		Write(oss.str());
		return *this;
	}

private:
	Console() = default;
	~Console() = default;

	// Delete copy and move constructors
	Console(const Console&) = delete;
	Console& operator=(const Console&) = delete;
	Console(Console&&) = delete;
	Console& operator=(Console&&) = delete;

	OutputCallback m_outputCallback;
	OutputCallback m_errorCallback;
	InputCallback m_inputCallback;

	std::mutex m_mutex;
};
