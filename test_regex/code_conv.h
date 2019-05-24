#pragma once
#include <windows.h>  
#include <string>


std::string utf16_2_utf8(const wchar_t* unicode);

std::string utf16_2_ansi(const wchar_t* unicode);

std::wstring utf8_2_utf16(const char* str);

std::wstring ansi_2_utf16(const char* str);


std::string ansi_2_utf8(const  char* str);
std::string utf8_2_ansi(const char* str);