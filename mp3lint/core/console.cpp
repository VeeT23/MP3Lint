#include "console.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// ------------------------------------------------------------
// UTF-16 -> UTF-8
// ------------------------------------------------------------

std::string Console::WideToUtf8(std::wstring_view value) {
	if (value.empty())
		return {};

	int size = WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		value.data(),
		static_cast<int>(value.size()),
		nullptr,
		0,
		nullptr,
		nullptr
	);

	if (size <= 0)
		return {};

	std::string result(size, '\0');

	WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		value.data(),
		static_cast<int>(value.size()),
		result.data(),
		size,
		nullptr,
		nullptr
	);

	return result;
}

// ------------------------------------------------------------
// UTF-8 -> UTF-16
// ------------------------------------------------------------

std::wstring Console::Utf8ToWide(std::string_view value) {
	if (value.empty())
		return {};

	int size = MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		value.data(),
		static_cast<int>(value.size()),
		nullptr,
		0
	);

	if (size <= 0)
		return {};

	std::wstring result(size, L'\0');

	MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		value.data(),
		static_cast<int>(value.size()),
		result.data(),
		size
	);

	return result;
}

// ------------------------------------------------------------
// Native Windows console output
// ------------------------------------------------------------

void Console::WriteConsoleWide(std::wstring_view value, bool error) {
	if (value.empty())
		return;

	HANDLE handle = GetStdHandle(
		error ? STD_ERROR_HANDLE : STD_OUTPUT_HANDLE
	);

	if (handle == INVALID_HANDLE_VALUE || handle == nullptr)
		return;

	DWORD written = 0;

	WriteConsoleW(
		handle,
		value.data(),
		static_cast<DWORD>(value.size()),
		&written,
		nullptr
	);
}

// ------------------------------------------------------------
// Callbacks
// ------------------------------------------------------------

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

// ------------------------------------------------------------
// UTF-8 output
// ------------------------------------------------------------

void Console::Write(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	// Convert UTF-8 -> UTF-16 for the Windows console.
	std::wstring wide = Utf8ToWide(message);

	WriteConsoleWide(wide, false);

	// Callback receives UTF-8.
	if (m_outputCallback) {
		m_outputCallback(message);
	}
}

void Console::WriteLine(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::wstring wide = Utf8ToWide(message);
	wide += L'\n';

	WriteConsoleWide(wide, false);

	if (m_outputCallback) {
		std::string output(message);
		output += '\n';

		m_outputCallback(output);
	}
}

void Console::WriteError(std::string_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::wstring wide = Utf8ToWide(message);
	wide += L'\n';

	WriteConsoleWide(wide, true);

	if (m_errorCallback) {
		std::string output(message);
		output += '\n';

		m_errorCallback(output);
	}
}

// ------------------------------------------------------------
// Wide output
// ------------------------------------------------------------

void Console::Write(std::wstring_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	// Direct UTF-16 -> Windows console.
	WriteConsoleWide(message, false);

	// Convert to UTF-8 for the GUI.
	if (m_outputCallback) {
		std::string utf8 = WideToUtf8(message);
		m_outputCallback(utf8);
	}
}

void Console::WriteLine(std::wstring_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::wstring wide(message);
	wide += L'\n';

	WriteConsoleWide(wide, false);

	if (m_outputCallback) {
		std::string utf8 = WideToUtf8(message);
		utf8 += '\n';

		m_outputCallback(utf8);
	}
}

void Console::WriteError(std::wstring_view message) {
	std::lock_guard<std::mutex> lock(m_mutex);

	std::wstring wide(message);
	wide += L'\n';

	WriteConsoleWide(wide, true);

	if (m_errorCallback) {
		std::string utf8 = WideToUtf8(message);
		utf8 += '\n';

		m_errorCallback(utf8);
	}
}

// ------------------------------------------------------------
// Input
// ------------------------------------------------------------

std::string Console::ReadLine() {
	std::lock_guard<std::mutex> lock(m_mutex);

	if (m_inputCallback) {
		return m_inputCallback();
	}

	std::string input;
	std::getline(std::cin, input);

	return input;
}

std::wstring Console::ReadLineW() {
	return Utf8ToWide(ReadLine());
}