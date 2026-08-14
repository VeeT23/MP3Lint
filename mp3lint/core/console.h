#pragma once

#include <string>
#include <string_view>
#include <functional>
#include <iostream>
#include <sstream>
#include <mutex>

class Console {
public:
	static Console& GetInstance() {
		static Console instance;
		return instance;
	}

	using OutputCallback = std::function<void(std::string_view)>;
	using InputCallback = std::function<std::string()>;

	void SetOutputCallback(OutputCallback callback);
	void SetErrorCallback(OutputCallback callback);
	void SetInputCallback(InputCallback callback);

	// Narrow / UTF-8
	void Write(std::string_view message);
	void WriteLine(std::string_view message);
	void WriteError(std::string_view message);

	// Wide / UTF-16 on Windows
	void Write(std::wstring_view message);
	void WriteLine(std::wstring_view message);
	void WriteError(std::wstring_view message);

	std::string ReadLine();
	std::wstring ReadLineW();

	// Stream interface
	template <typename T>
	Console& operator<<(const T& value) {
		std::ostringstream oss;
		oss << value;
		Write(oss.str());
		return *this;
	}

	Console& operator<<(std::string_view value) {
		Write(value);
		return *this;
	}

	Console& operator<<(const std::string& value) {
		Write(value);
		return *this;
	}

	Console& operator<<(std::wstring_view value) {
		Write(value);
		return *this;
	}

	Console& operator<<(const std::wstring& value) {
		Write(value);
		return *this;
	}

	Console& operator<<(const char* value) {
		Write(std::string_view(value));
		return *this;
	}

	Console& operator<<(const wchar_t* value) {
		Write(std::wstring_view(value));
		return *this;
	}

	Console& operator<<(wchar_t value) {
		Write(std::wstring_view(&value, 1));
		return *this;
	}

	Console& operator<<(std::ostream& (*manip)(std::ostream&)) {
		std::ostringstream oss;
		oss << manip;
		Write(oss.str());
		return *this;
	}

private:
	Console() = default;
	~Console() = default;

	Console(const Console&) = delete;
	Console& operator=(const Console&) = delete;
	Console(Console&&) = delete;
	Console& operator=(Console&&) = delete;

	static std::string WideToUtf8(std::wstring_view value);
	static std::wstring Utf8ToWide(std::string_view value);

	// Windows console output
	static void WriteConsoleWide(std::wstring_view value, bool error);

	OutputCallback m_outputCallback;
	OutputCallback m_errorCallback;
	InputCallback m_inputCallback;

	std::mutex m_mutex;
};