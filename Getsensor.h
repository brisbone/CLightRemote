//
// Created by brisbone on 10.03.19.
//

#ifndef CLIGHTREMOTE_GETSENSOR_H
#define CLIGHTREMOTE_GETSENSOR_H
#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

class Getsensor
{
private:

public:
    Getsensor();
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    string fetchSender(char[]);
};
#endif //CLIGHTREMOTE_GETSENSOR_H
