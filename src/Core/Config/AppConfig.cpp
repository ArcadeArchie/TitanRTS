#include "Core/Config/AppConfig.h"
#include <sstream>

namespace Core
{
    namespace Config
    {
        AppConfig AppConfig::from_file(std::string path)
        {
            std::ifstream is_file(path);
            return from_file(is_file);
        }
        AppConfig AppConfig::from_file(std::ifstream &file)
        {
            std::string line;
            AppConfig cfg;
            while (std::getline(file, line))
            {
                if (line.rfind('#', 0) == 0 || line.rfind(';', 0) == 0)
                    continue;
                std::istringstream is_line(line);
                std::string key;
                if (!std::getline(is_line, key, '='))
                    continue;
                std::string value;
                if (std::getline(is_line, value))
                    cfg.add_pair(key, value);
            }

            return cfg;
        }

        AppConfig::AppConfig()
        {
        }

        void AppConfig::add_pair(std::string key, std::string value)
        {
            config[key] = value;
        }
    }
}