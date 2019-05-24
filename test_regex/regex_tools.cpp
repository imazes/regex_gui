#include "regex_tools.h"

regex_tools::regex_tools()
{

}

std::vector<std::string> regex_tools::get_regex_method_des()
{
    std::vector<std::string>
        res;

    for (auto val: regex_method_des)
    {
        res.push_back(val.regex_name);
    }

    return res;
}

std::regex_constants::syntax_option_type 
regex_tools::get_regex_mark(std::string regex_method, bool ingore_caps)
{
    //正则 规则标志
    std::regex_constants::syntax_option_type  
        regex_mark= std::regex::ECMAScript;


    for (auto val : regex_method_des)
    {
        if (val.regex_name == regex_method)
        {
            regex_mark=val.mark;
            break;
        }
    }


    if (ingore_caps)
    {
        regex_mark |= std::regex::icase;
    }
    return regex_mark;
}

bool regex_tools::match(
    std::string regex_method, 
    bool ingore_caps, 
    std::string src, 
    std::string regular)
{
    bool res = false;

    try
    {

        if (regular.size() == 0)
        {
            return false;

        }

        std::regex_constants::syntax_option_type
            regex_mark = get_regex_mark(regex_method, ingore_caps);


        std::regex txt_regex(regular.c_str(), regex_mark);

        res = std::regex_match(src.c_str(), txt_regex);
    }

    catch (const std::regex_error & e)
    {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack)
        {
            std::cout << "The code was error_brack\n";
        }

        res = false;
    }


    return res;
}

std::string regex_tools::replace(
    std::string regex_method, 
    bool ingore_caps, 
    std::string src, 
    std::string regular,
    std::string replace
    )
{
    std::string res;



    try
    {
        if (regular.size() == 0)
        {
            return res;

        }

        std::regex_constants::syntax_option_type
            regex_mark = get_regex_mark(regex_method, ingore_caps);

        std::regex txt_regex(regular.c_str(), regex_mark);

        res = std::regex_replace(src, txt_regex, replace);
    }

    catch (const std::regex_error & e)
    {

        char buf[256] = { 0 };
        sprintf_s(buf,"语法错误:%s", e.what());
        res = buf;
    }

    return res;
}
