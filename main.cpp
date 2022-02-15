#include <iostream>
#include <vector>
#include <map>
#include <cpr/cpr.h>
struct Param{
    std::string arg;
    std::string val;
};

std::string Fill(std::vector<Param> &param){
    while (true){
        Param curParam;
        std::cin >> curParam.arg;
        if (curParam.arg == "post") return "post";
        else if (curParam.arg == "get") return "get";
        std::cin >> curParam.val;
        param.push_back(curParam);
    }
}
int main() {
    std::vector<Param> param;
    int count = 0;
    std::string arg, val;
    cpr::Response r;
    std::string typeResponse = Fill(param);
    if (typeResponse == "post"){
        cpr::Payload payload{{param[0].arg, param[0].val}};
        for (int i = 1; i < param.size(); i++){
            payload.Add({param[i].arg, param[i].val});
        };
        r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                    payload);
    } else if(typeResponse == "get"){
        std::string url = "http://httpbin.org/get?";
        for (auto & i : param){
            url += i.arg + "=" + i.val + "&";
        };
        r = cpr::Get(cpr::Url(url));
    }
    std::cout << r.text;
    return 0;
}
