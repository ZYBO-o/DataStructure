//
// Created by 张永斌 on 2021/4/10.
//

#ifndef DATASTRUCTURE_REALIZATION_TESTSTRING_H
#define DATASTRUCTURE_REALIZATION_TESTSTRING_H

#include "../HeadCodes/String/String.h"


namespace DataStructure{
namespace Test{
namespace StringTest {

void String_Test() {
    std::cout << "[===============================================================]\n";
    std::cout << "[---------------- Run DataStructure Test : String --------------]\n";
    std::cout << "[-------------------------- API test ---------------------------]\n";

    DataStructure::String str1("this is string1");
    DataStructure::String str2('t');
    DataStructure::String str3(str2);
    DataStructure::String str4 = "this is string4";
    str2 += "his is string2";
    str3 += "his is string3";
    std::cout << str1 << std::endl;
    std::cout << "length of str1 = " << str1.length() << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;
    DataStructure::String str5 = str1 + "," + str2;
    std::cout << "str5 = str1 + \",\" + str2 :" << str5 << std::endl;
    if(str1 < str5) {
        std::cout << "str1 < str5" << ((str1 < str5) ? " Yes" : " No") << std::endl;
    } else {
        std::cout << "str1 >= str5" << (str1 >= str5) << std::endl;
    }
    std::cout << "The 5th character of str1 is : " << str1[5] << std::endl;

    str1[8] = 'S';
    std::cout << "After Changing the 9th character of str1 to 'S' : " << str1 << std::endl;

    str1.startWith("The") ? (std::cout << "str1 is start with \"The\" " << std::endl) : (std::cout << "str1 is not start with \"The\" " << std::endl);
    str5.startWith("the") ? (std::cout << "str5 is start with \"the\" " << std::endl) : (std::cout << "str5 is not start with \"the\" " << std::endl);

    str1.endOf("String1") ? (std::cout << "str1 is end of \"String1\" " << std::endl) : (std::cout << "str1 is not end of \"String1\" " << std::endl);

    String new_str = "new ";
    std::cout << "After inserting \"a new \" string in str1 at position 8, str1 : " ;
    str1.insert(8, new_str).insert(8,"a ");
    std::cout << str1 << std::endl;

    String str6 = "   this is string6   ";
    std::cout << str6 << ",Length is : " << str6.length() << std::endl;
    str6.trim();
    std::cout << "After trim ,str5 : " << str6 << ",Length is : " << str6.length() << std::endl;

    std::cout << "\"string6\" at the position of str6 : " << str6.indexOf("string6") << endl;
    std::cout << "After removing \"string6\" : " << str6.remove("string6") << endl;

    String min = "this";
    String temp = str1 - min;
    std::cout << "str1 - \"this\" = " << temp << std::endl;

    str1 -= "String1";
    std::cout << "str1 -= \"String1\" : " << str1 << std::endl;

    std::cout << "replace \"this\" with \"THIS\" : " << str1.replace("this", "THIS") << endl;

    std::cout << "The sub(4,5): " << str1.sub(5,2) << endl;

    std::cout << "[------------------ String Performance Testing -----------------]\n";
}

}
}
}


#endif //DATASTRUCTURE_REALIZATION_TESTSTRING_H
