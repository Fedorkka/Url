//
// Created by Fedor on 04.12.2023.
//

#ifndef ULRPARSER_URL_H
#define ULRPARSER_URL_H
#define C_ALL(X) cbegin(X), cend(X)

#include <string>
#include <regex>
#include <iostream>
#include <map>

class Url {
private:
    std::string href_, protocol_, host_, hostname_, port_, pathname_, search_, hash_, origin_, password_, username_;

    bool ParseUrl(const std::string &url);

    bool is_invalid_ = false;

public:
    [[nodiscard]] const std::string &getHref() const;

    [[nodiscard]] const std::string &getProtocol() const;

    [[nodiscard]] const std::string &getHost() const;

    [[nodiscard]] const std::string &getHostname() const;

    [[nodiscard]] const std::string &getPort() const;

    [[nodiscard]] const std::string &getPathname() const;

    [[nodiscard]] const std::string &getSearch() const;

    [[nodiscard]] const std::string &getHash() const;

    [[nodiscard]] const std::string &getOrigin() const;

    [[nodiscard]] const std::string &getPassword() const;

    [[nodiscard]] const std::string &getUsername() const;

    [[nodiscard]] bool isValid() const;

    explicit Url(const std::string &url);

    std::string getInfoStr();


};

#endif //ULRPARSER_URL_H
