#include "code_conv.h"


std::string utf16_2_utf8(const wchar_t* unicode)
{
    int len;

    len = WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, NULL, 0, NULL, NULL);
    char* buf = (char*)malloc(len + 1);
    memset(buf, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, buf, len, NULL, NULL);

    //return (unsigned char*)buf;

    std::string res = buf;
    free(buf);
    return res;                                      
}

std::string utf16_2_ansi(const wchar_t* unicode)
{
    int len;

    len = WideCharToMultiByte(CP_ACP, 0, (const wchar_t*)unicode, -1, NULL, 0, NULL, NULL);
    char* sz_buf = (char*)malloc(len + 1);
    memset(sz_buf, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, (const wchar_t*)unicode, -1, sz_buf, len, NULL, NULL);
    //return (unsigned char*)sz_buf;
    std::string res = sz_buf;
    free(sz_buf);
    return res;
}

std::wstring utf8_2_utf16(const char* str)
{
    int textlen;
    wchar_t* result;
    textlen = MultiByteToWideChar(CP_UTF8, 0, (char*)str, -1, NULL, 0);
    result = (wchar_t*)malloc((textlen + 1) * sizeof(wchar_t));
    memset(result, 0, (textlen + 1) * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, (char*)str, -1, (LPWSTR)result, textlen);
    //return result;
    std::wstring res = result;
    free(result);
    return res;
}

std::wstring ansi_2_utf16(const char* str)
{
    int dwUnicodeLen = MultiByteToWideChar(CP_ACP, 0, (char*)str, -1, NULL, 0);
    if (!dwUnicodeLen)
    {
        return 0;
    }
    size_t num = dwUnicodeLen * sizeof(wchar_t);
    wchar_t* pwText = (wchar_t*)malloc(num);
    memset(pwText, 0, num);
    MultiByteToWideChar(CP_ACP, 0, (char*)str, -1, pwText, dwUnicodeLen);
    //return pwText;
    std::wstring res = pwText;
    free(pwText);
    return res;
}


std::string ansi_2_utf8(const  char* str)
{
    std::wstring unicode = ansi_2_utf16(str);
    std::string buf = utf16_2_utf8(unicode.c_str());

    return buf;
}

std::string utf8_2_ansi(const char* str)
{
    std::wstring unicode = utf8_2_utf16(str);
    std::string buf = utf16_2_ansi(unicode.c_str());

    return buf;
}