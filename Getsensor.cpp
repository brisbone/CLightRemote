//
// Created by brisbone on 10.03.19.
//
#include "Getsensor.h"
#include <iostream>
#include <string>

Getsensor::Getsensor(){

}

size_t Getsensor::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
string Getsensor::fetchSender(char url[])
{
    CURL *curl;
    CURLcode res;
    string readBuffer;
    //char URL = *url; //"http://ras.uwxy.de/sender.json";
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return "Fehler";
        }
        else
        {
            curl_easy_cleanup(curl);
            //cout << "test: \n" << readBuffer << " ende" << endl;
        }
    }
    return readBuffer;
}
