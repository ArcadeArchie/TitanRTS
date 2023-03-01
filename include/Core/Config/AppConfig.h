#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <fstream>
#include <vector>
#include <string>
#include <map>

namespace Core
{
    namespace Config
    {
        class AppConfig
        {
        public:
            static AppConfig from_file(std::string path);
            static AppConfig from_file(std::ifstream &file);
            std::string operator[](std::string key)
            {
                return config[key];
            }

        private:
            std::map<std::string, std::string> config;
            AppConfig();
            void add_pair(std::string key, std::string value);
        };
    }
}

#endif