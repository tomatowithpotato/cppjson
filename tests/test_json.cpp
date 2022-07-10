#include <string>
#include <iostream>
#include "json.h"

namespace JSON = haha::json;

int main(){
    std::string str = "{\"check\": 123.5e10, \"2893h\":\"ok\", \"arr\": [\"sd\", null, -11]}";
    JSON::Json json;

    bool ok = true;
    ok = json.fromString(str);

    std::cout << ok << std::endl;

    std::cout << json.toString(false) << std::endl;

    std::string filePath = "../test.json"; // 文件位置自己定

    ok = json.fromFile(filePath);

    std::cout << ok << std::endl;

    std::cout << json.toString() << std::endl;

    JSON::JsonObject::ptr obj;
    if(json.getType() == JSON::JsonType::Object){
        obj = json.getValuePtr<JSON::JsonObject>();
    }

    JSON::PrintFormatter fmt{
        JSON::JsonFormatType::NEWLINE,
        1,
        true
    };

    /* 序列化 */
    std::string output = obj->toString(fmt);
    std::cout << output << std::endl;

    std::cout << std::string(60, '*') << std::endl;

    /* 反序列化 */
    JSON::Json json1;
    ok = json1.fromString(output);
    std::cout << ok << std::endl;
    JSON::JsonObject::ptr obj1;
    if(json1.getType() == JSON::JsonType::Object){
        obj1 = json.getValuePtr<JSON::JsonObject>();
    }

    JSON::PrintFormatter fmt1{
        JSON::JsonFormatType::NEWLINE,
        1,
        false
    };
    
    if(ok){
        std::string output1 = obj1->toString(fmt1);
        std::cout << output1 << std::endl;
    }

    return 0;
}