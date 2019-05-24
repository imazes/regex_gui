#ifndef REGEX_TOOLS_H
#define REGEX_TOOLS_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>

//���� 
//std::regex::ECMAScript
//�������������ͱ�ʶ

//enum syntax_option_type
//{ // specify RE syntax rules
//    ECMAScript = 0x01,
//    basic = 0x02,
//    extended = 0x04,
//    awk = 0x08,
//    grep = 0x10,
//    egrep = 0x20,
//    _Gmask = 0x3F,
//    icase = 0x0100,
//    nosubs = 0x0200,
//    optimize = 0x0400,
//    collate = 0x0800
//};



struct regex_mathod
{
    std::string regex_name;
    std::regex_constants::syntax_option_type mark;
};

class regex_tools
{
public:
    regex_tools();

    //��ȡ֧�ֵ���������
    std::vector<std::string> get_regex_method_des();

    //��ȡ�����־
    //������﷨����
    std::regex_constants::syntax_option_type
        get_regex_mark(
        std::string regex_method,//�ַ������� �����﷨���� 
        bool ingore_caps         //���Դ�Сд
    );

    //match
    bool match(
        std::string regex_method,//�ַ������� �����﷨����
        bool ingore_caps,        //���Դ�Сд
        std::string src,         //ԭʼ����
        std::string regular      //�����ƥ�����
    );
    //replace
    std::string replace(
        std::string regex_method,//�ַ������� �����﷨����
        bool ingore_caps,        //���Դ�Сд
        std::string src,         //ԭʼ����
        std::string regular,      //�����ƥ�����
        std::string replace      //������滻����
    );

private:
    std::vector<regex_mathod>
        regex_method_des = 
    {
        {"ECMAScript ", std::regex::ECMAScript},
        {"basic ", std::regex::basic},
        {"extended ", std::regex::extended},
        {"awk ",  std::regex::awk},
        {"grep ",  std::regex::grep},
        {"egrep ",  std::regex::egrep}

    };
};

#endif // REGEX_TOOLS_H
